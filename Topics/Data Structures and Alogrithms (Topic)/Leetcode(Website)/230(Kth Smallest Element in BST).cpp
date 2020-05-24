/*
-------------------------Question:

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

 

Constraints:

The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/

/*
-------------------------My Approaches:
1. Using inorder array

For a BST, an inorder traversal gives a sorted array. So we can construct the inorder array and then use
that information to return the element at k-1 index which will satisfy the ocndition.

Time complexity: O(n)
Space complexity: O(n)


2. Using minHeap

We can also use a minHeap to return the Kth smallest element. Since the binary heap is self-managing, we
can delete the k-2 elements to get the k-1th index element we are looking for.

Constructing a heap takes O(n) time. However, deleting the elements from a heap takes O(log n) time. As a 
result, this approach is more useful when continous insertion and deletion takes place in the BST. Under
these conditions, My Approaches(1) would have to continously create the inorder array again and again
every time a modificaiton is made. This can take up O(m * n) time complexity where m is the number of 
modifications. On the otehr hand, My Approaches(2) would only take up O(m * log n) since any modification
for the BST means we could modify the bianry heap in place by just adding and deleting elements to it
without having to create the binary search tree again.

Time complexity: O(k * log n)
Space complexity: O(n)
*/

/*
-------------------------Other approaches

1. Iterative approach

We can solve this problem iteratively as well. If we notice the inorder traversal, the elements on the left
are the ones which are the minimum followed by the root node and followed by the right node. Using this
knowledge,we can return the kth minimum element without having to store the elements into an inorder array.
As long as there is a left node, we keep pushing it into stack. At the root level, we decrement k and check
if we hit 0. If so, we return the value of that root. Else, we go to the right node and continue the same
procedue of finding the left element and continuing from there. 

Time complexity: O(H + k) => H ->height of tree; O(log n + k) for balanced tree and O(n + k) for unbalanced
tree
Space complexity: O(H + k) -> O(n)

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
    void createInorder(TreeNode * root, vector<int> & inorder){
        if(root){
            createInorder(root->left, inorder);
            inorder.push_back(root->val);
            createInorder(root->right, inorder);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        createInorder(root, inorder);
        return inorder[k-1];
        
    }
};


// My Approaches(2)
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
    void fillPriorityQueue(priority_queue<int, vector<int>, greater<int>> & pq, TreeNode * root){
        if(root){
            fillPriorityQueue(pq, root->left);
            pq.push(root->val);
            fillPriorityQueue(pq, root->right);
        }
    }
    
    int getKthSmallest(priority_queue<int, vector<int>, greater<int>> pq, int k){
        for(int i = 0 ; i < k - 1; i++)
            pq.pop();
        return pq.top();
    }
    
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        fillPriorityQueue(pq, root);
        return getKthSmallest(pq, k);
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> elementStack;
        while(true){
            while(root){
                elementStack.push(root);
                root = root->left;
            }
            
            root = elementStack.top();
            elementStack.pop();
            if(--k == 0)
                return root->val;
            
            root = root->right;
        }
        return -1;
    }
};