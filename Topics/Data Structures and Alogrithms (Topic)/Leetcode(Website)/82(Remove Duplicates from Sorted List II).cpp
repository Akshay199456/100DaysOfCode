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
*/

/*
-------------------------Other approaches

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