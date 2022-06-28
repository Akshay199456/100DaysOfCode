/*
Problem statement:

Given a set of distinct numbers, find all of its permutations.

Permutation is defined as the re-arranging of the elements of the set. For example, {1, 2, 3} has the following six permutations:

{1, 2, 3}
{1, 3, 2}
{2, 1, 3}
{2, 3, 1}
{3, 1, 2}
{3, 2, 1}
If a set has ‘n’ distinct elements it will have n!
n!
 permutations.

Example 1:

Input: [1,3,5]
Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]
*/

/*
-------------------------    My Approaches:
1. DFS + backtracking

    we can use dfs + backtracking approach to solve this problem. the only difference between this problem and
    pb 98 grok is that in permutations we want o keep a check if we have inserted an elment or not. if we have, we skip it. else, we insert
    it into the list

    Time complexity: O(n*n!)
    Space complexity: O(n!)
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
#include <queue>
#include <vector>
#include <algorithm>

class Permutations {
 public:
  static void getPermutations(const vector<int>& nums, vector<vector<int>> & result, vector<int> & list){
    if(list.size() == nums.size()){
      result.push_back(list);
      return ;
    }
    else{
      for(int i=0; i< nums.size(); i++){
        if(!count(list.begin(), list.end(), nums[i])){
          list.push_back(nums[i]);
          getPermutations(nums, result, list);
          list.pop_back();
        }
      }
    }
  }

  static vector<vector<int>> findPermutations(const vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> list;
    // TODO: Write your code here
    if(nums.size())
      getPermutations(nums, result,list);
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Permutations::findPermutations(vector<int>{});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}



//  Other Approaches(1)
