/*
-------------------------Question:

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 

Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
 

Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
*/

/*
-------------------------My Approaches:
1. Recursive structure and inorder array

This approachh is also claled flattneing a BST since we are condensing the bst intoa n array.

We can use an inorder array to store our elements. When we want a next element, we return the current element in the array
and push the index forward. To check if there is a next element, we simply check if the index has crossed the size of the
array.

Overall Time complexity: O(n)
Overall Space complexity: O(n)
*/

/*
-------------------------Other approaches
1. Iterative approach

We can use the iterative inorder traversal well here. The problem we had in the prvious approach is that we couldn't stop
the recursion tree when we wanted. That is why we created an array to store the elements we want. However, if we were to 
use our own stack, we can then start and stop the traversal when needed to get the next element.

Overall Time complexity: O(n)
Overall Space complexity: O(h)
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
class BSTIterator {
public:
    vector<int> inOrderArray;
    int currIndex = 0;
    
    void constructInorder(TreeNode * root){
        if(root){
            constructInorder(root->left);
            inOrderArray.push_back(root->val);
            constructInorder(root->right);
        }
    }
    
    BSTIterator(TreeNode* root) {
        constructInorder(root);    
    }
     
    /** @return the next smallest number */
    int next() {
        return inOrderArray[currIndex++];
        printArray();
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return currIndex < inOrderArray.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


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
class BSTIterator {
public:
    stack<TreeNode *> elements;
    
    void constructStack(TreeNode * root){
        while(root){
            elements.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        constructStack(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode * nextElement = elements.top();
        elements.pop();
        constructStack(nextElement->right);
        return nextElement->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !elements.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */