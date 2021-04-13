/*
-------------------------Question:

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Using backtracking

We can use backtracking in order to solve this problem. Basically, we are dividing each substring into pieces of substrings. When we find that a substirng is a pallindrome, we push it into the list and verify if the rest of the substring
is a valid pallindrome. If it is, in that case we arrive at the end of the string , and so the whole string has been broken down into valid pallindromic substrings and we store that into our result.

Time complexity: O(2^n * n) as O(n) time is taken to generate substring and check if it sa pallindrome.
Space complexity: O(n)


2. Using Backtracking and Dynamic programming

We can apply dynamic programming on top of the backtracking appraoch to save a little additional time. We had learnt befpore that we can use a matrix to check if a string has substrings within it that are pallindromes using DP.
We can apply that approach here as well so that we don't need to check if a substring is a pallindrome again and again in O(n) time and can instead do it in O(1) time

Time complexity: O(2^n * n)
Space complexity: O(n^2)
*/

// Other Approaches(1)
class Solution {
public:
    bool isPallindrome(string word){
        for(int i=0; i<(word.size()/2); i++){
            if(word[i] != word[word.size()-1-i])
                return false;
        }
        return true;
    }
    
    void getSubstrings(string s, vector<vector<string>> & result, vector<string> list, int start, int end){
        if(start == s.size())
            result.push_back(list);
        else{
            for(int i=start; i<s.size(); i++){
                string curSubstring = s.substr(start, i-start+1); 
                if(isPallindrome(curSubstring)){
                    list.push_back(curSubstring);
                    getSubstrings(s, result, list, i+1, i+1);
                    list.pop_back();
                }
            }   
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> list;
        getSubstrings(s, result, list, 0, 0);
        return result;
    }
};

// Other Approaches(2)
class Solution {
public:
    void getSubstrings(string s, vector<vector<string>> & result, vector<string> list, int start, vector<vector<bool>> & statusMatrix){
        if(start == s.size())
            result.push_back(list);
        else{
            for(int i=start; i<s.size(); i++){
                string curSubstring = s.substr(start, i-start+1); 
                if(statusMatrix[start][i]){
                    list.push_back(curSubstring);
                    getSubstrings(s, result, list, i+1, statusMatrix);
                    list.pop_back();
                }
            }   
        }
    }
    
    void generateMatrix(string s, vector<vector<bool>> & statusMatrix){
        // initialize matrix
        for(int i=0; i<s.size(); i++){
            vector<bool> list;
            for(int j=0; j<s.size(); j++)
                list.push_back(false);
            statusMatrix.push_back(list);
        }
        
        // fillMatrix
        for(int i=s.size()-1; i>=0; i--){
            for(int j=i; j<s.size(); j++){
                if(j-i==0)
                   statusMatrix[i][j] = true;
                else if(j-i==1 && s[i] == s[j])
                    statusMatrix[i][j] = true;
                else
                    statusMatrix[i][j] = (s[i]==s[j] && statusMatrix[i+1][j-1] ? true : false); 
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> list;
        vector<vector<bool>> statusMatrix;
        generateMatrix(s, statusMatrix);
        getSubstrings(s, result, list, 0, statusMatrix);
        return result;
    }
};