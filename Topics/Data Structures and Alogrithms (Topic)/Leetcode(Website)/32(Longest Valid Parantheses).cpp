/*
-------------------------Question:

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

/*
-------------------------My Approaches:
1. Brute force approach[Not coded]

We can use the brute force approach here to generate all possible substrings and then use a stack to check if a substring is
a valid substring or not using that stack as it has been done in several problems. The time complexity in this case would
be O(n^3) as we need O(n^2) time to generate all tyhe ubstrings and O(n) time to check if each substirng is a valid
substring.

Time complexity: O(n^3)
Space complexity: O(n)
*/

/*
-------------------------Other approaches
1.
*/

// Other Approaches(1)
class Solution {
public:
    vector<int> dpList;
    
    void constructDpList(int size){
        for(int i=0; i<size; i++)
            dpList.push_back(0);
    }
    
    void printArray(){
        for(int i=0; i<dpList.size(); i++)
            cout<<dpList[i]<<" ";
        cout<<endl;
    }
    
    int getResult(string s){
        int maxResult = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ')' && i-1>=0){
                int val = 0;
                // check for (
                if(s[i-1]=='('){
                    if(i-2>=0)
                        val += dpList[i-2];
                    dpList[i]=2+val;
                }
                // check for  )
                else if(i-dpList[i-1]-1 >=0 && s[i-dpList[i-1]-1] == '('){
                    val += dpList[i-1];
                    if(i-2-dpList[i-1]>=0)
                        val+=dpList[i-2-dpList[i-1]];
                    dpList[i]=2+val;
                }
                maxResult=max(maxResult, dpList[i]);
            }
        }
        return maxResult;
    }
    
    int longestValidParentheses(string s) {
        if(!s.size())
            return 0;
        else{
            constructDpList(s.size());
            return getResult(s);
        }
    }   
};