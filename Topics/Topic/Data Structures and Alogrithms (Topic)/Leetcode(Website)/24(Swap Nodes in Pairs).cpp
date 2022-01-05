/*
-------------------------Question:

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

/*
-------------------------My Approaches:

1. Dummy pointer and pointer approach

Using a dummy pointer here helps in setting the problem up with handling some edge cases that occur. In addition, we use
a few pointers to keep track of the poisitons of the nodes as it is given that we can't swap values in nodes and can only change
nodes. As a result, we have a prev pointer that pointers to the previous pointer, a ptr1 that points to the noode after prev
and ptr2 that points to a node after ptr1. We do have a couple of additional pointers to point to the next set of nodes
as well if they exist which ptr1 and ptr2 use to move on to the next set of nodes.

The gist of the approach is that we use the pointers ptr1 and ptr2 to swap nodes and nxtPtr1 and nxtPtr2 as the next
set of references for ptr1 and ptr2. Check out 'Helping Images' for more info with respect to more information about this
approach.

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
    void insertDummy(ListNode * & head){
        ListNode * temp = new ListNode(0, head);
        head = temp;
    }
    
    void swapNodes(ListNode * & head){
        ListNode * prev = head, * ptr1 = prev->next, * ptr2 = ptr1->next, * nxtPtr1 = NULL, * nxtPtr2 = NULL;
        while(ptr1 && ptr2){
            nxtPtr1 = ptr2->next;
            nxtPtr2 = nxtPtr1 ? nxtPtr1->next : NULL;
            
            prev->next = ptr2;
            ptr2->next = ptr1;
            ptr1->next = nxtPtr1;
            
            prev = ptr1;
            ptr1 = nxtPtr1;
            ptr2 = nxtPtr2;
        }
    }
    
    void resetHead(ListNode * & head){
        ListNode * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(head && head->next){
            insertDummy(head);
            swapNodes(head);
            resetHead(head);
        }
        return head;
    }
};