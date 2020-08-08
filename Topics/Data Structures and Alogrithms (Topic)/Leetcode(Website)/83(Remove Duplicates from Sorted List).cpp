/*
-------------------------Question:
1.

Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

/*
-------------------------My Approaches:
1. Using two pointer approach

We can solve this problem using the two pointer approach. At the end, we only want one instance of the duplicate elements
while removing the rest. This means that our head pointer will always remains the same since if it had a duplicate, then
only the next node would be removed and not thew current one. So, as we are going through the list, if the slow pointer is
equal to the fast pointer, we delete the fast pointer and adjust the pointers accordingly, else we progress both forward.

Time complexity: O(n)
Space complexity: O(1)

*/

/*
-------------------------Other approaches

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
class Solution {
public:
    void removeDuplicates(ListNode * & head){
        ListNode * slow = head, * fast = head->next;
        while(fast){
            if(fast->val == slow->val){
                ListNode * temp = fast;
                slow->next = temp->next;
                fast = fast->next;
                temp->next = NULL;
                delete temp;
            }
            else{
                slow = slow->next;
                fast = fast->next;
            }
        }
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head)
            removeDuplicates(head);
        return head;
    }
};