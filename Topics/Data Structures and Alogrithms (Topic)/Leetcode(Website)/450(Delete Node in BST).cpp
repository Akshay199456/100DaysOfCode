/*
-------------------------Question:

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Follow up: Can you solve it with time complexity O(height of tree)?

 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
*/

/*
-------------------------My Approaches:
1. Deleting nodes by the kind of nodes they are

Depending on the kind of node we are deleting, if it has no child, one child or two children,we adopt different techniques
to solve the problem. Check 'Helping Images' for more info.

If it has two children, we replace the node with its inorder successor or inorder predecessor.
If it has one child, we replace the node we are deleting with it child
If it has no child, then we don't need to do anything and just reset the pointer on the parent of the node we are deleting.

Time complexity: O(h) -> O(n)
Space complexity: O(h) -> O(n)
*/

/*
-------------------------Other approaches
1. Recursive approach completely

We can do the same as My Approaches(1) but completely recursive instead as well.

Time complexity: O(h) -> O(n)
Space complexity: O(h) -> (n)
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
    TreeNode * findNode(TreeNode * root, int key, TreeNode * & parent){
        if(!root)
            return NULL;
        else if(root->val == key)
            return root;
        else if(key < root->val){
            parent = root;
            return findNode(root->left, key, parent);
        }
        else{
            parent = root;
            return findNode(root->right, key, parent);
        }
    }
    
    TreeNode * getSuccessor(TreeNode * root, TreeNode * & parent){
        if(!root->left)
            return root;
        else{
            parent = root;
            return getSuccessor(root->left, parent);
        }
    }
    
    void removeNode(TreeNode * & root, TreeNode * parent, TreeNode * toDeleteNode){
        if(toDeleteNode){
            TreeNode * leftOfDelete = toDeleteNode->left;
            TreeNode * rightOfDelete = toDeleteNode->right;
                
            TreeNode * leftOfParent = parent->left;
            TreeNode * rightOfParent = parent->right;
                
            // check if node to be deleted is leaf
            if(!leftOfDelete && !rightOfDelete){
                if(toDeleteNode == leftOfParent)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                    
                delete toDeleteNode;
            }
            // check if node to be deleted has one child
            else if((leftOfDelete && !rightOfDelete) || (rightOfDelete && !leftOfDelete)){
                if(toDeleteNode == rightOfParent){
                    if(rightOfDelete){
                        parent->right = rightOfDelete;
                        toDeleteNode->right = NULL;
                    }
                    else{
                        parent->right = leftOfDelete;
                        toDeleteNode->left = NULL;
                    }
                }
                    
                else{
                    if(rightOfDelete){
                        parent->left = rightOfDelete;
                        toDeleteNode->right = NULL;
                    }
                    else{
                        parent->left = leftOfDelete;
                        toDeleteNode->left = NULL;
                    }
                }
                delete toDeleteNode;
            }
                
            // check if node to be deleted has two children
            else{
                TreeNode * newParent = toDeleteNode;
                TreeNode * successorNode = getSuccessor(toDeleteNode->right, newParent);
                toDeleteNode->val = successorNode->val;
                removeNode(root, newParent, successorNode);
            }
        }
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(root->val == key){
                if(!root->left && !root->right)
                    root = NULL;
                else if(!root->right && root->left){
                    TreeNode * toDeleteNode = root;
                    root = root->left;
                    toDeleteNode->left = NULL;
                    delete toDeleteNode;
                }
                else if(!root->left && root->right){
                    TreeNode * toDeleteNode = root;
                    root = root->right;
                    toDeleteNode->right = NULL;
                    delete toDeleteNode;
                }
                else{
                    TreeNode * newParent = root;
                    TreeNode * successorNode = getSuccessor(root->right, newParent);
                    root->val = successorNode->val;
                    removeNode(root, newParent, successorNode);
                }
                
                return root;
            }
            else{
                TreeNode * parent = NULL;
                TreeNode * toDeleteNode = findNode(root, key, parent);
                removeNode(root, parent, toDeleteNode);
            }
        }
        return root;
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
    int getSuccessor(TreeNode * root){
        while(root->left)
            root = root->left;
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        else if(root->val == key){
            // delete node
            
            // if no child
            if(!root->left && !root->right)
                return NULL;
            
            // if one child
            else if(!root->left && root->right)
                return root->right;
            else if(!root->right && root->left)
                return root->left;
            
            // if two child
            else{
                int successor = getSuccessor(root->right);
                root->val = successor;
                root->right = deleteNode(root->right, successor);
            }
        }
        else if(key < root->val)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        
        return root;
    }
};