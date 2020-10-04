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
1. Recursive approach

The first approach is a basic recursive approach to the problem. At each stage, we have one of two choices. We can either
choose one character or two characters to form the next combination. This is because we know that at each stage, at most,
the mapping conissts of 1-2 characters and no more. Since at each step, there are 2 choices and we continue this till we
reach the end of string, the time complexity is as given.

Time complexity: O(2^n)
Space complexity: O(n)


2. Top-down approach

If we observe the 
*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    int getNum(string s, int index){
        if(index == s.size())
            return 1;
        else{
            int val = 0;
            
            bool oneDigit = s[index] == '0' ? false : true;
            if(oneDigit)
                val += getNum(s, index+1);
            
            bool twoDigit = false;
            if((index + 1 <= s.size()) && (stoi(s.substr(index,2)) >= 10 && stoi(s.substr(index,2)) <= 26))
                twoDigit = true;
            if(twoDigit)
                val += getNum(s, index+2);
            
            return val;
        }
    }
    
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        return getNum(s, 0);
    }
};


// My Approaches(2)
class Solution {
public:
    vector<int> dpList;
    
    void initializeDpList(int size){
        for(int i = 0; i < size; i++)
            dpList.push_back(-1);
    }
    
    int getNum(string s, int index){
        if(index == s.size()){
            dpList[index] = 1;
            return dpList[index];
        }
        else if(dpList[index] != -1)
            return dpList[index];
        else{
            int val = 0;
            
            bool oneDigit = s[index] == '0' ? false : true;
            if(oneDigit)
                val += getNum(s, index+1);
            
            bool twoDigit = false;
            if((index + 1 <= s.size()) && (stoi(s.substr(index,2)) >= 10 && stoi(s.substr(index,2)) <= 26))
                twoDigit = true;
            if(twoDigit)
                val += getNum(s, index+2);
            
            dpList[index] = val;
            return dpList[index];
        }
    }
    
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        
        initializeDpList(s.size() + 1);
        getNum(s,0);
        return dpList[0];
    }
};


