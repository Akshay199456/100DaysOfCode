/*
-------------------------Question:

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

/*
-------------------------    My Approaches:
1. Backtracking approach

We can use the backtracking approach to solve this problem. Whenevre we place a new queen, we want to make sure it doesn't intersect with other queens tha came before it in any way. Once we have placed all the queens, we can then store
the solution to that problem.

Time complexity: O(n!)
Space complexity: O()
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    bool checkNoCollision(int i, int nQueens, unordered_set<int> & xUsed, vector<vector<int>> & pairUsed){
        // check for collision along x axis
        if(xUsed.find(i) != xUsed.end())
            return false;
        
        // check for diagonal collision
        for(int index = 0; index < pairUsed.size(); index++){
            vector<int> currentPair = pairUsed[index];
            
            // primary diagonal
            if(i - nQueens == currentPair[0] - currentPair[1])
                return false;
            
            // secondary diagonal
            if(i + nQueens == currentPair[0] + currentPair[1])
                return false;
        }
        
        return true;
    }
        
    void placeQueens(vector<string> & board, int nQueens, unordered_set<int> xUsed, vector<vector<int>> pairUsed, vector<vector<string>> & result){
        if(nQueens == board.size())
            result.push_back(board);
        
        for(int i=0; i<board.size(); i++){
            if(checkNoCollision(i, nQueens, xUsed, pairUsed)){
                vector<int> list{i,nQueens};
                
                // initialize conditions
                board[i][nQueens] = 'Q';
                xUsed.emplace(i);
                pairUsed.push_back(list);
                //printSolution(board);
                
                // recursive call
                placeQueens(board, nQueens+1, xUsed, pairUsed, result);
                
                // reset conditions
                board[i][nQueens] = '.';
                xUsed.erase(i);
                pairUsed.pop_back();
            }
        }
    }
    
    void initializeBoard(vector<string> & board, int n){
        for(int i=0; i<n; i++){
            string tempString = "";
            for(int j=0; j<n; j++)
                tempString.push_back('.');
            board.push_back(tempString);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board;
        unordered_set<int> xUsed;
        vector<vector<int>> pairUsed;
        
        initializeBoard(board, n);
        placeQueens(board, 0, xUsed, pairUsed, result);
        return result;
    }
};