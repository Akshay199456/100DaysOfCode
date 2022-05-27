/*
Problem statement:

Given an array of numbers which is sorted in ascending order and also rotated by some arbitrary number, find if a given ‘key’ is present in it.

Write a function to return the index of the ‘key’ in the rotated array. If the ‘key’ is not present, return -1. You can assume that the given array does not have any duplicates.

Example 1:

Input: [10, 15, 1, 3, 8], key = 15
Output: 1
Explanation: '15' is present in the array at index '1'.
    1   
    3   
    8   
    10   
    15   
 Original array:  
 Array after 2 rotations:  
    10   
    15   
    1   
    3   
    8   
Example 2:

Input: [4, 5, 7, 9, 10, -1, 2], key = 10
Output: 4
Explanation: '10' is present in the array at index '4'.
 Original array:  
    -1   
    2   
    4   
    5   
    7   
    9   
    10   
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
*/

/*
-------------------------    My Approaches:
1. Modified binary search [does not work]

    the tactic to this problem is simple. we need to find either hte min element or max
    element in the aray. for either of the two element indexes known, we can divide the 
    array into two sorted parts and we can then find the element we are looking for in the respective sorted 
    half.

    while i was able to do the lattere, i had trouible coming up with an algorithm to 
    determine the max/min element in the sorted rotated array in O(log n) tiome. if i 
    could have got that, i wouild have been able to solve the problem fully.

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



//  My approaches(1) [Does not work]

using namespace std;

#include <iostream>
#include <vector>

class SearchRotatedArray {
 public:
  static int getMaxIndex(const vector<int>& arr){
    int beg = 0, end = arr.size()-1;
    while(beg <= end){
      int mid = beg + (end-beg)/2;
      bool leftComplete = false, rightComplete = false;

      if(mid == beg || arr[mid] > arr[beg])
        leftComplete = true;
      if(mid == end || arr[mid] > arr[end])
        rightComplete = true;
      
      // if in proper ascending order
      if(leftComplete && rightComplete)
        return mid;
      
      if(leftComplete)
        beg = mid+1;
      else
        end = mid-1;

    }
    return -1;
  }

  static int findElement(const vector<int>& arr, int key, int beg, int end){
    while(beg <= end){
      int mid = beg + (end-beg)/2;
      
      if(arr[mid] == key)
        return mid;
      else if(key < arr[mid])
        end = mid-1;
      else
        beg = mid+1;
    }
    return -1;
  }

  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    if(arr.size()){
      int maxIndex = getMaxIndex(arr);
      cout<<"Max index: "<<maxIndex<<endl;
      int leftSearch = findElement(arr, key, 0, maxIndex);
      if(leftSearch != - 1)
        return leftSearch;
      return findElement(arr, key, maxIndex+1, arr.size()-1);   
    }
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << SearchRotatedArray::search(vector<int>{10,15,1,3,8}, 15) << endl;
  cout << SearchRotatedArray::search(vector<int>{4,5,7,9,10,-1,2}, 10) << endl;
  cout << SearchRotatedArray::search(vector<int>{10,15,1,3,8}, 11) << endl;
  cout << SearchRotatedArray::search(vector<int>{1,3,8,10,15}, 8) << endl;
  cout << SearchRotatedArray::search(vector<int>{15,1,3,8,10}, 8) << endl;
  cout << SearchRotatedArray::search(vector<int>{10,15,1,3,8}, 8) << endl;
  cout << SearchRotatedArray::search(vector<int>{8,10,15,1,3}, 8) << endl;
  cout << SearchRotatedArray::search(vector<int>{3,8,10,15,1}, 8) << endl;

}


//  Other Approaches(1)
