/*
Problem statement:


*/

/*
-------------------------    My Approaches:
1. Tree Depth First Search

    We can apply the tree depth first search technique here. the only addition here being
    that we store the path as we are going along so that once we hit the leaf node and the sum equal what we are looking for, we store
    it for our final answer.

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
