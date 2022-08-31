/*
Problem statement:

There are a total of n courses a student has to take, numbered from 0 to n-1. A course may have prerequisites. The "depends on" relationship is expressed as a pair of numbers. For example, [0, 1] means you need to take course 1 before taking course 0. Given n and the list of prerequisites, decide if it is possible to take all the courses.

Example 1:

Input: n = 2, prerequisites = [[0, 1]]

Output: true

Explanation: we can take 1 first and then 0.

Example 2:

Input: n = 2, prerequisites = [[0, 1], [1, 0]]

Output: false

Explanation: the two courses depend on each other, there is no way to take them
*/

/*
-------------------------    My Approaches:
1. Topological sort technique

    we can use the topological sort technique to solve the problem. since specific courses can only be completed if the prerequisit is completed,
    there is an order in the relationships and there exists a relationship between each node. as a result, we can apply the topological sort technique to solve the problen

    Time complexity: O(n+m)
    Space complexity: O(n+m)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
problem is the same as task scheduling. at this point, if you had gone through teh repvious problems in the topological sort section, you should be able to solve this
problem using kahn's algorithm. for this problem, there is another way to solve the problem instea of topological ordering.
you can use DFS instead of BFS. the bfs version is easier to understand

Intuition

naturally, the dependency relationship can be modelled as a directed graph.
notice that a ciurse is 'not takeable' if any of its dependences is 'not takeable'. this only happens wher there iss a circular dependency
eg: A depends on B and B depends on A. in graph terms, this is called a cycle. this problem becomes determining if the graph
contains a ccycle. note that this is a directed graph and a path is only a cucle if one of the nodes ponts back to one of the nodes in the current path.

Cycle Detection

one way to detect cycles is to use DFS. for normal graph DFS, a node has two states, 'to be visited' and 'visited'. we traverse th graph and visit each 'tobe vistited' node and mark it as 'visited'.

in cycle detection, we need a third state 'visiting'. We perform DFS on each node by:
    1. mark a node as 'visiting'
    2. visit each of its neighbors

when we do a DFS, we mark each node in the path as 'visiting'. when we rech the end of the path (i.e. nor more out edge from the last node in the path), we mark the node in th epath as 'visited'. If during the DFS, we happen to come back to a node that is in the 
'visiting' state, then we have a cycle.


    Time complexity: O(n+m)
    Space complexity: O()

time compolexity is equal to n the number of ndoes in the graph plus m the number od edges in the graph. this is becasue we have to go through every connection
and node once when we sort the graph.

one question you may ask is why we have to introduce an additional state 'visiting'. couldn't have we solved it with only 'visited' and 'to be visited' as in normal DFS?

Consider the following case (Additional Notes(1)-8):

if we use the normal dfs logic and reject when a node in the 'visited' state is revisitied, we would have determined the above gropah to be a cycle., 
however, node 3 is visited tweice bit the graph does not contain a cycle.

in a directed graph, a pth is only a cycle if a node on the path points to an existing node on the same path. if we only have two states, we wouldnt be able to distinguhis this.
the 'visiting' state gives us a way to represent the 'current path'
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_map>
#include <queue>

void createGraph(int n, std::vector<std::vector<int>> & prerequisites, std::unordered_map<int, std::vector<int>> & graph){
    // initialize with empty list
    for(int i=0; i<n; i++){
        std::vector<int> list;
        graph[i] = list;
    }
    
    // initilaize with prerequsisites
    for(int i=0; i< prerequisites.size(); i++){
        std::vector<int> list = prerequisites[i];
        graph[list[1]].push_back(list[0]);
    }
}


void getParentCount(std::unordered_map<int, int> & parentCount, std::unordered_map<int, std::vector<int>> & graph){
    // initialize with 0
    for(auto it = graph.begin(); it!= graph.end(); it++){
        parentCount[it->first] = 0;
    }
    
    // initilaize with values
    for(auto it = graph.begin(); it!= graph.end(); it++){
        std::vector<int> list = it->second;
        for(int i=0; i< list.size(); i++){
            parentCount[list[i]] += 1;
        }
    }
}

std::vector<int> topSort(std::unordered_map<int, int> & parentCount, std::unordered_map<int, std::vector<int>> & graph){
    std::queue<int> elementQueue;
    std::vector<int> result;
    
    // initialize quue with parentcount = 0
    for(auto it = parentCount.begin(); it!= parentCount.end(); it++){
        if(!it->second)
            elementQueue.push(it->first);
    }
    
    // fill as you go 
    while(!elementQueue.empty()){
        int front = elementQueue.front();
        result.push_back(front);
        
        // remove count of this front element from the children
        std::vector<int> children = graph[front];
        for(int i=0; i<children.size(); i++){
            parentCount[children[i]] -= 1;
            if(!parentCount[children[i]])
                elementQueue.push(children[i]);
        }
        
        elementQueue.pop();
    }
    return result;
}


bool is_valid_course_schedule(int n, std::vector<std::vector<int>> prerequisites) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_map<int, std::vector<int>> graph;
    std::unordered_map<int, int> parentCount;
    createGraph(n, prerequisites, graph);
    getParentCount(parentCount, graph);
    std::vector<int> list = topSort(parentCount, graph);
    return list.size() == graph.size();
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int prerequisites_length;
    std::cin >> prerequisites_length;
    ignore_line();
    std::vector<std::vector<int>> prerequisites;
    for (int i = 0; i < prerequisites_length; i++) {
        prerequisites.emplace_back(get_words<int>());
    }
    bool res = is_valid_course_schedule(n, prerequisites);
    std::cout << std::boolalpha << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <vector> // vector

enum State { TO_VISIT, VISITING, VISITED };

std::unordered_map<int, std::vector<int>> build_graph(std::vector<std::vector<int>> prerequisites) {
    std::unordered_map<int, std::vector<int>> graph(prerequisites.size());
    for (std::vector<int> dependency : prerequisites) {
        if (!graph.count(dependency[0])) {
            graph[dependency[0]] = std::vector<int>();
        }
        graph[dependency[0]].emplace_back(dependency[1]);
    }
    return graph;
}

bool dfs(int start, State states[], std::unordered_map<int, std::vector<int>> graph) {
    // mark self as visiting
    states[start] = VISITING;

    if (graph.count(start)) {
        for (int next_vertex : graph[start]) {
            // ignore visited nodes
            if (states[next_vertex] == VISITED) continue;
            // revisiting a visiting node, CYCLE!
            if (states[next_vertex] == VISITING) return false;
            // recursively visit neighbours
            // if a neighbour found a cycle, we return false right away
            if (!dfs(next_vertex, states, graph)) return false;
        }
    }

    // mark self as visited
    states[start] = VISITED;
    // if we have gotten this far, our neighbours haven't found any cycle, return true
    return true;
}

bool is_valid_course_schedule(int n, std::vector<std::vector<int>> prerequisites) {
    std::unordered_map<int, std::vector<int>> graph = build_graph(prerequisites);
    State states[n] = { TO_VISIT };
    // DFS on each node
    for (int i = 0; i < n; i++) {
        if (!dfs(i, states, graph)) return false;
    }
    return true;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int prerequisites_length;
    std::cin >> prerequisites_length;
    ignore_line();
    std::vector<std::vector<int>> prerequisites;
    for (int i = 0; i < prerequisites_length; i++) {
        prerequisites.emplace_back(get_words<int>());
    }
    bool res = is_valid_course_schedule(n, prerequisites);
    std::cout << std::boolalpha << res << '\n';
}