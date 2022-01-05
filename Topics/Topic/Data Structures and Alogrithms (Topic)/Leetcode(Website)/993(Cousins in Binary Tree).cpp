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

1. Traversing through the tree in a DFS approach

We can traverse through the tree and when we hit the values set pair1 and pair2 resepectively. This
way by the time we have iterated through the tree, we would have filled both  pair1 and pair2. The only thing
left is to compare the levels and the parents at the end.

Time complexity: O(n)
Space complexity: O(H) h->height of tree

2. BFS approach

We can also traverse the tree in a BFS approach. With the BFS approach, we traverse the tree in a level by
level manner. At the end of the lvel, we check if we have encountered any of the values x and y. If we 
have only encountered one, then we can return false since both the nodes will not be on the same level.
If we encounter both, we check the parents of those nodes  to see if they are differnet and depending on
that either return true or false. Else, we continue till we hit one of those conditions or the queue is
empty.

Time complexity: O(n)
Space complexity: O(l); l->no of nodes in a level

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode *, TreeNode *>> elementQueue;
        TreeNode * node1, * node2, * parent1, * parent2;
        node1 = node2 = parent1 = parent2 = NULL;
        int nextLevelChildren = 0;
        
        elementQueue.push(make_pair(root, node1));
        ++nextLevelChildren;
        
        while(!elementQueue.empty()){
            
            int currentLevelChildren = nextLevelChildren;
            nextLevelChildren = 0;
            
            while(currentLevelChildren-- > 0){
                pair<TreeNode *, TreeNode *> nodePair = elementQueue.front();
                elementQueue.pop();
                
                if(nodePair.first->left){
                    elementQueue.push(make_pair(nodePair.first->left, nodePair.first));
                    nextLevelChildren++;
                }
                if(nodePair.first->right){
                    elementQueue.push(make_pair(nodePair.first->right, nodePair.first));
                    nextLevelChildren++;
                }
                
                if(nodePair.first->val == x || nodePair.first->val == y){
                    if(!node1){
                        node1 = nodePair.first;
                        parent1 = nodePair.second;
                    }
                    else{
                        node2 = nodePair.first;
                        parent2 = nodePair.second;
                    }
                }
            }
            
            if(node1 && node2){
                if(parent1 != parent2)
                    return true;
                else
                    return false;
            } 
            
            else if((!node1 && node2) || (!node2 && node1))
                return false;
        }
        return false;
    }
};