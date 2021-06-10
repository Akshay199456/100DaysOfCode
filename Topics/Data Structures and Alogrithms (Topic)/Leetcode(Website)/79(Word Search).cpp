// This problem was also solved using the UMPIRE approach

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

1. Backtracking

We can apply the bracktracking approach to solve this problem. If we find a character that matches the current index, we can search its neighbors for the next character and so on. If at the end, we arrive at the end of word, then
we have found the word else we have not.

Time complexity: O(mnk) whre k is length of word
Space complexity: O(max(m,n))


*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    bool findWord(vector<vector<char>> & board, string word, int index, int i, int j){
        if(index == word.size())
            return true;
        else if(i >= 0 && i < board.size() && j>=0 && j < board[0].size() && board[i][j] == word[index]){
            char beforeChar = board[i][j];
            board[i][j] = '#';
            bool result =  findWord(board, word, index+1, i-1, j) || findWord(board, word, index+1, i+1, j) || findWord(board, word, index+1, i, j-1) || findWord(board, word, index+1, i, j+1);
            board[i][j] = beforeChar;
            return result;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0] && findWord(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
