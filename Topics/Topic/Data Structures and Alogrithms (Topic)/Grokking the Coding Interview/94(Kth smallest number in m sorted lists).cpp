/*
Problem statement:

Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
Output: 4
Explanation: The 5th smallest number among all the arrays is 4, this can be verified from 
the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7], K=3
Output: 7
Explanation: The 3rd smallest number among all the arrays is 7.
*/

/*
-------------------------    My Approaches:
1. k way merge

    we can appl the k way merge pattern here similar to pb 93 grok. the difference here is
    that we need to insert elements into the min heap until our count vcalue hits the value of k. 
    since we have m sorted lists, we will have at most m elements in the heap at any time. when we pop an elemnet from the heap, that mneans that
    is the least element we have seen till now and would be next in our sorted lsit. so we increment count to inmdicate we have hit the 1st min element. we continue to do this till we hit the kth element.

    Time complexity: O(klogm) wheer m is the number of sorted lists, k is the smallest number we are finding
    Space complexity: O(m)
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
#include <tuple>
#include <queue>
#include <vector>

class KthSmallestInMSortedArrays {
 public:
  static int getKSmallest(const vector<vector<int>> &lists, int k){
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;
    int count = 0;
    tuple<int,int,int> topPair;

    // insert first elements from each list into min heap
    for(int i=0; i< lists.size(); i++){
      if(lists[i].size())
        minHeap.push(make_tuple(lists[i][0], i, 0));
    }

    while(count != k){
      topPair = minHeap.top();
      minHeap.pop();
      ++count;

      int elementIndex = get<2>(topPair);
      int listIndex = get<1>(topPair);
      if(elementIndex < lists[listIndex].size()-1)
        minHeap.push(make_tuple(lists[listIndex][elementIndex+1], listIndex, elementIndex+1));
    }
    return get<0>(topPair);
  }
  
  static int findKthSmallest(const vector<vector<int>> &lists, int k) {
    int count = 0;
    // TODO: Write your code here

    // get toal no of elements
    for(auto list: lists)
      count += list.size();
    
    if(k < 1 || k > count)
      return -1;
    return getKSmallest(lists, k);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{1}, {2}, {3}};
  int result = KthSmallestInMSortedArrays::findKthSmallest(lists, 3);
  cout << "Kth smallest number is: " << result;
}



//  Other Approaches(1)
