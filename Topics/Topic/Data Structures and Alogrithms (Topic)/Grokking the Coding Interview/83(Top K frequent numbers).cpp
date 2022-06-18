/*
Problem statement:

Given an unsorted array of numbers, find the top ‘K’ frequently occurring numbers in it.

Example 1:

Input: [1, 3, 5, 12, 11, 12, 11], K = 2
Output: [12, 11]
Explanation: Both '11' and '12' apeared twice.
Example 2:

Input: [5, 12, 11, 3, 11], K = 2
Output: [11, 5] or [11, 12] or [11, 3]
Explanation: Only '11' appeared twice, all other numbers appeared once.
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
#include <unordered_map>
#include <vector>

class TopKFrequentNumbers {
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };

 public:
  static void generateMap(const vector<int> &nums, unordered_map<int, int> & elementCount){
    for(int ele: nums){
      if(elementCount.find(ele) == elementCount.end())
        elementCount[ele] = 1;
      else
        elementCount[ele] += 1;
    }
  }

  static void getTopKNumbers(unordered_map<int, int> & elementCount, int k, vector<int> & topNumbers){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    //fill priority queue
    for(auto it = elementCount.begin(); it!= elementCount.end(); it++){
      if(pq.size() < k)
        pq.push(make_pair(it->second, it->first));
      else if(it->second > pq.top().first){
        pq.pop();
        pq.push(make_pair(it->second, it->first));
      }
    }

    // push priority queue results into vector
    while(!pq.empty()){
      topNumbers.push_back(pq.top().second);
      pq.pop();
    }
  }

  static vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) {
    vector<int> topNumbers;
    // TODO: Write your code here
    if(nums.size() and k){
      unordered_map<int, int> elementCount;
      generateMap(nums, elementCount);
      getTopKNumbers(elementCount, k, topNumbers);
    }
    return topNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{1, 1,1,1}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{5, 12, 11, 3, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}



//  Other Approaches(1)
