/*
*/

/*
*/

/*
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