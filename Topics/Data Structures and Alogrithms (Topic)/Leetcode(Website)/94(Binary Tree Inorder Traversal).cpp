/*
-------------------------Question:

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

/*
-------------------------My Approaches:

1. Recursively

The recursive solution is pretty simple. The inorder traversal is (node->left), node->val, (node->right)
so we follow that to add elements to the vector.

Time complexity: O(n)
Space complexity: O(log n)
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
    void getInorder(TreeNode * root, vector<int> & result){
        if(!root)
            return;
        else{
            getInorder(root->left, result);
            result.push_back(root->val);
            getInorder(root->right, result);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        getInorder(root, result);
        return result;
    }
};