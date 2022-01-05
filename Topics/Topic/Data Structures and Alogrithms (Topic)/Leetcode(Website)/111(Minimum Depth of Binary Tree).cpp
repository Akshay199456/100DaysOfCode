/*
-------------------------Question:
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/

/*
-------------------------My Approaches:
1. Recursive preordertraversal constructing answer from bottom-up.

When we encounter a leaf node,we can return 1 to the previous level. Else, we assign the left and right initially to be 
INT_MAX. If the current level node has a left, we explore it and update left accordingly. The same applies to the right
side as well.

Time complexity: O(n)
Space complexity: O(h)->O(n)
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
    int getMinDepth(TreeNode * root){
        if(!root->left && !root->right)
            return 1;
        else{
            int left = INT_MAX, right = INT_MAX;
            if(root->left)
                left = getMinDepth(root->left) + 1;
            if(root->right)
                right = getMinDepth(root->right) + 1;
            return min(left, right);
        }
    }
    
    int minDepth(TreeNode* root) {
        if(root){
            return getMinDepth(root);
        }
        return 0;
    }
};