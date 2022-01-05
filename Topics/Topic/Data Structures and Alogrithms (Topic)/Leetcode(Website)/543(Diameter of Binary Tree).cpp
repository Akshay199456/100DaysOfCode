/*
-------------------------Question:
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
*/

/*
-------------------------    My Approaches:
1. Recursive bottom-up appraoch

We can use a recursive approach in order to solve the problem. If we know the maxDiameter beneath a node, adding the current node allows us to extend the max diameter. As a result, we use this onledge to calculatre the max depth at each
node.

Time Complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

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
    int getDiameter(TreeNode * root, int & diameter){
        if(!root)
            return 0;
        else{
            int leftMaxRoute = getDiameter(root->left, diameter);
            int rightMaxRoute = getDiameter(root->right, diameter);
            diameter = max(diameter, leftMaxRoute + rightMaxRoute);
            return max(leftMaxRoute, rightMaxRoute) + 1;
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getDiameter(root, diameter);
        return diameter;
    }
};