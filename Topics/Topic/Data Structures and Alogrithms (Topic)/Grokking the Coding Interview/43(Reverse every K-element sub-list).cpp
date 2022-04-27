/*
Problem statement:

Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ sized sub-list starting from the head.

If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.
*/

/*
-------------------------    My Approaches:
1. in-place reversal of a linked list

    this problem sues the same technique as pb 42 grok does. the only difference is that
    it repeats itself continously until the very end so we must adjust the pointers 
    accordingly to make that possible.

    Time complexity: O(n)
    Space complexity: O(1)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
follows the in-place reversal of am linked list patterns and is quite to reverse a sub-list/..
only difference is that we have to reverse all the sub-lists. can use the same approach starting
with the first sub-list (i.e p=1, q=k) and keep reversing all the sublists of size 'k'.
*/



//  My approaches(1)
using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseEveryKElements {
 public:
  static void insertDummy(ListNode * & head){
    ListNode * temp = new ListNode(-1);
    temp->next = head;
    head = temp;
  }

  static void setPointers(ListNode * listBeg, ListNode * & subEnd, ListNode * & listEnd, int k){
    subEnd = listBeg;
    while(k && subEnd->next){
      subEnd = subEnd->next;
      k-=1;
    }
    listEnd = subEnd->next;
  }

  static void reverseList(ListNode * & subBeg, ListNode * & subEnd){
    ListNode * prevNode{nullptr}, * currNode{subBeg}, * nextNode{subBeg->next};
    while(subEnd != prevNode){
      currNode->next = prevNode;
      prevNode = currNode;
      currNode = nextNode;
      if(nextNode)
        nextNode = nextNode->next;
    }
  }

  static void reverseSubLists(ListNode * head, int k){
    ListNode * listBeg{head}, * subBeg{head->next}, * subEnd{nullptr}, * listEnd{nullptr};
    while(subBeg){
      setPointers(listBeg, subEnd, listEnd, k);
      reverseList(subBeg, subEnd);
      
      listBeg->next = subEnd;
      subBeg->next = listEnd;
      listBeg = subBeg;
      subBeg = listEnd;
    }
  }

  static ListNode *reverse(ListNode *head, int k) {
    // TODO: Write your code here
    if(head && head->next){
      insertDummy(head);
      reverseSubLists(head, k);
      head = head->next;
    }
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  
  ListNode *result = ReverseEveryKElements::reverse(head, 2);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}



//  Other Approaches(1)
using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseEveryKElements {
 public:
  static ListNode *reverse(ListNode *head, int k) {
    if (k <= 1 || head == nullptr) {
      return head;
    }

    ListNode *current = head, *previous = nullptr;
    while (true) {
      ListNode *lastNodeOfPreviousPart = previous;
      // after reversing the LinkedList 'current' will become the last node of the sub-list
      ListNode *lastNodeOfSubList = current;
      ListNode *next = nullptr;  // will be used to temporarily store the next node
      // reverse 'k' nodes
      for (int i = 0; current != nullptr && i < k; i++) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
      }

      // connect with the previous part
      if (lastNodeOfPreviousPart != nullptr) {
        lastNodeOfPreviousPart->next =
            previous;  // 'previous' is now the first node of the sub-list
      } else {         // this means we are changing the first node (head) of the LinkedList
        head = previous;
      }

      // connect with the next part
      lastNodeOfSubList->next = current;

      if (current == nullptr) {  // break, if we've reached the end of the LinkedList
        break;
      }
      // prepare for the next sub-list
      previous = lastNodeOfSubList;
    }

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode *result = ReverseEveryKElements::reverse(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
