/*
-------------------------Question:

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/

/*
-------------------------My Approaches:
1. Recursive Approach

We can check the solution for this problem using a recursive approach. The key here is to indentify the base cases as well
as traverse the trees at the same time in the same direction. That is why, we only use one function to simulteneosuly
travel through both the trees and check for values. The base case is when both trees are null or either one is null.

Time complexity: O(min(m,n))
Space complexity: O(min(log m, log n))
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkSameTree(TreeNode * p, TreeNode * q){
        if(!p && !q)
            return true;
        else if((!p && q) || (p && !q))
            return false;
        else
            return p->val == q->val && checkSameTree(p->left, q->left) && checkSameTree(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSameTree(p,q);
    }
};