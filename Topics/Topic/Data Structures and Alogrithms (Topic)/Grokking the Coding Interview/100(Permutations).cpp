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
solution follows the subsets pattern and we can follow a smiliar BFS approach. however, ubnlike subsets, every permutation must contain all the numbers.

following a bfs approach, we will consider one number at a time.

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
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
 public:
  static vector<vector<int>> findPermutations(const vector<int>& nums) {
    vector<vector<int>> result;
    queue<vector<int>> permutations;
    permutations.push(vector<int>());
    for (auto currentNumber : nums) {
      // we will take all existing permutations and add the current number to create new
      // permutations
      int n = permutations.size();
      for (int i = 0; i < n; i++) {
        vector<int> oldPermutation = permutations.front();
        permutations.pop();
        // create a new permutation by adding the current number at every position
        for (int j = 0; j <= oldPermutation.size(); j++) {
          vector<int> newPermutation(oldPermutation);
          newPermutation.insert(newPermutation.begin() + j, currentNumber);
          if (newPermutation.size() == nums.size()) {
            result.push_back(newPermutation);
          } else {
            permutations.push(newPermutation);
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}


//Other approaches(2)
using namespace std;

#include <iostream>
#include <vector>

class PermutationsRecursive {
 public:
  static vector<vector<int>> generatePermutations(const vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> currentPermutation;
    generatePermutationsRecursive(nums, 0, currentPermutation, result);
    return result;
  }

 private:
  static void generatePermutationsRecursive(const vector<int> &nums, int index,
                                      vector<int> &currentPermutation, vector<vector<int>> &result) {
    if (index == nums.size()) {
      result.push_back(currentPermutation);
    } else {
      // create a new permutation by adding the current number at every position
      for (int i = 0; i <= currentPermutation.size(); i++) {
        vector<int> newPermutation(currentPermutation);
        newPermutation.insert(newPermutation.begin() + i, nums[index]);
        generatePermutationsRecursive(nums, index + 1, newPermutation, result);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> result = PermutationsRecursive::generatePermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
