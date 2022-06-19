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


    Time complexity: O()
    Space complexity: O()
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
