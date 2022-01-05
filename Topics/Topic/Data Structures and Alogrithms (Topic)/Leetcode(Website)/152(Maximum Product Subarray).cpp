/*
-------------------------Question:

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches
1. Using same principle as Pb 53: Maximum Subarray

If we only had positive elements including 0 in this problem, then our max would be obtained by either extending the current
max or by starting the calculations from the ucrrent index. However, we are given that there are also negative numbers in
this array. In that case, if our max is +ve and the current element in +ve, then our max comes from extending the subarray.
However, we can also generate a max from our min if our min is -ve and our current element is -ve. As a result, at each
stage, we keep track of both the max and the min that are possible for the current index. This way, if our next element
is +ve,we generate our max from previous max else if our next element is -ve, them the max is generated from the min. 

Time complexity: O(n)
Space complexity: O(1)

*/

// Other approaches(1)
class Solution {
public:
    int getMaxProduct(vector<int> nums){
        int globalMax = nums[0], currentMax = nums[0], currentMin = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int tempMax = max(max(currentMax * nums[i], currentMin * nums[i]), nums[i]);
            int tempMin = min(min(currentMax * nums[i], currentMin * nums[i]), nums[i]);
            
            currentMax = tempMax;
            currentMin = tempMin;
            globalMax = max(currentMax, globalMax);
        }
        return globalMax;
    }
    
    int maxProduct(vector<int>& nums) {
        if(nums.size())
            return getMaxProduct(nums);
        return 0;
    }
};