/*
-------------------------Question:

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


 

Follow up:

Can you solve it using O(1) (i.e. constant) memory?
*/

/*
-------------------------My Approaches:

1. Two pointer approach

This approach uses two pointers to determine the end of the linked list. If the two pointers meet
at any time, then there exists a cycle in the linked list else if we reach null with the fast poitner
then we know there's no cycle.

Time complexity: O(n)
Space complexity: O(1)
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
    bool determineCycle(ListNode * slow, ListNode * fast){
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(!fast)
                return false;
            else
                fast = fast->next;
            
            if(slow == fast)
                return true;
        }
        return false;
    }
    
    bool hasCycle(ListNode *head) {
        return determineCycle(head, head);
    }
};