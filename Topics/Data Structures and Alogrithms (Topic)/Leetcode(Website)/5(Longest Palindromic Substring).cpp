/*
-------------------------Question:

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

/*
-------------------------My Approaches:

1. Brute Force Approach[Worst]

The brute force approch is simple. Generate all the substring combinations of the given string and for each
substring, check if it's a palindrome. If it is and it is of the max length that has been encoutnered, 
store the result. At the end, you want to return the string with the max length;

Time complexity: O(n^3)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    bool checkPalindrome(string element){
        for(int i = 0; i < element.size()/ 2; i++){
            if(element[i] != element[element.size() - i - 1])
                return false;
        }
        return true;
    }
    
    string findLongestPalindrome(string element){
        //printResult(allSubstrings);
        string maxElement = string(1,element[0]);
        int maxSize = 1;
        for(int i = 0; i < element.size(); i++){
            string result = string(1,element[i]);
            for(int j = i+1; j < element.size(); j++){
                result += string(1, element[j]);
                if(checkPalindrome(result) && result.size() > maxSize){
                    maxSize = result.size();
                    maxElement = result;
                }
            }
        }
        return maxElement;
    }
    
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        else
            return findLongestPalindrome(s);
    }
};