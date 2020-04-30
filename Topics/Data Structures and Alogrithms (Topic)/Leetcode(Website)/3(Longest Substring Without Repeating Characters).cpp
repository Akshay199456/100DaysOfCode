/*
-------------------------Question:

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
-------------------------My Approaches:

1. Using a hashmap to store the occurrences

We can keep track of the largest substring using a hashmap. At any instance, the current character can
either exist or not in the hashmap. If it doesn't exist, we add it to the hashmap and increment the level.
We also need to check if this level is the max level that we have encountered and if so, store it.

If we have encountered the character before, continuing from a state where the character didn't exist would
provoide the best solution. As a result, to keep the condition of substring going, we need to delete every
character that occurred on or before the first encounter from the hashmap. This way the hashmap only stores
the occurrences of the ucontinuing substring going at all times. We then insert the current character into
the hashmap.

A quick note here:

If you are searchign for a character in a hashmap using charMap[s[j]] and the character doesn't exist,
the [] operator automatically creates an entry into the hashmap with s[j] as the key and the default value
for the type of the value as the value, in this case, 0. As a result, it would always show that the elemntn
existed since if the element didn't exist, it would create it and if it did exist, it would repkace it.

Time complexity: O(n^2)
Space compelxity: O(n)
*/

/*
*/
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int getLongestSubstring(string s){
        int maxLevel = 1, currentLevel = 1;
        unordered_map<char, int> charMap;
        charMap[s[0]] = 0;
        for(int i= 1; i <  s.size(); i++){
            if(charMap.find(s[i]) == charMap.end()){
                currentLevel++;
                charMap[s[i]] = i;
                if(currentLevel > maxLevel)
                    maxLevel = currentLevel;
            }
            else{
                int diff = i - charMap[s[i]];
                currentLevel = diff;
                for(int j = 0; j <= charMap[s[i]]; j++){
                    if(charMap.find(s[j])!= charMap.end() && charMap[s[j]] == j)
                      charMap.erase(charMap.find(s[j]));
                }
                charMap[s[i]] = i;
            }      
        }
        return maxLevel;
    }
    
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        return getLongestSubstring(s);
    }
};