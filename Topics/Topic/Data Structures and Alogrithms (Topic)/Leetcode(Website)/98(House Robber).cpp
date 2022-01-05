/*
-------------------------Question:

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/

/*
-------------------------My Approaches:

1. Brute Force

If you think about it, the solution for this problem only exists within the tree for the first 
2 elements of the array[Check 'Helping Images'] for more information. This is because every element
after them have a tree pattern that's already embedded in the subtree of the first two elements.
As a result, we basically, need to find the max subrarray sum of the elments in the first 2 subtrees
and we will have the solution to the problem

Time complexity: O(n^n) since we will have n children for each node
Space complexity: O(n) as the max depth at any moment will be the total number of elements in tree.
*/


/*
-------------------------Other approaches

We will show the progression of the Other Approaches here. All of these approaches stem from the base
Other Approaches(1). The goal here is to understand how to think about DP problems and move from
a less efficient solution to another.

There is some frustration when people publish their perfect fine-grained algorithms without sharing any information abut how they were derived. This is an attempt to change the situation. There is not much more explanation but it's rather an example of higher level improvements. Converting a solution to the next step shouldn't be as hard as attempting to come up with perfect algorithm at first attempt.

This particular problem and most of others can be approached using the following sequence:

Find recursive relation
1. Recursive (top-down)
2. Recursive + memo (top-down)
3. Iterative + memo (bottom-up)
4. Iterative + N variables (bottom-up)



1. Other Approaches(1) - Recursive approach

Step 1. Figure out recursive relation.
A robber has 2 options: a) rob current house i; b) don't rob current house.
If an option "a" is selected it means she can't rob previous i-1 house but can safely proceed to the one before previous i-2 and gets all cumulative loot that follows.
If an option "b" is selected the robber gets all the possible loot from robbery of i-1 and all the following buildings.
So it boils down to calculating what is more profitable:

robbery of current house + loot from houses before the previous
loot from the previous house robbery and any loot captured before that
rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )

Step 2. Recursive (top-down)
Converting the recurrent relation from Step 1 shound't be very hard.
This algorithm will process the same i multiple times and it needs improvement. 

Time complexity: O[2^n]
Space complexity: O(n)



2. Other Approaches(2) - Top down recursive approach

As you will be see in the 'Helping Images' folder for this problem, this problem basically becomes
a tree with Other Approaches(1) where each parent can have one of 2 children. This also means that
there is a lot of repetition that occurs where certain subtrees are evaluated again and again 
which drastically impacts the runtime of the algorithm. The way around it is to store the 
occurences in a memo array so we can retrieve any values that are calculated from it. This 
becomes the crux of the DP approach where we work on a top-down technique to solve this problem.

In the top-down approach, we start at the problem in a normal manner and hope that for the subproblems
that they are already calculated or we will calculate them as we go on.

Time complexity: O(n)
Space complexity: O(n)

Much better, this should run in O(n) time. Space complexity is O(n) as well, because of the 
recursion stack, let's try to get rid of it.


3. Other Approaches(3) - Bottom up iterative approach


The other way we solve this program with DP is by using a bottom up approach. With a bottom up
approach, we calcualte the result at the bottom and use those to calculate the results at the top.

Time complexity: O(n)
Space complexity: O(n)



4. Other Approaches(4) - Iterative + n variables

If we actually notice Other Approaches(3), we are only using memo[i-1] and memo[i] to obtain
the value of memo[i-2]. This can as a result, takes up the form of the fibonacci series and as a
result, we can optimize the fibonacci series by using 2 variables to hold the previous 2 values
and update them when we get the new max for every element in the array.
*/




// My Approaches(1)
class Solution {
public:
    void getMaxMoney(vector<int> nums, int total, int startIndex, int & maxTotal){
        total += nums[startIndex];
        maxTotal = max(total, maxTotal);
        for(int i = startIndex + 2; i < nums.size(); i++)
            getMaxMoney(nums, total, i, maxTotal);
    }
    
    int rob(vector<int>& nums) {
        int total = 0, maxTotal = 0;
        
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        else{
            for(int i = 0; i <= 1; i++){
                cout<<"Max Total: "<< maxTotal<<endl;
                getMaxMoney(nums, total, i, maxTotal);
            }
            return maxTotal;
        }
    }
};


// Other Approaches(1)
class Solution {
public:
    int getMaxSum(vector<int> nums, int index){
        if(index < 0)
            return 0;
        else
            return max(nums[index] + getMaxSum(nums, index - 2), getMaxSum(nums, index - 1));
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else
            return getMaxSum(nums, nums.size() - 1);
    }
};



// Other Approaches(2)
class Solution {
public:
    int getMaxSum(vector<int> nums, int index, vector<int> & memo){
        if(index < 0)
            return 0;
        else if(memo[index] != -1)
            return memo[index];
        else{
            int total = max(nums[index] + getMaxSum(nums, index - 2, memo), getMaxSum(nums, index - 1, memo));
            memo[index] = total;
            return memo[index];
        }
    }
    
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        if(nums.size() == 0)
            return 0;
        else
            return getMaxSum(nums, nums.size() - 1, memo);
    }
};



// Other Approaches(3)
class Solution {
public:
    int getMaxSum(vector<int> nums, vector<int> & memo){
        memo[0] = 0;
        memo[1] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            memo[i+1] = max(memo[i-1] + nums[i], memo[i]);
        }
        return memo[nums.size()];
    }
    
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size() + 1, -1);
        if(nums.size() == 0)
            return nums.size();
        else
            return getMaxSum(nums, memo);
    }
};



// Other Approaches(4)
class Solution {
public:
    int getMaxSum(vector<int> nums){
        int valueBeforeValue = 0, valueBefore = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int temp = max(nums[i] + valueBeforeValue, valueBefore);
            valueBeforeValue = valueBefore;
            valueBefore = temp;
        }
        return valueBefore;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return nums.size();
        else
            return getMaxSum(nums);
    }
};