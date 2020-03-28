/*
-------------------------Question:
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its depth = 3.
*/

/*
-------------------------My Approaches:

1. DFS

This approach uses DFS to get the max level at each node from the right and the left side
and returns the max of the two.

Time complexity: O(n)
Space complexity: O(n)
*/

// My Approaches(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMaxDepth(TreeNode * node, int level){
        if(node){
            int leftDepth = getMaxDepth(node->left, level + 1);
            int rightDepth = getMaxDepth(node->right, level +1);
            return max(leftDepth, rightDepth);
        }
        return level-1;
    }
    
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        else
            return getMaxDepth(root, 1);
    }
};