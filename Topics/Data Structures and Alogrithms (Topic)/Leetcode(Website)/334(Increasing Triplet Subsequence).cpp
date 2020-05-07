/*
-------------------------Question:

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false
*/

/*
-------------------------My Approaches:

1. Brute force appraoch

The brute force appraoch is pretty simple. We check each subsequence pair depending and if the pair meets
the condition, we return true.

Time complexity: O(n^3)
Space complexity: O(1)

*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    bool checkIncreasingTriplet(vector<int> nums){
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    if(nums[i] < nums[j] && nums[j] < nums[k])
                        return true;
                }
            }
        }
        return false;
    }
    
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        else
            return checkIncreasingTriplet(nums);
    }
};