/*
-------------------------Question:

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/

/*
-------------------------    My Approaches:
1. Using prioirty queue to gather results

We can use a priority queue to push values from each of the sorted lists. We then pop off the one that's the smallest 
and move its pointer forward. We repeat this process till the lists have been covered.

Time complexity: O(nklog k)
Space complexity: O(k) 
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

typedef pair<int, int> pi;

class Solution {
public:
    void initializeQueue(vector<ListNode *> & lists, priority_queue<pi, vector<pi>, greater<pi>> & pq){
        for(int i=0; i<lists.size(); i++){
            if(lists[i])
                pq.push(make_pair(lists[i]->val, i));
        }
    }
    
    void mergeLists(vector<ListNode *> & lists, ListNode * & tail, priority_queue<pi, vector<pi>, greater<pi>> & pq){
        int completedLists = 0;
        initializeQueue(lists, pq);
        while(completedLists < lists.size() && pq.size()){
            pair<int, int> topPair = pq.top();
            pq.pop();
            tail->next = lists[topPair.second];
            tail = tail->next;
            lists[topPair.second] = lists[topPair.second]->next;
            if(lists[topPair.second])
                pq.push(make_pair(lists[topPair.second]->val, topPair.second));
            else
                completedLists++;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = new ListNode(-1);
        ListNode * tail = head;
        if(lists.size()){
            priority_queue<pi, vector<pi>, greater<pi>> pq;
            mergeLists(lists, tail, pq);
        }
        return head->next;
    }
};