/*
-------------------------Question:

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
*/

/*
-------------------------    My Approaches:
1. Passing information higher up

For the globalMax, there are 4 possible candidates that can give you the globalMAx. They are {root->val, root->val+leftMax, root->val+rightMax, root->val+leftMax+rightMax}. This is the decision that is made at teach node that decides the
overallMax. The information that is sent up, howeverm has one dimension missing and that is root->val + leftMax + rightMax since duplicates can't occur. If we were to consider this dimentison, then that means we are repeating the same
number twice as we go through its path. Hence, that is the information that is sent up. Doing this for each node gives you the answer for the whole tree.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

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
    int getMax(vector<int> & globalMaxCandidates){
        int curMax = INT_MIN;
        for(int i=0; i< globalMaxCandidates.size(); i++)
            curMax = max(curMax, globalMaxCandidates[i]);
        
        return curMax; 
    }
    
    int getMaxSum(TreeNode * root, int & globalMaxSum){
        if(!root)
            return 0;
        else{
            int leftMax = getMaxSum(root->left, globalMaxSum);
            int rightMax = getMaxSum(root->right, globalMaxSum);
            
            // set globalMax depending on cnandidates
            vector<int> upperLayerCandidates{root->val, root->val + leftMax, root->val + rightMax};
            int upperLayerMax = getMax(upperLayerCandidates);
            
            globalMaxSum = max(max(globalMaxSum,upperLayerMax), root->val + leftMax + rightMax);
            
            // pass information to above layer
            return upperLayerMax;
        }
    }
    
    int maxPathSum(TreeNode* root) {
        int globalMaxSum = INT_MIN;
        return max(globalMaxSum, getMaxSum(root, globalMaxSum));
    }
};