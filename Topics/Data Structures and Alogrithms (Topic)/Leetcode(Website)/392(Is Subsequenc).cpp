/*
-------------------------Question:

Given a string s and a string t, check if s is subsequence of t.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 10^4
Both strings consists only of lowercase characters.
*/

/*
-------------------------    My Approaches:
1. Greedy approach

We can apply the greedy approach here. When comparing s and t. Using two pointers, onse for the string s and the other for string t, we can check for the character of s in t. If the character is present, we advance the pointer for string 
s. Else, we keep advancing the pointer for string t. We end the loop when either of the pointers reach the end of the strings s and t. We know that s is a subsequuence of t if the pointer for s crosses is equal to the length fo the string
s. Else we return false;

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    bool checkSubsequence(string s, string t){
        int index = 0;
        for(int i=0; i<t.size() && index < s.size(); i++){
            if(s[index] == t[i])
                ++index;
        }
        
        if(index == s.size())
            return true;
        return false;
    }
    
    bool isSubsequence(string s, string t) {
        if(!s.size())
            return true;
        else if(s.size() > t.size())
            return false;
        return checkSubsequence(s, t);
    }
};