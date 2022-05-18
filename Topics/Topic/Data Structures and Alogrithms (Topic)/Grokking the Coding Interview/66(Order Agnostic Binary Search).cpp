/*
Problem statement:

Given a sorted array of numbers, find if a given number ‘key’ is present in the array. Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order. You should assume that the array can have duplicates.

Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.
*/

/*
-------------------------    My Approaches:
1. Modified Binary Search

    we can use the modified binary search pattern here. we adjust it depending on whwether 
    it is ascending or descending and use the beg and end accordingly.

    Time complexity: O(logn)
    Space complexity: O(1)
*/


/*
-------------------------    Other Approaches 
1. 
*/


/*
-------------------------    Notes

*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:
  static int getBinarySearch(const vector<int>& arr, int key)
  {
    bool isAscending = arr[0] <= arr[arr.size()-1]; 
    int beg = isAscending ? 0 : arr.size()-1;
    int end = isAscending ? arr.size()-1 : 0;
    int dirn = isAscending ? 1 : -1; 

    while((dirn==1 && beg <= end) || (dirn==-1 && end<=beg)){
      int mid = (beg+end)/2;
      if(key == arr[mid])
        return mid;
      else if(key < arr[mid])
        end = mid - dirn;
      else
        beg = mid + dirn;
    }
    return -1;
  }

  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    if(arr.size())
      return getBinarySearch(arr, key);
    return -1; 
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{4, 3, 2,1}, 2) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}



//  Other Approaches(1)
