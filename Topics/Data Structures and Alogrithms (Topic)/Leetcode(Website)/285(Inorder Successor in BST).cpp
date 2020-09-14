/*
-------------------------Question:

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node  p is the node with the smallest key greater than  p.val.

 

Example 1:



Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
Example 2:



Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.
 

Note:

If the given node has no in-order successor in the tree, return  null.
It's guaranteed that the values ​​of the tree are unique.

*/

/*
-------------------------My Approaches:
1. Using properties of bst

We can use the properties of a BST to improve upon our decision process. 

If the node given to us is a leaf, then the inorder succesor will be the last parent closest to the node that has a value
greater than the current node. This same condition also applied if the node given to us is a parent with only left child.
If the node has a right child, then the inorder successsor will be the left most node of the right subtree as that is the 
node that will have a value just greater than the node we are given

Time complexity: O(h) -> O(n)
Space complexity: O(h) -> O(n)


2. Create inorder array and return the node next to the one you are interested in[Not coded]

We can create an array using inorder traversal and return the element next to the one that we are interested in.

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
    TreeNode * findParent(TreeNode * root, TreeNode * nodeToFind){
        TreeNode * parent = NULL;
        bool isComplete = false;
        while(root != nodeToFind){
            if(root->val >= nodeToFind->val)
                parent = root;
            
            if(root->val > nodeToFind->val)
                root = root->left;
            else
                root = root->right;
        }
        return parent;
    }
    
    TreeNode * childNode(TreeNode * child){
        TreeNode * result = child;
        while(child){
            result = child;
            child = child->left;
        }
        return result;
    }
    
    TreeNode * traverseTree(TreeNode * root, TreeNode * nodeToFind){
        if(!root || (!root->left && !root->right))
            return NULL;
        else{
            bool isLeaf = (!nodeToFind->left && !nodeToFind->right);
            if(isLeaf){
                return findParent(root, nodeToFind);
            }
            else{
                if(nodeToFind->right)
                    return childNode(nodeToFind->right);
                else
                    return findParent(root, nodeToFind);
            }
        }
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode * nodeToFind = root->left->right->right;
        TreeNode * outputNode = traverseTree(root, nodeToFind);
        cout<<"Node to find: "<<nodeToFind->val<<endl;
        if(outputNode) 
            cout<<"Result node: "<<outputNode->val<<endl;
        else
            cout<<"NULL Result node"<<endl;
        return true;
    }
};