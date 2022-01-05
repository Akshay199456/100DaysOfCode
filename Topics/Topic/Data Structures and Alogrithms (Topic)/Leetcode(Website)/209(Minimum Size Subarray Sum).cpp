/*
-------------------------Question:

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

/*
-------------------------My Approaches:
1. Generating all subarrays and getting minimal length for each[Not coded]

The brute force approach to this problem would be to generate all subarrays and for each subarray, check the length and
see if the sum is greater than or equal to s.

Time complexity: O(n^3)
Space complexity: O(1)


2. Stopping subarray if we fnd a valid solution before hand[Not coded]

If we notice that previous approach, a bottleneck exists. If we find a subarray that satisifies the constraint, we don't need 
to continue generating subarrays since we have found the subarray with thos elements as the least length. As a result, we
can proceeed to the next index and start generating subarrays from it.

Time complexity: O(n^2)
Space complexity: O(1)


3. Sliding Window approach

If we notice the bottle necks in the previous two approaches, we notice that we are generating subarrays again and again.
This is actually not needed as we can use the information from the previous valid solution to help understand the next
solution as the next solution is almost the same as the previous solution without the first element in the array. This 
way we are moving our window towards the right till we meet the condition and once we meet the condition, we move the left
pointer and continue the same proceess again.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    int getMinLength(int s, vector<int> nums){
        int minLength = nums.size() + 1, begin = 0, end = 0, currSum = 0;
        
        while(begin < nums.size() && end < nums.size()){
            // get sum
            currSum += nums[end];
            // check if sum>=s
            if(currSum >= s){
                // if yes,
                // minLength = min(minLength, end-begin+1);
                minLength = min(minLength, end-begin+1);
                // subtract beg from sum and push beg forward
                currSum = currSum - nums[begin] - nums[end];
                begin++;
            }
            else{
                //if no, push end forward
                end++;   
            }
        }
        if(minLength == nums.size() + 1)
            return 0;
        return minLength;
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0 || (nums.size()==1 && nums[0] < s))
            return 0;
        else
            return getMinLength(s, nums);
    }
};