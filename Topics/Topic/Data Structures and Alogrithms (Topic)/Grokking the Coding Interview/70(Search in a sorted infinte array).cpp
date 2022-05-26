/*
Problem statement:

Given an infinite sorted array (or an array with unknown size), find if a given number ‘key’ is present in the array. Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.

Since it is not possible to define an array with infinite (unknown) size, you will be provided with an interface ArrayReader to read elements of the array. ArrayReader.get(index) will return the number at index; if the array’s size is smaller than the index, it will return Integer.MAX_VALUE.

Example 1:

Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
Output: 6
Explanation: The key is present at index '6' in the array.
Example 2:

Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 11
Output: -1
Explanation: The key is not present in the array.
Example 3:

Input: [1, 3, 8, 10, 15], key = 15
Output: 4
Explanation: The key is present at index '4' in the array.
Example 4:

Input: [1, 3, 8, 10, 15], key = 200
Output: -1
Explanation: The key is not present in the array.
*/

/*
-------------------------    My Approaches:
1. 

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
folllows the binary search pattern. since binary search helps us find a number in a sorted 
array efficiently, we can use a modified version of the binary search to find the 'key' in an 
infiinte sorted array.

only issue with applying binary search in this problem is that we don't know the  bounds of the array.
to handle this situation, we will first find the proper bounds off the array where we can perform 
a binary search

an efficeint way to find th eproper bounds is to start at the beginning of the array with the 
bound size as '1' and exponentailly increases the bounds's size (i.e double it ) untitl we 
fnd the bounds that can have the key.

Time complexityy:
    two parts to algorithm. in first path, we keep increasing the bounds' size exponentailly
    (double it every time) while searching for the proper bounds. threfore,, this stepp will
    takle O(logn) assuming that the array will have maximum 'n' numbers. in the second
    step, we perform binary search which is O(logn). thus thte total time compelxity is O(logn + logn)
    = O(logn)

Space compleixty: O(1)
*/



//  My approaches(1)



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class SearchInfiniteSortedArray {
 public:
  static int search(ArrayReader *reader, int key) {
    // find the proper bounds first
    int start = 0, end = 1;
    while (reader->get(end) < key) {
      int newStart = end + 1;
      end += (end - start + 1) * 2;  // increase to double the bounds size
      start = newStart;
    }
    return binarySearch(reader, key, start, end);
  }

 private:
  static int binarySearch(ArrayReader *reader, int key, int start, int end) {
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < reader->get(mid)) {
        end = mid - 1;
      } else if (key > reader->get(mid)) {
        start = mid + 1;
      } else {  // found the key
        return mid;
      }
    }

    return -1;
  }
};

int main(int argc, char *argv[]) {
  ArrayReader *reader =
      new ArrayReader(vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << SearchInfiniteSortedArray::search(reader, 16) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 11) << endl;
  reader = new ArrayReader(vector<int>{1, 3, 8, 10, 15});
  cout << SearchInfiniteSortedArray::search(reader, 15) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 200) << endl;
  delete reader;
}
