/*
Problem statement:

Given the head of a Singly LinkedList, reverse the LinkedList. Write a function to return the new head of the reversed LinkedList.

    2   
    4   
    6   
    8   
    10   
    null   
 Original List:  
 Reversed List:  
 Example:  
    2   
    4   
    6   
    8   
    10   

*/

/*
-------------------------    My Approaches:
1. Three pointer approach

    We can use three pointers to solve this problem. by using these three pointers we are
    able to to reverse the ;inked list

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

class ReverseLinkedList {
 public:
  static void reverseList(ListNode * & head){
    ListNode * prevNode{nullptr}, *nextNode{head->next}, *currNode{head};
    while(currNode){
      currNode->next = prevNode;
      prevNode = currNode;
      currNode = nextNode;
      if(nextNode)
        nextNode = nextNode->next;
    }
    head = prevNode;
  }

  static ListNode *reverse(ListNode *head) {
    // TODO: Write your code here
    if(head)
      reverseList(head);
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);

  ListNode *result = ReverseLinkedList::reverse(head);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}



//  Other Approaches(1)
