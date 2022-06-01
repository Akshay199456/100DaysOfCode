/*
Problem statement:

Given an array of numbers which is sorted in ascending order and is rotated ‘k’ times around a pivot, find ‘k’.

You can assume that the array does not have any duplicates.

Example 1:

Input: [10, 15, 1, 3, 8]
Output: 2
Explanation: The array has been rotated 2 times.
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

Input: [4, 5, 7, 9, 10, -1, 2]
Output: 5
Explanation: The array has been rotated 5 times.
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
 Array after 5 rotations:  
Example 3:

Input: [1, 3, 8, 10]
Output: 0
Explanation: The array has been not been rotated.
*/

/*
-------------------------    My Approaches:
1. Modified Binary Search 

    we can apply the modified binary search technique here. we know that the array is 
    rotated so that means that one half will always be sorted while the other will eb not. 
    the array that will be not sorted wwill be the one with the max element in the array.
    as a result, we find the max element in the array with binary search. once we fund
    it, the rest is easy. we know that in a purly sorted array, the max element will be on 
    the right most. so we find the difference in the index of the current max vs where it
    should be and that is the answer


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
follows binary search pattern. can use a similar strategy as dicussed in search in rotated array.

in this problem, asked to find the index of the minimum elelement. the number of times the 
minimum element is moved to the rright will be equal to the number of rotations. another interesting
fact about he minimum element is that it is the only element in the given array which is smaller
than its previous element. since the array is sorted in ascending order, all other elements are
bigger than theoir previous element.

after calculating the  middle, we can compare the number at index middle with its previous and
next number. this will give us two options:
1. if arr[middle] > arr[middle+1], then element middle+1 is the smallest
2. if arr[middle-1] > arr[middle], then element at middle is the smallest.

to adjust the ranges, we can follow the smae appraoch as dicussed in search in rotated array
problem. compareing the numbers at indeices start and middle will give us two optoons:
1. if arr[start] < arr[middle], numbers from start to middle are sorted.
2. else numbers from middle+1 to end are sorted.
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
 public:
  static int findCount(const vector<int>& arr){
    int beg = 0, end = arr.size()-1;
    while(beg <= end){
      bool leftComplete = false, rightComplete = false;
      int mid = beg + (end-beg)/2;


      // need to change this logic a bit. it has to compare against index end-1 if mid ==0 and the same for beg
      // in other words compare against the previous element wherever it is.
      if(((mid == 0) && (arr[mid] > arr[arr.size()-1])) || (arr[mid] > arr[mid-1]))
        leftComplete = true;
      if(((mid == arr.size()-1) && (arr[mid] > arr[0])) || (arr[mid] > arr[mid+1]))
        rightComplete = true;
      
      if(leftComplete && rightComplete)
        return (mid+1) % arr.size();
      else{
        if(arr[beg] <= arr[mid])
          beg = mid+1;
        else
          end = mid-1;
      }
    }
    return -1;
  }

  static int countRotations(const vector<int>& arr) {
    // TODO: Write your code here
    return findCount(arr);
  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{15, 1, 3, 8,10}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4,5,7,9,10,-1,2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1,3,8,10,15}) << endl;
  
}




//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
 public:
  static int countRotations(const vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
      int mid = start + (end - start) / 2;

      if (mid < end && arr[mid] > arr[mid + 1]) {  // if mid is greater than the next element
        return mid + 1;
      }
      if (mid > start && arr[mid - 1] > arr[mid]) {  // if mid is smaller than the previous element
        return mid;
      }

      if (arr[start] < arr[mid]) {  // left side is sorted, so the pivot is on right side
        start = mid + 1;
      } else {  // right side is sorted, so the pivot is on the left side
        end = mid - 1;
      }
    }

    return 0;  // the array has not been rotated
  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}
