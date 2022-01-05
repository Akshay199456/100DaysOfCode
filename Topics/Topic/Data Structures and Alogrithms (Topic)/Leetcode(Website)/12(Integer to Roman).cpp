/*
-------------------------Question:

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Example 2:

Input: num = 4
Output: "IV"
Example 3:

Input: num = 9
Output: "IX"
Example 4:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999
*/

/*
-------------------------    My Approaches:
1. Greedy approach

Given that anything at involves 4 or 9 on the unit, tens and hundreds place leads to a differnt order of the symbols, we can use that to solve the problem.
With every symbol we consider, we add it to the result and deduct it from our number. We do this till our number is not zero.

Time complexity: O(1)
Space coplexiy: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    vector<string> getSymbols(int num){
        vector<string> result;
        string deductAmount = "", symbolUsed = "";
        if(num >= 1000){
            deductAmount = "1000";
            symbolUsed = "M";
        }
        else if(num >= 500){
            deductAmount = "500";
            symbolUsed = "D";
        }
        else if(num >= 100){
            deductAmount = "100";
            symbolUsed = "C";
        }
        else if(num >= 50){
            deductAmount = "50";
            symbolUsed = "L";
        }
        else if(num >= 10){
            deductAmount = "10";
            symbolUsed = "X";
        }
        else if(num >= 5){
            deductAmount = "5";
            symbolUsed = "V";
        }
        else{
            deductAmount = "1";
            symbolUsed = "I";
        }
        
        result.push_back(deductAmount);
        result.push_back(symbolUsed);
        
        return result;
    }
    
    vector<string> findBestSymbol(int num, string & result, unordered_map<int, vector<string>> & elementMapping){
        if(num == 4 || num == 9)
            return elementMapping[num];
        else if(num >= 40 && num < 50)
            return elementMapping[40];
        else if(num >= 90 && num < 100)
            return elementMapping[90];
        else if(num >= 400 && num < 500)
            return elementMapping[400];
        else if(num >= 900 && num < 1000)
            return elementMapping[900];
        else
            return getSymbols(num);
    }
    
    string getConvertedNumber(int num, unordered_map<int, vector<string>> & elementMapping){
        string result= "";
        while(num > 0){
            vector<string> collectionPair = findBestSymbol(num, result, elementMapping);
            num -= stoi(collectionPair[0]);
            result += collectionPair[1];
        }
        return result;
    }
    
    string intToRoman(int num) {
        unordered_map<int, vector<string>> elementMapping = {{4, {"4", "IV"}}, {9, {"9", "IX"}}, {40, {"40", "XL"}}, {90, {"90", "XC"}}, {400, {"400", "CD"}}, {900, {"900", "CM"}}};
        return getConvertedNumber(num, elementMapping);
    }
};
