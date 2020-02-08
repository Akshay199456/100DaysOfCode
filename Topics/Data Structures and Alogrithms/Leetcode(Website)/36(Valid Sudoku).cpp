/*
-------------------------Question:
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/

/*
-------------------------    My Approaches:

Unfortunately, I wasn't able to figure out a concise solution to solving this problem. When I initially
planned out this problem, I intended to use an array of hashmaps to solve this problem. However, as I
solved using this approach more and more, I started to understand that the solution that I was coming
up with was being hard coded more and more rather than it being a generic solution to the problem at 
hand. As I had spent quite a lot of time trying to code it out, I decided to understand one of the top 
rated solution that was given.
*/

/*
-------------------------    Other approaches:

1. Using 3 arrays to keep track of the occurrence of the element across the row, column and grid (Check
 the **Helping Images** folder with respect to this particular problem to get a better understanding 
 of the approach that was utilized).

 Basically, checkRowMatrix had its row number as the row where the element would occur while its column 
 was the element + 1. Similarly, checkColumnMatrix had its row number as the column where the element 
 would occur while its column was the element + 1. Similarly, checkRowMatrix had its row number as the 
 box where the element would occur while its column was the element + 1.

 Having these 3 arrays made it really easy to check if an element had already occurred. If it did, we 
 returned false, else we make sure to set that particular entry in all the 3 arrays to true to confirm 
 we have encountered the element.
*/

class Solution {
public:
    static const int LEVELS = 9;
    
    void initializeMatrix(bool matrix[][LEVELS]){
        for(int i = 0; i < LEVELS; i++)
            for(int j = 0; j < LEVELS; j++)
                matrix[i][j] = false;
    }
    
    bool checkValidSolution(vector<vector<char>> board){
        bool checkRowMatrix[LEVELS][LEVELS] = {false}, checkColumnMatrix[LEVELS][LEVELS] = {false}, checkBoxMatrix[LEVELS][LEVELS] = {false};
        initializeMatrix(checkRowMatrix);
        initializeMatrix(checkColumnMatrix);
        initializeMatrix(checkBoxMatrix);
        for( int iIndex = 0; iIndex < LEVELS; iIndex++){
            for(int jIndex = 0; jIndex < LEVELS; jIndex++){
                if(board[iIndex][jIndex] != '.'){
                    int boxNumber = ((iIndex/3) * 3) + (jIndex/3);
                    int element = board[iIndex][jIndex] - '1';
                    if(checkRowMatrix[iIndex][element] || checkColumnMatrix[jIndex][element] || checkBoxMatrix[boxNumber][element])
                        return false;
                    
                    checkRowMatrix[iIndex][element] = true;
                    checkColumnMatrix[jIndex][element] = true;
                    checkBoxMatrix[boxNumber][element] = true;
                    // displayBoard(iIndex, jIndex);
                }
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkValidSolution(board);    
    }
};