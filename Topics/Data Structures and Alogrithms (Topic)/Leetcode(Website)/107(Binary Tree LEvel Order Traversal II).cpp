/*
-------------------------Question:

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

*/

/*
-------------------------My Approaches:
1. DFS

We can use DFS to implement a solution to this problem. What we can do this is go depth first through the binary tree.
If at any time the level we are currently are is equal to the size of the result array, we need to create a new list and
insert it into th eresult array. Else, we can keep adding elements to the part of the result at the current level.
At the end of this stage, we have an array with elements from left to right and from top to bottom. So, the only thing
remaining is to reverse the result array by swapping the array at index i with the array at array.size() - 1-i. The result
array is a vector of vectors. The inner vector dictates the left to right order in which the elements are arranged. The
outer vector dicatates the order in whcih elements are inserted, in our case from top to botttom. Since the result we are
looking for is the opposite of this, we need to swap the ith vector with vector.size() - i -1th index.

Time complexity: O(n)
Space complexity: O(1)
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
    void buildTraversal(TreeNode * root, vector<vector<int>> & result, int level){
        if(root){
            if(level == result.size()){
                vector<int> list;
                list.push_back(root->val);
                result.push_back(list);
            }
            else
                result[level].push_back(root->val);
            
            buildTraversal(root->left, result, level + 1);
            buildTraversal(root->right, result, level + 1);
        }
    }
    
    void printResult(vector<vector<int>> result){
        for(int i = 0; i < result.size(); i++){
            cout<<"Level "<<i<<":"<<endl;
            for(int j = 0; j < result[i].size(); j++)
                cout<<result[i][j]<<" ";
            cout<<endl;
        }
    }
    
    void swapLayers(vector<vector<int>> & result){
        for(int i = 0; i < result.size() / 2; i++){
            vector<int> list = result[i];
            result[i] = result[result.size() - 1 - i];
            result[result.size() - i - 1] = list;
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root){
            buildTraversal(root, result, 0);
            // printResult(result);
            swapLayers(result);
        }
        return result;
    }
};