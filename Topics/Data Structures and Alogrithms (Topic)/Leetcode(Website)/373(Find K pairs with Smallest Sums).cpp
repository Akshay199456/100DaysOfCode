/*
-------------------------Question:

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]] 
Explanation: The first 3 pairs are returned from the sequence: 
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence: 
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*/

/*
-------------------------    My Approaches:
1. Using a prioity queue to store final results

We can calculate the sum from each pair and store it into a min heap. We can then pop as we go along and push the result into a vector which is returned back.

Time complexity: O(mn logmn)
Space complexity: O(mn)
*/

/*
-------------------------    Other approaches:

*/


// My Approaches(1)
typedef pair<int,vector<int>> temp;

class Solution {
public:
    vector<vector<int>> getSmallestPairs(vector<int> nums1, vector<int> nums2, int k){
        vector<vector<int>> result;
        priority_queue<temp, vector<temp>, greater<temp>> elements;
        
        // create entries for each sum pair
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                vector<int> list{nums1[i], nums2[j]};
                elements.push(make_pair(nums1[i]+nums2[j], list));
            }
        }
        
        if(k < 0 || k > nums1.size() * nums2.size())
            k = nums1.size() * nums2.size();
        
        // get top k from heap
        for(int i=0; i<k; i++){
            result.push_back(elements.top().second);
            elements.pop();
        }
        
        return result;
    }
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if(!nums1.size() || !nums2.size() || !k)
            return result;
        return getSmallestPairs(nums1, nums2, k);
    }
};