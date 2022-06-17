/*
Problem statement:

Given an unsorted array of numbers, find the ‘K’ largest numbers in it.

Note: For a detailed discussion about different approaches to solve this problem, take a look at Kth Smallest Number.

Example 1:

Input: [3, 1, 5, 12, 2, 11], K = 3
Output: [5, 12, 11]
Example 2:

Input: [5, 12, 11, -1, 12], K = 3
Output: [12, 11, 12]
*/

/*
-------------------------    My Approaches:
1. Top K elements pattern

  we cna use the top kelements pattern in order to solve the rpoblem. we can use a min heap to save a bit of extra 
  space. in the min heap, we will insert elements only if the the current element is greater
  than the top of the heap so we pop the top of the heap and then insert this new eleement.
  this way, elkements which are greater are pushed into the heap with the rest being outside.

    Time complexity: O(nlogk)
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
brute force solution could be to sort the array and return the largest k numbers. the time complexity of such an algorithm
will be O(nlogn) as we need to use a sorting algorithm like Timsort if we use Java's colelction.sort()

the best data structure that comes to mind to keep track of top 'k' elements is heap.

if we iteratre through array one eleent at a time and keep k leargeest numbers in heap such that each time
we find a larger number than the smallest number in the heap, we do two things:
  1. take out the smallest nuimber from the heap and
  2. insert  the larger number into the heap.

this will always ensure we ave 'k' largest numbers in the heap. the most efficient way to repeatedly find the smallest
number among a set of numers will be to use a min-heap. as we now, we can find th esmallest numbeer in a min-heap
in constant time O(1) since the smallest numbers is always at the root fo t he heap.
extracting the smallest number from a min-heap will take O(logn) (if th eheap has n elements) as the heap
needs to readjist after the removal of an element

it will take us O(log k) to extract the minimum number from the min-heap. so the overall time complexity
of our algorithm will be O(klogk + (n-k) logk) since first we insert K numbers in the heap and then
iterate through the remaining numbers and at everys tep, int he worst case, we need to extract the 
minimum number and insert a new number in the heap.
*/



//  My approaches(1)
using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  static void getLargestNumbers(const vector<int>& nums, int k, vector<int> & result){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // get max heap of k elements
    for(int ele: nums){
      if(pq.size() < k)
        pq.push(ele);
      else if(pq.top() < ele){
        pq.pop();
        pq.push(ele);
      }
    }

    // push elements into vector
    while(!pq.empty()){
      result.push_back(pq.top());
      pq.pop();
    }
  }

  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    vector<int> result;
    // TODO: Write your code here
    if(nums.size() && k)
      getLargestNumbers(nums, k, result);  
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{5,4,3,2,1}, 6);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}



//  Other Approaches(1)
using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  struct greater {
    bool operator()(const int& a, const int& b) const { return a > b; }
  };
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    // put first 'K' numbers in the min heap
    vector<int> minHeap(nums.begin(), nums.begin() + k);
    make_heap(minHeap.begin(), minHeap.end(), greater());

    // go through the remaining numbers of the array, if the number from the array is bigger than
    // the top (smallest) number of the min-heap, remove the top number from heap and add the number
    // from array
    for (int i = k; i < nums.size(); i++) {
      if (nums[i] > minHeap.front()) {
        pop_heap(minHeap.begin(), minHeap.end(), greater());
        minHeap.pop_back();
        minHeap.push_back(nums[i]);
        push_heap(minHeap.begin(), minHeap.end(), greater());
      }
    }

    // the heap has the top 'K' numbers
    return minHeap;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
