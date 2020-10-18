/*
-------------------------Question:

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.
*/

/*
-------------------------    My Approaches:
1. DFS(Exceeding runtime)

We can use DFS to solve this problem. By using DFS, we can explore all possible solution paths and then choose the one
with the lexicographically smallest path.

Time complexity: O(V^3)
Space complexity: O(V^2)
*/

/*
-------------------------    Other approaches:
1. Improvement on  My Approaches(1)

Instead of finding all possible paths and then selecting the one with the least lexicographical order, we can instead represent
the graph as an adjacency list. The improvment comes from the fact that we sort the adjacncy list associated with each
vertex beforehand. This helps a lot as since all our elements in the adjancey list per vertex are arranged in lexicographical
order, the fiorst valid solutuon that we come across will be the solution that we are looking for since that will be formed
from entried that are the least lexicogrhical in order. Any other path that we find after that will not be a better solution
than this. Hence, sorting it beforehand helps us in obtianing a solution after which we will not need to carry on the
dfs anymore.
class Solution {
public:
    unordered_map<string, vector<string>> airportMap;
    vector<string> result;
    
    void createMap(vector<vector<string>> tickets){
        // put entries into the graph
        for(int i=0; i<tickets.size(); i++){
            if(airportMap.find(tickets[i][0]) == airportMap.end()){
                vector<string> list;
                list.push_back(tickets[i][1]);
                airportMap[tickets[i][0]] = list;
            }
            else
                airportMap[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        // sort each adjacency list
        for(auto it=airportMap.begin(); it!=airportMap.end(); it++)
            sort((it->second).begin(), (it->second).end());
    }
    
    void printMap(){
        for(auto it =airportMap.begin(); it!=airportMap.end(); it++){
            cout<<"City: "<<it->first<<endl;
            for(int i=0; i<(it->second).size(); i++)
                cout<<"\tNeighbor: "<<(it->second)[i]<<endl;
        }
    }
    
    
    void traverseGraph(string currCity, vector<string> path, int limit){
        if(path.size() == limit)
            result = path;
        else{
            for(int i=0; i<airportMap[currCity].size(); i++){
                if(!result.size()){
                    string deletedCity = airportMap[currCity][i];
                    path.push_back(deletedCity);
                    airportMap[currCity].erase(airportMap[currCity].begin()+i);
                    traverseGraph(deletedCity, path, limit);
                    path.pop_back();
                    airportMap[currCity].insert(airportMap[currCity].begin()+i, deletedCity);
                }
            }
        }
    }
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        string startCity = "JFK";
        vector<string> path;
        path.push_back(startCity);
        
        createMap(tickets);
        //printMap();
        traverseGraph(startCity, path, tickets.size()+1);
        return result;
    }
};
v+e + v*vlog
Time complexity: O(V+E+V^2logV) -> O(V^2logV)
Space complexity: O(V+E)
*/

// My Approaches(1)
class Solution {
public:
    unordered_map<string, int> airportMap;
    unordered_map<int, string> indexMap;
    vector<string> result;
    
    void constructMap(vector<vector<string>> tickets){
        int count=0;
        for(int i=0; i < tickets.size(); i++){
            if(airportMap.find(tickets[i][0]) == airportMap.end()){
                airportMap[tickets[i][0]] = count;
                indexMap[count] = tickets[i][0];
                count++;
            }
            
            if(airportMap.find(tickets[i][1]) == airportMap.end()){
                airportMap[tickets[i][1]] = count;
                indexMap[count] = tickets[i][1];
                count++;
            }
        }
    }
    
    void generateGrid(vector<vector<int>> & grid, vector<vector<string>> tickets){
        // set to 0s for everything
        for(int i=0; i < airportMap.size(); i++){
            vector<int> list;
            for(int j=0; j<airportMap.size(); j++)
                list.push_back(0);
            grid.push_back(list);
        }
        
        for(int i=0; i <tickets.size(); i++){
            int fromIndex = airportMap[tickets[i][0]];
            int toIndex = airportMap[tickets[i][1]];
            if(fromIndex != toIndex)
                grid[fromIndex][toIndex] += 1;
        }
    }

    vector<string> getLexicoGraphicalSmallest(vector<string> path){
        int index = 0;
        while(index < result.size()){
            if(path[index].compare(result[index]) ==0)
                index++;
            else if(path[index].compare(result[index]) < 0)
                return path;
            else
                return result;
        }
        return result;
    }
    
    void traverseGrid(int index, vector<vector<int>> grid, vector<string> path, int listSize){
        if(path.size() == listSize){
            if(!result.size())
                result = path;
            else
                result = getLexicoGraphicalSmallest(path);
        }
        else{
            for(int i=0; i<grid[index].size(); i++){
                if(grid[index][i] >= 1){
                    grid[index][i] -= 1;
                    path.push_back(indexMap[i]);
                    traverseGrid(i, grid, path, listSize);
                    path.pop_back();
                    grid[index][i] += 1;
                }
            }
        }
    }
        
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<vector<int>> grid;
        vector<string> path;
        path.push_back("JFK");
        
        constructMap(tickets);
        generateGrid(grid, tickets);
        traverseGrid(airportMap["JFK"], grid, path, tickets.size()+1);
        return result;
    }
};


// Other Approaches(1)
class Solution {
public:
    unordered_map<string, vector<string>> airportMap;
    vector<string> result;
    
    void createMap(vector<vector<string>> tickets){
        // put entries into the graph
        for(int i=0; i<tickets.size(); i++){
            if(airportMap.find(tickets[i][0]) == airportMap.end()){
                vector<string> list;
                list.push_back(tickets[i][1]);
                airportMap[tickets[i][0]] = list;
            }
            else
                airportMap[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        // sort each adjacency list
        for(auto it=airportMap.begin(); it!=airportMap.end(); it++)
            sort((it->second).begin(), (it->second).end());
    }
    
    void printMap(){
        for(auto it =airportMap.begin(); it!=airportMap.end(); it++){
            cout<<"City: "<<it->first<<endl;
            for(int i=0; i<(it->second).size(); i++)
                cout<<"\tNeighbor: "<<(it->second)[i]<<endl;
        }
    }
    
    
    void traverseGraph(string currCity, vector<string> path, int limit){
        if(path.size() == limit)
            result = path;
        else{
            for(int i=0; i<airportMap[currCity].size(); i++){
                if(!result.size()){
                    string deletedCity = airportMap[currCity][i];
                    path.push_back(deletedCity);
                    airportMap[currCity].erase(airportMap[currCity].begin()+i);
                    traverseGraph(deletedCity, path, limit);
                    path.pop_back();
                    airportMap[currCity].insert(airportMap[currCity].begin()+i, deletedCity);
                }
            }
        }
    }
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        string startCity = "JFK";
        vector<string> path;
        path.push_back(startCity);
        
        createMap(tickets);
        //printMap();
        traverseGraph(startCity, path, tickets.size()+1);
        return result;
    }
};