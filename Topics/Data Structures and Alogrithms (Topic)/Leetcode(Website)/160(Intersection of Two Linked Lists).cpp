/*
-------------------------Question:

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


begin to intersect at node c1.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 

Example 2:


Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
 

Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/*
-------------------------My Approaches:
1. Using pointers to determine length

We can use pointers to determine the length of both the lists. Once we know the length, we can progress
the starting pointer of the list that has the greater number of elements so that the starting pointers
of the list are of the same length. This way, if there is an intersection, we will be able to find the
intersecting element as lists of the same length will intersect at the same length from the beginning.
If no intersection is found, we just return NULL.

Time complexity: O(m+n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

1. Using two pointers but not having to determine length

If you think of what we did in My Approaches(1), we basically used the pointers to determine the length of
the lists and then made sure to adjust the pointers so that they start from the same length. We actually
don't need to know the length to adjust the differences in the length between the two lists.

In thsi approach, what we do is to keep pushing the pointers forward as long as they don't hit NULL. If they
hit NULL, we interchange the pointers. This means that ptrA will start pointing from the head of ptrB and
vice versa. The reason this approach works is as follows:

Let's assume A is of a greater length than B. During the first iteration of the elements, the pointer at
B will always be ahead of A by the difference in length between A and B. When B hits NULL, A will still be
iteraing through its list. By changing B to now A and when A hits NULL changing A to B, we are removing the
difference in length between A and B. This is because, in our case, by the time ptrA starts from the 
beginning of list B, ptrB would have travelled the differnce in length between A and B. As a result, as we
are passing through the elements in the second iteration, now there is no difference in length between A
and B. This means that, the two pointers will always meet irrespective of whether they meet at NULL(meaning
they don't intersect) or at a node. Thus, by switching the pointers to the lists they are pointing to we
are able to minimize the difference between the two lists and are able to acheive what we did in 
My Appraoches(1) without knowing the lrngth of the list.

Time complexity: O(m+n)
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
        int length = 0;
        ListNode * temp = head;
        while(temp){
            temp = temp->next;
            ++length;
        }
        return length;
    }
    
    ListNode * pushPointer(ListNode * head, int length){
        ListNode * temp = head;
        while(length-- > 0)
            temp = temp->next;
        return temp;
    }
    
    ListNode * getIntersection(ListNode * headA, ListNode * headB){
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        ListNode * ptrA = headA, * ptrB = headB;
        
        if(lengthA > lengthB)
            ptrA = pushPointer(headA, lengthA - lengthB);
        else if(lengthB > lengthA)
            ptrB = pushPointer(headB, lengthB - lengthA);
        
        while(ptrA){
            if(ptrA == ptrB)
                return ptrA;
            else{
                ptrA = ptrA->next;
                ptrB = ptrB->next;
            }
        }
        return NULL;
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        else
            return getIntersection(headA, headB);
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
    ListNode * findIntersection(ListNode * headA, ListNode * headB){
        ListNode * ptrA = headA, * ptrB = headB;
        while(ptrA != ptrB){
            if(ptrA)
                ptrA = ptrA->next;
            else
                ptrA = headB;
            
            if(ptrB)
                ptrB = ptrB->next;
            else
                ptrB = headA;
        }
        return ptrA;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        return findIntersection(headA, headB);
    }
};