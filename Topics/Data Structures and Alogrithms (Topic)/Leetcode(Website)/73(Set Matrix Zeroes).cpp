/*
-------------------------Question:

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

/*
-------------------------My Approaches:

1. Using vectors to store indexes of 0 [This is not a valid solution to the given problem as the
problem lists to do in place. However, this approach uses additional data structures]

In this approach, we use an additional data structure to store the indexes of the row and the 
column where the element is o. We later use that to fill the matrix to 0 in corresponding
spots.

Time complexity: O(m*n)
Space complexity: O(m+n)



2. Using the first row and column as auxiliary storage

Rather than using an additional array as an auxiliary storage, we can use the first row and column
instead as an auxiliary storage. Initially, we need to store information about the first row and
column to check if they have any eleemnt with 0s. If they do, at the end we will be setting all
the entries in that row or column to 0.

Once we have that information, depending on which elements are set to 0, we indicate their status
into the first row and column of that particular element to indicate that there's a 0 in that
row and column.

Once we have that information, we use that information in the next step to set the elements to 0
depending on whether a 0 was seen in that row or column.

We finally set the entries for the first row and column depending on whether any 0s were originally
noticed in the first row or column

Time complexity: O(m*n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    void findZeroes(vector<vector<int>> matrix, vector<int> & row, vector<int> & column){
        for(int i = 0; i <matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    column[j] = 0;
                }
            }
        }
    }
    
    void fillZeroes(vector<vector<int>> & matrix, vector<int> row, vector<int> column){
        for(int i = 0; i< row.size(); i++){
            if(row[i] == 0){
                for(int j = 0; j < column.size(); j++)
                    matrix[i][j] = 0;
            }
        }
        
        for(int i = 0; i< column.size(); i++){
            if(column[i] == 0){
                for(int j = 0; j < row.size(); j++)
                    matrix[j][i] = 0;
            }
        }
    }
    
    void printVector(vector<int> list){
        for(int i = 0; i<list.size();i ++)
            cout<<list[i]<<" ";
        cout<<endl;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() != 0){
            vector<int> row(matrix.size(), -1), column(matrix[0].size(), -1);
            findZeroes(matrix, row, column);
            //printVector(row);
            //printVector(column);
            fillZeroes(matrix, row, column);
        }
    }
};


// My Approaches(2)
class Solution {
public:
    bool checkFirstRow(vector<vector<int>> matrix){
        for(int i = 0; i < matrix[0].size(); i++)
            if(matrix[0][i] == 0)
                return true;
        return false;
    }
    
    bool checkFirstColumn(vector<vector<int>> matrix){
        for(int i = 0; i < matrix.size(); i++)
            if(matrix[i][0] == 0)
                return true;
        return false;
    }
    
    void generateAuxiliary(vector<vector<int>> & matrix){
        for(int i = 1; i< matrix.size(); i++){
            for(int j = 1; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    
    void setElements(vector<vector<int>> & matrix){
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[i].size(); j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
    }
    
    void setFirstRowAndColumn(vector<vector<int>> & matrix, bool firstRow, bool firstColumn){
        if(firstRow){
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
        
        if(firstColumn){
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
    
    void printMatrix(vector<vector<int>>  matrix){
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() != 0){
            bool firstRow = checkFirstRow(matrix);
            bool firstColumn = checkFirstColumn(matrix);
            generateAuxiliary(matrix);
            setElements(matrix);
            //printMatrix(matrix);
            setFirstRowAndColumn(matrix, firstRow, firstColumn);
        }
    }
};