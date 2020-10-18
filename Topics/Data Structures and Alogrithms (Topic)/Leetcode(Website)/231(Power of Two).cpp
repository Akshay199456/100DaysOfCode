/*
-------------------------Question:
Given an integer n, write a function to determine if it is a power of two.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
Example 4:

Input: n = 4
Output: true
Example 5:

Input: n = 5
Output: false
 

Constraints:

-231 <= n <= 231 - 1
*/

/*
-------------------------    My Approaches:
1. Dividing number by 2 at eachs tep.

We start from the number and move back. At the end, if it is a power of two, we should end up at 1. else we return false

Time complexity: O(log n)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        else{
            while(n > 1){
                if(n%2 != 0)
                    return false;
                n /= 2;
            }
            return true;
        }
    }
};