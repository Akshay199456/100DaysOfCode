/*
-------------------------Question:

*/

/*
-------------------------    My Approaches:

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