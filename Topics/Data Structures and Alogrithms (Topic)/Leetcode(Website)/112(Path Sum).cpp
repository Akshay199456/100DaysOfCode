/*
-------------------------Question:

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

/*
-------------------------My Approaches:
1. Recursive preorder traversal

We can use the preorder traversal here. If it's a null, we return false. Else we check for it its a leaf node. If it is,
we check if the currsum ==  targetSum and return true/false depending on that result. Else, we do a recursive search on the
left and right subtree.

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
    bool treeTraversal(TreeNode * root, int targetSum, int currSum){
        if(!root)
            return false;
        else{
            currSum += root->val;
            if(!root->left && !root->right){
                if(currSum == targetSum)
                    return true;
                return false;
            }
            
            return treeTraversal(root->left, targetSum, currSum) || treeTraversal(root->right, targetSum, currSum);
        }
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        return treeTraversal(root, sum, 0);
    }
};