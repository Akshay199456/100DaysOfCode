/*
-------------------------Question:

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

/*
-------------------------My Approaches:

1. Iteratively

The iterative solution uses 3 pointers to adjust the positions of the linked list nodes and as a
result reverse the linked list

Time complexity: O(n)
Space complexity: O(1)



2. Recursively from the head(Worse)

The second approach uses recursive method that employs part of My Approach(1) to solve it recursively.
Since the recursive approach needs to remember upto n levels deep, it has a worse space complexity
than My Approach(1)

Time complexity: O(n)
Space complexity: O(n)


/*
-------------------------    Other Approaches:

1. Recursively from the tail(Worse)

The final apporach uses recursive iteration from the tail of the linked list to solve the problem.
We need access to the current node as well as the head node. When curr->next = NULL, we know that
we are at the last node of the linked list so we need to set the head to the last node. This then 
takes us a layer higher in the recursive chain. We then set the pointer for the curr->next->next
(the next node of the current node) to the current node and then set the pointer to the curr node
to NULL. We continue this till we hit what was the first node of the linked list. This sets the
linked list recursively in reverse order.
Space compplexity remains O(n) since we still need to remember the n level deep nature of the 
recursive call.

Time complexity: O(n)
Space complexity: O(n)

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
    ListNode* reversedLinkedList(ListNode* head){
        ListNode *prev = NULL, *curr = head, *temp = head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = temp;
            if(temp)
                temp = temp->next;
        }
        head = prev;
        return head;
    }
    
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        else
            return reversedLinkedList(head);
    }
};


// My Approaches(2)
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
    ListNode* reversedLinkedList(ListNode *head, ListNode *prev, ListNode *curr, ListNode *temp){
        if(curr == NULL){
            head = prev;
            return head;
        }
        
        else{
            curr->next = prev;
            prev = curr;
            curr = temp;
            if(temp)
                temp = temp->next;
            return reversedLinkedList(head, prev, curr, temp);
        }
        
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        else{
            ListNode *prev = NULL, *curr = head, *temp = head->next;
            return reversedLinkedList(head, prev, curr, temp);
        }
    }
};


// Other Approaches(1)
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
    ListNode * reversedLinkedList(ListNode *head, ListNode *curr){
        if(!(curr->next))
            head = curr;
        else{
            head = reversedLinkedList(head, curr->next);
            curr->next->next = curr;
            curr->next = NULL;
        }
        // cout<<"Head value: "<<head->val<<" Curr value: "<<curr->val<<"\n";
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next))
            return head;
        else
            return reversedLinkedList(head, head);
    }
};

