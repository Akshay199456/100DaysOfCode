/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/*
-------------------------Other approaches

1. Recursive approach to mirror checking property

The key to solve this problem is to understand what it means for a binary tree to be a mirror
of itself. Two necessary conditions are:

a. The roots must have the same value
b. The left subtree of each tree must be a mirror reflection of the right subtree of each tree.
[Check images for more info]

So, this means that we check each left node of the tree with each right node of the tree and vice
versa. We do this till all the nodes in the left and right subtree from the middle have been 
checked.

Time complexity: O(n)
Space complexity: O(h) -> O(n)
*/



// Other Approaches(1)
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
    bool checkSymmetric(TreeNode * tree1, TreeNode * tree2){
        if(!tree1 && !tree2)
            return true;
        if(!tree1 || !tree2)
            return false;
        return ((tree1->val == tree2->val) && checkSymmetric(tree1->left, tree2->right) && checkSymmetric(tree1->right, tree2->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        else
            return checkSymmetric(root->left, root->right);
    }
};