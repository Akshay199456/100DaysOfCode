/*
Problem statement:

Given a binary tree, return an array containing nodes in its right view. The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.


*/

/*
-------------------------    My Approaches:
1. Tree Breadth First Search

    Can apply the breadth first search technique here. since we want to get the nodes
    that can be looked from the right, we want the nodes that are at the end of the level
    as these are the nodes that can be viewed from the roght. so we push each node at the 
    end of its level into the resul;t

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

class RightViewTree {
 public:
  static void getRightView(TreeNode * root, vector<TreeNode *> & result){
    queue<TreeNode *> eq;
    eq.push(root);
    while(!eq.empty()){
      int currSize = eq.size();
      for(int i=0 ; i< currSize; i++){
        TreeNode * temp = eq.front();
        eq.pop();
        if(temp->left)
          eq.push(temp->left);
        if(temp->right)
          eq.push(temp->right);
        
        if(i+1 == currSize)
          result.push_back(temp);
      }
    }
  }

  static vector<TreeNode *> traverse(TreeNode *root) {
    vector<TreeNode *> result;
    // TODO: Write your code here
    if(root)
      getRightView(root, result);
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  vector<TreeNode *> result = RightViewTree::traverse(root);
  for (auto node : result) {
    cout << node->val << " ";
  }
}



//  Other Approaches(1)
