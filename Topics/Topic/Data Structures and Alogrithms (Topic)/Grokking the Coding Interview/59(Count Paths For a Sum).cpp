/*
Problem statement:

Given a binary tree and a number ‘S’, find all paths in the tree such that the sum of all the node values of each path equals ‘S’. Please note that the paths can start or end at any node but all paths must follow direction from parent to child (top to bottom).
*/

/*
-------------------------    My Approaches:
1. 

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1. Tree Deopth First Search

    we can apply tree depth first search pattern to solve this problem. to find the total
    count of paths with the sum S, there are a couple of ways we can break this down
    1. we either find all the paths that start at at the current node
    2. we either find all the paths that end at the current node

    the wya we do this is pushing each node to a list and finding the sum upto that node
    either from the beginigng or from the end. this way we get the sum either starting from a point
    or ending froma  point. when we do this for every other node out ther, we basically find all the 
    paths that equal to the sum. in this way, we cover all the paths.

    Time complexity: O(n^2)
    Space complexity: O(n)
*/


/*
-------------------------    Notes
follows binary tree path sum pattern. can follow the same DFS approach. but 4 major differences:
  1. will keep track of the current path ina  list which will be passed to every recursive call
  2. whenever we traceetrse a node, we will do two things
    1. add the current node to the current path
    2. as we added a new node to the current path, we should find the sum of all sub-paths ending at
    the current node. if the sum of any sub-path is equal to 'S' we will increment our path count
  3. we will travrese all paths and will not s top processing after finding the first path
  4. remove the current node from the current path before returning from the function.
  this is needed to backtrack while we are going up the recursive call stack to process other paths.
*/



//  My approaches(1)



//  Other Approaches(1)
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

class CountAllPathSum {
 public:
  static int countPathsRecursive(TreeNode * root, int S, vector<int> & list){
    if(!root)
      return 0;
    
    list.push_back(root->val);
    int pathSum{0}, pathCount{0};

    // get total no of paths that end with the current node and satisfy condition
    for(int i=list.size()-1; i>=0; i--){
      pathSum += list[i];
      if(pathSum == S)
        pathCount += 1;
    }

    // get no of path on left and right
    pathCount += countPathsRecursive(root->left, S, list);
    pathCount += countPathsRecursive(root->right, S, list);
    list.pop_back();

    return pathCount;
  }

  static int countPaths(TreeNode *root, int S) {
    // TODO: Write your code here
    vector<int> list;
    return countPathsRecursive(root, S, list);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(8);
  root->right->right = new TreeNode(10);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 30) << endl;
}


//Other Approaches(2)
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

class CountAllPathSum {
 public:
  static int countPaths(TreeNode *root, int S) {
    vector<int> currentPath;
    return countPathsRecursive(root, S, currentPath);
  }

 private:
  static int countPathsRecursive(TreeNode *currentNode, int S, vector<int> &currentPath) {
    if (currentNode == nullptr) {
      return 0;
    }

    // add the current node to the path
    currentPath.push_back(currentNode->val);
    int pathCount = 0, pathSum = 0;
    // find the sums of all sub-paths in the current path list
    for (vector<int>::reverse_iterator itr = currentPath.rbegin(); itr != currentPath.rend();
         ++itr) {
      pathSum += *itr;
      // if the sum of any sub-path is equal to 'S' we increment our path count.
      if (pathSum == S) {
        pathCount++;
      }
    }

    // traverse the left sub-tree
    pathCount += countPathsRecursive(currentNode->left, S, currentPath);
    // traverse the right sub-tree
    pathCount += countPathsRecursive(currentNode->right, S, currentPath);

    // remove the current node from the path to backtrack,
    // we need to remove the current node while we are going up the recursive call stack.
    currentPath.pop_back();

    return pathCount;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 19) << endl;
}
