/*
-------------------------Question:

In an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

 

Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Example 2:

Input: n = 1, k = 0, row = 0, column = 0
Output: 1.00000
 

Constraints:

1 <= n <= 25
0 <= k <= 100
0 <= row, column <= n
*/

/*
-------------------------    My Approaches:
1. Backtracking

We can use the backtracking approach in order to figure out after K moves we are still on the baord or not. If so, we can add it to the totalMoves possible. At the end, we divide this number by the total number of moves which were physically
possible.

Time complexity: O(8^k)
Space complexity: O(k)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void findMoves(int N, int K, int r, int c, int & validMoves, vector<int> possiblePositions){
        if(!(r < 0 || c < 0 || r > N-1 || c > N-1)){
            if(!K)
                validMoves += 1;
            else{
                for(int i=0; i<possiblePositions.size(); i++){
                    for(int j=0; j<possiblePositions.size(); j++){
                        if(abs(possiblePositions[i]) != abs(possiblePositions[j]))
                            findMoves(N, K-1, r + possiblePositions[i], c + possiblePositions[j], validMoves, possiblePositions);
                    }
                }
            }
        }
    }
    
    double knightProbability(int N, int K, int r, int c) {
        double totalMoves = pow(8.0, K);
        int validMoves = 0;
        vector<int> possiblePositions {-2,-1,1,2};
        findMoves(N, K, r, c, validMoves, possiblePositions);
        return validMoves / totalMoves;
    }
};