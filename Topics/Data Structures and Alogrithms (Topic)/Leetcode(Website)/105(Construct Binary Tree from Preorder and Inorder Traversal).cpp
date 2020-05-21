/*
-------------------------Question:

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

/*
-------------------------My Approaches: 
1. [Doesn't work]
*/

/*
-------------------------Other approaches
1/2. Using preorder and inorder to fill tree

[Different between 1 and 2 is that while in 1, we have passed the map from one function to another. In 2, we 
instead make the map a global entity so that we can access it directly instead of creating copies of it
when passing from one method to another].

The key to understand about this problem is that to understand what preorder and inorder means.
Preorder -> Root, Left Subtree, Right Subtree (Root, L, R)
Inorder -> Left Subtree, Root, Right Subtree (L, Root, R)

Once we know what these defintions mean, we can figure out how to solve these problems. If we look at 
preorder, once we hit the root node, we go through the left substree and only then go through the right
subtree. So, if we know the number of element in the left subtree,we can use that knowledge to skip through
the left subtree elements and attach the right subtree to the node. A thing to note here is that we will
be doing this recursively. We know the number of left subtree elements from the inorder array. From the 
inorder array, we know that inorder elements are arranged in L, Root, and R. So, if we know the position
of the root, we can estimate the number of elements on the left and the right using the inorder array.
In particular, the index on the right can be determined using preorderStart + inorderIndex - inorderStart
+1. The reason we add preorderStart is that we must find the element in the preorder array starting from
the current root; we add 1 since we want to skip the left subtree elements and start from the right
subtree. Finally, in order to get the number of elements on the left subtree, we use info from the 
inorder array. We know that the number of elements on the left subtree to be considered can be obtained 
using inorderIndex - inorderStart as that gives the number of elements in the left subtree.

Now that we know how to fill the right subtree, let's understand how to fill the left subtree.  Filling
the left subtree is more easier. If we notice the preorder, elements are arranged in the order root node,
left subtree and right subtree. So, we can directly access the left subtree element from the preorder
element as it is the element in the next index after the root element

We continue to do this in a recursive fashion till all the elements are filled out.


Time complexity: O(n)
Space complexity: O(log n)
*/


// My Approaches(1) - Doesn't work but to show thinking procedure
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void createMapInorder(vector<int> inorder, unordered_map<int,int> & inorderMap){
        for(int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
    }
    
    void insertLeftRight(TreeNode * mainHead, unordered_map<int, int> & inorderMap, unordered_map<int, pair<int, TreeNode *>> & preorderMap, vector<int> inorder){
        int currIndex = inorderMap[mainHead->val];
        if(currIndex - 1 >= 0 && preorderMap.find(inorder[currIndex - 1]) == preorderMap.end()){
            mainHead->left = new TreeNode(inorder[currIndex - 1]);
            preorderMap.emplace(inorder[currIndex - 1], make_pair(-1, mainHead->left));
        }
        
        if((currIndex + 1 < inorderMap.size()) && preorderMap.find(inorder[currIndex + 1]) == preorderMap.end()){
            mainHead->right = new TreeNode(inorder[currIndex + 1]);
            preorderMap.emplace(inorder[currIndex + 1], make_pair(-1, mainHead->right));
        }
    }
    
    void insertTree(TreeNode * & head1, TreeNode * & head2, vector<int> preorder, vector<int> inorder, unordered_map<int, int> & inorderMap, unordered_map<int, pair<int, TreeNode *>> & preorderMap){
        TreeNode * mainHead;
        for(int i = 1; i < preorder.size(); i++){
            auto it = preorderMap.find(preorder[i]);
            if(it == preorderMap.end()){
                mainHead = new TreeNode(preorder[i]);
                if(!head1)
                    head1 = mainHead;
                else
                    head2 = mainHead;
                
                insertLeftRight(mainHead, inorderMap, preorderMap, inorder);
                preorderMap.emplace(mainHead->val, make_pair(1, mainHead));
            }
            
            else if(it != preorderMap.end()){
                if((it->second).first == -1){
                    TreeNode * node = (it->second).second;
                    insertLeftRight(node, inorderMap, preorderMap, inorder);
                    preorderMap[node->val] = make_pair(1, node);
                }
            } 
        }
    }
    /*
    void printTree(TreeNode * temp){
        if()
    }
    */
    
    int findLocation(int element, vector<int> list){
        int index = -1;
        for(int i = 0; i < list.size(); i++){
            if(list[i] == element)
                index = i;
        }
        return index;
    }
    
    void assignDirections(TreeNode * & root, TreeNode * & head1, TreeNode * & head2, vector<int> inorder, vector<int> preorder, unordered_map<int,int> inorderMap){
        if(!head1 && !head2){
            
        }
        
        else if(head1 && head2){
            int index1 = findLocation(head1->val, preorder);
            int index2 = findLocation(head2->val, preorder);
            
            if(index1 < index2){
                root->left = head1;
                root->right = head2;
            }
            
            else{
                root->left = head2;
                root->right = head1;
            }
        }
        
        else{
            int index1 = inorderMap[head1->val];
            int index2 = inorderMap[root->val];
            if(index1 < index2)
                root->left = head1;
            else
                root->right = head1;
        }
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * head1 = NULL, * head2 = NULL, * root = NULL;
        if(preorder.size()){
            unordered_map<int,int> inorderMap;
            unordered_map<int, pair<int, TreeNode *>> preorderMap;
            createMapInorder(inorder, inorderMap);
            
            root = new TreeNode(preorder[0]);
            preorderMap.emplace(root->val, make_pair(1, root));
            insertTree(head1, head2, preorder, inorder, inorderMap, preorderMap);
            assignDirections(root, head1, head2, inorder, preorder, inorderMap);            
        }
        return root;
        
    }
};






// Other Approaches(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    void buildInorderMap(vector<int> inorder, unordered_map<int,int> & inorderMap){
        for(int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
    }
    */
    
    TreeNode * buildTreeFormat(int preorderStart, int inorderStart, int inorderEnd, vector<int> preorder, vector<int> inorder, unordered_map<int,int> inorderMap, TreeNode * & root){
        TreeNode * temp = NULL;
        if(preorderStart > preorder.size() || inorderStart > inorderEnd){
            
        }
        
        else{
            temp = new TreeNode(preorder[preorderStart]);
            if(!root)
                root = temp;
            
            int inorderIndex = inorderMap[temp->val]; 
            temp->left = buildTreeFormat(preorderStart + 1, inorderStart, inorderIndex - 1, preorder, inorder, inorderMap, root);
            temp->right = buildTreeFormat(preorderStart + (inorderIndex - inorderStart) + 1, inorderIndex + 1, inorderEnd, preorder, inorder, inorderMap, root);
        }
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * root = NULL;
        if(preorder.size()){
            unordered_map<int,int> inorderMap;
            // buildInorderMap(inorder, inorderMap);
            
            for(int i = 0; i < inorder.size(); i++)
                inorderMap[inorder[i]] = i;
            
            buildTreeFormat(0,0,inorder.size() - 1, preorder, inorder, inorderMap, root);
        }
        return root;
        
    }
};


// Other Approaches(2)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> inorderMap;
    
    void buildInorderMap(vector<int> inorder){
        for(int i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;
    }
    
    TreeNode * buildTreeFormat(int preorderStart, int inorderStart, int inorderEnd, vector<int> preorder, vector<int> inorder, TreeNode * & root){
        TreeNode * temp = NULL;
        if(preorderStart > preorder.size()-1 || inorderStart > inorderEnd){
        }
        
        else{
            temp = new TreeNode(preorder[preorderStart], NULL, NULL);
            if(!root)
                root = temp;
            
            int inorderIndex = inorderMap[temp->val]; 
            temp->left = buildTreeFormat(preorderStart + 1, inorderStart, inorderIndex - 1, preorder, inorder, root);
            temp->right = buildTreeFormat(preorderStart + (inorderIndex - inorderStart) + 1, inorderIndex + 1, inorderEnd, preorder, inorder,  root);
        }
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * root = NULL;
        if(preorder.size()){
            buildInorderMap(inorder);
            buildTreeFormat(0,0,inorder.size() - 1, preorder, inorder, root);
        }
        return root;
        
    }
};
