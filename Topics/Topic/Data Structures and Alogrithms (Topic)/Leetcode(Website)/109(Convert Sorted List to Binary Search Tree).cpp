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
1. Using two pointer to find the middle[Not coded]

At the end, we require the middle node in order to insert it into the tree. We can use the two pointer approach where one
node moves at twice the speed of the other. This helps us identify the middle node. Since we have to do this for each of 
the nodes that is going to be inserted and each node takes O(n) time in order to find the middle and there are logn such
levels to build, this approach takes O(nlogn) time.

Time complexity: O(nlogn)
Space complexity: O(logn)


2. Using a hashmap[Not coded]

We can also use a hashmap istead of the array that we used in My Approaches(1). In the hashmap, we would stire the node as
well as the index it exists at. We can then use that information to find and take the middle node wehenever we calculate
the mid value. This is a very similar approach to the array approach but we use a hashmap here.

Time complexity: O(n)
Space complexity: O(n)


3. Using inorder property

In a normal bst, using inorder returns the nodes in ascending order. Since our linked list is also in ascending order,
we know that if we add the nodes in an inorder form to our bst using the linked list, we will be able to build it in an
effective manner and it will maintain its height property. In our linked list, the first node of our linked list is the 
first node in our bst that will be printed, the second node of our linked list is the second node in our bst that will be 
printed and so on.

In this problem, we are actually building the tree from the down up instead of the top down. In other words, we are creating
the leaf nodes and than assigning the leaf nodes to its parent nodes and keep continuing the cycle upwards. The way we do
this is by calling the left subtree till we hit null. At this point, we then create the node to be inserted into the bst 
and then repeat the process for the right subtree. At the end of this stage, we have the root node, its left node and its
right node. Once we align the structure by root->left = leafnode and root->right = rightnode, we return the root node. This
is then used by the parent to complete its substructure. As a result, slowly by slowly, we build the tree from the bottom
up instead of the top-down which we usually do with recursion.

Time complexity: O(n)
Space complexity: O(logn)

Time complexity: O(n)
Space complexity: O(log n)
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


// Other Approaches(3)
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
    int getLength(ListNode * head){
        int count = 0;
        while(head){
            head = head->next;
            ++count;
        }
        return count;
    }
    
    TreeNode * createTree(ListNode * & head , int beg, int end){
        if(beg <= end){
            int mid = (beg+end)/2;
            TreeNode * leftNode = createTree(head, beg, mid-1);
            
            TreeNode * newNode = new TreeNode(head->val);
            head = head->next;
            
            TreeNode * rightNode = createTree(head, mid+1, end);
            
            newNode->left = leftNode;
            newNode->right = rightNode;
            return newNode;
        }
        else
            return NULL;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head){
            int length = getLength(head);
            return createTree(head, 0, length-1);
        }
        return NULL;
    }
};