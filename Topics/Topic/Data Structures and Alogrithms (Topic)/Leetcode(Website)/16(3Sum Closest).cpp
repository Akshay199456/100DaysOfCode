/*
-------------------------Question:

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

/*
-------------------------    My Approaches:
1.Using two sum approach

We can initially sort the array. Once we do that we have the integers in proper order so we can move pointers as we need to get the result we need. Since for
each integer, we will be looking at O(n) times, te time complexity comes to O(n^2)

Time complexity: O(n^2)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    int getClosest(vector<int> & nums, int target){
        int minDistance = INT_MAX, dirn = 1;
        for(int i = 0; i < nums.size() - 2; i++){
            int beg = i+1, end = nums.size()-1;
            while(beg < end){
                int sum = nums[i] + nums[beg] + nums[end];
                if(minDistance > abs(sum-target)){
                    minDistance = abs(sum-target);
                    if(sum >= target)
                        dirn = 1;
                    else
                        dirn = -1;
                }
                
                if(sum <= target)
                    beg++;
                else if( sum > target)
                    end--;
            }
        }
        return (dirn == 1) ? target + minDistance: target - minDistance;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return getClosest(nums, target);
    }
};