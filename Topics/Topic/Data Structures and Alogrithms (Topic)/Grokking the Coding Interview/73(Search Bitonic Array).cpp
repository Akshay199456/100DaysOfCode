/*
Problem statement:

Given a Bitonic array, find if a given ‘key’ is present in it. An array is considered bitonic if it is monotonically increasing and then monotonically decreasing. Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].

Write a function to return the index of the ‘key’. If the ‘key’ is not present, return -1.

Example 1:

Input: [1, 3, 8, 4, 3], key=4
Output: 3
Example 2:

Input: [3, 8, 3, 1], key=8
Output: 1
Example 3:

Input: [1, 3, 8, 12], key=12
Output: 3
Example 4:

Input: [10, 9, 8], key=10
Output: 0
*/

/*
-------------------------    My Approaches:
1. Modified binary search

    we can apply the modified binary search technique here. we first apply the technique
    in order to find the index of maximum value. once we find that index, we know that
    both sides of that index are sorted. on the left, it is sorted in ascending order while
    on the right, it is sorted in descending otder. then, it becomes a smp[le techniue]
    of finding an element in a sorted array and again binary search technique is the 
    best there so we can check for the presence of the element in either of the 
    halves and it will still be a binary search technqiue.

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
problem follows binary search pattern. since binary search helps us efficiently find a number
in a sorted array, we can use a modified version of the binary search to find the 'key' 
in the bitonic array

here is how we can search in a bitonic array:
1. first, we can find the index of the maximum value of the bitonuic array, similar to 
bitonic array maximum problem. lets call the inex of the maximum number maxIndex.
2. now we can break the array into 2 sub-arrays:
    1. array from index '0' to maxindex, sorted in ascending order
    2. array from index maxIndex+1 to array_length-1, sorted in desicneidng order
3. we can then call binary search separately in these two arrays to search the key. we can use
the same order-agnostic binary search for searching
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class SearchBitonicArray {
 public:
  static int getMaxIndex(const vector<int> &arr){
    int beg=0, end = arr.size()-1;
    while(beg <= end){
      int mid = beg + (end-beg)/2;
      bool leftComplete = false, rightComplete = false;

      // conditions to satisfy dependong on position of mid
      if((mid == 0) || (arr[mid] > arr[mid-1]))
        leftComplete = true;
      if((mid == arr.size()-1) || (arr[mid] > arr[mid+1]))
        rightComplete = true;
      
      // if both are complete, then we have found our answer
      if(leftComplete && rightComplete)
        return mid;
      else if(leftComplete)
        beg = mid+1;
      else
        end = mid-1;
    }
    return -1;
  }

  static int findElement(const vector<int> &arr, int key, int beg, int end, int dirn){
      //ascending order
      while(beg <= end){
        int mid = beg + (end-beg)/2;
        if(key == arr[mid])
          return mid;
        else if(key < arr[mid]){
          if(dirn == -1)
            end = mid-1;
          else
            beg = mid+1;
        }
        else{
          if(dirn == -1)
            beg = mid+1;
          else
            end = mid-1;
        }
      }
    return -1;
  }

  static int search(const vector<int> &arr, int key) {
    // TODO: Write your code here
    if(arr.size()){
      int index = getMaxIndex(arr);
      int leftSearch = findElement(arr, key, 0, index, -1);
      int rightSearch = findElement(arr, key, index, arr.size()-1, 1);

      if(leftSearch != -1)
        return leftSearch;
      if(rightSearch != -1)
        return rightSearch;
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  cout << SearchBitonicArray::search(vector<int>{}, 4) << endl;
  cout << SearchBitonicArray::search(vector<int>{1}, -1) << endl;
  cout << SearchBitonicArray::search(vector<int>{1}, 1) << endl;
  cout << SearchBitonicArray::search(vector<int>{1}, 3) << endl;
  cout << SearchBitonicArray::search(vector<int>{1,4}, -1) << endl;
  cout << SearchBitonicArray::search(vector<int>{1,4}, 1) << endl;
  cout << SearchBitonicArray::search(vector<int>{1,4}, 2) << endl;
  cout << SearchBitonicArray::search(vector<int>{1,4}, 4) << endl;
  cout << SearchBitonicArray::search(vector<int>{1,4}, 6) << endl;

}




//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class SearchBitonicArray {
 public:
  static int search(const vector<int> &arr, int key) {
    int maxIndex = findMax(arr);
    int keyIndex = binarySearch(arr, key, 0, maxIndex);
    if (keyIndex != -1) {
      return keyIndex;
    }
    return binarySearch(arr, key, maxIndex + 1, arr.size() - 1);
  }

  // find index of the maximum value in a bitonic array
  static int findMax(const vector<int> &arr) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (arr[mid] > arr[mid + 1]) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    // at the end of the while loop, 'start == end'
    return start;
  }

 private:
  // order-agnostic binary search
  static int binarySearch(const vector<int> &arr, int key, int start, int end) {
    while (start <= end) {
      int mid = start + (end - start) / 2;

      if (key == arr[mid]) {
        return mid;
      }

      if (arr[start] < arr[end]) {  // ascending order
        if (key < arr[mid]) {
          end = mid - 1;
        } else {  // key > arr[mid]
          start = mid + 1;
        }
      } else {  // descending order
        if (key > arr[mid]) {
          end = mid - 1;
        } else {  // key < arr[mid]
          start = mid + 1;
        }
      }
    }
    return -1;  // element is not found
  }
};

int main(int argc, char *argv[]) {
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 4, 3}, 4) << endl;
  cout << SearchBitonicArray::search(vector<int>{3, 8, 3, 1}, 8) << endl;
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 12}, 12) << endl;
  cout << SearchBitonicArray::search(vector<int>{10, 9, 8}, 10) << endl;
}
