/*
-------------------------Question:

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
*/

/*
-------------------------My Approaches:

1. Using a vector

We use a vector here to store the elements of the linked list. This way we can easily check if it's
a palindrome by checking each element with its counter element from the end of the list

Time complexity : O(n)
Space complexity: O(n)
*/


//My Appraches(1)
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
    bool checkPalindrome(ListNode * head){
        ListNode * temp = head;
        vector<int> elements;
        while(temp){
            elements.push_back(temp->val);
            temp = temp->next;
        }
        
        int nElements = elements.size();
        for(int i = 0; i < nElements; i++){
            if(elements[i] != elements[nElements - 1 - i])
                return false;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        if( !head || !(head->next))
            return true;
        else
            return checkPalindrome(head);
    }
};