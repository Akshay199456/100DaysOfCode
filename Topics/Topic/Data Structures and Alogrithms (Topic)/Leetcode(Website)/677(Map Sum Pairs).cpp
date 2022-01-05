/*
-------------------------Question:

Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.
 

Example 1:

Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 

Constraints:

1 <= key.length, prefix.length <= 50
key and prefix consist of only lowercase English letters.
1 <= val <= 1000
At most 50 calls will be made to insert and sum.
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:

*/

// MY Approaches(1)
const int alphabetSize = 26;

struct TrieNode{
    TrieNode * children[alphabetSize];
    int value;
};

class MapSum {
public:
    TrieNode * root;
    /** Initialize your data structure here. */
    MapSum() {
        root = getNode();
    }
    
    TrieNode * getNode(){
        TrieNode * currentNode = new TrieNode;
        for(int i=0; i<alphabetSize; i++)
            currentNode->children[i] = NULL;

        currentNode->value = 0;
        
        return currentNode;
    }
    
    void insert(string key, int val) {
        TrieNode * currentNode = root;
        
        for(int i=0; i<key.size(); i++){
            int index = key[i] - 'a';
            if(currentNode->children[index] == NULL)
                currentNode->children[index] = getNode();
            currentNode = currentNode->children[index];
        }
        
        currentNode->value = val;
    }
    
    void recursiveSum(TrieNode * currentNode, int & total){
        if(currentNode->value != 0)
            total += currentNode->value;
        
        for(int i=0; i<alphabetSize; i++){
            if(currentNode->children[i] != NULL)
                recursiveSum(currentNode->children[i], total);
        }
    }
    
    int sum(string prefix) {
        int total = 0;
        TrieNode * currentNode = root;
        
        // check if prefix exists
        for(int i=0; i<prefix.size(); i++){
            int index = prefix[i] - 'a';
            // else return 0;
            if(currentNode->children[index] == NULL)
                return 0;
            else
                currentNode = currentNode->children[index];
        }
        
        // only if it exists, find the sum from words that are found from it.
        recursiveSum(currentNode, total);    
        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */