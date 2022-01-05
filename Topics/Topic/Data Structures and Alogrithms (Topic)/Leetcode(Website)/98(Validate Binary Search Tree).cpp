/*
-------------------------Question:

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

/*
1. DFS

This approach is very similar to Other Approaches(1) but is more concise

Time complexity: O(n)
Space complexity: O(n)

*/

/*
-------------------------Other approaches

1. DFS(Using a min and max for each node based on the nodes seen)[Best]

The key here is to check for the min and max as we go down each node and make sure that the current
node exists between the min and the max. If it doesn't we know that it's not a BST.

Intuition
On the first sight, the problem is trivial. Let's traverse the tree and check at each step if node.right.val > node.val and node.left.val < node.val. This approach would even work for some trees compute

The problem is this approach will not work for all cases. Not only the right child should be larger than the node but all the elements in the right subtree. Here is an example :

compute

That means one should keep both upper and lower limits for each node while traversing the tree, and compare the node value not with children values but with these limits.


Approach 1: Recursion
The idea above could be implemented as a recursion. One compares the node value with its upper and lower limits if they are available. Then one repeats the same step recursively for left and right subtrees.


Check 'Helping Images' for more information.


Time complexity: O(n)
Space complexity: O(n)



2. Using iterative DFS[Same]

We can do approach 1 using an iterative version that includes DFS.

Check 'Helping Images' for more information

Time complexity: O(n)
Space complexity: O(n)



3. Using Inorder traversal[Same]

This approach uses a vector to store the inorder element traversal of the binart tree. In a
BST, the inorder traversal results in a vector where each progressing element is greater than
the element before it and is this sorted.

We can use this approach to create a vector of the elements and then go through that list
to check if every progressing element is greater than the one before it. If so, we return true
at the end else we return false;

Time complexity: O(n) + O(n) -> O(n)
Space complexity: O(n) + O(n) -> O(n)


4. Using Inorder Traversal without additional array[Same]

This approach uses the same approach as Other approaches(3) but doesn't use the additional 
array.

Time complexity: O(n)
Space complexity: O(n)
*/

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
public:
    bool checkBST(TreeNode * node, TreeNode * lower, TreeNode * higher){
        // Base conditions
        if(!node)
            return true;
        
        if(lower && node->val <=lower->val)
            return false;
        if(higher && node->val >= higher->val)
            return false;
        
        if(!checkBST(node->left, lower, node))
            return false;
        if(!checkBST(node->right, node, higher))
            return false;
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        else
            return checkBST(root, NULL, NULL);
        
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
public:
    void fillInorder(TreeNode * node, vector<int> & inOrder){
        if(!node)
            return;
        else{
            fillInorder(node->left, inOrder);
            inOrder.push_back(node->val);
            fillInorder(node->right, inOrder);
        }
    }
    
    bool checkInorder(vector<int> inOrder){
        for(int i = 1; i<inOrder.size(); i++){
            if(inOrder[i] <= inOrder[i-1])
                return false;
        }
        return true;
    }

    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        else{
            vector<int> inOrder;
            fillInorder(root, inOrder);
            return checkInorder(inOrder);
        }
    }
};



// Other Approaches(4)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
public:
    bool checkBST(TreeNode * current, TreeNode *& inOrder){
        if(!current)
            return true;
        else{
            if(!checkBST(current->left, inOrder))
                return false;
            
            
            if(inOrder && current->val <= inOrder->val)
                return false;
            else
                inOrder = current;
                
            return checkBST(current->right, inOrder);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode * empty = NULL;
        if(!root)
            return true;
        else
            return checkBST(root, empty);
        
    }
};


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
    bool checkBST(TreeNode * root, long min, long max){
        if(!root)
            return true;
        else{
            //cout<<"Root: "<<root->val<<" min: "<<min<<" max: "<<max<<endl;
            if(!(root->val > min && root->val < max))
                return false;
            else
                return checkBST(root->left, min, root->val) && checkBST(root->right, root->val, max);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};