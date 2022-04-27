/*
Problem statement:


*/

/*
-------------------------    My Approaches:
1. 

    Time complexity: O()
    Space complexity: O()
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
