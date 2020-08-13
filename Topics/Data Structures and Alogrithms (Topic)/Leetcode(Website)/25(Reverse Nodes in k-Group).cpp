/*
-------------------------Question:

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches

*/

// Other Approaches(1)
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
    ListNode * reverseNodes(ListNode * & dummyNode, int k){
        ListNode * beg = dummyNode->next, * end = dummyNode->next, * movingNode = dummyNode;
        bool isEnd = true;
        while(isEnd){
            int count = 0;
            while(end && count < k){
                end = end->next;
                ++count;
            }

            if(count != k)
                isEnd = false;
            else{
                count = 0;
                ListNode * prev = end, * curr = beg;
                while(count++ < k){
                    ListNode * temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                }

                movingNode->next = prev;
                movingNode = beg;
                beg = end;
            }
        }
        return dummyNode->next;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !(head->next) || k==1 )
            return head;
        else{
            ListNode * dummyNode = new ListNode(-1, head);
            return reverseNodes(dummyNode, k);
        }
    }
};