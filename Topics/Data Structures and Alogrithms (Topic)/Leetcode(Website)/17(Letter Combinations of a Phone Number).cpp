/*
-------------------------Question:

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

/*
-------------------------My Approaches:

1. Backtracking 

We can use the backtracking approach to solve this problem. To solve this problem, we want to make sure 
the final solution of the problem has the same length as the length of the given string with the digits.
So, we keep adding characters to the current running string by finding it's mapping and adding characters.

Time complexity: O(3^n)
Space complexity: O(3^n)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    unordered_map<char, string> characterMapping;
    void generateMap(){
        characterMapping['2'] = "abc";
        characterMapping['3'] = "def";
        characterMapping['4'] = "ghi";
        characterMapping['5'] = "jkl";
        characterMapping['6'] = "mno";
        characterMapping['7'] = "pqrs";
        characterMapping['8'] = "tuv";
        characterMapping['9'] = "wxyz";
    }
    
    void generateSolution(string digits, vector<string> & result, string runningString, int index){
        if(index < digits.size()){
            char currentChar = digits[index];
            string mappingString = characterMapping[currentChar];
            for(int i = 0; i < mappingString.size(); i++){
                string s(1, mappingString[i]);
                generateSolution(digits, result, runningString + s, index+1);
            }
        }
        
        else
            result.push_back(runningString);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()){
            generateMap();
            generateSolution(digits, result, "", 0);
        }
        return result;
    }
};