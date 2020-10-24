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

2. Improved version of My Approaches(1)[Time limit exceeded]

In this version of code, we only calculate the dfs of a path if it has not been calculated. Once we calculate the dfs of a
path, any nodes that we exploreed as part of that dfs also have their path calculated. Thus, we don;t need to compute the 
dfs again and again for thos nodes whos status we already know.

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


// My Approaches(2)
class Solution {
public:
    vector<vector<int>> pacificMatrix;
    vector<vector<int>> atlanticMatrix;
    vector<vector<int>> result;
    
    void defineMatrix(int maxRows, int maxCols){
        for(int i=0; i<maxRows; i++){
            vector<int> list;
            for(int j=0; j<maxCols; j++)
                list.push_back(-1);
            pacificMatrix.push_back(list);
            atlanticMatrix.push_back(list);
        }
    }
    
    bool isValidNeighbor(int i, int j, int maxRows, int maxCols){
        if(i>=0 && j>=0 && i<maxRows && j<maxCols)
            return true;
        return false;
    }
    
    int fillMatrix(int i, int j, vector<vector<int>> matrix, int previousValue, int endI, int endJ, vector<vector<int>> & matrixGeneric){
        if(i==endI || j==endJ || (matrixGeneric[i][j] == 1 && matrix[i][j] <= previousValue)){
            matrixGeneric[i][j] = 1;
            return 1;
        }
        else if(matrixGeneric[i][j] == 0 || (matrixGeneric[i][j] == 1 && matrix[i][j] > previousValue))
            return 0;
        else{
            bool result = false;
            int currValue = matrix[i][j];
            matrix[i][j] = -1;
            if(isValidNeighbor(i+1,j,matrix.size(),matrix[i].size()) && matrix[i+1][j]!=-1 && currValue >= matrix[i+1][j])
                result = fillMatrix(i+1,j,matrix,currValue, endI, endJ, matrixGeneric);
            if(!result && isValidNeighbor(i-1,j,matrix.size(),matrix[i].size()) && matrix[i-1][j]!=-1 && currValue >= matrix[i-1][j])
                result = fillMatrix(i-1,j,matrix,currValue, endI, endJ, matrixGeneric);
            if(!result && isValidNeighbor(i,j+1,matrix.size(),matrix[i].size()) && matrix[i][j+1]!=-1 && currValue >= matrix[i][j+1])
                result = fillMatrix(i,j+1,matrix,currValue, endI, endJ, matrixGeneric);
            if(!result && isValidNeighbor(i,j-1,matrix.size(),matrix[i].size()) && matrix[i][j-1]!=-1 && currValue >= matrix[i][j-1])
                result = fillMatrix(i,j-1,matrix,currValue, endI, endJ, matrixGeneric);
            
            matrixGeneric[i][j] = result;
            return result;
        }
    }
    
    void printMatrix(vector<vector<int>> matrix){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size()){
            defineMatrix(matrix.size(), matrix[0].size());
            for(int i=0; i<matrix.size(); i++){
                for(int j=0; j<matrix[i].size(); j++){
                    if(pacificMatrix[i][j] == -1)
                        fillMatrix(i,j,matrix, -1,0,0, pacificMatrix);
                    if(atlanticMatrix[i][j] == -1)
                        fillMatrix(i,j, matrix, -1, matrix.size()-1, matrix[i].size()-1, atlanticMatrix);
                    
                    if(pacificMatrix[i][j] == 1 && atlanticMatrix[i][j] == 1){
                        vector<int> list{i,j};
                        result.push_back(list);
                    }
                }
            }
        }
        return result;
    }
};