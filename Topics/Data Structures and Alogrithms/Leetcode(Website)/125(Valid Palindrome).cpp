/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

/*
-------------------------    My Approaches:

1. 

The approach I came up with is a simple palindrome check that uses two pointers that initially
point to the beginning and the end of the string. If the characters are both alnum, we compare
their lowercase representations. If they are equal, we increment start and decrement end by 1. If
they are not equal, we return false as it's not a palindrome. If either of them are not alnum, 
we adjust the ointer depending on whether the start or the end element is not alphanumeric. We
continue this till start<end. If it comes out of the loop, we know that it's a palindrome, so we
return true;

Time complexity: O(n/2) = O(n)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

1. 
*/


// My approach(1)
class Solution {
public:
    bool checkPalindrome(string element){
        int start = 0, end = element.size() - 1;
        
        while( start < end){
            int startElement = element[start], endElement = element[end];
            
            if(isalnum(startElement) && isalnum(endElement)){
                if(tolower(startElement) == tolower(endElement)){
                    start++;
                    end--;
                }
                else
                    return false;
            }
            
            else{
                if(!isalnum(startElement))
                    start++;
                if(!isalnum(endElement))
                    end--;
            }
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        else
            return checkPalindrome(s);
    }
};