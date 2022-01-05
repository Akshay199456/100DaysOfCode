/*
-------------------------Question:
iven two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n
*/

/*
-------------------------    My Approaches:
1. Backtracking approach

We can use the backtracking approach here to generate all possible solutions. If we find a complete solution, we insert it into the result

Time complexity: O(nCk)
Space complexity: O(nCk)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void fillCombinations(vector<vector<int>> & result, vector<int> list, int n, int k, int startIndex){
        if(list.size() == k)
            result.push_back(list);
        else{
            for(int i = startIndex; i<=n; i++){
                list.push_back(i);
                fillCombinations(result, list, n, k, i+1);
                list.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> list;
        fillCombinations(result, list, n, k, 1);
        return result;
    }
};

