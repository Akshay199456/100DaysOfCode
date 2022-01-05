/*
-------------------------Question:

Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 

Example:

Input: 
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
Output:  
[null,null,null,null,2,null,3]

Explanation:
MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
 

Constraints:

0 <= index,val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex.
*/

/*
-------------------------My Approaches:
1. Implmenting each method as its own component and bunch of test cases

You can think of this problem as a system design problem. It is tryng to test how to you plan and implement this
concept. As a result, UMPIRE method is of very high importance. You want to treat each method as ots own component and 
have its own set of test cases to understand its functionality. The more time you invest into planning, the less time
it will take you to implement it. In addition, you want to understand the tradeoffs that might be involved in different
possible solutions
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
struct Node{
    int val;
    Node * next;
    Node(){
        this->val = 0;
        this->next = NULL;
    }
    
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
    
    Node(int val, Node * node){
        this->val = val;
        this->next = node;
    }
};

class MyLinkedList {
public:
    Node * head, *tail;
    int count;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    
    void printList(){
        Node * temp = head;
        while(temp){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= 0 && index < count){
            Node * temp = head;
            int currentCount = 0;
            while(currentCount < index){
                temp = temp->next;
                ++currentCount;
            }
            return temp->val;
        }
        return -1;
        // printList();
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node * temp = new Node(val);
        if(!head){
            head = temp;
            tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        ++count;
        // printList();
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node * temp = new Node(val);
        if(!head){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }  
        ++count;
        // printList();
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index >= 0){
            if(index == 0)
                addAtHead(val);
            else if(index == count)
                addAtTail(val);       
            else if(index < count){
                Node * temp = new Node(val);
                Node * curr = head, * prev = head;
                int currentCount = 0;
                while(currentCount < index){
                    prev = curr;
                    curr = curr->next;
                    ++currentCount;
                }
                prev->next = temp;
                temp->next = curr;
                ++count;
            }   
        }
        // printList();
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= 0 && index < count){
            Node * temp = head;
            Node * prev = NULL;
            if(head == tail){
                head = NULL;
                tail = NULL;
                delete temp;
            }
            else{
                if(index  == 0){
                    head = head->next;
                    temp->next = NULL;
                    delete temp;
                }
                else{
                    int currentCount = 0;
                    while(currentCount < index){
                        prev = temp;
                        temp = temp->next;
                        ++currentCount;
                    }
                    if(temp == tail)
                        tail = prev;
                    prev->next = temp->next;
                    temp->next = NULL;
                    delete temp;
                }
            }
            --count;
        }
        // printList();
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */