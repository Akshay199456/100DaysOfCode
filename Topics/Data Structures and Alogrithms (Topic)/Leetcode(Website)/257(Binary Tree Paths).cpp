/*
-------------------------Question:

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

/*
-------------------------My Approaches:
1. Recursive approach

We can recursively go through the tree and add the current node to the path. Wehen we encounter a leaf node, we add it
to the currPath and push that into our result. We then backtrack and continue with the other nodes in the same way.

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
    void getPath(vector<string> & resultPath, TreeNode * element, string currPath){
        if(element){
            if(!(element->left) && !(element->right)){
                currPath.append("->"+to_string(element->val));
                resultPath.push_back(currPath);
            }
            else{
                currPath.append("->"+ to_string(element->val));
                getPath(resultPath, element->left, currPath);
                getPath(resultPath, element->right, currPath);
            }
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> resultPath;
        string currPath = "";
        if(root){
            if(root->left || root->right){
                currPath.append(to_string(root->val));
                getPath(resultPath, root->left, currPath);
                getPath(resultPath, root->right, currPath);
            }
            else{
                currPath.append(to_string(root->val));
                resultPath.push_back(currPath);
            }
        }
        return resultPath;
    }
};