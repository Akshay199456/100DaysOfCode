/*
-------------------------Question:

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

/*
-------------------------My Approaches:
1. Using dummy pointers as head followed by inserting nodes into separate categories based on condition

We can use dummy pointers and have 4 different pointer, ltHead, ltTail, gtHead, gtTail which we can use to point
to the dummy pointers. We then go through th elinked list and insert the nodes respectively into the respective group 
depending on whther the value of the current node is less than or greater than or equal to the node and adjust pointers
accordingly. At the end, we reset the pointer headers by getting rid of the dummy nodes and adjusting the head pointer
accordingly.

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
    void setUpDummy(ListNode * & ltHead, ListNode * & ltTail, ListNode * & gtHead, ListNode * & gtTail){
        ltHead = new ListNode(-1);
        gtHead = new ListNode(-1);
        ltTail = ltHead;
        gtTail = gtHead;
    }
    
    void movePointers(ListNode * & head, ListNode * & tail, ListNode * & curr){
        tail->next = curr;
        tail = tail->next;
        curr = curr->next;
        tail->next = NULL;
    }
    
    void resetHead(ListNode * & head){
        ListNode * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        
    }
    
    void partitionList(ListNode * & head, int x){
        ListNode * ltHead , * ltTail , * gtHead, * gtTail , * curr = head;
        setUpDummy(ltHead, ltTail, gtHead, gtTail);
        
        while(curr){
            if(curr->val < x)
                movePointers(ltHead, ltTail, curr);
            else
                movePointers(gtHead, gtTail, curr);
        }
        
        resetHead(ltHead);
        resetHead(gtHead);
        
        if(ltHead){
            ltTail->next = gtHead;
            head = ltHead;
        }
        else
            head = gtHead;
    }
    
    ListNode* partition(ListNode* head, int x) {
        if(head)
            partitionList(head, x);
        return head;
    }
};