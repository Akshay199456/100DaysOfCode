/*
-------------------------Question:

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
 

Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".
*/

/*
-------------------------    My Approaches:
1. Using pow

We can use pow to calculate the value fore ach column as we are pogressing

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0, index = 0;
        for(int i = s.size()-1; i>=0; i--){
            result += pow(26, index++) * (s[i] - 'A' +1);
        }
        return result;
    }
};