/*
-------------------------Question:

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [0]
Output: [0]
Example 4:

Input: head = [1,3]
Output: [3,1]
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-10^5 <= Node.val <= 10^5
*/

/*
-------------------------My Approaches:
1. Converting linked list to sorted array

The bottleneck in Other Approaches(1) is that we have to find the middle node again and again since we don't have indexes
to reference it by immediately. As a result, this process is time intensive which results in a O(nlogn) time complexity
solution.

We can improve the time complexity by using an array instead to hold the values. Since we store the values into an array,
we can easily find the mid element and transfer it into a binary tree without the logn time required to find the middle
node.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------Other approaches
1. Using two pointer to find the middle

At the end, we require the middle node in order to insert it into the tree. We can use the two pointer approach where one
node moves at twice the speed of the other. This helps us identify the middle node. Since we have to do this for each of 
the nodes that is going to be inserted and each node takes O(n) time in order to find the middle and there are logn such
levels to build, this approach takes O(nlogn) time.

Time complexity: O(nlogn)
Space complexity: O(logn)

*/

// My Approaches(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode * begNode;
    
    void getSortedArray(ListNode * head, vector<int> & sortedArray){
        while(head){
            sortedArray.push_back(head->val);
            head = head->next;
        }
    }
    
    void createTree(TreeNode * root ,  vector<int> sortedArray, int beg, int end, int dirn){
        if(beg <= end){
            int mid = (beg+end)/2;
            TreeNode * newNode = new TreeNode(sortedArray[mid]);
            if(!root){
                begNode = newNode;
                root = newNode;
            }
            else{
                if(dirn == -1){
                    root->left = newNode;
                    root = root->left;
                }
                else{
                    root->right = newNode;
                    root = root->right;
                }
            }
            
            createTree(root, sortedArray, beg, mid-1, -1);
            createTree(root, sortedArray, mid+1, end, 1);
        }
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> sortedArray;
        if(head){
            getSortedArray(head, sortedArray);
            createTree(NULL, sortedArray,0, sortedArray.size()-1, 0);
        }
        return begNode;
    }
};