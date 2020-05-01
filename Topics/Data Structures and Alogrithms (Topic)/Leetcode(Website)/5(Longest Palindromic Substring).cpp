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

1. Using mirroring property of Palindromes(Dynamic Programming)[Better]

If you take a string that's a palindrome, you notice that starting from its center, every character to its
left and right are equal.

eg: aba -> starting from b, every character i-1, i+1 are equal to each other
    abba -> here, we assume the center to be between the two midpoints[b and b]. every character i-1, i+1
            are equal to each other

In addition, if you look at a palindrome like 'aba' and 'abba', each of these palindromes can be broken into
two core conditions. The general condition being 
    P(i,j) = {
                true if Si.....Sj is a palindrome
                false otherwise
              }
    
    and P(i,j) = P(i+1, j-1) && S[i] == S[j]

The two core conditions are:
    P(i,i) = true (Since a string of length 1 is always a palindrome and odd length)
    P(i,i+1) = true if S[i] == S[i+1][ String of length 2 and even length]

Every other string can be broken down into one of these conditions. We will be using these conditions
to test for palindromes as we pass through the stirng element.

Now, we can divide the string into 2n-1 centers => n from the single element and n-1 from the double element.
We test for these conditions at the 2n-1 centers as we progress through the string. The reason we choose the
centers is because the palindromes mirror around the center. Hence, if our centers are equal, we can expand
outwards from there and keep the same check going.

Time complexity: O(n^2) => Going through the string of length n and for each center, worse case is that
we will go throguh the whole string.
Space complexity: O(1)

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



// Other Approaches(1)
class Solution {
public:
    string findLongestPalindrome(string element){
        // will be used to store the beginning and end index of the palindromic substring
        int start = 0, end = 0;
        for(int i = 0; i < element.size(); i++){
            //finding the max length using the single center
            int singleCenterLength = extendPalindromeSubstring(element,i,i);
            //finding the max length using the double center
            int doubleCenterLength = extendPalindromeSubstring(element,i,i+1);
            // only need the largest length from them since that's what we are looking for
            int maxLength = max(singleCenterLength, doubleCenterLength);
            
            // only if the length of the current palindrome is greater than what we had
            if(maxLength > (end - start + 1)){
                start = i - (maxLength - 1) / 2;
                end = i + maxLength / 2;   
            }
        }
        return element.substr(start, end - start + 1);
    }
    
    int extendPalindromeSubstring(string element, int left, int right){
        // as long as we are within the limits of the string, we can keep moving outward both on the left
        // and the right starting from the current center
        while((left >= 0 && right <element.size()) && (element[left] == element[right])){
            left--;
            right++;
        }
        // returning the length of the palindromic substring
        return right - left - 1;
    }
    
    
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        else
            return findLongestPalindrome(s);
    }
};