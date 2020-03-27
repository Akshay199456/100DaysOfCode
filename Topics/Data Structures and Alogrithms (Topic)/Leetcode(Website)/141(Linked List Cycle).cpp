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


Complexity analysis

Time complexity : O(n)O(n). Let us denote nn as the total number of nodes in the linked list. To analyze its time complexity, we consider the following two cases separately.

List has no cycle:
The fast pointer reaches the end first and the run time depends on the list's length, which is O(n)O(n).

List has a cycle:
We break down the movement of the slow pointer into two steps, the non-cyclic part and the cyclic part:

The slow pointer takes "non-cyclic length" steps to enter the cycle. At this point, the fast pointer has already reached the cycle. \text{Number of iterations} = \text{non-cyclic length} = NNumber of iterations=non-cyclic length=N

Both pointers are now in the cycle. Consider two runners running in a cycle - the fast runner moves 2 steps while the slow runner moves 1 steps at a time. Since the speed difference is 1, it takes \dfrac{\text{distance between the 2 runners}}{\text{difference of speed}} 
difference of speed
distance between the 2 runners
​	
  loops for the fast runner to catch up with the slow runner. As the distance is at most "\text{cyclic length K}cyclic length K" and the speed difference is 1, we conclude that
\text{Number of iterations} = \text{almost}Number of iterations=almost "\text{cyclic length K}cyclic length K".

Therefore, the worst case time complexity is O(N+K)O(N+K), which is O(n)O(n).
*/

/*
-------------------------Other approaches

1. Using hashtable

We can use a hashtable to store the position of the pointers. This way whenever we approach a 
duplicate, we know that we have encountered a cycle start point

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