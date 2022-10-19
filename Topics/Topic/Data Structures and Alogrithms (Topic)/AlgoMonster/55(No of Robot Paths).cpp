/*
Problem statement:

A robot is located at the top-left corner of a m x n grid.



The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 1:
Input: m = 2, n = 3

Output: 3

Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:

Right -> Right -> Down

Right -> Down -> Right

Down -> Right -> Right

Example 2:
Input: m = 5, n = 3

Output: 15

*/

/*
-------------------------    My Approaches:
1. combinatorics + dfs

    we can use the basic combinatorics approach to solve the problem. at each step, we have one fo wo chocies.
    we either move down or right. as a result,  each of those provide us with a unique solution

    Additional:
    in this problem, we can either go from the destinaion to the source and conunt the number of ways
    or we can go like we have done fromt he source to the destination.

    Time complexity: O(2^max(m,n))
    Space complexity: O(max(m,n))


2. Top down + memo

    we can use the top-down approach in order to solve this problem as well. if we observe the brute force approach, there are a few repearted calcualtions that are made
    when we calculate the number of ways. we can store those results so that we return those when we encounter it the next time

    Time complexity: O(m*n)
    Space complexity: O(m*n)

*/


/*
-------------------------    Other Approaches 
1.

this is a 'grid dp' problem. it's an extension of the 'sequence dp' where dp[i] normally represents the max/min/best value for sequence  ending at index i.

the key is that the robot can move to the right or down only. this translates to 'the robot could only reach a caell from top or left'. hence the number
of paths to reach a cell = number of oaths to reach the cell to the left + no of paths to reach the cell at the top.

let dp[r][c] represnet the no of unique paths to reach cell (r,c). (r stands for row, and c stands for column)

dp[r][c] = dp[r-1][c] + dp[r][c-1]

where (r-1,c) is the cell on the left and (r,c-1) is the cell at the top.

not that since for the top row, there's only one way to reahch each cell - from the left. and for the leftmost column, there's aonly one way
to reach each cell - from the top. we pre-poulate them before moving to the internal cells

    Time complexity: O(n*m)
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits

int countPaths(int currX, int currY, int destX, int destY){
    if(currX > destX || currY > destY)
        return 0;
    else if(currX == destX && currY == destY)
        return 1;
    else{
        int nPaths = countPaths(currX+1, currY, destX, destY) + countPaths(currX, currY+1, destX, destY);
        return nPaths;
    }
}

int unique_paths(int m, int n) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(!m && !n)
        return 0;
    return countPaths(0,0,m-1,n-1);
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int m;
    std::cin >> m;
    ignore_line();
    int n;
    std::cin >> n;
    ignore_line();
    int res = unique_paths(m, n);
    std::cout << res << '\n';
}



// My Approaches(2)
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits
#include <vector>

int countPaths(int currX, int currY, int destX, int destY, std::vector<std::vector<int>> & dp){
    if(currX > destX || currY > destY)
        return 0;
    else if(currX == destX && currY == destY)
        return 1;
    else if(dp[currX][currY] != -1)
        return dp[currX][currY];
    else{
        int nPaths = countPaths(currX+1, currY, destX, destY,dp) + countPaths(currX, currY+1, destX, destY,dp);
        dp[currX][currY] = nPaths;
        return dp[currX][currY];
    }
}

int unique_paths(int m, int n) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
    if(!m && !n)
        return 0;
    return countPaths(0,0,m-1,n-1,dp);
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int m;
    std::cin >> m;
    ignore_line();
    int n;
    std::cin >> n;
    ignore_line();
    int res = unique_paths(m, n);
    std::cout << res << '\n';
}



//  Other Approaches(1)
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits

int unique_paths(int m, int n) {
    int dp[n][m];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (row == 0 || col == 0) {
                dp[row][col] = 1;
            } else {
                dp[row][col] = dp[row][col - 1] + dp[row - 1][col];
            }
        }
    }
    return dp[n - 1][m - 1];
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int m;
    std::cin >> m;
    ignore_line();
    int n;
    std::cin >> n;
    ignore_line();
    int res = unique_paths(m, n);
    std::cout << res << '\n';
}