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
the visited array and modifying it and searching indexes that have already been visited. As we get rid of
an island, we move on to another island and keep doing so till all islands have been covered.

Time compleity: O(mn)
Space complexity: O(max(m,n))


2. BFS

We can also solve this approach in a BFS manner. Similar to the Other Approach(1), whenever we encounter
a 1, we set it to 0 and then check its neighbors for any other 1s clearing as we go. The difference here
is that we are going in a BFS manner breadth by breadth. While the outer loop recognizes the start of the
island, the inner loop which uses the queue till empty, uses the queue to get all the neighbors which are
set to 1 and use that to discover the remainign neighbors till all the neighbors have ebeen covered for a 
collection. We then repeat this for the all the island collections.

The neighborCheck is used as an automated way to cover all the neighbors of the current node.

Time complexity: O(mn)
Space complexity: O(mn)
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


// Other Approaches(2)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nIslands = 0;
        queue<pair<int,int>> indexPair;
        vector<int> neighborCheck{0, 1, 0, -1, 0};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    nIslands++;
                    indexPair.push(make_pair(i,j));
                    while(!indexPair.empty()){
                        pair<int, int> element = indexPair.front();
                        indexPair.pop();
                        for( int k = 0 ; k < neighborCheck.size() - 1; k++){
                            int rowIndex = element.first + neighborCheck[k], colIndex = element.second + neighborCheck[k+1];
                            if( rowIndex >= 0 && rowIndex < grid.size() && colIndex >= 0 && colIndex < grid[i].size() && grid[rowIndex][colIndex] == '1'){
                                grid[rowIndex][colIndex] = '0';
                                indexPair.push(make_pair(rowIndex, colIndex));
                            }
                        }
                    }
                }
            }
        }
        return nIslands;
    }
};