/*
Problem statement:

iven an array of ‘K’ sorted LinkedLists, merge them into one sorted list.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7]
Output: [1, 5, 7, 8, 9]

*/

/*
-------------------------    My Approaches:
1. K way merge pattern

    we cam apply the k way merge pattern here. we are given k sorted lisnked lists and should merge them into one sorted list.
    this technique is eprfect for this kind of problem.

    there are 2 different approaches you can use here. if we are given access to movable pointers in vector of linked lists, we can use it in order to move the head forward.
    if not, we can just insert the node into the min heap itself and add a comparator function to make the comparing decision.

    Time complexity: O(nklogk) where k-> no of sorted linked;lists; n-> avg number of elemnts per linked list
    Space complexity: O(k)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class MergeKSortedLists {
 public:
  struct compareOperation{
    bool operator()(const ListNode * x, const ListNode * y){
      return y->value < x->value;
    }
  };

  static ListNode * mergeLists(const vector<ListNode *> &lists){
    priority_queue<ListNode *, vector<ListNode *>, compareOperation> pq;
    ListNode * resultHead = nullptr, * resultTail = nullptr;
    int completeLists = 0;

    // insert the first elements from each list into min heap
    for(int i=0; i<lists.size(); i++){
      if(lists[i])
        pq.push(lists[i]);
      else
        completeLists++;
    }

    while(completeLists < lists.size()){
      ListNode * topPair = pq.top();
      pq.pop();

      // add this current node to result
      if(!resultHead)
        resultHead = resultTail = topPair;
      else{
        resultTail->next = topPair;
        resultTail = resultTail->next;
      }

      // push next value into heap if it exists
      if(topPair->next){
        pq.push(topPair->next);
      }
      else
        completeLists++;
    }

    return resultHead;
  }

  static ListNode *merge(const vector<ListNode *> &lists) {
    ListNode *resultHead = nullptr;
    // TODO: Write your code here
    return mergeLists(lists);
  }
};

int main(int argc, char *argv[]) {
  ListNode *l1 = nullptr;

  ListNode *l2 = nullptr;

  ListNode *l3 = nullptr;

  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1,l2,l3});
  cout << "Here are the elements form the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}



//  Other Approaches(1)
