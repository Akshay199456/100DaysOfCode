/*
-------------------------Question:

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/

/*
-------------------------My Approaches:
1. Using the multiple pass approach

We can use the mulitple appraoch here to good advantage. Using that we can obtain the length of the list. Once we have
that length, we just need to find the node with value of (n - (k%n)) with the nodes starting at 0. This will be the node
that's the beginning of the new head. We then adjust the pointers accordingly to link the collection of the new head with
the other half which includes the initial head. Check 'Helping Images' for more information.

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
    int getLength(ListNode * head){
        int count = 0;
        while(head){
            head = head->next;
            ++count;
        }
        return count;
    }
    
    void adjustPointers(ListNode * & head, ListNode * & prev, ListNode * & curr){
        ListNode * temp = curr;
        while(temp->next)
            temp = temp->next;
        temp->next = head;
        prev->next = NULL;
        head = curr;
    }
    
    void iterateList(ListNode * & head, int k, int length){
        ListNode * prev = head, * curr = head;
        int count = 0;
        while(count != (length - (k % length))){
            prev = curr;
            curr = curr->next;
            ++count;
        }
        adjustPointers(head, prev, curr);
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int length = getLength(head);
        if (!(length == 0 || length == 1 || k%length == 0))
            iterateList(head, k, length);
        return head;
    }
};