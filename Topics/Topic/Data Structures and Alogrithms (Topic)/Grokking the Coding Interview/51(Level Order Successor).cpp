/*
Problem statement:

Given a binary tree and a node, find the level order successor of the given node in the tree. The level order successor is the node that appears right after the given node in the level order traversal.


*/

/*
-------------------------    My Approaches:
1. Tree Breadth first Search aporach

    We cna use the breadth first approach to solve this problem. we jsut ened to return the 
    next element in the level.

    Time complexity: O(n)
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes

*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class LevelOrderSuccessor {
 public:
  static TreeNode * getSuccessor(TreeNode * root, int key){
    queue<TreeNode *> eq;
    eq.push(root);
    while(!eq.empty()){
      TreeNode * temp = eq.front();
      eq.pop();
      if(temp->left)
        eq.push(temp->left);
      if(temp->right)
        eq.push(temp->right);

      if(temp->val == key){
        if(eq.empty())
          return nullptr;
        return eq.front();
      }
    }
    return nullptr;
  }

  static TreeNode *findSuccessor(TreeNode *root, int key) {
   // TODO: Write your code here
   if(root)
    return getSuccessor(root, key);
   return nullptr;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  
  TreeNode *result = LevelOrderSuccessor::findSuccessor(root, 4);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
  
  root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  
  result = LevelOrderSuccessor::findSuccessor(root, 9);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
  
  result = LevelOrderSuccessor::findSuccessor(root, 12);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
}



//  Other Approaches(1)
