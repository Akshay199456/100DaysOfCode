/*
-------------------------Question:

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/


/*
-------------------------My Approaches:

1. Double for loops

We can use a double for loop to caluclate the sum from adjacent elements on the previous level and
add it into the current level.

Time complexity: O(n^2)
Space complexity: O(n^2)
*/


// My Approaches(1)
class Solution {
public:
    vector<vector<int>> generatePattern(vector<vector<int>> & result, int numRows){
        vector<int> level(1, 1);
        result.push_back(level);
        if(numRows == 1)
            return result;
        else{
            for(int i = 1; i < numRows; i++){
                vector<int> prevLevel = result[i-1];
                vector<int> currLevel(1,1);
                for(int j = 1; j < prevLevel.size(); j++)
                    currLevel.push_back(prevLevel[j] + prevLevel[j-1]);
                currLevel.push_back(1);
                result.push_back(currLevel);
            }
        }
        return result;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0)
            return result;
        else{
            return generatePattern(result, numRows);
        }
    }
};