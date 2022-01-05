/*
-------------------------Question:
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

/*
-------------------------My approaches

1. Using exor to get the difference in the number of bits set


We can use exor get the total number of bits that are different between the two numbers. Once we have
that, we can then get the total nulber of bits that are different between the two.


Time complexity: O(1) depends on the number of bits different
Space complexity: O(1)

*/

/*
-------------------------Other approaches

*/


// My Approaches (1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = x ^ y, count = 0;
        while(result != 0){
            count++;
            result &= result-1;
        }
        return count;
    }
};