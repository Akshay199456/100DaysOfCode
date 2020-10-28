/*
-------------------------Question:
We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

Example:
Input: 
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
Output: 2
Explanation: 
The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
 

Constraints:

1 <= routes.length <= 500.
1 <= routes[i].length <= 10^5.
0 <= routes[i][j] < 10 ^ 6.
*/

/*
-------------------------    My Approaches:
1. BFS approach (Doesn't work)

My initial approach was to use a BFS approach as we go along taking note of the buses we have visited and the bus numbers
we have used up. However, that doesn't pass all the test cases

Time complexity: O(V+E)
Space complexity: O(V+E)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> graph;
    
    void insertEntry(int i, int j, int nextJ, vector<vector<int>> routes){
        if(graph.find(routes[i][j]) == graph.end()){
            vector<pair<int,int>> currentPair;
            graph[routes[i][j]] = currentPair;
        }
        graph[routes[i][j]].push_back(make_pair(routes[i][nextJ], i));
    }
    
    void createGraph(vector<vector<int>> routes){
        for(int i=0; i<routes.size(); i++){
            for(int j=0; j<routes[i].size()-1; j++){
                // enter entries into the graph as long as the size is greater than or equal to 2.
                // we enter values till last + 1 index. For last index, we enter the value associated with the first index as long as the length of the array is not 1
                insertEntry(i,j,j+1,routes);
            }
            
            if(routes[i].size() != 1)
                insertEntry(i,routes[i].size()-1, 0, routes);
        }
    }
    
    void printGraph(){
        for(auto it=graph.begin(); it!=graph.end(); it++){
            cout<<"Current element: "<<it->first<<endl;
            for(int i=0; i<it->second.size(); i++){
                cout<<"\tNeighbor bus: "<<it->second[i].first<<" Neighbor bus stop: "<<it->second[i].second<<endl;
            }
        }
    }
    
    int findShortestRoute(int s, int t){
        queue<pair<int,int>> neighborQueue;
        unordered_set<int> visitedBuses;
        unordered_set<int> visitedBusStops;
        
        if(graph.find(s) == graph.end() || graph.find(t) == graph.end())
            return -1;
        else if(s == t)
            return 0;
        else{
            // pushing all the neighbors from the source s
            visitedBuses.emplace(s);
            for(int i=0; i<graph[s].size(); i++)
                neighborQueue.push(make_pair(graph[s][i].first, graph[s][i].second));
            
            while(!neighborQueue.empty()){
                pair<int,int> currentPair = neighborQueue.front();
                neighborQueue.pop();
                if(visitedBuses.find(currentPair.first) == visitedBuses.end()){
                    visitedBuses.emplace(currentPair.first);
                    if(visitedBusStops.find(currentPair.second) == visitedBusStops.end())
                        visitedBusStops.emplace(currentPair.second);

                    if(currentPair.first == t)
                        return visitedBusStops.size();
                    
                    for(int i=0; i<graph[currentPair.first].size(); i++)
                        neighborQueue.push(make_pair(graph[currentPair.first][i].first, graph[currentPair.first][i].second));
                }
            }
            return -1;
        }
    }
    
    
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        createGraph(routes);
        // printGraph();
        // return -1;
       return findShortestRoute(S, T);
    }
};