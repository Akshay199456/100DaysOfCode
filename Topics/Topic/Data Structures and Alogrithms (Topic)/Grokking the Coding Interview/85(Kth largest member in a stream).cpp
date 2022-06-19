/*
Problem statement:

Design a class to efficiently find the Kth largest element in a stream of numbers.

The class should have the following two things:

The constructor of the class should accept an integer array containing initial numbers from the stream and an integer ‘K’.
The class should expose a function add(int num) which will store the given number and return the Kth largest number.
Example 1:

Input: [3, 1, 5, 12, 2, 11], K = 4
1. Calling add(6) should return '5'.
2. Calling add(13) should return '6'.
2. Calling add(4) should still return '6'.

*/

/*
-------------------------    My Approaches:
1. Top k elements pattern

    we can use a min heap as it follows the top k elements pattern. by using a min heap and 
    restricting it to size k, we will always have k elements. also since we have a min heap of size
    k, the kth largest elemnt will always be atht the top of the min heap since the max value will be k levels down.
    as a result, when adding a number, it becomes really easy to return the kth largest element since it is the top of the heap
    depending whether the value we are adding is greater than the top of the heap or not.

    Time complexity: O(log k) for add; O(log n) in worst case for return value 
    Space complexity: O(k)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
follows top k elements pattern and shares similarities with kth smallest number.

can follow the same approach as dicussed in 'kth smallest number' problem. however, will use a 
min heap(instead of max heap) as we need to find the kth largest number.

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthLargestNumberInStream {
 public:
  priority_queue<int, vector<int>, greater<int>> pq;

  KthLargestNumberInStream(const vector<int> &nums, int k) {
  // TODO: Write your code here
    for(int i=0; i< nums.size(); i++){
      if(pq.size() < k)
        pq.push(nums[i]);
      else if(nums[i] > pq.top()){
        pq.pop();
        pq.push(nums[i]);
      }
    }
  }

  virtual int add(int num) {
    // TODO: Write your code here
    int result = 0;
    if(num > pq.top()){
      pq.pop();
      result = pq.top();
      pq.push(num);
    }
    else
      result = pq.top();

    return result;
  }
};

int main(int argc, char *argv[]) {
  KthLargestNumberInStream kthLargestNumber({3, 1, 5, 12, 2, 11}, 4);
  cout << "4th largest number is: " << kthLargestNumber.add(6) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(13) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(4) << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthLargestNumberInStream {
 public:
  struct numCompare {
    bool operator()(const int &x, const int &y) { return x > y; }
  };

  priority_queue<int, vector<int>, numCompare> minHeap;
  const int k;

  KthLargestNumberInStream(const vector<int> &nums, int k) : k(k) {
    // add the numbers in the min heap
    for (int i = 0; i < nums.size(); i++) {
      add(nums[i]);
    }
  }

  virtual int add(int num) {
    // add the new number in the min heap
    minHeap.push(num);

    // if heap has more than 'k' numbers, remove one number
    if ((int)minHeap.size() > this->k) {
      minHeap.pop();
    }

    // return the 'Kth largest number
    return minHeap.top();
  }
};

int main(int argc, char *argv[]) {
  KthLargestNumberInStream kthLargestNumber({3, 1, 5, 12, 2, 11}, 4);
  cout << "4th largest number is: " << kthLargestNumber.add(6) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(13) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(4) << endl;
}
