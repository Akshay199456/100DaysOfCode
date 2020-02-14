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

The way I solved this was that you would contruct 2 maps for each of the arrays. You would then go over
the map of one and check for the number of min occurrences in the second map if the element existed in it.

Time complexity: O(m+n)
Space complexity: O(m+n)

*/

/*
-------------------------    Other approaches:

1. Using map(Better)

You can improve upon the previous solution by only using one map instead of two. This way we save a 
little amount of space. After constructing one of the maps and going over the vector of the other,
you would check if that particular element existed in the map and if it does, subtract its occurrence
by one in the map and append it to the result vector.

Time complexity: O(m+n)
Space complexity: O(m)


2. Sorting and using a double pointer(Better in some instances)

If the inputs are already sorted, this solution will be more efficient since we are just using two pointers
to iterate through the arrays. 

Time complexity: O(mlogm) + O(nlogn) + O(n)[shorter array] = O(mlogm + nlogn)
Space complexity: O(1);
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


// Other approaches(2)

class Solution {
public:
    
    void sortVectors(vector<int> & nums1, vector<int> & nums2){
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
    }
    
    vector<int> findIntersection(vector<int> nums1, vector<int> nums2){
        int index1 = 0, index2 = 0;
        vector<int> result;
        while( (index1 < nums1.size()) && (index2 < nums2.size())){
            if(nums1[index1] == nums2[index2]){
                result.push_back(nums1[index1]);
                index1++;
                index2++;
            }
            else if(nums1[index1] < nums2[index2])
                index1++;
            else
                index2++;
        }
        return result;
    }
    
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sortVectors(nums1, nums2);
        return findIntersection(nums1, nums2);
    }
};

/*
-------------------------Follow up questions:

1. Use the other approaches(2) solution. It would be a O(n) time complexity solution[n is shorted array]
2. The other approach(1) would be a better solution since it will be a O(m) time comlpexity solution
while the sorting solution would take O(mlogm) time.
3.  I think the goal of this question is to test whether the interview understands some of the data engineering techniques. From a data engineer's perspective, basically there are three ideas to solve the question:

Store the two strings in distributed system(whether self designed or not), then using MapReduce technique to solve the problem;

Processing the Strings by chunk, which fits the memory, then deal with each chunk of data at a time;

Processing the Strings by streaming, then check. 
*/