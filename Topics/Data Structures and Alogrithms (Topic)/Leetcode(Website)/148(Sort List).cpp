/*
-------------------------Question:

Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/

/*
-------------------------My Approaches:

1. Applying merge sort technique but with linked list

We apply the same technique that we applied to the mergesort problem which is the divide and conquer approach. We keep
dividing the linked list till we have two lists that are of length 1. At this stage, we can actually merge the list.
While merging the lists we want to make sure to change the beginning of the first list if the first element in the merged
list was from the second list

Time complexity: O(n * log n)
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
            ++count;
            head = head->next;
        }
        return count;
    }
    
    ListNode * getMid(ListNode * beg, int length){
        int count = 0;
        ListNode * curr = beg, * prev = beg;
        while(count < length / 2){
            prev = curr;
            curr = curr->next;
            ++count;
        }
        
        prev->next = NULL;
        return curr;
    }
    
    void mergeSort(ListNode * & beg1, ListNode *  beg2){
        int len1 = getLength(beg1);
        int len2 = getLength(beg2);
        ListNode * newBeg = NULL;
        if(len1 != 1){
            newBeg = getMid(beg1, len1);
            mergeSort(beg1, newBeg);
        }
        if(len2 != 1){
            newBeg = getMid(beg2, len2);
            mergeSort(beg2, newBeg);
        }
        beg1 = merge(beg1, beg2);
    }
    
    ListNode * merge(ListNode * beg1, ListNode * beg2){
        ListNode * dummyHead = new ListNode(-1);
        ListNode * mergedBeg = dummyHead;
        while(beg1 && beg2){
            if(beg1->val < beg2->val){                
                mergedBeg->next = beg1;
                beg1 = beg1->next;
                mergedBeg = mergedBeg->next;
            }
            else{
                mergedBeg->next = beg2;
                beg2 = beg2->next;
                mergedBeg = mergedBeg->next;
            }
        }
        
        if(!beg1)
            mergedBeg->next = beg2;
        else
            mergedBeg->next = beg1;
        
        ListNode * temp = dummyHead->next;
        dummyHead->next = NULL;
        delete dummyHead;
        return temp;
    }
    
    void printList(ListNode * temp){
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    ListNode* sortList(ListNode* head) {
        int length = getLength(head);
        if(length == 0 || length == 1)
            return head;
        else{
            ListNode * temp = getMid(head, length);
            mergeSort(head, temp);
            return head;
        }
    }
};