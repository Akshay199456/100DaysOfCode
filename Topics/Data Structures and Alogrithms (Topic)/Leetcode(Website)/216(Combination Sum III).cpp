/*
-------------------------Question:

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations. [1,2,1] is not valid because 1 is used twice.
Example 4:

Input: k = 3, n = 2
Output: []
Explanation: There are no valid combinations.
Example 5:

Input: k = 9, n = 45
Output: [[1,2,3,4,5,6,7,8,9]]
Explanation:
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
​​​​​​​There are no other valid combinations.
 

Constraints:

2 <= k <= 9
1 <= n <= 60
*/

/*
-------------------------    My Approaches:
1. Backtracking

We can use backtracking here to find the soluton to the problem. With backtracking, whenever find a valid solution we add it to the result, else we keep searching as long as the number of leements in the list is less than k.

Time complexity: O(9Ck * k)
Space complexity: O(9Ck * k)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void generateCombinations(vector<vector<int>> & result, vector<int> list, int k, int n, int startIndex){
        if(list.size() == k && accumulate(list.begin(), list.end(), 0) == n)
            result.push_back(list);
        else if(list.size() < k){
            for(int i= startIndex; i<=9; i++){
                list.push_back(i);
                generateCombinations(result, list, k, n, i+1);
                list.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> list;
        generateCombinations(result, list, k, n, 1);
        return result;
    }
};