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
