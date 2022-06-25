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
follows k way merge pattern and ca be easily converted to kth samllest number in m sorted lists problem. as each row(or column) of the given matrix
can be seen as a sorted list, we essentially need to find the kth smallest number in n sorted lists

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
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInSortedMatrix {
 public:
  struct numCompare {
    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }
  };

  static int findKthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare>
        minHeap;

    // put the 1st element of each row in the min heap
    // we don't need to push more than 'k' elements in the heap
    for (int i = 0; i < n && i < k; i++) {
      minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
    }

    // take the smallest element form the min heap, if the running count is equal to k return the
    // number if the row of the top element has more elements, add the next element to the heap
    int numberCount = 0, result = 0;
    while (!minHeap.empty()) {
      auto heapTop = minHeap.top();
      minHeap.pop();
      result = heapTop.first;
      if (++numberCount == k) {
        break;
      }

      heapTop.second.second++;
      if (n > heapTop.second.second) {
        heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
        minHeap.push(heapTop);
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix2 = {vector<int>{2, 6, 8}, vector<int>{3, 7, 10},
                                 vector<int>{5, 8, 11}};
  int result = KthSmallestInSortedMatrix::findKthSmallest(matrix2, 5);
  cout << "Kth smallest number is: " << result << endl;
}