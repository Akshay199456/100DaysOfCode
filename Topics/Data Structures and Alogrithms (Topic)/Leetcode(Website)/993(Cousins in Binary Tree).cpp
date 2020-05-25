/*
-------------------------Question:

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/

/*
-------------------------My Approaches:

1. Traversing through the tree

We can traverse through the tree and when we hit the values set pair1 and pair2 resepectively. This
way by the time we have iterated through the tree, we would have filled both  pair1 and pair2. The only thing
left is to compare the levels and the parents at the end.

Time complexity: O(n)
Space complexity: O(H) h->height of tree
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
    void traverseTree(TreeNode * root, int x, int y, pair<int, TreeNode *> & pair1, pair<int, TreeNode *> & pair2, TreeNode * parent, int level){
        if(root){
            if(root->val == x)
                pair1 = make_pair(level, parent);
            
            else if(root->val == y)
                pair2 = make_pair(level, parent);
            
            else{
                traverseTree(root->left, x, y, pair1, pair2, root, level + 1);
                traverseTree(root->right, x, y, pair1, pair2, root, level + 1);
            }
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode * node1 = NULL, * node2 = NULL, * parent = NULL;
        pair<int, TreeNode *> pair1, pair2;
        traverseTree(root, x, y, pair1, pair2, parent, 0);
        
        if(pair1.first == pair2.first && pair1.second != pair2.second)
            return true;
        return false;
    }
};