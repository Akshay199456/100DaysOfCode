/*
-------------------------Question:

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "0"
Output: 0
Example 4:

Input: s = "1"
Output: 1
Example 5:

Input: s = "2"
Output: 1
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

/*
-------------------------My Approaches:
1. [Time limit exceeded]

The first approach is a basic recursive approach to the problem. At each stage, we have one of two choices. We can either
choose one character or two characters to form the next combination. This is because we know that at each stage, at most,
the mapping conissts of 1-2 characters and no more. Since at each step, there are 2 choices and we continue this till we
reach the end of string, the time complexity is as given.

Time complexity: O(2^n)
Space complexity: O(n)
*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    bool checkElementValid(string element){
        int val = stoi(element);
        // cout<<"Val: "<<val<<endl;
        if(val >=1 && val <= 26)
            return true;
        return false;
    }
    
    int getNum(string s, int index, int steps){
        // cout<<"Round --------------------------------------------"<<endl;
        // cout<<"Index: "<<index<<" Steps: "<<steps<< " String size: "<<s.size()<<endl;
        if(index >= s.size()){
            // cout<<"we have crossed the boundary"<<endl;
            return 0;
        }
        else{
            string element = "";
            char ch = s[index];
            // cout<<"char: "<<s[index]<<endl;
            string s2(1, ch);
            // cout<<"s2 string: "<<s2<<endl;
            if(steps == 1)
                element += s2;
            else{
                string s1(1, s[index-1]);
                // cout<<"s1 string: "<<s1<<endl;
                element += s1 + s2;
            }
            
            // cout<<"Element: "<<element<<endl;
            if(!checkElementValid(element) || element[0] == '0'){
                // cout<<"element not valid"<<endl;
                return 0;
            }
            else if(index == s.size() - 1){
                // cout<<"Index: "<<index<<" String size: "<<s.size()<<endl;
                // cout<<"at end of string"<<endl;
                return 1;
            }
            else
                return getNum(s, index+1,1) + getNum(s, index+2, 2);
        }
    }
    
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        else
            return getNum(s, 0, 1) + getNum(s, 1, 2);
    }
};