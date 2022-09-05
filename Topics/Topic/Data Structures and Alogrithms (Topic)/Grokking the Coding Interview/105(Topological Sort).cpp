/*
Problem statement:

Topological Sort of a directed graph (a graph with unidirectional edges) is a linear ordering of its vertices such that for every directed edge (U, V) from vertex U to vertex V, U comes before V in the ordering.

Given a directed graph, find the topological ordering of its vertices.

Example 1:

Input: Vertices=4, Edges=[3, 2], [3, 0], [2, 0], [2, 1]
Output: Following are the two valid topological sorts for the given graph:
1) 3, 2, 0, 1
2) 3, 2, 1, 0
    3   
    2   
    0   
    1   
Example 2:

Input: Vertices=5, Edges=[4, 2], [4, 3], [2, 0], [2, 1], [3, 1]
Output: Following are all valid topological sorts for the given graph:
1) 4, 2, 3, 0, 1
2) 4, 3, 2, 0, 1
3) 4, 3, 2, 1, 0
4) 4, 2, 3, 1, 0
5) 4, 2, 0, 3, 1
    4   
    2   
    3   
    0   
    1   
Example 3:

Input: Vertices=7, Edges=[6, 4], [6, 2], [5, 3], [5, 4], [3, 0], [3, 1], [3, 2], [4, 1]
Output: Following are all valid topological sorts for the given graph:
1) 5, 6, 3, 4, 0, 1, 2
2) 6, 5, 3, 4, 0, 1, 2
3) 5, 6, 4, 3, 0, 2, 1
4) 6, 5, 4, 3, 0, 1, 2
5) 5, 6, 3, 4, 0, 2, 1
6) 5, 6, 3, 4, 1, 2, 0

There are other valid topological ordering of the graph too.
    6   
    4   
    2   
*/

/*
-------------------------    My Approaches:
1. topological sort

    we use the base topological osrt alogirhtm here in order to get hte right order of the nodes

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


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <queue>

class TopologicalSort {
 public:
  static void createGraph(unordered_map<int, vector<int>> & graph, int vertices, const vector<vector<int>>& edges){
    vector<int> list;
    // initialize all vertices to empty list
    for(int i=0; i < vertices; i++){
      graph[i] = list;
    }

    // iniitlaize graph to its edges
    for(int i=0; i< edges.size(); i++){
      vector<int> list = edges[i];
      graph[list[0]].push_back(list[1]);
    }
  }

  static void getParents(unordered_map<int, vector<int>> & graph, unordered_map<int, int> & parentCount){
    // initialze parents for all vertices to 0
    for(auto it = graph.begin(); it!=graph.end(); it++){
      parentCount[it->first] = 0;
    }

    // get parents for each node
    for(auto it = graph.begin(); it!= graph.end(); it++){
      vector<int> list = it->second;
      for(int i=0; i< list.size(); i++){
        parentCount[list[i]] += 1;
      }
    }
  }

  static vector<int> topSort(unordered_map<int, vector<int>> & graph, unordered_map<int, int> & parentCount){
    queue<int> elementQueue;
    vector<int> result;
    
    // push nodes iwht parent = 0
    for(auto it = parentCount.begin(); it!= parentCount.end(); it++){
      if(!it->second){
        elementQueue.push(it->first);
      }
    }

    // full rest of the queue
    while(!elementQueue.empty()){
      int topElement = elementQueue.front();
      result.push_back(topElement);

      // remove parent count from topElement since it has been considered
      vector<int> list = graph[topElement];
      for(int i=0; i< list.size(); i++){
        parentCount[list[i]] -= 1;
        if(!parentCount[list[i]])
          elementQueue.push(list[i]);
      }
      elementQueue.pop();
    }
    return result;
  }


  static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
    vector<int> sortedOrder;
    vector<int> list;
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> parentCount;

    createGraph(graph, vertices, edges);
    getParents(graph, parentCount);
    sortedOrder = topSort(graph, parentCount);
    // TODO: Write your code here
    if(sortedOrder.size() == graph.size())
      return sortedOrder;
    else
      return list;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result =
      TopologicalSort::sort(2, vector<vector<int>>{vector<int>{1,0}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopologicalSort::sort(
      5, vector<vector<int>>{vector<int>{4, 2}, vector<int>{4, 3}, vector<int>{2, 0},
                             vector<int>{2, 1}, vector<int>{3, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopologicalSort::sort(
      7, vector<vector<int>>{vector<int>{6, 4}, vector<int>{6, 2}, vector<int>{5, 3},
                             vector<int>{5, 4}, vector<int>{3, 0}, vector<int>{3, 1},
                             vector<int>{3, 2}, vector<int>{4, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}



//  Other Approaches(1)
