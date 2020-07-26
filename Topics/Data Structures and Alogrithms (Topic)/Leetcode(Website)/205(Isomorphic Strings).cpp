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

Time complexity: O(n)
Space complexity: O(n)

*/

/*
-------------------------Other approaches

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