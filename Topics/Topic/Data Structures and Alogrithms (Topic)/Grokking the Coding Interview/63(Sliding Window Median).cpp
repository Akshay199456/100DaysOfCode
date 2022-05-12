/*
Problem statement:


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
