/*
Problem statement:

We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’. The array has only one duplicate but it can be repeated multiple times. Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.

Example 1:

Input: [1, 4, 4, 3, 2]
Output: 4
Example 2:

Input: [2, 1, 3, 3, 5, 4]
Output: 3
Example 3:

Input: [2, 4, 1, 4, 4]
Output: 4

*/

/*
-------------------------    My Approaches:
1. using cycle sort pattern

    we can use the cyclic sort pattern to solve this porblem just like the otehr problems. using cyclic sort, sort hte numbers
    into their place. the duplicates will get into spots where the numbers are missing. as a result, when we go through it
    a second time, we can easily find the duplicate element

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

class FindDuplicate {
 public:
  static void sortNumbers(vector<int> & nums){
    int start{0};
    while(start < nums.size()){
      if((nums[start] == start + 1) || (nums[nums[start]-1] == nums[start]))
        ++start;
      else{
        int startIndex{start}, swappedIndex{nums[start]-1};
        int startValue{nums[startIndex]}, swappedValue{nums[swappedIndex]};
        nums[startIndex] = swappedValue;
        nums[swappedIndex] = startValue;
      }
    }
  }

  static int getDuplicate(vector<int> & nums){
    for(int i=0; i< nums.size(); i++){
      if(nums[i] != i+1)
        return nums[i];
    }
    return -1;
  }

  static int findNumber(vector<int> &nums) {
    // TODO: Write your code here
    sortNumbers(nums);
    return getDuplicate(nums);
  }
};



//  Other Approaches(1)
