/*
-------------------------Question:

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

/*
-------------------------My Approaches:
1. Using two pointer approach.

We can use the two pointer approach here to help solve this problem. Initially, we can use the two pointers to understand
where in the subarray teh sorting needs to take place. Once we get that info, we want to make sure to get the min and max
in that subarray. This is needed because we are not going over the continuous subarray. So, if there is a min and max in the
subarray that is less than / greater than the elements outside the subarray, we adjust the subarray acfcordingly as those
elements will need to be sorted as well

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    pair<int, int> getMinMax(int left, int right, vector<int> nums){
        int min = nums[left], max = nums[left];
        int temp = left + 1;
        while(temp <= right){
            if(nums[temp] < min)
                min = nums[temp];
            if(nums[temp] > max)
                max = nums[temp];
            temp++;
        }
        return make_pair(min,max);
    }
    
    int getLengthUnsorted(vector<int> nums){
        int left = 0, right = nums.size() - 1;
        int isLeftFound = false, isRightFound = false;
        
        // scan left
        while(!isLeftFound && left < nums.size() - 1){
            if(nums[left] <= nums[left+1])
                left++;
            else
                isLeftFound = true;
        }
        isLeftFound = false;
        
        // scan right
        while(!isRightFound && right > 0){
            if(nums[right] >= nums[right - 1])
                right--;
            else
                isRightFound = true;
        }
        isRightFound = false;
        
        if(abs(left-right) == nums.size() - 1){
            if(left > right)
                return 0;
            else
                return nums.size();
        }
        else{
            // get Min and Max in window
            pair<int,int> getValues = getMinMax(left, right, nums);

            //Extending left and right depending on min and max
            for(int i = left - 1; i >= 0 && !isLeftFound; i--){
                if(nums[i] > getValues.first)
                    left = i;
                else
                    isLeftFound = true;
            }

            for(int i = right + 1; i < nums.size() && !isRightFound; i++){
                if(nums[i] < getValues.second)
                    right = i;
                else 
                    isRightFound = true;
            }
            return right - left + 1;
        }
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()== 0 || nums.size() == 1)
            return 0;
        else
            return getLengthUnsorted(nums);
    }
};