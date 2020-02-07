/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/*
-------------------------    My Approaches:

1. Using hashmap to store element along with index

With each iteration of the loop, we check if target - nums[index] is present in the map. If it isn't,
we add nums[index] to the map. If it is present, we add the index of the element in the map as well as
the index of the current element in a vector and return it.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Brute force approach: 

1. (Worse)

For each element in the vector, we can check if the target- nums[index] exists. If it does, we return a 
vector with those indices

Time complexity: O(n^2)
Space complexity: O(1)

*/

// My approaches(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroptr = 0;
        for(int index = 0; index < nums.size(); index++){
            if(nums[index] != 0)
                nums[zeroptr++] = nums[index];
        }
        
        while(zeroptr < nums.size())
            nums[zeroptr++] = 0;
    }
};