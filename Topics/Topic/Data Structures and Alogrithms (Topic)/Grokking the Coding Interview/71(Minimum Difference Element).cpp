/*
Problem statement:

Given an array of numbers sorted in ascending order, find the element in the array that has the minimum difference with the given ‘key’.

Example 1:

Input: [4, 6, 10], key = 7
Output: 6
Explanation: The difference between the key '7' and '6' is minimum than any other number in the array 
Example 2:

Input: [4, 6, 10], key = 4
Output: 4
Example 3:

Input: [1, 3, 8, 10, 15], key = 12
Output: 10
Example 4:

Input: [4, 6, 10], key = 17
Output: 10
*/

/*
-------------------------    My Approaches:
1. Modified binary search

    we can us ethe modified binary search pattern here. for every mid leemnt we need to get the 
    absolute difference and if it is less than what we have, we swap it. once done that with,
    we then need to make a decision to eiehr move forward or backward to get to a possibility
    of a much better solution so we adjust beg and end accordngly.

    Time complexity: O(log n)
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
#include <bits/stdc++.h>

class MinimumDifference {
 public:
  static int minDiff(const vector<int>& arr, int key){
    int beg = 0, end = arr.size()-1;
    int minDiff = INT_MAX, element = INT_MAX;
    while(beg <= end){
      int mid = beg + (end-beg)/2;
      
      if(arr[mid] == key)
        return arr[mid];
      else if(abs(arr[mid] - key) < minDiff){
        minDiff = abs(arr[mid] - key);
        element = arr[mid];
      }

      if(arr[mid] < key)
        beg = mid+1;
      else
        end = mid-1;
    }
    return element;
  }

  static int searchMinDiffElement(const vector<int>& arr, int key) {
    // TODO: Write your code here
    if(arr.size())
      return minDiff(arr, key);
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1,5}, 2) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1,5}, 4) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1,1,1,1}, 4) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1,1,1,1}, 1) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1,1,1,1}, -1) << endl;
}



//  Other Approaches(1)
