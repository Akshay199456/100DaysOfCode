/*
Problem statement:

Find the minimum depth of a binary tree. The minimum depth is the number of nodes along the shortest path from the root node to the nearest leaf node.
*/

/*
-------------------------    My Approaches:
1. Tree Breadth Frist Search technique

    we can apply the tree breath first approach here. the only trhing isat the end of each level, we have a tracker on the level we are at and that icnreases as the depth increasses. so, wen we reach at a leaf node (with no left or right
    node), then we return the depth imeediately as we have been tracking

    The time dns space complexity is O(n) as in the worst case scenariop we have to go throuygh teh whole list a=or store at least n/2 nodes inn the queue which gives the constaint time and space.

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
follows the binary tree level order traversal pattern. can follow the same approach as BFS. inly difference is that we are keeping trakc of the depth of the tree. as we ffind the first leaf ndoe
that level will reperesent the minimum depth of the tree.
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

class MinimumBinaryTreeDepth {
 public:
  static int getMinimumDepth(TreeNode * root){
    int minDepth = 1;
    queue<TreeNode *> eq;
    eq.push(root);
    while(!eq.empty()){
      int currSize = eq.size();
      for(int i=0; i < currSize; i++){
        TreeNode * temp = eq.front();
        eq.pop();
        if(!temp->left && !temp->right)
          return minDepth;
        
        if(temp->left)
          eq.push(temp->left);
        if(temp->right)
          eq.push(temp->right);
      }
      minDepth += 1;
    }
    return -1;
  }

  static int findDepth(TreeNode *root) {
    int minimumTreeDepth = 0;
    // TODO: Write your code here
    if(root)
      minimumTreeDepth= getMinimumDepth(root);
    return minimumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->left->left = new TreeNode(6);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
  // root->left->left = new TreeNode(9);
  // root->right->left->left = new TreeNode(11);
  // cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}



//  Other Approaches(1)
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

class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    int minimumTreeDepth = 0;
    while (!queue.empty()) {
      minimumTreeDepth++;
      int levelSize = queue.size();
      for (int i = 0; i < levelSize; i++) {
        TreeNode *currentNode = queue.front();
        queue.pop();

        // check if this is a leaf node
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
          return minimumTreeDepth;
        }

        // insert the children of current node in the queue
        if (currentNode->left != nullptr) {
          queue.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
          queue.push(currentNode->right);
        }
      }
    }
    return minimumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}
