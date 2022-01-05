/*
-------------------------Question:

The boundary of a binary tree is the concatenation of the root, the left boundary, the leaves ordered from left-to-right, and the reverse order of the right boundary.

The left boundary is the set of nodes defined by the following:

The root node's left child is in the left boundary. If the root does not have a left child, then the left boundary is empty.
If a node in the left boundary and has a left child, then the left child is in the left boundary.
If a node is in the left boundary, has no left child, but has a right child, then the right child is in the left boundary.
The leftmost leaf is not in the left boundary.
The right boundary is similar to the left boundary, except it is the right side of the root's right subtree. Again, the leaf is not part of the right boundary, and the right boundary is empty if the root does not have a right child.

The leaves are nodes that do not have any children. For this problem, the root is not a leaf.

Given the root of a binary tree, return the values of its boundary.

 

Example 1:


Input: root = [1,null,2,3,4]
Output: [1,3,4,2]
Explanation:
- The left boundary is empty because the root does not have a left child.
- The right boundary follows the path starting from the root's right child 2 -> 4.
  4 is a leaf, so the right boundary is [2].
- The leaves from left to right are [3,4].
Concatenating everything results in [1] + [] + [3,4] + [2] = [1,3,4,2].
Example 2:


Input: root = [1,2,3,4,5,6,null,null,null,7,8,9,10]
Output: [1,2,4,7,8,9,10,6,3]
Explanation:
- The left boundary follows the path starting from the root's left child 2 -> 4.
  4 is a leaf, so the left boundary is [2].
- The right boundary follows the path starting from the root's right child 3 -> 6 -> 10.
  10 is a leaf, so the right boundary is [3,6], and in reverse order is [6,3].
- The leaves from left to right are [4,7,8,9,10].
Concatenating everything results in [1] + [2] + [4,7,8,9,10] + [6,3] = [1,2,4,7,8,9,10,6,3]
*/

/*
-------------------------    My Approaches:
1. Two pass through the tree

During the first pass through the tree, we can get all the leaves that are in the tree. Doing the second pass through the tree, we now use the information on the leaves to exclude themm from the left and the right boundary based on the
conditions given.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Appraoches(1)
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
    void fillLeaves(TreeNode * root, vector<TreeNode *> & leaves, TreeNode * parent){
        if(parent){
            // if it's a leaf
            if(!parent->left && !parent->right && parent != root)
                leaves.push_back(parent);
            
            fillLeaves(root, leaves, parent->left);
            fillLeaves(root, leaves, parent->right);
        }
    }
    
    void fillMap(TreeNode * root, vector<TreeNode *> & leaves, TreeNode * parent, unordered_map<TreeNode *, int> & leftBoundary, unordered_map<TreeNode *, int> & rightBoundary){
        if(parent){
            // left boundary
            if(leftBoundary.find(parent) != leftBoundary.end()){
                if(parent->left){
                    if(leaves.size() && leaves[0] != parent->left)
                        leftBoundary[parent->left] = leftBoundary.size();
                }   
                else if(parent->right){
                    if(leaves.size() && leaves[0] != parent->right)
                        leftBoundary[parent->right] = leftBoundary.size();
                } 
            }
            
            //right boundary
            else if(rightBoundary.find(parent) != rightBoundary.end()){
                if(parent->right){
                    if(leaves.size() && leaves[leaves.size()-1] != parent->right)
                        rightBoundary[parent->right] = rightBoundary.size();
                } 
                    
                else if(parent->left){
                    if(leaves.size() && leaves[leaves.size()-1] != parent->left)
                        rightBoundary[parent->left] = rightBoundary.size();
                } 
            }
            fillMap(root, leaves, parent->left, leftBoundary, rightBoundary);
            fillMap(root, leaves, parent->right, leftBoundary, rightBoundary);
        }
    }
    
    void fillVectors(unordered_map<TreeNode *, int> leftBoundary, unordered_map<TreeNode *, int> rightBoundary, vector<TreeNode *> & leftVector, vector<TreeNode *> & rightVector){
        // fill left vector
        for(auto it=leftBoundary.begin(); it!= leftBoundary.end(); it++)
            leftVector[it->second] = it->first;
        
        for(auto it=rightBoundary.begin(); it!= rightBoundary.end(); it++)
            rightVector[it->second] = it->first;
    }
    
    void fillSolution(vector<int> & boundary, vector<TreeNode *> leftBoundary, vector<TreeNode *> leaves, vector<TreeNode *> rightBoundary){
        // transfer leftBoundary
        for(int i=0; i<leftBoundary.size(); i++)
            boundary.push_back(leftBoundary[i]->val);
        
        // transfer leaves
        for(int i=0; i<leaves.size(); i++)
            boundary.push_back(leaves[i]->val);
        
        // transfer rightBoundary
        for(int i=rightBoundary.size()-1; i>=0; i--)
            boundary.push_back(rightBoundary[i]->val);
    }
        
    void printVector(vector<TreeNode *> list){
        for(int i=0; i<list.size(); i++){
            cout<<list[i]->val<<" ";
        }
        cout<<endl;
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> boundary (1, root->val);
        vector<TreeNode *> leaves;
        unordered_map<TreeNode *, int> leftBoundary, rightBoundary;
        
        // fills all leaves
        fillLeaves(root, leaves, root);
        
        // fills left Boundary and right Boundary
        if(root->left && leaves[0] != root->left)
            leftBoundary[root->left] = 0;
        if(root->right && leaves[leaves.size() -1] != root->right)
            rightBoundary[root->right] = 0;
        fillMap(root, leaves,root->left, leftBoundary, rightBoundary);
        fillMap(root, leaves,root->right, leftBoundary, rightBoundary);
        
        // transfer everything to vectors
        vector<TreeNode *> leftVector(leftBoundary.size(), NULL), rightVector(rightBoundary.size(), NULL);
        fillVectors(leftBoundary, rightBoundary, leftVector, rightVector);
        
//         cout<<"Printing left boundary vector"<<endl;
//         printVector(leftVector);
//         cout<<"Printing right boundary vector"<<endl;
//         printVector(rightVector);
//         cout<<"Printing leaves vector"<<endl;
//         printVector(leaves);
        
        //fill the solution vector
        fillSolution(boundary, leftVector, leaves, rightVector);
        return boundary;
    }
};