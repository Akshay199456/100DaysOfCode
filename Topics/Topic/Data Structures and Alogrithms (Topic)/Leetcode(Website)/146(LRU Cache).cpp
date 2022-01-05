/*
-------------------------Question:

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
At most 3 * 104 calls will be made to get and put.
*/

/*
-------------------------    My Approaches:
1. Using a doubly linked list with a hashmap

We can implement the LRU cache using a hashmap and a doubly linked list. The hashm,ap stores the references to the nodess created. This way we can move th most recently used node easily around and adjusting it into the right position. 
For every get and put operation, there are certain conditions which can exist(added as comments into the code)

Time complexity:

get-> O(1)
put-> O(1)

Space complexity: O(n)

2. Using a hashmap with a queue[Not coded]
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
struct DoublyLinkedListNode{
    int key;
    int value;
    DoublyLinkedListNode * next;
    DoublyLinkedListNode * prev;
};

class LRUCache {
public:
    int totalElements;
    int cap;
    DoublyLinkedListNode * head;
    DoublyLinkedListNode * tail;
    unordered_map<int, DoublyLinkedListNode *> elementsSeen;
    
    LRUCache(int capacity) {
        totalElements = 0;
        cap = capacity;
        head = NULL;
        tail = NULL;
    }
    
    // creates a new node and returns it
    DoublyLinkedListNode * getNewNode(int key, int value){
        DoublyLinkedListNode * tempNode = new DoublyLinkedListNode;
        tempNode->key = key;
        tempNode->value = value;
        tempNode->next = NULL;
        tempNode->prev = NULL;
        
        return tempNode;
    }
    
    // given a key, this function deletes the node associated with that key from the linked list and the map
    void deleteNode(int key){
        /*
         Need to delete the node from the linked list and the hashmap
            1. find the node to delete. Get th node's key and value.
            2. Match the key to the key stored in the hashmap and delete it.
            3. Now, only remaining task is to delete node from the linked list
            4. 3 possible states in which the node can exist
                1. node is at the beginning of the list
                2. node is at the end of the list
                3. node is between beginning and end, both not included
        */
        DoublyLinkedListNode * lruNode = elementsSeen[key];
        
        // node to be deleted is at the head of the list
        if(lruNode == head){
            // if the cahce is only of length 1
            if(lruNode == tail){
                head = NULL;
                tail = NULL;
            }
            // else otherwise
            else{
                head = head->next;
                head->prev = NULL;
                lruNode->next = NULL;
            }
        }
        // node to be deleted is at the end of the list
        else if(lruNode == tail){
            tail = tail->prev;
            tail->next = NULL;
            lruNode->prev = NULL;
        }
        // node to be deeleted is between head and tail
        else{
            DoublyLinkedListNode * prevNode = lruNode->prev;
            DoublyLinkedListNode * nextNode = lruNode->next;
            
            prevNode->next = lruNode->next;
            nextNode->prev = lruNode->prev;
            
            lruNode->next = NULL;
            lruNode->prev = NULL;
        }
        
        elementsSeen.erase(key);
        totalElements--;
        delete lruNode;
    }
    
    // given a key and value, this function creates a node corresponding ot that key and value and inserts it at the beginning of the linked list
    void insertNode(int key, int value){
        DoublyLinkedListNode * tempNode = getNewNode(key, value);
        if(!head)
            tail = tempNode;
        else{
            tempNode->next = head;
            head->prev = tempNode;
        }

        ++totalElements;
        head = tempNode;
        elementsSeen[key] = tempNode; 
    }
    
    
    int get(int key) {
        // cout<<"Before get, list is:"<<endl;
        // printLinkedList();
        
        int returnValue = -1;
        // if key doesn't exist
        if(elementsSeen.find(key) == elementsSeen.end())
            returnValue = -1;
        else{
            // if key exists
            DoublyLinkedListNode * tempNode = elementsSeen[key];
            returnValue = tempNode->value;
            deleteNode(key);
            insertNode(key, returnValue);
        }
        // cout<<"getting for key: "<<key<<endl;
        
        // cout<<"After get, list is:"<<endl;
        // printLinkedList();
        return returnValue;
    }
    
    void put(int key, int value) {
        // cout<<"Before put, list is:"<<endl;
        // printLinkedList();
        /*
        3 cases can exist while putting an element
            1. The element doesn't exist in the map
                . if the cache is full, we need to delete the LRU node and then insert the new node
                . if the cache is not full, insert it onto the top of the LRU cache, store it into the map and increment totalElement count
            2. The elemt exists in the map and we have hit capacity
            3. the element exists in the map and we have not hit capacity
        */
        
        // if the element doesn't exist in the map
        if(elementsSeen.find(key) == elementsSeen.end()){
            // if we have hit the cap, need to delete the lru node
            if(totalElements == cap)
                deleteNode(tail->key);
            
            // insert the new node into the map and linked list
            insertNode(key, value);  
        }
        
        // if the element exists in the map
        else{
            deleteNode(key);
            insertNode(key, value);
        }
        
        // cout<<"putting key:"<<key<<" value: "<<value<<endl;
        // cout<<"After put, list is:"<<endl;
        // printLinkedList();
    }
    
    void printLinkedList(){
        DoublyLinkedListNode * tempNode = head;
        while(tempNode){
            cout<<"("<<tempNode->key<<","<<tempNode->value<<") -> ";
            tempNode = tempNode->next;
        }
        cout<<endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */