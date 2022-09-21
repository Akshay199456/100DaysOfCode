/*
Problem statement:

Given a list of n items and their weights, find all sums that can be formed using their weights.

Input
weights: A list of items and their weights.
Output
A list of possible sums using the weights.

Examples
Example 1:
Input:

weights = [1, 3, 3, 5]
Output: [0, 1, 3, 4, 5, 6, 7, 8, 9, 11, 12]

Explanation:

We can form all sums from 0 to 12 except 2 and 10. Here is a short explanation for the sums:

0: use none of the weights
1: use item with weight 1
3: use item with weight 3
4: use weights 1 + 3 = 4
5: use item with weight 5
6: use weights 3 + 3 = 6
7: use weights 1 + 3 + 3 = 7
8: use weights 3 + 5 = 8
9: use weights 1 + 3 + 5 = 9
11: use weights 3 + 3 + 5 = 11
12: use all weights
Constraints
1 <= len(weights) <= 100
1 <= weights[i] <= 100
*/

/*
-------------------------    My Approaches:
1. brute force approach - combinations

    since the problem asks for all sums that can be formed using their weights, one way we can get the sum of all weights is to
    generate all weight combinations first. this then falls into a combination problem where we are generating all possible combinations.
    in order to generate all possible permutations, at each step, we have one of two chocies. we can either add this elemnt to the list from the previous
    step or we can choose not to. doing that for all elements gives us all possible combinations and the sum of each gives us all poissible weight combination sums.

    Time complexity: O(2^n)
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
a brute force method enumerates all possibilites. we start with a toal su, of 0 and process every item by either choosing to nclude it into our sum or not into our sum.
once no more items are left to process, we can include the final su, in a list of sums. additionally, we will store these sums in a set since there can be repeating sums.

by going through every possibility, we are generating all possible subsets, so we guarnatee that we are also generating all possible sums.

since there are n items, two possibilities each and it takes O(1) to compute each possibiility, the final runtime is O(2^n).

the following the space-state tree for this idea using input [1,3,3,5]. each level i of the tree represents a binary decision to include or not include the ith number. for example,
we have two branches in level i=1, the left branch eans not picking the ith item 3 and the right branch means picking it.


    Time complexity: O()
    Space complexity: O()

Top-down dynamic programming

    first, the 'top-down' solution is, basically, the brute force solution but with memoization. we store results that have already been computed and return them once needed.
    but, in precisely what way should be store/represent the data? going back to the idea of dynamic programming, we should consider what is 
    important so far and if any of the information has been recomputed

    memoizatiion, identifying the state
        to memoize, we need to find the duplicate subtrees in the state-space tree

        note that the duplicate subtrees are of the same level for this problem. this isnt a coincide.

        unlike word break and decode ways in the backtracking section, the items in the knapsack problem can only be used once

        consider node a and node b in the tree

        node' B's subtree has leaf values of 3 and 8. And node A's subtree has leaf values of 3,8,6,11. they are clearly not the same subtree.
        this is because the meaning of a node's value is the weigt sum by considering items from 0 to i.

        therefore, the state we need to memoize consists of the level/dpeth of the node and the node value itself. we will use i(sum) to denote this.

        thus, we will store a 2d boolean array memo where memo[i][sum] = true if the (i,sum) pair has already been computed and false otherwise.
        the size of the array is n*total_sum where n is the number of items and total_sum is the weight sum of all items.
        we need a slot for each possoble weight we can make up and all the possible weights are in th range of 0 to total_sum

        since there are n* totalSum states, each state depends on O(1) subproblems and each state takes O(1) to compute and the final runtime is 
        O(n*totalSum)

bottom-up dynamic programming
    now, let's talk about the 'bottom-up' solution. reacall that the idea of any bottom-up solution i to work from the smallest cases,
    'combine' them together and continue this until we get to our desired solution. thus, by looping through
    each item, we determine which sums we can construct based on if there exists a smaller sum that we can build on top of.
    for example, suppose we already built all possible sums using [1,3,3] and we wanted to know which sums we can build sing all of
    [1,3,3,5] now. 

    the final runtome of this program is O(n*totalSum) because thier is O(n*totoalSum) states, each state depends on O(1) subproblems,
    and each state talkes O(1) to compute


space optimization (optional)
    finally, there is a slight memory optimization that we can perfoorm. obersve that dp[i][w] depends on, at most, the previous
    row (dp[i][w] = dp[i-1][w]) || dp[i-1][w-weights[i-1]]. thus instead of storing the entire 2d array, we can simple
    store two 1d arrays, one to keep track of the previous and one to for the current. this improves our memory usage from
    O(n*totoalSum) to O(totalSum)

    the space optimizatioin is a nice trick but its also easy to get the row swapping wrong. its great to mention this to the interviewer after
    you have perfected your regular solution and confirm that with the interviewer. pre-mature optimization is the 
    root of all evil in softwre engineering


Additional note
    we had come up with this improvmenet approach as shown in Other Approaches(2) itself. the only thing was that we didnt code it.
    instead of using a 2d matrix to store the entries, we were going to use either a set or a map to store the level and sum we had encountered. 
    we will be implmenting this.

    so good job on finding the brute force approiach as well as the top-down approach to this problem

*/



//  My approaches(1)
#include <algorithm> // copy, sort
#include <iostream> // cin
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <algorithm>
#include <unordered_set>

void dfs(std::vector<int> & weights, std::unordered_set<int> & elementSet, int index, int total){
    if(index == weights.size())
        elementSet.emplace(total);
    else{
        // we can choose to add this element to the total
        dfs(weights, elementSet, index+1, total + weights[index]);
        // we can choose to not add this element to the total
        dfs(weights, elementSet, index+1, total);
    }
}


void fillResult(std::unordered_set<int> & elementSet, std::vector<int> & result){
    for(auto it = elementSet.begin(); it!= elementSet.end(); it++){
        result.push_back(*it);
    }
}


std::vector<int> knapsack_weight_only(std::vector<int> weights) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_set<int> elementSet;
    std::vector<int> result;
    dfs(weights, elementSet, 0, 0);
    // sort result and remove duplicates
    fillResult(elementSet, result);
    return result;
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
    std::vector<int> weights = get_words<int>();
    std::vector<int> res = knapsack_weight_only(weights);
    std::sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
      std::cout << res[i];
      if (i != res.size() - 1) {
        std::cout << " ";
      }
    }
    std::cout << "\n";
}


// My Approaches(2)
#include <algorithm> // copy, sort
#include <iostream> // cin
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <algorithm>
#include <unordered_set>
#include <utility>

// Hash function 
struct hashFunction
{
  size_t operator()(const std::pair<int,int> &x) const
  {
    return x.first ^ x.second;
  }
};

void dfs(std::vector<int> & weights, std::unordered_set<int> & elementSet, int index, int total, std::unordered_set<std::pair<int,int>, hashFunction> & visitedSet){
    // (total, index)
    std::pair<int,int> currentPair = std::make_pair(total, index);
    if(visitedSet.find(currentPair) != visitedSet.end())
        return;
    else{
        // push this as visited
        visitedSet.emplace(currentPair);
        
        if(index == weights.size())
            elementSet.emplace(total);
        else{
            // we can choose to add this element to the total
            dfs(weights, elementSet, index+1, total + weights[index],visitedSet);
            // we can choose to not add this element to the total
            dfs(weights, elementSet, index+1, total, visitedSet);
        }
    }
}


void fillResult(std::unordered_set<int> & elementSet, std::vector<int> & result){
    for(auto it = elementSet.begin(); it!= elementSet.end(); it++){
        result.push_back(*it);
    }
}


std::vector<int> knapsack_weight_only(std::vector<int> weights) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_set<int> elementSet;
    std::unordered_set<std::pair<int,int>, hashFunction> visitedSet;
    std::vector<int> result;
    dfs(weights, elementSet, 0, 0,visitedSet);
    // sort result and remove duplicates
    fillResult(elementSet, result);
    return result;
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
    std::vector<int> weights = get_words<int>();
    std::vector<int> res = knapsack_weight_only(weights);
    std::sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
      std::cout << res[i];
      if (i != res.size() - 1) {
        std::cout << " ";
      }
    }
    std::cout << "\n";
}




//  Other Approaches(1)
#include <set> // set

void generate_sums(vector<int> &weights, set<int> &sums, int sum, int n) {
  if (n == 0) {
    sums.insert(sum);
    return;
  }
  generate_sums(weights, sums, sum, n - 1);
  generate_sums(weights, sums, sum + weights[n - 1], n - 1);
}

vector<int> knapsack_weight_only(vector<int> weights) {
  set<int> sums;
  int n = weights.size();
  generate_sums(weights, sums, 0, n);
  vector ans(sums.begin(), sums.end());
  return ans;
}


// Other Approaches(2)
void generate_sums(vector<int> &weights, set<int> &sums, int sum, int n, vector<vector<bool>> &memo) {
  if (memo[n][sum]) {
    return;
  }
  if (n == 0) {
    sums.insert(sum);
    return;
  }
  generate_sums(weights, sums, sum, n - 1, memo);
  generate_sums(weights, sums, sum + weights[n - 1], n - 1, memo);
}
vector<int> knapsack_weight_only(vector<int> weights) {
  set<int> sums;
  int n = weights.size();
  // find total sum of all items
  int total_sum = 0;
  for (int weight : weights) {
    total_sum += weight;
  }
  // initialize memo table to store if result has been calculated
  vector<vector<bool>> memo(n + 1, vector<bool>(total_sum + 1, false));
  generate_sums(weights, sums, 0, n, memo);
  vector ans(sums.begin(), sums.end());
  return ans;
}


// Other Approaches(3)
ector<int> knapsack_weight_only(vector<int> weights) {
  int n = weights.size();
  int total_sum = 0;
  for (int weight : weights) {
    total_sum += weight;
  }
  vector<vector<bool>> dp(n + 1, vector<bool>(total_sum + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= total_sum; w++) {
      // vertical blue arrow in the above slides
      dp[i][w] = dp[i][w] || dp[i - 1][w];
      // diagonal blue arrow in the above slides
      if (w - weights[i - 1] >= 0) { // make sure current item's weight is smaller than the target weight w
        dp[i][w] = dp[i][w] || dp[i - 1][w - weights[i - 1]];
      }
    }
  }
  vector<int> ans;
  // check the last row for all possible answers
  for (int w = 0; w <= total_sum; w++) {
    if (dp[n][w]) {
      ans.emplace_back(w);
    }
  }
  return ans;
}


// Other Approaches(4)
#include <algorithm> // copy, sort
#include <iostream> // cin
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

vector<int> knapsack_weight_only(vector<int> weights) {
  int n = weights.size();
  int total_sum = 0;
  for (int weight : weights) {
    total_sum += weight;
  }
  vector<vector<bool>> dp(2, vector<bool>(total_sum + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= total_sum; w++) {
      dp[1][w] = dp[1][w] || dp[0][w];
      if (w - weights[i - 1] >= 0) {
        dp[1][w] = dp[1][w] || dp[0][w - weights[i - 1]];
      }
    }
    for (int w = 0; w <= total_sum; w++) { // update previous row to current row
      dp[0][w] = dp[1][w];
    }
  }

  // dp[0][w] = true if `w` is an attainable weight, thus add it to our answer
  vector<int> ans;
  for (int w = 0; w <= total_sum; w++) {
    if (dp[0][w]) {
      ans.emplace_back(w);
    }
  }
  return ans;
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
    std::vector<int> weights = get_words<int>();
    std::vector<int> res = knapsack_weight_only(weights);
    std::sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
      cout << res[i];
      if (i != res.size() - 1) {
        cout << " ";
      }
    }
    cout << "\n";
}
