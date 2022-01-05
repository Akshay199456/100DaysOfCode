/*
-------------------------Question:
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

/*
-------------------------    My Approaches:
1. DFS on graph based problem.

Since this problem can be represented as a graph, we can traveerse through it with DFS. We first check the corners since
any O that is connected to the O at the corner, either directly or indirectly, also bcomes a part of it and can't be 
flipped. We repreent these with '#'. After that, any O that is remaning is not connected to the corners, so we can flip 
them while the Os which have been converted to # can be reset to Os.

Time complexity: O(mn)
Space complexity: O(m+n)

*/

/*
-------------------------    Other approaches:

*/

// MY Approaches(1)
class Solution {
public:
    void recursiveSearch(vector<vector<char>> & board, int i, int j){
        if(i >=0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j] == 'O'){
            // Setting O's connected to border as #
            board[i][j] = '#';
            recursiveSearch(board, i, j+1);
            recursiveSearch(board, i, j-1);
            recursiveSearch(board, i+1, j);
            recursiveSearch(board, i-1, j);
        }
    }
    
    void printList(vector<int> array){
        for(int i = 0; i < array.size(); i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
    
    void printBoard(vector<vector<char>> board){
        for(int i=0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size()){
            vector<int> rowIndices{0, (int) board.size()-1};
            vector<int> colIndices{0, (int) board[0].size()-1};
            
            // checking the row ends for connected 0s
            for(int i = 0; i < rowIndices.size(); i++){
                for(int j = 0; j < board[0].size(); j++){
                    if(board[rowIndices[i]][j] == 'O')
                        recursiveSearch(board, rowIndices[i], j);
                }
            }
            
            // checking the column ends for connected 0s
            for(int j = 0; j < colIndices.size(); j++){
                for(int i = 0; i < board.size(); i++){
                    if(board[i][colIndices[j]] == 'O')
                        recursiveSearch(board, i, colIndices[j]);
                }
            }
            
            // flipping surrounded regions
            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[0].size(); j++){
                    if(board[i][j] == '#')
                        board[i][j] = 'O';
                    else if(board[i][j] == 'O')
                        board[i][j] = 'X';
                }
            }
        }
    }
};