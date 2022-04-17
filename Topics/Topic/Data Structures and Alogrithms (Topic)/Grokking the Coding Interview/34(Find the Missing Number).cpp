/*
Problem statement:

We are given an array containing n distinct numbers taken from the range 0 to n. Since the array has only n numbers out of the total n+1 numbers, find the missing number.

Example 1:

Input: [4, 0, 3, 1]
Output: 2
Example 2:

Input: [8, 3, 5, 2, 4, 6, 0, 1]
Output: 7

*/

/*
-------------------------    My Approaches:
1. using bit exor operation

    we can use the bit exor operation to ifn dht eolution ot the problem, by exoring every number with the index, at the very end the missing 
    number will be w=the only number that will remaing since every index will cancel off with its number.

    Time complexity: O(n)
    Space complexity: O(1)


2. using cyclic sort method

    basically, in this method, we apply the cyclic sort method which is to sort the number in its place
    by ,making sure the number aligns with its index in one form or another just like grok pb
    33. the only difference ehre  is that when we enocunter the number eqal to the length of the array we just want to skip
    it so that every other number gets sorted into its place. this way, if the number equal tot he length
    of the array ois present, it will automatically get pushed to the position where the number
    is not available and that will be ryour resu;t. if we dont have the numebr equal to the
    length of the array, then the length of the array is the missing number.

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
follows hte cyclic sort pattern.  since input aray contains unique numbers from range 0 to n, cna use similar strartey as 
dicussed in cyclic sort to place the numbers on their correct index. once we have evry number in its correct poition, can 
iteratre through the array to find the indexx which does not have the correct number and that index will be our missing number

2 differences with cyclic sort:
    1. numbers ranged from 0 to n compared ot 1-n in cylic sort. result in two changes in algorithm:
        1. each number should be equal to its idnex compared to index-1 in cyclic sort; this means nums[i] == nums[nums[i]]
        2. since array will have n numbers which mean array indices will range from 0 to n-1. therefore we ignore hte number n
        as we cant place it in the array so nums[i] < nums.length

    2. sway we are at index i. if we swap the number at index i to place it in the correct index, we cna still have the wrong 
    umber at index i. it didnt cause any problems in cyclic sort as ove rhtere we made sure to place one number into its correct spot at
    each step but that wont be enough as we have one extra number due to larger range. therfore before swapping we will check if
    the number at index i is withing ht epermissible range i.e less than the legnth of the input array ad if not, we will skip
    ahead
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    // TODO: Write your code here
    int missingNumber = nums.size();
    for(int i{0}; i< nums.size(); i++){
      missingNumber ^= i ^ nums[i];
    }
    return missingNumber;
  }
};



//My Approaches(2)
using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int getMissingNumber(vector<int> & nums){
    for(int i=0; i< nums.size(); i++){
      if(nums[i] != i)
        return i;
    }
    return nums.size();
  }

  static void sortNumbers(vector<int> & nums){
    int start = 0;
    while(start < nums.size()){
      if(nums[start] >= nums.size() || nums[start] == start)
        ++start;
      else{
        int startValue = nums[start], swappedValue = nums[nums[start]];
        int startIndex = start, swappedIndex = nums[start];
        nums[startIndex] = swappedValue;
        nums[swappedIndex] = startValue;
      }
    }
  }

  static int findMissingNumber(vector<int> &nums) {
    // TODO: Write your code here
    sortNumbers(nums);
    return getMissingNumber(nums);
  }
};




//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] < nums.size() && nums[i] != nums[nums[i]]) {
        swap(nums, i, nums[i]);
      } else {
        i++;
      }
    }

    // find the first number missing from its index, that will be our required number
    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i) {
        return i;
      }
    }

    return nums.size();
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {4, 0, 3, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
  v1 = {8, 3, 5, 2, 4, 6, 0, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
}
