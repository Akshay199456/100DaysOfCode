/*
-------------------------Question:

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

*/

/*
-------------------------My Approaches:
1. Using a vector to store the nodes

We can use a vector to store the nodes at each level. By using DFS, the nodes are inserted into the vector
from left to right. Once we have stored them into the vector, the remainging step is to connect the nodes
at each level by attaching the next pointer of one node to the next


Time complexity: O(n)
Space complexity: O(n)


2. Linking right nodes to left nodes for same level

If you think about it, you don't need to store the nodes at each level into a vector to link them together.
At the end, you just need to link nodes which are derived from the same parent as well as link the right node
with the left node of it;s immediate cousin if it has one.

Time complexity: O(n)
Space complexity: O(log n)


3. Iterative approach to My approaches(2)

We can implement My Approaches(2) iteratively as well. In this case, we can keep moving from left to right in
the same level using the next pointers which we established in the previous step either between nodes with 
the same parent or with nodes whose parents are immeditate cousins. We keep moving from left to right on the
same levelt to  establish the connections for the next stage. We continue this till we hit the leaf nodes 
cause once we hit the leaf nodes, we have already established all the connections since the connections
in the current level had been implemented in the previous level.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void generateCollection(Node * root, vector<vector<Node *>> & elementCollection, int level){
        if(root){
            if(level >= elementCollection.size()){
                vector<Node *> row;
                row.push_back(root);
                elementCollection.push_back(row);
            }
            
            else
                elementCollection[level].push_back(root);
            
            generateCollection(root->left, elementCollection, level + 1);
            generateCollection(root->right, elementCollection, level + 1);
        }
    }
    
    void linkNodes(vector<vector<Node *>> & elementCollection){
        for(int i = 0; i < elementCollection.size(); i++){
            for(int j = 0 ; j < elementCollection[i].size() - 1; j++){
                elementCollection[i][j]->next = elementCollection[i][j+1];
            }
        }
    }
    
    
    Node* connect(Node* root) {
        if(root){
            vector<vector<Node *>> elementCollection;
            generateCollection(root, elementCollection, 0);
            linkNodes(elementCollection);
        }
        return root;
    }
};


// My Approaches(2)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void linkNodes(Node * root){
        if(!(root->left) && !(root->right)){
            
        }
        else{
            root->left->next = root->right;
            if(root->next)
                root->right->next = root->next->left;
            linkNodes(root->left);
            linkNodes(root->right);
        }
    }
    
    Node* connect(Node* root) {
        if(!root || !(root->left)){
            
        }
        else
            linkNodes(root);
        return root;
    }
};


// My Approaches(3)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void linkNodes(Node * root){
        Node * levelStart = root;
        while(levelStart->left){
            root = levelStart;
            while(root){
                root->left->next = root->right;
                if(root->next)
                    root->right->next = root->next->left;
                root = root->next;
            }
            levelStart = levelStart->left;
        }
    }
    
    Node* connect(Node* root) {
        if(!root){
            
        }
        else
            linkNodes(root);
        return root;
    }
};