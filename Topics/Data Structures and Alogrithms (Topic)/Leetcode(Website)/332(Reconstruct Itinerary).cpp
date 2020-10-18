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
    // My Approaches
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
