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
1. Recursive approach without using memory for storing paths

We can accomplish the same process as we implemented in our approaches but without using arrays to store the path. In this
approach, we first find both the nodes that we are interested in and then backtrack to find the LCA of them. So, if we hit
a null node, we return 0. For each ode, we check th eleft, right and the current node to keep track of the LCA. 
We return 1 if we are at any one of the nodes since we have found it. If our left + right + curr == 2, we know that we have 
encountered both the nodes through this node so this must be the answer. At the end, we return status of whether we have
found any of the nodes to the previous level

Time complexity: O(n)
Space complexity: O(n)


2. Using parent pointers[Not coded]

If we have access tot he parent pointers, we can use that info to backtrack the nodes to find the first common point 
between the two nodes. As we are going through the tree, we store the parent pointers into a parent hashmap. To find the
common point between the two paths of pointers, we use a set to store the parent pointers of p and then go through it with
the parents of q to find the first common point.

Time complexity: O(n)
Space complexity: O(n)


3. Keeping track of LCA as we are going along

We can also keep track of the LCA as we are going along. This approach is also built on the approach of finding the nodes
first followed by then tracking tha ancestors to find LCA. Once we encnounter the first node, that becomes our LCA. If the
second node is a child somewhere from the first node, then once we find the seocnd node, we return that as the LCA. However,
if our second node is not a child of the first node, then our LCA will be a parent of both the first node and the second
node at some parent level. We use this logic to change the LCA once we find the first node and are looking for the second
node. Once we find botht he nodes, we return that lca at that point.

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
    TreeNode * ans;
public:
    int getPath(TreeNode * root, TreeNode * p, TreeNode * q){
        if(!root)
            return 0;
        else{
            int left = getPath(root->left, p, q);
            int right = getPath(root->right, p, q);
            int curr = (root == p) || (root == q) ? 1 : 0;
            
            if(curr + left + right == 2)
                ans = root;
            
            return (curr+left+right > 0)  ? 1 : 0; 
        }
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        else{
            getPath(root, p, q);
            return ans;
        }
    }
};


// Other Approaches(3)
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
    TreeNode * ans;
public:
    void traverseTree(TreeNode * root, TreeNode * p, TreeNode * q, stack<pair<TreeNode *, int>> elementStack){
        bool firstFound = false, allFound = false;
        TreeNode * nodeFirstVisited = NULL;
        while(!elementStack.empty() && !allFound){
            pair<TreeNode *, int> top = elementStack.top();
            /*
            cout<<"Top element: "<<top.first->val<<" Status: "<<top.second<<endl;
            if(ans)
                cout<<"Ans: "<<ans->val<<endl;
            */
            if(top.first == p || top.first == q){
                if(!firstFound){
                    firstFound = true;
                    ans = top.first;
                    
                    if(top.first == p)
                        nodeFirstVisited = p;
                    else
                        nodeFirstVisited = q;
                }
                else if(firstFound){
                    if((top.first == p && nodeFirstVisited == q) || (top.first == q && nodeFirstVisited == p))
                        allFound = true;
                }
            }
            
            
            if(!allFound && top.second == 0){
                elementStack.top() = make_pair(top.first, 1);
                if((top.first)->left)
                    elementStack.push(make_pair((top.first)->left, 0));
            }
            
            else if(!allFound && top.second == 1){
                elementStack.top() = make_pair(top.first, 2);
                if((top.first)->right)
                    elementStack.push(make_pair((top.first)->right,0));
            }
            
            else if(!allFound && top.second == 2){
                elementStack.pop();
                if(top.first == ans){
                    ans = (elementStack.top()).first;
                }
            }
        }
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        else{
            stack<pair<TreeNode *, int>> elementStack;
            elementStack.push(make_pair(root,0));
            traverseTree(root, p, q, elementStack);
            return ans;
        }
    }
};