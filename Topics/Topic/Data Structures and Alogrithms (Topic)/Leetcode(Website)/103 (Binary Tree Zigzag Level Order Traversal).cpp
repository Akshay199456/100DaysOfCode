/*
-------------------------Question:

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/*
-------------------------My Approaches:

1. Using stack and queue to implement from BFS.

Once we have the BFS layer down of the tree, we can use a stack and a queue in order to store the elements
into these containers as we go layer by layer alternating between the two.

Time complexity: O(n)
Space complexity: O(n)

Instead of using a queue and a stack together, we could rather use a vector and depending on whether 
it's the queue or stack order, we could go through the elements either in the normal or reverse order
and fill it into the result. Same time and space complexity.

2. Reversing odd leveled vectors in result 

The other way we could solve this problem is to initally insert all elements into the result in the order
in which they occur in the queue arranged by level. At the end, we just need to reverse the odd numbered
levels, since odd numbered levels are the ones which are arranged in right to left order and hence need to
be reversed.

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
    void fillInitialQueue(TreeNode * root, queue<pair<int,int>> & initialQueue, int level){
        queue<pair<TreeNode *, int>> tempQueue;
        tempQueue.push(make_pair(root, level));
        
        while(!tempQueue.empty()){
            pair<TreeNode *, int> elementPair = tempQueue.front();
            initialQueue.push(make_pair(elementPair.first->val, elementPair.second));
            tempQueue.pop();
            
            if(elementPair.first->left)
                tempQueue.push(make_pair(elementPair.first->left, elementPair.second + 1));
            
            if(elementPair.first->right)
                tempQueue.push(make_pair(elementPair.first->right, elementPair.second + 1));
        }
    }
    
    void fillVector(queue<pair<int,int>> & initialQueue, vector<vector<int>> & result){
        bool useQueue = true;
        queue<int> tempQueue;
        stack<int> tempStack;
        
        while(!initialQueue.empty()){
            vector<int> tempVector;
            int currentLevel = -1;
            
            if(useQueue){
                if(tempQueue.empty()){
                    tempQueue.push(initialQueue.front().first);
                    currentLevel = initialQueue.front().second;
                    initialQueue.pop();
                }
                
                while(initialQueue.front().second == currentLevel){
                    tempQueue.push(initialQueue.front().first);
                    initialQueue.pop();
                }
                    
                while(!tempQueue.empty()){
                    tempVector.push_back(tempQueue.front());
                    tempQueue.pop();
                }
                useQueue = false;
            }
            
            
            
            else{
                if(tempStack.empty()){
                    tempStack.push(initialQueue.front().first);
                    currentLevel = initialQueue.front().second;
                    initialQueue.pop();
                }
                
                while(initialQueue.front().second == currentLevel){
                    tempStack.push(initialQueue.front().first);
                    initialQueue.pop();
                }
                    
                while(!tempStack.empty()){
                    tempVector.push_back(tempStack.top());
                    tempStack.pop();
                }
                
                useQueue = true;
            }
            
            result.push_back(tempVector);
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root){
            queue<pair<int,int>> initialQueue;
            fillInitialQueue(root, initialQueue, 0);
            fillVector(initialQueue, result);
        }
        return result;
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
    void fillInitialQueue(TreeNode * root, queue<pair<int,int>> & initialQueue, int level){
        queue<pair<TreeNode *, int>> tempQueue;
        tempQueue.push(make_pair(root, level));
        
        while(!tempQueue.empty()){
            pair<TreeNode *, int> elementPair = tempQueue.front();
            initialQueue.push(make_pair(elementPair.first->val, elementPair.second));
            tempQueue.pop();
            
            if(elementPair.first->left)
                tempQueue.push(make_pair(elementPair.first->left, elementPair.second + 1));
            
            if(elementPair.first->right)
                tempQueue.push(make_pair(elementPair.first->right, elementPair.second + 1));
        }
    }
    
    void fillVector(queue<pair<int,int>> & initialQueue, vector<vector<int>> & result){
        while(!initialQueue.empty()){
            pair<int,int> elementPair = initialQueue.front();
            if(elementPair.second >= result.size()){
                vector<int> tempVector;
                tempVector.push_back(elementPair.first);
                result.push_back(tempVector);
            }
            else
                result[elementPair.second].push_back(elementPair.first);
    
            initialQueue.pop();
        }
    }
    
    void reverseVector(vector<vector<int>> & result){
        for(int i = 0; i < result.size(); i++){
            if(i % 2 != 0){
                int innerSize = result[i].size();
                for(int j = 0; j < innerSize / 2; j++){
                    swap(result[i][j], result[i][innerSize - 1 - j]);
                }
            }
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root){
            queue<pair<int,int>> initialQueue;
            fillInitialQueue(root, initialQueue, 0);
            fillVector(initialQueue, result);
            reverseVector(result);
        }
        return result;
    }
};