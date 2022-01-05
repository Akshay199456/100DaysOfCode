/*
-------------------------Question:

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

/*
-------------------------    My Approaches:
1. Using storage arrays to store intermediate results

If we observe the calulcations that we are interested in, the anseer for each position is the product of all integers to its left and all integers to the right. As a result, we can use this property in order to store the results into 2
different arrays which store the results of the left and right up till that point. We then multiply these two to get the final result.

Time complexity: O(n)
Space complexity: O(n)


2. Space efficiency

Instead of using two different arrays for storing the intermediate calculations, we can use the output array in order to fill our results as we go along

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct(nums.size(), 1), rightProduct(nums.size(), 1);
        vector<int> result;
        
        // fill left Product
        for(int i=1; i<nums.size(); i++)
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
        
        // fill right product
        for(int i=nums.size() - 2; i>=0; i--)
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        
        // multiply both to get final answer
        for(int i=0; i<nums.size(); i++)
            result.push_back(leftProduct[i] * rightProduct[i]);
        
        return result;
    }
};


// My Approahces(2)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int cumProduct = 1;
        
        // fill left Product
        for(int i=0; i<nums.size(); i++){
            if(!i)
                result.push_back(1);
            else
                result.push_back(result[i-1] * nums[i-1]);    
        }
            
        // fill right product
        for(int i=nums.size()-2; i>=0; i--){
            cumProduct = cumProduct * nums[i+1];
            result[i] = cumProduct * result[i];
        }
        
        return result;
    }
};