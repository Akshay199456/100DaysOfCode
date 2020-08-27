/*
-------------------------Question:

In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.

*/

/*
-------------------------My Approaches:

1. Using an array as a buffer to hold elements

We use an array of size equal to the number of columns that are requested in the final array to push the elements into 
the resulting array. Hence, our additonal space here is O(n) in addition to the space required for the final array.

Time complexity: O(mn)
Space complexity: O(mn)

*/

/*
-------------------------Other approaches

1. Same as My Approaches(1) but without additonal buffer [Not coded]

We can do slightly better than My approaches(1) without the use of the buffer. By creating and intializing the array
with the right size before, we can avoid using the buffer.

Time complexity: O(mn)
Space complexity: O(mn)

*/

// My approaches(1)
class Solution {
public:
    vector<vector<int>> manipulateMatrix(vector<vector<int>> nums, int c){
        int count = 0;
        vector<int> list;
        vector<vector<int>> result;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                ++count;
                list.push_back(nums[i][j]);
                if(count == c){
                    vector<int> temp;
                    count = 0;
                    result.push_back(list);
                    list = temp;
                }
            }
        }
        return result;
    }
    
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(r * c != nums.size()* nums[0].size())
            return nums;
        return manipulateMatrix(nums, c);
    }
};