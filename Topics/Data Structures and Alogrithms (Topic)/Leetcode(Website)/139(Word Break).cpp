/*
-------------------------Question:

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches
1. Brute force recursive tree approach

If we break down this problem into its components, we can notice a recursive structure. At each index, either the substring
until that index occurs in the dictionary and in that case, we check the remaining half if that occurs in the directionary
either directly by its presence in the doictionary or by indeirectly by being composed of words that are avaialble in the
dictionary. The other possibility is that the substring till that index doesn't occur in the dictonary. 

This is why at each step, we check for two conditions for all possible substring combinations starting from index 0 of the
string. The first check is for whether the substring from 0 to current index exists in the dictionary and the second is for
the recurisve check on whether the substring i+1:end exists in the dictionary either directly by its presence or indeirectly 
by constructting it from those elements present in the dictionary

Time compleixty: O(2^n)
Space complexity: O(1)
*/

// Other Approaches(1)
class Solution {
public:
    unordered_set<string> wordSet;
    
    void constructSet(vector<string> wordDict){
        for(int i = 0; i < wordDict.size(); i++)
            wordSet.emplace(wordDict[i]);
    }
    
    bool wordBreakCheck(string s){
        if(!s.size())
            return true;
        else{
            for(int i = 0; i < s.size(); i++){
                if(wordSet.find(s.substr(0,i+1)) != wordSet.end() && wordBreakCheck(s.substr(i+1)))
                    return true;
            }
            
            return false;
        }
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        constructSet(wordDict);
        return wordBreakCheck(s);
    }
};