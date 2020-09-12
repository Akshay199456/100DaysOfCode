/*
-------------------------Question:


Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches

*/

// My Approahces(1)
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
    void treeTraversal(TreeNode * root, string currPath, int & totalSum){
        if(!root){}
        else{
            currPath += to_string(root->val);
            if(!root->left && !root->right)
                totalSum += stoi(currPath);
            else{
                treeTraversal(root->left, currPath, totalSum);
                treeTraversal(root->right, currPath, totalSum);
            }
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        if(root)
            treeTraversal(root, "", totalSum);
        return totalSum;
        
    }
};