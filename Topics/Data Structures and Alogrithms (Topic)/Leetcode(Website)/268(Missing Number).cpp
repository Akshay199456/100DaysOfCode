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

Two approaches that can be used as well but with worse time complexities are using a hashset to 
store the occurrences and sorting the array. The former has a time complexity of O(n) and space
complexity of O(n) while the latter has a time complexity of O(nlogn) and space comeplexity of O(1).
*/

/*
-------------------------Other approaches

1. Using bit manipulation[Same]

We can use bit manipulation to figure out which integer we are missing. Check out the [Helping Images]
folder for more information on the approach.

The crux of the apporach is that a^b = b^a and a^a = 0. Since we know that there is only element
missing in the array that's conitnuous in the distribution of elements and that the collection in the
array will either be equal to or less than the index of the max index by 1, we can use that info to
exor the indexes and the values stored in the indexes. As a result, at the end, we will be left
with only the missing value as that will only have one occurrence from the index and not from the 
collection while the rest of the indexes and elements will cancel out since a^a = 0. Have to make
sure though that we start with the length of the array as the initial value for missing value
as that will help us decide if the element with value equal to the legnth of the array is either
missing or will be canceled out by the value stored in the calculation.

Time complexity: O(n)
Space complexity: O(1)
*/


// My Approaches(1)
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


// Other Approaches(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingValue = nums.size();
        for(int i = 0; i < nums.size(); i++)
            missingValue ^= nums[i] ^ i;
        return missingValue;
    }
};