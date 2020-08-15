/*
-------------------------Question:

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches
1. Two pointer and dummy node

This problem uses the same UMPIRE approach that we have been applying. Since Linked List problems can come in 3 different
patterns: dummy node, 2 pointer and multiple pass, we can use the first 2 here. The dummy node can be used to help adjust
the pointer that is at the beginning of the first collection and make it point to the end of the next collection. The 2
pointer helps us break the list into collections which we can traverse through to reverse nodes accordingly.

Time complexity: O(n)
Space complexity: O(1)


2. Using an array for additional storage

This approach doesn't abide by the conditions of the problem. However, it is a good solution to use if the conditions were a
little relaxed. In this case, we use an array to store the elements as we go through the linked list the first time k
 nodes at a time. As we go through the second time, we insert the elements into the linked list in the reverse order from
 the array.

Time complexity: O(n)
Space complexity: O(n)


3. Imporvisation on Other Approaches(1)

This approach is very similar to Other Approaches(1) but it has a clear explanation and direction. We create a dummy pointer
initially and cover k pointers at a time. Our goal is to reverse pointers between beg and end, both exclusive. Since this
reverses the pointers in betwen, the only thing remainign is to reverse the begin and end pointers. As a result, we adjust the 
pointers accordingly and set it up for the next k nodes.

Time complexity: O(n)
Space complexity: O(1)
*/

// Other Approaches(1)
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
    ListNode * reverseNodes(ListNode * & dummyNode, int k){
        ListNode * beg = dummyNode->next, * end = dummyNode->next, * movingNode = dummyNode;
        bool isEnd = true;
        while(isEnd){
            int count = 0; // used to check if we have a valid collection
            while(end && count < k){
                // adjusts the end pointer so that we are sorting only 1 collection with k nodes at a time
                end = end->next;
                ++count;
            }
            // if it's not a valid collection of k nodes in size, it's invalid and hence we stop it.
            if(count != k)
                isEnd = false;
            else{
                count = 0;
                // reversing the nodes but in a slightly different manner
                // we make the beginning of first collection point to end of second collection and adjust it later
                ListNode * prev = end, * curr = beg;
                while(count++ < k){
                    // reverses nodes in between
                    ListNode * temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                }
                // using the moving node we can adjust the head of each collection to the new node instead and make it
                // ready for the next collection by adjusting itself to the tail of the current collection
                movingNode->next = prev;
                movingNode = beg;
                beg = end;
            }
        }
        return dummyNode->next;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !(head->next) || k==1 )
            return head;
        else{
            ListNode * dummyNode = new ListNode(-1, head);
            return reverseNodes(dummyNode, k);
        }
    }
};

// Other Approaches(2)
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
    void reverseNodes(ListNode * & head, int k){
        ListNode * beg = head, * end = head;
        vector<int> array(k,-1);
        bool isEnd = false;
        while(!isEnd){
            int count = 0;
            while(end && count < k){
                array[count++] = end->val;
                end = end->next;
            }
            
            if(count != k)
                isEnd = true;
            else{
                while(beg != end){
                    beg->val = array[--count];
                    beg = beg->next;
                }
            }
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!(!head || !(head->next) || k==1 ))
            reverseNodes(head, k);
        return head;
    }
};


// Other Approaches(3)
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
    ListNode * reverseBetweenBegEnd(ListNode * begin, ListNode * end){
        ListNode * prev = begin, * curr = begin->next, * first = curr;
        while(curr != end){
            ListNode * temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        // Adjusting pointers for next iteration
        begin->next = prev;
        first->next = curr;
        return first;
    }
    
    ListNode * reverseNodes(ListNode * & head, int k){
        ListNode * dummy = new ListNode(-1, head);
        int count = 0;
        ListNode * begin = dummy;
        while(head){
            ++count;
            if(count % k == 0){
                begin = reverseBetweenBegEnd(begin, head->next);
                head = begin->next;
            }
            else{
                head = head->next;
            }
        }
        
       // deleting dummy and returning head
        ListNode * temp = dummy->next;
        dummy->next = NULL;
        delete dummy;
        return temp;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!(!head || !(head->next) || k==1 ))
            return reverseNodes(head, k);
        return head;
    }
};