/*
-------------------------Question:
Given an array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.
*/

/*
-------------------------    My Approaches:
1. Two pointer approach

We can use the two pointer appraoch here in order to find the answer to the problem. If our current sum from the beg and end is less than the target, we increment beg else if it is greater, we decrement end. If they are eual, we have
found our answer.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void getIndexes(vector<int> & numbers, int target, vector<int> & result){
        int beg = 0, end = numbers.size()-1;
        bool isEnd = false;
        while(beg < end && !isEnd){
            int sum = numbers[beg] + numbers[end];
            if(sum == target){
                result.push_back(beg+1);
                result.push_back(end+1);
                isEnd = true;
            }
            else if(sum < target)
                beg++;
            else
                end--;
        }
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        getIndexes(numbers, target, result);
        return result;
    }
};