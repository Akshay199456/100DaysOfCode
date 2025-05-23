/*
Problem statement:

here are n coins in a straight line. The ith coin has a value of coins[i]. You play this game with a friend alternating turns, starting with you, remove one coin from one end of the line and add that coin's value to your score.

If your friend plays perfectly in such a way that maximizes their score, what is your maximum possible score?

Input
coins: A list of the coins.
Output
Your maximum possible score, provided that you go first and your friend plays perfectly.

Examples
Example 1:
Input:

coins = [4, 4, 9, 4]
Output: 13

Explanation:

The coins start like this:

4, 4, 9, 4

You always go first, so you take the 4 from the left side:

4, 9, 4

Your friend takes any of the 4s (it doesn't matter)

9, 4

Now you take the 9, and your friend takes the remaining 4.

Your score in this case, is 4 + 9 = 13.

Constraints
1 <= len(coins) <= 1000
1 <= coins[i] <= 5 * 10^5
*/

/*
-------------------------    My Approaches:
1. brute foce - combinatorics + dfs (doesnt work)

    my though process here was that we would generate all possible combinations of selections possible by both the player
    and the opponent and we could then get the max score from that. however, that approach doesnt seem to have worked.

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
1. Brute force 

    A brute force solution would enumerate through all possibilities. for each of the n turns, we either choose the left-most coin or the rght=-most coin
    and check which option maximizes our score

    the 2 cases mentioned above are described as follows:

    case 1: we take coin l
        1. coins in the range [l+1,r] are left
        2. since our opponent plays optimally, they will gain points eqaul to maxScore(l+1,r)
        3. since we get all other coins, our score will be sum(l,r) - maxScore(l+1,r)
    

    case 2: we take coin r
        1. coins in the range [l,r-1] are left
        2. since our opponent plays optimally, they will gain points eqaul to maxScore(l,r-1)
        3. since we get all other coins, our score will be sum(l,r) - maxScore(l,r-1)

    next we choose the case that gives us the greatest score or minimzes the opponent';s score. therefore the solution is either:
        1. maxScore(l,r) = max(sum(l,r) - maxScore(l+1,r), sum(l,r) - maxScore(l,r-1)) OR
        2. maxScore(l,r) = sum(l,r) - min(maxScore(l+1,r), maxScore(l,r-1))
    
    note that a common pitfall is to try to keep tracking of which player the current recursive call is for using an extra state variable.
    this is unnecessary because it doesnt reallly matter which user the recursive call is for becasuse the current plater
    always tries to minimize the other player's score ( each user 'plays perfectly in suych a wauy that maximizes their score'). each 
    recursive call returns the best possible score the current player can get. the outemost call will return the best score
    for the first player.

    since there are n turns, 2 possibilities each turn and takes O(n) to calculate the sum from l to r, the final runtime is 
    O(n*2^n)



    Time complexity: O()
    Space complexity: O()


Additional notes:
    I now understand the logic they used bejind the scoring. so, you can either select l or r for your coin.
    lets assume that you selected l for your coin. once you make that choice, that leaves behind [l+1,r] coins for your oponent to select. and since your opponenet is also playing optimally, his goals would be to 
    maximize his score from [l+1,r] coins which has been represented as maxScore(l+1,r). this means that your oponment is going to select his coins
    such that his score is maximized for the coins [l+1,r] and this has been represented as maxScore(l+1,r).
    okay, since we now know what your opoonent is looking for which is maxScore(l+1,r), once he makes that choice, what is the score you are left with.
    It is sum(l+r) - maxScore(l+1,r). In other words, our score will be whatever is remaining once our oppoent has made the chocice
    to maximize his score of maxScore(l+1,r) and the way we can calcualte that is to subtract maxxScore(l+1,r) from the sum of coins which is what we are doing.


2. Slight optimiazation

    so far, for each recursive call we are spending O(n) time to calculate the sum between the range [l,r]. however, instead of using
    O(n) every time we need the sum, we can use a prefix sum array to get the range in O(1) time and a single O(n) pre-computation.


3. Top-down dp

    In essence, the top-down DP solution is the brute force solution with memoization. you may have noticed that
    max_score(l,r) can be memoized.

    lets formalize the idea above by specifying our DP state (i.e. what's important that can lead us to our answer). in this case,
    let dp(l,r) be the maximum score we can achieve if coins in the range [l,r] are the only ones present and we go first.

    Furthermore, our base case is : dp(l,r) = v_r if l=r. that is, since the range contains only one coin, we simply take
    that coin.

    now we deal with the transition. exactly like our brute force solution, we consider two cases of picking either the left or right
    coin.

    next, we choose the case that gives us the greatest score or minimizes the opponent's score. therefore, the solution is either:
        1. dp(l,r) = max(sum(l,r) - dp(l+1,r), sum(l,r) - dp(l,r-1)) OR
        2. dp(l,r) = sum(l,r) - min(dp(l+1,r), dp(l,r-1))


4. Bottom-up DP

    the iterative version is a bit trickier. the idea is that we loop through all the possible lengths starting from 1 to n. then for each
    size, we consider all possible left starting positions and calculate the respective rightt ending position. we do it in this order because
    we are building solutions from the smallest case and building the solutions up. that is, first considering each item as in interval of length 1, then merging
    their solutions together to form larger and larger interval lengths until we get to an interval of size n

*/



//  My approaches(1) [does not work]
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void playGame(std::vector<int> & coins, int plScore, int opScore, int & maxScore, int beg, int end, int turn){
    if(beg > end){
        int higherScore = std::max(plScore, opScore);
        maxScore = std::max(higherScore, maxScore);
    }
    else{
        // choose from the beginning
        if(turn){
            // if player's turn
            playGame(coins, plScore + coins[beg], opScore, maxScore, beg+1, end, 0);
        }
        else{
            // if opponent's turn
            playGame(coins, plScore, opScore + coins[beg], maxScore, beg+1, end, 1);
        }
        
        // choose from the end
        if(turn){
            // if player's turn
            playGame(coins, plScore + coins[end], opScore, maxScore, beg, end-1, 0);
        }
        else{
            // if opponent's turn
            playGame(coins, plScore, opScore + coins[end], maxScore, beg, end-1, 1);
        }
        
    }
}


int coin_game(std::vector<int> coins) {
    // WRITE YOUR BRILLIANT CODE HERE
    int maxScore = 0;
    // turn = 1 for player and =0 for opponent
    playGame(coins, 0, 0, maxScore, 0, coins.size()-1, 1);
    return maxScore;
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

int main() {
    std::vector<int> coins = get_words<int>();
    int res = coin_game(coins);
    std::cout << res << '\n';
}




//  Other Approaches(1)
int max_score(vector<int> coins, int l, int r) {
  if (l == r) {
    return coins[r];
  }

  int sum = 0;
  for (int i = l; i <= r; i++) {
    sum += coins[i];
  }

  int left_pick = max_score(coins, l + 1, r);
  int right_pick = max_score(coins, l, r - 1);
  return sum - min(left_pick, right_pick);
}

int coin_game(vector<int> coins) {
  int n = coins.size();
  return max_score(coins, 0, n - 1);
}


// Other Approaches(2)
int max_score(vector<int> coins, int l, int r) {
  int sum = coins[r] - coins[l - 1]; // query sum from [l, r] in O(1)
  if (l == r) {
    return sum;
  }

  int left_pick = max_score(coins, l + 1, r);
  int right_pick = max_score(coins, l, r - 1);
  return sum - min(left_pick, right_pick);
}

int coin_game(vector<int> coins) {
  int n = coins.size();
  vector<int> prefix_sum(n + 1, 0); // precompute prefix sum
  for (int i = 1; i <= n; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + coins[i -1];
  }
  return max_score(prefix_sum, 1, n);
}


// Othe rApproaches(3)
int max_score(vector<vector<int>> &dp, vector<int> &prefix_sum, int l, int r) {
  if (dp[l][r] != 0) {
    return dp[l][r];
  }

  int sum = prefix_sum[r] - prefix_sum[l - 1];
  if (l == r) {
    dp[l][r] = sum;
  } else {
    dp[l][r] = sum - min(max_score(dp, prefix_sum, l + 1, r), max_score(dp, prefix_sum, l, r - 1));
  }

  return dp[l][r];
}

int coin_game(vector<int> coins) {
  int n = coins.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  vector<int> prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + coins[i - 1];
  }
  return max_score(dp, prefix_sum, 1, n);
}


// Other Approaches(4)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

int coin_game(vector<int> coins) {
  int n = coins.size();
  vector<int> prefix_sum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + coins[i - 1];
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int size = 0; size < n; size++) {
    for (int l = 1; l + size <= n; l++) {
      int r = l + size;
      if (l == r) {
        dp[l][r] = prefix_sum[r] - prefix_sum[l - 1];
      } else {
        dp[l][r] = prefix_sum[r] - prefix_sum[l - 1] - min(dp[l + 1][r], dp[l][r - 1]);
      }
    }
  }
  return dp[1][n];
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

int main() {
    std::vector<int> coins = get_words<int>();
    int res = coin_game(coins);
    std::cout << res << '\n';
}