/*
-------------------------Question:

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Follow up: Recursive solution is trivial, could you do it iteratively?

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [2,1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

/*
-------------------------My Approaches:
1. Using a visited set to keep track of the nodes we have visited

There are a few way we can keep track of the state of the nodes we have visited. First, we can use a stack whcih can 
change its status through a pair of values stored into it including the node and its current status. Anytime we go to its
left, we change it status to a value, anytime we move to its right we change its status as well as when we just encounter
it, we change its status[Check pb 236 Other Approaches(3) for an example]. The second way is that we can use a set to keep
track of the nodes that we have completely covered so we don't repeat the subtree structure. This is what we use in this
problem. As long as there is a left or right and they haven;t been visited before, we put it into the stack and visit it
and visit its subtree structure. However, if they have been visited there is no point visiting it again as we have already
covered it. Finally, we have covered all paths for a node[left and right], we print it, mark it as visited and remove it 
from the stack.

Time complexity: O(n)
Space complexity: O(n) + O(n) -> O(n)


2. Recursive[Not coded]

The recusive appraoch is pretty simple. The base case bein null, we keep traversing left, right and print the current node.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------Other approaches

1. Using only one stack

The plan here is to use just one stack as we go through post order traversal. As long as we have a left node, we want to 
keep exploring it as postOrder is left -> right -> node. We push the node into the stack and make our curr pointer move
to the left child. When curr == NULL, we know that we have explored the left node of the current node so we want to explore
the right node. As long as a right node exists and we haven't yet explored it, we can explore it. At the end of this, we
would have explored the right nodes. If we have explored both the left and right paths, we want to push the node into the
result and continue the process until the stack is empty.

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void insertPostOrder(TreeNode * root, vector<int> & result){
        unordered_set<TreeNode *> elementsVisited;
        stack<TreeNode *> elementsStack;
        elementsStack.push(root);
        TreeNode * curr = root;
        while(!elementsStack.empty()){
            if(curr->left && elementsVisited.find(curr->left) == elementsVisited.end()){
                elementsStack.push(curr->left);
                curr = curr->left;
            }
            else if(curr->right && elementsVisited.find(curr->right) == elementsVisited.end()){
                elementsStack.push(curr->right);
                curr = curr->right;
            }
            else{
                result.push_back(curr->val);
                elementsVisited.emplace(curr);
                elementsStack.pop();
                if(!elementsStack.empty())
                    curr = elementsStack.top();
            }
        }
    }
    
    void printArray(vector<int> result){
        for(int i = 0; i < result.size(); i++)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root){
            insertPostOrder(root, result);
        }
        return result;
    }
};


// Other Approaches(1)
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
    void insertPostOrder(TreeNode * root, vector<int> & result){
        TreeNode * curr = root, * lastInserted = NULL;
        stack<TreeNode *> elementStack;
        bool start = true; // used to get into the the loop for the first time
        
        while(start || !elementStack.empty()){
            start = false; // once we get into it the first time, we want the loop to be dictated by the size of the stack.
            if(curr){
                // As long as a left node exists, we explore it as it is post order.
                elementStack.push(curr);
                curr = curr->left;
            }
            else{
                // only if a right node exists and we haven't visited it before
                if(!elementStack.empty() && elementStack.top()->right && elementStack.top()->right != lastInserted)
                    curr = elementStack.top()->right;
                else{
                    // otherwise, we push the element into the result as we have explored both its left and right
                    // and store it as the lastInserted node and pop it from the stack.
                    result.push_back(elementStack.top()->val);
                    lastInserted = elementStack.top();
                    elementStack.pop();
                }
            }
        }
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root)
            insertPostOrder(root, result);
        return result;
    }
};