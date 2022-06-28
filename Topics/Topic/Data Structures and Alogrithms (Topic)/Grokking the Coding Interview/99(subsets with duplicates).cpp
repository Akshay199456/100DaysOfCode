/*
Problem statement:

Given a set of numbers that might contain duplicates, find all of its distinct subsets.

Example 1:

Input: [1, 3, 3]
Output: [], [1], [3], [1,3], [3,3], [1,3,3]
Example 2:

Input: [1, 5, 3, 3]
Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3], [3,3], [1,3,3], [3,3,5], [1,5,3,3] 
*/

/*
-------------------------    My Approaches:
1. use map and custom hash to store each vector [not coded
2. go through all n to see if it matches with any exisitng solution [not coded]

now we came up with 2 approaches to solve this problem neither of which we have coded since they both are not using the subset technqiue we learnt.
as a result, we can use any of those two approaches to solve the problem.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
problem follows subsets pattern can ca follow a similar BFS approach. the only additional thing we need to do is handle duplicates. since the given set can have duplicate numbers, if we follow the same appraoch
diccussed in subsets problem, we will end up with duplicate subsets which is not acceptable. to handle this, we will do two extra things:

1. sort all numbers of the given set. thois will ensure that all diplicate numbers are next to each other.
follwo the same BFS approach but whenever we are about to process a duplicate (io.e when the current and previous numbers are the same), instead of adding the current nummber(which is a duplicate) to al the exisitng subsets, only add it ti
the subsets which were created in the previous step.

    Time complexity: O()
    Space complexity: O()


ADditional notes:

the part i missed was sorting. if you look through my notes, I had though of sorting the arrya. however, i didn't process with it
since i thought by sorting, we would loose order and that would affect our result we were interested in. hpwever, since we were intersted in dicstinct subsets,
any ordering of the elements that gives to the same result is a duplicate. so, if we just asorted the elements and had used the logic after that, we would have been able to solve the problem.
in order words, [3,5,5] is the same as [5,3,3] and [5,3,5]. and since we are intersted in subsets/combinations, ordering does not matter so even if were to sort, we couild get a valid solution. that is omething i need to rememebr going forward.

now i know that if we are interested in dicstinct subsets, we can sue the sort without worry about hte result as we will be capturing one of the results and that's all we are interested in

*/



//  My approaches(1)



//  Other Approaches(1)
using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // sort the numbers to handle duplicates
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>());
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i < nums.size(); i++) {
      startIndex = 0;
      // if current and the previous elements are same, create new subsets only from the subsets
      // added in the previous step
      if (i > 0 && nums[i] == nums[i - 1]) {
        startIndex = endIndex + 1;
      }
      endIndex = subsets.size() - 1;
      for (int j = startIndex; j <= endIndex; j++) {
        // create a new subset from the existing subset and add the current element to it
        vector<int> set(subsets[j]);
        set.push_back(nums[i]);
        subsets.push_back(set);
      }
    }
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
