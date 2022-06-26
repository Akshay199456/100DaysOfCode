/*
Problem statement:

Given ‘M’ sorted arrays, find the smallest range that includes at least one number from each of the ‘M’ lists.

Example 1:

Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
Output: [4, 7]
Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
Example 2:

Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
Output: [9, 12]
Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3.
*/

/*
-------------------------    My Approaches:
1. k way merge [not coded]

    we can use the k way merge pattern in order to create a list of all the elemnts in the arrays in theire sorted order. once we have that list,
    we can then use the two pointer technique to go through the intervals and see if we have a number in each of the lists within that interval.
    using the two pointer approach then would solve this problem

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.k way merge pattern

so the way they coded this approach is pretty sommeth. for the loop condition, the size of the heap must always be equal to the ist size. if it is not, we then know that one of the lists has exceeded all its elements
and that means all the elements from that list have been considered and hence any solution from that stage onwards will ot be a comprehensive solution.

also the reason this approach works is because at all times, since our heap size is equal to the list size, all the elements in the heap
are basically one elment from each of the list. as a result, we are considering all the lists at each and every moment, and so the solution that we otain
covres all the arrays we are interested in which gives us a valid solution. 

we always keep track of the max element we have pushed inside the heap as the difference between it and hte minimum elemtn of the heap at any moment gives us 
a range that we are interested in. the other reason this works is because, the minimum element is only form one elemnt of the list. and there are going to be atleast k-1 other elemnts form the list
corresponding to the k-1 lists. so if we have the differenfce bettween the max and min element correpsonding to the ement form one list, it will cover every other ekment from all the other lists
since their values will be greater than the minimum elmeent. that is why we use a min hepa.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
follows k way merge pattern and can follow a similar approach as dicussed in mrge k sorted lists.

can start by inserting the first number from all the arrays in a min-heap. will keep track of the largest number that we have inserted in the heap (lets call it currentMaxNumber)

in a loop, we will take the smallest(top) element from the min-heap and currentMAxNumber has the largest element that we inserted in the heap. if these two numbers give us a smaller range, we will update our range.
finally, if the array of the top element has more elements, we will inser the next element to the heap.

can finish searching the minimum range as soon as an array is completed or, in other terms, the heap has less than 'm' elements.

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

class SmallestRange {
 public:
  struct valueCompare {
    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }
  };

  static pair<int, int> findSmallestRange(const vector<vector<int>> &lists) {
    // we will store the actual number, list index and element index in the heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare>
        minHeap;

    int rangeStart = 0, rangeEnd = numeric_limits<int>::max(),
        currentMaxNumber = numeric_limits<int>::min();
    // put the 1st element of each array in the min heap
    for (int i = 0; i < lists.size(); i++) {
      if (!lists[i].empty()) {
        minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
        currentMaxNumber = max(currentMaxNumber, lists[i][0]);
      }
    }

    // take the smallest (top) element form the min heap, if it gives us smaller range, update the
    // ranges if the array of the top element has more elements, insert the next element in the heap
    while (minHeap.size() == lists.size()) {
      auto node = minHeap.top();
      minHeap.pop();
      if (rangeEnd - rangeStart > currentMaxNumber - node.first) {
        rangeStart = node.first;
        rangeEnd = currentMaxNumber;
      }
      node.second.second++;
      if (lists[node.second.first].size() > node.second.second) {
        node.first = lists[node.second.first][node.second.second];
        minHeap.push(node);  // insert the next element in the heap
        currentMaxNumber = max(currentMaxNumber, node.first);
      }
    }

    return make_pair(rangeStart, rangeEnd);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{1, 5, 8}, {4, 12}, {7, 8, 10}};
  auto result = SmallestRange::findSmallestRange(lists);
  cout << "Smallest range is: [" << result.first << ", " << result.second << "]";
}
