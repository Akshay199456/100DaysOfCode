/*
-------------------------Question:
Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.



 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
 

Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000
*/

/*
-------------------------My Approaches:
1. Going through the original matrix column wise and transfering it into a new array

Time complexity: O(mn)
Space complexity: O(mn)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    void transposeMatrix(vector<vector<int>> A , vector<vector<int>> & result){
        int nRows = A.size();
        int nColumns = A[0].size();
        for(int j = 0; j < nColumns; j++){
            vector<int> list;
            for(int i = 0; i < nRows; i++){
                list.push_back(A[i][j]);
            }
            result.push_back(list);
        }
    }
    
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result;
        transposeMatrix(A, result);
        return result;
    }
};