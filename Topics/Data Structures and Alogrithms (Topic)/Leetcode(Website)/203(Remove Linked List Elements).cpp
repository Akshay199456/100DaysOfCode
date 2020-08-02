/*
-------------------------Question:

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

/*
-------------------------My Approaches:
1. Using a dummy pointer and removing pointers with two pointer approach

We can insert a dummy pointer at the beginning of the linked list. This way it becomes easier to make any changes if the
first pointer contains a duplicate element. We then keep track of the elements using two pointers, a curr and prev 
pointer which we use to traverse the list. If the curr pointer equlas the value we del;ete it by adjusting the pointers.

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
    void insertDummy(ListNode *& head, int val){
        ListNode * temp = new ListNode(val, head);
        head = temp;
    }
    
    void removeElement(ListNode * head, int val){
        ListNode * curr = head->next, *prev = head;
        while(curr){
            if(curr->val == val){
                ListNode * temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                temp->next = NULL;
                delete temp;
            }
            else{
                prev = curr;
                curr = curr->next;   
            }
        }
    }
    
    
    ListNode* removeElements(ListNode* head, int val) {
        if(head){
            insertDummy(head, val);
            removeElement(head, val);
            
            ListNode * temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
        return head;
    }
};