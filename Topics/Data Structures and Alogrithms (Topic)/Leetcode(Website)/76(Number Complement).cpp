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


2. Using binary complement pattern

To find the complement of a number, there's a more easier way to find the complement rather than using a
vector to store the binary representation. For any number that's a factor of 2, the complement is num-1.
For any other number the complement is 2^n(greater than the number) - num -1.

n: number of bits
Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

1. Using bitmask

We can use bitmask to obtain the number of bits used to represent the number and then use that information
to return the complement of the number. By setting the bitmnask to ~0(or all 1s) and & with the num, we are
basically checking for the number of bits used to represent the number. Once we have that info, 0s will
be present in the indexes used to represent the number whiles 1s will be present everywhere else. So, if 
we exor with the complement of the number, we are basially selecting the bits which are active in the 
complement which is the compleemnt of the number itself.

Time complexity: O(1) since 32 bits at max used to represent number at most
Space complexity: O(1)
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


// My approaches(2)
class Solution {
public:
    double getHigherExponentiation(int num){
        double result = 0;
        int nBits = 0;
        while(num > result){
            nBits++;
            result = pow(2, nBits);
        }
        return result;
    }
    
    int findComplement(int num) {
        double result = getHigherExponentiation(num);
        if(result == num)
            return num - 1;
        return result - 1 - num;
    }
};


// Other Approaches(1)
class Solution {
public:
    int findComplement(int num) {
        unsigned int bitMask = ~0;
        while(bitMask & num)
            bitMask<<=1;
        return bitMask ^ ~num;
        // OR
        // return ~bitMask & ~num;
    }
};