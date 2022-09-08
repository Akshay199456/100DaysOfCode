/*
Problem statement:

There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite tasks which need to be completed before it can be scheduled. Given the number of tasks and a list of prerequisite pairs, write a method to print all possible ordering of tasks meeting all prerequisites.

Example 1:

Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
Output: [0, 1, 2]
Explanation: There is only possible ordering of the tasks.
Example 2:

Input: Tasks=4, Prerequisites=[3, 2], [3, 0], [2, 0], [2, 1]
Output: 
1) [3, 2, 0, 1]
2) [3, 2, 1, 0]
Explanation: There are two possible orderings of the tasks meeting all prerequisites.
Example 3:

Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
Output: 
1) [0, 1, 4, 3, 2, 5]
2) [0, 1, 3, 4, 2, 5]
3) [0, 1, 3, 2, 4, 5]
4) [0, 1, 3, 2, 5, 4]
5) [1, 0, 3, 4, 2, 5]
6) [1, 0, 3, 2, 4, 5]
7) [1, 0, 3, 2, 5, 4]
8) [1, 0, 4, 3, 2, 5]
9) [1, 3, 0, 2, 4, 5]
10) [1, 3, 0, 2, 5, 4]
11) [1, 3, 0, 4, 2, 5]
12) [1, 3, 2, 0, 5, 4]
13) [1, 3, 2, 0, 4, 5]
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
this problem is similar to tasks scheduling order, the only idfference is that we need to find all the topolgolgical orderins of the
tasks.

at any stage, if we have more than one source available and since we can choose any source, therefore, int this case,
we will have multiple ordering of the tasks. we can use a recursive approach with backtracking to consider all
sources at any step

Additional notes:

i guessed the approach. it was evident that we would be doign topolgocal sort and i knew that we had to get all combinations which uses backtracking.
the only thing i didnt know was how it would be done.

whenever we have to do all possible ordering/permutations/combinations, backtracking is one of the only ways to generate that.
there is no other alternative to generate all permutations. as a result, this problem also used the same 
methodology of backtracking to solve the problem.

this problem solving pattern is something i definitely have to get more comfortable with since my peformance in subsets category of 
grokking the coding interview was not great and i didnt do wel. we definitely need to solve more problems there to have
a much better idea tpo solve those kind of problems.


    Time complexity: O(V! + E)
    Space complexity: O(V! + E)

if we dont have any prerequisites, all combinations of the tasks can re[present a topolgocal ordering. as we know, that there can be N! combinations
for n numbers, therefore, the time and space complexity of our algorithm will be O(V! * E) where v is the total number of tasks and 'e' is the total prerequsities.
we need the 'e' part because in each recursive call, at max, we remove (adnd add back) all the edges.
*/



//  My approaches(1)



//  Other Approaches(1)
using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AllTaskSchedulingOrders {
 public:
  static void printOrders(int tasks, vector<vector<int>> &prerequisites) {
    vector<int> sortedOrder;
    if (tasks <= 0) {
      return;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (int i = 0; i < tasks; i++) {
      inDegree[i] = 0;
      graph[i] = vector<int>();
    }

    // b. Build the graph
    for (int i = 0; i < prerequisites.size(); i++) {
      int parent = prerequisites[i][0], child = prerequisites[i][1];
      graph[parent].push_back(child);  // put the child into it's parent's list
      inDegree[child]++;               // increment child's inDegree
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    vector<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push_back(entry.first);
      }
    }

    printAllTopologicalSorts(graph, inDegree, sources, sortedOrder);
  }

 private:
  static void printAllTopologicalSorts(unordered_map<int, vector<int>> &graph,
                                       unordered_map<int, int> &inDegree,
                                       const vector<int> &sources, vector<int> &sortedOrder) {
    if (!sources.empty()) {
      for (int vertex : sources) {
        sortedOrder.push_back(vertex);
        vector<int> sourcesForNextCall = sources;
        // only remove the current source, all other sources should remain in the queue for the next
        // call
        sourcesForNextCall.erase(
            find(sourcesForNextCall.begin(), sourcesForNextCall.end(), vertex));

        vector<int> children =
            graph[vertex];  // get the node's children to decrement their in-degrees
        for (auto child : children) {
          inDegree[child]--;
          if (inDegree[child] == 0) {
            sourcesForNextCall.push_back(child);  // save the new source for the next call
          }
        }

        // recursive call to print other orderings from the remaining (and new) sources
        printAllTopologicalSorts(graph, inDegree, sourcesForNextCall, sortedOrder);

        // backtrack, remove the vertex from the sorted order and put all of its
        // children back to consider the next source instead of the current vertex
        sortedOrder.erase(find(sortedOrder.begin(), sortedOrder.end(), vertex));
        for (auto child : children) {
          inDegree[child]++;
        }
      }
    }

    // if sortedOrder doesn't contain all tasks, either we've a cyclic dependency between tasks, or
    // we have not processed all the tasks in this recursive call
    if (sortedOrder.size() == inDegree.size()) {
      for (int num : sortedOrder) {
        cout << num << " ";
      }
      cout << endl;
    }
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}};
  AllTaskSchedulingOrders::printOrders(3, vec);
  cout << endl;

  vec = {{3, 2}, {3, 0}, {2, 0}, {2, 1}};
  AllTaskSchedulingOrders::printOrders(4, vec);
  cout << endl;

  vec = {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}};
  AllTaskSchedulingOrders::printOrders(6, vec);
  cout << endl;
}
