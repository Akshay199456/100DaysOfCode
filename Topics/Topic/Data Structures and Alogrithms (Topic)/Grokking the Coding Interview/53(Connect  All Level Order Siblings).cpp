/*
Problem statement:

Given a binary tree, connect each node with its level order successor. The last node of each level should point to the first node of the next level.



*/

/*
-------------------------    My Approaches:
1. Tree Breadth First Search

    tree breadht first ssearrch tehcnique here. we dont need to know the no of nodes in each level

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
follows boinary tree level order. cam follow bfs approach. only differennce is that whoile traverseing
we will remember (irrespective of level) the previous node to connect it with the ccirrent
node.
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

  // tree traversal using 'next' pointer
  virtual void printTree() {
    TreeNode *current = this;
    cout << "Traversal using 'next' pointer: ";
    while (current != nullptr) {
      cout << current->val << " ";
      current = current->next;
    }
  }
};

class ConnectAllSiblings {
 public:
  static void connectTree(TreeNode * & root){
    queue<TreeNode *> eq;
    eq.push(root);
    while(!eq.empty()){
      TreeNode * temp = eq.front();
      eq.pop();
      if(temp->left)
        eq.push(temp->left);
      if(temp->right)
        eq.push(temp->right);
      
      if(eq.empty())
        temp->next = nullptr;
      else
        temp->next = eq.front();
    }
  }

  static void connect(TreeNode *root) {
   // TODO: Write your code here
   if(root)
    connectTree(root);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(9);

  ConnectAllSiblings::connect(root);
  root->printTree();
}


//  Other Approaches(1)
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

  // tree traversal using 'next' pointer
  virtual void printTree() {
    TreeNode *current = this;
    cout << "Traversal using 'next' pointer: ";
    while (current != nullptr) {
      cout << current->val << " ";
      current = current->next;
    }
  }
};

class ConnectAllSiblings {
 public:
  static void connect(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    TreeNode *currentNode = nullptr, *previousNode = nullptr;
    while (!queue.empty()) {
      currentNode = queue.front();
      queue.pop();
      if (previousNode != nullptr) {
        previousNode->next = currentNode;
      }
      previousNode = currentNode;

      // insert the children of current node in the queue
      if (currentNode->left != nullptr) {
        queue.push(currentNode->left);
      }
      if (currentNode->right != nullptr) {
        queue.push(currentNode->right);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  ConnectAllSiblings::connect(root);
  root->printTree();
}
