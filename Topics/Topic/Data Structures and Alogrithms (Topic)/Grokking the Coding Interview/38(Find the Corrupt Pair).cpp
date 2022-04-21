/*
Problem statement:

e are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array originally contained all the numbers from 1 to ‘n’, but due to a data error, one of the numbers got duplicated which also resulted in one number going missing. Find both these numbers.

Example 1:

Input: [3, 1, 2, 5, 2]
Output: [2, 4]
Explanation: '2' is duplicated and '4' is missing.
Example 2:

Input: [3, 1, 2, 3, 6, 4]
Output: [3, 5]
Explanation: '3' is duplicated and '5' is missing.
*/

/*
-------------------------    My Approaches:
1. Usiung cyclic sort pattern

    We can use the cyclic sort pattern in order to solve this problem. once we sort the 
    vecotr and put the elements inot heir position, the only thing that remains is to get
    the duplicate and the missing element. the duplicate elemnt will be at the missing
    element index so we can grab both that information from there.

    Time complexity: O(n)
    Space complexity: O(1)
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
#include <string>
#include <vector>

class FindCorruptNums {
 public:
  static void sortNumbers(vector<int> & nums){
    int start{0};
    while(start < nums.size()){
      if((start+1 == nums[start]) || (nums[start] == nums[nums[start]-1]))
        ++start;
      else{
        int startIndex{start}, swappedIndex{nums[start]-1};
        int startValue{nums[start]}, swappedValue{nums[swappedIndex]};
        nums[startIndex] = swappedValue;
        nums[swappedIndex] = startValue;
      }
    }
  }

  static vector<int> corruptPair(vector<int> & nums){
    vector<int> result{-1,-1};
    for(int i=0; i< nums.size(); i++){
      if(nums[i] != i+1){
        result[0] = nums[i];
        result[1] = i+1;
      }
    }
    return result;
  }

  static vector<int> findNumbers(vector<int> &nums) {
    // TODO: Write your code here
    sortNumbers(nums);
    return corruptPair(nums);
  }
};




//  Other Approaches(1)
