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

We can get righ of the recurisve call to make it a O(1) space complexity solution


2. Finding pivot without binary search followed by binary search for element

We can find the pivot index through linear search. Once we get the pivot, we now have two subarrays within which we can 
check for the element.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

1. Being on the same or opposite side of the pivot

This approach has been explained well in the 'Helping Images' section for this problem. To summarize,
we basically check if the target element we are searching for and the middle element are on the 
same side or on the opposite side of the pivot element. The pivot element that we are considering
is the element at the beginning of the array. We call it the pivot element because if the array
were in its sorted order, the elements on the left side of the pivot element would be less than
the pivot while the elements on the right side of the pivot element would be more than the pivot.

As long as the mid element and the target element are on the same side, we can keep applying
normal binary search to find the element we are looking for since we will eventually get there
as both the middle and target element are on the same side. However, if the mid and target element
are on opposite sides, 2 conditions exist:

1. If the target element is less than the pivot, we make the middle element as -Inf as the element
we are searching for is on the right side of the middle element in order to keep applying binary 
search. Else we make the middle element as +Inf so that we start applying binary search to the left
of the middle elements.

	Here, we don't need to check any condition with respect to the mid element as we can infer that
	information. For example, if the target element is less than the pivot element, we can infer
	that the mid element is greater than the target element because we entered that if condition
	only because the middle element and the target element were on different sides of the pivot
	element. Since in this case, the target elment is less than the pivot element whih also means
	the mid element is greater than the target element, we cknow that the target eleemtn to find
	will be in the section from mid+1 to end. As a result, we are assigning mid the value of 
	INT_MIN so that the secction of the array from mid+1 to end is selected for the binary search
	in the next iteration of the loop. This also works for the vice versa condition.

Time complexity: O(log n)
Space complexity: O(1) 

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


// My Approaches(2)
class Solution {
public:
    int getPivot(vector<int> nums){
        int beg = 0, end = 1;
        bool found = false;
        while(end < nums.size() && !found){
            if(nums[end] > nums[beg])
                end++;
            else
                found = true;
        }
        return end;
    }
    
    int binarySearch(int beg, int end, vector<int> nums, int target){
        while(beg <= end){
            int mid = (beg + end)/2;
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                end = mid-1;
            else
                beg = mid+1;
        }
        return -1;
    }
    
    int getIndex(vector<int> nums, int target){
        if(nums[nums.size() - 1] > nums[0])
            return binarySearch(0, nums.size() - 1, nums, target);
        else{
            int pivotIndex = getPivot(nums);
            if(target >= nums[0] && target <= nums[pivotIndex-1])
                return binarySearch(0, pivotIndex - 1, nums, target);
            else if(target >= nums[pivotIndex] && target <= nums[nums.size() -1])
                return binarySearch(pivotIndex, nums.size() - 1, nums, target);
            else
                return -1;
        }
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(target == nums[0])
                return 0;
            else
                return -1;
        }
        else
            return getIndex(nums, target);
    }
};



// Other Approaches()
class Solution {
public:
    int findElement(vector<int> nums, int beg, int end, int target){
        int pivot = nums[0];
        int comparator = INT_MIN;
        while(beg <= end){
            int mid = beg + (end-beg) / 2;
            if((nums[mid] >= pivot) == (target >= pivot))
                comparator = nums[mid];
            else{
                if(target < pivot)
                    comparator = INT_MIN;
                else
                    comparator = INT_MAX;
            }
            
            if(target == comparator)
                return mid;
            else if(target > comparator)
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        else
            return findElement(nums, 0, nums.size() - 1, target);
    }
};