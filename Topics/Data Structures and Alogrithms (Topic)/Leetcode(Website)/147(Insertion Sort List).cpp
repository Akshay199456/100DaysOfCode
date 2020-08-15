/*
-------------------------Question:

Sort a linked list using insertion sort.

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

/*
-------------------------My Approaches:
1. Using insertion sort technique with linked lists.

The key here to understand is that each new node can be inserted into one of 3 positions: beginning, end or anywhere in
between. Based on where they are inserted, there are slight variations in the way they are added to the list

Time complexity: O(n^2)
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
    ListNode * getInsertion(ListNode * head){
        ListNode * dummy = new ListNode(-1, head);
        ListNode * sorted = head->next;
        head->next = NULL;
        
        while(sorted){
            ListNode * prev = dummy, * curr = head, * nextNode = sorted->next;
            bool isSorted = false;
            while(!isSorted && curr){
                if(sorted->val < curr->val){
                    if(curr == head)
                        head = sorted;
                    
                    prev->next = sorted;
                    sorted->next = curr;
                    isSorted = true;
                }
                else{
                    prev = curr;
                    curr = curr->next;
                }
            }
            
            if(!isSorted){
                prev->next = sorted;
                sorted->next = NULL;
                isSorted = true;
            }
            sorted = nextNode;
        }
        return dummy->next;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !(head->next))
            return head;
        else
            return getInsertion(head);
    }
};