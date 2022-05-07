/*
Problem statement:

Given a binary tree, find the length of its diameter. The diameter of a tree is the number of nodes on the longest path between any two leaf nodes. The diameter of a tree may or may not pass through the root.

Note: You can always assume that there are at least two leaf nodes in the given tree.
*/

/*
-------------------------    My Approaches:
1. Tree Depth First Search

    we cna apply the tree depth first search technique here. what we do for each componenbt
    is that if it s a null node we return 0. since we are looking o find the diameter of the
    tree, that means we need to know at each node what is the maximum distance between
    two leaves. we know that there is two leaves when both left and right are non-zero, else one of them is zero. as a result
    that is why we only calcualte the maximum depth when both are non-zero as that is the
    actual answer we are looking for and we can get that answer by basically adding
    left+right+1(for the current node).
    what we reutn back to the previous level is the max no of nodes from that node to
    the leaf and so when both left and right are non-zero, we know tha max no of nodes
    from both the left leaf and the right leaf and that is why we caluclate the max
    at this level  


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
follows boinary tree path sym pattern. can follow the same DFS approach, there will be a few differences:
    1. at tevery step, we need to find te height of both children of the current node. for
    this we will make two recursive calls similar to dfs
    2. the height of the current node will be equal to the max of the heights of its left
    or right children + 1 for the current node
    3. the tree diameter at the current node will be equal to the height of the left child
    plus the right child plus 1 for the current node: diameter = leftTreeHeight + rightTreeHeight + 1.
    to find the overall tree diameter, we will use a class level variable. this varirable will
    store the diameter of all the nodes visited so far, hence eventually, it will have the final
    tree diameter.
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

class TreeDiameter {
 public:
  static int getTreeDiameter(TreeNode * root, int & treeDiameter){
    if(!root)
      return 0;
    else{
      int left = getTreeDiameter(root->left, treeDiameter);
      int right = getTreeDiameter(root->right, treeDiameter);
      if(left && right)
        treeDiameter = max(treeDiameter, left+right+1);
      return max(left, right)+1;
    }
  }

  static int findDiameter(TreeNode *root) {
    int treeDiameter = 0;
    // TODO: Write your code here
    getTreeDiameter(root, treeDiameter);
    return treeDiameter;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;

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

class TreeDiameter {
 public:
  static int findDiameter(TreeNode *root) {
    int treeDiameter = 0;
    calculateHeight(root, treeDiameter);
    return treeDiameter;
  }

 private:
  static int calculateHeight(TreeNode *currentNode, int &treeDiameter) {
    if (currentNode == nullptr) {
      return 0;
    }

    int leftTreeHeight = calculateHeight(currentNode->left, treeDiameter);
    int rightTreeHeight = calculateHeight(currentNode->right, treeDiameter);

    // if the current node doesn't have a left or right subtree, we can't have
    // a path passing through it, since we need a leaf node on each side
    if (leftTreeHeight != 0 && rightTreeHeight != 0) {
      // diameter at the current node will be equal to the height of left subtree +
      // the height of right sub-trees + '1' for the current node
      int diameter = leftTreeHeight + rightTreeHeight + 1;

      // update the global tree diameter
      treeDiameter = max(treeDiameter, diameter);
    }

    // height of the current node will be equal to the maximum of the heights of
    // left or right subtrees plus '1' for the current node
    return max(leftTreeHeight, rightTreeHeight) + 1;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
  root->left->left = nullptr;
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->left->right->left = new TreeNode(10);
  root->right->right->left->left = new TreeNode(11);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
}
