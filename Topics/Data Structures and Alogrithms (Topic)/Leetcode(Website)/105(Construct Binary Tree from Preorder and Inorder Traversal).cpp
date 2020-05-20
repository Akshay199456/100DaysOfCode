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

*/

/*
-------------------------Other approaches

*/



// My Approaches(1) - Doesn't pass all test cases
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
