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
