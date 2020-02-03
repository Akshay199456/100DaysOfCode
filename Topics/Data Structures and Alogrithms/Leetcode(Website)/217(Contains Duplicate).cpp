/*
-------------------------Question:

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true

*/

/*
-------------------------    My Approach:

1. Using set

Using a set helps save time as you only have to check in the set while iterating if an element exists 
or not

Time complexity: O(n)
Space complexity: O(n)

Note: For certain test cases with not very large n, the runtime of this method can be slower 
than Approach #2. The reason is hash table has some overhead in maintaining its property. One should 
keep in mind that real world performance can be different from what the Big-O notation says. 
The Big-O notation only tells us that for sufficiently large input, one will be faster than the other. 
Therefore, when nn is not sufficiently large, an O(n) algorithm can be slower than an 
O(nlogn) algorithm.
*/

/*
-------------------------    Other Approaches:
1. Brute force (worst)

The brute force approach would be to go through each element in the list and then check if that
element exists in the other elments of the list. 

Time complexity: O(n^2)
Space complexity: O(1)

2. Sorting approach(worse)

The sorting approach first sorts the array and then checks adjacent elements for repeats

Time complexity: O(nlogn)
Space complexity: O(1)

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++){
            auto iterator = set.find(nums[i]);
            if(iterator == set.end())
                set.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};