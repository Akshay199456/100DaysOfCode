/*
-------------------------Question:

You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:

0 means the cell cannot be walked through.
1 represents an empty cell that can be walked through.
A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).

Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.

You are guaranteed that no two trees have the same height, and there is at least one tree needs to be cut off.

 

Example 1:


Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
Output: 6
Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.
Example 2:


Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
Output: -1
Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.
Example 3:

Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
Output: 6
Explanation: You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.
 

Constraints:

m == forest.length
n == forest[i].length
1 <= m, n <= 50
0 <= forest[i][j] <= 109
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Using a pioirty queue and bfs

We use a prioirty queue in order to decide the next shortest in order to cut it. We then use BFS starting at the 0,0 to find the location of the enxt tree and the no of steps it would take to get to that tree. Once we do that,
we repeat the same process for each and every tree that remains in teh prioity queue

Time complexity: O((mn)^2)
Space complexity: O(mn)
*/

// Other Approaches(1)
class Solution {
public:
    typedef pair<int,pair<int,int>> pi;
    
    struct pair_hash{
        template <class T1, class T2> size_t operator () (pair<T1,T2> const & pair) const {
            size_t h1 = hash<T1>()(pair.first);
            size_t h2 = hash<T2>()(pair.second);
            return h1 ^ h2;
        }
    };
    
    void fillHeap(vector<vector<int>> & forest, priority_queue<pi, vector<pi>, greater<pi>> & pq){
        for(int i=0; i< forest.size(); i++){
            for(int j=0; j < forest[0].size(); j++){
                if(forest[i][j] > 1)
                    pq.push(make_pair(forest[i][j], make_pair(i,j)));
            }
        }
    }
    
    int bfs(pi & topTree, int sourceX, int sourceY, vector<vector<int>> & forest){
        int destX = topTree.second.first;
        int destY = topTree.second.second;
        int nSteps = 0;
        queue<pair<int,int>> elements;
        vector<vector<int>> visited(forest.size(), vector<int>(forest[0].size(), 0));
        vector<vector<int>> directions {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        
        elements.push(make_pair(sourceX, sourceY));
        visited[sourceX][sourceY] = 1;
        
        while(!elements.empty()){
            int size = elements.size();
            for(int i =0; i < size; i++){
                pair<int, int> currentPair = elements.front();
                elements.pop();
                
                if(currentPair.first == destX && currentPair.second == destY)
                    return nSteps;
                else{
                    for(int i=0; i < directions.size(); i++){
                        int potX = currentPair.first + directions[i][0], potY = currentPair.second + directions[i][1];
                        if(potX >= 0 && potX < forest.size() && potY >= 0 && potY < forest[0].size() && forest[potX][potY] && visited[potX][potY] != 1){
                            visited[potX][potY] = 1;
                            elements.push(make_pair(potX, potY));
                        }
                    }
                }
            }
            nSteps++;
        }
        
        return -1;
    }
    
    int getMinSteps(vector<vector<int>> & forest){
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int totalSteps = 0;
        int sourceX = 0, sourceY = 0;
        
        // define heap to store order of trees
        fillHeap(forest, pq);
        
        while(!pq.empty()){
            // get next tree to cut 
            pi topTree = pq.top();
            pq.pop();
            int nSteps = bfs(topTree, sourceX, sourceY, forest);
            
            // no path available
            if(nSteps == -1)
                return -1;
            
            // path Available
            totalSteps += nSteps;
            
            // change start point to the new coordinates
            sourceX = topTree.second.first;
            sourceY = topTree.second.second;
        }
        return totalSteps;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        return getMinSteps(forest);
    }
};