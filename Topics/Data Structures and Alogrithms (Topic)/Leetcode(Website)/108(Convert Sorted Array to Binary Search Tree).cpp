/*
-------------------------Question:

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/

/*
-------------------------My Approaches:

1. Divide and Conquer

This approach uses the divide and conquer approach to keep adding elements to the tree after
getting the center of each interval of the array. The best way to create a balanced tree is to 
divide the elements into two halfs which are of almost the same length in height. While we keep
adding the middle element, this continues for each interval of the array till all the elements 
are added to the tree.


Time complexity: O(n)
Space complexity: O(h) -> O(n)
*/

// My Approaches(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    void createBalancedBST(TreeNode * & root, int beg, int end, vector<int> nums){
        if(beg > end)
            return;
        else{
            int mid = (beg + end)/2;
            TreeNode * object = new TreeNode(nums[mid]);
            
            if(!root)
                root = object;
            else{
                if(object->val > root->val)
                    root->right = object;
                else
                    root->left = object;
            }
            createBalancedBST(object, beg, mid-1, nums);
            createBalancedBST(object, mid+1, end, nums);
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = NULL;
        if(nums.size() != 0)
            createBalancedBST(root, 0, nums.size() - 1, nums);
        return root;
    }
};