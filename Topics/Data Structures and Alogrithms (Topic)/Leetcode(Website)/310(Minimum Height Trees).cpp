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