/*
Problem statement:

This problem is similar to Task Scheduling. The primary difference is now we assign times to tasks and we ask for the minimum amount of time to complete all tasks. There will be an extra times array such that times[i] indicates the time required to complete task[i]. You have also invited all your friends to help complete your tasks so you can work on any amount of tasks at a given time. Be sure to remember that task a must be completed before task b so despite your unlimited manpower your friends must still wait for task a to complete before starting task b.

There is guaranteed to be a solution.

Examples
Example 1
Input:
tasks = ["a", "b", "c", "d"]
times = [1, 1, 2, 1]
requirements = [["a", "b"], ["c", "b"], ["b", "d"]]
*/

/*
-------------------------    My Approaches:
1. 

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
since this problem is similat to task scheduling, we still use the tempalte for kahn's algorithm. the basic ideas is to perform
a topolgical sort ecept we also keep track of the largest amount of time expended for a partcular path through the graph. the time it takes to complete a task in inhibited by
the most time-consuming task in its dependencies. we make sure that we update every node such that it contains the maximum time needed to complete 
every prerequisite task. we then make sure to update every children such that it contains the distance as the final answer is essentially the maximal path through the graph

    Time complexity: O(n+m)
    Space complexity: O()

time complexity is equal to n the number of nodes in the graph plsu m the number of edges in the graph. this is because we have to go through every connection and node once when we sort the graph.


Additional Notes
    since this problem is similar to task scheduling, we still use the template for kahn's algorithm. the basic idea is to perfrom a 
    topological sort except we also keep track of the largest amount of time expended for a partcilaur path through the graph.
    the time it takes to complete a task is inhibited by the most time-consuming task in its dependencies.
    we make sure that we update every node such that it contains the maximum time needed to complete every prerequisite task.  we then make sure that to update
    every children such that it contains the distance as the final answer is essentially the maximal path through the the graph

    time complexity: O(n+m)
        the tme complexity is equal to the n the number of nodes in the graph plus m the no of edges in the graph. this is because
        we have to goo hrough every connection and node once when we sort the graph



    Looking at this approach, it now makes sense. line 201 here is used o allocate the distances with respect to the the first
    set of ndoes who have no parents. for them, its pretty easy. the time it will take to compelte their taslks is going to depend on the 
    their task time itself and as a reault, that is the value that is allocated to them. we use line 202 for ans, to keep track
    of the max distance from all the chldren wioth 0 parents because a child node wwhich has parents is limited bu the node
    which has the max tiome requireed to complete.

    we then enter into the while loop. the same things get done for the hwile loop like every other opological sort
    problem. the section of whe while loop where it calculates the distance for the child is a good strategy.
    we know that every child is going to be limited by its parent. as a result, when we are going to be going too throught he aprent, we already know the 
    max time it takes for the parent which we have stored in distances[node]. as a reuslt, for now, to complete this child, the distance
    to complete the child is either going to be max of itself or the max distance of the parent + time taken for the child.
    ans is used to represent the final answer so we update it with this new child.

    that's the crux of this problem. by keeping track of the max distance for eveyr child and for the answer at every step, we can get he answer.
    

*/



//  My approaches(1) [not fully impleented]
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_map>

void createGraph(unordered_map<std::string, std::vector<std::string>> & graph, std::vector<std::string> & tasks, std::vector<std::vector<std::string>> & requirements){
    // initialize with empty list first
    for(int i=0; i< tasks.size(); i++){
        std::vector<int> list;
        graph[tasks[i]] = list;
    }
    
    //add relationships
    for(int i=0; i< requirements.size(); i++){
        std::vector<int> list = requirements[i];
        graph[list[0]].push_back(list[i]);
    }
}


void getParentCount(unordered_map<std::string, std::vector<std::string>> & graph, unordered_map<std::string, int> & parentCount){
    // initialize parent count to 0
    for(auto it = graph.begin(); it!=graph.end(); it++)
        parentCount[it->first] = 0;
    
    // get parent count
    for(auto it = graph.begin(); it!= graph.end(); it++){
        std::vector<std::string> list = it->second;
        for(int i=0; i< list.size(); i++)
            parentCount[list[i]] += 1;
    }
}


void getTimeCount(std::vector<std::string> & tasks, std::vector<int> & times, unordered_map<std::string, int> & timeCount){
    for(int i=0; i< tasks.size(); i++){
        timeCount[tasks[i]] = times[i];
    }
}


int task_scheduling_2(std::vector<std::string> tasks, std::vector<int> times, std::vector<std::vector<std::string>> requirements) {
    // WRITE YOUR BRILLIANT CODE HERE
    unordered_map<std::string, std::vector<std::string>> graph;
    unordered_map<std::string, int> parentCount;
    unordered_map<std::string, int> timeCount;
    
    createGraph(graph, tasks, requirements);
    getParentCount(graph, parentCount);
    getTimeCount(tasks, times, timeCount);
    topSort(graph, parentCount, timeCount);
    
    return 0;
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
    std::vector<int> times = get_words<int>();
    int requirements_length;
    std::cin >> requirements_length;
    ignore_line();
    std::vector<std::vector<std::string>> requirements;
    for (int i = 0; i < requirements_length; i++) {
        requirements.emplace_back(get_words<std::string>());
    }
    int res = task_scheduling_2(tasks, times, requirements);
    std::cout << res << '\n';
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

int topo_sort(std::unordered_map<std::string, std::vector<std::string>> graph, std::unordered_map<std::string, int> task_times) {
    int ans = 0;
    std::queue<std::string> q;
    std::unordered_map<std::string, int> distances;
    for (auto entry : graph) {
        distances[entry.first] = 0;
    }
    std::unordered_map<std::string, int> counts = count_parents(graph);
    for (auto entry : counts) {
        if (entry.second == 0) {
            q.push(entry.first);
            distances[entry.first] = task_times[entry.first];
            ans = std::max(ans, distances[entry.first]);
        } 
    }
    while (q.size() > 0) {
        std::string node = q.front();
        for (std::string child : graph[node]) {
            counts[child] -= 1;
            distances[child] = std::max(distances[child], distances[node] + task_times[child]);
            ans = std::max(ans, distances[child]);
            if (counts[child] == 0) q.push(child);
        }
        q.pop();
    }
    return ans;
}

int task_scheduling_2(std::vector<std::string> tasks, std::vector<int> times, std::vector<std::vector<std::string>> requirements) {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::unordered_map<std::string, int> task_times;
    for (int i = 0; i < tasks.size(); i++) {
        graph[tasks[i]] = std::vector<std::string>();
        task_times[tasks[i]] = times[i];
    }
    for (std::vector<std::string> req : requirements) {
        graph[req[0]].emplace_back(req[1]);
    }

    return topo_sort(graph, task_times);
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
    std::vector<int> times = get_words<int>();
    int requirements_length;
    std::cin >> requirements_length;
    ignore_line();
    std::vector<std::vector<std::string>> requirements;
    for (int i = 0; i < requirements_length; i++) {
        requirements.emplace_back(get_words<std::string>());
    }
    int res = task_scheduling_2(tasks, times, requirements);
    std::cout << res << '\n';
}