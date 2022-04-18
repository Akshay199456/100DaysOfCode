/*
Problem statement:

We are given an unsorted array containing n numbers taken from the range 1 to n. The array has some numbers appearing twice, find all these duplicate numbers using constant space.

Example 1:

Input: [3, 4, 4, 5, 5]
Output: [4, 5]
Example 2:

Input: [5, 4, 7, 2, 3, 5, 3]
Output: [3, 5]

*/

/*
-------------------------    My Approaches:
1. using cyclic sort approach

    we can use the cyclic sort approach to solve this problem. we use the cyclic sort
    approach to put the numbers in its place. while doing this, if we ever come across a number
    that we are trying to insert into its place but its place already has a number with
    the same value, we know we have encountered a duplicate so we add it to our results.

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
follows cyclci sort pattern. will palce each number at its correct index. after that, will
iteratre through array to find all numbers that are not at occrect indiceds. these numbers are duplicate
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class FindAllDuplicate {
 public:
  static void getDuplicateNumbers(vector<int> & nums, vector<int> & duplicateNumbers){
    int start = 0;
    while(start < nums.size()){
      if(start + 1 == nums[start])
        ++start;
      else if(nums[start] == nums[nums[start]-1]){
        duplicateNumbers.push_back(nums[start]);
        ++start;
      }
      else{
        int startIndex{start}, swappedIndex{nums[start]-1};
        int startValue{nums[startIndex]}, swappedValue{nums[swappedIndex]};
        nums[startIndex] = swappedValue;
        nums[swappedIndex] = startValue;
      }
    }
  }

  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> duplicateNumbers;
    // TODO: Write your code here
    getDuplicateNumbers(nums, duplicateNumbers);
    return duplicateNumbers;
  }
};




//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class FindAllDuplicate {
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

    vector<int> duplicateNumbers;
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        duplicateNumbers.push_back(nums[i]);
      }
    }

    return duplicateNumbers;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 4, 4, 5, 5};
  vector<int> duplicates = FindAllDuplicate::findNumbers(v1);
  cout << "Duplicates are: ";
  for (auto num : duplicates) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {5, 4, 7, 2, 3, 5, 3};
  duplicates = FindAllDuplicate::findNumbers(v1);
  cout << "Duplicates are: ";
  for (auto num : duplicates) {
    cout << num << " ";
  }
  cout << endl;
}
