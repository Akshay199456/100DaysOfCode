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

Time complexity: O(mn)
Space complexity; O(mn)
*/

/*
-------------------------Other approaches
1. Setting visited index to 0 instead.

This approach is very similar to My approaches(1). However, the key difference in this approach is that
we can avoid the O(mn) space complexity by instead settign the visited nodes to 0 and explore the path from
there. This way we will only start exploring if a node is 1 and can avoid the time required to index
the visited array and modifying it.

Time compleity: O(mn)
Space complexity: O(max(m,n))
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
                        nIslands++;
                    }
                }
            }
        }
        return nIslands;
    }
};


// Other Approaches(1)
class Solution {
public:
    void explore(int i, int j, vector<vector<char>> & grid){
        if(i >=0 && j>=0 && i < grid.size() && j < grid[i].size()){
            if(grid[i][j] == '1'){
                grid[i][j] = '0';
                explore(i, j + 1, grid);
                explore(i + 1, j, grid);
                explore(i - 1, j, grid);
                explore(i, j - 1, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int nIslands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    explore(i, j, grid);
                    nIslands++;
                }
            }
        }
        return nIslands;
    }
};