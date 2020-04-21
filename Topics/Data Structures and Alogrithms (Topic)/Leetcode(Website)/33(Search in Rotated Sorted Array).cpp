/*
-------------------------Question:

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/

/*
-------------------------My Approaches:

1. Binary Search along pivot

The key thing to understand in this problem is that the array remains sorted along the pivot,
which can either be the smallest or the largest element in the array. Once we identify the pivot,
it becomes easy to find in which section the target element either exists or doesn't exist.

Finding the pivot:

Check the respective folder folder in 'Helping Images' for more info on the approach. To summarize,
the beg element is either greater than the end element or it isn't. If it isn't, it means that 
the array is already in proper sorted order. If it is, to find the mid element at each instance,
we check if the mid element is less than the beg element. If it is, we know that the greatest
element must exist on the left half. Else, it exists in the left half. As we are progressing, we
keep track of the max element through the mid.

findElement:

Once we find the pivot, it becomes easy. This is becasue, at the pivot, we can divide the array
into two sections each of which are sorted on their own. Since they are sorted, we can apply
binary search here as well to find in which section it exists.

Time complexity: O(log n)
Space complexity: O(h) -> O(log n) for height of the recursive calls.
*/

/*
-------------------------Other approaches

*/



// My Approaches(1)
class Solution {
public:
    int findPivot(vector<int> nums, int beg, int end){
        int maxIndex = INT_MIN, maxValue = INT_MIN;
        while(beg <= end){
            int mid = (beg + end) / 2;
            if(nums[mid] >= maxValue){
                maxIndex = mid;
                maxValue = nums[mid];
            }
            
            if(nums[beg] > nums[end] && nums[mid] < nums[beg])
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return maxIndex;
    }
    
    int findElement(vector<int> nums, int beg, int end, int target){
        if(beg <= end){
            int mid = (beg + end) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                return findElement(nums, beg, mid - 1, target);
            else
                return findElement(nums, mid + 1, end, target);
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        else{
            int pivot = findPivot(nums, 0, nums.size() - 1);   
            cout<<"Pivot number: "<<pivot<<endl;
            if(target >= nums[0] && target <= nums[pivot])
                return findElement(nums, 0, pivot, target);
            else
                return findElement(nums, pivot+1, nums.size() - 1, target);
        }
    }
};