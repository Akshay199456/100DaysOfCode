/*
Problem statement:

Given an array, find the sum of all numbers between the K1’th and K2’th smallest elements of that array.

Example 1:

Input: [1, 3, 12, 5, 15, 11], and K1=3, K2=6
Output: 23
Explanation: The 3rd smallest number is 5 and 6th smallest number 15. The sum of numbers coming
between 5 and 15 is 23 (11+12).
Example 2:

Input: [3, 5, 8, 7], and K1=1, K2=4
Output: 12
Explanation: The sum of the numbers between the 1st smallest number (3) and the 4th smallest 
number (8) is 12 (5+7).

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


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
 public:
  static void getSum(const vector<int> &nums, int k1, int k2, int & elementSum){
    priority_queue<int> pq;

    // fill max heap
    for(int i=0; i< nums.size(); i++){
      if(pq.size() < k2)
        pq.push(nums[i]);
      else if(nums[i] < pq.top()){
        pq.pop();
        pq.push(nums[i]);
      }
    }

    // calculate sum
    pq.pop();
    for(int i=0; i < k2-k1-1; i++){
      elementSum += pq.top();
      pq.pop();
    }
  }
  
  static int findSumOfElements(const vector<int> &nums, int k1, int k2) {
    int elementSum = 0;
    // TODO: Write your code here
    if(k2-k1 > 1 and k1 <= nums.size() and k2 <= nums.size())
      getSum(nums, k1, k2, elementSum);
    return elementSum;
  }
};

int main(int argc, char *argv[]) {
  int result = SumOfElements::findSumOfElements(vector<int>{1}, 3, 5);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;

  result = SumOfElements::findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;
}



//  Other Approaches(1)
