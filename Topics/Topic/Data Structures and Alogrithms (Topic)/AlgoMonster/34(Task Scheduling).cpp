/*
Problem statement:

For this problem, given a list of tasks and a list of requirements, compute a sequence of tasks that can be performed, such that we complete every task once while satisfying all the requirements.

Each requirement will be in the form of a list [a, b], where task a needs to be completed first before task b can be completed,

There is guaranteed to be a solution.

Examples
Example 1
Input:
tasks = ["a", "b", "c", "d"]
requirements = [["a", "b"], ["c", "b"], ["b", "d"]]
Output: ["a", "c", "b", "d"]
*/

/*
-------------------------    My Approaches:
1. Topological sort

    we can solve this problem using topological sort. this is because, in this problem it requires us to insert compoennts based on the order in which they can be completedm
    which is what topological sort is about. in addition, there is a relationship between nodes and as a result, the requirements can be represented as a graph.



    Time complexity: O(V+e)
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
apply  kahn's algorithm to solve the problem

    Time complexity: O(n+m)
    Space complexity: O()

the time complexity is qual to n, the number of nodes in the graph and m , the number of edges in the graph. this is because
we have to go through every connection and node once when we sort the graph.
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_map>
#include <queue>

void createGraph(std::unordered_map<std::string, std::vector<std::string>> & graph, std::vector<std::string> & tasks, std::vector<std::vector<std::string>> & requirements){
    //initialize everything to null list
    for(int i=0; i< tasks.size(); i++){
        std::vector<std::string> list;
        graph[tasks[i]] = list;
    }
    
    // push the relationships from requirements into graph
    for(int i=0; i<requirements.size(); i++){
        std::vector<std::string> list = requirements[i];
        graph[list[0]].push_back(list[1]);
    }
}


void getParentCount(std::unordered_map<std::string, int> & parentCount, std::unordered_map<std::string, std::vector<std::string>> & graph){
    // initialize parent count for each task to 0
    for(auto it = graph.begin(); it!= graph.end(); it++){
        parentCount[it->first] = 0;
    }
    
    for(auto it = graph.begin(); it!= graph.end(); it++){
        std::vector<std::string> list = it->second;
        for(int i=0; i< list.size(); i++){
            parentCount[list[i]] += 1;
        }
    }
}


std::vector<std::string> getResult(std::unordered_map<std::string, int> & parentCount, std::unordered_map<std::string, std::vector<std::string>> & graph){
    std::queue<std::string> elementQueue;
    std::vector<std::string> result;
    // initially fill queue with parents who have 0
    for(auto it = parentCount.begin(); it!= parentCount.end(); it++){
        if(!it->second)
            elementQueue.push(it->first);
    }
    
    // push into queue
    while(!elementQueue.empty()){
        std::string frontElement = elementQueue.front();
        result.push_back(frontElement);
        std::vector<std::string> children = graph[frontElement];
        for(int i=0; i < children.size(); i++){
            parentCount[children[i]] -= 1;
            if(!parentCount[children[i]])
                elementQueue.push(children[i]);
        }
        elementQueue.pop();
    }
    
    return result;
}


std::vector<std::string> task_scheduling(std::vector<std::string> tasks, std::vector<std::vector<std::string>> requirements) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::unordered_map<std::string, int> parentCount;
    createGraph(graph, tasks, requirements);
    getParentCount(parentCount, graph);
    std::vector<std::string> result =  getResult(parentCount, graph);
    
    if(result.size() == graph.size())
        return result;
    return std::vector<std::string>();
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
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
    std::vector<std::string> tasks = get_words<std::string>();
    int requirements_length;
    std::cin >> requirements_length;
    ignore_line();
    std::vector<std::vector<std::string>> requirements;
    for (int i = 0; i < requirements_length; i++) {
        requirements.emplace_back(get_words<std::string>());
    }
    std::vector<std::string> res = task_scheduling(tasks, requirements);
    if (res.size() != tasks.size()) {
        std::cout << "output size " << res.size() << " does not match input size " << tasks.size() << '\n';
        return 0;
    }
    std::unordered_map<std::string, int> indices;
    for (int i = 0; i < res.size(); i++) {
        indices.insert({res[i], i});
    }
    for (auto req : requirements) {
        for (auto task : req) {
            if (indices.find(task) == indices.end()) {
                std::cout << "'" << task << "' is not in output" << '\n';
                return 0;
            }
        }
        std::string a = req[0];
        std::string b = req[1];
        if (indices[a] >= indices[b]) {
            std::cout << "'" << a << "' is not before '" << b + "'" << '\n';
            return 0;
        }
    }
    std::cout << "ok" << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <queue> // queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <vector> // vector

template <typename T> std::unordered_map<T, int> count_parents(std::unordered_map<T, std::vector<T>> graph) {
    std::unordered_map<T, int> counts;
    for (auto entry : graph) {
        counts[entry.first] = 0;
    }
    for (auto entry : graph) {
        for (auto node : entry.second) {
            counts[node] += 1;
        }
    }
    return counts;
}

template <typename T> std::vector<T> topo_sort(std::unordered_map<T, std::vector<T>> graph) {
    std::vector<T> res;
    std::queue<T> q;
    std::unordered_map<T, int> counts = count_parents(graph);
    for (auto entry : counts) {
        if (entry.second == 0) q.push(entry.first);
    }
    while (q.size() > 0) {
        T node = q.front();
        res.emplace_back(node);
        for (T child : graph[node]) {
            counts[child] -= 1;
            if (counts[child] == 0) q.push(child);
        }
        q.pop();
    }
    if (graph.size() == res.size()) return res;
    else {
        std::cout << "Invalid topo sort: graph contains cycle" <<'\n';
        return std::vector<T>();
    }
}

std::vector<std::string> task_scheduling(std::vector<std::string> tasks, std::vector<std::vector<std::string>> requirements) {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    for (std::string task : tasks) {
        graph[task] = {};
    }
    for (std::vector<std::string> req : requirements) {
        graph[req[0]].emplace_back(req[1]);
    }
    return topo_sort(graph);
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
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
    std::vector<std::string> tasks = get_words<std::string>();
    int requirements_length;
    std::cin >> requirements_length;
    ignore_line();
    std::vector<std::vector<std::string>> requirements;
    for (int i = 0; i < requirements_length; i++) {
        requirements.emplace_back(get_words<std::string>());
    }
    std::vector<std::string> res = task_scheduling(tasks, requirements);
    if (res.size() != tasks.size()) {
        std::cout << "output size " << res.size() << " does not match input size " << tasks.size() << '\n';
        return 0;
    }
    std::unordered_map<std::string, int> indices;
    for (int i = 0; i < res.size(); i++) {
        indices.insert({res[i], i});
    }
    for (auto req : requirements) {
        for (auto task : req) {
            if (indices.find(task) == indices.end()) {
                std::cout << "'" << task << "' is not in output" << '\n';
                return 0;
            }
        }
        std::string a = req[0];
        std::string b = req[1];
        if (indices[a] >= indices[b]) {
            std::cout << "'" << a << "' is not before '" << b + "'" << '\n';
            return 0;
        }
    }
    std::cout << "ok" << '\n';
}