/*
*/

/*
*/

/*
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