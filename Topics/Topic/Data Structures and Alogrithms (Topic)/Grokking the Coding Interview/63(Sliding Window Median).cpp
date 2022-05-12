/*
Problem statement:


*/

/*
-------------------------    My Approaches:
1. 2 heaps pattern

    we used the 2 heaps pattern in order to solve the problem. a max heap and a amin heap.
    since we wanted to find the sliding window median, well we wanted some way to keep 
    hold to the mid of tghe sldiwing window and one way to do that is to use a 2 heap
    strucutre to divide the elements into two parts. this is where the 2 heaps pattern
    is most helpful.

    balancing the heap strucutre is very important as we are going along when we are 
    tryinmg to insert elements or ppiiing off elements. 

    when the sum of the sizes of the heap is less than k,we have still not achieved the full
    window so we jkeep adding elements into the proper heap and blaance them as needed.

    once the heapsizes sum is equal to k, we then get eh median from the heap which is already
    balanced. we then pop off elements from the heap depending on where the element is
    and then balance the heap again.

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

class SlidingWindowMedian {
 public:
  void balanceHeaps(priority_queue<int> & maxHeap, priority_queue<int, vector<int>, greater<int>> & minHeap){
    if(maxHeap.size() > 1+ minHeap.size()){
      // cout<<"Balancing heap: pushing "<<maxHeap.top()<<" into minHeap"<<endl;
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
    else if(minHeap.size() > maxHeap.size()){
      // cout<<"Balancing heap: pushing "<<minHeap.top()<<" into maxHeap"<<endl;
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  void getSlidingMedian(const vector<int> & nums, int k, vector<double> & result){
    int beg = 0, end = 0, count = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    while(end < nums.size()){
      if(minHeap.size() < k - maxHeap.size()){
        // insert nums[end] into the proper heap
        if(maxHeap.empty() || nums[end] < maxHeap.top()){
          // cout<<"Inserting: pushing "<<nums[end]<<" into maxHeap"<<endl;
          maxHeap.push(nums[end]);
        }
        else{
          // cout<<"Inserting: pushing "<<nums[end]<<" into minHeap"<<endl;
          minHeap.push(nums[end]);
        }
        end+=1;

        // balance the heaps
        balanceHeaps(maxHeap, minHeap);
      }

      if(minHeap.size() == k - maxHeap.size()){
        // get median and insert it
        if((maxHeap.size() + minHeap.size()) % 2 != 0)
          result[count++] = maxHeap.top();
        else
          result[count++] = (((double)(maxHeap.top() + minHeap.top()))/ 2);

        // cout<<"Stable:median inserted value:"<<result[result.size()-1]<<endl;
        // pop off nums[beg] from the right heap
        if(nums[beg] <= maxHeap.top()){
          // cout<<"Popping out numbers from maxHeap"<<endl;
          while(nums[beg] != maxHeap.top()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
          }
          maxHeap.pop();
        }
        else{
          // cout<<"Popping out numbers from minHeap"<<endl;
          while(nums[beg] != minHeap.top()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
          }
          minHeap.pop();
        }

        beg+=1;

        //balance heaps
        balanceHeaps(maxHeap, minHeap);
      }
    }
  }

  virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
    vector<double> result(nums.size() - k + 1);
    // TODO: Write your code here
    if(nums.size() >= k)
      getSlidingMedian(nums, k, result);
    return result;
  }
};

int main(int argc, char *argv[]) {
  SlidingWindowMedian slidingWindowMedian;
  vector<double> result =
      slidingWindowMedian.findSlidingWindowMedian(vector<int>{1}, 4);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  slidingWindowMedian = SlidingWindowMedian();
  result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}





//  Other Approaches(1)
using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

// extending priority_queue to implement 'remove'
template <typename T, class Container = vector<T>,
          class Compare = less<typename Container::value_type>>
class priority_queue_with_remove : public priority_queue<T, Container, Compare> {
 public:
  bool remove(const T &valueToRemove) {
    auto itr = std::find(this->c.begin(), this->c.end(), valueToRemove);
    if (itr == this->c.end()) {
      return false;
    }
    this->c.erase(itr);
    // ideally we should not be rebuilding the heap as we are removing only one element
    // a custom implementation of priority queue can adjust only one element in O(logN)
    std::make_heap(this->c.begin(), this->c.end(), this->comp);
    return true;
  }
};

class SlidingWindowMedian {
 public:
  priority_queue_with_remove<int> maxHeap;
  priority_queue_with_remove<int, vector<int>, greater<int>> minHeap;

  virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
    vector<double> result(nums.size() - k + 1);
    for (int i = 0; i < nums.size(); i++) {
      if (maxHeap.size() == 0 || maxHeap.top() >= nums[i]) {
        maxHeap.push(nums[i]);
      } else {
        minHeap.push(nums[i]);
      }
      rebalanceHeaps();

      if (i - k + 1 >= 0) {  // if we have at least 'k' elements in the sliding window
        // add the median to the the result array
        if (maxHeap.size() == minHeap.size()) {
          // we have even number of elements, take the average of middle two elements
          result[i - k + 1] = maxHeap.top() / 2.0 + minHeap.top() / 2.0;
        } else {  // because max-heap will have one more element than the min-heap
          result[i - k + 1] = maxHeap.top();
        }

        // remove the element going out of the sliding window
        int elementToBeRemoved = nums[i - k + 1];
        if (elementToBeRemoved <= maxHeap.top()) {
          maxHeap.remove(elementToBeRemoved);
        } else {
          minHeap.remove(elementToBeRemoved);
        }
        rebalanceHeaps();
      }
    }
    return result;
  }

 private:
  void rebalanceHeaps() {
    // either both the heaps will have equal number of elements or max-heap will have
    // one more element than the min-heap
    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    } else if (maxHeap.size() < minHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }
};

int main(int argc, char *argv[]) {
  SlidingWindowMedian slidingWindowMedian;
  vector<double> result =
      slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 2);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  slidingWindowMedian = SlidingWindowMedian();
  result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}
