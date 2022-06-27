/*
Problem statement:

Given two sorted arrays in descending order, find ‘K’ pairs with the largest sum where each pair consists of numbers from both the arrays.

Example 1:

Input: L1=[9, 8, 2], L2=[6, 3, 1], K=3
Output: [9, 3], [9, 6], [8, 6] 
Explanation: These 3 pairs have the largest sum. No other pair has a sum larger than any of these.
Example 2:

Input: L1=[5, 2, 1], L2=[2, -1], K=3
Output: [5, 2], [5, -1], [2, 2] 
*/

/*
-------------------------    My Approaches:
1. using max heap to store sum by going through all elementsof all arrays [not coded]

    we can use a double for loop to go through all of th eelements in the arrays and push therir sum into a max heap. we later retireve k pairs from it


    Time complexity: O(mn logmn)
    Space complexity: O(mn)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
problem follows k way merge pattern and we can follow a similar approach as dicussed in merge k dosrted lists

can go through all the numbers of the two input arrays to create pairs and initially insert them all in the heap until we have 'k' pairs in min-heap. after that, if a pair is bigger than the 
top(smallest pair) in the heap, we can remove the smallest pair and inser this pair in the heap.

can optimize the algorithm in 2 ways:

1. instead of iterating over all the numbers of both arrays, can iterate only the first 'k' numbers from both arrays. since the arrays are sorted in descendig order, the pairs with max sum will be
consituted by the first k numbers from both the arrays.
2. as soon as we encounter a pair with a sum that is smaller than the smallest)top) element of the heap, we done need to process the next elements of the array.
since the arrays are sorted in descending order, we wont be able to find a pair with a higher sum moving forward.

    Time complexity: O()
    Space complexity: O()


Addditional notes:

as data has suggested, in most situations whenever we give up, we are usually in the right path for solving the problem and just have a little bit to 
cover. in this problem we had the same case as well. if you look at my approaches(1) which i didnt code, it was the exact same appraoch as they had suggested.
the only difference was the optimization of using a min heap and stopping when you get a sum less than the top of the heap. but the rest of the appraoch was the same.

the moral of the story: more often than not, whenever wyou feel like giving up on a problem, you already have cpme up with a proper approach to the problem and just need to optimize the approach a bit.

*/



//  My approaches(1)



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class LargestPairs {
 public:
  struct sumCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.first + x.second > y.first + y.second;
    }
  };

  static vector<pair<int, int>> findKLargestPairs(const vector<int> &nums1,
                                                  const vector<int> &nums2, int k) {
    vector<pair<int, int>> minHeap;
    for (int i = 0; i < nums1.size() && i < k; i++) {
      for (int j = 0; j < nums2.size() && j < k; j++) {
        if (minHeap.size() < k) {
          minHeap.push_back(make_pair(nums1[i], nums2[j]));
          push_heap(minHeap.begin(), minHeap.end(), sumCompare());
        } else {
          // if the sum of the two numbers from the two arrays is smaller than the smallest (top)
          // element of the heap, we can 'break' here. Since the arrays are sorted in the descending
          // order, we'll not be able to find a pair with a higher sum moving forward.
          if (nums1[i] + nums2[j] < minHeap.front().first + minHeap.front().second) {
            break;
          } else {  // else: we have a pair with a larger sum, remove top and insert this pair in
                    // the heap
            pop_heap(minHeap.begin(), minHeap.end(), sumCompare());
            minHeap.pop_back();
            minHeap.push_back(make_pair(nums1[i], nums2[j]));
            push_heap(minHeap.begin(), minHeap.end(), sumCompare());
          }
        }
      }
    }
    return minHeap;
  }
};

int main(int argc, char *argv[]) {
  auto result = LargestPairs::findKLargestPairs({9, 8, 2}, {6, 3, 1}, 3);
  cout << "Pairs with largest sum are: ";
  for (auto pair : result) {
    cout << "[" << pair.first << ", " << pair.second << "] ";
  }
}
