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
1. Using the property of sorted arrays.

Since the arrays are sorted, we can use that property to fill the heap. For ay index (i,j), the contenders that could have values equla to (i,j) are (i+1,j) and (1,j+1). As a result, we insert these into the heap. The one that is the smallest
will be wt the top of the heap so we remove it and insert it into the result. The next value on the top of the heap will be the next smallest entry. We contineu doing this till we reacf th end of the heap or k==0.

The reason we initally fill in the heap with (i,0) is beacuse this makes sure that we are inserting each pair at most once into the heap as opposed to filling it multiple times resulting in dup;licates and a wrong result

Time complexity: O(k log k)
Space complexity: O(mn)


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

// Other Approaches(1)
typedef pair<int,pair<int,int>> customTemplate;

class Solution {
public:
    void printSet(set<pair<int,int>> occurredPairs){
        for(auto it = occurredPairs.begin(); it!= occurredPairs.end(); it++){
            cout<<"First elelment: "<<it->first<<" Second element: "<<it->second<<endl;
        }
    }
    
    vector<vector<int>> getSmallestPairs(vector<int> nums1, vector<int> nums2, int k){
        vector<vector<int>> result;
        priority_queue<customTemplate, vector<customTemplate>, greater<customTemplate>> elements;
        set<pair<int,int>> occurredPairs;
        
        for(int i=0; i<nums1.size(); i++)
            elements.push(make_pair(nums1[i] + nums2[0], make_pair(i,0)));
            
        // cout<<"Top of heap"<<endl;
        // cout<<"Sum: "<<elements.top().first<<" i: "<<elements.top().second.first<<" j: "<<elements.top().second.second<<endl;
        
        while(!elements.empty() && k-- > 0){
            int sum = elements.top().first;
            pair<int,int> indexPair = elements.top().second;
            elements.pop();
            int i = indexPair.first, j = indexPair.second;
            
            occurredPairs.emplace(make_pair(i,j));
            // cout<<" step sum: "<<sum<<" step i: "<<i<<" step j: "<<j<<endl;
            
            vector<int> temp{nums1[i], nums2[j]};
            result.push_back(temp);

            if(j+1 < nums2.size()){
                pair<int,int> nextPair = make_pair(i,j+1);
                if(occurredPairs.find(nextPair) == occurredPairs.end())
                    elements.push(make_pair(nums1[i] + nums2[j+1], nextPair));
            }   
        }
        // printSet(occurredPairs);
        return result;
    }
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if(!nums1.size() || !nums2.size() || !k)
            return result;
        return getSmallestPairs(nums1, nums2, k);
    }
};