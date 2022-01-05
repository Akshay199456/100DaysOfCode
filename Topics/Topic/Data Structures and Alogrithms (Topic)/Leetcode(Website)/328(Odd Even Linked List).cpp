/*
-------------------------Question:

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/

/*
-------------------------My Approaches:

1. Using 4 pointers

To solve this problem in place, you will need to make sure to connect each even to the next even and each
odd to the next odd element as we move along each node. This way we are able to manipulate the linked list
in place.

What we do is link each even node to the next even node and each odd node to the next odd node as we move
along the linked list. Once we reach the end of the linked list[established by conditions in the while
loop], we link the end of the odd linked list to the beginning of the even linked list to generate our
result.

Time complexity: O(n)-> n: number of nodes
Space complexity: O(1)
*/

// My approaches(1)
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
    ListNode * oddEvenLinkedList(ListNode * head){
        ListNode * currOdd, * currEven, * prevOdd, * prevEven, *evenHead;
        currOdd = prevOdd = head;
        currEven = prevEven = evenHead = head->next;
        
        while((currOdd && currEven) && (currOdd->next && currEven->next)){
            currOdd = currOdd->next->next;
            currEven = currEven->next->next;
            
            prevOdd->next = currOdd;
            prevEven->next = currEven;
            
            prevOdd = currOdd;
            prevEven = currEven;
        }
        
        currOdd->next = evenHead;
        return head;
    } 
    
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head->next))
            return head;
        else
            return oddEvenLinkedList(head);
    }
};