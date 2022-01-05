/*
-------------------------Question:

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

/*
-------------------------My Approaches:

1.

Using two pointers that start at the head, you can push the fast pointer n steps forward. This way
when we hit NULL with the fast pointer, the slow pointer is at the node just before the node to be
deleted. We can then delete the node as done in problem 237.

Time complexity: O(n)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode * del;
        if(n <= 0)
            return head;
        else{
            while(n-- > 0){
                if(!curr)
                    return head;
                else
                    curr = curr->next;
            }

            if(!curr){
                del = head;
                head = head->next;
                del->next = NULL;
            }

            else{
                ListNode* temp = head;
                while(curr->next){
                    curr = curr->next;
                    temp = temp->next;
                }

                del = temp->next;
                temp->next = del->next;
                del->next = NULL;   
            }
            return head;
        }
    }
};