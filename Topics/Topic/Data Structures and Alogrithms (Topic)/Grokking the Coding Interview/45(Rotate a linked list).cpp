/*
Problem statement:

Given the head of a Singly LinkedList and a number ‘k’, rotate the LinkedList to the right by ‘k’ nodes.

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
another way of defining the rotation is to take the sub-list of 'k' ending nodes of the
linked list and connect them to the beginning. other than that we ahve to do three things"
    1. connect the last node of the linked list to the head becase the list will have a differnet 
    tail after the rotation
    2. new head of the linked list will be the node at the beginning of th esublist.
    3. node right before the start of sub-list will be the new taol of the rotated 
    linked list
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

class RotateList {
 public:
  static ListNode *rotate(ListNode *head, int rotations) {
    if (head == nullptr || head->next == nullptr || rotations <= 0) {
      return head;
    }

    // find the length and the last node of the list
    ListNode *lastNode = head;
    int listLength = 1;
    while (lastNode->next != nullptr) {
      lastNode = lastNode->next;
      listLength++;
    }

    lastNode->next = head;    // connect the last node with the head to make it a circular list
    rotations %= listLength;  // no need to do rotations more than the length of the list
    int skipLength = listLength - rotations;
    ListNode *lastNodeOfRotatedList = head;
    for (int i = 0; i < skipLength - 1; i++) {
      lastNodeOfRotatedList = lastNodeOfRotatedList->next;
    }

    // 'lastNodeOfRotatedList.next' is pointing to the sub-list of 'k' ending nodes
    head = lastNodeOfRotatedList->next;
    lastNodeOfRotatedList->next = nullptr;
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

  ListNode *result = RotateList::rotate(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
