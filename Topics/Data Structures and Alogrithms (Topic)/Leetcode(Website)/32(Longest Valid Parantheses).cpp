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
1. Using DP as a bottom up-approach.

We know that a valid substring at the least will end with a ')'. We can't have substrings that end with '(' as the '(' would
have to cancel the ')' in order for the substring to be valid. Since we know that the substrings must end with a ')', there
are 2 different variations of which a valid substring can occur. One, as I casll i, is the adjacent substring of the form
'()()' where the substring is being closed immediately and so you have a '(' at the index-1 position. The second, is
a containsing substring, in which you have a valid substring contained within another like '(())'. In this case, we would
need to check the character at index-1-dpList[index-1] and see if the character is '('; if it is ,we know that it is a valid
containsing substring. We use these 2 checks as we along.

Time complexity: O(n)
Space complexity: O(n)


2. Using a stack

We can also use a stack to solve this problem. We know that we can use a stack to check whether a substring is valid or not
by checking if it's empty after pushing in all the elements. We can slightly modify this approach by storing indexes
of possible starts, indexes from which we can have valid substrings. At the end, we are only left with indexes which were
invalid starts in the stack. Every other valid indexes have been removed and the maxLEngth has been calculated with respect
to it on removal.

Time complexity: O(n)
Space complexity: O(n)


3. Using two pointers

We use balance checking specific to this problem in order to determine if we have a valid substring or not. Since we can't
catach the longest substring from either the front or the back, we need to use a combination of the two to ctach the full
solution. For every index, if we encounter a '(' we increament left by 1 else we increment right by 1. If left == right,
then we have obtained a valid substring so we record its length. Else, if on the forward pass if right > left, we reset
both to 0 since we won't get a valid substring including it. Similarly on the backward pass if left > right, then we need
to reset left and right as we won't get a valid substring after it.

Time complexity: O(n)
Space complexity: O(1)
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


// Other Approaches(2)
class Solution {
public:
    stack<int> indexStack;
    
    int getResult(string s){
        int maxResult = 0;
        for(int i=0; i < s.size(); i++){
            if(s[i] == '(')
                indexStack.push(i);
            else{
                indexStack.pop();
                if(indexStack.empty())
                    indexStack.push(i);
                else
                    maxResult = max(maxResult, i - indexStack.top());
            }
        }
        return maxResult;
    }
    
    int longestValidParentheses(string s) {
        if(!s.size())
            return 0;
        else{
            indexStack.push(-1);
            return getResult(s);
        }
    }
};

// Other Approaches(3)
class Solution {
public:
    int getResult(string s){
        // using balance checkinf for left to right
        int left = 0, right = 0, maxLength = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(right==left)
                maxLength = max(maxLength, 2*right);
            else if(right > left){
                left =0;
                right = 0;
            }
        }
            
        // using balance checkinf for right to left
        left = 0, right = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(right==left)
                maxLength = max(maxLength, 2*right);
            else if(left > right){
                left =0;
                right = 0;
            }
        }
        return maxLength;
    }
    
    int longestValidParentheses(string s) {
        if(!s.size())
            return 0;
        return getResult(s);
    }
};