/*
Problem statement:


*/

/*
-------------------------    My Approaches:
1. Tree Depth First Search

    We can apply the tree depth first search technique here. the only addition here being
    that we store the path as we are going along so that once we hit the leaf node and the sum equal what we are looking for, we store
    it for our final answer.

    Time complexity: O(n^2) since you are passing a copy of a list (for result) in every recursive call
    as you are doing that O(n) times, tyotal time complexity is O(n^2)
    Space complexity: O(n) if space for all results is ignored
    otherwise O(nlogn)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
follows the binary tree path sum, pattern, can follows the same DFS approach. wll be 2
differences:
    1. every time we find a root-to-leadf path, we will store it in a list
    2. we will traverse all paths and will not stop processing after finding  the first 
    path
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

class FindAllTreePaths {
 public:
  static void getAllPaths(TreeNode * root, int sum, vector<vector<int>> & allPaths, vector<int> result){
    sum -= root->val;
    result.push_back(root->val);
    
    if(!root->left && !root->right && !sum)
      allPaths.push_back(result);

    if(root->left)
      getAllPaths(root->left, sum, allPaths, result);

    if(root->right)
      getAllPaths(root->right, sum, allPaths, result);
  }

  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> result;
    // TODO: Write your code here
    if(root)
      getAllPaths(root, sum, allPaths, result);
    return allPaths;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = nullptr;
  int sum = 0;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
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

class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    findPathsRecursive(root, sum, currentPath, allPaths);
    return allPaths;
  }

 private:
  static void findPathsRecursive(TreeNode *currentNode, int sum, vector<int> &currentPath,
                                 vector<vector<int>> &allPaths) {
    if (currentNode == nullptr) {
      return;
    }

    // add the current node to the path
    currentPath.push_back(currentNode->val);

    // if the current node is a leaf and its value is equal to sum, save the current path
    if (currentNode->val == sum && currentNode->left == nullptr && currentNode->right == nullptr) {
      allPaths.push_back(vector<int>(currentPath));
    } else {
      // traverse the left sub-tree
      findPathsRecursive(currentNode->left, sum - currentNode->val, currentPath, allPaths);
      // traverse the right sub-tree
      findPathsRecursive(currentNode->right, sum - currentNode->val, currentPath, allPaths);
    }

    // remove the current node from the path to backtrack,
    // we need to remove the current node while we are going up the recursive call stack.
    currentPath.pop_back();
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
