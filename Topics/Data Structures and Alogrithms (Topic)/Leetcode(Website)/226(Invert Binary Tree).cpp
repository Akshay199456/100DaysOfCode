/*
-------------------------Question:

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/*
-------------------------My Approaches:
1. DFS

We can implement DFS as we solve this problem. The key in this problem is to interchange the left and
right side of each node. As long as we can do that for every node in the tree, we can invert the tree.

Time complexity: O(n)
Space complexity: O(h)


2. BFS

We can implement this approach using BFS as well. Here also we swap the left and right level nodes using
the node at the front of the queue. However, we keep inserting nodes into the queue level by level.

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
    void swapTrees(TreeNode * root){
        if(root){
            TreeNode * temp = root->left;
            root->left = root->right;
            root->right = temp;
            
            swapTrees(root->left);
            swapTrees(root->right);
        }
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root)
            swapTrees(root);
        return root;
    }
};


// My Approaches(2)
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode *> elementQueue;
        if(root){
            elementQueue.push(root);
            while(!elementQueue.empty()){
                TreeNode * element = elementQueue.front(), * temp = NULL;
                elementQueue.pop();
                temp = element->left;
                element->left = element->right;
                element->right = temp;
                
                if(element->left)
                    elementQueue.push(element->left);
                if(element->right)
                    elementQueue.push(element->right);
            }
        }
        return root;
    }
};