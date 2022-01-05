/*
-------------------------Question:

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 400
*/

/*
-------------------------My Approaches:
1. Using Bottom up DP

We can use the DP approach here since there is a recursive substructure available here. This approach focused on saving the
max value that we had seen until the particular index not taking into consideration the imeediate previous value. As a result,
every index had the max of the values that came before it. For the new element, we would find the max of the values before
it excluding the previous index and add the new element to it. We continue this till the end of the array/

At each new element, we can either choose to not rob this house or rob this house and getting the max of the rest of the 
housese that we looted.

Time complexity: O(n^2)
Space complexity: O(n)


2. Improvmeent on DP

The bottleneck in the previous apporoach was that we were storing the max for a particular element not taking into consideration
the immediate previous element. As a result, for a particuallr element, we would have to go through all the previous
max values to find the curr max value for this element. 

We can get rid of the bottleneck by storing the max values as we are going along for each value. In this approach, if we choose
to rob this current house, we use dpList[i-2] which stores the max that we had ecnountered not including the previous house
and add the current loot or not rob this house and get the max till the previous house dpList[i-1]. Whichever is the max
of these two, that is the maximum value that we can loot until this house. We continue to do this till all houses are 
covered.

Thus, in this appraoch, we are storing the max that we have ecnountered thill this house which is made up of two choices:
1. We decided to loot this house and we calculate the max as dpList[i-2] + nums[i]
2. We deviede to not lott this house so we get the max as dpList[i-1].

We find the max of these two choiuces and store it for this current idnex.

Time complexity: O(n)
Space complexity: O(n)


3. Improvmeent of My Appraoches(2)

If we notice the bottleneck in the previous approach, we can notice that we are only using the previous two indexes at most
at any time. So, rather than using an array, we can use two variables to store the values as we are going along and display
the results accordingly.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    int robAlgorithm(vector<int> nums){
        vector<int> dpList;
        int currLevelMax = INT_MIN, allLevelMax = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            currLevelMax = nums[i];
            for(int j = i-2; j >= 0; j--)
                currLevelMax = max(nums[i] + dpList[j], currLevelMax);
            
            allLevelMax = max(currLevelMax, allLevelMax);
            dpList.push_back(currLevelMax);
        }
        return max(allLevelMax, dpList[nums.size()-1]);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else
            return robAlgorithm(nums);
    }
};


// My Approaches(2)
class Solution {
public:
    int robAlgorithm(vector<int> nums){
        vector<int> dpList;
        int currMax = -1;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0)
                currMax = nums[0];
            else
                currMax = (i-2 >= 0) ? max(dpList[i-1], dpList[i-2] + nums[i]) : max(dpList[i-1], nums[i]);
            
            dpList.push_back(currMax);
        }
        return dpList[nums.size() - 1];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else
            return robAlgorithm(nums);
    }
};


// My Approaches(3)
class Solution {
public:
    int robAlgorithm(vector<int> nums){
        int pMax = nums[0], ppMax = 0;
        for(int i = 1; i < nums.size(); i++){
            int temp = pMax;
            pMax = max(ppMax + nums[i], pMax);
            ppMax = temp;
        }
        return pMax;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        return robAlgorithm(nums);
    }
};