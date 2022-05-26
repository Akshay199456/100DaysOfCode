/*
Problem statement:

Given an array of numbers sorted in ascending order, find the range of a given number ‘key’. The range of the ‘key’ will be the first and last position of the ‘key’ in the array.

Write a function to return the range of the ‘key’. If the ‘key’ is not present return [-1, -1].

Example 1:

Input: [4, 6, 6, 6, 9], key = 6
Output: [1, 3]
Example 2:

Input: [1, 3, 8, 10, 15], key = 10
Output: [3, 3]
Example 3:

Input: [1, 3, 8, 10, 15], key = 12
Output: [-1, -1]

*/

/*
-------------------------    My Approaches:
1. Modifided binary search

    since the array is sorted here, we can apply the modified binary search algorithm.
    if key == mid, then we know we have found one candidate. but there could be other candidtes
    as well so we search on the left and right as well. else we do the usual binary search.

    the time complexity in the worst case is O(n) as you would have to go through all the 
    elements to find the answer.

    Time complexity: O(n)
    Space complexity: O(1)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes

*/



//  My approaches(1)



//  Other Approaches(1)
