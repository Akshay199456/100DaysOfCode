// This problem was also solved using the UMPIRE approach

/*
-------------------------Question:

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

/*
-------------------------My Approaches:

1. [Doesn't admit to constraints of problem] Sorting array and finding consecutive elements

One of the ways we can achieve the objective is to sort the array. By sorting the array, we have the elements in their
sorted order which helps us in finding consecutive elements. The only thing we want to amke sure is that if there are 
duplicates, then we don't add it to the length of the max subsequence.

Time complexity: O(nlog n)
Spacec complexity: O(1)
*/

/*
-------------------------Other approaches

1. Brute Force approach[Not coded]

With the brute force approach, with each number, we try to find the largest subsequence we can encounter with each number
and do that for each number in the array. We keep track of the largest subsequence we have encountered as we progress.
Check in 'Helping Images' for more information on this approach.

Time complexity: O(n^3)
Space complexity: O(1)


2. Optimization of the brute force appraoch

We can optimize the brute force approach shown above by instead using a hashmap to keep track of the elements in the map.
In addition, we only find the largest subsequence only for those elements in the array that are the beginning of the 
subsequence instead of all the elements by checking for the previous element in the array. This way we will check all the
elements in the array.

Time complexity: O(n)
Space complexity: O(n)


3. Variation of brute force approach

This approach builds upon my theory of storing the n-1 and n+1 entry into the map. Basically, you search for the element in the map. If it
exists , you don't need to do anything and can skip it. Else, you use the entries in the map to find the length of the 
max subsequence that includes the current element and store it with respect to the current element into the map. We also
want to adjust the boundaries so that the next elements that are near the boundary can use that information to get the 
max length of the subsequence and don't need to do any thing about the elements betwen the current element and the boundaries
as the only elements that will use that information are duplicates and since we are not doing any work for duplicates, we
can skip it.

Time complexity: O(n)
Space complexity: O(n)

*/

// My Approaches(1)
class Solution {
public:
    int getLengthLongestConsecutive(vector<int> nums){
        sort(nums.begin(), nums.end());
        int start = nums[0], length = 1, maxLength = 1;
        for(int i=1; i <nums.size(); i++){
            if(nums[i] - nums[i-1] <= 1){
                if(nums[i] - nums[i-1] != 0){
                    length++;
                    if(length > maxLength)
                        maxLength = length;
                }   
            }
            else{
                start = nums[i];
                length = 1;
            }
        }
        return maxLength;
    }
    
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();
        else
            return getLengthLongestConsecutive(nums);
    }
};


// Other Approaches(2)
class Solution {
public:
    void fillSet(vector<int> nums, unordered_set<int> & elementSet){
        for(int i = 0; i < nums.size(); i++)
            elementSet.emplace(nums[i]);
    }
    
    bool arrayContains(vector<int> nums, unordered_set<int> elementSet, int element){
        return !(elementSet.find(element) == elementSet.end());
    }
    
    
    
    int getLengthLongestConsecutive(vector<int> nums, unordered_set<int> elementSet){
        int maxLength = 1;
        for(int i=0; i<nums.size(); i++){
            if(elementSet.find(nums[i] - 1) == elementSet.end()){
                int currentElement = nums[i];
                int length = 1;
                while(elementSet.find(currentElement + 1) != elementSet.end()){
                    currentElement += 1;
                    length += 1;
                }
                maxLength = max(length, maxLength);
            }
        }
        return maxLength;
    }
    
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();
        else{
            unordered_set<int> elementSet;
            fillSet(nums, elementSet);
            return getLengthLongestConsecutive(nums, elementSet);
        }
    }
};


// Other Approaches(3)
class Solution {
public:
    int getLengthLongestConsecutive(vector<int> nums){
        int maxLength = 0;
        unordered_map<int,int> map;
        for(int i=0; i<nums.size(); i++){
            if(map.find(nums[i]) == map.end()){
                
                int left = (map.find(nums[i] - 1) != map.end()) ? map[nums[i] - 1]: 0;
                int right = (map.find(nums[i] + 1) != map.end()) ? map[nums[i] + 1]: 0;   
                int length = left + right + 1;
                map[nums[i]] = length;
                maxLength = max(length, maxLength);
                
                map[nums[i] - left] = length;
                map[nums[i] + right] = length;
            }
        }
        return maxLength;
    }
    
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();
        else
            return getLengthLongestConsecutive(nums);
    }
};