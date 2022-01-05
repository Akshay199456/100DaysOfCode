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

At each index, we add at most two values. The first value is from index+1 as long as it satisfies the conditions pertaining
to a single element i.e. >=2 && <=9. The second value is from index+2 as long as it also satisifes the conditions pertaining
to 2 digit entry i.e >=10 && <=26.

Time complexity: O(2^n)
Space complexity: O(n)


2. Top-down approach

If we observe the recursive approach, we notice the recursive relationship. The number of ways for a particular index 
depends on the no of ways for index+1 and if it exist no of ways for index+2. As a result, in our top-down approach,
we use this information to populate the dpList as we are going along where we are sotring calculations as we are moving from
our goal to the base cases.

Here, dpList[5] means that if we arrive at an index that is 1 greater than the length, we know that it is a valid combinatioon
as only valid combinations would arrive at that index by satisfying the previous conditions. The rest that don't satisfy
, we don't traverse their trees at all so they would never end at the index+1. Hence, we return 1 if it arrives at index+1.
i.e dpList[5] = 1 for a string of length 4. Our goal then would be to obtain the value for dpList[0] as that would hold the
value for the entire string.

Time complexity: O(n)
Space complexity: O(n)


3. Bottom-up approach.

The bottom-up apporach is always almost better than the top-down approach as you save space in auxiliary storage and 
recursive call chain. So, we notice the base conditions in the previous example i.e dpList[string.size()] and store it as 1.
dpList[string.size()-1] is either 1 or 0 depending on whether the character at string.size() is a valid 1 character 
mapping or not. As a result, we are filling the list from string.size() + 1 to 0. This translates to the string in the order
from string.size() -> 0. In other words, for a string s = "1234", dpList[2] means that we are making the calculations 
for the string value "34" which can be composed either of element of size 1 which is "3" or element of size 2 which is "34".
So, here also, our goal is to return dpList[0] as that will hold the value for the whole string.

Time complexity: O(n)
Space complexity: O(n)


4. Iprovement on bottom-up approach

If we notice the botom-up approach, at any point we are at most using the values for the next 2 entries only. As a result,
we actually don't need the whole list and can use 2 variables only to achieve our goal. As a result, we will return
pValue which holds the most updated value.

Time complexity: O(n)
Space complexity: O(1)
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


// My Approaches(3)
class Solution {
public:
    vector<int> dpList;
    
    void initializeDpList(int size){
        for(int i = 0; i < size; i++)
            dpList.push_back(0);
        dpList[size-1] = 1;
    }
    
    void getNum(string s, int size){
        dpList[size-1] = (s[size-1] == '0') ? 0 : 1;
        for(int i = size-2; i>=0; i--){
            bool oneDigit = s[i] == '0' ? false : true;
            if(oneDigit)
                dpList[i] += dpList[i+1];
            
            bool twoDigit = false;
            if(stoi(s.substr(i,2)) >= 10 && stoi(s.substr(i,2)) <= 26)
                twoDigit = true;
            if(twoDigit)
                dpList[i] += dpList[i+2];
        }
    }
    
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        
        initializeDpList(s.size() + 1);
        getNum(s,s.size());
        return dpList[0];
    }
};


// My Approaches(4)
class Solution {
public:
    int getNum(string s, int size){
        int ppValue = 1;
        int pValue = (s[size-1] == '0') ? 0 : 1;
        for(int i = size-2; i>=0; i--){
            int temp = 0;
            bool oneDigit = s[i] == '0' ? false : true;
            if(oneDigit)
                temp += pValue;
            
            bool twoDigit = false;
            if(stoi(s.substr(i,2)) >= 10 && stoi(s.substr(i,2)) <= 26)
                twoDigit = true;
            if(twoDigit)
                temp += ppValue;
            
            ppValue = pValue;
            pValue = temp;
        }
        return pValue;
    }
    
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        return getNum(s,s.size());
    }
};
