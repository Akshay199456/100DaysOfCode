/*
Problem statement:

Suppose we have a m by n matrix filled with non-negative integers, find a path from top left corner to bottom right corner which minimizes the sum of all numbers along its path.

Note: Movements can only be either down or right at any point in time.

Example:
Input:
  [
    [1,3,1],
    [1,5,1],
    [4,2,1]
  ]
Output:
7
Explanation:
Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
*/

/*
-------------------------    My Approaches:
1. combinatorics + dfs

    we can use the combinatorics + dfs approach  to solve this problem. the solution is to get minsum from 0,0
    to r,c. as a result, we calcuate the min at each step along the way starting from r,c as that is the one
    which is the clsoest to destination adn then going to 0,0 from there to build up a solution piece by piece.
    if both the rightsum and bottomum are INT_MAX, then we know that we jave arroved at the answer, so we return 0 instead.

    Time complexity: O(m*n)
    Space complexity: O(m*n)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


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

int getMinSum(std::vector<std::vector<int>> & grid, int currX, int currY, int maxSizeX, int maxSizeY){
    if(currX == maxSizeX || currY == maxSizeY)
        return std::numeric_limits<int>::max();
    
    int rightSum = getMinSum(grid, currX, currY+1, maxSizeX, maxSizeY);
    int bottomSum = getMinSum(grid, currX+1, currY, maxSizeX, maxSizeY);
    
    if(rightSum == std::numeric_limits<int>::max() && bottomSum == std::numeric_limits<int>::max())
        return grid[currX][currY];
    return grid[currX][currY] + std::min(rightSum, bottomSum);
}

int min_path_sum(std::vector<std::vector<int>> grid) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(!grid.size())
        return 0;
    return getMinSum(grid,0,0,grid.size(),grid[0].size());
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
    int grid_length;
    std::cin >> grid_length;
    ignore_line();
    std::vector<std::vector<int>> grid;
    for (int i = 0; i < grid_length; i++) {
        grid.emplace_back(get_words<int>());
    }
    int res = min_path_sum(grid);
    std::cout << res << '\n';
}



//  Other Approaches(1)
