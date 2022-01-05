/*
-------------------------Question:
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
*/

/*
-------------------------    My Approaches:
1. Making the length of both lists equal and then using recursion

If the length of the bost of the lists are equal, we can then add them by adding subsequent positions and taking the carry from the prebious step. To generate the cary, we make use of recursion to add the lists from the end of the lst
first instead of the beginning of the list and then take it into the previous poisiton in the list to add it. At the end of the addition, if we are left with a remainder other than 0, we create a new nocde and append it.

Time complexity: O(max(m,n))
Space complexity: O(max(m,n))

*/

/*
-------------------------    Other approaches:

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
        int length = 0;
        ListNode * temp = head;
        while(temp){
            ++length;
            temp = temp->next;
        }
        return length;
    }
    
    void appendZeros(ListNode * & head, int nZero){
        ListNode * tempTail = NULL, * tempHead = NULL;
        while(nZero-- > 0){
            ListNode * zeroNode = new ListNode(0);
            if(!tempHead)
                tempHead = zeroNode;
            else
                tempTail->next = zeroNode;
            tempTail = zeroNode;
        }
        
        // merge two lists
        tempTail->next = head;
        head = tempHead;
    }
    
    int addLists(ListNode * & l1, ListNode * l2){
        if(!l1)
            return 0;
        else{
            int value = l1->val + l2->val + addLists(l1->next, l2->next);
            l1->val = value % 10;
            return value/10 ;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length1 = getLength(l1), length2 = getLength(l2);
        if(length1 < length2)
            appendZeros(l1, length2-length1);
        else if(length1 > length2)
            appendZeros(l2, length1-length2);
        
        int rem = addLists(l1, l2);
        if(rem != 0){
            ListNode * tempNode = new ListNode(rem);
            tempNode->next = l1;
            l1 = tempNode;
        }
        return l1;
    }
};
