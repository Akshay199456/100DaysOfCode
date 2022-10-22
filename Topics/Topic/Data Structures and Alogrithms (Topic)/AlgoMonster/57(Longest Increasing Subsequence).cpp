/*
Problem statement:

Input
nums: the integer sequence
Output
the length of longest subsequence

Examples
Example 1:
Input:

nums = [50, 3, 10, 7, 40, 80]
Output: 4

Explanation:

The longest subsequence is [3, 7, 40, 80] which has length 4.

Example 2:
Input:

nums = [1, 2, 4, 3]
Output: 3

Explanation:

Both [1, 2, 4] and [1, 2, 3] are longest subsequences which have length 3.
*/

/*
-------------------------    My Approaches:
1. combinatorics + dfs

    we generate the state-space tree using combinatorics. at each stage, we have 1 of 2 possible steps we can do.
    1) we can either not add the element at the current index and move the index forward
    2) we can add the element at the current index
        - the ability to add the element at the current index will depend if the element at the current idnex exceeds the last element that we had added.
        if it does not exceeed, then it doesnt contrinbute to an increasing subsequence and as a result, there is no point adding that element. if it does exceed,
        then we can add that element, increase the index by 1 and currLength by 1 and move forward with the recursive call structure

    Time complexity: O(2^n) where n is the size of the array
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
1. brute forice

    a brute force method traverses through all 2^n possible subsequences, which is essentially generating all subsets. there are
    2^n since, for every element, we either include it or exclude it. then, for every subsequence, we check if its increasing in O(n) tiime

    the final time complexity is going to be O(n*2^n) and the space complexity is also O(n*2^n) since we must geerate and store all
    O(2^n) subsets each of length O(n)

    Time complexity: O()
    Space complexity: O()


2. DFS + memoization

    the keywords 'longest' and 'sequence' are good indicators of dynamic programming.

    lets try thhinking about a dp solution. first what is the overall problem that we want to solve. its 'what is the LIS of a sequence of n
    numbers?"
    
    what is the dp state? typically when you think of a dp solution for sequences, we consider a prefix of the orginginal sequence.
    in this case, the state is: consdiering the first i numbers (nums[1], nums[2],.... nums[i]), what is the longest increasing
    subsequence that contins nums[i]?

    next the transition. if we want to build an LIS that ends with nums[i], then we need to find a previously existing LIST that ends with a number less than nums[i]. in other words,
    find the largest existing LIS(j <i ) where nums[j] < nums[i] and simply append nums[i] to that LIS.

    a simple base case would be if i=0 then return 0 since if we dont have any elements, the longest increasing subsequence is
    of length 0.

    here's a sumarray of the dp relationship:
        1. state: f(i) is the longest increasing subsequence that ends/contains nums[i]
        2. base case: f(0) = 0: an empty list has n LIS of length 0
        3. transition: f(i) = max(f(j) + 1) for j = 0....i-1 as long as nums[j] < nums[i] (extend a pre-existing LIS)

    as is usual with problems with recursive relations, we store a memo trable to store answers that may be reused to stop unnecessary computations

    runtime of solution is O(n^2) where n is the number of elements in nums since there are O(n) states and each state
    takes takesO(n) to compute. the space complexity is O(n) due to the use of the memo array


    Additional notes:
        the inital call to f(4) kinda thre me off thinking that they are going from f(4) to f(3) and so on. 
        However, by looking at the code, that is not happening. the inner for loop where j gets used starts at
        f(1) and then calcualtes for f(2) [which makes call to f(1) again), then f(3), when then makes call to f(1) and f(2) and so on]



3. Bottom-up DP

    this can be done iteratively. this is simlar to the recursive version except instead of foing from top-down, we build out solution from the bottom-up. 
    we can do this because a larger solution f(n) wll depend on smaller solutions f(0)....f(n-1)

    runtime for this solution is O(n^2) since there are O(n) states and each state takes O(n) to compute. the sapce
    compldexity is O(n) due to the use of the dp array of length O(n)


4. O(nlogn) with DP and binary search

    going to first construct a different DP solution that still runs in O(n^2) time and later see how we can improve it
    to O(nlogn).

    let dp[i] be the last element for an LIS of length i. if there are multiple elements, then choose the smallest one.,

    we will assume that dp[0] = -infinity and all other elmeents dp[i] = infinity. then, process the elements in nums one by one whole maintaining the state we state above and 
    keep dp[i] updated. our answer will be the largest i such that dp(i) != infinity


5.
    if we look at the diagram createved from the above solution, we see that the dp array will always be sorted: dp[i-1] <= dp[i] for all i=1...n.
    Also, for every nums[i], we only update the dp array once

    this means, our goal for every nums[i] is to find the first number in dp strictly greater than nums[].
    this can be done with binary search in O(logn) time. thus, the final runtime is O(nl;ogn)

    once again, the final runtime is O(nlogn) where n is the number of elements in nums since for each element we use
    O(logn) time to update the dp array. the space complexdity is O(n) due to the use of the dp array.

    This is an interesting problem because unlike the previous dynamic programming problems, our solution depends on the solution of a 
    dynamic number of subproblems

*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <limits>

void getLongestLength(std::vector<int> & nums, int lastElement, int currLength, int & maxLength, int index){
    if(index == nums.size()){
        maxLength = std::max(currLength, maxLength);
        return;
    }
    
    // choose to not add element
    getLongestLength(nums, lastElement, currLength, maxLength, index+1);
    // choose to add element
    if(nums[index] > lastElement)
        getLongestLength(nums, nums[index], currLength+1, maxLength, index+1);
}


int longest_sub_len(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    int maxLength = 0;
    if(!nums.size())
        return 0;
    getLongestLength(nums, std::numeric_limits<int>::min(), 0, maxLength,0);
    return maxLength;
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
    int res = longest_sub_len(nums);
    std::cout << res << '\n';
}



//  Other Approaches(1)
int f(int i, vector<int> &nums, vector<int> &memo, int &lis) { // pass lis by reference to act like a global variable
  if (i == 0) {
    return 0;
  }
  if (memo[i] != 0) { // if already computed, use said answer
    return memo[i];
  }
  int len = f(0, nums, memo, lis) + 1; // begin with starting a new LIS
  int ni = nums[i - 1];

  for (int j = 1; j < i; j++) { // try building upon a pre-existing LIS
    int nj = nums[j - 1];
    int f_of_j = f(j, nums, memo, lis); // compute f(j), otherwise if nums[i] < nums[j] then f(j) will never be computed
    if (nj < ni) {
      len = max(len, f_of_j + 1);
    }
  }
  // LIS can end anywhere in the sequence due to the definition of our state, so update each time
  lis = max(lis, len);

  return memo[i] = len;
}

int longest_sub_len(vector<int> &nums) {
  int n = (int) nums.size();
  vector<int> memo(n + 1, 0);
  int lis = 0;
  f(n, nums, memo, lis);
  return lis;
}



// Other Approaches(2)
int longest_sub_len(vector<int> &nums) {
  int N = (int) nums.size();
  vector<int> dp(N + 1, 0);

  dp[0] = 0; // base case: no elements has an LIS of length 0
  int len = 0;
  for (int i = 1; i <= N; ++i) {
    int ni = nums[i - 1];
    dp[i] = dp[0] + 1; // first we try starting a new sequence

    for (int j = 1; j < i; ++j) { // then try extending an existing LIS from indices less than i
      int nj = nums[j - 1];
      if (nj < ni) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }

    len = max(len, dp[i]);
  }
  return len;
}



// Other Approaches(4)
int longest_sub_len(vector<int> &nums) {
  int n = (int) nums.size();
  const int INFINITY = numeric_limits<int>::max();
  vector<int> dp(n + 1, INFINITY);
  dp[0] = -INFINITY;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[j-1] < nums[i] && nums[i] < dp[j]) {
        dp[j] = nums[i];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (dp[i] < INFINITY) {
      ans = i;
    }
  }
  return ans;
}



// Other Approaches(5)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

int longest_sub_len(vector<int> &nums) {
  int n = (int) nums.size();
  const int INFINITY = numeric_limits<int>::max();
  vector<int> dp(n + 1, INFINITY);
  dp[0] = -INFINITY;

  for (int i = 0; i < n; i++) {
    int j = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
    if (dp[j-1] < nums[i] && nums[i] < dp[j]) {
      dp[j] = nums[i];
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (dp[i] < INFINITY) {
      ans = i;
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
    std::vector<int> nums = get_words<int>();
    int res = longest_sub_len(nums);
    std::cout << res << '\n';
}
