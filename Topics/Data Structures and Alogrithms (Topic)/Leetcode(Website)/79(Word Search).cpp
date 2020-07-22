/*
-------------------------Question:

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    void createMatrix(vector<vector<bool>> & occurrenceMatrix, int r, int c){
        for(int i = 0; i < r; i++){
            vector<bool> list;
            for(int j =0; j < c; j++)
                list.push_back(false);
            occurrenceMatrix.push_back(list);
        }
    }
    
    bool arrayDFS(int i, int j, string word, vector<vector<bool>> occurrenceMatrix, int curWordPos, vector<vector<char>> board){
        if(i >= 0 && i < board.size() && j>=0 && j < board[i].size()){
            if((word[curWordPos] == board[i][j]) && !occurrenceMatrix[i][j]){
                occurrenceMatrix[i][j] = true;
                if(curWordPos == word.size() - 1)
                    return true;
                return( arrayDFS(i,j+1, word, occurrenceMatrix, curWordPos + 1, board) || arrayDFS(i+1,j, word, occurrenceMatrix, curWordPos + 1, board) || arrayDFS(i,j-1, word, occurrenceMatrix, curWordPos + 1, board) || arrayDFS(i-1,j, word, occurrenceMatrix, curWordPos + 1, board));
            }
            return false;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> occurrenceMatrix;
        if(board.size() && word.size()){
            createMatrix(occurrenceMatrix, board.size(), board[0].size());
        
            for(int i=0; i<board.size(); i++){
                for(int j=0; j<board[i].size(); j++){
                    bool status = arrayDFS(i,j, word, occurrenceMatrix, 0, board);
                    if(status)
                        return true;
                }
            }
        }
        return false;
    }
};
