/*
-------------------------Question:

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

/*
-------------------------My Approaches:
1. Using graph based approach

We can think of this problem as a graph based problem as each value symbolizes the sum and the relaitionship between cells 
is the path. Since there exists a relationship between cells, we can think of graph techniques here.

With graph, we can think of the dfs approach where we explore every path in the tree and find the min of all paths that
take us from the source to the destination and return that sum accoridngly.

Time complexity: O(2^(m+n))
Space complexity: O(m+n)
*/

/*
-------------------------Other approaches
1. Using DP approach

Since this is an optimizatiuon based problem, dp could be an interesting choice here. To confirm that's its a dp based
problem, we want to make sure that thhere are recursive subproblems to the problem. We have covered this is good detail
in 'Helping Images'.

Time complexity: O(mn)
Space complexity: O(mn)
*/

// My Approaches(1)
class Solution {
public:
    vector<vector<int>> gridCopy;
    void getMinPathSum(int x, int y, int destX, int destY, int currSum, int & minSum){
        if(x > destX || y > destY){
            
        }
        
        else{
            currSum += gridCopy[x][y];
            // cout<<"x: "<<x<<" y: "<<y<<" destX: "<<destX<<" destY: "<<destY<<" currSum: "<<currSum<<" minSum: "<<minSum<<endl;
            if(x == destX && y == destY)
                minSum = min(minSum, currSum);
            else{
                getMinPathSum(x,y+1,destX, destY,currSum, minSum);
                getMinPathSum(x+1,y,destX, destY,currSum, minSum);
            }
        }
    }
    
    void constructGridCopy(vector<vector<int>> grid){
        for(int i= 0; i < grid.size(); i++){
            vector<int> list;
            for(int j = 0; j < grid[0].size();j++)
                list.push_back(grid[i][j]);
            gridCopy.push_back(list);
        }
    }
    
    int minPathSum(vector<vector<int>>& grid){
        if(!grid.size())
            return 0;
        else{
            constructGridCopy(grid);
            int nRows = grid.size(), nCols = grid[0].size();
            int destX = nRows-1, destY = nCols-1;
            int minSum = INT_MAX, currSum = 0;
            getMinPathSum(0,0,destX, destY,currSum, minSum);
            return minSum;
        }
    }
};


// Other Approaches(1)
class Solution {
public:
    void printDpMatrix(vector<vector<int>> matrix, int nRows, int nCols){
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int constructDpTable(vector<vector<int>> grid){
        int nRows = grid.size(), nCols = grid[0].size();
        vector<vector<int>> dp;
        
        for(int i = 0; i < nRows; i++){
            vector<int> list;
            for(int j = 0; j < nCols; j++)
                list.push_back(0);
            dp.push_back(list);
        }
        
        // fill dp[0][0]
        dp[0][0] = grid[0][0];
        
        // fill remaining entries
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                if(!(i == 0 && j == 0)){
                    if(i == 0)
                        dp[i][j] = dp[i][j-1] + grid[i][j];
                    else if(j==0)
                        dp[i][j] = dp[i-1][j] + grid[i][j];
                    else
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        
        // printDpMatrix(dp, nRows, nCols);
        
        return dp[nRows-1][nCols-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;
        else
            return constructDpTable(grid);
    }
};