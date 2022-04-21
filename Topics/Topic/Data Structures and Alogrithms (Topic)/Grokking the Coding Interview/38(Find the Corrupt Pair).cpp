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
Follows cyclic sort pattern and shares similarities with Find All Duplicate Numbers.
Following similar approach, we place each number at correct index. once done with cyclic
sort, will iteratre through array to find number that is not at the correct index. since
only one number gets corrupted, number at the wrong index is duplicated number and the index itself
represents the missing number.
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
using namespace std;

#include <iostream>
#include <string>
#include <vector>

class FindCorruptNums {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      } else {
        i++;
      }
    }

    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        return vector<int>{nums[i], i + 1};
      }
    }

    return vector<int>{-1, -1};
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 1, 2, 5, 2};
  vector<int> nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;

  v1 = {3, 1, 2, 3, 6, 4};
  nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;
}