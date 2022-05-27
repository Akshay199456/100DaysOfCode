/*
Problem statement:

Find the maximum value in a given Bitonic array. An array is considered bitonic if it is monotonically increasing and then monotonically decreasing. Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].

Example 1:

Input: [1, 3, 8, 12, 4, 2]
Output: 12
Explanation: The maximum number in the input bitonic array is '12'.
Example 2:

Input: [3, 8, 3, 1]
Output: 8
Example 3:

Input: [1, 3, 8, 12]
Output: 12
Example 4:

Input: [10, 9, 8]
Output: 10
*/

/*
-------------------------    My Approaches:
1. Modified Binary Search

    can use the mdoified binary search pattern here. we use 2 boolean variables to track the state 
    of whether the element at the middle is greater than its left and right and if so adjust 
    the boolean variables accordingly.

    if both are satisfied we have found our element else if only left is astisifed, then 
    there is a greater element on the right so we have to adjust our beg to it. if there
    is a greater element on the  left , then only the right is satisifed so we adjust our
    beg accordingly.

    at the point of maximum value, the maximum value is greater both than its left and right.
    if it is present at the ends fo the arrya, we adjsut accordingly.,

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
bitonic array is sorted array; only difference is that its first part is sorted in ascending order
and the second part in descending order. can use a similar approach as dicussed in 
order-agnostic binaryu search. since no two consecutive numbers are same, whenever we calculate
middle, we can compare the numbers pointed out byh the index middle and middle+1 to find if 
we are in the ascending or descending part. So:
    1. if arr[middle] > arr[middle+1], we are in second(descending) part of the bitonic array.
    therefore, our required number could either be pointed out by middle or will be before middle.
    this means we will be doing: end = middle
    2. if arr[middle] < arr[middle+1], we are in the first (ascending part) of the bitonic array.
    therefore, the required number will be after middle. this means we will be doing
    start = middle+1.

we can break when start==end. due to the two points smentioned above, both start and end will bne
pointing at the maximim number of the bitonic array.
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class MaxInBitonicArray {
 public:
  static int getMax(const vector<int>& arr){
    int beg = 0, end = arr.size()-1;
    while(beg <= end){
      int mid = beg + (end-beg)/2;
      // cout<<"mid: "<<mid<<endl;
      bool leftComplete = false, rightComplete = false;

      // conditions to satisfy dependong on position of mid
      if((mid == 0) || (arr[mid] > arr[mid-1]))
        leftComplete = true;
      if((mid == arr.size()-1) || (arr[mid] > arr[mid+1]))
        rightComplete = true;
      
      // if both are complete, then we have found our answer
      if(leftComplete && rightComplete)
        return arr[mid];
      else if(leftComplete)
        beg = mid+1;
      else
        end = mid-1;
    }
    return -1;
  }

  static int findMax(const vector<int>& arr) {
    // TODO: Write your code here
    if(arr.size())
      return getMax(arr);
    return -1;
  }

};

int main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1,3,8,10,12,9}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int>& arr) {
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
    return arr[start];
  }
};

int main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}
