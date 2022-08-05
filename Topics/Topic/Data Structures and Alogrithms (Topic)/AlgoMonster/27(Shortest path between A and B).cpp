/*
Problem statement:

Given an (unweighted) graph, return the length of the shortest path between two nodes A and B, in terms of the number of edges.

Input:

graph: {
  0: [1, 2],
  1: [0, 2, 3],
  2: [0, 1],
  3: [1]
}
A: 0
B: 3
Output: 2


*/

/*
-------------------------    My Approaches:
1. bfs

since the problem asks for the shortest path between the two locations a and b, we can use bfs to solve this problem.

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
bfs is best for finding the distance between two nodes sice it traverses level by level. since the graph is already built for us get_neighbors function retirieves the adjacency list

n is the no of nodes in the graph and m the number of edges. the time spent isequal to the nummber of nodes and edges in the worst
case. consider for example a linerar graph 0->1->2->3 and so on where we want to get from end to end, we would traverse every node and edge excatly once.

    Time complexity: O(n+m)
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <queue>
#include <unordered_set>

std::vector<int> getNeighbors(int node, std::vector<std::vector<int>> & graph){
    std::vector<int> result;
    return graph[node];   
}

int getBfs(std::vector<std::vector<int>> & graph, int a, int b) {
    std::queue<int> q;
    q.push(a);
    std::unordered_set<int> visited;
    visited.emplace(a);
    int level = 0;
    while (q.size() > 0) {
        int node = q.front();
        for (int neighbor : getNeighbors(node, graph)) {
            if(neighbor == b)
                return level+1;
            else if (visited.find(neighbor) != visited.end()) {
                continue;
            }
            q.push(neighbor);
            visited.emplace(neighbor);
        }
        q.pop();
        ++level;
    }
    return -1;
}

int shortest_path(std::vector<std::vector<int>> graph, int a, int b) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(a == b)
        return 0;
    int getShortestPath = getBfs(graph,a,b);
    return getShortestPath;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int graph_length;
    std::cin >> graph_length;
    ignore_line();
    std::vector<std::vector<int>> graph;
    for (int i = 0; i < graph_length; i++) {
        graph.emplace_back(get_words<int>());
    }
    int a;
    std::cin >> a;
    ignore_line();
    int b;
    std::cin >> b;
    ignore_line();
    int res = shortest_path(graph, a, b);
    std::cout << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <queue> // queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_set> // unordered_set
#include <vector> // vector

std::vector<int> get_neighbors(std::vector<std::vector<int>> graph, int node) {
    return graph[node];
}

// BFS template
int bfs(std::vector<std::vector<int>> graph, int root, int target) {
    std::queue<int> q;
    q.push(root);
    std::unordered_set<int> visited;
    visited.emplace(root);
    int level = 0;
    while (q.size() > 0) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            int node = q.front();
            if (node == target) return level;
            for (int neighbor : get_neighbors(graph, node)) {
                if (visited.count(neighbor)) continue;
                q.push(neighbor);
                visited.emplace(neighbor);
            }
            q.pop();
        }
        // increment level after we have processed all nodes of the level
        level++;
    }
    return level;
}

int shortest_path(std::vector<std::vector<int>> graph, int a, int b) {
    return bfs(graph, a, b);
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int graph_length;
    std::cin >> graph_length;
    ignore_line();
    std::vector<std::vector<int>> graph;
    for (int i = 0; i < graph_length; i++) {
        graph.emplace_back(get_words<int>());
    }
    int a;
    std::cin >> a;
    ignore_line();
    int b;
    std::cin >> b;
    ignore_line();
    int res = shortest_path(graph, a, b);
    std::cout << res << '\n';
}
A quick note on "unweighted". Sometimes, graph's edges can have weight. For example, a graph that represents city connections and edges' weights represent the distance between cities.

BFS can find the shortest path for unweighted graphs. For weighted graphs, we need algorithms like Dijkstra's algorithm. Dijkstra's algorithm rarely comes up in coding interviews so we won't get into details here.