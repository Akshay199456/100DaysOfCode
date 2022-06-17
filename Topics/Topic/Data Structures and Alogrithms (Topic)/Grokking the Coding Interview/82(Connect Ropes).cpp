/*
Problem statement:

Given ‘N’ ropes with different lengths, we need to connect these ropes into one big rope with minimum cost. The cost of connecting two ropes is equal to the sum of their lengths.

Example 1:

Input: [1, 3, 11, 5]
Output: 33
Explanation: First connect 1+3(=4), then 4+5(=9), and then 9+11(=20). So the total cost is 33 (4+9+20)
Example 2:

Input: [3, 4, 5, 6]
Output: 36
Explanation: First connect 3+4(=7), then 5+6(=11), 7+11(=18). Total cost is 36 (7+11+18)
Example 3:

Input: [1, 3, 11, 5, 2]
Output: 42
Explanation: First connect 1+2(=3), then 3+3(=6), 6+5(=11), 11+11(=22). Total cost is 42 (3+6+11+22)
*/

/*
-------------------------    My Approaches:
1. Top K elements

    We can use thee top k elements pattern here as well., in this problem we use a min heap
    to store the elements. first, we make a min heap of all the elements in the array. this is important
    as we want to get eh samallest elements and connect them first and keep that process going as the toal cost is only
    ,minimized if we join the ropes of least length together.

    Time complexity: O(nlogn)
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
following a greedy approach to connect the smallest ropes first will ensure the lowerst cost. 
can use a min heap to find the smallest ropes fopllowing a similar approach as docussed in kth smallest number.
once we connect 2 ropes, we need to inser the resultant rope back in the min heap so that we can connect it with the remaining ropes

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

// comparator function to make min heap 
struct greaters{ 
  bool operator()(const int& a,const int& b) const{ 
    return a>b; 
  } 
}; 

class ConnectRopes {
 public:
  static void printList(vector<int> list){
    cout<<"printing list "<<endl;
    for(int i=0; i< list.size(); i++){
      cout<<list[i]<<" ";
    }
    cout<<endl;
  }

  static void getMinCost(const vector<int> &ropeLengths, int & result){
    vector<int> pq(ropeLengths);
    int totalCost = 0;
    make_heap(pq.begin(), pq.end(), greaters());
    // printList(pq);

    while(pq.size() > 1){
      int cost  = 0, count = 0;
      // get min two elements and their cost
      while(count++ < 2){
        pop_heap(pq.begin(), pq.end(), greaters());
        // cout<<"back element: "<<pq.back()<<endl;
        cost += pq.back();
        // cout<<"cost: "<<cost<<endl;
        pq.pop_back();
      }

      totalCost += cost;
      // cout<<"total cost: "<<totalCost<<endl;

      // push cost of those two elements into the heap
      pq.push_back(cost);
      push_heap(pq.begin(), pq.end(), greaters());
    }

    result = totalCost;
  }

  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    int result = 0;
    // TODO: Write your code here
    if(ropeLengths.size() == 1)
      return ropeLengths[0];
    else if(ropeLengths.size())
      getMinCost(ropeLengths, result);
    return result;
  }
};

int main(int argc, char *argv[]) {
  int result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
 public:
  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // add all ropes to the min heap
    for (int i = 0; i < ropeLengths.size(); i++) {
      minHeap.push(ropeLengths[i]);
    }

    // go through the values of the heap, in each step take top (lowest) rope lengths from the min
    // heap connect them and push the result back to the min heap. keep doing this until the heap is
    // left with only one rope
    int result = 0, temp = 0;
    while (minHeap.size() > 1) {
      temp = minHeap.top();
      minHeap.pop();
      temp += minHeap.top();
      minHeap.pop();
      result += temp;
      minHeap.push(temp);
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  int result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}
