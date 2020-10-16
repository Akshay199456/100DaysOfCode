/*
-------------------------Question:
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

Example 1:


Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
Example 2:


Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
Example 3:

Input: n = 1, edges = []
Output: [0]
Example 4:

Input: n = 2, edges = [[0,1]]
Output: [0,1]
 

Constraints:

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
All the pairs (ai, bi) are distinct.
The given input is guaranteed to be a tree and there will be no repeated edges.
*/

/*
-------------------------    My Approaches:
1. Brute force[Runtime exception]

In the brute force approach, you start with each vertex as the root of the tree and do DFS on it to find the height of that
tree. As a result, we are finding the hright for each of the trees and then using thhat info to return the tree with the 
min height.

Time complexity: O(V(V+E))
Space complexity: O(V+E)
*/

/*
-------------------------    Other approaches:
1. Moving from the leaves of the graph towards the center

We can visualize this problem as a graph of networks. In this case, the problem has mentioned that it follows tree conditions
with no cycles. Our goal is to get towards the center of the graph as this will minimize the height of the tree. For exampke,
let's assume we had a graph with oinly oine path

1-2-3-4-5
1-2-3-4-5-6

In the first case, there is only going to be one tree with one min height and that starts with 3 which is the center.
In the second case, there are two trees that are going to be with min height and that starts with 3 and 4. So, that will 
be our answer.

We can extend this appraoch to graphs with more than one path. As a result, at each step, we are going to start from
the leaves and move towrds the center. We know the leaves will only have one path so in the graph, the leaf nodes are gping
to be the one with length ==1 in their size. During each step, we will remove connections from the leaves as well as the 
neighbors they are connected to and keep doing this till we are either left with one or 2 nodes. Once we reach this level,
we have arrived at the root of the trees that will minimize the height.

Time complexity: O(V)
Space complexity: O(V+E)
*/

// My Approaches(1)
class Solution {
public:
    vector<vector<int>> graph;
    
    void addEdges(int nVertices, vector<vector<int>> edges){
        for(int i =0; i < nVertices; i++){
            vector<int>list;
            graph.push_back(list);
        }
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }
    
    void recursivelyThread(int currIndex, int currentHeight, int & maxHeight, vector<bool> visited){
        if(!visited[currIndex]){
            visited[currIndex] = true;
            maxHeight = max(maxHeight, currentHeight);
            for(int i = 0; i < graph[currIndex].size(); i++)
                recursivelyThread(graph[currIndex][i], currentHeight+1, maxHeight, visited);
        }
    }
    
    vector<int> getMHT(){
        vector<int> result;
        unordered_map<int, int> heightMap;
        int minMHT = INT_MAX, maxHeight = 0, currentHeight = 0;
        vector<bool> visited;
        
        for(int i=0; i < graph.size(); i++)
            visited.push_back(false);
        
        for(int i = 0; i < graph.size(); i++){
            recursivelyThread(i, currentHeight,maxHeight, visited);
            heightMap[i] = maxHeight;
            minMHT = min(minMHT, maxHeight);
            maxHeight = 0;
        }
        
        for(int i = 0; i < heightMap.size(); i++){
            if(heightMap[i] == minMHT)
                result.push_back(i);
        }
        return result;
    }
    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(!edges.size()){
            vector<int> list(1,0);
            return list;
        }
        else{
            addEdges(n, edges);
            return getMHT();
        }
    }
};


// Other approaches(1)
class Solution {
public:
    vector<vector<int>> graph;
    
    void addEdges(int nVertices, vector<vector<int>> edges){
        for(int i =0; i < nVertices; i++){
            vector<int>list;
            graph.push_back(list);
        }
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }
    
    
    vector<int> getMHT(int nVertices){
        vector<int> leaves;
        // find all the vertices that are leaves
        for(int i =0; i < graph.size(); i++){
            if(graph[i].size() == 1)
                leaves.push_back(i);
        }
        
        /*
        At each step we want to get rid of the leaves so we end up closer to the center of the graph.
        The center of the graph will be the point of minimum height.
        */
        while(nVertices > 2){
            nVertices -= leaves.size();
            vector<int> newLeaves;
            // get rid of the connections from the leaves and the nodes that are connected to the leaves
            for(int i = 0; i < leaves.size(); i++){
                int neighbor = graph[leaves[i]][0];
                graph[leaves[i]].clear();
                
                auto pos = find(graph[neighbor].begin(), graph[neighbor].end(), leaves[i]);
                graph[neighbor].erase(graph[neighbor].begin() + distance(graph[neighbor].begin(), pos));
                
                if(graph[neighbor].size() == 1)
                    newLeaves.push_back(neighbor);
            }   
            leaves = newLeaves;
        }
        
        return leaves;
    }
    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(!edges.size()){
            vector<int> list(1,0);
            return list;
        }
        else{
            addEdges(n, edges);
            return getMHT(n);
        }
    }
};