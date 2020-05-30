/*
-------------------------Question:

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1
*/

/*
-------------------------My Approaches:

1. Using a double variable as a container

We can use a double value as a container to take care of the overflow condition.

Time complexity: O(log n)
Space complexity: O(1)

*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(double i = 1; i*i <= num; i++){
            if(i*i == num)
                return true;
        }
        return false;
    }
};