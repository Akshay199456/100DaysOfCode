/*
Problem statement:

very non-negative integer N has a binary representation, for example, 8 can be represented as “1000” in binary and 7 as “0111” in binary.

The complement of a binary representation is the number in binary that we get when we change every 1 to a 0 and every 0 to a 1. For example, the binary complement of “1010” is “0101”.

For a given positive number N in base-10, return the complement of its binary representation as a base-10 integer.

Example 1:

Input: 8
Output: 7
Explanation: 8 is 1000 in binary, its complement is 0111 in binary, which is 7 in base-10.
Example 2:

Input: 10
Output: 5
Explanation: 10 is 1010 in binary, its complement is 0101 in binary, which is 5 in base-10.
*/

/*
-------------------------    My Approaches:
1. Bit manipulation approach

    we used the bit manipulation approach to solve the problem. we use a mask of 1s here in order to obtain the boundar at which all 1s are available in the original number. once we obtain that boundary, we then exor the bitmask with the
    complement of the number. this will give ypou the result

    Time complexity: O(n) where n is the nth last bit set from the right
    Space complexity: O(1)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O(b) where b s the number of bits required to store the given number
    Space complexity: O(1)
*/


/*
-------------------------    Notes
the following properties of xor:
    1. it will return 1 if we take xor of two different bits i.e 1^0 = 0^1 = 1
    2. it will return 0 if we take xor of two same bits i.e 0^0 = 1^1 = 0. in other words, xor of two
    same numbers is 0.
    3. it returns the same number if we xor with 0.

from the above mentioned firt property, we can conclude that xor of a number with its complement
will resukt in an number that has all of its bit set to 1. for example, the binary complement of 101 is 010 and if
we take xor of these two numbers, we will get a number wil all bits set to 1, i.e 101 ^ 010 = 111

we can write this fact in the following operation:
number ^ complement = all_bits_set

lets add 'number' on both sides
number ^ number ^ complement = number ^ all_bits_set

from the above mentioned second property:
0^complement = number ^ all_bits_set

from the above mentioned third proerty:
complement = number ^ all_bits_set

can use this fact to find the complement of anyu number

how do we calculate all_bits_set? One way to calculate all_bits_set will be to first count the bits
required to store the given number. we can then use the fact that that for a number which is a compleet power of 2
i.e can be written as pow(2,n), if we subtract '1' from such a s number, we get a number which has 'n'
lease significant bits se to 1. for example, '4' which is a cmplement powerof '2', and '3' (which is one less than 4)
has a bonary representation of '11' i'e it has '2' least significant bits set to 1.
*/



//  My approaches(1)
#include <iostream>

using namespace std;

class CalculateComplement {
    public:
      static int bitwiseComplement(int n) {
        // TODO: Write your code here
        unsigned int bitmask = ~0;
        while(bitmask & n)
          bitmask <<=1;
        return bitmask ^ ~n;
    }
};

int main(int argc, char* argv[]) {
  // your code goes here
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(0) << endl;
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(10) << endl;
}


//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <math.h>

class CalculateComplement {
public:
  static int bitwiseComplement(int num) {
    // count number of total bits in 'num'
    int bitCount = 0;
    int n = num;
    while (n > 0) {
      bitCount++;
      n = n >> 1;
    }

    // for a number which is a complete power of '2' i.e., it can be written as pow(2, n), if we
    // subtract '1' from such a number, we get a number which has 'n' least significant bits set to
    // '1'. For example, '4' which is a complete power of '2', and '3' (which is one less than 4)
    // has a binary representation of '11' i.e., it has '2' least significant bits set to '1'
    int all_bits_set = pow(2, bitCount) - 1;

    // from the solution description: complement = number ^ all_bits_set
    return num ^ all_bits_set;
  }
};

int main(int argc, char *argv[]) {
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(8) << endl;
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(10) << endl;
}