/*
-------------------------Question:

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

/*
-------------------------My Approaches:

1. Two pointer approach

We can use the two pointer appraoch here to solve the problem. We know that 0s occur at the beginning of the array while
2s occur at the end. Using this info we can have two pointers pointing to the beginning and the end. When we encounter a
0, we swap beginning with the current index and push both beginning and curr forward. If we encounter a 2,we swap it wwith
the end and push the end backward. If we counter a 1, we just push curr forward.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

1. Using two pass [Not coded]

We can also use a two pass approach where in the first pass, we get the no of 0,1,2 and in the second pass, insert them
into the array in the proper order

Time complexity: O(n)
Space complexity: O(1)
*/

// My Approaches(1)
class Solution {
public:
    void sortInPlace(vector<int> & nums){
        int begin = 0, end = nums.size() -1, curr = 0;
        while(end >= 0 && curr < nums.size() && curr <= end){
            if(nums[curr] == 2)
                swap(nums[curr], nums[end--]);
            else{
                if(nums[curr] == 0)
                    swap(nums[curr], nums[begin++]);
                curr++;
            }
        }
    }
    
    void sortColors(vector<int>& nums) {
        if(!(nums.size() == 0 || nums.size() == 1))
            sortInPlace(nums);
    }
};