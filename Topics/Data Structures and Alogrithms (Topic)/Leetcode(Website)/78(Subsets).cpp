/*
-------------------------Question:

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

/*
-------------------------My Approaches:

1. Dynamic programming

We can build up the solution for the current step using the solutions from the previous step. To each of the solutions from
the previous step, we make a copy of it and add the new element to those solutions

Time complexity: O(2^n)
Space complexity: O(2^n)


2. Recursive approach

We can implement the previous approach in a recursive manner as well. As long as the currIndex is less than the length of
the array, we can keep copying elements and inserting them into the result.

Time complexity: O(2^n)
Space complexity: O(2^n)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    vector<vector<int>> result;
    
    void generateSubsets(vector<int> nums){
        for(int i = 0; i < nums.size(); i++){
            int size = result.size();
            for(int j = 0; j < size; j++){
                vector<int> listCopy = result[j];
                listCopy.push_back(nums[i]);
                result.push_back(listCopy);
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums){
        vector<int> list;
        result.push_back(list);
        if(nums.size())
            generateSubsets(nums);
        return result;
    }
};

// My Approaches(2)
class Solution {
public:
    vector<vector<int>> result;
    
    void generateSubsets(vector<int> & nums, int currIndex){
        if(currIndex < nums.size()){
            int size = result.size();
            for(int i = 0; i < size; i++){
                vector<int> listCopy = result[i];
                listCopy.push_back(nums[currIndex]);
                result.push_back(listCopy);
            }
            generateSubsets(nums, currIndex + 1);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> list;
        result.push_back(list);
        if(nums.size())
            generateSubsets(nums, 0);
        return result;
    }
};