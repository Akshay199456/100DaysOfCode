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

    Time complexity: O(n + k)
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1. Basically using My Approaches(1) but recues space by sorting it in place

    This approach is basically like My Approaches(1). the only difference is that in this
    soltuion, they save a bit of space by sorting the  array in place. they then put in
    the elements which are not in place into a set. if by the time they go through the 
    list and k still remains, they then use that information about the elements stored
    in the set to fill in the remaining numbers till k is greater than 0.

    Time complexity: O(n+k)
    Space complexity: O(k)
*/


/*
-------------------------    Notes
his problem follows the Cyclic Sort pattern and shares similarities with Find the 
Smallest Missing Positive Number. The only difference is that, in this problem, we 
need to find the first ‘k’ missing numbers compared to only the first missing number.


We will follow a similar approach as discussed in Find the Smallest Missing Positive 
Number to place the numbers on their correct indices and ignore all numbers that are 
out of the range of the array. Once we are done with the cyclic sort we will iterate t
hrough the array to find indices that do not have the correct numbers.

If we are not able to find ‘k’ missing numbers from the array, we need to add additional
 numbers to the output array. To find these additional numbers we will use the length 
 of the array. For example, if the length of the array is 4, the next missing numbers 
 will be 4, 5, 6 and so on. One tricky aspect is that any of these additional numbers 
 could be part of the array. Remember, while sorting, we ignored all numbers that are 
 greater than or equal to the length of the array. So all indices that have the 
 missing numbers could possibly have these additional numbers. To handle this, we 
 must keep track of all numbers from those indices that have missing numbers. 
 Let’s understand this with an example:

    nums: [2, 1, 3, 6, 5], k =2
After the cyclic sort our array will look like:

    nums: [1, 2, 3, 6, 5]
From the sorted array we can see that the first missing number is ‘4’ (as we have 
‘6’ on the fourth index) but to find the second missing number we need to remember 
that the array does contain ‘6’. Hence, the next missing number is ‘7’.
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
using namespace std;

#include <iostream>
#include <unordered_set>
#include <vector>

class FirstKMissingPositive {
 public:
  static vector<int> findNumbers(vector<int> &nums, int k) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      } else {
        i++;
      }
    }

    vector<int> missingNumbers;
    unordered_set<int> extraNumbers;
    for (i = 0; i < nums.size() && missingNumbers.size() < k; i++) {
      if (nums[i] != i + 1) {
        missingNumbers.push_back(i + 1);
        extraNumbers.insert(nums[i]);
      }
    }

    // add the remaining missing numbers
    for (i = 1; missingNumbers.size() < k; i++) {
      int candidateNumber = i + nums.size();
      // ignore if the array contains the candidate number
      if (extraNumbers.find(candidateNumber) == extraNumbers.end()) {
        missingNumbers.push_back(candidateNumber);
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
  vector<int> v1 = {3, -1, 4, 5, 5};
  vector<int> missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {-2, -3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 2);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;
}

