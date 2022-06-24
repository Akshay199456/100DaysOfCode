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
brute force solition would be to add all elements of the given 'k' lists to one list and sort it. if there are a total of 'N' elements in all the input lists, then the brute force appraoch wi;; ave a time complexity of O(
    N log N) as well need to sort the merged list. how can we utilzie the fact that input lists are indivudally sorted.

if we have to find the smallest element of all the input lists, we have to compare only the smallest(i.e the first) element of all the lists. once we ahve the smallest elemenmt., we can put it int he merged lists. following a smilar
pattern we can then find the next smallest elemtn of all the lists to add it tot he merged list.

the best data strcuture that comes to mind to find the smallest num,ber amounf a set of 'K' numbers is a heap. lets see how we can use  aheap to find a better algptoithm
    1. we can inser the first element of each array in min heap
    2. after this, we can take out the smallest(top) element from heap and add it to merged list.
    3. adfer removing the smalelst element from the heap, we can insert the next elmeent of the same list inot the heap
    4. we can repeat steps 2 ad 3 to pipilat eh merged lists in sorted order

)

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
  struct valueCompare {
    bool operator()(const ListNode *x, const ListNode *y) { return x->value > y->value; }
  };

  static ListNode *merge(const vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, valueCompare> minHeap;

    // put the root of each list in the min heap
    for (auto root : lists) {
      if (root != nullptr) {
        minHeap.push(root);
      }
    }

    // take the smallest (top) element form the min-heap and add it to the result;
    // if the top element has a next element add it to the heap
    ListNode *resultHead = nullptr, *resultTail = nullptr;
    while (!minHeap.empty()) {
      ListNode *node = minHeap.top();
      minHeap.pop();
      if (resultHead == nullptr) {
        resultHead = resultTail = node;
      } else {
        resultTail->next = node;
        resultTail = resultTail->next;
      }
      if (node->next != nullptr) {
        minHeap.push(node->next);
      }
    }

    return resultHead;
  }
};

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);

  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);

  ListNode *l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);

  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1, l2, l3});
  cout << "Here are the elements form the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
