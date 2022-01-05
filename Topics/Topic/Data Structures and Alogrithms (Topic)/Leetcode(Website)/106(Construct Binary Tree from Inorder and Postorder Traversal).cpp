/*
-------------------------Question:

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

/*
-------------------------My Approaches:
1. Using same principle as in Pb 105 leetcode but implementing in differnet direction.

This problem used the same conectp that we learned in pb 105  but in a slightly different manner. Here, we are given the inorder
and postorder traversals. In postorder, the nodes are arranged in (Left, Root, Right)  while in inorder the nodes are
arranged in (Left, Root, right). So, we use the inorder array to obtain the no of nodes on the left and the right and
use that information accordingly to set the preorderBeg and preorderEnd accordingly for both the left and the right halves.
To know which node is going to be inserted next, it's always going to be the preorderEnd since preorder is arranged in
(left, right, root) and thus the root is at the end and that will be the first element on the left and right halves to be
inserted

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
    unordered_map<int, int> elementMap;
    void constructMap(vector<int> inorder){
        for(int i = 0; i < inorder.size(); i++)
            elementMap[inorder[i]] = i;
    }
    
    TreeNode * constructTree(int postorderBeg, int postorderEnd, int inorderBeg, int inorderEnd, vector<int> postorder, TreeNode * & root){
        if(postorderBeg > postorderEnd || inorderBeg > inorderEnd){
            return NULL;
        }
        else{
            TreeNode * temp = new TreeNode(postorder[postorderEnd]);
            if(!root)
                root = temp;
            
            int inorderIndex = elementMap[temp->val];
            int nLeft = inorderIndex - inorderBeg;
            temp->left = constructTree(postorderBeg, postorderBeg + nLeft - 1, inorderBeg, inorderIndex-1,postorder, root);
            temp->right = constructTree(postorderBeg+nLeft, postorderEnd - 1, inorderIndex+1, inorderEnd,postorder, root);
            return temp;
        }
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode * root = NULL;
        if(inorder.size()){
            constructMap(inorder);
            return constructTree(0, postorder.size()-1, 0, inorder.size()-1,postorder, root);
        }
        return root;
    }
};