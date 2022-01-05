/*
-------------------------Question:
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.

*/

/*
-------------------------    My Approaches:
1. DFS on queries

The goal of this problem is to go from the souce node to the destination node and to calculate the results as we go along.
Obviously, if a node is visited, we don't want to visit it again. Also, if either the source node or the destination node
are not available in the graph, that means there exists no path and hence we add -1. If source node and destination node
are the same we return the result that we had calculated till that step. Finlly, once we arrive at the destination node,
we don't need to find any other path as we have obtained a path from the souce node to the destination node.

Time complexity: O(n(V+E)) where n is no of queries
Space complexity: O(V) + O(V+E) = O(V+E)
*/

/*
-------------------------    Other approaches:

*/

// MY Approaches(1)
class Solution {
public:
    vector<double> result;
    unordered_map<string, int> variableMapping;
    unordered_map<string, vector<pair<string,double>>> equationGraph;
    
    void addNode(string startNode, string endNode, double value){
        if(equationGraph.find(startNode) == equationGraph.end()){
            variableMapping[startNode] = variableMapping.size();
            vector<pair<string, double>> list;
            equationGraph[startNode] = list;
        }
        equationGraph[startNode].push_back(make_pair(endNode, value));
    }
    
    void createGraph(vector<vector<string>> equations, vector<double> values){
        for(int i=0; i<equations.size(); i++){
            addNode(equations[i][0], equations[i][1], values[i]);
            addNode(equations[i][1], equations[i][0], (((double)1)/values[i]));
        }
    }
    
    void initializeVisited(vector<bool> & visitedNodes){
        for(int i=0; i<variableMapping.size(); i++)
            visitedNodes.push_back(false);
    }
    
    void dfs(string currentNode, string destNode, double currentValue, double & resultValue, bool & isFound, vector<bool> visitedNodes){
        if(currentNode.compare(destNode) == 0){
            resultValue = currentValue;
            isFound = true;
        }
        else{
            int index = variableMapping[currentNode];
            if(!visitedNodes[index]){
                // cout<<"Current node: "<<currentNode<<endl;
                visitedNodes[index] = true;
                for(int i=0; i<equationGraph[currentNode].size(); i++){
                    if(!isFound){
                        pair<string, double> currentPair = equationGraph[currentNode][i];
                        dfs(currentPair.first, destNode, currentValue * currentPair.second, resultValue, isFound, visitedNodes);
                    }
                }
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<bool> visitedNodes;
        createGraph(equations, values);
        initializeVisited(visitedNodes);
        for(int i=0; i<queries.size(); i++){
            if(equationGraph.find(queries[i][0]) == equationGraph.end() || equationGraph.find(queries[i][1]) == equationGraph.end())
                result.push_back(-1);
            else if(queries[i][0].compare(queries[i][1]) == 0)
                result.push_back(1);
            else{
                bool isFound = false;
                double resultValue = 1, currentValue = 1;
                dfs(queries[i][0], queries[i][1], currentValue, resultValue, isFound, visitedNodes);
                if(!isFound)
                    resultValue = -1;
                result.push_back(resultValue);
                
                // resetting values
                resultValue = 1;
                isFound = false;
            }
        }
        return result;
    }
};