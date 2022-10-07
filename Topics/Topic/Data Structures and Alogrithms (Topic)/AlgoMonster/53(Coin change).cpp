/*
Problem statement:

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11

Output: 3

Explanation:
11 = 5 + 5 + 1, 3 total coins

Example 2:
Input: coins = [3], amount = 1

Output: -1
*/

/*
-------------------------    My Approaches:
1. Combinatorics

    we can use combinaotircs in order to solve this problem. at any step, we can use one of all the different types of coins 
    we have. as a result, we use that to generate all possible combinatioons of coins. if our sum exceeds the amopunt or if we have mincoins set and the current coint of coins is more than mincoins, 
    then we step the recusion. else we add the current coin to sum, increase the count and call recursively.

    Time complexity: O()
    Space complexity: O()

2. top-down DP
    because, we use combinatorics to generate all possible combination there can be states that are repeated during that recursion.
    as a result, we make use of a set to store the two states which represent whether an element has alreay occurred or not.
    those are the (level of recursion, sum). both of these togehther, let us know if we have already come across this state and help us get rid of branches whoich have been calculated before.


3. bottom-up [not fully working]
    the idea behind this approach was to start from the smallest unit to get the solution. as a result, the smallest unit would be
    to have no coin and build up the amount. at each level we can then add one coin as we go and see if we can reach the amount we are looking for.
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
1. brute foce
    this is a classical problem very similar to the unbounded knapsack problem.

    brute foce method enumerates all possibilties with the use of backtracking. we start with a total sum of 0 and try every denomination.
    since we can use each denomination more than once, we repeat this process until the toal sum reaches (or exceeds) the target.
    runtime is O(n^{amount/T}} where T is the minimum denomination. the space complexity is amount/T since the recursive tree will be at most amount/T deep at any given time)    


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void getMinCoins(std::vector<int> & coins, int amount, int & minCoins, int sum, int count){
    // if sum > amount, we stop
    if(sum > amount)
        return;
    else if(sum == amount){
        // if sum == amount
        if(count < minCoins)
            minCoins = count;
        return;
    }
    // if minCoins is set and number of coins exceeds it
    else if((minCoins != std::numeric_limits<int>::max()) && (count > minCoins))
        return;
    
    
    for(int i=0; i<coins.size(); i++)
        getMinCoins(coins, amount, minCoins, sum + coins[i], count+1);
}


int coin_change(std::vector<int> coins, int amount) {
    // WRITE YOUR BRILLIANT CODE HERE
    int minCoins = std::numeric_limits<int>::max();
    if(!amount)
        return 0;
    getMinCoins(coins, amount, minCoins,0,0);
    if(minCoins == std::numeric_limits<int>::max())
        return -1;
    return minCoins;
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
    int res = coin_change(coins, amount);
    std::cout << res << '\n';
}


// My Approaches(2)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_set>

// Hash function 
struct hashFunction
{
  size_t operator()(const std::pair<int,int> &x) const
  {
    return x.first ^ x.second;
  }
};

void getMinCoins(std::vector<int> & coins, int amount, int & minCoins, int sum, int count, std::unordered_set<std::pair<int,int>, hashFunction> & visited){
    // if sum > amount, we stop
    std::pair<int,int> currPair = std::make_pair(sum,count);
    
    if(sum > amount)
        return;
    else if(sum == amount){
        // if sum == amount
        if(count < minCoins)
            minCoins = count;
        return;
    }
    // if minCoins is set and number of coins exceeds it
    else if((minCoins != std::numeric_limits<int>::max()) && (count > minCoins))
        return;
    // if we have already come across this pair before
    else if(visited.find(currPair) != visited.end())
        return;
    
    visited.emplace(currPair);
    for(int i=0; i<coins.size(); i++)
        getMinCoins(coins, amount, minCoins, sum + coins[i], count+1, visited);
}


int coin_change(std::vector<int> coins, int amount) {
    // WRITE YOUR BRILLIANT CODE HERE
    int minCoins = std::numeric_limits<int>::max();
    std::unordered_set<std::pair<int,int>, hashFunction> visited;
    
    if(!amount)
        return 0;
    
    getMinCoins(coins, amount, minCoins,0,0, visited);
    if(minCoins == std::numeric_limits<int>::max())
        return -1;
    return minCoins;
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
    int res = coin_change(coins, amount);
    std::cout << res << '\n';
}


// My Approaches(2) [not working]
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int getMinCoins(std::vector<int> coins, int amount, int n){
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));

    dp[0][0] = 1;
    
    for(int i=1; i <= coins.size(); i++){
        int element = coins[i-1];
        for(int j=0; j < amount+1; j++){
            if(j < element)
                dp[i][j] = dp[i-1][j];
            else if(j == element)
                dp[i][j] = 1;
            else{
                if(dp[i][j-element])
                    dp[i][j] = dp[i][j-element] + 1;
                if(dp[i-1][j])
                    dp[i][j] = std::min(dp[i][j], dp[i-1][j]);
            } 
        }
    }
    if(!dp[n][amount])
        return -1;
    return dp[n][amount];
}

int coin_change(std::vector<int> coins, int amount) {
    // WRITE YOUR BRILLIANT CODE HERE
    int n = coins.size();
    if(!amount)
        return 0;
    
    return getMinCoins(coins, amount, n);
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
    int res = coin_change(coins, amount);
    std::cout << res << '\n';
}



//  Other Approaches(1)
int min_coins(vector<int> &coins, int amount, int sum) {
  if (sum == amount) {
    return 0;
  }
  if (sum > amount) {
    return numeric_limits<int>::max();
  }
  int ans = numeric_limits<int>::max();
  for (auto &coin : coins) {
    int result = min_coins(coins, amount, sum + coin);
    if (result == numeric_limits<int>::max()) {
      continue;
    }
    ans = min(ans, result + 1);
  }
  return ans;
}

int coin_change(vector<int> coins, int amount) {
  int result = min_coins(coins, amount, 0);
  return result == numeric_limits<int>::max() ? -1 : result;
}
