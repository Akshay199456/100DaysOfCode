/*
-------------------------Question:

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
*/

/*
-------------------------My Approaches:
1. Using map to store the occurrences of elements

Given that we have two arrays of differing lengths, we can generate a map from the one with the greater length. We store 
the initial value as false to indicate the status of its occurrence in the second array. Once, we have generated the map
from the array with the greater length, we step through the array with the shorter length to find the occurrence in the
map. If it does occur in the map, we then check if it is a unique element with the value stored in the map. If it is true,
then it's a duplicate and we don't add it. If it is false, then we set the value to true in the map and add it to the 
result.

Time complexity: O(m+n)
Space complexity: O(n)
*/

/*
-------------------------Other approaches

1. Sorting and using two pointers (Not implemented)

Typical approach. Check 'Helping Images' for this problem for more info.

Time complexity: O(nlogn)
Space complexity: O(1)


2. Sorting the longer array and using binary search for searching an element

Typoical approach. Check 'Helping Images' for this problem for more info.

Time complexity: O(nlogn)
Space complexity: O(1)
*/


// My Approaches(1)
class Solution {
public:
    void generateMap(vector<int> nums, unordered_map<int, bool> & elementMap){
        for(int i = 0; i < nums.size(); i++){
            if(elementMap.find(nums[i]) == elementMap.end())
                elementMap[nums[i]] = false;
        }
    }
    
    void getIntersection(vector<int> nums1, vector<int> nums2, vector<int> & result){
        unordered_map<int, bool> elementMap;
        generateMap(nums1, elementMap);
        
        for(int i = 0; i < nums2.size(); i++){
            if(elementMap.find(nums2[i]) != elementMap.end()  && !elementMap[nums2[i]]){
                elementMap[nums2[i]] = true;
                result.push_back(nums2[i]);
            }
        }
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(nums1.size() && nums2.size()){
            if(nums1.size() > nums2.size())
                getIntersection(nums1, nums2, result);
            else
                getIntersection(nums2, nums1, result);
        }
        return result;   
    }
};