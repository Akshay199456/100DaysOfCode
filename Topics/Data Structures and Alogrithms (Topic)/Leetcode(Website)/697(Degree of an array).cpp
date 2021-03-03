/*
-------------------------Question:

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 

Example 1:

Input: nums = [1,2,2,3,1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:

Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 

Constraints:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.
*/

/*
-------------------------    My Approaches:
1. using maps to register first seen and last seen state

We can use maops to register the count, first seen state ans last seen state of any element. Once we do that, we can go through the array again to find the elements that have the same count as the degree and use the firstseenstate and 
lastseenstate to determine the lenght. We can keep track of the min length as we are going along.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/


// My Approaches(1)
class Solution {
public:
    int fillMaps(vector<int> nums, unordered_map<int,int> & countMap, unordered_map<int,int> & firstSeenMap,unordered_map<int,int> & lastSeenMap){
        // fills the maps and returns the degree of the array
        
        int maxCount = 0;
        for(int i=0; i<nums.size(); i++){
            int value = 0;
            
            // filling countMap and degree
                // if element doesn't exist in countMap, insert it
            if(countMap.find(nums[i]) == countMap.end())
                value = 1;
            else
                value = countMap[nums[i]] + 1;
            
            countMap[nums[i]] = value;
            maxCount = max(maxCount, value);
            
            // filling firstSeenMap and lastSeenMap
            if(firstSeenMap.find(nums[i]) == firstSeenMap.end())
                firstSeenMap[nums[i]] = i;
            lastSeenMap[nums[i]] = i;
        }
        return maxCount;
    }
    
    int getMinLength(vector<int> nums, unordered_map<int,int> countMap, unordered_map<int,int> firstSeenMap,unordered_map<int,int> lastSeenMap, int degree){
        int minLength = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(countMap[nums[i]] == degree)
                minLength = min(minLength, lastSeenMap[nums[i]] - firstSeenMap[nums[i]] + 1);
        }
        return minLength;
    }
    
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> countMap, firstSeenMap, lastSeenMap;
        // get degree of array
        int degree = fillMaps(nums, countMap, firstSeenMap, lastSeenMap);
        
        // from firstSeen, lastSeen and count maps, find elements that have the same count and minimize the length
        return getMinLength(nums, countMap, firstSeenMap, lastSeenMap, degree);
    }
};