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


2. Dividing num by integer rather than mutipying integer with itself to get num

Since we know that i*i = num for a perfect square, we can use that info for the check status instead
to prevent overflow by i <= (num/i) and then check inside if we hit the value and return true if we do.

Time complexity: O(log n)
Space complexity: O(!)

*/

/*
-------------------------Other approaches

1. Property of perfect square numbers

One of the property of perfect square numbers is that they are composed from the sum of odd numbers
Eg:
1 = 1
4 = 1 + 3
9 = 1 + 3 + 5
16 = 1 + 3 + 5 + 7
....

We can use this property to test if a number is a perfect square

Time complexity: O(sqrt n)
Space complexity: O(1)


2. Binary Search

Another interesting approach that you can use to solve this problem is to use binary search. This way
any vlaue that would have casued an overflow can be weeded out inside the binary search as we move
towards the middle. Since the list of numbers is a sorted list, this approach can be used to find the 
number we are looking for. If mid^2 == num, we return true, else we adjust beg and end accordingly to
keep moving towards the square of the number.

Time complexity: O(log n)
Space complexity: O(1)

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


// My Approaches(2)
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i = 1; i <= num / i; i++){
            if(i == (num / (double)i))
                return true;
        }
        return false;
    }
};


// Other Approaches(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        int valueCheck = 1;
        while(num > 0){
            num-= valueCheck;
            valueCheck+=2;
            if(!num)
                return true;
        }
        return false;
    }
};


// Other Approaches(2)
class Solution {
public:
    bool isPerfectSquare(int num) {
        long beg = 0, end = num, mid = 0;
        while(beg <= end){
            mid = beg + (end - beg) / 2;
            if( mid * mid == num)
                return true;
            else if(mid * mid > num)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return false;
    }
};