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
    Space complexity: O(w) where w is max no of modes in a level
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
