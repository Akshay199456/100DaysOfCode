/*
Problem statement:

Given a binary tree, connect each node with its level order successor. The last node of each level should point to a null node.


*/

/*
-------------------------    My Approaches:
1. Tree Breadth First Search

    we can apply the tree breadh first search here. we need to keep track of the level
    so that we point the last node of any level to nulklptr

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
  TreeNode *next;

  TreeNode(int x) {
    val = x;
    left = right = next = nullptr;
  }

  // level order traversal using 'next' pointer
  virtual void printLevelOrder() {
    TreeNode *nextLevelRoot = this;
    while (nextLevelRoot != nullptr) {
      TreeNode *current = nextLevelRoot;
      nextLevelRoot = nullptr;
      while (current != nullptr) {
        cout << current->val << " ";
        if (nextLevelRoot == nullptr) {
          if (current->left != nullptr) {
            nextLevelRoot = current->left;
          } else if (current->right != nullptr) {
            nextLevelRoot = current->right;
          }
        }
        current = current->next;
      }
      cout << endl;
    }
  }
};

class ConnectLevelOrderSiblings {
 public:
  static void connectLevelOrder(TreeNode * & root){
    queue<TreeNode *> eq;
    eq.push(root);
    while(!eq.empty()){
      int currSize = eq.size();
      for(int i=0; i< currSize; i++){
        TreeNode * temp = eq.front();
        eq.pop();
        if(temp->left)
          eq.push(temp->left);
        if(temp->right)
          eq.push(temp->right);
        
        if(i+1 == currSize)
          temp->next = nullptr;
        else
          temp->next = eq.front();
      }
    }
  }

  static void connect(TreeNode *root) {
    // TODO: Write your code here
    if(root)
      connectLevelOrder(root);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(6);
  ConnectLevelOrderSiblings::connect(root);
  cout << "Level order traversal using 'next' pointer: " << endl;
  root->printLevelOrder();
}



//  Other Approaches(1)
