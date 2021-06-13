/*
-------------------------Question:

Given a string s, return the last substring of s in lexicographical order.

 

Example 1:

Input: s = "abab"
Output: "bab"
Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
Example 2:

Input: s = "leetcode"
Output: "tcode"
 

Constraints:

1 <= s.length <= 4 * 105
s contains only lowercase English letters.
*/

/*
-------------------------    My Approaches:
1. Pushing all substrings and then sorting them [Time limit eceeded]

This brute force approach generates all the substrings from the string, then sorts through the results and displays the last substring in that collection

Time complexity: O(n^3 log (n^2))
Space complexity: O(n^2)
*/

/*
-------------------------    Other approaches:

*/

// My Approafches(1) [Time limit exceeded]
class Solution {
public:
    void generateSubstrings(string & s, vector<string> & allSubstrings){
        for(int i=0; i< s.size(); i++){
            string temp = "";
            for(int j=i; j < s.size(); j++){
                temp += s[j];
                allSubstrings.push_back(temp);
            }
        }
    }
    
    string lastSubstring(string s) {
        vector<string> allSubstrings;
        generateSubstrings(s, allSubstrings);
        sort(allSubstrings.begin(), allSubstrings.end());
        return allSubstrings[allSubstrings.size()-1];
    }
};