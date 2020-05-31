/*
-------------------------Question:

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

/*
-------------------------My Approaches:
1. DFS algorithm

At the end of the day, if you think about it, the goal of this problem is to find the number of collections
of 1s which indicate the islands. As a result, if we encounter a 1, we keep exploring the path till we 
hit 0s or have visted paths that have already been visited. When we finally enter a pause in the islands,
we increment the number of islands and continue to do so till we have exploreed all the isalnd paths

Time complexity:
Space complexity; 
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    void explore(int i, int j, vector<vector<char>> grid, vector<vector<bool>> & visited){
        if(i < visited.size() && j < visited[i].size() && !visited[i][j]){
            visited[i][j] = true;
            if(grid[i][j] == '1'){
                explore(i, j + 1, grid, visited);
                explore(i + 1, j, grid, visited);
                explore(i - 1, j, grid, visited);
                explore(i, j - 1, grid, visited);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // vector<vector<bool>> visited(false, vector<bool>(false));
        vector<vector<bool>> visited;
        for(int i = 0 ; i < grid.size(); i++){
            vector<bool> list;
            for(int j = 0; j < grid[i].size(); j++)
                list.push_back(false);
            visited.push_back(list);
        }
        
        int nIslands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(!visited[i][j]){
                    visited[i][j] = true;
                    if(grid[i][j] == '1'){
                        explore(i, j + 1, grid, visited);
                        explore(i + 1, j, grid, visited);
                        explore(i - 1, j, grid, visited);
                        explore(i, j - 1, grid, visited);
                        nIslands++;
                    }
                }
            }
        }
        return nIslands;
    }
};