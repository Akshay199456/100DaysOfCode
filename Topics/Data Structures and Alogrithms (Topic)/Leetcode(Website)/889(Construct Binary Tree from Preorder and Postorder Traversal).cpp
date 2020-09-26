/*
-------------------------Question:

Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
*/

/*
-------------------------My Approaches:
1. Using property of preorder and postorder to add elements

We know that:
preorder: (Root, left, right)
postOrder: (left, Right, Root)

We also that the beginning node is going to be preorder[0]. Since preorder moves from root->left->right, we can insert nodes
as we go along till the post order is out of children. As the postorder traversal is left->right->root, we can check if
a node has any remaining children left by keeping track of the indexes upto which elements have already been inserted into
the tree. If it has children remaing, we move on tot he next preorder node and insert it. If it doesn't, we know that for
that particular node, all left and right children node have been inserted so, we have to go to its parent and do the same
check. We keep using the info from preorder and postorder to build this tree going along. To keep track of where we are with
each node as we are going along, we also push in a status variable along with each node in the stack and use that information
to make changes.

1 -> left is being visited
2 -> right is being visited


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
    unordered_map<int,int> postMap;
    
    void constructPostMap(vector<int> post){
        for(int i = 0; i < post.size(); i++)
            postMap[post[i]] = i;
    }
    
    void constructTree(vector<int> pre, vector<int> post, TreeNode * & root){
        int postBeg = INT_MIN, postEnd = INT_MIN;
        pair<TreeNode *, int> topPair;
        stack<pair<TreeNode *, int>> elementWithStatus;
        root = new TreeNode(pre[0]);
        elementWithStatus.push(make_pair(root,1));
        
        for(int i = 1; i < pre.size();i++){
            TreeNode * temp = new TreeNode(pre[i]);
            topPair = elementWithStatus.top();
            if(topPair.second == 1)
                topPair.first->left = temp;
            else
                topPair.first->right = temp;
            
            int postOrderIndex = postMap[pre[i]];
            if(postOrderIndex - 1 < 0 || (postOrderIndex - 1 >= postBeg && postOrderIndex - 1 <= postEnd)){
                bool isEnd = false;
                if(postOrderIndex - 1 < 0){
                    postBeg = 0;
                    postEnd = 0;
                }
                else{
                    postEnd = postOrderIndex;
                }
                while(!isEnd && !elementWithStatus.empty()){
                    topPair = elementWithStatus.top();
                    if(topPair.second == 1){
                        elementWithStatus.pop();
                        elementWithStatus.push(make_pair(topPair.first,2));
                        int newTopIndex = postMap[topPair.first->val];
                        if(newTopIndex - 1 >= postBeg && newTopIndex - 1 <= postEnd){
                            postEnd = newTopIndex;
                            elementWithStatus.pop();
                        }
                        else
                            isEnd = true;
                    }
                    else{
                        int newTopIndex = postMap[topPair.first->val];
                        postEnd = newTopIndex;
                        elementWithStatus.pop();
                    }
                }
            }
            else
                elementWithStatus.push(make_pair(temp,1));
        }
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode * root = NULL;
        if(pre.size()){
            constructPostMap(post);
            constructTree(pre, post, root);
        }
        return root;
    }
};