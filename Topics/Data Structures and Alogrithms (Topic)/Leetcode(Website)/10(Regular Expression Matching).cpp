/*
-------------------------Question:

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false
 

Constraints:

0 <= s.length <= 20
0 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Dynamic Programming

We can solve this problem with DP approach. We are going to make use of one extra row and one extra column to store results and populate them. Now, comparison for characters on both ends are easy. If they don't match, that element is false.
If they match, we now tknow that they match. So, we must compare [i-1][j-1] to see if they match cause if they do, then this element is true else its false. The premise is that if the characters match, then we just need to compare the
rest of the s and p from the beginning to check if they match and this is possible through [i-1][j-1]. This also applies for any '.' that we compare on the pattern.

The other case that we run into is the '*'. When we run into '*', there are 1 of two posiibilites we need to check. Since '*' indicates 0 or more occurences, the first check we want to make is for 0 occcurrences of the character. The
infomation for that can be obtained from [i][j-2] since that indicates the absence of the character in p. If that is true, our element is true. If that isn't, we then need to compare the current character in s with the previous character 
in p to see if the characters in s are extending the previous character in p. As a result, we compare with [i-1][j] to get that result.

Additional references: https://www.youtube.com/watch?v=l3hda49XcDE&ab_channel=TusharRoy-CodingMadeSimple

Time complexity: O(mn)
Space complexity: O(mn)
*/

// Other Approaches(1)
class Solution {
public:
    void printMatrix(vector<vector<bool>> dpMatrix){
        for(int i=0; i<dpMatrix.size(); i++){
            for(int j=0; j<dpMatrix[0].size(); j++){
                cout<<dpMatrix[i][j]<<" ";
            }   
            cout<<endl;
        }
    }
    
    bool isMatch(string s, string p) {
        vector<vector<bool>> dpMatrix;
        
        // defining dp Matrix and setting first column
        for(int i=0; i < s.size() +1 ; i++){
            vector<bool> list(p.size()+1, false);
            dpMatrix.push_back(list);
        }
        dpMatrix[0][0] = true;
        
        // setting first row
        for(int j=1; j < p.size()+1; j++){
            if(p[j-1] == '*')
                dpMatrix[0][j] = dpMatrix[0][j-2];
        }
        
        // setting other rows
        for(int i=1; i< s.size() +1; i++){
            for(int j=1; j < p.size() + 1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dpMatrix[i][j] = dpMatrix[i-1][j-1];
                else if(p[j-1] == '*'){
                    if( (j-2 >=0 && dpMatrix[i][j-2]) || ((p[j-2] == s[i-1] || p[j-2] == '.') && dpMatrix[i-1][j]))
                        dpMatrix[i][j] = true;
                }
            }
        }
        
        // printMatrix(dpMatrix);
        return dpMatrix[s.size()][p.size()];
    }
};