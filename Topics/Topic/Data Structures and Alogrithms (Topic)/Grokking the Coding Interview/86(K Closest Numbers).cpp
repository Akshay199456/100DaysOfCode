/*
Problem statement:

Given a sorted number array and two integers ‘K’ and ‘X’, find ‘K’ closest numbers to ‘X’ in the array. Return the numbers in the sorted order. ‘X’ is not necessarily present in the array.

Example 1:

Input: [5, 6, 7, 8, 9], K = 3, X = 7
Output: [6, 7, 8]
Example 2:

Input: [2, 4, 5, 6, 9], K = 3, X = 6
Output: [4, 5, 6]
Example 3:

Input: [2, 4, 5, 6, 9], K = 3, X = 10
Output: [5, 6, 9]
*/

/*
-------------------------    My Approaches:
1. Top k elements pattern

    we can apply the top k elements paatern here in order to solve the problem. since we 
    are looking for the closesnt difference, what we want to make use of is a ax heap
    (max heap of specific size is great for optimizing space for problems that realte to minimizing result as compared to min heap of full size; 
    min heap of specific size is great for optimizing space for problems that realte to maximing result as compared to max heap of full size).
    we then insert tkements into the max heap dependong ion ht diffrentrce between the element and X.
    if we find an element with a much smaller difference, we pop off the top and insert this
    new elemnt into the heap

    at the end, we have a heap which contains the k elements which are closest with the one hacing max diffrence at the top and the one haveing
    min difference at the bottom. we can then push that into an arrya and sort it to get the numbers in sorted order.

    Time complexity: O(n + k + klogk) = O(n) + O(klogk)
    Space complexity: O(k)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
problem follows the top k numbers pattern. biggest difference in this problem is that we need to
find the closes(to 'X') numbers compared to f7nding the overall largest numbers. another diff is that given array is sorted.

utilizing similar approach, can find the numbers closest to 'x' through following algorithm:
1. since array sorted, can first find the number closest to 'x' through binary search. lets say that number is 'Y'.
2. The 'k' closest numbers to 'Y' will be adjacent to 'T' in the array. can search in both directions of 'y' to find the closest numbers
3. can use a heap to efficiently search for closest numbers. will take 'k' numbers in both directions of 'y' and push them in min heap
sorted by absolute difference from 'x'. this will ensure that the numbers with smallest difference from 'x' (i.e closest to 'x') cna be extracted easily
from min heap.
4. findally, will extract the top k numbers from the min heap to find the required numbers.

    Time complexity: O(log n + klogk)
    Space complexity: O(k)


Comparing my apporac against theirs, they are almost very similar. however, since hte arrya is sorted, they have made use of binary search to find the element that is closest to X
and then use that to get K elements on its left and right as the answer has to lie between that and cannot be outside of that which is a prtty efficient way to think about it.

another improvied approach they used was the two pointers after the binary search which also is a good approach.
*/



//  My approaches(1)
using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KClosestElements {
 public:
  struct numCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { 
      if(x.first == y.first)
        return x.second > y.second;
      return x.first < y.first; 
      }
  };

  static void getClosestElements(const vector<int> &arr, int K, int X, vector<int> & result){
    priority_queue<pair<int,int>, vector<pair<int,int>>, numCompare> pq;
    cout<<"Inserting elements into heap"<<endl;

    // insert elements into heap
    for(int i=0; i< arr.size(); i++){
      if(pq.size() < K)
        pq.push(make_pair(abs(arr[i] - X), arr[i]));
      else if(pq.top().first > abs(arr[i] - X)){
        pq.pop();
        pq.push(make_pair(abs(arr[i] - X), arr[i]));
      }
    }

    // // printing heap
    // cout<<"Printing heap"<<endl;
    // while(!pq.empty()){
    //   pair<int,int> p = pq.top();
    //   pq.pop();
    //   cout<<"Difference: "<< p.first<<" Element: "<<p.second<<endl;
    // }

    
    // push results into result array
    while(!pq.empty()){
      result.push_back(pq.top().second);
      pq.pop();
    }

    // reverse results as result array will have it in descending order
    sort(result.begin(), result.end());
  }

  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
    vector<int> result;
    // TODO: Write your code here
    if(K && arr.size() && arr.size() >= K)
      getClosestElements(arr, K, X, result);
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result = KClosestElements::findClosestElements(vector<int>{}, 3, -1);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 10);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}



//  Other Approaches(1)
using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KClosestElements {
 public:
  struct numCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; }
  };

  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
    int index = binarySearch(arr, X);
    int low = index - K, high = index + K;
    low = max(low, 0);                      // 'low' should not be less than zero
    high = min(high, (int)arr.size() - 1);  // 'high' should not be greater the size of the array

    priority_queue<pair<int, int>, vector<pair<int, int>>, numCompare> minHeap;
    // add all candidate elements to the min heap, sorted by their absolute difference from 'X'
    for (int i = low; i <= high; i++) {
      minHeap.push(make_pair(abs(arr[i] - X), i));
    }

    // we need the top 'K' elements having smallest difference from 'X'
    vector<int> result;
    for (int i = 0; i < K; i++) {
      result.push_back(arr[minHeap.top().second]);
      minHeap.pop();
    }

    sort(result.begin(), result.end());
    return result;
  }

 private:
  static int binarySearch(const vector<int> &arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) {
        return mid;
      }
      if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (low > 0) {
      return low - 1;
    }
    return low;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result = KClosestElements::findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}


// Other Approches(2)
using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class KClosestElements {
 public:
  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
    deque<int> result;
    int index = binarySearch(arr, X);
    int leftPointer = index;
    int rightPointer = index + 1;
    for (int i = 0; i < K; i++) {
      if (leftPointer >= 0 && rightPointer < (int)arr.size()) {
        int diff1 = abs(X - arr[leftPointer]);
        int diff2 = abs(X - arr[rightPointer]);
        if (diff1 <= diff2) {
          result.push_front(arr[leftPointer--]);  // append in the beginning
        } else {
          result.push_back(arr[rightPointer++]);  // append at the end
        }
      } else if (leftPointer >= 0) {
        result.push_front(arr[leftPointer--]);
      } else if (rightPointer < (int)arr.size()) {
        result.push_back(arr[rightPointer++]);
      }
    }
    vector<int> resultVec;
    std::move(std::begin(result), std::end(result), std::back_inserter(resultVec));
    return resultVec;
  }

 private:
  static int binarySearch(const vector<int> &arr, int target) {
    int low = 0;
    int high = (int)arr.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) {
        return mid;
      }
      if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (low > 0) {
      return low - 1;
    }
    return low;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result = KClosestElements::findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 10);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
