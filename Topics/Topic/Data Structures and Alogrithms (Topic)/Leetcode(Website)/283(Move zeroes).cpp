/*
-------------------------Question:

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.	
*/

/*
-------------------------    My Approaches:
1. Using a double pointer

While one pointer always sticks to the position of 0, the other pointer keeps moving and finds the next
non-zero element. When it does, it exchanges the zero and the non-zero element and progresses both the
pointers forwards. Does this till the end of the array.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------    Other Approaches:

1. (Worse) 

Can use either a map(sorted) or a set(sorted) to store the occurrence of non-zero elements during the
first iteration of going through the array. During the second iteration, replace the zero elements 
with the non-zero elements till the set/map is empty. Fill the remaining elements with zeroes.

Time complexity: O(n) + O(n) = O(n)
Space complexity: O(n) 


2. (Same but fewer operations)

Slightly different approach is to keep a zeropointer. Whenever you hit a non-zero element, you replace
the current index to the position where the zeropointer was. This means that it skips the position when
the element is zero so the next time a non-zero element is found, it replaces the zero. At the end of the
first loop, all the non-zero elements are in the correct order. So, you use a while loop to replace
the remainging elements to zero

Time complexity: O(n)
Space complexity: O(1)
*/

// My approach(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if((nums.size() == 0) || (nums.size() == 1)){
            
        }
        else{
            int zeroptr = 0, ptr = 0;
            while(ptr < nums.size()){
                if(nums[zeroptr] != 0 && nums[ptr] != 0)
                    zeroptr++;
                else if(nums[zeroptr] == 0 && nums[ptr] != 0){
                    swap(nums[zeroptr], nums[ptr]);
                    zeroptr++;
                }
                ptr++;
            }
        }
    }
};


// Other approach(2)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroptr = 0;
        for(int index = 0; index < nums.size(); index++){
            if(nums[index] != 0)
                nums[zeroptr++] = nums[index];
        }
        
        while(zeroptr < nums.size())
            nums[zeroptr++] = 0;
    }
};