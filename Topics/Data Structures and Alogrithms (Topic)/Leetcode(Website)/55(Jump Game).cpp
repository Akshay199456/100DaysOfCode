/*
-------------------------Question:

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5
*/

/*
-------------------------    My Approaches:
1. Backtracking

At each step, we can explore all possible jumps that are possible from the current index and do this till we either cross
the bounds of the array, find the index or hit a zero. This resembles a tree strcutre in the order of calls that are made
to other values.

Time complexity: O(2^n)
Space complexity: O(n)

2. Backtracking with caching

If we check the tree structure from My Approaches(1), we notice that the same call can be repeated multiple times across
differnt structure calls. Once we know that we can't reach the goal from a particular index, we don't need to repeat it again
and again. Instead, we can just use its cached state since we already know that we can't reach the goal from our current 
index.

Time complexity: O()
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    bool checkJump(vector<int> nums, int currIndex){
        if(currIndex == nums.size() - 1)
            return true;
        else if(currIndex >= nums.size() || nums[currIndex] == 0)
            return false;
        else{
            for(int i = nums[currIndex]; i > 0; i--){
                if(checkJump(nums, currIndex + i))
                    return true;
            }
            return false;
        }
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        return checkJump(nums, 0);
    }
};


// My Approaches(2)
class Solution {
public:
    bool checkJump(vector<int> nums, int currIndex, vector<int> & statusVector){
        if(currIndex == nums.size() - 1)
            return true;
        else if(currIndex >= nums.size() || statusVector[currIndex] == 0 || nums[currIndex] == 0){
            if(currIndex < nums.size())
                statusVector[currIndex] = 0;
            return false;
        }
        else{
            for(int i = nums[currIndex]; i > 0; i--){
                if(checkJump(nums, currIndex + i, statusVector)){
                    statusVector[currIndex] = 1;
                    return true;
                }
            }
            statusVector[currIndex] = 0;
            return false;
        }
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> statusVector(nums.size(), -1);
        if(nums.size() == 1)
            return true;
        return checkJump(nums, 0, statusVector);
    }
};