/*
-------------------------Question:

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
*/

/*
-------------------------My Approaches:
1. Getting path to nodes and comparing paths

A brute force of solving this problem is to get paths from the root to the nodes. Once we have the paths, it becomes more 
of an easy problem. We can compare the paths to find the point of disconnect and the node before which the paths disconnect
is the LCA. Else we incrementing pointer to the next node.

Time complexity: O(n) + O(n) + O(n) -> O(n)
Space complexity: O(n)

2. More efficient way of getting paths

The bottle neck in the previous approach was that we were going through the tree twice, once for p and the other for q 
in order to generate the path. If you think about it, you need to go through the tree only once if you want to get the path
from the root to any node. As a result, when we get the path, we can store that info corresponding to the node. This works
since we know that every node exists in the tree so we will have a valid solution. We can then compare the nodes like we
did before

Time complexity: O(n) + O(n) -> O(n)
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<TreeNode *> pPath;
    vector<TreeNode *> qPath;
public:
    void getPath(TreeNode * root, TreeNode * element, int count, vector<TreeNode *> path){
        if(!root){
            
        }
        else{
            path.push_back(root);
            if(root == element){
                if(count == 0)
                    pPath = path;
                else
                    qPath = path;
            }
            else{
                getPath(root->left, element, count, path);
                getPath(root->right, element, count, path);
            }
        }
    }
    
    void printPath(vector<TreeNode *> path){
        for(int i = 0; i <path.size(); i++)
            cout<<path[i]->val<<" ";
        cout<<endl;
    }
    
    TreeNode * findCommonAncestor(vector<TreeNode *> pPath, vector<TreeNode *> qPath){
        int ptr = 0;
        bool isFound = false;
        while(ptr < min(pPath.size(), qPath.size()) && !isFound){
            if(pPath[ptr] == qPath[ptr])
                ptr++;
            else
                isFound = true;
        }
        return pPath[--ptr];
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        else{
            vector<TreeNode *> path;
            getPath(root, p, 0, path);
            getPath(root, q, 1, path);
            return findCommonAncestor(pPath, qPath);
            // printPath(pPath);
            // printPath(qPath);
        }
    }
};


// My Approaches(2)
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
    vector<TreeNode *> pPath;
    vector<TreeNode *> qPath;
public:
    void getPath(TreeNode * root, TreeNode * p, TreeNode * q, vector<TreeNode *> path){
        if(!root){
            
        }
        else{
            path.push_back(root);
            if(root == p)
                pPath = path;
            else if(root == q)
                qPath = path;
            
            getPath(root->left, p, q, path);
            getPath(root->right, p, q, path);
        }
    }
    
    void printPath(vector<TreeNode *> path){
        for(int i = 0; i <path.size(); i++)
            cout<<path[i]->val<<" ";
        cout<<endl;
    }
    
    TreeNode * findCommonAncestor(vector<TreeNode *> pPath, vector<TreeNode *> qPath){
        int ptr = 0;
        bool isFound = false;
        while(ptr < min(pPath.size(), qPath.size()) && !isFound){
            if(pPath[ptr] == qPath[ptr])
                ptr++;
            else
                isFound = true;
        }
        return pPath[--ptr];
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        else{
            vector<TreeNode *> path;
            getPath(root, p, q, path);
            return findCommonAncestor(pPath, qPath);
            // printPath(pPath);
            // printPath(qPath);
        }
    }
};