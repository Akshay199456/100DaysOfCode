/*
Problem statement:

Given the head of a LinkedList and two positions ‘p’ and ‘q’, reverse the LinkedList from position ‘p’ to ‘q’.

*/

/*
-------------------------    My Approaches:
1. In-place reversal of list and dummy node

    We can use the in-place reveral and ummy node tcechnique to solve this problem.
    using the dummy node as the first node helps us as even if we are reversing the whole
    list, having the dummy node always makes it as a sub-list so it becomes easier to 
    change head.

    Dummy node is always a good option when you know that the state of the head node
    might change based on in-place manipulation.

    We then set pointers accordingly ro identify the sub beg and end as well as list beg and end
    and then reverse the list

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
problem follows in-palce reversal of a linked list. can use a similar appraoch as dicussed
in reverse a linked list problem
    1. skip the first p-1 nodes , to reach the node at position p.
    2. remember the node at position p-1 to be used later to connect with the reversed sub-list
    3. next, reverse the nodes from p to q using the same approach discussed in reverse a 
    linked list problem
    4. connect p-q and q+1 nodes to the reversed sub-list
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

class ReverseSubList {
 public:
  static int getNumber(ListNode * head){
    int count = 1;
    while(head->next){
      head = head->next;
      count+=1;
    }
    return count;
  }

  static void insertDummy(ListNode * & head){
    ListNode * temp = new ListNode(-1);
    temp->next = head;
    head = temp;
  }

  static void setPointers(ListNode * & listBeg, ListNode * & subBeg, ListNode * & subEnd, ListNode * & listEnd, int p, int q){
    int count = 1;
    while (count < p){
      listBeg = subBeg;
      subBeg = subBeg->next;
      count += 1;
    }

    subEnd = subBeg;
    while(count < q){
      subEnd = subEnd->next;
      count += 1;
    }
    listEnd = subEnd->next;
  }

  static void reverseList(ListNode * subBeg, ListNode * subEnd){
    ListNode * prevNode{nullptr}, * currNode{subBeg}, * nextNode{subBeg->next};
    while(subEnd != prevNode){
      currNode->next = prevNode;
      prevNode = currNode;
      currNode = nextNode;
      if(nextNode)
        nextNode = nextNode->next;
    }
  }

  static ListNode *reverse(ListNode *head, int p, int q) {
    // TODO: Write your code here
    if(head && head->next){
      int total = getNumber(head);
      if(p>=1 && q<=total && p!=q){
        insertDummy(head);
        ListNode * listBeg{head}, * subBeg{head->next}, * subEnd{nullptr}, * listEnd{nullptr};
        setPointers(listBeg, subBeg, subEnd, listEnd, p, q);
        reverseList(subBeg, subEnd);

        listBeg->next = subEnd;
        subBeg->next = listEnd;
        head = head->next;
      }
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

  ListNode *result = ReverseSubList::reverse(head, 1, 2);
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

class ReverseSubList {
 public:
  static ListNode *reverse(ListNode *head, int p, int q) {
    if (p == q) {
      return head;
    }

    // after skipping 'p-1' nodes, current will point to 'p'th node
    ListNode *current = head, *previous = nullptr;
    for (int i = 0; current != nullptr && i < p - 1; ++i) {
      previous = current;
      current = current->next;
    }

    // we are interested in three parts of the LinkedList, part before index 'p', part between 'p'
    // and 'q', and the part after index 'q'
    ListNode *lastNodeOfFirstPart = previous;  // points to the node at index 'p-1'

    // after reversing the LinkedList 'current' will become the last node of the sub-list
    ListNode *lastNodeOfSubList = current;
    ListNode *next = nullptr;  // will be used to temporarily store the next node

    // reverse nodes between 'p' and 'q'
    for (int i = 0; current != nullptr && i < q - p + 1; i++) {
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }

    // connect with the first part
    if (lastNodeOfFirstPart != nullptr) {
      lastNodeOfFirstPart->next = previous;  // 'previous' is now the first node of the sub-list
    } else {  // this means p == 1 i.e., we are changing the first node (head) of the LinkedList
      head = previous;
    }

    // connect with the last part
    lastNodeOfSubList->next = current;

    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = ReverseSubList::reverse(head, 2, 4);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
