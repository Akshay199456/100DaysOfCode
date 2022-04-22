/*
Problem statement:

Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.

Example 1:

Input: [3, -1, 4, 5, 5], k=3
Output: [1, 2, 6]
Explanation: The smallest missing positive numbers are 1, 2 and 6.
Example 2:

Input: [2, 3, 4], k=3
Output: [1, 5, 6]
Explanation: The smallest missing positive numbers are 1, 5 and 6.
Example 3:

Input: [-2, -3, 4], k=2
Output: [1, 2]
Explanation: The smallest missing positive numbers are 1 and 2.
*/

/*
-------------------------    My Approaches:
1. Using a set to store elements that occured

    we can use a set to store the elements that occured in the array. we then start 
    from 1 and until k is 0, check if the element has ooccurred. if not, we insert it into
    the result, decremenet k and move forward by 1 else we only move forward by 1.

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
#include <unordered_set>
#include <vector>

class FirstKMissingPositive {
 public:
  static void createSet(vector<int> & nums, unordered_set<int> & elementSet){
    for(int ele: nums)
      elementSet.insert(ele);
  }

  static void getNumbers(unordered_set<int> & elementSet, int k,vector<int> & missingNumbers){
    int start = 1;
    while(k > 0){
      if(elementSet.find(start) == elementSet.end()){
        missingNumbers.push_back(start);
        k -= 1;
      }
      start += 1;
    }
  }

  static vector<int> findNumbers(vector<int> &nums, int k) {
    vector<int> missingNumbers;
    unordered_set<int> elementSet;
    // TODO: Write your code here
    createSet(nums, elementSet);
    getNumbers(elementSet, k, missingNumbers);
    return missingNumbers;
  }
};




//  Other Approaches(1)
