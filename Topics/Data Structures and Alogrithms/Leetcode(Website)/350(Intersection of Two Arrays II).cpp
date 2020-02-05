/*
-------------------------Question:

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.


Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/*
-------------------------My Approaches:

1. Using maps


*/


// My approaches(1)
class Solution {
public:
    void constructMap(unordered_map<int, int> & mapsTemplate, vector<int> numsTemplate){
        for(int i = 0; i < numsTemplate.size(); i++){
            auto it = mapsTemplate.find(numsTemplate[i]);
            if(it == mapsTemplate.end())
                mapsTemplate[numsTemplate[i]] = 1;
            else
                mapsTemplate[numsTemplate[i]] += 1;
        }
    }
    
    vector<int> returnIntersection(unordered_map<int,int> smallerMap, unordered_map<int,int> longerMap){
        vector<int> result;
        for( auto smallit = smallerMap.begin(); smallit != smallerMap.end(); smallit++){
            auto longit = longerMap.find(smallit->first);
            if(longit != longerMap.end()){
                int minValue = min(smallit->second, longit->second);
                for(int i = 0; i < minValue; i++)
                    result.push_back(smallit->first);
            }
        }
        return result;
    }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1, map2;
        constructMap(map1, nums1);
        constructMap(map2, nums2);
        if(nums1.size() <= nums2.size())
            return returnIntersection(map1, map2);
        else
            return returnIntersection(map2, map1);
    }
};