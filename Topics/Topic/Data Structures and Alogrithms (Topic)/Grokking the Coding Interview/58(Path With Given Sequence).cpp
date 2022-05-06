/*
Problem statement:

Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.


*/

/*
-------------------------    My Approaches:
1. Tree Depth First Pattern

    Can use the tree depth first pattern here. we use index to understand where we are 
    in the sequencfe and use that information

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
follows the binary trree oath sum pattern. can follow the same dfs approach, track the element
of the given sequence that we should match with the current node. also,m we can return false
as soon as we find amismatch between sequence and node value.
*/



//  My approaches(1)
#include <iostream>
#include <vector>

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

class PathWithGivenSequence {
 public:
  static bool checkPathExists(TreeNode *root, const vector<int> &sequence, int index){
    bool result = false;
    if(index >= sequence.size() || sequence[index] != root->val)
      return false;
    else if(!root->left && !root->right){
      if(index == sequence.size()-1)
        return true;
      return false;
    }
    else{
      if(root->left)
        result = result || checkPathExists(root->left, sequence, index+1);
      if(root->right)
        result = result || checkPathExists(root->right, sequence, index+1);
    }
    return result;
  }

  static bool findPath(TreeNode *root, const vector<int> &sequence) {
    // TODO: Write your code here
    if(root)
      return checkPathExists(root, sequence, 0);
    return false;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(5);

  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1,5,6})
       << endl;
}




//  Other Approaches(1)
#include <iostream>
#include <vector>

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

class PathWithGivenSequence {
 public:
  static bool findPath(TreeNode *root, const vector<int> &sequence) {
    if (root == nullptr) {
      return sequence.empty();
    }

    return findPathRecursive(root, sequence, 0);
  }

 private:
  static bool findPathRecursive(TreeNode *currentNode, const vector<int> &sequence,
                                int sequenceIndex) {
    if (currentNode == nullptr) {
      return false;
    }

    if (sequenceIndex >= sequence.size() || currentNode->val != sequence[sequenceIndex]) {
      return false;
    }

    // if the current node is a leaf, add it is the end of the sequence, we have found a path!
    if (currentNode->left == nullptr && currentNode->right == nullptr &&
        sequenceIndex == sequence.size() - 1) {
      return true;
    }

    // recursively call to traverse the left and right sub-tree
    // return true if any of the two recursive call return true
    return findPathRecursive(currentNode->left, sequence, sequenceIndex + 1) ||
           findPathRecursive(currentNode->right, sequence, sequenceIndex + 1);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7})
       << endl;
  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6})
       << endl;
}
