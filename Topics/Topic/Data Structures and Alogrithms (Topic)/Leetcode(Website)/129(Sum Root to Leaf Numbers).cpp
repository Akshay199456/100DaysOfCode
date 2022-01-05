/*
-------------------------Question:


Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/

/*
-------------------------My Approaches:
1. Recursive path holding algorithm

In this approach, we hold the path as we go along the tree. We add the current node to the path. Wehen we hit a leaf node,
 we convert the path to an int, get the value and add it to the sum. Else, we traverse the left and right subtrees
 continuosly

Time complexity: O(n * noOfLeafNodes)
Space complexity: O(n)
*/

/*
-------------------------Other approaches
1. top-down recusrive approach

In this approach, we caluclate the value associated with the node as we ago along in top-down fashion. The base condition
here is that if it's a leaf node, we want to return 10 * previous value + current node value to the previous level.
The previous level uses this information both from its left and right side and returns it to its previous level.
We want to make sure here though that we are passing 10*previous value + currValue into the next level where it will get
used to store its value. 

As a result, here we are calculating the sum from the left to right instead of the right to left

eg: 123
        1. 10 * 0 + 1  = 1->first level
        2. 10 * 1 + 2  = 12 ->second level
        3. 10 * 12 + 3  = 123 ->third level(or leaf)

as opposed to right to left as:
eg: 123
        1. 10^0 * 3 + 3 = 3 -> first level(leaf)
        2. 10^1 * 2 + 3 = 23 -> second level
        3. 10^2 * 1 + 23 = 123 -> third level


We do want to remember this as this technique can be used to calcualte the sum both from left to right and from right
to left depending on the problem at hand.

Time complexity: O(n)
Space complexity: O(n)


2. Modifying nodes as we are going along[Not coded][Check helping iamges for more info]

We can do the same approach as in Other Approaches(1) but we modify the nodes of the tree as we go along. This way when we
hit the leaf node, we can just add the sum from it. Check 'Helping Images' for more info.

Time complexity: O(n)
Space complexity: O(n)
*/

// My Approahces(1)
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
    void treeTraversal(TreeNode * root, string currPath, int & totalSum){
        if(!root){}
        else{
            currPath += to_string(root->val);
            if(!root->left && !root->right)
                totalSum += stoi(currPath);
            else{
                treeTraversal(root->left, currPath, totalSum);
                treeTraversal(root->right, currPath, totalSum);
            }
        }
    }
    
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        if(root)
            treeTraversal(root, "", totalSum);
        return totalSum;
        
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
    int treeTraversal(TreeNode * root, int currValue){
        if(!root->left && !root->right)
            return 10*currValue + root->val;
        else{
            int leftSum = 0, rightSum = 0;
            if(root->left)
                leftSum = treeTraversal(root->left, 10*currValue + root->val);
            if(root->right)
                rightSum = treeTraversal(root->right, 10*currValue + root->val);
            return leftSum + rightSum;
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(root)
            return treeTraversal(root, 0);
        return 0;
    }
};