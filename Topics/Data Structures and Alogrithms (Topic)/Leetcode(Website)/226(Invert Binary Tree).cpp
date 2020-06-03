/*
-------------------------Question:

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/*
-------------------------My Approaches:
1. DFS

We can implement DFS as we solve this problem. The key in this problem is to interchange the left and
right side of each node. As long as we can do that for every node in the tree, we can invert the tree.

Time complexity: O(n)
Space complexity: O(h)
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
    void swapTrees(TreeNode * root){
        if(root){
            TreeNode * temp = root->left;
            root->left = root->right;
            root->right = temp;
            
            swapTrees(root->left);
            swapTrees(root->right);
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root)
            swapTrees(root);
        return root;
    }
};