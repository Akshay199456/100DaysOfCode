/*
-------------------------Question:

Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

/*
-------------------------My Approaches:
1. Using two pointer approach.

We can use the two pointer approach here to help solve this problem. Initially, we can use the two pointers to understand
where in the subarray teh sorting needs to take place. Once we get that info, we want to make sure to get the min and max
in that subarray. This is needed because we are not going over the continuous subarray. So, if there is a min and max in the
subarray that is less than / greater than the elements outside the subarray, we adjust the subarray acfcordingly as those
elements will need to be sorted as well

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

1. Sorting and finding limits of subarray

We can sort a copy of the array and compare it with the original array. Once we do this, starting at the beginning we 
compare the orgiinal with teh copy and wherever there is a discrpancy, that's the start of the subarray to be sorted.
Similarly, for the end, we start at the end of athe arrays and whereever there is a discrepancy that's the end.

Time complexity: O(nlogn)
Space complexity: O(1)


2. Implementation of selection sort

We can use an implementation of insertion sort to solve this problem as well. Basically, like insertion sort, we are trying
to find if an element is already in place or not. If it is, good enough. However, if it isn't, instead of swapping the values
with the min, we keep track of the left and right indexes where this occurs. As we move along with the differnet elements,
we can use this knowledge from the previous step to extend the limits of the index if we keep finding elements out of 
position.

Time complexity: O(n^2)
Space complexity: O(1)


3. Selective sorting using information about elements in graph

This implementation is similar to selective sorting as well. If we plot the elements onto the graph, we see elements
with slopes moving up and down. Our goal at the end is to obtin a graph withe only an increasing slope. As a result,
in order to find the left point we need to find the point at which the slope starts falling. In addiiton,we need to make
a check to make sure the elements in the subarray are not less than this left. If thery are , we adjust the left 
accordingly. We do the smae for the right but for the opposite conditions. Eg: we need to find the point at which we see
an increasing slop as we are traversing back.

Time complexity: O(n)
Space complexity: O(n)

This si a common approach that I see in array based problems where you can plot the numbers on a graph to find and
understand the problem clearly and find oout the conditions for the results you are looking for.
*/

// My Approaches(1)
class Solution {
public:
    pair<int, int> getMinMax(int left, int right, vector<int> nums){
        int min = nums[left], max = nums[left];
        int temp = left + 1;
        while(temp <= right){
            if(nums[temp] < min)
                min = nums[temp];
            if(nums[temp] > max)
                max = nums[temp];
            temp++;
        }
        return make_pair(min,max);
    }
    
    int getLengthUnsorted(vector<int> nums){
        int left = 0, right = nums.size() - 1;
        int isLeftFound = false, isRightFound = false;
        
        // scan left
        while(!isLeftFound && left < nums.size() - 1){
            if(nums[left] <= nums[left+1])
                left++;
            else
                isLeftFound = true;
        }
        isLeftFound = false;
        
        // scan right
        while(!isRightFound && right > 0){
            if(nums[right] >= nums[right - 1])
                right--;
            else
                isRightFound = true;
        }
        isRightFound = false;
        
        if(abs(left-right) == nums.size() - 1){
            if(left > right)
                return 0;
            else
                return nums.size();
        }
        else{
            // get Min and Max in window
            pair<int,int> getValues = getMinMax(left, right, nums);

            //Extending left and right depending on min and max
            for(int i = left - 1; i >= 0 && !isLeftFound; i--){
                if(nums[i] > getValues.first)
                    left = i;
                else
                    isLeftFound = true;
            }

            for(int i = right + 1; i < nums.size() && !isRightFound; i++){
                if(nums[i] < getValues.second)
                    right = i;
                else 
                    isRightFound = true;
            }
            return right - left + 1;
        }
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()== 0 || nums.size() == 1)
            return 0;
        else
            return getLengthUnsorted(nums);
    }
};


// Other Approaches(2)
class Solution {
public:
    int getLengthUnsorted(vector<int> nums){
       int left = nums.size(), right = 0;
        for(int i =0; i < nums.size() - 1; i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] < nums[i]){
                    left = min(left, i);
                    right = max(right, j);
                }
            }
        }
        return right - left < 0 ? 0 : right - left + 1;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()== 0 || nums.size() == 1)
            return 0;
        else
            return getLengthUnsorted(nums);
    }
};


// Other Approaches(3)
class Solution {
public:
    int getLengthUnsorted(vector<int> nums){
       stack<int> elements;
        int left = nums.size(), right = 0;
        for(int i = 0; i < nums.size(); i++){
            while(!elements.empty() && nums[elements.top()] > nums[i]){
                left = min(left, elements.top());
                elements.pop();
            }
            elements.push(i);
        }
        
        elements.empty();
        
        for(int i = nums.size() - 1; i >= 0 ; i--){
            while(!elements.empty() && nums[elements.top()] < nums[i]){
                right = max(right, elements.top());
                elements.pop();
            }
            elements.push(i);
        }
        
        return right - left < 0 ? 0 : right-left + 1;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()== 0 || nums.size() == 1)
            return 0;
        else
            return getLengthUnsorted(nums);
    }
};