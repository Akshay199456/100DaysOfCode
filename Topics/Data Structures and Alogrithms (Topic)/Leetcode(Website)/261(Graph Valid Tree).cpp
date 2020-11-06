/*
*/

/*
*/

/*
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