/*
-------------------------Question:
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:

Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
 

Example 2:

Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

 

Constraints:

1 <= N <= 200
M[i][i] == 1
M[i][j] == M[j][i]


*/

/*
-------------------------    My Approaches:
1. DFS approach based on grpah problem

This problem can be a visualized a graph based problem. As a result, we can use dfs to find the connected components with
each other. We do this for all the elements with 1. This gives us the toal number of friend groups

Time complexity: O(n^2)
Space complexity: O(n)

*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    vector<vector
    unordered_set<int> visited;
    
    void recursiveSearch(vector<vector<int>> & M, int index){
        for(int j = 0; j < M.size(); j++){
            if(M[index][j]==1){
                M[index][j] = 0;
                if(visited.find(j) == visited.end()){
                    visited.emplace(j);
                    recursiveSearch(M, j);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        for(int i = 0; i < M.size(); i++){
            for(int j =0; j < M.size(); j++){
                if(M[i][j] == 1){
                    visited.emplace(i);
                    recursiveSearch(M, i);
                    ++count;
                }
            }
        }
        return count;
    }
};