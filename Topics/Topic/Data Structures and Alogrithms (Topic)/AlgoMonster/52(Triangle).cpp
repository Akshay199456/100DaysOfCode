/*
Problem statement:

The problem is to find the minimum path sum from top to bottom if given a triangle. Each step you may move to adjacent numbers on the row below.

Input
triangle: see example
Output
the minimum path sum

Examples
Example 1:
Input:

triangle = [+
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
Output: 11

Explanation:

The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.
*/

/*
-------------------------    My Approaches:
1. combinatorics

    in this approach we use the cmbinatorics approach to generate the state-space tree.
    once we start from the root, we have one of two chocies: either move to the index at the next level or move to the index+1 
    at the next level. this way we cover all possible permutations of the problem and we have a minvalue that evalauts the minimum value
    at the last level of the tree

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
trickiest part of this part is understanding the indexing and which ones correspond to traversing the left branch or the right branch

once you finish playing around with the examples given to you, you might notice that for any 'node' at position triangle[i][j],
the left branch is triangle[i+1][j] and the right branch is trinagle[i+1][j+1]. this becomes extremely apprarent if we left-align the nodes:

1. brute force

    a brute force enumerates through all possibilities such that at each step we rety the left branch and right branch, then figuring out which branch
    gives us the minimum sum. this can be done with a recursive combinatorial search with a time complexity of O(2^n).

    runtime is O(2^n) since for each state we have two choices - go left or go right. the space complexity is O(n) since we have at most O(n) function calls in the 
    memory stack at any given time

2. DFS + memoization

    idea for memoization for this problem comes from the idea that for certain values in triangle, it may be useful for more than one
    future computation. For example, in the diagram, we see that the nodes labelled A and B depend on node C. So intead, of recomputing the value correspondong to node C every time, we can store our result for node C in a memo table.

    since each node can be uniquely identified based on their row and comlum value, memo will be a 2d array where memo[row][col] represents the min path sum up to the node corresponding.

    runtime is O(n^2) since there are O(n^2) states and each state takles O(1) to compute. the space complexity is O(n^2) too due to the use of hte n by n memo table/


3. Bottom up

    Alternatively you can use a bottom-up approach. again the idea of bottom-up is to build our solution from the smallest solutions
    up to the one we want. so, we can start from the last tow and build our way up to the first row. our state and transition remains the same

    State:
        dp[r][c] is the min path sum starting from rth row and cth column
    Transition
        dp[r][c] = min(dp[r-1][c], dp[r-1][c-1]) + triangle[r][c]

    Time complexity: O()
    Space complexity: O()

4. Memory optimization )Optional)

    lastly, we can optimize our memory usage by noticing that our transition only uses information from the row below it. this, for every row, we only need to keep track fo thr row
    below and everything else beyond that is useless. this takes our memory from O(n^2) to O(n)


Additional notes:

the top-down approach here which solves for duplicates works only when we start from the leaf. when we start frm the leaf with the aalgorithm they have
used, duplicates occur. for eg, once we are done with minimum sum possible at the node 5, node 3 and node 4 on the upper layer make use of that minimum
sum for their calculations. as a result, there is a duplicate effort invovled going from the leaf to the top. 
otherwise, if we were going from top to down, i dont think we run into duplicate effort but it would definitely take more time.

*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void getMin(std::vector<std::vector<int>> & triangle, int & minValue, int sum, int index, int level){
    // if we have reached the leaf
    if(level == triangle.size()){
        if(sum < minValue)
            minValue = sum;
        return;
    }
    // if any branch has a sum greater than minValue after it has been set (pruning)
    else if((sum != std::numeric_limits<int>::max()) && (sum > minValue))
        return;
    
    sum  += triangle[level][index];
    getMin(triangle, minValue, sum, index, level+1);
    getMin(triangle, minValue, sum, index+1, level+1);
}

int minimum_total(std::vector<std::vector<int>> triangle) {
    // WRITE YOUR BRILLIANT CODE HERE
    int minValue = std::numeric_limits<int>::max();
    if(!triangle.size())
        return 0;
    
    getMin(triangle,minValue, 0, 0, 0);
    return minValue;
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
    int triangle_length;
    std::cin >> triangle_length;
    ignore_line();
    std::vector<std::vector<int>> triangle;
    for (int i = 0; i < triangle_length; i++) {
        triangle.emplace_back(get_words<int>());
    }
    int res = minimum_total(triangle);
    std::cout << res << '\n';
}
}



//  Other Approaches(1)
int min_path_sum(vector<vector<int>> &triangle, int row, int col) {
  if (row == (int) triangle.size()) {
    return 0;
  }
  int left_sum = min_path_sum(triangle, row + 1, col);
  int right_sum = min_path_sum(triangle, row + 1, col + 1);
  return triangle[row][col] + min(left_sum, right_sum);

}
int minimum_total(vector<vector<int>> &triangle) {
  return min_path_sum(triangle, 0, 0);
}


// Other Approaches(2)
#include <algorithm> // copy, min
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int dfs(std::vector<std::vector<int>>& triangle, int level, int column, std::vector<std::vector<int>>& memo) {
    if (level == triangle.size()) return 0;
    if (memo[level][column] != std::numeric_limits<int>::max()) {
        return memo[level][column];
    }
    int left = dfs(triangle, level + 1, column, memo);
    int right = dfs(triangle, level + 1, column + 1, memo);
    memo[level][column] = std::min(left, right) + triangle[level][column];
    return memo[level][column];
}

int minimum_total(std::vector<std::vector<int>> triangle) {
    int n = triangle.size();
    std::vector<std::vector<int>> memo(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    return dfs(triangle, 0, 0, memo);
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
    int triangle_length;
    std::cin >> triangle_length;
    ignore_line();
    std::vector<std::vector<int>> triangle;
    for (int i = 0; i < triangle_length; i++) {
        triangle.emplace_back(get_words<int>());
    }
    int res = minimum_total(triangle);
    std::cout << res << '\n';
}


// Other Approaches(3)
int minimum_total(vector<vector<int>> &triangle) {
  int n = (int) triangle.size();

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < n; i++) { // first deal with last row
    dp[n - 1][i] = triangle[n - 1][i];
  }

  for (int i = n - 2; i >= 0; i--) { // start from second last row and build up to (0, 0)
    for (int j = 0; j <= i; j++) {
      dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
    }
  }

  return dp[0][0];
}

// Other Approaches(4)
include <algorithm> // copy, min
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

using namespace std;

int minimum_total(vector<vector<int>> triangle) {
  int n = (int) triangle.size();
  // dp[0][...] is current row
  // dp[1][...] is row below
  vector<vector<int>> dp(2, vector<int>(n + 1, 0));
  
  for (int i = 0; i < n; i++) { // first deal with last row
    dp[1][i] = triangle[n - 1][i];
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      dp[0][j] = min(dp[1][j], dp[1][j + 1]) + triangle[i][j];
    }

    for (int j = 0; j <= i; j++) { // swap rows - now dp[0][...] becomes row below
      dp[1][j] = dp[0][j];
    }
  }

  return dp[1][0]; // last swap makes our answer on the second row
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
    int triangle_length;
    std::cin >> triangle_length;
    ignore_line();
    std::vector<std::vector<int>> triangle;
    for (int i = 0; i < triangle_length; i++) {
        triangle.emplace_back(get_words<int>());
    }
    int res = minimum_total(triangle);
    std::cout << res << '\n';
}
