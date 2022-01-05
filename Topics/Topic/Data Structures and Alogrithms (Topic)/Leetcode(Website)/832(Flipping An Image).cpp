/*
-------------------------Question:

Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/

/*
-------------------------    My Approaches:
1. Changing in place

We can change the elements in place instead by doing both the steps in one pass instead of two passes.

Time complexity: O(rc)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// MY Approaches(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0; i<A.size(); i++){
            int limit = (A.size()%2==0) ? A.size()/2: (A.size()+1)/2 ;
            for(int j=0; j<limit; j++){
                if(j == A.size()-1-j)
                    A[i][j] = 1-A[i][j];
                else{
                    int temp = 1-A[i][j];
                    A[i][j] = 1-A[i][A.size()-1-j];
                    A[i][A.size()-1-j] = temp;
                }
            }
        }
        return A;
    }
};