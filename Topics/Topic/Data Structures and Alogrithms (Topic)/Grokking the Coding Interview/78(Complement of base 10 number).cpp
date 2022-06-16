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

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes

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
