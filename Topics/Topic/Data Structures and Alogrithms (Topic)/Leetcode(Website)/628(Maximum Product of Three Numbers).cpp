/*
-------------------------Question:

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
 

Constraints:

3 <= nums.length <= 104
-1000 <= nums[i] <= 1000
*/

/*
-------------------------    My Approaches:
1. Greedy Approach

We can solve this problem in a greedy approach. Since we are interested in finding the max of the prodct, we are intersted in the product of the three numbers that lead to th eproduct. Now, there are  possible permutations in which threse
3 numbers can occur:
    3 positive
    2 positive 1 negative
    1 positive 2 negative
    3 negative

Given that thee three numbers can only occur ni 1 of these 4 scenarios, let's see how many cases we have to consider.

(a) 3 positive
    Since all the three numbers are positive, once we sort the array, the largest value is goin to be towards the end of the array on the right.

(b) 3 neagtaive
    If all the three numbers. then these numbers are going to be on the left side of the sorted array which means they are going to be the lowest. In that case, choosing the three values at the end of the array will always provide us
    with better results.

(c) 1 positive, 2 negative
    In this case, the negative will be at the left end of the sorted array while the 1 positive will be at the right end of the sorted array. As a result, this is alos a valid solution as it will provide us with the a high produict that
    can compete with the three on the right product.

(d) 2 positive, 1 negative
    In this case, the tweo positive will be at the right end of the sorted array while the 1 negative will be at the left end of the sorted array. In this case, we will always be better off with the 3 positive since the 2 positve 1 negative
    will always be less than the three postive.

Since there are twop possible routes which can give us the max product, we want to return the ma of those two as the answeer.

Time complexity; O(nlogn)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int top3Prod = 1, last2Prod = 1;
        
        // get top 3 prod
        for(int i=1; i<=3; i++)
            top3Prod *= nums[nums.size()-i];
        
        // get last 2 and top 1 prod
        for(int i=0; i<=1; i++)
            last2Prod *= nums[i];
        last2Prod *= nums[nums.size()-1];
        
        return max(top3Prod, last2Prod);
    }
};