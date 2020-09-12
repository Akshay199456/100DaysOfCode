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
1. Recursive path holding algorithm

In this approach, we hold the path as we go along the tree. We add the current node to the path. Wehen we hit a leaf node,
 we convert the path to an int, get the value and add it to the sum. Else, we traverse the left and right subtrees
 continuosly

Time complexity: O(n * noOfLeafNodes)
Space complexity: O(n)
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


// Other Approaches(1)
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
    int treeTraversal(TreeNode * root, int currValue){
        if(!root->left && !root->right)
            return 10*currValue + root->val;
        else{
            int leftSum = 0, rightSum = 0;
            if(root->left)
                leftSum = treeTraversal(root->left, 10*currValue + root->val);
            if(root->right)
                rightSum = treeTraversal(root->right, 10*currValue + root->val);
            return leftSum + rightSum;
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(root)
            return treeTraversal(root, 0);
        return 0;
    }
};