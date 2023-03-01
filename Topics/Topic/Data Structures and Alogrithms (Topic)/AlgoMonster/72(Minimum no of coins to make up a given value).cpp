/*
Problem statement:

You are given coins of different denominations and an amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

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
1. DFS approach[Not coded]

    The first approach is the normal DFS approach where we generate the state-space tree. at each step to make up the amount,
    we have the chocies to choose any of the coins. if the total sum crosses over the target amount, then that amount cant be made and we stop the recursion thre.
    if the sum we made form the coins is equal to the target amount, then we return the total no of coins it took to make the amount.

    Time complexity: O()
    Space complexity: O()


2. BFS approach [Not coded]
    another way we can solve this problem is using BFS. we know at each step, the choices we ahve depends on the coins we have. as a result, if we use DFs,
    we will apporach the solution the quickest if it exists. if it deos not, then we return -1



3. Memoization approach [not coded]
    From Ny Approaches(1), we can obverve that the same amount comes up many times in different subtrees. as a result, we can store the min no of coins we have seen till then when we reach an amount. 
    This way we prevent duplicate calculations from taking place
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
Solution:
    We can start from 0 and repeatedly add coin values from the list until we either get to the target amount or exceed it. here's the state-space tree:

Implementation
    we traverse the state-space tree using backtracking while keeping an additional state sum that starts from 0 and branch out
    by adding coin values at each step. we reach a leaf node when we either reach or exceed target amount. if we exceed the target value, then we return the largest value possible
    inf. in the aggregation logic, if the return value from a child call is less than what we currently have, then we updat eot the samller value.


Memoization
    since we aggregate on the return value with min, the result we get after the for loop is the smallest possible for the subtree.
    therefore we can memoize the result.


    Time complexity: O()
        size of the memo array is O(amount). for each amount, we try upto n coins. so the overall time complexity
        is O(amount *n)
    Space complexity: O()
        te height of the state-space tree is O(amount/min(coins)). however, the memo array takes O(amount) soace so the overall space
        complexity is O(amount)
*/



//  My approaches(1)



//  Other Approaches(1)
nt min_coins(vector<int> &coins, int amount, int sum) {
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



// Other Approaches(2)
int min_coins(vector<int> &coins, int amount, int sum, vector<int> &memo) {
  if (sum == amount) {
    return 0;
  }
  if (sum > amount) {
    return numeric_limits<int>::max();
  }
  if (memo[sum] != -1) {
    return memo[sum];
  }
  int ans = numeric_limits<int>::max();
  for (auto &coin : coins) {
    int result = min_coins(coins, amount, sum + coin, memo);
    if (result == numeric_limits<int>::max()) {
      continue;
    }
    ans = min(ans, result + 1);
  }
  return memo[sum] = ans;
}

int coin_change(vector<int> coins, int amount) {
  vector<int> memo(amount + 1, -1);
  int result = min_coins(coins, amount, 0, memo);
  return result == numeric_limits<int>::max() ? -1 : result;
}
