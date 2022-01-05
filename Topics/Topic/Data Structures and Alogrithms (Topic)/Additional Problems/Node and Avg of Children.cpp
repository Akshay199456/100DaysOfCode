/*
-------------------------Question:

Given a binary tree, check if each node is the average of its direct children.
For example: In the tree below each node has a value which is the average of the values of its direct children

          4
         / \
        2   6
       /   / \
      2   3   9
  
Node 4 = (2+6) / 2
Node 2 = 2 / 1
Node 6 = (3+9) / 2
*/

/*
-------------------------My Approaches:
1. Recursive approach



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
    int checkSubtreeAverage(TreeNode * root, bool & isValid){
        if(!root->left && !root->right){
            
        }
        else if(root->right &&!root->left){
            int rightSum = checkSubtreeAverage(root->right, isValid);
            isValid = isValid && (root->val == rightSum);
        }
        else if(root->left &&!root->right){
            int leftSum = checkSubtreeAverage(root->left, isValid);
            isValid = isValid && (root->val == leftSum);
        }
        else{
            int leftSum = checkSubtreeAverage(root->left, isValid);
            int rightSum = checkSubtreeAverage(root->right, isValid);
            isValid = isValid && (2*root->val == leftSum + rightSum);
        }
            
        return root->val;
    }
    
    bool isValidAverageTree(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return true;
        else{
            bool isValid = true;
            checkSubtreeAverage(root, isValid);
            return isValid;
        }
    }
};