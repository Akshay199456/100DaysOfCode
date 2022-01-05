/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/*
-------------------------Other approaches

1. Recursive approach to mirror checking property

The key to solve this problem is to understand what it means for a binary tree to be a mirror
of itself. Two necessary conditions are:

a. The roots must have the same value
b. The left subtree of each tree must be a mirror reflection of the right subtree of each tree.
[Check images for more info]

So, this means that we check each left node of the tree with each right node of the tree and vice
versa. We do this till all the nodes in the left and right subtree from the middle have been 
checked.

Time complexity: O(n)
Space complexity: O(h) -> O(n)


2. BFS with queue iterative approach[Same]

The iterative approach to this problem makes use of a BFS esque approach where we check the nodes
at each level. If both are NULL, we move to the next iteration while if either one of them or NULL,
we return false. Else, we check the values of the two nodes. Again, if they are not equal we return
false else we insert the left and right children of the two nodes into the queue. It's important
here that we insert the left of one node followed by the right of the other and then the right of
the first node with the left of the second. At the end of this, if we have the queue empty, we 
know that the left and right subtrees are mirrors of each other[Check images for more info]

Time complexity: O(n)
Space complexity: O(2n) -> O(n)


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
    bool checkSymmetric(TreeNode * tree1, TreeNode * tree2){
        if(!tree1 && !tree2)
            return true;
        if(!tree1 || !tree2)
            return false;
        return ((tree1->val == tree2->val) && checkSymmetric(tree1->left, tree2->right) && checkSymmetric(tree1->right, tree2->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        else
            return checkSymmetric(root->left, root->right);
    }
};


// Other Approaches(2)
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
    bool checkSymmetric(TreeNode * root){
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        TreeNode * child1, * child2;
        
        while(!q.empty()){
            child1 = q.front();
            q.pop();
            child2 = q.front();
            q.pop();
            
            if(!child1 && !child2){
                
            }
            else if(!child1 || !child2)
                return false;
            else{
                if(child1->val != child2->val)
                    return false;

                q.push(child1->left);
                q.push(child2->right);
                q.push(child1->right);
                q.push(child2->left);  
            }      
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        else
            return checkSymmetric(root);
    }
};