/*
-------------------------Question:

Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].
*/

/*
-------------------------My Approaches:
1. Recursive post order traversal

We use the post order traversal here in order to solve the problem. Basically, we return the level of the previous node
and use that info to push the current node into its right place in the final result. When we hit null, we return -1. Else
at each level, we return the 1+max(leftTree, rightTree) and use that info to push the element into its place.

Time complexity: O(n)
Space complexity:O(n)
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
    vector<vector<int>> result;
    
    int traverseTree(TreeNode * root){
        if(!root)
            return -1;
        else{
            int leftLevel = traverseTree(root->left);
            int rightLevel = traverseTree(root->right);
            int currLevel = max(leftLevel, rightLevel) + 1;
            
            if(currLevel == result.size()){
                vector<int> list;
                list.push_back(root->val);
                result.push_back(list);
            }
            
            else
                result[currLevel].push_back(root->val);
            return currLevel;
        }
    }
    
    void printResult(){
        cout<<"Printing result: "<<endl;
        for(int i = 0; i < result.size(); i++){
            for(int j = 0; j < result[i].size(); j++)
                cout<<result[i][j]<<" ";
            cout<<endl;
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(root){
            traverseTree(root);
            printResult();
        }
        return -1;
    }
};