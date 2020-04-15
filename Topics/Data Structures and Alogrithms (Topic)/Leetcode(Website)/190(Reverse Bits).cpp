/*
-------------------------Question:

Reverse bits of a given 32 bits unsigned integer.

 

Example 1:

Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:

Input: 11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 

Note:

Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 

Follow up:

If this function is called many times, how would you optimize it?


*/

/*
-------------------------My Approaches:

1. Reversing bits the normal way

We use a bool variable to store the bits and then interchange the bits the normal way like we would
reverse a string.

Time complexity: O(n) where n is the total number of bits of the number
Space complexity: O(n)
*/

/*
-------------------------Other approaches


1. Reversing bits in groups


This approach has been summarized well in the 'Helping Images' folder with respect to this 
problem so please check that out to get a good idea of how this algorithm works.

To summarize this approach, we divide the bits into 2 groups. We select the first groups of bits by 
using a bit mask and then shift them right. We then select the second group of bits by using another
bit mask and shift the result left. We then append the first and second group of bits. We continue
this till we have reached a single bit and then return the result. 
*/


// My approaches(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bitRep(n);
        int beg = 0, end = bitRep.size() - 1;
        while(beg < end){
            bool temp = bitRep[beg];
            bitRep[beg++] = bitRep[end];
            bitRep[end--] = temp;
        }
        return (uint32_t) (bitRep.to_ulong());
    }
};



// Other Approaches(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = n >> 16 | n << 16;
        n = ((n & 0xff00ff00) >> 8) |((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) |((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) |((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) |((n & 0x55555555) << 1);
        return n;
    }
};