/*
Problem statement:

We are given an unsorted array containing numbers taken from the range 1 to ‘n’. The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.

Example 1:

Input: [2, 3, 1, 8, 2, 3, 5, 1]
Output: 4, 6, 7
Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.
Example 2:

Input: [2, 4, 1, 2]
Output: 3
Example 3:

Input: [2, 3, 2, 1]
Output: 4
*/

/*
-------------------------    My Approaches:
1. Using the cyclic sort method

    we cna use the cyclic sort method in order to solve this problem. we first sort the list by using cucle sort. the way
    we do that is by putting each element into its place. there will be a few duplicates in the problem. the way we can 
    cehck for that is by looking at the position where this element is originally supposed to be at. if that posisiton is 
    alreayd filled with the right number, we then know that this number sis a duplicate and we can just move forward. that
    way, all the duplicates eventually make t intot he spots where thre are missing numbers hwil ethe rest of the numbers are sorted.


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
follows cyclic sort pattern and shares similarities with find th emissing number with one difference. there canbe many
duplicates.
will follow similar approach as pb 34 grok to place numbers into correct indices. once done with cyclic sort, will iterate array
ti find indices with missing correct numbers.
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class AllMissingNumbers {
 public:
  static void sortNumbers(vector<int> & nums){
    int start{0};
    while(start < nums.size()){
      if((start + 1 == nums[start]) || (nums[nums[start]-1] == nums[start]))
        ++start;
      else{
          int startValue = nums[start], swappedValue = nums[nums[start]-1];
          int startIndex = start, swappedIndex = nums[start]-1;
          nums[startIndex] = swappedValue;
          nums[swappedIndex] = startValue;
      }
    }
  }

  static void getMissingNumbers(vector<int> & nums, vector<int> & missingNumbers){
    for(int i=0; i< nums.size(); i++){
      if(nums[i] != i+1)
        missingNumbers.push_back(i+1);
    }
  }

  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> missingNumbers;
    // TODO: Write your code here
    sortNumbers(nums);
    getMissingNumbers(nums, missingNumbers);
    return missingNumbers;
  }
};



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class AllMissingNumbers {
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

    vector<int> missingNumbers;
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        missingNumbers.push_back(i + 1);
      }
    }

    return missingNumbers;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {2, 3, 1, 8, 2, 3, 5, 1};
  vector<int> missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 4, 1, 2};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 3, 2, 1};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;
}
