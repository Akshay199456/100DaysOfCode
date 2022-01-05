/*
-------------------------Question:

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/

/*
-------------------------My Approaches:
1. Using two pointer approach

We can use the two pointer appraoch here to reverse each word in place. When we ecnounter a space, that's when we reverse
the word and continue with the next

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    void reverseEachWord(string & s, int beg, int end){
        while(beg < end){
            swap(s[beg++], s[end--]);
        }
    }
    
    string reverseWords(string s) {
        int beg = 0, end = 0;
        while(end < s.size()){
            if(s[end] != ' ')
                ++end;
            else{
                reverseEachWord(s, beg, end-1);
                beg = end+1;
                end = beg;
            }
        }
        reverseEachWord(s, beg, end-1);
        return s;
    }
};