/*
Problem statement:

Given an array of numbers and a number ‘K’, we need to remove ‘K’ numbers from the array such that we are left with maximum distinct numbers.

Example 1:

Input: [7, 3, 5, 8, 5, 3, 3], and K=2
Output: 3
Explanation: We can remove two occurrences of 3 to be left with 3 distinct numbers [7, 3, 8], we have to skip 5 because it is not distinct and appeared twice. 

Another solution could be to remove one instance of '5' and '3' each to be left with three distinct numbers [7, 5, 8], in this case, we have to skip 3 because it appeared twice.
Example 2:

Input: [3, 5, 12, 11, 12], and K=3
Output: 2
Explanation: We can remove one occurrence of 12, after which all numbers will become distinct. Then we can delete any two numbers which will leave us 2 distinct numbers in the result.
Example 3:

Input: [1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5], and K=2
Output: 3
Explanation: We can remove one occurrence of '4' to get three distinct numbers.
*/

/*
-------------------------    My Approaches:
1. top k elements pattern

    we can apply the top k elements pattern here as well. 
    
    1. we need to know the count of each elment in order to know how many ditinct elements we have. so first we crate a map that stores the frequency of all elem,ents and returns
    the size of the map. this is th etoal no of different elements we have to begin with.
    2. we then insert into the heap each element that has a frequency count > 1 as these elements have duplicates and should be the first to get removed so that we are left with distinct elements. we 
    get the eheap size. this is the total number of duplicate elements we have.
    3. out initial distinct elementscount will be then obtained from sibtracting 2 from 1.
    4. now it is given that we have k elements to remove. we want to remove the duplicates first beginning with the one with the least no of duplicates. this is a greedy approach as by removing the duplicates with least number,
    we allow to maximize the no of doistinct elemnts we have remaining as other approaches will nto provide a bettter solution. for each, we check how many will we need to remove in order to make it a s distcunt element.
    if k >= 0 after removing the duplicates from it, we are now left with a new distinct elemnt so we remove it from the heap and add it to distinctelemtnscount. we continue this process till k > 0.


    Time complexity: O(n + nlogn + nlogn) = O(nlogn) where O(n) for creating map, O(nlogn) fir creating heap in worst case, O(nlogn) for removing elements from heap in worst case.
    Space complexity: O(n)
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

class MaximumDistinctElements {
 public:
  static int createMap(const vector<int> &nums, unordered_map<int,int> & elementCount){
    for(int i=0; i< nums.size(); i++){
      if(elementCount.find(nums[i]) == elementCount.end())
        elementCount[nums[i]] = 0;
      elementCount[nums[i]]+=1;
    }
    return elementCount.size();
  }

  static int createHeap(unordered_map<int,int> & elementCount, priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> & pq){
    int duplicateCount = 0;
    for(auto it = elementCount.begin(); it!= elementCount.end(); it++){
      if(it->second != 1){
        duplicateCount++;
        pq.push(make_pair(it->second, it->first));
      }
    }
    return duplicateCount;
  }

  static void getDistinctElements(priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> & pq, int & distinctElementsCount, int & k){
    while(k > 0 && !pq.empty()){
      pair<int,int> topPair = pq.top();
      int diffFromOne = topPair.first - 1;
      k-=diffFromOne;
      if(k>=0){
        distinctElementsCount +=1;
        pq.pop();
      }
    }
  }

  static int findMaximumDistinctElements(const vector<int> &nums, int k) {
    int distinctElementsCount = 0;
    // TODO: Write your code here
    if(nums.size() > k){
      unordered_map<int,int> elementCount;
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      int totalCount = createMap(nums, elementCount);
      int duplicateCount = createHeap(elementCount, pq);
      distinctElementsCount = totalCount - duplicateCount;
      getDistinctElements(pq, distinctElementsCount, k);
      if(k > 0)
        distinctElementsCount -= k;
    }
    return distinctElementsCount;
  }
};

int main(int argc, char *argv[]) {
  int result =
      MaximumDistinctElements::findMaximumDistinctElements(vector<int>{1,2,3}, 5);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(vector<int>{3, 5, 12, 11, 12}, 3);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(
      vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}



//  Other Approaches(1)
