/*
-------------------------Question:

Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
num >= 1
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/
*/

/*
-------------------------My Approaches:

1. Using a vector to store the binary representation

We can use a vector to store the binary representation of a number. We just divide the number and get the
remainder as we move along and continue so till the number hits 0. If n is the no of bits used to represent
number:
n -> no of bits to represent number

Time complexity: O(n) 
Space complexity: O(n)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    vector<bool> convertDecToBinaryComplement(int num){
        vector<bool> result;
        while(num > 0){
            result.push_back(num % 2);
            num = num / 2;
        }
        
        for(int i= 0 ; i < result.size(); i++)
            result[i] = !result[i];
        
        return result;
    } 
    
    int getNumber(vector<bool> result){
        int number = 0, bitLocation = 0;
        for(int i = 0; i < result.size(); i++){
            number += pow(2, bitLocation++) * result[i];
        }
        return number;
    }
    
    int findComplement(int num) {
        vector<bool> result = convertDecToBinaryComplement(num);
        return getNumber(result);
    }
};