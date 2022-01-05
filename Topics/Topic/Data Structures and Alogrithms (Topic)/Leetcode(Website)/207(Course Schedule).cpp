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
1. Toplogical sort with BFS

We can use a topolical sort algorithm with BFS to solve this problem as well. However, in this approach, the way we construct
the graph will be in a slightly different way. If a course is a prequisite for a certain course, we will store all the
courses which require a particular course as the prequisite for aevery vertex in the graph. In addition, we are going to
use an inDegreeList which will store the number of incoming edges to a particular vertex. So, if any vertex has the number
of incoming edges as 0, it means that that course doesn't have any other courses as its prerquisite. In other words, it is
a leaf. As a result, we trace back from the leaves to the rest of the graph and keep determining if there is a cycle along the
way. If there is a cycle in the graph, we will eventually end up in a situation where the number of incoming edges of
elements that are still remaining(those that don't have value -1) will have none as 0. If this is the case, we know that
there is a cycle because of the remaining vertexes, every vertex depends on some other vertex as its prequisite and this 
is a cycle by its definintion.


Note: We have added an image with 'Additional notes'. This was use to prove why we would need to store the graph in a format
where the vertexes mean other nodes are dependedn on this vertex. If we were to store it as shown in this image where vertex
represents all the prerequisites the current vertex depends upon, when we would oncstruct the indegree list and go though
the same process as Other Approaches(1), in order to reduce the indegree edges corresponding to the vertex we are currently
at, we would have to go through all the remaining vertexes to see if the current vertex exists in that and if it does, reduce
the incoming edges for that vertex. This would be highly inefficienct as compared to the way in Other approaches(1) where
we use the current vertex and go through its neighbors to reduce the incoming edge counts for its neighbors

Time complexity: O(n^2)
Space complexity: O(n^2)

2. Improved version of My Approaches(1)

In my approaches(1), we start at each course number and check if we can detect a cycle. This is repetitive as that would mean we would be checking for nodes that are descendant from a node more than once., As a result, that
would lead to inefficiency. We cn take care of that by using another array that stores the state of whether or not we have checked it before. If we have cheked it before, we don't need to check it again and skip through
it instead. 

Time complexity: O(V+E)
Space complexity: O(V+E)
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


// Other Approaches(1)
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> inDegreeList;
    
    void createGraph(int numCourses, vector<vector<int>> prerequisites){
        // initialize graph with empty lists and indegreeList
        for(int i=0; i<numCourses; i++){
            vector<int> list;
            graph[i] = list;
            inDegreeList.push_back(0);
        }
        
        // initialize graph with edge relations
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegreeList[prerequisites[i][0]]++;
        }
    }
    
    bool finishAllCourses(int numCourses){
        for(int i=0; i<numCourses; i++){
            int j=0;
            for(; j < numCourses; j++){
                if(!inDegreeList[j])
                    break;
            }
            
            if(j == numCourses)
                return false;
            inDegreeList[j]--;
            
            for(int k=0; k<graph[j].size(); k++)
                inDegreeList[graph[j][k]]--;
        }
        return true;
    }
        
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        createGraph(numCourses, prerequisites);
        return finishAllCourses(numCourses);
    }
};

// Other Approaches(2)
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    void createGraph(int numCourses, vector<vector<int>> & prerequisites){
        // fill with empty lists
        vector<int> list;
        for(int i=0; i< numCourses; i++)
            graph[i] = list;
        
        // fill with edges
        for(int i=0; i< prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
    }
    
    void printGraph(){
        for(auto it=graph.begin(); it!=graph.end(); it++){
            cout<<"Element: "<<it->first<<endl;
            for(int i=0; i<it->second.size(); i++){
                cout<<"\tDependency: "<<it->second[i]<<endl;
            }
        }
    }
    
    bool hasCycle(int currCourse, vector<bool> & hasPreviouslySeen, vector<bool> & hasChecked){
        bool result = false;
        
        if(hasPreviouslySeen[currCourse])
            return true;
        else if(hasChecked[currCourse] || !graph[currCourse].size())
            return false;
        
        hasPreviouslySeen[currCourse] = true;
        for(int i=0; i< graph[currCourse].size() && !result; i++){
            result = hasCycle(graph[currCourse][i], hasPreviouslySeen, hasChecked); 
        }
        
        hasPreviouslySeen[currCourse] = false;
        hasChecked[currCourse] = true;
        return result;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        createGraph(numCourses, prerequisites);
        vector<bool> hasPreviouslySeen(numCourses, false);
        vector<bool> hasChecked(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            if(hasCycle(i, hasPreviouslySeen, hasChecked))
                return false;
        }
        return true;
    }
};