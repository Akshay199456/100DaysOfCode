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



Alternate solution

we are given that each row and column of the matrix sorted, so it might be possible to use binary search to find th ekth smalelst number.

biggest proble to use binary search, in this case, is that we dont have a straighforward sorted array, instead we have a mat5rix. in binary search,
we calculate the middle index of the search space('1' to 'n') and see if our required number is pointed out by the middle index; if not we either search in the lower half or the upper half.
in a sorted matrix, we can't really find a middle. even if we do consider some index as middle, it is not straightforward to find the search space containing numbers bigger or smaller than the number pointed out
bu the middle index.

an alternative could be to apply the binary search on the 'number range' instead of the 'index range' as we know that the smallest number of our matrix
is at the top left corner and the biggest number is at the bottom right corner. these two numbers can represent the 'range' i.e the start and the 
end for the bonary search. here is how our algorithm will work:
    1. start the binary search with start = matrix[0][0] and end = matrix[n-1][n-1].
    2. find middle of the start and the end. this middle number is not necesarily an element in the matrix.
    3. count all the numbers smaller than or equal to middle in the matrix. as the matrix is sorte,d we can do this in O(n).
    4. while counting,m we can keep track of the 'smallest number greater than the middl;e'(lets call it n1) and at the same time 'the biggest number less than or equal to the middle'(lets call it n2). these two numbers will be used to adjust the
    'number range' for the binary search in the next iteration.
    5. if the count is equal to 'k', n2 will be our required number as it is the 'biggest number less than or equal to the middle' and is definitely present in the matrix.
    6. if the count is less than 'k', we can update start = n2 to search in the higheer part of the matrix and if the count is greater than 'k', we can update end = n1 to search in the lower part of the matrix in the next iteration.

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



// Other Approaches(2)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInSortedMatrix {
 public:
  static int findKthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int start = matrix[0][0], end = matrix[n - 1][n - 1];
    while (start < end) {
      int mid = start + (end - start) / 2;
      // first number is the smallest and the second number is the largest
      pair<int, int> smallLargePair = {matrix[0][0], matrix[n - 1][n - 1]};
      int count = countLessEqual(matrix, mid, smallLargePair);
      if (count == k) {
        return smallLargePair.first;
      }

      if (count < k) {
        start = smallLargePair.second;  // search higher
      } else {
        end = smallLargePair.first;  // search lower
      }
    }

    return start;
  }

 private:
  static int countLessEqual(vector<vector<int>> &matrix, int mid, pair<int, int> &smallLargePair) {
    int count = 0;
    int n = matrix.size(), row = n - 1, col = 0;
    while (row >= 0 && col < n) {
      if (matrix[row][col] > mid) {
        // as matrix[row][col] is bigger than the mid, let's keep track of the
        // smallest number greater than the mid
        smallLargePair.second = min(smallLargePair.second, matrix[row][col]);
        row--;
      } else {
        // as matrix[row][col] is less than or equal to the mid, let's keep track of the
        // biggest number less than or equal to the mid
        smallLargePair.first = max(smallLargePair.first, matrix[row][col]);
        count += row + 1;
        col++;
      }
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix2 = {vector<int>{2, 6, 8}, vector<int>{3, 7, 10},
                                 vector<int>{5, 8, 11}};
  int result = KthSmallestInSortedMatrix::findKthSmallest(matrix2, 5);
  cout << "Kth smallest number is: " << result << endl;
}
