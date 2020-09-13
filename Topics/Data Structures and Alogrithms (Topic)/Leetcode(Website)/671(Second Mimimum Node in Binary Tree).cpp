/*
-------------------------Question:

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:

Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
 

Example 2:

Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
*/

/*
-------------------------My Approaches:
1. Recursive preorder approach

We can use the preorder appraoch here to find the second smallest element. Based on the constrainsts of the problem, we know
that the root will always be the least minmium element in the tree. This is because, we know that from the constrints of the
problem, each node will the minimum of its children. This means that, our root node will be the minimum of its children.
the children will be the mnimum of their children and so on. At the end , our root node will eb the minimum of the mimum
of the left subtree and right subtree which gives it to be the least node in the tree.

We can then traverse the tree to find the second minimum node and return that if we find a second mimum node elese we return
-1.

Time complexity: O(n)
Space complexity: O(h)
*/

/*
-------------------------Other approaches
1. Navigating towards one side based on constrainsts of the problem.

We can also use the constrainsts of the problem to navigate around the tree. Since we know that each node is the minimum
of the nodes after it, we want to keep track of the secondmin as we go along. Since one of the child nodes will the same
as the root, we want to keep traversing it since we know at that level, the value that the root possesses is the least value.
So, there is a possibilty to get a higher value from that substructure as well. However, we also want to keep track of
the node and nopt its substrcutre of the node that is not equal to the minimum node since that node will have at min a
value equal to it or a value greater than it. Hence, you are not going to get a smaller value that that from that subtree.


Time complexity: O(logn) -> O(n)
Space complexity: O(h) -> O(n)
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
    void traverseTree(TreeNode * root, int min, int & secondMin, bool & isFound){
        if(!root->left && !root->right){}
        else{
            if(root->left->val <= secondMin && root->left->val != min){
                secondMin = root->left->val;
                isFound = true;
            }
            
            if(root->right->val <= secondMin && root->right->val != min){
                secondMin = root->right->val;
                isFound = true;
            }
            
            traverseTree(root->left, min, secondMin, isFound);
            traverseTree(root->right, min, secondMin, isFound);
        }
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int min = root->val;
        int secondMin = INT_MAX;
        bool isFound = false;
        traverseTree(root, min, secondMin, isFound);
        
        if(isFound)
            return secondMin;
        else
            return -1;
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
    void traverseTree(TreeNode * root, int min, int & secondMin, bool & isFound){
        if(!root){}
        else{
            if(root->val != min && root->val <= secondMin){
                secondMin = root->val;
                isFound = true;
            }
            else if(root->val == min){
                traverseTree(root->left, min, secondMin, isFound);
                traverseTree(root->right, min, secondMin, isFound);
            }
        }
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int min = root->val;
        int secondMin = INT_MAX;
        bool isFound = false;
        traverseTree(root, min, secondMin, isFound);
        
        if(isFound)
            return secondMin;
        else
            return -1;
    }
};