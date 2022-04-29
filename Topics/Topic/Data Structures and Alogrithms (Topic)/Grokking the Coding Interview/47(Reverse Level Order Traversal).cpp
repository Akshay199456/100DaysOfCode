/*
Problem statement:

Given a binary tree, populate an array to represent its level-by-level traversal in reverse order, i.e., the lowest level comes first. You should populate the values of all nodes in each level from left to right in separate sub-arrays.

*/

/*
-------------------------    My Approaches:
1.  Tree Bredath first search

    We can use the tree breadth first search similar to pb 46 grok. the only difference is
    that we use the api of deque(double ended queue) to insert it into the list in a different
    order

    Time complexity: O(n) where n is number of nodes in the tree
    Space complexity: O(n) if list is considered else O(w)
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

#include <deque>
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

class ReverseLevelOrderTraversal {
 public:
  static void traverseTree(TreeNode * root,deque<vector<int>> & result){
    queue<TreeNode *> eq;
    eq.push(root);
    while(!eq.empty()){
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
      result.push_front(list);
    }
  } 

  static deque<vector<int>> traverse(TreeNode *root) {
    deque<vector<int>> result = deque<vector<int>>();
    // TODO: Write your code here
    if(root)
      traverseTree(root, result);
    return result;
  }
};
int main(int argc, char *argv[]) {
  TreeNode *root = nullptr;
  auto result = ReverseLevelOrderTraversal::traverse(root);

  cout << "Reverse level order traversal: ";
  for (auto que : result) {
    for (auto num : que) {
      cout << num << " ";
    }
    cout << endl;
  }
}




//  Other Approaches(1)
