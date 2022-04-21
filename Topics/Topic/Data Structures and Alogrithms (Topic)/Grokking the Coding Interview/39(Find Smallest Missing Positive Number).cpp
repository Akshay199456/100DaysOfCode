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
follows cuclic sort pattern and shares similarities with find the missing number with one 
big difference, in this problem, numbers not bound by any range so we can have any number
in the input array

follow same appraoch as dicussed in miussing number to place numbers on their correct
indeices and ignore all numbers that are out of range of array (i.e. all negative numbers and
all numbers greater than length of array). once done with cyclic sort, will iterate array and
that first index that does not have the correct number will be the smallest missing
positive number
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
      if((nums[start] == start+1) || (nums[start] < 1) || (nums[start] > nums.size()))
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
      if((nums[i] != i+1))
        return i+1;
    }
    return nums.size()+1;
  }

  static void printList(vector<int> & nums){
    for(int i=0; i< nums.size(); i++)
      cout<<nums[i]<<" ";
    cout<<endl;
  }

  static int findNumber(vector<int> &nums) {
    // TODO: Write your code here
    sortNumbers(nums);
    printList(nums);
    return findMissingNumber(nums);
  }
};




//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class FirstSmallestMissingPositive {
 public:
  static int findNumber(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      } else {
        i++;
      }
    }

    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return nums.size() + 1;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {-3, 1, 5, 4, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, -2, 0, 1, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, 2, 5, 1};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;
}
