/*
-------------------------Question:

Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

 

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
 

Constraints:

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/

/*
-------------------------    My Approaches:
1. Parsing the array before hand through left and right

With brute force, we would basically go through the all the left and all the right and keep track of the sum as we are goin along. This si a good approach but it takes O(n^2) time complexity. We can do better by caching the left and right
sum beforehand. This way when we run through the arrays next time, we are only evaluating the left and right sum at each index to check the pivotIndex.

Time Complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:
1. Using two sum similar technique

We can apply the two sum technique and use O(1) space instead. If we find the sum of the whole array during the first run, we can then use that to calculate the rightSum and leftSum as we are moving along and when we find the index when
they are equal we return that index

Time complexity: O(n)
Space complexity: O(1)
*/

// My Approaches(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum[nums.size()], rightSum[nums.size()];
        int pivotIndex = -1;
        bool isEnd = false;
        
        // initialize arrays with default value
        for(int i=0; i<nums.size(); i++){
            leftSum[i] = 0;
            rightSum[i] = 0;
        }
        
        // create left sum
        for(int i=1; i<nums.size(); i++){
            leftSum[i] = leftSum[i-1] + nums[i-1];
        }
        
        // create right sum
        for(int i = nums.size() - 2; i>=0; i--)
            rightSum[i] = rightSum[i+1] + nums[i+1];
        
        // find point of pivot
        for(int i=0; i<nums.size() && !isEnd; i++){
            if(leftSum[i] == rightSum[i]){
                isEnd = true;
                pivotIndex = i;
            }
        }
        return pivotIndex;
    }
};


// Other Approaches(1)
class Solution {
public:
    int getTotal(vector<int> & nums){
        int total = 0;
        for(int i=0; i<nums.size(); i++)
            total += nums[i];
        return total;
    }
    
    int getPivotIndex(vector<int> & nums, int rightSum){
        int leftSum = 0;
        for(int i=0; i<nums.size(); i++){
            rightSum -= nums[i];
            if(leftSum == rightSum)
                return i;
            else
                leftSum += nums[i];   
        }
        return -1;
    }
    
    int pivotIndex(vector<int>& nums) {
        int sum = getTotal(nums);
        return getPivotIndex(nums, sum);
    }
};