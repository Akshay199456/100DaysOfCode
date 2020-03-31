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

1. Using queue as a BFS element addition which stores pair of node and the current level

This approaches uses a queue to keep track of the current element and the level they are at.
If we come across a level greater than the number of rows currently, we push in a new array with 
the new element. If the current level is not greater, then we just append it to the level-1 it is at
taking into consideration that the root starts at level 1 and the array starts at 0. We continue
this till the queue is empty.

Time complexity: O(n)
Space complexity: O(h) -> O(n)
*/

/*
-------------------------Other approaches

1. Using queue to store only the node and not the level[Better(from a practical point of view. On
paper, both have O(n) space complexity)] - BFS

This approach is basically My Approaches(1) but uses the queue to only store the next nodes in 
line. It doesn't store the level since that info can be gathered from the no of elements in the 
queue at any instant and hence we can store that level by level

Time complexity: O(n)
Space complexity: O(h) -> O(n)




2. Using DFS inorder[Same]

We can also use DFS to store elements into their proper position in the result. Whenever the level
of the element exceeds the size of the result array, we create a new row and append it. We then
append elements to that row

Time complexity: O(h) 
Space complexity: O(n)-> O(n)




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
    void getLevelOrder(vector<vector<int>> & result, int level, TreeNode * root){
        queue<TreeNode *> elementsQueue;
        elementsQueue.push(root);
        while(!elementsQueue.empty()){
            vector<int> list;
            TreeNode * currentElement;
            int queueSize = elementsQueue.size();
            for(int i = 0 ; i < queueSize; i++){
                currentElement = elementsQueue.front();
                list.push_back(currentElement->val);
                if(currentElement->left)
                    elementsQueue.push(currentElement->left);
                if(currentElement->right)
                    elementsQueue.push(currentElement->right);
                
                elementsQueue.pop();
            }
            result.push_back(list);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root)
            getLevelOrder(result, 0, root);
        
        return result;
        
    }
};



// Other Approaches(2)
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
    void getLevelOrder(TreeNode * node, vector<vector<int>> & result, int level){
        if(!node)
            return;
        
        if(level > result.size()){
            vector<int> list;
            result.push_back(list);
        }
        
        result[level-1].push_back(node->val);
        getLevelOrder(node->left, result, level+1);
        getLevelOrder(node->right, result, level+1);       
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root)
            getLevelOrder(root, result, 1);
        
        return result;
        
    }
};