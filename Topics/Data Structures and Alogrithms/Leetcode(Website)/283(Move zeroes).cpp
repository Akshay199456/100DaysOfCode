/*
-------------------------Question:

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.	
*/

/*
-------------------------    My Approaches:
1.


*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if((nums.size() == 0) || (nums.size() == 1)){
            
        }
        else{
            int zeroptr = 0, ptr = 0;
            while(ptr < nums.size()){
                if(nums[zeroptr] != 0 && nums[ptr] != 0)
                    zeroptr++;
                else if(nums[zeroptr] == 0 && nums[ptr] != 0){
                    swap(nums[zeroptr], nums[ptr]);
                    zeroptr++;
                }
                ptr++;
            }
        }
    }
};