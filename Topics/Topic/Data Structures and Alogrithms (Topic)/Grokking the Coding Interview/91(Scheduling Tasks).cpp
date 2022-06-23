/*
Problem statement:

ou are given a list of tasks that need to be run, in any order, on a server. Each task will take one CPU interval to execute but once a task has finished, it has a cooling period during which it can’t be run again. If the cooling period for all tasks is ‘K’ intervals, find the minimum number of CPU intervals that the server needs to finish all tasks.

If at any time the server can’t execute any task then it must stay idle.

Example 1:

Input: [a, a, a, b, c, c], K=2
Output: 7
Explanation: a -> c -> b -> a -> c -> idle -> a
Example 2:

Input: [a, b, a], K=3
Output: 5
Explanation: a -> b -> idle -> idle -> a
*/

/*
-------------------------    My Approaches:
1. top k elements pattern

  we can applt the top k elements pattern here in exactly the same way we applied it to
  pb 90. there is alsmot no diffrenece between these two approaches.


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


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduler {
 public:
  static void createMap(vector<char> &tasks, unordered_map<char,int> & taskCount){
    for(char ele: tasks)
      taskCount[ele]++;
  }

  static void createHeap(unordered_map<char,int> & taskCount, priority_queue<pair<int,char>> & pq){
    for(auto it = taskCount.begin(); it!= taskCount.end(); it++)
      pq.push(make_pair(it->second,it->first));
  }

  static void arrangeTasks(priority_queue<pair<int,char>> & pq, int k, int & intervalCount){
    int count = 0;
    queue<tuple<char,int,int>> waitList;

    while(!waitList.empty() || !pq.empty()){
      bool isSkip = false;
      if(!waitList.empty()){
        tuple<char,int,int> tuplePair = waitList.front();
        if(get<2>(tuplePair) + k + 1 == count){
          pq.push(make_pair(get<1>(tuplePair), get<0>(tuplePair)));
          waitList.pop();
        }
        else if((get<2>(tuplePair) + k + 1 > count) && pq.empty()){
          isSkip = true;
          ++count;
        }
      }

      if(!isSkip){
        pair<int, char> currentEntry = pq.top();
        pq.pop();
        if(currentEntry.first > 1)
          waitList.push(make_tuple(currentEntry.second, currentEntry.first-1, count));
        count+=1;
      }
    }

    intervalCount = count;
  }

  static int scheduleTasks(vector<char> &tasks, int k) {
    int intervalCount = 0;
    // TODO: Write your code here
    if(!k || !tasks.size())
      return tasks.size();
      
    unordered_map<char,int> taskCount;
    priority_queue<pair<int,char>> pq;
    createMap(tasks, taskCount);
    createHeap(taskCount, pq);
    arrangeTasks(pq, k, intervalCount);
    return intervalCount;
  }
};

int main(int argc, char *argv[]) {
  vector<char> tasks = {'a'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 0) << endl;

  tasks = vector<char>{'a', 'b', 'a'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 1) << endl;
}




//  Other Approaches(1)
