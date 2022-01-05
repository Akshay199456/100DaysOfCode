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

1. Backtracking with recursiveness

We can use the backtracking approach to solve this problem. To solve this problem, we want to make sure 
the final solution of the problem has the same length as the length of the given string with the digits.
So, we keep adding characters to the current running string by finding it's mapping and adding characters.

Time complexity: O(3^n)
Space complexity: O(3^n)


2. Using iterative approach

We can also use an iterative approach to solve this problem. We use a queue to keep pushing the mappings
from the digits. We continue this till all the digits have been covered. Whatever is then remaning in the
queue is the set of solutions to the problem.

Time complxity: O(3^n)
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


// My Approaches(2)
class Solution {
public:
    unordered_map<char, string> characterMapping;
    void generateMap(){
        characterMapping['0'] = "";
        characterMapping['1'] = "";
        characterMapping['2'] = "abc";
        characterMapping['3'] = "def";
        characterMapping['4'] = "ghi";
        characterMapping['5'] = "jkl";
        characterMapping['6'] = "mno";
        characterMapping['7'] = "pqrs";
        characterMapping['8'] = "tuv";
        characterMapping['9'] = "wxyz";
    }
    
    void generateSolution(string digits, vector<string> & result){
        queue<string> combQueue;
        combQueue.push("");
        for(int i = 0; i < digits.size(); i++){
            string mapping = characterMapping[digits[i]];
            int length = combQueue.size();
            for(int k = 0; k < length; k++){
                for(int j =0; j < mapping.size(); j++){
                    string s(1, mapping[j]);
                    combQueue.push(combQueue.front() + s);
                }
                combQueue.pop();
            }
        }
        fillResult(result, combQueue);
    }
    
    void fillResult(vector<string> & result, queue<string> combQueue){
        while(!combQueue.empty()){
            result.push_back(combQueue.front());
            combQueue.pop();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()){
            generateMap();
            generateSolution(digits, result);
        }
        return result;
    }
};