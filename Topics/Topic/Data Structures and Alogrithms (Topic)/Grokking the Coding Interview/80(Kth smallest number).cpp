/*
Problem statement:

Given an unsorted array of numbers, find Kth smallest number in it.

Please note that it is the Kth smallest number in the sorted order, not the Kth distinct element.

Note: For a detailed discussion about different approaches to solve this problem, take a look at Kth Smallest Number.

Example 1:

Input: [1, 5, 12, 2, 11, 5], K = 3
Output: 5
Explanation: The 3rd smallest number is '5', as the first two smaller numbers are [1, 2].
Example 2:

Input: [1, 5, 12, 2, 11, 5], K = 4
Output: 5
Explanation: The 4th smallest number is '5', as the first three small numbers are [1, 2, 5].
Example 3:

Input: [5, 12, 11, -1, 12], K = 3
Output: 11
Explanation: The 3rd smallest number is '11', as the first two small numbers are [5, -1].
*/

/*
-------------------------    My Approaches:
1. Top K elements pattern

    we can apply the smae pattern here since we are looking for the kth smallest elements.
    different from the rpeivous problem, we use a max heap here instead and use it in order to keep track of the k smallest elements.
    if thre is an element that is smaller than the top fo the heap, we repmove the top and insert this new element instead
    at the end, we just need to return the top of the heap as that is the kth smallest element.

    Time complexity: O(nlogk => O(k) + O((n-k) logk))
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
problem follows problem 79 but has two differences:
    1. here we find kth smallest number, whereas in top k numbers, we were dealing with 'k' largest numbers
    2. in this problem, we need to find only one number (kth smallest) compared to finding all k largest numbers

can follow the same approach as discussed in 'top k elements' problem. to handle the first difference, we use a max-heap
instead of a min-heap. as we know, the root is the biggest element in th emax heap. so, since we want to keep track of the 'k' smal;lest numbers, we can
compare every number with the root while iterating throwingh all numbers and if its smaller than the root, we will take the root out and inser the 
smallestr number
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestNumber {
 public:
  static int getSmallest(const vector<int> &nums, int k){
    priority_queue<int> pq;
    for(int i=0; i< nums.size(); i++){
      if(pq.size() < k)
        pq.push(nums[i]);
      else if(nums[i] < pq.top()){
        pq.pop();
        pq.push(nums[i]);
      }
    }
    return pq.top();
  }

  static int findKthSmallestNumber(const vector<int> &nums, int k) {
    // TODO: Write your code here
    if(nums.size() && k && k <= nums.size())
      return getSmallest(nums, k);
    return -1;
  }
};

int main(int argc, char *argv[]) {
  int result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1,1,1,1}, 2);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 4);
  cout << "Kth smallest number is: " << result << endl;

  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Kth smallest number is: " << result << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(const vector<int> &nums, int k) {
    priority_queue<int> maxHeap;

    // put first k numbers in the max heap
    for (int i = 0; i < k; i++) {
      maxHeap.push(nums[i]);
    }

    // go through the remaining numbers of the array, if the number from the array is smaller than
    // the top (biggest) number of the heap, remove the top number from heap and add the number from
    // array
    for (int i = k; i < nums.size(); i++) {
      if (nums[i] < maxHeap.top()) {
        maxHeap.pop();
        maxHeap.push(nums[i]);
      }
    }

    // the root of the heap has the Kth smallest number
    return maxHeap.top();
  }
};

int main(int argc, char *argv[]) {
  int result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 3);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 4);
  cout << "Kth smallest number is: " << result << endl;

  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Kth smallest number is: " << result << endl;
}
