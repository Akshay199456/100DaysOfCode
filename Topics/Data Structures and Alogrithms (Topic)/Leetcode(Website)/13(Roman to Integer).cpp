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
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4
*/

/*
-------------------------My Approaches:

1. Using a hashmap to store the roman numerals.

We can use a hashmap to store the roman numerals. We start calculating the value from the end to 
the beginning of the stirng. For all the letters of the string except the end letter, we have to
check the value of the letter to the right. If it's more than the value of the current letter, we
subtract it from the total, else we add it to the total.

Time complexity: O(n)
Space complexity: O(c) -> constant size for the mappings



2. Omitting the hashamp

If the mappinggs are of constant length, we can eliminate the hashmap and instead use if statements.
This is because, to retrieve value from a hashmap, it needs the hash the key, find th location
according to the hashed value and then return the value associated with the key. This takes quite 
some time as compared to just returning the value for a constant size mapping through if statements.


Time complexity: O(n)
Space complexity: O(1)
*/



// My Approach(1)
class Solution {
public:
    void constructMap(unordered_map<char, int> & romanNumerals){
        romanNumerals['I'] = 1;
        romanNumerals['V'] = 5;
        romanNumerals['X'] = 10;
        romanNumerals['L'] = 50;
        romanNumerals['C'] = 100;
        romanNumerals['D'] = 500;
        romanNumerals['M'] = 1000;
    }
    
    int getInteger(unordered_map<char, int> romanNumerals, string element){
        int total = romanNumerals[element[element.size() - 1]];
        for(int i = element.size() - 2; i >= 0; i--){
            if(romanNumerals[element[i]] < romanNumerals[element[i+1]])
                total -= romanNumerals[element[i]];
            else
                total += romanNumerals[element[i]];
        }
        return total;
    }
    
    int romanToInt(string s) {
        if(s.length() == 0)
            return 0;
        else{
            unordered_map<char, int> romanNumerals;
            constructMap(romanNumerals);
            return getInteger(romanNumerals, s);
        }
    }
};



// My Approach(2)
class Solution {
public:
    int getRomanValue(char letter){
        if(letter == 'I')
            return 1;
        else if(letter == 'V')
            return 5;
        else if(letter == 'X')
            return 10;
        else if(letter == 'L')
            return 50;
        else if(letter == 'C')
            return 100;
        else if(letter == 'D')
            return 500;
        else if(letter == 'M')
            return 1000;
        
        return 0;
    }
    
    int getInteger(string element){
        int total = getRomanValue(element[element.size() - 1]);
        for(int i = element.size() - 2; i >= 0; i--){
            int value = getRomanValue(element[i]);
            if(value < getRomanValue(element[i+1]))
                total -= value;
            else
                total += value;
        }
        return total;
    }
    
    int romanToInt(string s) {
        if(s.length() == 0)
            return 0;
        else
            return getInteger(s);
    }
};