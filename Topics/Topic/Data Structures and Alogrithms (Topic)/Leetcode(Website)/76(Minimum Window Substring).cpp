/*
-------------------------Question:

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

/*
-------------------------    My Approaches:
1. Sliding window approach

We can apply the sliding window problem cause we are looking at substrings. As long as the number of characters are not matching, we can mve the right ptr forward and check the condition. Once the condition is satisifed, we want to
remove the characters from the left ptr till condition is not satisifed and keep repeating this process.

Time complexity: O(m+n)
Space complexity: O(m+n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void createMap(string t, unordered_map<char, pair<int, bool>> & tMap){
        for(int i=0; i< t.size(); i++){
            if(tMap.find(t[i]) == tMap.end())
                tMap[t[i]] = make_pair(1, false);
            else
                tMap[t[i]] = make_pair(tMap[t[i]].first+1, false);
        }
    }
    
    string findMinWindow(string s, unordered_map<char, pair<int,bool>> & tMap){
        int beg = 0, end = 0, minBeg = INT_MAX, minLength = INT_MAX, matchingCount = 0;
        bool isEnd = false;
        unordered_map<char, int> sMap;
        
        while(beg<=end && !isEnd){
            if(end < s.size() && matchingCount < tMap.size()){
                // add character to map of s
                if(sMap.find(s[end]) == sMap.end())
                    sMap[s[end]] = 1;
                else
                    sMap[s[end]]++;
                
                // check if the char satisifes condition
                if(tMap.find(s[end]) != tMap.end() && sMap[s[end]] >= tMap[s[end]].first && !tMap[s[end]].second){
                    matchingCount++;
                    tMap[s[end]] = make_pair(tMap[s[end]].first, true);
                }
                end++;
            }
            else if(matchingCount == tMap.size()){
                if(minLength > end-beg){
                    minLength = end-beg;
                    minBeg = beg;
                }
                
                // need to remove characters till matchingCount < tMap.size()
                sMap[s[beg]]--;
                if(tMap.find(s[beg]) != tMap.end() && sMap[s[beg]] < tMap[s[beg]].first){
                    --matchingCount;
                    tMap[s[beg]] = make_pair(tMap[s[beg]].first, false);
                }
                
                if(sMap[s[beg]] == 0)
                    sMap.erase(s[beg]);
                beg++;
            }
            else
                isEnd = true;
        }
        
        if(minBeg == INT_MAX)
            return "";
        return s.substr(minBeg, minLength);
    }
    
    
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "";
        
        unordered_map<char, pair<int,bool>> tMap;
        createMap(t, tMap);
        return findMinWindow(s, tMap);
    }
};