/*
-------------------------Question:

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

/*
-------------------------My Approaches:

1. Using map to store occurrences

We can use the map to store the number of occurences of each number in the vector. After every entry, we
check if it exceeds the threshold of n/2 and if it does, we return that element. Since the list is 
guarantted to have a solution, we don't have to worry about elsewise.

Time complexity: O(n)
Space complexity: O(n)

*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    int getMajorityElement(vector<int> nums, int threshold){
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            auto it = map.find(nums[i]);
            if(it == map.end())
                map[nums[i]] = 1;
            else
                map[nums[i]]++;
            
            if(map[nums[i]] > threshold)
                return nums[i];
        }
        return -1;
    }
    
    int majorityElement(vector<int>& nums) {
        int threshold = nums.size() / 2;
        return getMajorityElement(nums, threshold);
    }
};