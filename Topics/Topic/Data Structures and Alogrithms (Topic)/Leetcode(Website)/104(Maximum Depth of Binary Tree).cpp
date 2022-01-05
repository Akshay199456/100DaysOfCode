/*
-------------------------Question:
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its depth = 3.
*/

/*
-------------------------My Approaches:

1. DFS

This approach uses DFS to get the max level at each node from the right and the left side
and returns the max of the two.

Time complexity: O(n)
Space complexity: O(h) -> to clear up, if the tree is skewed the space complexity depends on
the height of the tree which will be of height n; if it's balanced, then the height will be log n.
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

/*
-------------------------Other approaches

1. BFS (Worse)

Using a queue to store the elements as well as their level

Time complexity: O(n)
Space complexity: O(n)
*/

// My Approaches(1)
class Solution {
public:
    int getMaxDepth(TreeNode * node, int level){
        if(node){
            int leftDepth = getMaxDepth(node->left, level + 1);
            int rightDepth = getMaxDepth(node->right, level +1);
            return max(leftDepth, rightDepth);
        }
        return level-1;
    }
    
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        else
            return getMaxDepth(root, 1);
    }
};


// Other Approaches(1)
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
    int getMaxDepth(queue<pair<TreeNode *, int>> q){
        int maxLevel = 1;
        
        while(!q.empty()){
            pair<TreeNode *, int> currentElement = q.front();
            q.pop();
            TreeNode * node = currentElement.first;
            int level = currentElement.second;
            if(level > maxLevel)
                maxLevel = level;
            if(node->left)
                q.push(make_pair(node->left, level+1));
            if(node->right)
                q.push(make_pair(node->right, level+1));
        }
        
        return maxLevel;
    }
    
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        else{
            queue<pair<TreeNode *, int>> q;
            q.push(make_pair(root, 1));
            return getMaxDepth(q);
        }
    }
};