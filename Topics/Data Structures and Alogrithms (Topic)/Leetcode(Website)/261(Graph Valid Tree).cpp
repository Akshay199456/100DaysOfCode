/*
-------------------------Question:

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
For example:
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0]and thus will not appear together in edges.
*/

/*
-------------------------    My Approaches:
1. Using the principle of detecting a cycle.

To solve this problem, there are two components to it. For an undirected graph to be considered a tree, it must satisfy
2 conditions. First, it must not contain a cycle and the second being that the graph is connected which means starting from
any node, we can get to any other node.

The latter can be decvided easily. We pass in a starting node to the dfs. At the end of that dfs, if the no of vertices
that have been found is equal to the toal no of vertices, it means that eery vertice has been found which means it it 
connected. 

For the first part, we apply the cycle detecting algorithm that we applied to detecting cycle in a directed graph. The only
caveat here is that we don't want to keep visiting the previous node that we came from in the dfs structure.

Time complexity: O(V+E)
Space complexity: O(V+E)


*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)



#include <iostream>
#include<ostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, vector<int>> graph;
int discoveredVertices = 0;

void addEdge(int v1, int v2){
  graph[v1].push_back(v2);
  graph[v2].push_back(v1);
}

void printGraph(){
  for(auto it = graph.begin(); it!=graph.end(); it++){
    cout<<"Element: "<<it->first<<endl;
    for(int i=0; i<it->second.size(); i++){
      cout<<"\tNeighbor: "<<it->second[i]<<" ";
    }
    cout<<endl;
  }
}

bool isCycle(int startVertex, int lastVertex, unordered_map<int,int> & vertexStates){
  if(vertexStates.find(startVertex) != vertexStates.end() && vertexStates[startVertex] == 1)
    return false;
  vertexStates[startVertex] = 0;
  for(int i=0; i<graph[startVertex].size(); i++){
    if(graph[startVertex][i] != lastVertex){
      if(vertexStates.find(graph[startVertex][i]) != vertexStates.end()){
        if(vertexStates[graph[startVertex][i]] == 0)
          return true;
      }

      else{
        if(isCycle(graph[startVertex][i], startVertex, vertexStates))
          return true;
      }
    }
  }

  vertexStates[startVertex] = 1;
  discoveredVertices++;
  return false;

}

bool checkTree(int startVertex, int nVertices){
  // 0->visiting, 1->visited
  unordered_map<int,int> vertexStates;
  if(isCycle(startVertex, -1, vertexStates)){
    cout<<"Cycle exists in graph"<<endl;
    return false;
  } 
  else if(discoveredVertices != nVertices){
    cout<<" All vertices could not be discovered"<<endl;
    return false;
  }

  cout<<"Valid tree"<<endl;
  return true;
}

void initializeGraph(int nVertices){
  for(int i=0; i<nVertices; i++){
    vector<int> list;
    graph[i] = list;
  }
}


int main() {
  int nVertices = 6;
  initializeGraph(nVertices);
  addEdge(0,1);
  addEdge(0,2);
  addEdge(3,0);
  addEdge(4,3);
  printGraph();
  cout<<endl;

  bool result = checkTree(0, nVertices);
  std::cout << "Result: "<<result<<endl;
}