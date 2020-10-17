/*
-------------------------Question:
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

/*
-------------------------    My Approaches:
1. Graph based dFS

Since each 1 is an island and the relationship between the one's extended the islands, this problem can be interpreted as
a graph based problem. As a result, we can apply DFS here to find the max area of the island as we are exploreing it and
return that as the answer.

Time complexity: O(V^2)
Space complexity: O(V^2)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void recursivelyExplore(int i, int j, vector<vector<int>> & grid, int & currentArea){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j] == 1){
            currentArea +=1;
            grid[i][j] = 0;
            recursivelyExplore(i+1,j,grid, currentArea);
            recursivelyExplore(i-1,j,grid, currentArea);
            recursivelyExplore(i,j+1,grid, currentArea);
            recursivelyExplore(i,j-1,grid, currentArea);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(!grid.size())
            return 0;
        else{
            int maxArea = 0, currentArea = 0;
            for(int i=0; i < grid.size(); i++){
                for(int j=0; j<grid[0].size(); j++){
                    if(grid[i][j] == 1){
                        recursivelyExplore(i,j,grid,currentArea);
                        maxArea = max(maxArea, currentArea);
                        currentArea = 0;
                    }
                }   
            }
            return maxArea;
        }
    }
};