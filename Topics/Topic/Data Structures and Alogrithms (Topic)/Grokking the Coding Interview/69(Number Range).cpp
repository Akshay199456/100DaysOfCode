/*
Problem statement:

Given an array of numbers sorted in ascending order, find the range of a given number ‘key’. The range of the ‘key’ will be the first and last position of the ‘key’ in the array.

Write a function to return the range of the ‘key’. If the ‘key’ is not present return [-1, -1].

Example 1:

Input: [4, 6, 6, 6, 9], key = 6
Output: [1, 3]
Example 2:

Input: [1, 3, 8, 10, 15], key = 10
Output: [3, 3]
Example 3:

Input: [1, 3, 8, 10, 15], key = 12
Output: [-1, -1]

*/

/*
-------------------------    My Approaches:
1. Modifided binary search

    since the array is sorted here, we can apply the modified binary search algorithm.
    if key == mid, then we know we have found one candidate. but there could be other candidtes
    as well so we search on the left and right as well. else we do the usual binary search.

    the time complexity in the worst case is O(n) as you would have to go through all the 
    elements to find the answer.

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
problem follows binary search pattern. since binary search helps us find a number in a sorted
array efficieintly, we can uyse a modified version of the binary search to find the first and
last position of  a number

can use similar approach as discussed in order-agnsotic binary search. will try to search for
'key' in given array: if found (i.e key == arr[middle], have two options:
    1. when trying to find the first poisition of the key, we can update end = middle-1
    to see if key is present before middle
    2. when trying to find last position of key, can update start = middle+1 to ssee if key
    is present after middle.

in both cases, we will keeep track of the last position where we found th ekey. these positiions will
be the required range.
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class FindRange {
 public:
  static void calculateRange(const vector<int> &arr, int key, int & minValue, int & maxValue, int beg, int end){
    if(beg <= end){
      int mid = beg + (end-beg)/2;
      if(key == arr[mid]){
        if(minValue > mid)
          minValue = mid;
        if(maxValue < mid)
          maxValue = mid;
        
        calculateRange(arr,key,minValue,maxValue,beg,mid-1);
        calculateRange(arr,key,minValue,maxValue,mid+1,end);
      }

      else if(key < arr[mid])
        calculateRange(arr, key, minValue, maxValue, beg, mid-1);
      else
        calculateRange(arr, key, minValue, maxValue, mid+1, end);
    }
  }

  static void getRange(const vector<int> &arr, int key, pair<int,int> & result){
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    int beg = 0, end = arr.size()-1;
    calculateRange(arr,key,minValue,maxValue,beg,end);
    if(minValue != INT_MAX)
      result.first = minValue;
    if(maxValue != INT_MIN)
      result.second = maxValue;
  }

  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    // TODO: Write your code here
    if(arr.size())
      getRange(arr, key, result);
    return result;
  }
};

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1,3}, 3);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    result.first = search(arr, key, false);
    if (result.first != -1) {  // no need to search, if 'key' is not present in the input array
      result.second = search(arr, key, true);
    }
    return result;
  }

 private:
  // modified Binary Search
  static int search(const vector<int> &arr, int key, bool findMaxIndex) {
    int keyIndex = -1;
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < arr[mid]) {
        end = mid - 1;
      } else if (key > arr[mid]) {
        start = mid + 1;
      } else {  // key == arr[mid]
        keyIndex = mid;
        if (findMaxIndex) {
          start = mid + 1;  // search ahead to find the last index of 'key'
        } else {
          end = mid - 1;  // search behind to find the first index of 'key'
        }
      }
    }
    return keyIndex;
  }
};

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}
