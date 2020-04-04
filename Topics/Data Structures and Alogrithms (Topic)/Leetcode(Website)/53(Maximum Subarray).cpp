/*
-------------------------Question:

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
/*

/*
-------------------------Other approaches

1. Have written a lot about this approach in pages and have attached them in the 'Helping Images'
folder which will provide a great explanation to the solution. 

The key here is to optimize the whole problem by optimizing the sub problem thereby being a dynamic
programming problem.

Time complexity: O(n)
Space complexity: O(1)
*/

// Other Approaches(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        if(nums.size() == 0)
            return INT_MIN;
        else{
            int current_max, global_max;
            current_max = global_max = nums[0];
            
            for(int i = 1 ; i < nums.size(); i++){
                current_max = max(nums[i], nums[i] + current_max);
                if(current_max > global_max)
                    global_max = current_max;
            }         
            return global_max;
        }
    }
};