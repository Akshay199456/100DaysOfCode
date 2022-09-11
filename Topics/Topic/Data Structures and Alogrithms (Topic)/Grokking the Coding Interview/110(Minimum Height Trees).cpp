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
from the above mentioned examples, can clearly see that any leaf node (i.e node with only one edge) can never give us an MHT because its adjacent non-leaf nodes will always give us an MHT with a smaller height.
all the adjacent non-leadnodes will consider the leaf node as a subtree

lets understand this with another example. suppose we have a tree with root 'M' and height '5'. now if we take another node, say 'P' and make the 'M'
tree as its subtree, then the height of the overall treee with root 'p' will be '6'(5+1). now this while tree can be considered a graph, where 'p' is a leaf as it has only one 
edge (connection with 'm'). this clearly shows that the lead node 'p') gives us a tree of height '6' whereas its adjacent non-leaf node ('m') gives  us a tree with smaller
height '5' since 'p' will be a child of 'm'.

this gives us a stretegy to find MHTs. since leaves can't give us MHTs, we can remove them from the graph and remove their edges too. once we remove the leaves, we will have new leaves. since these new leaves
cant give us mht, we will repeat hte process and remove them formt he graph too. we will prune the leaves untitl we are left with one or two nodes which will be our answer and the roots for MHTs.

we can implement the above process using the topological sort. any node with only one edge (i.e a leaf) can be our source end
and in a stepwise fashion, we can remove lal sources from the graph to find new sources, we will repeat htis process untutl we are left with one or two nodes in the graph which will be our answer


Additional notes:

as soonas they had mentioned that leaf nodes will never be mst because adjacent non-leaf nodes will always hjave 1 less node, i knoew they would use the stretegy to keep removeing
leaf by leaf. that is a stretegy we have used a while ago in a few problems to get the answer to the one with th eleast/most umber of something. and they used the same stretgy here as well.

to follow the topoligical sort, there is just one difference. since it is an undirected graph, we add both nodes to each other. so the one with the leaves have indegree of 1 insteaf of 0 in a typical directed grpah. and they use that
to get rid of the leaves layer by layer till we get to the smallest layer we can have

    Time complexity: O(v+e)
    Space complexity: O(v+e)
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
using namespace std;

#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class MinimumHeightTrees {
 public:
  static vector<int> findTrees(int nodes, vector<vector<int>>& edges) {
    vector<int> minHeightTrees;
    if (nodes <= 0) {
      return minHeightTrees;
    }

    // with only one node, since its in-degree will be 0, therefore, we need to handle it separately
    if (nodes == 1) {
      minHeightTrees.push_back(0);
      return minHeightTrees;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (int i = 0; i < nodes; i++) {
      inDegree[i] = 0;
      graph[i] = vector<int>();
    }

    // b. Build the graph
    for (int i = 0; i < edges.size(); i++) {
      int n1 = edges[i][0], n2 = edges[i][1];
      // since this is an undirected graph, therefore, add a link for both the nodes
      graph[n1].push_back(n2);
      graph[n2].push_back(n1);
      // increment the in-degrees of both the nodes
      inDegree[n1]++;
      inDegree[n2]++;
    }

    // c. Find all leaves i.e., all nodes with only 1 in-degree
    deque<int> leaves;
    for (auto entry : inDegree) {
      if (entry.second == 1) {
        leaves.push_back(entry.first);
      }
    }

    // d. Remove leaves level by level and subtract each leave's children's in-degrees.
    // Repeat this until we are left with 1 or 2 nodes, which will be our answer.
    // Any node that has already been a leaf cannot be the root of a minimum height tree, because
    // its adjacent non-leaf node will always be a better candidate.
    int totalNodes = nodes;
    while (totalNodes > 2) {
      int leavesSize = leaves.size();
      totalNodes -= leavesSize;
      for (int i = 0; i < leavesSize; i++) {
        int vertex = leaves.front();
        leaves.pop_front();
        vector<int> children = graph[vertex];
        for (auto child : children) {
          inDegree[child]--;
          if (inDegree[child] == 1) {  // if the child has become a leaf
            leaves.push_back(child);
          }
        }
      }
    }

    std::move(std::begin(leaves), std::end(leaves), std::back_inserter(minHeightTrees));
    return minHeightTrees;
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

  vec = {{0, 1}, {0, 2}, {2, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {1, 2}, {1, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
