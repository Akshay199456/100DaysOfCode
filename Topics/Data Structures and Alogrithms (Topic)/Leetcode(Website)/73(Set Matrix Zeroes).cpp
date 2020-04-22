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
*/

/*
-------------------------Other approaches

*/


// My Approach(1)
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