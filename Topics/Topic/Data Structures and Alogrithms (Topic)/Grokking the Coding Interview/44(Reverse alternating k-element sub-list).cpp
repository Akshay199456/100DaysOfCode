/*
Problem statement:

Given the head of a LinkedList and a number ‘k’, reverse every alternating ‘k’ sized sub-list starting from the head.

If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.

*/

/*
-------------------------    My Approaches:
1. In-place reversal of linked list

    We can apply the same in-place reversal of linked list and dummy node for this problem
    as we did for pb 43. the only difference here is that we have to skip few nodes

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

class ReverseAlternatingKElements {
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

  static void skipNodes(ListNode * & listBeg, ListNode * & subBeg, int k){
    while(k && listBeg->next){
      listBeg = listBeg->next;
      k -= 1;
    }
    subBeg = listBeg->next;
  }

  static void reverseAlternate(ListNode * head, int k){
    ListNode * listBeg{head}, * subBeg{head->next}, * subEnd{nullptr}, * listEnd{nullptr};
    while(subBeg){
      setPointers(listBeg, subEnd, listEnd, k);
      reverseList(subBeg, subEnd);

      listBeg->next = subEnd;
      subBeg->next = listEnd;
      listBeg = subBeg;
      subBeg = listEnd;

      skipNodes(listBeg, subBeg, k);
    }
  }

  static ListNode *reverse(ListNode *head, int k) {
    // TODO: Write your code here
    if(k > 1 && head && head->next){
      insertDummy(head);
      reverseAlternate(head,k);
      head = head->next;
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

  ListNode *result = ReverseAlternatingKElements::reverse(head, 8);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}




//  Other Approaches(1)
