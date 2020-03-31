/*
-------------------------Question:

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/*
-------------------------My Approaches:

1. Using queue as a BFS element addition

This approaches uses a queue to keep track of the current element and the level they are at.
If we come across a level greater than the number of rows currently, we push in a new array with 
the new element. If the current level is not greater, then we just append it to the level-1 it is at
taking into consideration that the root starts at level 1 and the array starts at 0. We continue
this till the queue is empty.

Time complexity: O(n)
Space complexity: O(n)
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
class Solution {
public:
    void getLevelOrder(vector<vector<int>> & result, queue<pair<TreeNode *, int>> elementQueue, int nRows){
        while(!elementQueue.empty()){
            pair<TreeNode *, int> elementPair = elementQueue.front();
            TreeNode * element = elementPair.first;
            int level = elementPair.second;

            if(level > nRows){
                vector<int> list;
                list.push_back(element->val);
                result.push_back(list);
                nRows++;
            }      
            else
                result[level-1].push_back(element->val);

            elementQueue.pop();
            if(element->left)
                elementQueue.push(make_pair(element->left, level+1));
            if(element->right)
                elementQueue.push(make_pair(element->right, level+1));
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<pair<TreeNode * , int>> elementQueue;
        int nRows = 0;
        if(root){
            elementQueue.push(make_pair(root, 1));
            getLevelOrder(result, elementQueue, nRows);
        }
        return result;
        
    }
};