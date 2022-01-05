/*
-------------------------Question:

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.
*/

/*
-------------------------My Approaches:

1. Breaking down into different components

We can break down this problem into 4 different components. During our first iteration, we get rid of extra spaces in
between that's more than two. During the second iteraton, we get rid of trailign and leading zeros. We then reverse the
whole string and finally reverse each word in the stirng. This gives the output we desire.

Time complexity: O(n)
Space complexity: O(1)

*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    void getRidLeadingTrailingSpaces(string & s){
        int beginNonSpace = 0, endNonSpace = s.size() - 1;
        bool isEnd = false;
        // getting first Non space character index from beginning
        while(beginNonSpace < s.size() && !isEnd){
            if(s[beginNonSpace] == ' ')
                beginNonSpace++;
            else
                isEnd = true;
        }
        // getting first non space character index from end
        isEnd = false;
        while(endNonSpace >= 0 && !isEnd){
            if(s[endNonSpace] == ' ')
                endNonSpace--;
            else
                isEnd = true;
        }
        
        // set string to the modified string
        s = s.substr(beginNonSpace, endNonSpace-beginNonSpace+1);
    }
    
    void getRidMultipleSpaces(string & s){
        int complete = 0, begin = 0;
        bool isFirstSpaceOccurred = false;
        while(begin < s.size()){
            // if not space exchange character at complete with that of begin
            if(s[begin] != ' '){
                isFirstSpaceOccurred = false;
                swap(s[complete++], s[begin++]);
            }
            //else
            else{
                // if not first space
                if(isFirstSpaceOccurred){
                    begin++;
                }
                // if not first space
                else{
                    isFirstSpaceOccurred = true;
                    complete++;
                    begin++;
                }
            }
        }
        
        while(complete < s.size()){
            s[complete++] = ' ';
        }
    }
    
    void reverseString(string & s, int beg, int end){
        while(beg < end){
            swap(s[beg++], s[end--]);
        }
    }
    
    void reverseEachString(string & s){
        int beg = 0, end = 0;
        bool isSpaceEncountered = false;
        while(end < s.size()){
            if(s[end] != ' '){
                isSpaceEncountered = false;
                end++;
            }
            else{
                isSpaceEncountered = true;
                reverseString(s,beg, end-1);
                beg = end+1;
                end = beg;
            }
        }
        reverseString(s, beg, end-1);
    }
    
    string reverseWords(string s) {
        getRidMultipleSpaces(s);
        getRidLeadingTrailingSpaces(s);
        reverseString(s, 0, s.size() - 1);
        reverseEachString(s);
        return s;
    }
};