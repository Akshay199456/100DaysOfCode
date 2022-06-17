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
