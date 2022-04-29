/*
Problem statement:

Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the right by ‘k’ nodes.
*/

/*
-------------------------    My Approaches:
1. in-place reversal of linked list

    we can use the in-place revrsal technique to solve this problem. what we do is to 
    push the pointer by k steps ahead from the head of th elinked list. we then oush a pointer 
    ffrom the head forwarrd and another from the k steps ahead. when we reach the end, that will
    indicate th end of the secind linked list. the first pointer will indicat eht end of the 
    first linked list. we then use that information to rotate the linked list

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

class RotateList {
 public:
  static int getNumberNodes(ListNode * head){
    int count = 0;
    while(head){
      head = head->next;
      count += 1;
    }
    return count;
  }

  static void rotateList(ListNode * & head, int swapCount){
    ListNode * endSecond = head, * begSecond = nullptr, * endFirst = head;
    while(swapCount--)
      endSecond = endSecond->next;
    
    while(endSecond->next){
      endSecond = endSecond->next;
      endFirst = endFirst->next;
    }
    begSecond = endFirst->next;

    endFirst->next = nullptr;
    endSecond->next = head;
    head = begSecond;

  }


  static ListNode *rotate(ListNode *head, int rotations) {
    // TODO: Write your code here
    int count = getNumberNodes(head);
    if(head && count && rotations % count){
      rotateList(head, rotations % count);
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

  ListNode *result = RotateList::rotate(head, 5);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
