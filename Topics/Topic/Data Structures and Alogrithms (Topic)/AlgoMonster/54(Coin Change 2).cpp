/*
Problem statement:

You are given coins of different denominations and a total amount of money amount. Write a function to compute the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

Input
coins: A list of the coins and their denominations.
amount: The target amount
Output
The number of combinations that make up that amount.

Examples
Example 1:
Input:

coins = [1, 2, 5]
amount = 11
Output: 4

Explanation:

There are four ways to make up the amount:

5 = 5
5 = 2 + 2 + 1
5 = 2 + 1 + 1 + 1
5 = 1 + 1 + 1 + 1 + 1
Example 2:
Input:

coins = [2]
amount = 3
Output: 0

Explanation:

The amount of 3 cannot be made up with just coins of 2.

Constraints
1 <= len(coins) <= 300
1 <= amount <= 5000
1 <= coins[i] <= 5000
*/

/*
-------------------------    My Approaches:
1. Cobinatorics + dfs

    we use combinatoics + dfs to solve this problem in brute force. we make use of the dfs state-space tree to get the 
    answer we are looking for by generating all possible unique combinations and using dfs

    there are actually two different ways which we can use to get rid of duplicate answers aince this answer wants each unique combination to count to the answr and not a duplicate
    
    1. the first is to store count of each of the coins that you use so when you hit the target, you can form a string from it and store it into a hahsmap. this way
    when you come across another ansser that amtches the taarget, we can compare the strings to see if it has already occurred. if it has, we then know it is not a unique comboination so we skip it, else we add it to the count and to the hashmap

    2. the second way is to only go forward in the indexes and not go backward. in other words, lets say we have considered index 1 in this iteration of the loop. when we do dfs again, we only resume from 1 and dont go back to idnex 0.
    the way this works is as follows:
    lets say you come across an answer that is formed from 1,1,1,2 from going only forward in the indexes.
    if you were to allow to go backward what would happen is that you would get an anbswer that is 1,1,2,1.
    now, we already have that answer by going in the peroper order without going back. 
    that is why, it is important to only go forward or from the same index to skip duplicate answers and get unique answers


    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
1.brute force

    a brute force enumerates through all possibilitites. we start wth a total sum of 0 and try every denomination. since we can use each denomination more than once, after
    we retry every denomination again until we reach our target.

    we essentailly use the same iea used in combination sum problem where we try every single denomination while removing duplicate combinations by maintaingin the
    starting indices

    runtime is going to be O(n^(amount/T)) where t is the smallest denomination since each sum branches into n combinations with a max depth of
    amount/T. the space compleity is amount/T since the reursion stack contains at most amount/T calls.


    Time complexity: O()
    Space complexity: O()


2. DFS + memoization

 can slightly imprive our runtime by reusing solutions that have already been computed. we apply memoization on the starting position as one dimention and the current sum as a seocnd dimension since our function
 is really just f(start, sum)  where we want to find the number of ways to reach amount starting with sum and using all coins starting from index start   

    additional note:
        the thing we got right over here is that we needed a two layer system to store state. i had though it would be (sum, level in tree) but that didnt make sense after a while.
        the right answer was (sum,index) cause if we have for eg: (4,0) giving us 2 possible solutions, that doesnt mean
        (4,1) will give us the same answer. also levels can be the same if you ultiple answers to the same target in the same number of steps.
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void getCount(std::vector<int> & coins, int & amount, int & count, int sum, int index){
    if(sum > amount)
        return;
    else if(sum == amount){
        count += 1;
        return;
    }
    else{
        for(int i=index; i < coins.size(); i++)
            getCount(coins, amount, count, sum + coins[i], i);
    }
}

int coin_game(std::vector<int> coins, int amount) {
    // WRITE YOUR BRILLIANT CODE HERE
    int count = 0;
    if(!coins.size() || !amount)
        return 0;
    getCount(coins, amount, count, 0, 0);
    return count;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> coins = get_words<int>();
    int amount;
    std::cin >> amount;
    ignore_line();
    int res = coin_game(coins, amount);
    std::cout << res << '\n';
}



//  Other Approaches(1)
int num_of_ways(int sum, int amount, int start, vector<int> &coins) {
  if (sum == amount) {
    return 1;
  }
  if (sum > amount) {
    return 0;
  }
  int res = 0;
  for (int i = start; i < (int) coins.size(); i++) { // try every single denomination
    res += num_of_ways(sum + coins[i], amount, i, coins);
  }
  return res;
}

int coin_game(vector<int> coins, int amount) {
  return num_of_ways(0, amount, 0, coins);
}


// Other Approaches(2)
int numOfWays(int sum, int amount, int start, vector<int> &coins, vector<vector<int>> &dp) {
  if (sum == amount) {
    return 1;
  }
  if (sum > amount) {
    return 0;
  }
  if (dp[start][sum] != -1) {
    return dp[start][sum];
  }
  int res = 0;
  for (int i = start; i < (int) coins.size(); ++i) {
    res += numOfWays(sum + coins[i], amount, i, coins, dp);
  }
  return dp[start][sum] = res;
}

int coin_game(vector<int> coins, int amount) {
  int n = (int)coins.size();
  vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
  return numOfWays(0, amount, 0, coins, dp);
}