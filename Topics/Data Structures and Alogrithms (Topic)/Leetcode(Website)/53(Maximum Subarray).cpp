/*
-------------------------Question:

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
/*

/*
-------------------------Other approaches

1. Have written a lot about this approach in pages and have attached them in the 'Helping Images'
folder which will provide a great explanation to the solution. 

The key here is to optimize the whole problem by optimizing the sub problem thereby being a dynamic
programming problem.

Time complexity: O(n)
Space complexity: O(1)



2. Divide and Conquer Approach[Worse]

This approach uses the divide and conquer algorithm to break down the problem into sub-problems.
The base condition is when the array has only one element or beg=end. 

1.     Task is to find out subarray which has the largest sum. So we need to find out the 2 indexes (left index and right index) between which the sum is maximum.

2.     Divide the problem into 2 parts, left half and right half.

Now we can conclude the final result will be in one of the three possibilities.

1. Left half of the array. (Left index and right index both are in left half of the array).
2. Right half of the array. (Left index and right index both are in right half of the array).
3. Result will cross the middle of the array. (Left index in the and left half of the array and right index in right half of the array).

Solve the all three and return the maximum among them.

Left half and right half of the array will be solved recursively.

The result[max sum] can exist in only one of those 3 conditions. It can either be in the left
half completely, the right half completely or spread across the left and right half.

As a result, leftSum stores the best possible sum that we can obtain on the left side, rightSum
stores the best possible sum that we can obtain on the right side. Finally, the crossSum gets the
max sum containing the mid element starting from the mid element and going to it's left and right.
At the end, the result has to be in one of these three. As a result, we obtain the max continuous
sum in the array.

Time complexity: O(nlogn)
Space complexity: O(log n)
*/



// Other Approaches(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        if(nums.size() == 0)
            return INT_MIN;
        else{
            int current_max, global_max;
            current_max = global_max = nums[0];
            
            for(int i = 1 ; i < nums.size(); i++){
                current_max = max(nums[i], nums[i] + current_max);
                if(current_max > global_max)
                    global_max = current_max;
            }         
            return global_max;
        }
    }
};


// Other Approaches(2)
class Solution {
public:
    int conquerCrossSum(vector<int> nums, int beg, int mid, int end){
        int sum = 0, leftSum = INT_MIN, rightSum = INT_MIN;
        for( int i = mid ; i >= beg; i--){
            sum += nums[i];
            if(sum > leftSum)
                leftSum = sum;
        }
        
        sum = 0;
        for(int i = mid + 1; i <= end; i++){
            sum += nums[i];
            if (sum > rightSum)
                rightSum = sum;
        }
        return leftSum + rightSum;
    }
    
    int divideArray(vector<int> nums, int beg, int end){
        if(beg == end)
            return nums[beg];
        else{
            int mid = beg +  (end - beg)/ 2;
            int leftSum = divideArray(nums, beg, mid);
            int rightSum = divideArray(nums, mid+1, end);
            int crossSum = conquerCrossSum(nums, beg, mid, end);
            return max(max(leftSum, rightSum), crossSum);
        }
    }
    
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else
            return divideArray(nums, 0, nums.size() - 1);        
    }
};