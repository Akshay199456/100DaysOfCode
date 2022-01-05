/*
-------------------------Question:

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:


Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
Example 2:


Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.
 

Follow up:

Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?
*/

/*
-------------------------    My Approaches:
1. In-place change of state

We change the initialState to an intermediate state that helps us identify what the initial State was and what the final State will be. This way, we can maniuplate the board in place without having to use up extra space. Once we know
this information, we determine thje final state of a;; the elemnts and represent them with these placeholder values. Finally, we convert the placeholder values back to the final state and return that as the output.

Time complexity: O(mn)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// MY Approaches(1)
class Solution {
public:
    
    int getLiveCount(vector<vector<int>> board, int i, int j, vector<int> possibleX, vector<int> possibleY){
        int liveNeighbors = 0;
        for(int x = 0; x< possibleX.size(); x++){
            for(int y=0; y< possibleY.size(); y++){
                if(((i + possibleX[x] >=0) && (j + possibleY[y] >= 0) && (i + possibleX[x] < board.size()) && (j + possibleY[y] < board[0].size())) && (board[i+possibleX[x]][j + possibleY[y]] == 1 || board[i+possibleX[x]][j + possibleY[y]] == 5 || board[i+possibleX[x]][j + possibleY[y]] == 4)){
                    if(possibleX[x] == 0 && possibleY[y] == 0){  
                    }
                    else
                        liveNeighbors++;
                }
            }
        }
        return liveNeighbors;
    }
    
    int getIntermediateState(int originalState, int finalState){
        if(originalState == finalState){
            if(originalState == 0)
                return 2;
            else
                return 5;
        }
        else{
            if(originalState == 0)
                return 3;
            else
                return 4;
        }
    }
    
    void fillIntermediateStates(vector<vector<int>> & board, vector<int> possibleX, vector<int> possibleY){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                int originalState = board[i][j];
                int finalState = 0;
                
                // get no of live neighbors
                int liveNeighbors = getLiveCount(board, i,j, possibleX, possibleY);
                
                // apply rules to determine final state
                if(originalState == 1){
                    if(liveNeighbors == 2 || liveNeighbors == 3)
                        finalState = 1;
                }
                else if(liveNeighbors == 3)
                    finalState = 1;
                
                // fill with intermediate results to populate later
                board[i][j] = getIntermediateState(originalState, finalState);
                // cout<<"i: "<<i<<" j: "<<j<<" Original state: "<<originalState<<" Final state: "<<finalState<<" liveNeighbors: "<<liveNeighbors<<" Intermediate state: "<<board[i][j]<<endl;
            }
        }
    }
    
    void fillFinalStates(vector<vector<int>> & board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 3 || board[i][j] == 5)
                board[i][j] = 1;
            else
                board[i][j] = 0;       
            }
        }
    }
    
    void printBoard(vector<vector<int>> board){
        cout<<"Printing intermediate state \n\n";
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> possibleX {-1,0,1}, possibleY {-1,0,1};
        // fill the current board with the 4 possible intermediate states that can exist
        fillIntermediateStates(board, possibleX, possibleY);
        // printBoard(board);
        // refill the board with the final states
        fillFinalStates(board);
    }
};