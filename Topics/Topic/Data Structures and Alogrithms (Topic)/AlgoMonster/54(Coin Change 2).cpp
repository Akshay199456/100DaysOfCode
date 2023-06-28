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

2 top down and bottom up
  we can use the approach as shown in my approaches(2)-1. from the brute force, we can see that there are some duplicate trees that keepo 
  appearning over and over again. so the top-down approach improves that by storing the combinations for the amount we have already
  encountered

  the bottom up approach is similar to pb 53(coin change) in that we have the the values from 0 to the amount in a table.
  then on each of the row, we add each type of coin. for each sum, we have one of two chocies. either we can choose to use this new coin in which case
  we would need to make the amount - coins[i] with the same set of coins or we can choose to make the amount without using the coins in which case we use the previous row.
  as a result, the total no of combinations is the sum of these two values.
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


3. bottom-up approach

    this can also be done iteratively in a similar way to the unbounded knapsack problm. once again, the iea of bottom-up DP
    is to, instead of going from top-down , we build our solution froom the bottom-up

    once again, the idea for this solution is extremely similar to that of the unbounded knapsack.

    note the order of the loops. we first loop through all the coins, then amounts. you may think that with our
    top-down recurisve solution, we would first loop through all amounts then coins.. however, that would be incrorrect.

    why? because then we would be overcounting the number of ways since our DP definition actually changes to be dp[i][s] is
    te number of ways to construct the amount s using all cooins. this is aking to the start value we pass in the finction in
    combination sum to remove duplicates. we must keep our defintion to be dp[i][s] is the number of ways to construct the amount s using the first i coins,
    oitherwise there will be duplicates

    additoonal note:
        the bottom up approach is very similar to the unbonunded knapsack problem. i had an idea about i and was doing it. 
        however, i forgot that you could make use of the coin indefinitely. previous iterations of the problem that i had solved wau 
        earlier were such that you ould not use the coin again. as a result, yu would go to the previous row for both the chocies (making sum with the coin and without the coin).
        however, since we can us eht coin definjitely, we still ahve 2 chocies. one choice is to not make use of the coin (which takes us to repvious row)
        while the other is to make us eof the coin (which will take us to the same row since we still ajhve the coint available to us but at a distance sum - coins[i])


4. memory optimization
    note that our transtition dp[i][s] += dp[i][s-coins[i-1]] only depends on the previos row. this, we can optimize our solution
    form O(n*amount) to O(amount) by only storing the previous and current row.

    the time complexity is still O(n*amount) where n is the number of items, ut now the space complexity is O(amount) since
    we only have two amount sized 1d arrays.

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


// Other Approaches(3)
int coin_game(vector<int> coins, int amount) {
  int N = coins.size();

  vector<vector<int>> dp(N + 1, vector<int>(amount + 1, 0));

  dp[0][0] = 1; // there is only 1 way to make a sum of 0 using none of the coins
  for (int i = 1; i <= N; ++i) {
    for (int s = 0; s <= amount; ++s) {
      dp[i][s] = dp[i - 1][s]; // first take the number of ways to make `s` without the `i`th item
      if (s - coins[i - 1] >= 0) {
        dp[i][s] += dp[i][s - coins[i - 1]]; // then, try the `i`th item (if it's valid to use)
      }
    }
  }
  return dp[N][amount];
}


//Other Approaches(4)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

int coin_game(vector<int> coins, int amount) {
  int N = coins.size();

  // dp[0][...] is the previous row
  // dp[1][...] is the current row
  vector<vector<int>> dp(2, vector<int>(amount + 1, 0));

  dp[0][0] = 1; // there is only 1 way to make a sum of 0 using none of the coins
  for (int i = 1; i <= N; ++i) {
    for (int s = 0; s <= amount; ++s) {
      dp[1][s] = dp[0][s]; // first take the number of ways to make `s` without the `i`th item
      if (s - coins[i - 1] >= 0) {
        dp[1][s] += dp[1][s - coins[i - 1]]; // then, try the `i`th item (if it's valid to use)
      }
    }
    for (int s = 0; s <= amount; ++s) { // current row becomes previous row for the next iteration
      dp[0][s] = dp[1][s];
    }
  }
  return dp[0][amount];
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