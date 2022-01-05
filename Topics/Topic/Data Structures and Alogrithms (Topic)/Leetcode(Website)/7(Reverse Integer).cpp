/*
-------------------------Question:

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

/*
-------------------------    My Approaches:

The way I approached this solution was to use a long long int to handle the calculations part. This
way we can easily check if an overflow has occurred and return 0 if so. Most likely this solution
is not allowed since the question mentions that the solution must exist in an environement where
we can only store integers within the 32 bit range.

Time complexity : O(log n) where n is the number of digits
Space complexity : O(1)
*/

/*
-------------------------    Other approaches:

1. (Same but valid)

In this approach, we make a check if the current reverse number is >= INT_MAX/10. This helps us
deal with the overflow issue. If it is > , then we are sure that multiplying reverse number by 10
wil cause an overflow, so we return a 0. If it is =, then the answer depends on the popped element.
If the popped element is > 7, we return a 0 as well, since overflow would occur after the new
reverse calculation. This way we can use an int variable and check for overflow.

If neither of those conditions are met, we know what adding the newly popped element and 
multiplying it by 10 will not cause an overflow and can hence proceed. Of particular interest, 
is the case when num == INT_MIN. In this case we return 0, since abs(num) would cause overflow.
Also, reversing an INT_MIN number would cause overflow and hence we can return 0. 

We take the abs of the value and pass it to getReverse so that we can work with one algorithm
irrespective of whether the number is positive or negative.
*/

// My appraches(1)
class Solution {
public:
    static int const MAX_INT = 2147483647;
    static int const MIN_INT = -2147483648;
    int findLength(int number){
        int length = 0;
        if(!number)
            return 1;
        while(number > 0){
            number /= 10;
            length += 1;
        }
        return length;
    }
    
    int checkNegative(int x){
        if(abs(x) == x)
            return 1;
        else
            return -1;
    }
    
    int calculateReverse(int number, int length, int isNegative){
        long long int reversedNumber = 0;
        for(int i = 0; i < length; i++){
            int rem = number % 10;
            reversedNumber += (rem * pow(10, length - i - 1));
            number /= 10;
        }
        
        reversedNumber *= isNegative; 
        cout<<"Reversed Number: "<<reversedNumber;
        if(reversedNumber <= MAX_INT && reversedNumber >= MIN_INT)
            return reversedNumber;
        else
            return 0;
        
    }
    
    
    int reverse(int x) {
        if(x == MAX_INT || x == MIN_INT)
            return 0;
        else{
            int length = findLength(abs(x));
            int isNegative = checkNegative(x);
            return calculateReverse(abs(x), length, isNegative);
        }
    }
};


// Other approaches(1)

class Solution {
public:
    
    int checkNegative(int number){
        if(abs(number) == number)
            return 1;
        else 
            return -1;
    }
    
    int getReverse(int number, int isNegative){
        int reverse = 0;
        while(number > 0){
            int poppedElement = number % 10;
            number /= 10;
            
            if((reverse > (INT_MAX / 10)) || ((reverse == (INT_MAX/10)) && (poppedElement > 7)))
                return 0;
            reverse = reverse * 10 + poppedElement;
            
        }
        return reverse * isNegative;
    }
    
    int reverse(int x) {
        if(x == INT_MIN)
            return 0;
        else{
            int isNegative = checkNegative(x);
            return getReverse(abs(x), isNegative);
        }    
    }
};