/*

*/
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