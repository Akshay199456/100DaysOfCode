/*
-------------------------Question:

Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

The order of returned grid coordinates does not matter.
Both m and n are less than 150.
 

Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

/*
-------------------------    My Approaches:
1. BFS towards source and destination[Time limit exceeded]

We can apply a BFS both from the element towards the pacific as well as towards the atlantic. If we find a path, we then set
boolean variables. If there is a path for both, we then know that is a valid solution and add it to the result.

Time complexity: O(mn * (mn))
Space complexity: O(max(m,n))
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    vector<vector<int>> result;
    
    bool isConditionSatisfied(vector<vector<int>> matrix, int i, int j, int addX, int addY){
        // cout<<"\tCurrent x: "<<i<<" Current y: "<<j<<" AddX: "<<addX<<" AddY: "<<addY<<endl;
        if(i+addX >= 0 && j+addY >= 0 && i+addX <matrix.size() && j+addY < matrix[0].size() && matrix[i+addX][j+addY] != -1 && matrix[i][j] >= matrix[i+addX][j+addY])
            return true;
        return false;
    }
    
    bool bfs(int startX, int startY, int dirn, vector<vector<int>> matrix){
        queue<pair<int,int>> indexPair;
        indexPair.push(make_pair(startX, startY));
        while(!indexPair.empty()){
            pair<int,int> currentPair = indexPair.front();
            // cout<<"\tFirst: "<<currentPair.first<<" Second: "<<currentPair.second<<endl;
            indexPair.pop();
            
            if(dirn == -1 && (currentPair.first==0 || currentPair.second==0))
                return true;
            else if(dirn == 1 && (currentPair.first==matrix.size()-1 || currentPair.second==matrix[0].size()-1))
                return true;
            else{
                if(isConditionSatisfied(matrix, currentPair.first, currentPair.second, 1, 0))
                    indexPair.push(make_pair(currentPair.first+1, currentPair.second));
                
                if(isConditionSatisfied(matrix, currentPair.first, currentPair.second, -1, 0))
                    indexPair.push(make_pair(currentPair.first-1, currentPair.second));
                
                if(isConditionSatisfied(matrix, currentPair.first, currentPair.second, 0, 1))
                    indexPair.push(make_pair(currentPair.first, currentPair.second+1));
                
                if(isConditionSatisfied(matrix, currentPair.first, currentPair.second, 0, -1))
                    indexPair.push(make_pair(currentPair.first, currentPair.second-1));   
                
                matrix[currentPair.first][currentPair.second] = -1;
            }
        }
        return false;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size()){
            for(int i=0; i<matrix.size(); i++){
                for(int j=0; j<matrix[i].size(); j++){
                    // cout<<"Current element i: "<<i<<" current elemeent j: "<<j<<endl;
                    // cout<<"Exploring Pacific: "<<endl;
                    bool isPacific = bfs(i, j,-1, matrix);
                    // cout<<"isPacific: "<<isPacific<<endl;
                    // cout<<"Exploring Atlantic: "<<endl;
                    bool isAtlantic = bfs(i,j,1, matrix);
                    // cout<<"isAtlantic: "<<isAtlantic<<endl;
                    if(isAtlantic && isPacific){
                        vector<int> list{i,j};
                        result.push_back(list);
                    }
                }
            }
        }
        return result;
    }
};