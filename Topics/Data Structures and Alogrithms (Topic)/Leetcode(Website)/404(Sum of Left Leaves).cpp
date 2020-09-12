/*
-------------------------Question:

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

/*
-------------------------My Approaches:
1. Recursive Preorder traversal

We can use the preorder traversal here. We want to make sure that we are checking if it's a leaf node first since that allows
us to add the sum if its a left node. Else we continue with the traversal technique.

Time compleixty: O(n)
Space complexity: O(n)
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
    void traverseTree(TreeNode * root, int & sum, int dirn){
        if(!root){}
        else if(!root->left && !root->right){
            if(dirn == -1)
                sum += root->val;
        }
        else{
            traverseTree(root->left, sum, -1);
            traverseTree(root->right, sum, 1);
        }
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root)
            traverseTree(root, sum, 0);
        return sum;
    }
};