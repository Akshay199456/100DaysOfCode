/*
Problem statement:

Given a BST, output the k closest values in this BST to x. Sort the output by value.

The output set is guaranteed to be unique.

Do not convert the BST to a list.

Input
bst: a valid BST of size n.
x: an integer representing the number to find the k closest numbers to.
k: an integer.
Output
A list of integers containing the k closest numbers to x.

Examples
Example 1:
Input:

bst = <See explanation>
x = 7
k = 4
Output: [5, 6, 8, 10]

Explanation:



All four numbers in the output are within 3 away from 7.

Constraints
1 <= k <= n <= 10^5
*/

/*
-------------------------    My Approaches:
1. my approach [doesnt follow all conditions][not coded]

    well this approach will break one fo the ocnditions that has been setup by the program which is to not convert bst into list. 

    the way i would oslve it is to basically get the bst into a list. we can then use binary search to find where exactly the element would be situated if it were part of the bst.
    once we have the index, then we start taking one index from the left and right. we compare and see which is the smallest and add that to the result and push the index further back for whichever
    was the smallest. we continue to do this till we get all k closest values and contiunue to amekt he comparisona nd push the indexes. if we reach the end of the indexes on either end, we just take the rest of the values
    from the other side of the list. 

    Time complexity: O(n)
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
