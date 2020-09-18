/*
-------------------------Question:

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/*
-------------------------My Approaches:
1. Using preorder traversal

We can use the preorder traversal to serialize the tree. This is because, in our preoreder traversal the order fo the nodes
is root -> left->right. Hence, once we get our root, it would become easy for our deserialize step to decode the string
since it's a binart search tree. As it is a binary search tree, we can take the element as we go along and insert it into
its place and as a result, we are able to serialize and deserialzie effectively.

Serialize:

Time complexity: O(n)
Space complexity: O(1)

Deserialize:

Time complexity: O(nlogn)
Space complexity: O(n)
*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializedTree = "";
        if(root){
            stack<TreeNode *> elements;
            elements.push(root);

            while(!elements.empty()){
                TreeNode * topElement = elements.top();
                elements.pop();
                serializedTree.append(to_string(topElement->val) + "#");

                if(topElement->right)
                    elements.push(topElement->right);
                if(topElement->left)
                    elements.push(topElement->left);

            }
        }
        return serializedTree;
    }

    void getTokens(string data, vector<int> & tokens){
        string token = "";
        for(int i = 0; i <data.size(); i++){
            if(data[i] != '#'){
                string characterString(1, data[i]);
                token.append(characterString);
            }
            else{
                tokens.push_back(stoi(token));
                token = "";
            }
        }
    }
    
    void printTokens(vector<int> tokens){
        for(int i=0; i < tokens.size(); i++)
            cout<<tokens[i]<<" ";
        cout<<endl;
    }
    
    void insertNewElement(int element, TreeNode * curr, TreeNode * parent, int dirn){
        if(!curr){
            if(dirn == -1)
                parent->left = new TreeNode(element);
            else
                parent->right = new TreeNode(element);
        }
        else if(element < curr->val)
            insertNewElement(element, curr->left, curr, -1);
        else
            insertNewElement(element, curr->right, curr, 1);
    }
    
    void insertTokens(vector<int> tokens, TreeNode * & root){
        root = new TreeNode(tokens[0]);
        for(int i = 1; i < tokens.size(); i++)
            insertNewElement(tokens[i], root, root, 0);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode * root = NULL;
        if(data.size()){
            vector<int> tokens;
            getTokens(data, tokens);
            // printTokens(tokens);
            insertTokens(tokens, root);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));