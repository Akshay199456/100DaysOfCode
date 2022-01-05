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

1. Dynamic programming using solutions from the previous step for the current step without length restrictions

We can build up the solution for the current step using the solutions from the previous step. To each of the solutions from
the previous step, we make a copy of it and add the new element to those solutions

Time complexity: O(n*2^n)
Space complexity: O(n*2^n)


2. Dynamic programming recursive approach of My Approaches(1)

We can implement the previous approach in a recursive manner as well. As long as the currIndex is less than the length of
the array, we can keep copying elements and inserting them into the result.

Time complexity: O(n*2^n)
Space complexity: O(n*2^n)
*/

/*
-------------------------Other approaches

1. Dynamic programming using only solutions from the previous step that are 1 length away from the current step

We can implement another approach of dynamic programming but this time we will loop over the length of the combination
rather than the candidate number itself and generate all combinations for a given length

Time complexity: O(n*2^n)
Space complexity: O(n*2^n)


2. Bit generation to represent the subsets

This approach has been summarized well through comments given in the code for this approach.

Time complexity: O(n*2^n)
Space complexity: O(n*2^n)
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


// Other Approaches(1)
class Solution {
public:
    vector<vector<int>> result;
    unordered_map<int,int> elementMap;
    
    void generateSubsets(vector<int> nums, vector<vector<int>> levelCopy, int level){
        if(level < nums.size()){
            vector<vector<int>> nextLevel;
            if(level == 0){
                for(int i = 0; i < nums.size(); i++){
                    vector<int> list;
                    list.push_back(nums[i]);
                    result.push_back(list);
                    nextLevel.push_back(list);
                }
            }
            
            else{
                for(int i = 0 ; i < levelCopy.size(); i++){
                    vector<int> list = levelCopy[i];
                    int nextIndex = elementMap[list[list.size() - 1]] + 1;
                    for(int j = nextIndex; j < nums.size(); j++){
                        list = levelCopy[i];
                        list.push_back(nums[j]);
                        result.push_back(list);
                        nextLevel.push_back(list);
                    }
                }
            }
            generateSubsets(nums, nextLevel, level + 1);
        }
    }
    
    void createMap(vector<int> nums){
        for(int i = 0 ; i < nums.size(); i++)
            elementMap[nums[i]] = i;
    }
        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> list;
        result.push_back(list);
        if(nums.size()){
            createMap(nums);
            generateSubsets(nums, result, 0);
        }
        return result;
    }
};


// Other Approaches(2)
class Solution {
public:
    vector<vector<int>> result;
    
    /*
        This method returns a string representation of the integer value that is provided to it. Given a number nBits,
        we use a mask of 1 to check the status of the bit. By the operation (mask & nBits) we are basically isolating if
        the last bit is a one or not. If it is, we append a 1 to the string at the end. Else we append a 0 to the end.
        We then repeat this procedure till the number is set to 0 by the operation nBits >> 1 
    */
    string getStringRepresentation(int nBits){
        string result = "";
        int mask = 1;
        while(nBits){
            if((mask & nBits) >= 1)
                result = "1" + result;
            else
                result = "0" + result;
            
            nBits = nBits >>1;
        }
        return result;
    }
    
    /*
        Generates bit representation for each of the possible solutions for the problem since there are 2^n subsets and
        there are 2^n possible combinations of bits for each n. Hence, we associate each bit value with a subset
        combination. We want to make sure to get all the n bits corresponding to the n inputs. As a result, we use a 
        mask with 1 as its initial value and then fill it with remaining 0s by pushing it left n times. We then OR with the
        paritcular value of i so that we capture the number correponding to the bit pattern.

        Once we get the bit representation, we then check for any 1s. Whereever, we get a 1 , we push the nums associated
        with that index into the list and push it into the solution at the end.

        eg:
        For an input [1,2,3]
        0 -> 1000 -> []
        1 -> 1001 -> [3]
        2 -> 1010 -> [2]
        3 -> 1011 -> [2,3]
        ....
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        for(int i = 0; i < (int) pow(2, nums.size()); i++){
            // We use this bit masking trick to capture all the n digits.
            int nBits = (1 << nums.size()) | i;
            string bitRepresentation = getStringRepresentation(nBits).substr(1);
            vector<int> list;
            for(int i = 0; i <bitRepresentation.size(); i++){
                if(bitRepresentation[i] == '1')
                    list.push_back(nums[i]);
            }
            result.push_back(list);
        }
        return result;
    }
};