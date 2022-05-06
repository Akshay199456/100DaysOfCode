/*
Problem statement:

Given a binary tree where each node can only have a digit (0-9) value, each root-to-leaf path will represent a number. Find the total sum of all the numbers represented by all paths.


*/

/*
-------------------------    My Approaches:
1. Tree Depth Firs Search

    We can use the depth first search technique here. we keep track of the number using a 
    string and when we reach the leaf, we convert that into an int.

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
follows the binary tree path sum pattern/. can follow the same dfs appraoch. the additional
thing we need to do is keep track of the number representing the current path.

how to calculate the path number for a node.. 
*/



//  My approaches(1)
using namespace std;

#include <iostream>
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

class SumOfPathNumbers {
 public:
  static void getSum(TreeNode * root, int & totalPathsSum, string & result){
    result += to_string(root->val);
    if(!root->left && !root->right)
      totalPathsSum += stoi(result);
    
    if(root->left)
      getSum(root->left, totalPathsSum, result);
    if(root->right)
      getSum(root->right, totalPathsSum, result);
    
    result.pop_back();
  }

  static int findSumOfPathNumbers(TreeNode *root) {
    int totalPathsSum = 0;
    string result = "";
    // TODO: Write your code here
    if(root)
      getSum(root, totalPathsSum, result);
    return totalPathsSum;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->right = new TreeNode(5);
  root->right->left = new TreeNode(8);
  root->right->left->right = new TreeNode(9);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>

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

class SumOfPathNumbers {
 public:
  static int findSumOfPathNumbers(TreeNode *root) {
    return findRootToLeafPathNumbers(root, 0);
  }

 private:
  static int findRootToLeafPathNumbers(TreeNode *currentNode, int pathSum) {
    if (currentNode == nullptr) {
      return 0;
    }

    // calculate the path number of the current node
    pathSum = 10 * pathSum + currentNode->val;

    // if the current node is a leaf, return the current path sum.
    if (currentNode->left == nullptr && currentNode->right == nullptr) {
      return pathSum;
    }
    // traverse the left and the right sub-tree
    return findRootToLeafPathNumbers(currentNode->left, pathSum) + 
           findRootToLeafPathNumbers(currentNode->right, pathSum);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}
