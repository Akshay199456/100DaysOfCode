/*
-------------------------Question:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

/*
-------------------------    My Approaches:
1. Cycle Detection using BFS

This problem is basically a cycle detection problem. We are testing whether another prerequisite results in a cycle and if
so, then we know we wouldn't be able to complete it. To store the states, we use one of two values. 0 refers to a state
where you have already visited the node while 1 refers to a state where you are still visiting the node. If we are in the
middle of visiting a node and we come across a node which is still being visited, we know that a cycle exists, hence we 
return true for the determination of a cycle. Also, we dont explore the nodes that we have already visited before.

Time complexity: O(N^2)
Space complexity: O(N^2)
where N is the total number of buses.
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    void createGraph(int numCourses, vector<vector<int>> prerequisites){
        // initialize graph with empty lists
        for(int i=0; i<numCourses; i++){
            vector<int> list;
            graph[i] = list;
        }
        
        // initialize graph with edge relations
        for(int i=0; i<prerequisites.size(); i++)
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    
    void printGraph(){
        for(auto it=graph.begin(); it!=graph.end(); it++){
            cout<<"Element: "<<it->first<<endl;
            for(int i=0; i<it->second.size(); i++){
                cout<<"\tDependency: "<<it->second[i]<<endl;
            }
        }
    }
    
    bool finishAllCourses(int numCourses){
        unordered_map<int,int> vertexStates;
        for(int i=0; i<numCourses; i++){
            if(isCycleExist(i, vertexStates))
                return false;
        }
        return true;
    }
    
    bool isCycleExist(int vertex, unordered_map<int,int> & vertexStates){
        // 0->visited, 1->visited
        if(vertexStates.find(vertex) != vertexStates.end() && vertexStates[vertex] == 1)
            return false;
        vertexStates[vertex] = 0;
        for(int i=0; i<graph[vertex].size(); i++){
            if(vertexStates.find(graph[vertex][i]) != vertexStates.end()){
                if(vertexStates[graph[vertex][i]] == 0)
                    return true;
            }
            else{
                if(isCycleExist(graph[vertex][i], vertexStates))
                    return true;
            }
        }
        vertexStates[vertex] = 1;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        createGraph(numCourses, prerequisites);
        // printGraph();
        return finishAllCourses(numCourses);
    }
};