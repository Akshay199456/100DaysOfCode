// This problem was also solved using the UMPIRE approach

/*
-------------------------Question:

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

/*
-------------------------My Approaches:

1. [Doesn't admit to constraints of problem] Sorting array and finding consecutive elements

One of the ways we can achieve the objective is to sort the array. By sorting the array, we have the elements in their
sorted order which helps us in finding consecutive elements. The only thing we want to amke sure is that if there are 
duplicates, then we don't add it to the length of the max subsequence.

Time complexity: O(nlog n)
Spacec complexity: O(1)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    int getLengthLongestConsecutive(vector<int> nums){
        sort(nums.begin(), nums.end());
        int start = nums[0], length = 1, maxLength = 1;
        for(int i=1; i <nums.size(); i++){
            if(nums[i] - nums[i-1] <= 1){
                if(nums[i] - nums[i-1] != 0){
                    length++;
                    if(length > maxLength)
                        maxLength = length;
                }   
            }
            else{
                start = nums[i];
                length = 1;
            }
        }
        return maxLength;
    }
    
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();
        else
            return getLengthLongestConsecutive(nums);
    }
};