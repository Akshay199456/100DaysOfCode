/*
-------------------------Question:
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

/*
-------------------------    My Approaches:
1. Using a map and prioirty queue

We can use a map to store the count of each of the ekements in the array and can then transeer that infor into a prioirty queue and extract the top k elements.

Time complexity: O(nlogn)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My approaches(1)
typedef pair<int, int> pi;

class Solution {
public:
    void createMap(unordered_map<int, int> & countMap, vector<int> & nums){
        for(int i=0; i<nums.size(); i++){
            if(countMap.find(nums[i]) == countMap.end())
                countMap[nums[i]] = 1;
            else
                countMap[nums[i]]++;
        }
    }
    
    void fillHeap(priority_queue<pi, vector<pi>> & elements, unordered_map<int, int> & countMap){
        for(auto it= countMap.begin(); it!= countMap.end(); it++)
            elements.push(make_pair(it->second, it->first));
    }
    
    void getMostFrequent(priority_queue<pi, vector<pi>> & elements, vector<int> & result, int k){
        while(k-- > 0){
            result.push_back(elements.top().second);
            elements.pop();
        }
    }
    
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        priority_queue<pi, vector<pi>> elements;
        vector<int> result;
        
        createMap(countMap, nums);
        fillHeap(elements, countMap);
        getMostFrequent(elements, result, k);
        return result;
    }
};