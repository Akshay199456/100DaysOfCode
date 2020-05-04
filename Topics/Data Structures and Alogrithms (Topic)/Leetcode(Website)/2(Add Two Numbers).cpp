/*
-------------------------Question:

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/*
-------------------------My Approaches:
1. Pointer approach

In this approach, you basically use pointers to keep adding the sum from each pair of digits and keep
view of carry as you move along. There are one of 3 possibilities that can exist when you are adding the 
values associated with the pointers.

1. Both the lists are of the same length
2. List1 is greater in length than List2
3. List2 is greater in length than List1

The approach differs slightly depending on which of three cases we are dealing with a lot in common as
well. Also, since the goal of this approach is to not use additional space, we will storing the result in
list1 always.

Let's begin with two pointers that point to the head of the list. We will also have two pointers to store
the nodes ecnountered for both the list as this will help us extend the list. As long as both nodes exist
we keep adding the values associated with the nodes by taking into consideration the carry that we obtain
from the previous step as well and push the pointers forward. We also want to make sure to keep account of
the last pointers encountered. We keep storing this into list1 as we don't want to take up extra space.
At the end of this, we deal with one of the three situations I mentioned earlier:

1. If both of the lists are of the same length, both the pointers will hit NULL at the same time.

    In this case, we just need to check if the carry is not equal to 0 at the end. If it is, we creater a 
    new node and append it with the value of carry. This way we would have stored the sum in reverse order
    at the end.

2. If list1 is greater in length than list2, list2 will hit NULL sooner

    In this case, we need to keep adding the carry from the pervious step and the current node value of 
    list1 and keep continuing this till we hit the end of list1. At the end, we make the same check for
    the carry as we did in (1).

3. If list2 is greater in length than list1, list1 will hit NULL sooner

    In this case, once we hit the end of list1, we want to make sure to redirect the next poitner from
    list1 to list2 so that the end of list1 redirects to the next node of list2. We then keep adding
    the carry from the previous step with the current value of the node in list1 and do this till we hit
    the end of list2. At the end we make the same check for carry as in (1). 


Time complexity: O(max(m,n))
Space complexity: O(1)


2. Refactored version of My Approaches(1)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr1 = l1, * ptr2 = l2, * lstPtr1 = NULL, * lstPtr2 = NULL;
        int carry = 0;
        while(ptr1 && ptr2){
            int temp = ptr1->val + ptr2->val + carry;
            ptr1->val = temp % 10;
            carry = temp / 10;
            
            lstPtr1 = ptr1;
            lstPtr2 = ptr2;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        if(ptr2){
            while(ptr2){
                int temp = carry + ptr2->val;
                ptr2->val = temp % 10;
                carry = temp /10;
                
                lstPtr1->next = ptr2; 
                lstPtr1 = ptr2;
                ptr2 = ptr2->next;
            }
            
            if(carry != 0)
                lstPtr1->next = new ListNode(carry);
        }
        
        else if(ptr1){
            while(ptr1){
                int temp = carry + ptr1->val;
                ptr1->val = temp % 10;
                carry = temp / 10;
                
                lstPtr1 = ptr1;
                ptr1 = ptr1->next;
            }
            
            if(carry != 0)
                lstPtr1->next = new ListNode(carry);
            
        }
        
        else{
            if(carry != 0)
                lstPtr1->next = new ListNode(carry);
        }
        
        return l1;
    }
};


// My Approaches(2)
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
    void addDigits(int digit1, int digit2, ListNode * ptr, int & carry){
        int temp = digit1 + digit2 + carry;
        ptr->val = temp % 10;
        carry = temp / 10;
    }
    
    void checkCarryZero(ListNode * ptr, int carry){
        if(carry != 0)
            ptr->next = new ListNode(carry);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr1 = l1, * ptr2 = l2, * lstPtr1 = NULL, * lstPtr2 = NULL;
        int carry = 0;
        while(ptr1 && ptr2){
            addDigits(ptr1->val, ptr2->val, ptr1, carry);
            
            lstPtr1 = ptr1;
            lstPtr2 = ptr2;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        if(ptr2){
            while(ptr2){
                addDigits(0, ptr2->val, ptr2, carry);    
                lstPtr1->next = ptr2; 
                lstPtr1 = ptr2;
                ptr2 = ptr2->next;
            }   
            checkCarryZero(lstPtr1, carry);
        }
        
        else if(ptr1){
            while(ptr1){
                addDigits(ptr1->val, 0, ptr1, carry);      
                lstPtr1 = ptr1;
                ptr1 = ptr1->next;
            }
            checkCarryZero(lstPtr1, carry);   
        }
        
        else
            checkCarryZero(lstPtr1, carry);
        
        return l1;
    }
};