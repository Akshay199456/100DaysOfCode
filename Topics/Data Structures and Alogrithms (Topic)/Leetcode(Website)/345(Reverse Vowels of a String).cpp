/*
-------------------------Question:

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/

/*
-------------------------    My Approaches:
1. Using two pointer approach

We can use the two pointer approach, one at the beginning and the other at the end of the string to exchange if vowels

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// MY Approaches(1)
class Solution {
public:
    unordered_set<char> vowelSet;
    
    void constructSet(){
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        int size = sizeof(vowels)/ sizeof(vowels[0]);
        for(int i= 0; i < size; i++)
            vowelSet.emplace(vowels[i]);
    }
    
    void reverseString(string & word){
        int beg = 0, end = word.size()-1;
        while(beg < end){
            if(vowelSet.find(tolower(word[beg])) == vowelSet.end())
                beg++;
            else if(vowelSet.find(tolower(word[end])) == vowelSet.end())
                end--;
            else
                swap(word[beg++], word[end--]);
        }
    }
    
    string reverseVowels(string s) {
        constructSet();
        reverseString(s);
        return s;
    }
};