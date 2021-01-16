/*
-------------------------Question:

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.
*/

/*
-------------------------    My Approaches:
1. Dynamic Programming

If we think about this problem, there is a brtue force approach to solve it. That is to find all the paths from start to finish, store it into a map and check for uniquenesds. That way we get to know the no of unique paths by travelling 
through all possible paths. However, this is a very inefficient solution as there could be up to 2^(m+n-1) possible paths.

However, if we anayze the possible paths for a few cases, we get to see a few patterns emerge. To get from any point to any point on either the same row or the same column will only have one path as the robot can only move right
and down. Using this, we can extend to other cases and notice that the solution for each step (i,j) depends on the step (i-1,j) and (i,j-1) as the only way to get to (i,j) is from these two points. So, in order to know the no of steps
we need to get to (i,j), we need to know the no of steps it takes to get to (i,j-1) and (i-1,j) and sum them up. We can extend these till we arrive at the begoinning. As a result, this is a aDP problem as the solution for the current
sub-problem is obtained by analzying the solutioins for the previous subproblems.

Time complexity: O(mn)
Space complexity: O(mn)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    int totalPaths(int m, int n){
        vector<vector<int>> dpMatrix;
        
        for(int i=0; i<m; i++){
            vector<int> list;
            for(int j=0; j<n; j++)
                list.push_back(1);
            dpMatrix.push_back(list);
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dpMatrix[i][j] = dpMatrix[i][j-1] + dpMatrix[i-1][j];
            }
        }
        
        return dpMatrix[m-1][n-1];
    }
    
    int uniquePaths(int m, int n) {
        if(m == 1 || n ==1)
            return 1;
        return totalPaths(m,n);
    }
};