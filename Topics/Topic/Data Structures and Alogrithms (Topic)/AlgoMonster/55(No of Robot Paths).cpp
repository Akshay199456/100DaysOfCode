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
1. comb inatorics + dfs

    we can use the basic combinatorics approach to solve the problem. at each step, we have one fo wo chocies.
    we either move down or right. as a result,  each of those provide us with a unique solution

    Time complexity: O(2^max(m,n))
    Space complexity: O(max(m,n))
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



//  Other Approaches(1)
