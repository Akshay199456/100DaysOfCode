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


    Time complexity: O()
    Space complexity: O()
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
