/*
Problem statement:

Given an array of numbers sorted in an ascending order, find the ceiling of a given number ‘key’. The ceiling of the ‘key’ will be the smallest element in the given array greater than or equal to the ‘key’.

Write a function to return the index of the ceiling of the ‘key’. If there isn’t any ceiling return -1.
*/

/*
-------------------------    My Approaches:
1. Modified Bonary Search

    we can apply the modified binary search pattern here. in order to find the right index,
    we will have to go through the whole array by skipping half of it at each interval
    if our mid element is greater than the key, then we know that we atleast have a solution.
    but, we still need to explore if we have a better solution so we adjust our end to mid-1.
    if our mid element is less than the key, then we need to search in the latter half for
    the element we are looking for.


    Time complexity: O(logn)
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
problem follows binary search pattern. since binary search helps us find a number in
sorted array efficieintly , can use modified versioin of bonaary search to find ceiling of number.

can use similar approach as discussed in order-agnostic binary search. will try to search
fir key in given array. if we find the 'key', we retun its index as the ceiling.
iof cwe cant find the keyu, the next big number will be pointed out by the index start.

since always adjusting our range to find the key, when we exist the loop, the start of our range
will point to the smallesst number greater than the key.

can add a check in beginning to see if key is bigger than biggest number in input
array. if so, return -1.
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int getCeiling(const vector<int>& arr, int key){
    int beg = 0, end = arr.size()-1, index = -1;
    while(beg <= end){
      int mid = beg + (end-beg)/2;
      if(arr[mid] >= key){
        index = mid;
        end = mid-1;
      }
      else
        beg = mid+1;
    }
    return index;
  }

  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    // TODO: Write your code here
    if(arr.size())
      return getCeiling(arr, key);
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1,1,1,2,3,4}, 1) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 8) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 1) << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    if (key > arr[arr.size() - 1]) {  // if the 'key' is bigger than the biggest element
      return -1;
    }

    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < arr[mid]) {
        end = mid - 1;
      } else if (key > arr[mid]) {
        start = mid + 1;
      } else {  // found the key
        return mid;
      }
    }
    // since the loop is running until 'start <= end', so at the end of the while loop, 'start ==
    // end+1' we are not able to find the element in the given array, so the next big number will be
    // arr[start]
    return start;
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 6) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}
