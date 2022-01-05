/*
-------------------------Question:
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
Example 2:

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Note:

The number of nodes in the given list will be between 1 and 100.
*/

/*
-------------------------My Approaches:

1. Calculating the length of the list and then moving the pointer by the required length


This apporach is pretty trivial. We calculate the length of the list and move the pointer by
length/2 and then return the pointer.

Time complexity: O(n)
Space complexity: O(1)


2. Two pointer method

We use the two pointer approach here where we have a slow and fast pointer. The fast pointer moves
twice the speed of the slow pointer. We keep moving the pointers till fast->next exists. At this
point, the location of the slow pointer is the middle element.


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
    int getLength(ListNode * head){
        ListNode * temp = head;
        int length = 0;
        while(temp){
            length++;
            temp = temp->next;
        }
        return length;
    }
    
    ListNode * middleNodeElement(ListNode * head, int length){
        ListNode * temp = head;
        int index = 0;
        while(index < (length / 2)){
            index++;
            temp = temp->next;
        }
        return temp;
    }
    
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return head;
        else{
            int length = getLength(head);
            return middleNodeElement(head, length);
        }
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
    ListNode * middleNodeElement(ListNode * head){
        ListNode * slow, * fast;
        slow = fast = head;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
            if(fast->next)
                fast = fast->next;
        }
        
        return slow;
    }
    
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return head;
        else
            return middleNodeElement(head);
    }
};