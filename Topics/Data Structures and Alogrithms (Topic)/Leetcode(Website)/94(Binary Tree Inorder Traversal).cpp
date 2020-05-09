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

1. Solving recursively

The recursive solution is pretty simple. The inorder traversal is (node->left), node->val, (node->right)
so we follow that to add elements to the vector.

Time complexity: O(n)
Space complexity: O(log n)
*/

/*
-------------------------Other approaches

1. Solving iteratively

We can solve this problem iteratively as well. Instead of the recursion stack which helps in solving this
problem recursively, we will make use of a normal stack instead. If we observe the problem carefully for
recursion, we know that as long as there exists a left node, we keep moving towards left and left. While 
solving it iteratively, we also do it. In addition, we keep track  of the parent node as we keep moving
along in a stack. When we hit null, we now know that, we must print the element as required for the 
inorder traversal. So we store the value at the top of the stack into the result as that is the inorder
traversal. We assign that as our current node and move along its right tree instead. We keep repeating
this as long as the stack is not empty or node is not null.


Time complexity: O(n)
Space complexity; O(log n) -> stores depth of the tree at max
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


// Other approaches(1)
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> elementStack;
        TreeNode * current = root;
        while(current || !elementStack.empty()){
            while(current){
                elementStack.push(current);
                current = current->left;
            }
            
            current = elementStack.top();
            result.push_back(current->val);
            elementStack.pop();
            current = current->right;
        }
        return result;
    }
};