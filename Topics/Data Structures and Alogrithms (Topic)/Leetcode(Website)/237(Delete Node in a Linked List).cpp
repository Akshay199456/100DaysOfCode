/*
-------------------------Question:

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:



 

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
 

Note:

The linked list will have at least two elements.
All of the nodes' values will be unique.
The given node will not be the tail and it will always be a valid node of the linked list.
Do not return anything from your function.
*/

/*
-------------------------My Approaches:
1.

To solve this problem, you can use two pointers, one pointing to the current one and the other to
the next node. You have to keep swapping node values till the last node is encountered by the next
node. Then set the current node to null.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches
1.

Rather than using two pointers to swap values till the end, you can just exchange the value of the 
current node with the next node and make sure to point the current node to the node after the next
node and deleting the next node. This doesn't make you go through the whole list.

Time complexity: O(1)
Space complexity: O(1)
*/



// My Approaches(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * nextNode = node->next;
        while(nextNode != NULL){
            swap(node->val, nextNode->val);
            nextNode = nextNode->next;
            if(!nextNode){
            }
            else
                node = node->next;
        }
        node->next = NULL;
    }
};


// Other Approaches(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        nextNode->next = NULL;   
    }
};