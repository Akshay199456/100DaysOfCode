/*
Problem statement:

Given a binary tree, populate an array to represent its level-by-level traversal. You should populate the values of all nodes of each level from left to right in separate sub-arrays.


*/

/*
-------------------------    My Approaches:
1. Tree Breadth First Search

    we can sue the tree breadth first search technique here. since we are lookinf for 
    level-by-level traversal, we can use a queue and go level by level

    Time complexity: O(n) where n is total nodes in tree
    Space complexity: O(n) since array stores n elements and since n/2 is amx nodes
    at any level, will need O9n) space to store them in queue.
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
need to traverse all nodes of each level before moving in to next level, can use the BFS
technique to solve problem
can se queue to efficeintly traverse in bef fashion. here are steps:
    1. start by pushing toot node to queue
    2. keep iterating until quue empty
    3. in each iteration, first count elements in the queue (lets call it levelsize). will
    have these many nodes in the current level
    4. enxt, remove levlesize nodes form queue and push their value in an array to represent current ;evel
    5. after removing each node form thre queu, insert both the children into queue
    6. if queue not empty, repreat step 3 fro next level
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

class LevelOrderTraversal {
 public:
  static void traverseTree(TreeNode * root, vector<vector<int>> & result){
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty()){
      int currSize = nodeQueue.size();
      vector<int> list;
      for(int i=0; i< currSize; i++){
        TreeNode * frontNode = nodeQueue.front();
        nodeQueue.pop();
        list.push_back(frontNode->val);
        if(frontNode->left)
          nodeQueue.push(frontNode->left);
        if(frontNode->right)
          nodeQueue.push(frontNode->right);
      }
      result.push_back(list);
    }
  }

  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    // TODO: Write your code here
    if(root)
      traverseTree(root, result);
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(10);
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
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

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
      int levelSize = queue.size();
      vector<int> currentLevel;
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();
        // add the node to the current level
        currentLevel.push_back(currentNode->val);
        // insert the children of current node in the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
      result.push_back(currentLevel);
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
