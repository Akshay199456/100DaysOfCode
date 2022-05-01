/*
Problem statement:

Given a binary tree, populate an array to represent its zigzag level order traversal. You should populate the values of all nodes of the first level from left to right, then right to left for the next level and keep alternating in the same manner for the following levels.



*/

/*
-------------------------    My Approaches:
1. Tree Breadth First Search

    we can use the tree breath first seearch to solve this problem. the only didfernece with pb 47 grok is that we reverse
    the list before we insert it if level is even.

    Time complexity: O(n)
    Space complexity: O(n) is result is consdiered else O(w)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
Follows binary tree level order traversak. can follow bfs approach. only additional step to consider is to alternate level
order traversal which means that for every other level, traverse similar to pb 47 grok

they place elements into a list by creating space for it. if left to right, they insert it from beg to end, else they insert
it from the end to begin.
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

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

class ZigzagTraversal {
 public:
  static void zigzag(TreeNode * root, vector<vector<int>> & result){
    queue<TreeNode *> eq;
    eq.push(root);
    int level = 1;
    while(!eq.empty())
    {
      int currSize = eq.size();
      vector<int> list;
      for(int i=0; i<currSize; i++){
        TreeNode * temp = eq.front();
        eq.pop();
        list.push_back(temp->val);
        if(temp->left)
          eq.push(temp->left);
        if(temp->right)
          eq.push(temp->right);
      }
      if(level % 2 == 0)
        reverse(list.begin(), list.end());
      result.push_back(list);
      level += 1;
    }
  }

  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    // TODO: Write your code here
    if(root)
      zigzag(root, result);
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    bool leftToRight = true;
    while (!queue.empty()) {
      int levelSize = queue.size();
      vector<int> currentLevel(levelSize);
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();

        // add the node to the current level based on the traverse direction
        if (leftToRight) {
          currentLevel[i] = currentNode->val;
        } else {
          currentLevel[levelSize - 1 - i] = currentNode->val;
        }

        // insert the children of current node in the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
      result.push_back(currentLevel);
      // reverse the traversal direction
      leftToRight = !leftToRight;
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
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}
