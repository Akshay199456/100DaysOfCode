/*
-------------------------Question:

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

/*
-------------------------My Approaches:
1. Using stack and pushing right node before left node

We can use a stack to push the elements as we go along. We want to make sure that we are inserting th right node first
followed by the left node since that way the left node will be popped first and be printed.

Time complexity: O(n)
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
    void getPreorder(TreeNode * root, vector<int> & result){
        stack<TreeNode *> elementStack;
        elementStack.push(root);
        while(!elementStack.empty()){
            TreeNode * topElement = elementStack.top();
            result.push_back(topElement->val);
            elementStack.pop();
            
            if(topElement->right)
                elementStack.push(topElement->right);
            if(topElement->left)
                elementStack.push(topElement->left);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root)
            getPreorder(root, result);
        return result;
    }
};