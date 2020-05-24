/*
-------------------------Question:

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

 

Constraints:

The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/

/*
-------------------------My Approaches:
1. Using inorder array

For a BST, an inorder traversal gives a sorted array. So we can construct the inorder array and then use
that information to return the element at k-1 index which will satisfy the ocndition.

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
    void createInorder(TreeNode * root, vector<int> & inorder){
        if(root){
            createInorder(root->left, inorder);
            inorder.push_back(root->val);
            createInorder(root->right, inorder);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        createInorder(root, inorder);
        return inorder[k-1];
        
    }
};