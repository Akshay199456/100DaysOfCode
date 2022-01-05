// This problem was also solved using the UMPIRE approach

/*
-------------------------Question:

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
*/

/*
-------------------------My Approaches:

1. Using a map and set to store the occurrences

This problem can be solved efficiently using a map and a set to store the occurrences of the characters in string s and t.
To get more information about this approach, check out the corresponding images with respect to this problem in 'Helping
Images'.

Time and space complexity are both of O(n) since the both strings are assumed to be of the same length.

Time complexity: O(n)
Space complexity: O(n)

*/

/*
-------------------------Other approaches

1. Using an array instead of a map.

If we know the kind of characters we will be dealing with, we can use an array instead of a map. That way we can optimize
on space complexity. In this problem, we know that all characters are possible and since there are 128 characters with ASCII
characters that's the size I have chosen. We initialize initially the values to -1. After going through each character in
both the strings, we make sure to correspond both the characters in the strings to the same value since they are mapped
to each other. If they don't match in value, it means that they have been mapped to differnt characters and so we return 
false. If we get rhough the whole loop, we return true.

Our space complexity here is O(1) since the array is of a constant fixed size and doesn't change with input.

Time complexity: O(n)
Space complexity: O(1)
*/


// My Approaches(1)
class Solution {
public:
    bool checkIsomorphic(string s, string t){
        unordered_map<char, char> sMap;
        unordered_set<char> tSet;
        for(int i=0; i<s.size(); i++){
            auto it = sMap.find(s[i]);
            if(it != sMap.end()){
                if(sMap[s[i]] != t[i])
                    return false;
            }
            else{
                auto it = tSet.find(t[i]);
                if(it != tSet.end())
                    return false;
                sMap[s[i]] = t[i];
                tSet.emplace(t[i]);
            }
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        if(!s.size())
            return true;
        else
            return checkIsomorphic(s, t);
    }
};


// Other approaches(1)
class Solution {
public:
    bool checkIsomorphic(string s, string t){
        vector<int> sArray (128, -1), tArray(128, -1);
        for(int i=0; i<s.size(); i++){
            if(sArray[s[i]] != tArray[t[i]])
                return false;
            sArray[s[i]] = i;
            tArray[t[i]] = i;
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        if(!s.size())
            return true;
        else
            return checkIsomorphic(s, t);
    }
};