/*
-------------------------Question:
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

/*
-------------------------    My Approach:

1. Using two pointers and creating new nodes

The first approach uses two pointers to compare the values of the two linked lists and then creates
new nodes and inserts the values into them progressing the pointers that had the lower value. This
continues till all the values have been inserted into the new list.

Time complexity: O(m+n)
Space complexity: O(m+n)

*/

// My Approach(1)
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
    void createAndLinkNode(ListNode * & listPointer, ListNode * & head, ListNode * & temp){
        ListNode * newNode =  new ListNode(listPointer->val);
        if(!head)
            head = newNode;
        else
            temp->next = newNode;
        
        temp = newNode;
        listPointer = listPointer->next;
        
        // cout<<"Temp node in createAndLinkNode: "<<temp->val<<"\n";
    }
    
    ListNode *mergedLists(ListNode * l1, ListNode *l2, ListNode * head){
        ListNode *temp = head;
        while(l2 && l1){
            if(l2->val <= l1->val)
                createAndLinkNode(l2, head, temp);
            else
                createAndLinkNode(l1, head, temp);
            // cout<<"Temp node in mergedLists: "<<temp->val<<"\n";
        }
        
        if(!l1)
            while(l2)
                createAndLinkNode(l2, head, temp);

        else
            while(l1)
                createAndLinkNode(l1, head, temp);
        
        return head;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return mergedLists(l1, l2, NULL);
    }
};