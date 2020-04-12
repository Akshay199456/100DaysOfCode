/*
-------------------------Question:

Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?
*/

/*
-------------------------My Approaches:

1. Mathematical log operation

We can use log10 to check if a value is a power of 3. Be wary here that you can't use natural logarithm
and the corresponding Math functino log() since it generates a round off error for 243.

Time compleity: Unknown since operation of log depends on the compiler and language we are using.
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/

// My Apporaches(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n <= 0)
            return false;
        else{
            double value = log10(n) / log10(3);
            if(value == floor(value))
                return true;
            return false;
        }
    }
};