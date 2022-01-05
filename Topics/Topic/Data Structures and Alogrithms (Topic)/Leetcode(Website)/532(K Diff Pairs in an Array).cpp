/*
-------------------------Question:
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Example 4:

Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
Output: 2
Example 5:

Input: nums = [-1,-2,-3], k = 1
Output: 2
 

Constraints:

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107
*/

/*
-------------------------    My Approaches:
1. Using hashset with hash function used to allow pairs in one hashset

The elementSet set is sued to keep track of the element we have currently seen./ For each element, we check if the elemntn+k or element-k has occurred in the set. If it hasn't, we just insert the curr element into elemtnSet. However, if it
has occurred, we will only insert the pair into the pairSet if it is a uniue pair. As a result, we use a hash function to configure the pairSet to recognize pairs and only if it is uniue do we incrmeet the count and add the pair into it.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    struct pair_hash{
        template <class T1, class T2> size_t operator() (pair<T1, T2> const & pair) const{
            size_t h1 = hash<T1>()(pair.first);
            size_t h2 = hash<T2>()(pair.second);
            return h1^h2;
        }
    };
    
    void checkValue(unordered_set<int> & elementSet, unordered_set<pair<int, int>, pair_hash> & pairSet, int curr, int k, int & count){
        if(elementSet.find(curr + k) != elementSet.end()){
            if(pairSet.find(make_pair(curr, curr+k)) == pairSet.end() && pairSet.find(make_pair(curr+k, curr)) == pairSet.end()){
                ++count;
                pairSet.emplace(make_pair(curr, curr+k));
            }
            elementSet.emplace(curr);
        }
    }
    
    
    int getPairs(vector<int> & nums, int k){
        int count = 0;
        unordered_set<int> elementSet;
        unordered_set<pair<int, int>, pair_hash> pairSet;
        
        for(int i=0; i< nums.size(); i++){
            int curr = nums[i];
            if(elementSet.find(curr + k) == elementSet.end() && elementSet.find(curr-k) == elementSet.end())
                elementSet.emplace(curr);
            else{
                checkValue(elementSet, pairSet, curr, k, count);
                checkValue(elementSet, pairSet, curr, -k, count);                
            }
        }
        return count;
    }
    
    int findPairs(vector<int>& nums, int k) {
        return getPairs(nums, k);
    }
};