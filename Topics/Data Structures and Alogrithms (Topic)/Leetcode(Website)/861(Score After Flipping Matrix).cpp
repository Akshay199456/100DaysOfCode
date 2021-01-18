/*
-------------------------Question:

We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)[Doesn't work]
class Solution {
public:
    int getRowValue(vector<int> list){
        int total = list[list.size()-1], stepIncrease = 1;
        for(int i=list.size()-2; i>=0; i--){
            total += (2*stepIncrease*list[i]);
            stepIncrease *= 2;
        }
        return total;
    }
    
    int getMaxValue(int size){
        int total = 1, stepIncrease = 1;
        for(int i=size-2; i>=0; i--){
            total += (2*stepIncrease);
            stepIncrease *= 2;
        }
        return total;
    }
    
    int matrixScore(vector<vector<int>>& A) {
        int rowMax = getMaxValue(A[0].size());
        int minRowValue = INT_MAX, minRowIndex = -1;
        int total = 0;
        
        // returns row with minimum value
        for(int i=0; i<A.size(); i++){
            int rowValue = getRowValue(A[i]);
            if(rowValue < minRowValue){
                minRowValue = min(minRowValue, rowValue);
                minRowIndex = i;
            }
        }
        
        // flip row with min value to all 1s and then invert columns from other rows accordingly
        for(int j=0; j<A[minRowIndex].size(); j++){
            if(!A[minRowIndex][j]){
                for(int i=0; i<A.size(); i++){
                    A[i][j] = (A[i][j] == 0) ? 1 : 0;
                }
            }
        }
        
        // get total score by making check whether complement or the number in the row is higher
        for(int i=0;i<A.size(); i++){
            int value = getRowValue(A[i]);
            total += (value > rowMax - value) ? value : rowMax - value;
        }
        
        return total;
    }
};