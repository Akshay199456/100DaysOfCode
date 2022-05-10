/*
Problem statement:

Find the path with the maximum sum in a given binary tree. Write a function that returns the maximum sum.

A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root. The path must contain at least one node.
*/

/*
-------------------------    My Approaches:
1. Tree Depth First Search[Does not work]

    can apply the depth first search pattern here. get the left sum,, right sum and
    caclulate the max sum

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
fololows the binary tree path sum pattern and sahres algorithmic logic with tree diameter. can
follows the same dfs appraoch. only differeence will be to ignore any paths with negative sums.
since we need to find the overall maximum sum, we should ignore any path which has an 
overall negative sum.

my words:
not a whole lot different between my approach and this. in my alrogirthm, i pass in the 
state of left and right sum even if they are negative. that was the wrong thing to do. since if thee
left or right are negative, they are not helping, the best solution would be to ignore them
just like this approach. that way we only pass the root. eitjer way we ae collecting the path
sum as we are going along so that will get updated with the max sum.
*/



//  My approaches(1)
#include <iostream>
#include <climits>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class MaximumPathSum {
 public:
  static int getPathMax(TreeNode * root, int & pathMax){
    if(!root)
      return 0;
    else{
      int leftSum = getPathMax(root->left, pathMax);
      int rightSum = getPathMax(root->right, pathMax);
      pathMax = max(pathMax, leftSum+rightSum+root->val);
      return max(leftSum,rightSum)+ root->val;
    }
  }

  static int findMaximumPathSum(TreeNode *root) {
    // TODO: Write your code here
    int pathMax = INT_MIN;
    if(root)
      getPathMax(root, pathMax);
    return pathMax;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root = new TreeNode(-1);
  root->left = new TreeNode(-3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}



//  Other Approaches(1)
#include <iostream>
#include <limits>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class MaximumPathSum {
 public:
  static int findMaximumPathSum(TreeNode *root) {
    int globalMaximumSum = numeric_limits<int>::min();
    findMaximumPathSumRecursive(root, globalMaximumSum);
    return globalMaximumSum;
  }

 private:
  static int findMaximumPathSumRecursive(TreeNode *currentNode, int &globalMaximumSum) {
    if (currentNode == nullptr) {
      return 0;
    }

    int maxPathSumFromLeft = findMaximumPathSumRecursive(currentNode->left, globalMaximumSum);
    int maxPathSumFromRight = findMaximumPathSumRecursive(currentNode->right, globalMaximumSum);

    // ignore paths with negative sums, since we need to find the maximum sum we should
    // ignore any path which has an overall negative sum.
    maxPathSumFromLeft = max(maxPathSumFromLeft, 0);
    maxPathSumFromRight = max(maxPathSumFromRight, 0);

    // maximum path sum at the current node will be equal to the sum from the left subtree +
    // the sum from right subtree + val of current node
    int localMaximumSum = maxPathSumFromLeft + maxPathSumFromRight + currentNode->val;

    // update the global maximum sum
    globalMaximumSum = max(globalMaximumSum, localMaximumSum);

    // maximum sum of any path from the current node will be equal to the maximum of
    // the sums from left or right subtrees plus the value of the current node
    return max(maxPathSumFromLeft, maxPathSumFromRight) + currentNode->val;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root = new TreeNode(-1);
  root->left = new TreeNode(-3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}


//Other Approaches(2)
#include <iostream>
#include <climits>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class MaximumPathSum {
 public:
  static int getPathMax(TreeNode * root, int & pathMax){
    if(!root)
      return 0;
    else{
      int leftSum = max(0,getPathMax(root->left, pathMax));
      int rightSum = max(0,getPathMax(root->right, pathMax));
      pathMax = max(pathMax, leftSum+rightSum+root->val);
      return max(leftSum,rightSum)+ root->val;
    }
  }

  static int findMaximumPathSum(TreeNode *root) {
    // TODO: Write your code here
    int pathMax = INT_MIN;
    if(root)
      getPathMax(root, pathMax);
    return pathMax;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root = new TreeNode(-1);
  root->left = new TreeNode(-3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}
