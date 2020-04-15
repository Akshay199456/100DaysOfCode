/*
-------------------------Question:

Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

 

Example 1:

Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
 

Note:

Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above the input represents the signed integer -3.
 

Follow up:

If this function is called many times, how would you optimize it?
*/

/*
-------------------------My Approaches:

1. Converting number to its bit representation[Worst]


We can convert the unsigned number to its bit string representation and then calculate the number of 
bits which are one in it by going through the string.

If n is the maximum number of bits required to represent the number. In addition, we can use
bitset library to store the binary representation of the number.

bitset<32>(n) -> converts the number n to its 32 bit representation.

Time complexity: O(1) but depends on the number of bits used to represent the number 
Space complexity: O(1)



2. Using a bit mask[Better]

We can do the same approach as shown in Approach (1) by using a bit mask as well

Time complexity: O(1)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

1. & n and n-1[Best]

Whenever you & n and n-1, the least significant bit is set to 0. Let's illustrate this with an 
example:

42 -> 0010 1010
41 -> 0010 1001
-----------------
42 & 41 -> 0010 1000

As you can see, whenever you set the & n and n-1, the least significant bit in 1 is changed to
obtain n-1. As a result, when you append the two numbers, the least significant bit will be set
to 0 in n.


Coming back to the approach, as long as there exists a least significant bit of 1 in the answer,
n & n-1 will keep returning a non 0 number. As a result, as long as bits are set to 1 in n,
we can keep doing n & n-1 as it will return a non-negative number by setting the least significant
bit to 0. When there are no other bits that are set to 1, we will obtain 0.


Time complexity: O(1) but depends on the number of bits
Space complexity: O(1)

*/


// My Approaches(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        string binaryRep = bitset<32>(n).to_string();
        for(int i = 0; i < binaryRep.size(); i++){
            if(binaryRep[i] == '1')
                count++;
        }
        return count;
    }
};



// My Approaches(2)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int count = 0;
        for(int i = 0; i < 32; i++){
            if((mask & n) != 0)
                ++count;
            mask = mask << 1;
        }
        return count;
    }
};


// Other Approaches(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int mask = 1;
        while(n != 0){
            count++;
            n &= n-1;
        }
        return count;
    }
};