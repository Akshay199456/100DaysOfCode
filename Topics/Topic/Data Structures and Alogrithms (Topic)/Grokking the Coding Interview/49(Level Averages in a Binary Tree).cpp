/*
Problem statement:

Given a binary tree, populate an array to represent the averages of all of its levels.

*/

/*
-------------------------    My Approaches:
1. Tree Breadth First search

    we can use the tree breadth first search to solve this problem. we just calculate avg over every level as we are going
    along.

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

class LevelAverage {
 public:
  static void calculateAverage(TreeNode * root, vector<double> & result){
    queue<TreeNode *> eq;
    eq.push(root);
    while(!eq.empty()){
      int currSize = eq.size();
      int count{0};
      double sum{0};
      for(int i=0; i< currSize; i++){
        TreeNode * temp = eq.front();
        eq.pop();
        sum += temp->val;
        count += 1;

        if(temp->left)
          eq.push(temp->left);
        if(temp->right)
          eq.push(temp->right);
      }
      result.push_back(((double) sum)/count);
    }
  }

  static vector<double> findLevelAverages(TreeNode *root) {
    vector<double> result;
    // TODO: Write your code here
    if(root)
      calculateAverage(root, result);
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(3);
  vector<double> result = LevelAverage::findLevelAverages(root);
  cout << "Level averages are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}



//  Other Approaches(1)
