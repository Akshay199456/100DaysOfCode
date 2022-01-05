/*
-------------------------Question:

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches
1. Using property of complete binary tree.

In a complete binary tree, we fill the nodes from the left to the right with each level being complete, except the last
level which may or may not be complete. We use this principole in this appraoch to improve the time complexity of our
solution. What we can do is that we can find the height for both the left and right ends by going through the nodes
in left and right fashion respectively. If they are equal, then we know that the subtree is complete, so in that case
we would return pow(2, leftHeight) -1 as that many number of nodes will be in that subtree. However, if they are not 
eaul, we would then calculate the same for its left and right subtree recursively till we get a state where wee hit null or
we get eaul left and right heigh. At the end, we will be skipping the calcualtion for most of the subtrees since there will
be at max only one subtree that differs in height vs the rest. For the others, the simple calcuation of 
pow(2, leftHeight) - 1 will give the answer. 


Time complexity: O(logn * logn)
Space complexity: O(log n)
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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        else{
            int leftHeight = 0, rightHeight = 0;
            TreeNode * left = root, * right = root;
            while(left){
                ++leftHeight;
                left = left->left;
            }
            
            while(right){
                ++rightHeight;
                right = right->right;
            }
            
            if(leftHeight == rightHeight)
                return (1 << leftHeight) - 1;
            else
                return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};