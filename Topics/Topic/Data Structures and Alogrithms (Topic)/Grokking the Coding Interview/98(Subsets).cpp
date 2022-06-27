/*
Problem statement:

Given a set with distinct elements, find all of its distinct subsets.

Example 1:

Input: [1, 3]
Output: [], [1], [3], [1,3]
Example 2:

Input: [1, 5, 3]
Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]
*/

/*
-------------------------    My Approaches:
1. Permutations and Coombinations - DFS

    we can solve this problem by generating all the given permutations and combinations. 
    for every loop, we inser the leemnt, push it into the result, call dfs and then pop it off or r the next element.

    Time complexity: O(n2^n)
    Space complexity: O(n2^n)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class Subsets {
 public:
  static void getSubsets(const vector<int>& nums, vector<vector<int>> & subsets, int startIndex, vector<int> & list){
    for(int i=startIndex; i < nums.size(); i++){
      list.push_back(nums[i]);
      subsets.push_back(list);
      getSubsets(nums, subsets, i+1, list);
      list.pop_back();
    }
  }

  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> list;
    subsets.push_back(list);
    // TODO: Write your code here
    if(nums.size()){
      getSubsets(nums, subsets, 0, list);
    }
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}



//  Other Approaches(1)
