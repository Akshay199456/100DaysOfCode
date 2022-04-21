/*
Problem statement:

Given an unsorted array containing numbers, find the smallest missing positive number in it.

Note: Positive numbers start from ‘1’.

Example 1:

Input: [-3, 1, 5, 4, 2]
Output: 3
Explanation: The smallest missing positive number is '3'
Example 2:

Input: [3, -2, 0, 1, 2]
Output: 4
Example 3:

Input: [3, 2, 5, 1]
Output: 4

*/

/*
-------------------------    My Approaches:
1. Using cyclic sort

    We can use the cclic sort in order to sovle this problem. once we sort the numbers into their
    place, we just need to find the first number that is less than 1 in our array. that will
    be our missing number

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
#include <vector>

class FirstSmallestMissingPositive {
 public:
  static void sortNumbers(vector<int> & nums){
    int start{0};
    while(start < nums.size()){
      if((nums[start] == start+1) || (nums[start] < 1))
        ++start;
      else{
        int startIndex{start}, swappedIndex{nums[start]-1};
        int startValue{nums[startIndex]}, swappedValue{nums[swappedIndex]};
        nums[startIndex] = swappedValue;
        nums[swappedIndex] = startValue;
      }
    }
  }

  static int findMissingNumber(vector<int> & nums){
    for(int i=0; i<nums.size(); i++){
      if(nums[i] < 1)
        return i+1;
    }
    return -1;
  }

  static int findNumber(vector<int> &nums) {
    // TODO: Write your code here
    sortNumbers(nums);
    return findMissingNumber(nums);
  }
};



//  Other Approaches(1)
