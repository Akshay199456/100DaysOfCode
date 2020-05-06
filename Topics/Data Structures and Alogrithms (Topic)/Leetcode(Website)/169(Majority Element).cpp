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

1. Sorting the array

We can sort the array and return the mid element. This will always guarantee to hold the element that
occurs more than n/2 as long as there is an element that exceeds it. Check 'Helping Images' for more info
on this approach. 

As can be seen in the 'Helping Images', if the majority element exists in the beginning of the array,
it will always exist at the mid and/or exceed it towards the end of the array. If the majority element
exists at the end of the array, it will always exist at the mid and/or exceed it towards the beginning of
the array. If it exists anywhere in between, the line will always cross over the middle and hence irrespective
of where the majorith element exists, it will always be in the middle of the array.

Time complexity:O(nlogn)
Space complexity: O(1)
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


// Other Approaches(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];     
    }
};