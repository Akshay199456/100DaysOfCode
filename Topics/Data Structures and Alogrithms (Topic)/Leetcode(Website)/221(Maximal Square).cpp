/*
-------------------------Question:

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Brute Force approach

Using the brute force appraoch, when we find a 1, we knwo that we can have a square with area 1 and can expand that to 2 to see if that is a valid combination. If it is, then there must be 1s in the new row and column and we coan continue the 
same, till we reach an invalid index.

Time complexity: O(mn)^2
Space complexity: O(1)
*/

// Other approaches(1)
class Solution {
public:
    void getMaximalSquare(int i, int j, int & maxSquare, vector<vector<char>> & matrix, bool & oneEncountered){
        if(matrix[i][j] == '1'){
            oneEncountered = true;
            int currSquare = 1;
            bool isValid = true;
            while(i+ currSquare < matrix.size() && j + currSquare < matrix[0].size() && isValid){
                // check if the new row has only 1s
                for(int k=j; k<= j+ currSquare && isValid; k++){
                    if(matrix[i + currSquare][k] == '0')
                        isValid = false;
                }
                
                // check if the new column has only 1s
                for(int k=i; k <= i + currSquare && isValid; k++){
                    if(matrix[k][j + currSquare] == '0')
                        isValid = false;
                }
                
                // get status if new row and column only contained 1s
                if(isValid){
                    currSquare++;
                    maxSquare = max(maxSquare, currSquare);
                }
            }
        }
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSquare = 0;
        bool oneEncountered = false;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j< matrix[0].size(); j++){
                getMaximalSquare(i,j, maxSquare, matrix, oneEncountered);
            }
        }
        
        return  (!maxSquare) ? (oneEncountered ? 1 : 0 ) : (maxSquare * maxSquare);
    }
};


// Other Approaches(2)
class Solution {
public:
    int getMinimum(vector<int> & xList, vector<int> & yList, int maxRows, int maxCols, vector<vector<int>> & dpMatrix){
        vector<int> minValues;
        for(int i=0; i<xList.size(); i++){
            if(xList[i] < 0 || xList[i] > maxRows-1 || yList[i] < 0 || yList[i] > maxCols-1)
                minValues.push_back(0);
            else
                minValues.push_back(dpMatrix[xList[i]][yList[i]]);
        }
        
        // getMinimum of those values
        int currMin = INT_MAX;
        for(int i=0; i<minValues.size(); i++)
            currMin = min(currMin, minValues[i]);
        
        return currMin;
    }
    
    int getMaximalLength(vector<vector<char>> & matrix, vector<vector<int>> & dpMatrix){
        int maxLength = 0;
        
        // initialize matrix
        for(int i=0; i<matrix.size(); i++){
            vector<int> list(matrix[0].size(), 0);
            dpMatrix.push_back(list);
        }
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    vector<int> xList{i-1,i-1,i};
                    vector<int> yList{j-1,j,j-1};
                    dpMatrix[i][j] = getMinimum(xList, yList, matrix.size(), matrix[0].size(), dpMatrix) + 1;
                    maxLength = max(maxLength, dpMatrix[i][j]);
                }
            }
        }
        return maxLength;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dpMatrix;
        int maxLength = getMaximalLength(matrix, dpMatrix);
        return maxLength * maxLength;
    }
};