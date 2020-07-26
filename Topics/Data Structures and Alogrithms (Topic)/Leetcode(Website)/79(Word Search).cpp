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

1. Backtracking using the UMPIRE method

We can use backtracking here to solve this problem. If the current character matches with the charcter in the board, we 
continue finding path from it that only visits nodes that have not been visited before. At any stage if the character
doesn't match, we return false instead and explore a different path as no solution can be obtained from the current path.
If all the characters match then we have obtained a solution and we can say that it exists in the 2d array and return true. 
Since the  only possible paths the next character can exist given the current character matches is left, right, top and bottom, 
we explore those paths to find the match of the next character.

Time complexity: O(n^2)
Space complexity: O(n^2)

A main reason I feel I did well on this problem is by following the UMPIRE method from codepath properly. Using it as a 
guiding material while solving the problem helped me understand the different stages to the problem clearly without
spending too much time on any one stage. A key aspect that I understood here is that the P - planning and I - implement
stage and inversely proportional to each other. The better planned your approach is, the less time it takes to implement
the code as you have planned approaches to the different scenarios that might occur. Therefore, you want to spend more time
in planning th eproblem before actually implmenting the code. The less time you take in planning, the more time you will 
take in implementing the code and you will fumble through the code as well.

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
