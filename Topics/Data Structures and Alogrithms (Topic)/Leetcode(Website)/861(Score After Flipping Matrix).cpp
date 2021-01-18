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
1. Greedy Approach

Since the goal of the problem is to maximize the score, we can look at this problem as a greedy approach problem. If we want to maximize the score, we want to maximize each the value that is possible, so that the the toal score is
maximized. If we obsserve the columns of the matrix, we notice that the first column on the left has more weight as compared to the other columns. For example, if we were to compare 0011 and 1011, the latter number is higher, because
primarily of the 1 set on the first column in 1011. As a result, it contributes to more than half of the total of the value. As a result, our goal is to maximize the first column for each of the rows that allows us to maximize the score.
Once we do that, for the other columns,we just want to maximize the total number of 1s we can obtain from those columns. We do this by calculating the number of 1s in that column that we have after toggling and comparing it to the
coplement of it. Whichever is higher, that is what we want in that column across the matrix. We then multiply this with the value associated with that column and get the toal score that is the maximum

Time complexity: O(mn)
Space complexity: O(1)

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


// Other Approaches(1)
class Solution {
public:
    void toggleRow(vector<int> & list){
        for(int i=0; i<list.size(); i++){
            list[i] = list[i] ^ 1;
        }
    }
    
    int matrixScore(vector<vector<int>>& A) {
        int total = 0, stepIncrease = 1;
        // maximize first column by converitng to all 1s in athat column.
        for(int i=0; i < A.size(); i++){
            if(!A[i][0]){
                toggleRow(A[i]);
            }
        }
        
        // maximize the number of 1s from remaingin columns
        for(int j=A[0].size()-1; j>=0; j--){
            // get total number of 1s in a particular column
            int oneNumber = 0;
            for(int i=0; i<A.size(); i++){
                if(A[i][j])
                    oneNumber++;
            }
            
            total +=  stepIncrease * max(oneNumber, (int)(A.size()) - oneNumber);
            stepIncrease *= 2;
        }
        
        return total;
    }
};