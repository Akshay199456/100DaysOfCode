/*
Problem statement:

Given an N * N
N∗N
 matrix where each row and column is sorted in ascending order, find the Kth smallest element in the matrix.

Example 1:

Input: Matrix=[
    [2, 6, 8], 
    [3, 7, 10],
    [5, 8, 11]
  ], 
  K=5
Output: 7
Explanation: The 5th smallest number in the matrix is 7.
*/

/*
-------------------------    My Approaches:
1. k way merge pattern

    we can apply the k wy merge pattern here similar to pb 93 and 94. we just keep moving along the rows as needed based on the condition.

    Time complexity: O(klogn)
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
#include <tuple>
#include <queue>
#include <vector>

class KthSmallestInSortedMatrix {
 public:
  static int getKSmallest(vector<vector<int>> &matrix, int k){
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;
    tuple<int,int,int> topPair;
    int count = 0;

    // insert first elements from each list into min heap
    for(int i=0; i< matrix.size(); i++){
      if(matrix[i].size())
        minHeap.push(make_tuple(matrix[i][0], i, 0));
    }

    while(count != k){
      topPair = minHeap.top();
      minHeap.pop();
      ++count;

      int elementIndex = get<2>(topPair);
      int listIndex = get<1>(topPair);
      if(elementIndex < matrix[listIndex].size()-1)
        minHeap.push(make_tuple(matrix[listIndex][elementIndex+1], listIndex, elementIndex+1));
    }
    return get<0>(topPair);
  }

  static int findKthSmallest(vector<vector<int>> &matrix, int k) {
    int result = -1;
    if(k<=0 || !matrix.size() || !matrix[0].size() || ((matrix.size() * matrix[0].size()) <k))
      return -1;
    return getKSmallest(matrix, k);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix2 = {vector<int>{1}};
  int result = KthSmallestInSortedMatrix::findKthSmallest(matrix2, 0);
  cout << "Kth smallest number is: " << result << endl;
}


//  Other Approaches(1)
