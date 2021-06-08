/*
-------------------------Question:

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: The given linked list is empty (null pointer), so return null.
 

Constraints:

0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random is null or is pointing to some node in the linked list.
*/

/*
-------------------------    My Approaches:
1.  Using hashmap to store positions of pointers for both new and old nodes

We can use hashmaps to store information about both the new and old nodes. For the old nodes, we want to use the node as the key and store its index ans well as the index of the random node. For the new nodes, we want to store the index
of the node as the key and the noed asthe value. Using this information, we can then link the new nodes between themselves.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:
1. In place linked list manipulation

Insteafd of using ahashmap to store relationships between old and new nodes, we can instead create new nodes nad then link the old nodes immediately to the nwe nodes. Using this stategy, we can easily change both the new nd random
poiunters for the new and old nodes respectively that would give us the ability to modify the linked list in place.

Time complexity: O(n)
Space complexity: O(1)
*/

// My Approaches(1)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void createOldValueMapping(unordered_map<Node *, pair<int, int>> & oldListMapping, Node * head){
        int count = 0;
        while(head){
            oldListMapping[head] = make_pair(count++, -1);
            head = head->next;
        }
    }
    
    void createRandomMapping(unordered_map<Node *, pair<int, int>> & oldListMapping, Node * head){
        while(head){
            if(head->random){
                pair<int, int> currentPair  = oldListMapping[head];
                pair<int, int> randomPair = oldListMapping[head->random];
                oldListMapping[head] = make_pair(currentPair.first, randomPair.first);
            }
            head = head->next;
        }
    }
    
    void createNewMapping(unordered_map<int, Node *> & newListMapping, Node * & newHead, Node * head){
        Node * newTail = newHead;
        int count = 0;
        while(head){
            Node * temp = new Node(head->val);
            newTail->next = temp;
            newTail = temp;
            newListMapping[count++] = temp;
            head = head->next;
        }
    }
    
    void connectNewRandom(unordered_map<int, Node *> & newListMapping, unordered_map<Node *, pair<int, int>> & oldListMapping, Node * newHead, Node * head){
        while(newHead){
            pair<int, int> currentPair = oldListMapping[head];
            if(currentPair.second != -1){
                Node * newNode = newListMapping[currentPair.second];
                newHead->random = newNode;
            }
            head = head->next;
            newHead = newHead->next;
        }
    }
     
    
    void printMaps(unordered_map<Node *, pair<int, int>> oldListMapping, unordered_map<int, Node *> newListMapping){
        cout<<"Old mapping"<<endl;
        for(auto it = oldListMapping.begin(); it!= oldListMapping.end(); it++){
            cout<<"Value: "<<it->first->val<<" "<<"its index: "<<it->second.first<<" Random index: "<<it->second.second<<endl; 
        }
        
        cout<<"New mapping"<<endl;
        for(auto it=newListMapping.begin(); it!= newListMapping.end(); it++){
            cout<<"Index: "<<it->first<<" Node value: "<<it->second->val<<endl;
        }
    }
    
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, pair<int, int>> oldListMapping;
        unordered_map<int, Node *> newListMapping;
        Node * newHead = new Node(-1);
        if(head){
            createOldValueMapping(oldListMapping, head);
            createRandomMapping(oldListMapping, head);
            createNewMapping(newListMapping, newHead, head);
            connectNewRandom(newListMapping, oldListMapping, newHead->next, head);
        }
        return newHead->next;
        
    }
};


// Other Approaches(1)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void attachNewNodes(Node * & head){
        Node * temp = head;
        while(temp){
            Node * newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
    }
    
    void attachRandomNodes(Node * & head){
        Node * temp = head;
        while(temp){
            Node * oldNode = temp, * newNode = temp->next;
            if(oldNode->random)
                newNode->random = oldNode->random->next;
            temp = newNode->next;
        }
    }
    
    void removeOldAttachments(Node * & head, Node * & newHead){
        Node * temp = head;
        newHead->next = temp->next;
        while(temp){
            Node * oldNode = temp, * newNode = temp->next;
            oldNode->next = newNode->next;
            if(oldNode->next)
                newNode->next = oldNode->next->next;
            temp = temp->next;
        }
    }
    
    Node* copyRandomList(Node* head) {
        Node * newHead = new Node(-1);
        if(head){
            attachNewNodes(head);
            attachRandomNodes(head);
            removeOldAttachments(head, newHead);   
        }
        return newHead->next;
    }
};