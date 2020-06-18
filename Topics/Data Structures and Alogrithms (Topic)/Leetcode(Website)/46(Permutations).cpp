/*
-------------------------Question:

Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*
-------------------------My Approaches:

1. Dynamic programming approach

We can implement this problem using dynamic programming. If we observe carefully, the
solution for this problem for the current step can be obtained by taking the solutions
from the previous problem. Since the problem exhibits both optimal substructure and
overlapping subproblems, we can use DP. We go over the nums array to generate the final
soltion. To obtain the solution for the current step, we add the element at the current
index at different positions of the solutions obtained in the previous step. This way
we build the current solution on previous solutions. 

Time complexity: O(n!)
Space complexity: O(n!)

*/

/*
-------------------------Other approaches

1. Recursive backtracking approach

We can also solve this problem recursively. The key gist of this approach is that you
want to keep adding elements into the array till the length of the list is equal to the
length of the nums array. One thing to make sure though is that you don't want to be
storing the state at each level. If you do, you want to get id of it for the next
iteration to take the next element in the array into consideration.

Time complexity: O(n!)
Space complexity: O(n!)
*/

// My Approaches(1)
class Solution {
public:
    void generatePermutations(vector<int> nums, vector<vector<int>> & result){
        for(int i = 1; i < nums.size(); i++){
            vector<vector<int>> newResult;
            for(int j = 0; j < result.size(); j++){
                int insertIndex = 0;
                for(int k = 0; k < i + 1; k++){
                    vector<int> list;
                    bool isInserted = false;
                    for(int l = 0; l < result[j].size(); l++){
                        if(insertIndex == l && !isInserted){
                            isInserted = true;
                            list.push_back(nums[i]);
                            l--;
                        }
                        else
                            list.push_back(result[j][l]);
                    }
                    if(!isInserted)
                        list.push_back(nums[i]);
                    insertIndex++;
                    newResult.push_back(list);
                }
            }
            result = newResult;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> list;
        if(nums.size()){
            list.push_back(nums[0]);
            result.push_back(list);
            generatePermutations(nums, result);
        }
        else
            result.push_back(list);
        return result;
    }
};


// Other Approaches(1)
class Solution {
public:
    vector<vector<int>> result;
    void generatePermutations(vector<int> nums, unordered_set<int> elementSet, vector<int> list, int n){
        if(list.size() == n)
            result.push_back(list);
        else{
            for(int i = 0; i < nums.size(); i++){
                if(elementSet.find(nums[i]) == elementSet.end()){
                    vector<int> listCopy = list;
                    unordered_set<int> elementSetCopy = elementSet;
                    listCopy.push_back(nums[i]);
                    elementSetCopy.emplace(nums[i]);
                    generatePermutations(nums, elementSetCopy, listCopy, n);
                }
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> list;
        unordered_set<int> elementSet;
        if(nums.size())
            generatePermutations(nums, elementSet, list, nums.size());
        return result;
    }
};