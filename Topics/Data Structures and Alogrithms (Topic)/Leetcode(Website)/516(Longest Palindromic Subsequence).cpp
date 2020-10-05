/*
-------------------------Question:

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
 

Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    int getRecursive(string s, int beg, int end){
        if(beg > end)
            return 0;
        else if(beg == end)
            return 1;
        else{
            if(s[beg] == s[end])
                return 2 + getRecursive(s, beg+1, end-1);
            else{
                int left = getRecursive(s, beg, end-1);
                int right = getRecursive(s, beg+1, end);
                return max(left, right);
            }
        }
    }
    
    int longestPalindromeSubseq(string s) {
        return getRecursive(s, 0, s.size()-1);
    }
};