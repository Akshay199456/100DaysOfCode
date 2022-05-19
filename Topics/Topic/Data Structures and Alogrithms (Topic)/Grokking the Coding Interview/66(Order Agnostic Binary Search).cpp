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
to make things simple, lets first solve this problem assuming that the input array is sorted
in ascending order. here are the set of steps for bonary search:

1. lets assume start is pointing to the first index and end is pointitn to the last index 
of the input array (lets call it arr). this means
    int start = 0;
    int end = arr.length-1;

2. first, we will find th emiddle of start and end. an easy way to find middle would be
middle = (start+end)/2. for java and c++, this equation will work for most cases, but when start
or end is large, this equation will give us the wrong result due to integer overflow. imagine
that end is equal to the maximum range of an interger (eg for java int end = integer.max_value).
now adding any positive number to end will result in an integer overflow. since we need to add
both the numbers first to evaluate our eqauation, an oveflfow might occur. the safest way
to find the middle of two numbers without getting an overflow isa s follows:
middle = start + (end-start)/2;

3. next we will see if the key is eqaul to the number at index middle. if it is equal, we return 
middle as the required index

4. if key is not eqaul to number at index middle, we have to check two things:
    1. if key  < arr[middle], then we can conclude that the key will be smaller than all the 
    numbers after index middle as the array is sorted in asecnding order. hence we can reduce
    our search to end = mid-1.
    2. if key > arr[middle], the we can conclude that the key will be greater than all numbers
    before index middle as the array is sorted in the ascending order. hence we can reduce our
    searcg to start = mid+1

5. will repeat steps 2-4 with new ragnes of start to end. if at any time start becomes greater
than end, this means that we cant find the key in th einput array and we must return -1.

if the array is sorted in the descending order, we have to update step 4 as
    1. if key > arr[middle], then we can conclude that the key will be greater than all numbers
    after index middle as the array is sorted in descending order. hence we can reduyce our 
    searcg to end = mid-1
    2. if key < arr[middle], then we can conclude that the key will be samaller than all
    the numbers before index middle as the array is sorted in descending order. hence we can reduce
    our searcg to start = mid + 1

finally, how can we igure out the sort porder if input arrayy, we can compare the nnumbers 
pointed out by start and end  index to find the sort order. if arr[start] < arr[end],
it means that the numbers are sorted in ascending order otherwise they are sorted in
descneding order
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
      int mid = beg+((end-beg)/2);
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
using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    bool isAscending = arr[start] < arr[end];
    while (start <= end) {
      // calculate the middle of the current range
      int mid = start + (end - start) / 2;

      if (key == arr[mid]) {
        return mid;
      }

      if (isAscending) {  // ascending order
        if (key < arr[mid]) {
          end = mid - 1;    // the 'key' can be in the first half
        } else {            // key > arr[mid]
          start = mid + 1;  // the 'key' can be in the second half
        }
      } else {  // descending order
        if (key > arr[mid]) {
          end = mid - 1;    // the 'key' can be in the first half
        } else {            // key < arr[mid]
          start = mid + 1;  // the 'key' can be in the second half
        }
      }
    }
    return -1;  // element not found
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}
