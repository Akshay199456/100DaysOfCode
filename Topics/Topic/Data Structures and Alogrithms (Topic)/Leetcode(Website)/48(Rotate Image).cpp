/*
-------------------------Question:
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

/*
-------------------------    My Approaches:

1. 

While I didn't completely solve this problem for in-place, I was able to solve it for using an extra
matrix and discover the recipe for solving the problem.

The key to this problem is to discover the relationship to rotate it in place. For a 90 degree 
clockwise rotation, the key formula is that newMatrix[i][j] = oldMatrix[j][n-1-i]. However, you
can't use this formula as it is since doing this keeps moving the new values around.
*/

/*
-------------------------    Other approaches: 

1. Better

Taking the recipe we obtained from **My Approaches(1)**, the key is to transform the matrix and then
reverse it per each row in order to get the result matrix that has been rotated by 90 degree. 
Transforming the original matrix results in matrix[i][j] -> matrix[j][i]. Reversing each row then
gives matrix[j][i] -> matrix[j][n-i-1] which is our result matrix.

Time complexity: O(n^2)
Space complexity: O(1)


2. Better

The second approach works by moving each ring starting from the outer edge to the inner core. While
the elements are put in place starting from the top and going clockwise. Swap is applied thrice to
the same element since it contains the new values whenever values are swapped.

Once done with the other rings, the alogrithm moves inward and continues till all elements have been
inserted into their place

Time complexity: O(n^2);
Space complexity: O(1)

*/

// Other approaches(1)
class Solution {
public:
    void transposeMatrix(vector<vector<int>> & matrix){
        // cout<<"\n Transposing matrix \n";
        for(int i = 0; i < matrix.size(); i++)
            for(int j = i; j< matrix.size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void displayMatrix(vector<vector<int>> matrix){
        cout<<"\n Displaying matrix \n";
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
    }
    
    void reverseMatrix(vector<vector<int>> & matrix){
        cout<<"\n Reversing matrix \n";
        for(int i = 0; i < (matrix.size() / 2); i++)
            for(int j = 0; j < matrix.size(); j++)
                swap(matrix[j][i], matrix[j][matrix.size() - i - 1]);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transposeMatrix(matrix);
        // displayMatrix(matrix);
        reverseMatrix(matrix);
        displayMatrix(matrix);
    }
};


// Other appraoches(2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), a = 0, b = n -1;
        while(a < b){
            for(int i = 0; i < b-a; i++){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            
            a++;
            --b;
        }
    }
};