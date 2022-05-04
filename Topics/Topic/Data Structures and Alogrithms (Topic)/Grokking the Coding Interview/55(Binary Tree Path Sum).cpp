/*
Problem statement:

Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that the sum of all the node values of that path equals ‘S’.



*/

/*
-------------------------    My Approaches:
1. Tree Depth First Search

    we can use the tree depth first search pattern to solve this problem. i used a recursive
    solution in order to solve the problem. with every recursive solution, you want to make
    sure to take care of the base condition which is the condition at which the recursive
    structure stops. in this problem, that recursive base condition was when we found a leaf node.
    when we found a leaf node, we wanted to checkc if our currSum is equal to the target
    sum we are looking for and show the proper result. 
    the other part of the recursive solution is to pass down state information so the state frp, tje above level is avialble down the ;line for the function
    to use that information to ame the decusions it needs. in our case, as long as we dont find a leaf node we want to keep going down the reursive function
    and when we find the base condition, we check the condition and stop.

    Time complexity: O(n)
    Space complexity: O(h) on average where h is heoght of the tree
                        O(n) in the worst case scraniro when it is a linked list.
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
as trying to search for a root-to-leaf path, cause use the depth first
search (DFS) technique to solve this problem.
to recursivley traverse a binary tree in a DFS fashion, we can
start from the root and at every step, amke two recusirve calls one for the 
left and one for the right child.


*/



//  My approaches(1)
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

class TreePathSum {
 public:
  static bool isPathAvailable(TreeNode * root, int sum, int currSum){
    // base case
    bool result = false;
    currSum += root->val;

    if(!root->left && !root->right){
      if(currSum == sum)
        return true;
      return false;
    }

    if(root->left)
      result = result || isPathAvailable(root->left, sum, currSum);
    if(root->right)
      result = result || isPathAvailable(root->right, sum, currSum);
    
    return result;
  }

  static bool hasPath(TreeNode *root, int sum) {
    // TODO: Write your code here
    int currSum = 0;
    if(root)
      return isPathAvailable(root, sum, currSum);
    return false;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(5);
  cout << "Tree has path: " << TreePathSum::hasPath(root, 3) << endl;

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

class TreePathSum {
 public:
  static bool hasPath(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }

    // if the current node is a leaf and its value is equal to the sum, we've found a path
    if (root->val == sum && root->left == nullptr && root->right == nullptr) {
      return true;
    }

    // recursively call to traverse the left and right sub-tree
    // return true if any of the two recursive call return true
    return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << TreePathSum::hasPath(root, 23) << endl;
  cout << "Tree has path: " << TreePathSum::hasPath(root, 16) << endl;
}
