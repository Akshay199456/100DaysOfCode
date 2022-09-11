/*
Problem statement:

We are given an undirected graph that has characteristics of a k-ary tree. In such a graph, we can choose any node as the root to make a k-ary tree. The root (or the tree) with the minimum height will be called Minimum Height Tree (MHT). There can be multiple MHTs for a graph. In this problem, we need to find all those roots which give us MHTs. Write a method to find all MHTs of the given graph and return a list of their roots.

Example 1:

Input: vertices: 5, Edges: [[0, 1], [1, 2], [1, 3], [2, 4]]
Output:[1, 2]
Explanation: Choosing '1' or '2' as roots give us MHTs. In the below diagram, we can see that the 
height of the trees with roots '1' or '2' is three which is minimum.
    0   
    1   
    2   
    3   
    4   
    1   
    0   
    2   
    3   
    4   
    0   
    1   
    2   
    3   
    4   
    2   
    1   
    4   
    3   
    0   
    3   
    1   
    0   
    2   
    4   
    4   
    2   
    1   
    0   
    3   
 With '0' as the root  
 With '1' as the root  
 With '2' as the root  
 With '3' as the root  
 With '4' as the root  
 Given graph ==>  
 Height = 4  
 Height = 4  
 Height = 4  
 Height = 3  
 Height = 3  
Example 2:

Input: vertices: 4, Edges: [[0, 1], [0, 2], [2, 3]]
Output:[0, 2]
Explanation: Choosing '0' or '2' as roots give us MHTs. In the below diagram, we can see that the 
height of the trees with roots '0' or '2' is three which is minimum.
 With '0' as the root  
 With '1' as the root  
 With '2' as the root  
 With '3' as the root  
 Given graph ==>  
 Height = 4  
 Height = 4  
 Height = 3  
 Height = 3  
    0   
    1   
    2   
    3   
    1   
    0   
    2   
    3   
    2   
    0   
    3   
    1   
    3   
    2   
    0   
    1   
    0   
    1   
    2   
    3   
Example 3:

Input: vertices: 4, Edges: [[0, 1], [1, 2], [1, 3]]
Output:[1]s
*/

/*
-------------------------    My Approaches:
1. bfs approach

    we can use the bfs approach to solve this problem. since the graph in undirected, while creating the graph, we cadd the neighbors both ways. then we just need to run bfs from each vertex o get the height if the tree was to be created from that vertex. we then store the height for that vertex
    into a map. we do that for all the vertexes. we then look at the map to find the min hiehgt and get all the vertices with that as the hight and fill that into the result

    Time complexity: O(v*(v+e))
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

#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

class MinimumHeightTrees {
 public:
  static void createGraph(int nodes, vector<vector<int>>& edges, unordered_map<int, vector<int>> & graph){
    // initialize each vertex to empty list
    for(int i=0; i< nodes; i++){
      vector<int> list;
      graph[i] = list;
    }

    // add edges to graph
    for(int i=0; i< edges.size(); i++){
      vector<int> list = edges[i];
      graph[list[0]].emplace_back(list[1]);
      graph[list[1]].emplace_back(list[0]);
    }
  }

  static void getMinHeight(int nodes, unordered_map<int, vector<int>> & graph, unordered_map<int,int> & heightMap){
    // start tree at each node
    for(int i=0; i<nodes; i++){
      queue<pair<int,int>> elementQueue;
      vector<bool> visited(nodes, false);
      int maxHeight = 1;
      elementQueue.push(make_pair(i,1));

      while(!elementQueue.empty()){
        pair<int,int> topPair = elementQueue.front();
        int element = topPair.first, currHeight = topPair.second;
        elementQueue.pop();
        vector<int> neighbors = graph[element];

        if(currHeight > maxHeight)
          maxHeight = currHeight;

        for(int j=0; j< neighbors.size(); j++){
          if(visited[neighbors[j]] == false)
            elementQueue.push(make_pair(neighbors[j], currHeight+1));
        }

        // mark this node as visited
        visited[i] = true;
      }

      heightMap[i] = maxHeight;
    }
  }

  static vector<int> minTrees(unordered_map<int,int> & heightMap){
    int minHeight = numeric_limits<int>::max();
    vector<int> result;

    // get minHeight
    for(auto it= heightMap.begin(); it!= heightMap.end(); it++){
      if(it->second < minHeight)
        minHeight = it->second;
    }

    // fill min height
    for(auto it = heightMap.begin(); it!= heightMap.end(); it++){
      if(it->second == minHeight)
        result.push_back(it->first);
    }

    return result;
  }

  static vector<int> findTrees(int nodes, vector<vector<int>>& edges) {
    vector<int> minHeightTrees;
    unordered_map<int, vector<int>> graph;
    unordered_map<int,int> heightMap;
    // TODO: Write your code here
    createGraph(nodes, edges, graph);
    getMinHeight(nodes, graph, heightMap);
    return minTrees(heightMap);
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}, {1, 3}, {2, 4}};
  vector<int> result = MinimumHeightTrees::findTrees(5, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  // vec = {{0, 1}, {0, 2}, {2, 3}};
  // result = MinimumHeightTrees::findTrees(4, vec);
  // cout << "Roots of MHTs: ";
  // for (auto num : result) {
  //   cout << num << " ";
  // }
  // cout << endl;

  // vec = {{0, 1}, {1, 2}, {1, 3}};
  // result = MinimumHeightTrees::findTrees(4, vec);
  // cout << "Roots of MHTs: ";
  // for (auto num : result) {
  //   cout << num << " ";
  // }
  // cout << endl;
}



//  Other Approaches(1)
