/*
-------------------------Question:

Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4
 

Constraints:

The number of nodes in the given tree will be between 0 and 10^4.
Each node will have a unique integer value from 0 to -10^8, inclusive.
-10^8 <= val <= 10^8
It's guaranteed that val does not exist in the original BST.
*/

/*
-------------------------My Approaches:
1. Recursive approach

This approach is pretty straight forward. As we traverse through the tree, we keep track of the dirn we are going. When
we hit a null, we know that the node before it is where the value should be inserted. So, we use the direction to insert
the node in its place.

Time complexity: O(h) -> O(n)
Space complexity: O(h) -> O(n)
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
    void traverseBST(TreeNode * & curr, TreeNode * parent, TreeNode * newNode, int dirn){
        if(!curr){
            if(dirn == -1)
                parent->left = newNode;
            else
                parent->right = newNode;
        }
        else{
            if(curr->val < newNode->val)
                traverseBST(curr->right, curr, newNode, 1);
            else
                traverseBST(curr->left, curr, newNode, -1);
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * newNode = new TreeNode(val);
        if(!root)
            root = newNode;
        else
            traverseBST(root, NULL, newNode, 0);
        return root;
    }
};