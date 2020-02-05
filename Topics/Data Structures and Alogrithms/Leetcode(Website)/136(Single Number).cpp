/*
-------------------------Question:

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4

*/

/*
-------------------------My Approaches:

1. Use of map

The way I planned to solve this problem was to create a map from the elements in the array and store
the count of the elements in the map. This would happen in O(n) time complexity.

We would then go through the map and find the element with the key whose value was equal to one. This
would in the worst case take up O(n) time as well.

As a result:

Time complexity: O(n) + O(n) = O(n)
Space compexity: O(n)

*/

/*
-------------------------    Other approaches:

1. Using a more efficient use of the map/set(Better)

The other way we can improve the approach I used was to rather use a set. As we are going through
the array, we can check if the element exists in the set. If it doesn't, we add it to the set to indicate
that the element has been encountered. So, if we encounter it the next time in the set, we know that
we have seen the element before and as a result, can remove it from the set. This way, at the end of
spanning the array, we will only have 1 element in the set and that is the element which occurs only once
in the array. This prevents of having to go though the map a second time as in my approach(1).

Time complexity: O(n) + O(1) = O(n)
Space complexity: O(n) since it still requires O(n) space to store the elements.

Definitely more faster than My approach(1) but not a big improvement. This is because it still takes O(n)
time in iterating through the vector and creating the set.


2.

*/

// My approach(1)
class Solution {
public:
    void constructMap(unordered_map<int, int> & map, vector<int> nums){
        for(int i = 0; i< nums.size(); i++){
            auto iterator = map.find(nums[i]);
            if(iterator == map.end())
                map[nums[i]] = 1;
            else
                map[nums[i]] += 1;
        }
    }
    
    int findSolution(unordered_map<int, int> map){
        for(auto it = map.begin(); it != map.end(); it++){
            if(it->second == 1)
                return it->first;
        }
        return -1;
    }
    
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        constructMap(map, nums);
        return findSolution(map);
        
    }
};

// Other approaches(1)
class Solution {
public:
    void constructSet(unordered_set<int> & set, vector<int> nums){
        for(int i = 0; i< nums.size(); i++){
            auto iterator = set.find(nums[i]);
            if(iterator == set.end())
                set.insert(nums[i]);
            else
                set.erase(nums[i]);
        }
    }
    
    int findSolution(unordered_set<int> set){
        auto it = set.begin();
        return *it;
    }
    
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        constructSet(set, nums);
        return findSolution(set);
        
    }
};
