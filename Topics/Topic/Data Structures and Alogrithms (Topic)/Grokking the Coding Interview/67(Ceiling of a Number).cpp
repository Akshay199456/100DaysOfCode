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
