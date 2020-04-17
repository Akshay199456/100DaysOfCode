/*
-------------------------Question:

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing
from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant 
extra space complexity?
*/

/*
-------------------------My Approaches:

1. Using formular for n natural numbers

Since we know that our array will be a collection of n natural numbers + 0, we can use the formula
for the sum of n natural numbers. We can also find the sum from the array by running through it.
The difference between the sum of n natural numbers and the sum from the array will give the missing
element

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/


//My Approaches(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int naturalSum = nums.size() * (nums.size() + 1) / 2;
        int arraySum = 0;
        for(int i= 0; i < nums.size(); i++)
            arraySum += nums[i];
        return naturalSum - arraySum;
    }
};