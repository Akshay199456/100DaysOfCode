/*
Problem statement:

We are given an array containing n objects. Each object, when created, was assigned a unique number from the range 1 to n based on their creation sequence. This means that the object with sequence number 3 was created just before the object with sequence number 4.

Write a function to sort the objects in-place on their creation sequence number in O(n)
O(n)
 and without using any extra space. For simplicity, let’s assume we are passed an integer array containing only the sequence numbers, though each number is actually an object.

Example 1:

Input: [3, 1, 5, 4, 2]
Output: [1, 2, 3, 4, 5]
Example 2:

Input: [2, 6, 4, 3, 1, 5]
Output: [1, 2, 3, 4, 5, 6]
Example 3:

Input: [1, 5, 6, 4, 3, 2]
Output: [1, 2, 3, 4, 5, 6]
*/

/*
-------------------------    My Approaches:
1. Using cyclic sort pattern

    we can use the cyclic sort pattern to solve this problem. since ewe know thae array contains
    numbers form 1 to n and just need to put them into their position, we know werere the final
    position for all those elements should be. 
    so, we start with a pointer scalled start. until the value at start is sorted, we keep swapping values
    between the value at start and the value where it should actually be. in other words, we are
    putting the value that was at start in its place and continue to do so till start itself is
    in its proper place. once it is, we move start forward by 1.

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

class CyclicSort {
 public:
  static void sortNumbers(vector<int> & nums){
    int start{0};
    while(start < nums.size()){
      if(nums[start] != start+1){
        int startValue = nums[start], swappedValue = nums[nums[start]-1];
        int startIndex = start, swappedIndex = nums[start]-1;
        nums[startIndex] = swappedValue;
        nums[swappedIndex] = startValue;
      }
      else
        start += 1;
    }
  }

  static void sort(vector<int> &nums) {
    // TODO: Write your code here    
    if(nums.size())
      sortNumbers(nums);
  }
};




//  Other Approaches(1)
