/*
-------------------------Question:

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

/*
-------------------------My Approaches:
1. Using map to store records of duplicates

We can use a map to store the occurences of the numbers and whether duplicates of them exist. While removing the duplicates,
we want to keep status if the first element is a duplicate or not. If it is,we flag it. We then start with the second 
element and remove all the duplicates by checking whether they exist as a duplicate in the map. Finally, once we are done
with the rest of the list, we go back to the first element and fix it into place depending on whether or not it is a 
duplicate.

Time complexity: O(n)
Space complexity: O(n)


2. Using three pointers to store the current node, next node and prev node

Instead of using a map to store the occurences of the elements in the map, we can achieve the same result with just 3 
pointers instead. These pointers will help us adjust the position of the duplicate elements and remove them from the 
linked list when they are encountered.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

Other approaches very similar to My Approaches(2)

*/

// MY Approahces(1)
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
    void createMap(ListNode * head, unordered_map<int,bool> & map){
        ListNode * temp = head;
        while(temp){
            if(map.find(temp->val) == map.end())
                map[temp->val] = false;
            else
                map[temp->val] = true;
            
            temp = temp->next;
        }
    }
    
    void printMap(unordered_map<int, bool> map){
        for(auto it = map.begin(); it != map.end(); it++)
            cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
    }
    
    void removeDuplicates(unordered_map<int, bool> map, ListNode * & head){
        ListNode * slow = head, * fast = head->next;
        bool deleteHead = false;
        if(map[slow->val])
            deleteHead = true;
        
        while(fast){
            if(map[fast->val]){
                ListNode * temp = fast;
                fast = fast->next;
                slow->next = fast;
                temp->next = NULL;
            }
            else{
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        if(deleteHead){
            ListNode * temp = head;
            head = head->next;
            temp->next = NULL;
        }
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head){
            unordered_map<int,bool> map;
            createMap(head, map);
            removeDuplicates(map, head);
        }
        return head;
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
    void removeDuplicates(ListNode * & head){
        // fast pointer is one node ahead of slow pointer
        // prev pointer is used to point to the previous pointer of slow pointer
        ListNode * slow = head;
        ListNode * fast = head->next;
        ListNode * prev = NULL;
        // Used to check if the beginning element is a duplicate element as well as used to indicate if the node that's
        // a duplicare is to be skipped.
        bool deleteBeg = false, skipNode = false;
        
        // As lon as fast exists we run the loop
        while(fast){
            // If the vlaues are equal, we know we have encountered a duplicate
            if(slow->val == fast->val){
                // If it's the beginning of the linked list, we want to make sure to remove the beginning node.
                if(slow == head)
                    deleteBeg = true;
                
                // temp used to remove the duplicate node which is fast
                ListNode * temp = fast;
                fast = fast->next;
                temp->next = NULL;
                slow->next = fast;
                skipNode = true; // setting to true to remove the slow pointer associated with this fast pointer
            }
            else{
                // If we have to skip the slow pointer since it's a duplicate and it's not at the beginning of the linked list
                if(skipNode && prev){
                    skipNode = false;
                    prev->next = slow->next;
                    slow->next = NULL;    
                }
                else{
                    // we adjust the prev pointer to the slow pointer for the next loop run.
                    if(!prev)
                        skipNode = false;
                    prev = slow;
                }
                
                //  move pointers ahead
                slow = fast;
                fast = fast->next;
            }
        }
        
        // if we are not at the beginning of the linked list and we have to skip a node after coming out of a loop
        if(skipNode && prev){
            skipNode = false;
            prev->next = slow->next;
            slow->next = NULL;
        }
        
        // If the beinning element of the linked list is dupplicate, it must be removed.
        if(deleteBeg){
            ListNode * temp = head;
            head = head->next;
            temp->next = NULL;
        }
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head)
            removeDuplicates(head);
        return head;
    }
};