/*
-------------------------Question:

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/

/*
-------------------------My Approaches:
1. Two level binary search

We can implement a two step binary search implementation to search for an element given our constraints. Since, each row
has elements that are greater than the row before it, we can use the first binary search to search the row where we think
our element might lie. If it is in the range, we can go forward iwith the second binary search to check if the element exists
else we go through the half where we think it might lie.

Time complexity: O(logn + logm)
Space complexity: O(logn + logm)
*/

/*
-------------------------Other approaches
1. Binary search treating 2D matrix as 1D array

We can treat the 2D array as a sorted 1D array and apply binary search on the formular for converting 2D arrays into 1D
arrays.

Time complexity: O(log nm) = O(logn) + O(logm)
Space complexity: O(1)

*/

// My Approaches(1)
class Solution {
public:
    bool columnBinarySearch(vector<int> list, int target, int colStart, int colEnd){
        if(colStart <= colEnd){
            int midCol = colStart + (colEnd-colStart)/2;
            if(list[midCol] == target)
                return true;
            else if(target < list[midCol])
                return columnBinarySearch(list, target, colStart, midCol-1);
            else
                return columnBinarySearch(list, target, midCol+1, colEnd);
        }
        return false;
    }
    
    bool rowBinarySearch(vector<vector<int>> matrix, int target, int rowStart, int rowEnd){
        if(rowStart <= rowEnd){
            int midRow = rowStart + (rowEnd-rowStart)/2;
            if(target>=matrix[midRow][0] && target<=matrix[midRow][matrix[midRow].size() - 1])
                return columnBinarySearch(matrix[midRow], target, 0, matrix[midRow].size() - 1);
            else if(target < matrix[midRow][0])
                return rowBinarySearch(matrix, target, rowStart, midRow-1);
            else
                return rowBinarySearch(matrix, target, midRow+1, rowEnd);
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size())
            return false;
        return rowBinarySearch(matrix, target, 0, matrix.size()-1);
    }
};