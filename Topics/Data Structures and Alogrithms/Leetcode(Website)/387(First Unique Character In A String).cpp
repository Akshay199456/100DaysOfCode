/*

-------------------------Question:

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letter

*/

/*
-------------------------    My Approaches:

1.

The key to solving this problem is to know the order as well as the no of occurrences of the element.
Using a hashmap to store the no of occurrences of each character of the string on the first run
and then going through the string to check the first occurrence of the character that occurs once
helps achieve the solution.

Time complexity: O(n) + O(n) = O(n)
Space complexity: O(n)

To note, this solution takes O(n) to create the hashmap and another O(n) to go through the string.
As a result, if we are dealing with a very long string, this solution would cost a lot of memory.
In that case, having a sorted hashmap that maintains the order of the elements that have been 
inserted/ or using two hashmaps(one to store those that occur once - a sorted hashmap while the 
other to store more than once - a normal hashmap) can be more helpful as you wouldn't have to 
iterate through the string twice could be a more helpful solution.

*/


// My approaches(1)
class Solution {
public:
    void createMap(unordered_map<char, int> & map, string element){
        for(int i= 0 ; i < element.size() ; i++){
            auto it = map.find(element[i]);
            if(it == map.end())
                map[element[i]] = 1;
            else
                map[element[i]] += 1;
        }
    }
    
    int getFirstUnique(unordered_map<char, int> map, string element){
        for(int i = 0; i< element.size(); i++){
            if(map[element[i]] == 1)
                return i;
        }
        return -1;
    }
    
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        createMap(map, s);
        return getFirstUnique(map, s);
    }
};