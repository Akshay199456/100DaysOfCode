/*
-------------------------Question:

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

/*
-------------------------    My Approaches:
1. Applying criteria to the word

We can goo through the string and check if it meets the criteria

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    int getCapitalNumber(string word){
        int nCapital = 0;
        for(int i = 0; i < word.size(); i++){
            if(isupper(word[i]))
                ++nCapital;
        }
        return nCapital;
    }
    
    bool detectCapitalUse(string word) {
        int nCapital = getCapitalNumber(word);
        if(nCapital == 0 || nCapital == word.size() || (nCapital == 1 && isupper(word[0])))
            return true;
        return false;
    }
};