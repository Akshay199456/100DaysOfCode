/*
-------------------------Question:
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.
 

Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
*/

/*
-------------------------    My Approaches:
1. BFS implementation of Other Approaches(1)

I have extended the implementation of Other approaches(1) using BFS instead. With BFS, we follow the same principle but
if a node has a color , we make checks for if the color is the currect color. If the node doesn't have a color, we assign color
to it and push its neighboring nodes into the queue.

Time complexity: O(V+E)
Space complexity: O(V+E)
*/

/*
-------------------------    Other approaches:
1. DFS Coloring

The key to this problem is to sort the elements into one of two sets. If that is possible, then the graph is bi-partite.
Each node can possess one of 3 states. It can be not colored, colored blue(represented here by -1) or colored red(
represeneted here by +1). If it is not colored, we can assign it one of the two colors. If it is colored, its neighbors
should be colored opposite for it to be biu-partite. As a result, we use this technqie to assign colors to the elements
as we are going depth first into the graph.

Time complexity: O(V+E)
Space complexity: O(V+E)
*/


// My Approaches(1)
class Solution {
public:
    vector<int> colorVector;
    
    void defineColorVector(int nVertices){
        for(int i=0; i<nVertices; i++)
            colorVector.push_back(0);
    }
    
    bool bfsColoring(vector<vector<int>> graph, int element, int color){
        queue<pair<int, int>> elementColorPair;
        elementColorPair.push(make_pair(element,color));
        while(!elementColorPair.empty()){
            pair<int,int> currentPair = elementColorPair.front();
            elementColorPair.pop();
            if(colorVector[currentPair.first] != 0){
                if(colorVector[currentPair.first] != currentPair.second)
                    return false;
            }
            else{
                colorVector[currentPair.first] = currentPair.second;
                for(int i=0; i<graph[currentPair.first].size(); i++){
                    elementColorPair.push(make_pair(graph[currentPair.first][i], -1*currentPair.second));
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        defineColorVector(graph.size());
        
        // coloring each element into one of 2 sets: 1->red, -1->blue
        for(int i=0; i<graph.size(); i++){
            if(colorVector[i]==0 && !bfsColoring(graph,i,1))
                return false;
        }
        return true;
    }
};



// Other Approaches(1)
class Solution {
public:
    vector<int> colorVector;
    
    void defineColorVector(int nVertices){
        for(int i=0; i<nVertices; i++)
            colorVector.push_back(0);
    }
    
    bool recursiveColoring(vector<vector<int>> graph, int element, int color){
        if(colorVector[element]!=0)
            return colorVector[element] == color;

        colorVector[element] = color;
        for(int i=0; i<graph[element].size(); i++){
            if(!recursiveColoring(graph, graph[element][i], -1*color))
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        defineColorVector(graph.size());
        
        // coloring each element into one of 2 sets: 1->red, -1->blue
        for(int i=0; i<graph.size(); i++){
            if(colorVector[i]==0 && !recursiveColoring(graph,i,1))
                return false;
        }
        return true;
    }
};