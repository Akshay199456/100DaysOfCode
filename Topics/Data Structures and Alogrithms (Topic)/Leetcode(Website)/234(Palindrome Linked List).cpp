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



2. Modifying the original linked list[Same]

This approach modifies the original linked list. It breaks it down into a few steps
	a. getting the length of the original linked list.
	b. getting the second head by detecting whether the original list had an even or ordd number
	of elements. If it had odd, we remove the middle element as it doesn't factor into determing
	whether the ;inked list is a pallindrome or not. If it's even, we keep the linked list as it
	is. The second head will start at the middle of the linked list(modified or not).
	c. reverse the linked list that start at the second head. At the end of the reversal, you want
	to return the tail of this linkedlist
	d. Compare the values starting at both the heads.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------Other approaches

1. Recursive approach to check the beginning with the end of the list[Same]

This method uses a recursive approach to test the beginning pointer wih the end pointer. It does
this till the beginning pointer hits NULL as well as the end pointer hits the first element. As
a result, this approach goes through the whole linked list even though it may not be a palindrome.


Time complexity: O(n)
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
    int getLength(ListNode * head){
        int count = 0;
        ListNode * temp = head;
        while(temp){
            ++count;
            temp = temp -> next;
        }
        return count;
    }
    
    void removeMiddleNode(ListNode * head, int length){
        ListNode * temp = head, * curr = NULL;
        int count = 0;
        while(count < length/2){
            curr = temp;
            temp = temp -> next;
            ++count;
        }
        
        curr->next = temp->next;
        temp->next = NULL;
    }
    
    ListNode * getSecondHead(int length, ListNode * head){
        ListNode * temp = head;
        int count = 0;
        if(length %2 !=0)
            removeMiddleNode(head, length--);
        while(count < length/2){
            temp = temp->next;
            ++count;
        }
        return temp;
    }
    
    ListNode * reverseList(ListNode * secondHead, ListNode *& newHead){
        if(!(secondHead->next)){
            newHead = secondHead;
            return secondHead;
        }
        else{
            ListNode * nextNode = reverseList(secondHead->next, newHead);
            nextNode->next = secondHead;
            secondHead->next = NULL;
            return secondHead;
        }
        
    }
    
    void displayList(ListNode * head){
        ListNode * temp = head;
        while(temp){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"\n";
    }
    
    bool compareHeads(ListNode * head, ListNode * newHead){
        ListNode * temp = head, * newTemp  = newHead;
        while(temp && newTemp){
            if(temp-> val != newTemp->val)
                return false;
            temp = temp->next;
            newTemp = newTemp->next;
        }
        return true;
    }
    
    bool checkPalindrome(ListNode * head){
        ListNode * newHead = NULL;
        int length = getLength(head);
        ListNode * secondHead = getSecondHead(length, head);
        reverseList(secondHead, newHead);
        return compareHeads(head, newHead);
    }
    
    bool isPalindrome(ListNode* head) {
        if( !head || !(head->next))
            return true;
        else
            return checkPalindrome(head);
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
    bool checkPalindrome(ListNode *& startPointer, ListNode * current){
        if(!current)
            return true;
        else{
            bool status = checkPalindrome(startPointer, current->next) && (startPointer->val == current->val);
            startPointer = startPointer->next;
            return status;
        }
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(!head || !(head->next))
            return true;
        else
            return checkPalindrome(head, head);
    }
};