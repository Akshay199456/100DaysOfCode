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
