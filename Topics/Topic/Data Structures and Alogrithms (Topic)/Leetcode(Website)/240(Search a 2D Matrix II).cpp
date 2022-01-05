/*
-------------------------Question:

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches
1. Using the properties of the problem

From the problem statement, we know that each row is sorted left to right and each column is sorted from top to bottom.
So, what we can do is start from the bottem left or top-right elements and continue the search from theere. The reason
these two are good starting points is that, they are both the smallest/largest element in their rows and columns. We can
therefore use that information to navigate thhrough the array to search for the element we are interested in. In  my case,
I have chosen the bottom left. If that is the element that we are looking for, we reutn true. Else, if the target is less
that the current element, we move to the right, meaning the next column as the next greater element can only be obtianed
if we move right from our current posisiton. Similarly, if we encounter target less than the current element, we know that
it can't be from the same row since we have been moving towards the right to find the value, so we must move upwards
instead to find the lement we are interested in.

The reason we move towards the right is that since we know that the target is greater, if we want to find a greater element
then we have to ove towards the right as going upwards will only give us a smaller value as the colujmn in sorted and we 
have encountered all the values below it till then which is why we are in the current position so it won't be there.
Simialry, if we want to move upwards since we now that the target is smaller, we have to find a smalelr element. There is no
use moving towards the left of the current row since we have alreayd encountered those elemnts which is whay wer are in that
current position. The onyl way to find a smaller element would be to go upwards.


Time complexity: O(m+n)
Space complexity: O(1)
*/


// Other Approaches(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        else{
            int row = matrix.size()-1;
            int col = 0;
            while(col < matrix[0].size() && row >= 0){
                if(matrix[row][col] == target)
                    return true;
                else if(target > matrix[row][col])
                    col += 1;
                else
                    row -= 1;
            }
            return false;
        }
    }
};