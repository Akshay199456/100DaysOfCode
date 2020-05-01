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
Space complexity: O(n^2)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    void getAllSubstrings(vector<string> & allSubstrings, string element){
        for(int i = 0; i < element.size(); i++){
            string result = string(1,element[i]);
            allSubstrings.push_back(result);
            for(int j = i+1; j < element.size(); j++){
                result += string(1, element[j]);
                allSubstrings.push_back(result);
            }
        }
    }
    
    bool checkPalindrome(string element){
        for(int i = 0; i < element.size()/ 2; i++){
            if(element[i] != element[element.size() - i - 1])
                return false;
        }
        return true;
    }
    
    string findLongestPalindromeSubstring(vector<string> allSubstrings){
        string maxElement = "";
        int maxSize = 0;
        for(int i= 0 ; i < allSubstrings.size(); i++){
            string element = allSubstrings[i];
            if(checkPalindrome(element) && element.size() > maxSize){
                //cout<<"Element: "<<element<<endl;
                maxSize = element.size();
                maxElement = element;
            }
        }
        return maxElement;
    }
    
    
    
    void printResult(vector<string> list){
        for(int i = 0; i < list.size(); i++)
            cout<<list[i]<<" ";
        cout<<endl;
    }
    
    string findLongestPalindrome(string element){
        vector<string> allSubstrings;
        getAllSubstrings(allSubstrings, element);
        //printResult(allSubstrings);
        return findLongestPalindromeSubstring(allSubstrings);
    }
    
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        else
            return findLongestPalindrome(s);
    }
};