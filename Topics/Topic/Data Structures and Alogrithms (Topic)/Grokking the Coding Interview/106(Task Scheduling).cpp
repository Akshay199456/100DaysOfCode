/*
Problem statement:

here are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite tasks which need to be completed before it can be scheduled. Given the number of tasks and a list of prerequisite pairs, find out if it is possible to schedule all the tasks.

Example 1:

Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
Output: true
Explanation: To execute task '1', task '0' needs to finish first. Similarly, task '1' needs 
to finish before '2' can be scheduled. One possible scheduling of tasks is: [0, 1, 2] 
Example 2:

Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
Output: false
Explanation: The tasks have a cyclic dependency, therefore they cannot be scheduled.
Example 3:

Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
Output: true
Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5] 
*/

/*
-------------------------    My Approaches:
1. Topological sort

    we can use the basic topological sort algoirthm in order to solve the problem. since this problem will fail if there are cycles, at the end of the topological sort, we just need to compare the result
    and the graph in order to see if all the eemements are in th eresult. if not, we then know there is a graph. if there is a grpah, we retn flase, esle we return true./

    Time complexity: O(v+e)
    Space complexity: O(v+e)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
this problem is asking us to find out f it is possible to find a topolgoical ordering f the given tasks. the tasks are equivalent to the vertices and the prerequisites are the edges.

we can use a similar algorithm as described in topological osrt to find the topolgical ordering of the tasks. if the ordering does not include all the taks, we weill conlcude that some tasks have
cyclic dependencies.


    Time complexity: O(v+e)
    Space complexity: O(v+e)
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <queue>

class TaskScheduling {
 public:
  static void createGraph(int tasks, const vector<vector<int>>& prerequisites, unordered_map<int, vector<int>> & graph){
    vector<int> list;

    // iniitlaize each node to emptu list
    for(int i=0; i < tasks; i++){
      graph[i] = list;
    }

    // initialze graph to prerequisities
    for(int i=0; i< prerequisites.size(); i++){
      list = prerequisites[i];
      graph[list[0]].push_back(list[1]);
    }
  }

  static void getParentCount(unordered_map<int, vector<int>> & graph, unordered_map<int,int> & parentCount, int tasks){
    // iniitialzie each parent to 0
    for(int i=0; i< tasks; i++){
      parentCount[i] = 0;
    } 

    // get parent count
    for(int i=0; i< graph.size(); i++){
      vector<int> list = graph[i];
      for(int j=0; j< list.size(); j++){
        parentCount[list[j]] += 1;
      }
    }
  }

  static vector<int> getTopSort(unordered_map<int,int> & parentCount, unordered_map<int, vector<int>> & graph){
    queue<int> elementQueue;
    vector<int> result;

    // add all nodes with parent count = 0
    for(auto it = parentCount.begin(); it!= parentCount.end(); it++){
      if(!it->second){
        elementQueue.push(it->first);
      }
    }

    // insert other elements into queue
    while(!elementQueue.empty()){
      int topElement = elementQueue.front();
      result.push_back(topElement);
      elementQueue.pop();
      vector<int> list = graph[topElement];
      for(int i=0; i< list.size(); i++){
        parentCount[list[i]] -= 1;
        if(!parentCount[list[i]]){
          elementQueue.push(list[i]);
        }
      }
    }

    return result;
  }

  static bool isSchedulingPossible(int tasks, const vector<vector<int>>& prerequisites) {
    // TODO: Write your code here    
    unordered_map<int, vector<int>> graph;
    unordered_map<int,int> parentCount;

    createGraph(tasks, prerequisites, graph);
    getParentCount(graph, parentCount, tasks);
    vector<int> list = getTopSort(parentCount, graph);

    return list.size() == graph.size();
  }
};

int main(int argc, char* argv[]) {
  bool result = TaskScheduling::isSchedulingPossible(
      2, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 0}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
                             vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
  cout << "Tasks execution possible: " << result << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduling {
 public:
  static bool isSchedulingPossible(int tasks, const vector<vector<int>>& prerequisites) {
    vector<int> sortedOrder;
    if (tasks <= 0) {
      return false;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (int i = 0; i < tasks; i++) {
      inDegree[i] = 0;
      graph[i] = vector<int>();
    }

    // b. Build the graph
    for (int i = 0; i < prerequisites.size(); i++) {
      int parent = prerequisites[i][0], child = prerequisites[i][1];
      graph[parent].push_back(child);  // put the child into it's parent's list
      inDegree[child]++;               // increment child's inDegree
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    queue<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
    while (!sources.empty()) {
      int vertex = sources.front();
      sources.pop();
      sortedOrder.push_back(vertex);
      vector<int> children =
          graph[vertex];  // get the node's children to decrement their in-degrees
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    // if sortedOrder doesn't contain all tasks, there is a cyclic dependency between tasks,
    // therefore, we will not be able to schedule all tasks
    return sortedOrder.size() == tasks;
  }
};

int main(int argc, char* argv[]) {
  bool result = TaskScheduling::isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
                             vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
  cout << "Tasks execution possible: " << result << endl;
}
