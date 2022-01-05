/*
-------------------------Question:

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Using recursion and assuming each node to be the start of the subtree

To chceck if one subtree is equal to another subtree we can assume that the subtree begins at a certain node and then compare the two trees for complete equlaity. If they are equal, then we have found our answer. If not, we then do the
same for the the next node and cover all of the nodes of s in this process till we find an answer to the problem.

Time complexity: O(mn)
Space complexity: O(m) where m is the number of nodes in s.
*/

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
    bool checkTreesEqual(TreeNode * s, TreeNode * t){
        if(!s && !t)
            return true;
        if(!s || !t)
            return false;
        
        return (s->val == t->val) && checkTreesEqual(s->left, t->left) && checkTreesEqual(s->right, t->right);
    }
    
    bool checkSubtree(TreeNode * s, TreeNode * t){
        return s && (checkTreesEqual(s,t) || checkSubtree(s->left, t) || checkSubtree(s->right, t));
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return checkSubtree(s, t);
    }
};