/*
-------------------------Question:

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/

/*
-------------------------My Approaches:
1. Binary Seach

We can apply the bianry search approach here to find the index where the element either occurs or should have occurrred.
If beg>end, then, that's the index where the element will occur. else, we keep applying binary search to find the elelement.

Time complexity: O(log n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    int binarySearchValue(vector<int> nums, int beg, int end, int target){
        if(beg > end)
            return beg;
        else{
            int mid = beg +(end-beg)/2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid])
                return binarySearchValue(nums, mid+1, end, target);
            else
                return binarySearchValue(nums, beg, mid-1, target);
        }
    }
    
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        else
            return binarySearchValue(nums, 0, nums.size()-1, target);
    }
};