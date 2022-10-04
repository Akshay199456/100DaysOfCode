/*
Problem statement:

Input
nums: the array
Output
if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal

Examples
Example 1:
Input:

nums = [3, 4, 7]
Output: true

Explanation:

The array can be partitioned as [3,4] and [7].

Example 2:
Input:

nums = [1, 5, 11, 5]
Output: true

Explanation:

The array can be partitioned as [1, 5, 5] and [11].


*/

/*
-------------------------    My Approaches:
1. brute force - combinatorics

    since this problem asks if we can soplit the elements into two subsets, well then that's what we have got to do. in order to do that, this problem then becomes part of the 
    combinatorics problem where we have to generate all possible combinations. and that is exactly what we do.
    at every new element, you have one of two chocies, either add it to set a or add it to set b. When we have finally
    added the last element, we can then comapre the sums to make srue they are equal and if they are return true. else return false.

    Time complexity: O()
    Space complexity: O()

2. DP - top-down approach

    we can improve upon the previous approach by pruing off branches that are repeated as well as those that have repeated
    branches. we use a set to store the state of th esums that we enter. if we come across it, then we know that we dont have a valid solution so we return false.
    else we move down to the next branch after making modifications to the current sum branches.
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
brute force:

first, the sum of each subset should be the sum of the entire array divided by 2, sum(nums)/2, we will call it target. if the original sum is odd, we can immediately return false
as it is impossible to find two equal subset sums where the sum is odd by parity rules

the immediate approach would be to brute force all possible sums and check if a sum of target is possible. the following is a space-state tree of this idea

in the figure, we continue search despite already having ffound target, but once we find it, we can return true. furthermore, if we notice that the current sum is greater than the target,
we also dont need to keep searching but is not done in figure for clarity.

    Time complexity: O()
    Space complexity: O()

Runtiime is O(2^n) in the worst case since there are n items and each item has two possibilities: either include it in the sum or don't. since this is implemetned
recursively, the space complexity is O(n) since there are at most n items on the memory stack at any given moment.


Parition DP

1. top-down

    we can see that when we consider elements [3,4,7] the sum of 7 can be generated in two different ways. we can sloso
    see that the subtree beneath the nodes where the sum is 7, highlighted as node A and node B are the exact same. Despite node A
    and node B being parts of different subtrees, adding level/number of items considered to the state makes the nodes 7 unique (are all the same).
    so instead of recomputing these values everytime the sum is 7, we can immediately stop before going to deeper. thus, we can store, in a table,
    if a subtree has been recompiuted already and its value. a fully-pruned state -space tree looks like this:

    we see taht nodes that have already been computed still appear or are greater than the target sum still appear, but do not go deeper into
    their computation

    the runtime of this solution is O(n*target) since there are O(n*target) states, each state depends on O(1) subproblems and each state takes O(1) to compute. the runtime is also
    O(n*target +n) = O(n*target) because of the O(n*target) dp table and O(n) recursion depth.


2. bottom-up
    the top down solution may exceed the recursive stack depth. so, we can implement thje idea bove iteratively. once again, the idea of iterative or bottom-up DP is to start from the samaleest case,
    and build our way up to the final solution

    we will maintain a 2d table where dp[i][s] = true if we can form the sum s when considering the first i items. otherwise dp[i][s] = false.
    we can take our idea from the top-down solutuon by thinking about each item have two possibilities: including it in our sum or not.
    thus, dp[i][s] = true if:
        1. the sum s can be formed without including the ith element, dp[i-1][s]=true OR
        2. the sum s can be formed including the ith element, dp[i-1][s-nums[i]] == true
    
    following figures present this idea when considering all elements [3,4,7,6]:

    runtime of the code above is O(n*target) since there are O(n*target) states, each state depends on O(1) subproblems and each
    state takes O(1) to compute. the space complexity is also O(n*target) with the ise ofthe 2D dp table

3. Space optimization
    can slightly optimize the memor usage of our solution above by notcing that for any dp[i][s],. we only really care about the preivous row, dp[i-1][...]. thus, instead of storing the entrire 2d grid,
    we can store a 2 1d arrays, one for the current row and one for the previous row.
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

bool dfs(std::vector<int> & nums, int sumA, int sumB, int index){
    if(index == nums.size()){
        if(sumA == sumB)
            return true;
        return false;
    }
    return dfs(nums, sumA + nums[index], sumB, index+1) || dfs(nums, sumA, sumB + nums[index], index+1);
}

bool can_partition(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    return dfs(nums, 0, 0, 0);
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
    std::vector<int> nums = get_words<int>();
    bool res = can_partition(nums);
    std::cout << std::boolalpha << res << '\n';
}



//  My approaches(2)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
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

bool dfs(std::vector<int> & nums, int sumA, int sumB, int index, std::unordered_set<std::pair<int,int>, hashFunction> & visited){
    if(index == nums.size()){
        if(sumA == sumB)
            return true;
        return false;
    }
    else if(!nums[index])
        return dfs(nums, sumA + nums[index], sumB, index+1, visited) || dfs(nums, sumA, sumB + nums[index], index+1, visited);
    
    std::pair<int,int> firstPair = std::make_pair(sumA, sumB);
    std::pair<int,int> secondPair = std::make_pair(sumB, sumA);
    if(((visited.find(firstPair) != visited.end()) || (visited.find(secondPair) != visited.end())))
        return false;
    else{
        visited.emplace(firstPair);
        visited.emplace(secondPair);
        return dfs(nums, sumA + nums[index], sumB, index+1, visited) || dfs(nums, sumA, sumB + nums[index], index+1, visited);
    }
    
}

bool can_partition(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_set<std::pair<int,int>, hashFunction> visited;
    if(!nums.size())
        return true;
    else
        return dfs(nums, nums[0], 0, 1, visited) || dfs(nums,0, nums[0], 1, visited);
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
    std::vector<int> nums = get_words<int>();
    bool res = can_partition(nums);
    std::cout << std::boolalpha << res << '\n';
}


// Other Approaches(1)
bool target_exists(int n, vector<int> &nums, int target_sum, int current_sum) {
  // target sum is possible
  if (current_sum == target_sum) {
    return true;
  }
  // impossible if no more elements or current sum exceeds target sum
  if (n == 0 || current_sum > target_sum) {
    return false;
  }
  bool exists = target_exists(n - 1, nums, target_sum, current_sum + nums[n - 1]) // use element
             || target_exists(n - 1, nums, target_sum, current_sum);              // don't use element
  return exists;
}

bool can_partition(vector<int> nums) {
  int total_sum = 0;
  for (int num : nums) {
    total_sum += num;
  }

  if (total_sum % 2 != 0) {
    return false;
  }

  int target = total_sum / 2;
  int n = nums.size();
  return target_exists(n, nums, target, 0);
}



// Other Approaches(2)
bool target_exists(int n, vector<int> &nums, int target_sum, int current_sum, vector<vector<int>> &dp) {
  // target sum is possible
  if (current_sum == target_sum) {
    return true;
  }
  // impossible if no more elements or current sum exceeds target sum
  if (n == 0 || current_sum > target_sum) {
    return false;
  }
  if (dp[n][currentSum] != 0) {
    if (dp[n][currentSum] == 1) {
      return true;
    } else {
      return false;
    }
  }
  bool exists = target_exists(n - 1, nums, target_sum, current_sum + nums[n - 1], dp) // use element
            || target_exists(n - 1, nums, target_sum, current_sum, dp);              // don't use element
  if (exists) {
    dp[n][currentSum] = 1;
  } else {
    dp[n][currentSum] = 2;
  }
  return exists;
}
bool can_partition(vector<int> nums) {
  int total_sum = 0;
  for (int num : nums) {
    total_sum += num;
  }
  if (total_sum % 2 != 0) {
    return false;
  }
  int target = total_sum / 2;
  int n = nums.size();
  // dp[i][j] = 0 : value not computed yet
  // dp[i][j] = 1 : value computed and is true
  // dp[i][j] = 2 : value computed and is false
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
  return target_exists(n, nums, target, 0, dp);
}


// Other Approaches(3)
bool can_partition(vector<int> nums) {
  int total_sum = 0;
  for (int num : nums) {
    total_sum += num;
  }

  if (total_sum % 2 != 0) {
    return false;
  }

  int target = total_sum / 2;
  int n = nums.size();

  vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int s = 0; s <= target; s++) {
      if (s < nums[i - 1]) {
        dp[i][s] = dp[i - 1][s];
      } else {
        dp[i][s] = dp[i - 1][s] || dp[i - 1][s - nums[i - 1]];
      }
    }
  }
  return dp[n][target];
}


// Other Approaches(4)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

bool can_partition(vector<int> nums) {
  int total_sum = 0;
  for (int num : nums) {
    total_sum += num;
  }

  if (total_sum % 2 != 0) {
    return false;
  }

  int target = total_sum / 2;
  int n = nums.size();

  // dp[0] is the previous row
  // dp[1] is the current row
  vector<vector<bool>> dp(2, vector<bool>(target + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int s = 0; s <= target; s++) {
      if (s < nums[i - 1]) {
        dp[1][s] = dp[0][s];
      } else {
        dp[1][s] = dp[0][s] || dp[0][s - nums[i - 1]];
      }
    }
    for (int s = 1; s <= target; s++) {
      dp[0][s] = dp[1][s];
      dp[1][s] = false;
    }
  }
  return dp[0][target];
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
    std::vector<int> nums = get_words<int>();
    bool res = can_partition(nums);
    std::cout << std::boolalpha << res << '\n';
}