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

2. Backtracking with caching - Top down

If we check the tree structure from My Approaches(1), we notice that the same call can be repeated multiple times across
differnt structure calls. Once we know that we can't reach the goal from a particular index, we don't need to repeat it again
and again. Instead, we can just use its cached state since we already know that we can't reach the goal from our current 
index.

Time complexity: O(n^2)
Space complexity: O(n)

3. Greedy Approach

We can use a greedy appraoch here in order to obtain the solution to the problem. If we analysze Other Approaches(1), we
actually just need to keep track of the index to which we can jump to. If we can jump to the goal either directly or indirectly
from an index, this means that we can jump there from the current index so we adjust the minIndexNeeeded to the current
index since we just need to get here on the next run. As we run from right to left, we keep doing this. We return true 
when we know we can jump from 0 to a valid index that reaches the goal, either directly or indirectly.

Time complexity: O(n)
Space complexity: O(1)
*/



/*
-------------------------    Other approaches:
1. Bottom up approach

We can base off the My Approaches(2) to find a bottom up approach. In this approach, we start from the right and move to
the left. When we start from the right, given the max jump psossible at each index, we check if any of the posssible jump
values can result us in arriving at the goal either indirectly or directly. However, the final check is made against the
index 0, as we are starting from this index. If we are able to get to the  goal either directly or indirectly through
other indexes from index 0, we return true else false.

Time complexity: O(n^2)
Space complexity: O(n)
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


// My approaches(3)
class Solution {
public:
    bool checkJump(vector<int> nums, int minIndexNeeded){
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] >= minIndexNeeded - i)
                minIndexNeeded = i;
        }
        
        if(minIndexNeeded == 0)
            return true;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        return checkJump(nums, nums.size() -1);
    }
};


// Other Approaches(1)
class Solution {
public:
    bool checkJump(vector<int> nums, vector<int> & statusVector){
        for(int i = nums.size()-2; i>=0; i--){
            int maxJump = min((int) nums.size()-1, i + nums[i]);
            bool isEnd = false;
            for(int j = i+1; j <= maxJump && !isEnd; j++){
                if(statusVector[j] == 1)
                    isEnd = true;
            }
            
            statusVector[i] = isEnd ? 1 : 0;
        }
        return statusVector[0] == 1;
    }
    
    bool canJump(vector<int>& nums) {
        // -1-> enexplored, 0->no path possible, 1->path possible
        vector<int> statusVector(nums.size(), -1);
        statusVector[nums.size()-1] = 1;
        return checkJump(nums, statusVector);
    }
};