/*
-------------------------Question:

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

/*
-------------------------My Approaches:

1. Solving recursively

The recursive solution is pretty simple. The inorder traversal is (node->left), node->val, (node->right)
so we follow that to add elements to the vector.

Time complexity: O(n)
Space complexity: O(log n)
*/

/*
-------------------------Other approaches

1. Solving iteratively

We can solve this problem iteratively as well. Instead of the recursion stack which helps in solving this
problem recursively, we will make use of a normal stack instead. If we observe the problem carefully for
recursion, we know that as long as there exists a left node, we keep moving towards left and left. While 
solving it iteratively, we also do it. In addition, we keep track  of the parent node as we keep moving
along in a stack. When we hit null, we now know that, we must print the element as required for the 
inorder traversal. So we store the value at the top of the stack into the result as that is the inorder
traversal. We assign that as our current node and move along its right tree instead. We keep repeating
this as long as the stack is not empty or node is not null.


Time complexity: O(n)
Space complexity; O(log n) -> stores depth of the tree at max



2. Morris Traversal

We can use the Morris Traversal algorithm to get the inorder traversal of the algorithm. This algorithm
helps achieve the same result in O(n) time and O(1) space. The algorithm is as follows:

Step 1: Initialize current as root

Step 2: While current is not NULL,

If current does not have left child

    a. Add current’s value

    b. Go to the right, i.e., current = current.right

Else

    a. In current's left subtree, make current the right child of the rightmost node

    b. Go to this left child, i.e., current = current.left


The reasoning of the algorithm is a s follows:

Since we are trying to find the inorder traversal, our goal is to go left node, then the current node value,
followed by the right node. That's why, in this algorithm, any time we have a left, we want to make sure
to attach the current node tree to the left as in the inorder traversal as the current node only occurs after
the left subtree has been explored. We keep doing this for all the nodes as long as they have a left node.
This way, once the tree nodes have been put into place, we will have an inorder tree structure also known
as a threaded tree and we would just need to traverse it to get the inorder traversal solution to the 
problem. 

Time complexity: O(n)
Space complexiuty: O(1)

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
    void getInorder(TreeNode * root, vector<int> & result){
        if(!root)
            return;
        else{
            getInorder(root->left, result);
            result.push_back(root->val);
            getInorder(root->right, result);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        getInorder(root, result);
        return result;
    }
};


// Other approaches(1)
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> elementStack;
        TreeNode * current = root;
        while(current || !elementStack.empty()){
            while(current){
                elementStack.push(current);
                current = current->left;
            }
            
            current = elementStack.top();
            result.push_back(current->val);
            elementStack.pop();
            current = current->right;
        }
        return result;
    }
};


// Other Approaches(2)
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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode * current = root, * parent = NULL;
        vector<int> result;
        while(current){
            if(current->left){
                TreeNode * next = current->left;
                TreeNode * rightMost = next;
                while(rightMost->right)
                    rightMost = rightMost->right;
                
                current->left = NULL;
                if(parent)
                    parent->right = rightMost;
                rightMost->right = current;
                current = next;
            }
            
            else{
                result.push_back(current->val);
                parent = current;
                current = current->right;
            }
        }
        return result;
    }
};