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

1. Using loops[Same]

We can check a number is a factor of 3 by continuosly dividing it by 3. If it's a factor, at the 
end, we should be left with 1. Else, we will have other factors and as a result, we won't be left
wuth 1.

Time complexity: O(log 3 n)
Space complexity: O(1)


2. Base conversion[Worse]

When we convert a number to its base, if it's a number that is a power of the base that we have
considered, we will have a single 1 followed by a series of 0's. 

eg:

10 base 10 = 10
100 base 10 = 100
1000 base 10 = 1000

2 base 2 = 10
4 base 2 = 100
8 base 2 = 1000


3 base 3 = 10
9 base 3 = 100
27 base 3 = 1000

So, if we have a number that's a power of 3, it's going to be of the format shown above. We can
make this check by considering the first bit and oring(|) the rest of the best to check for remaining
1s.


Time complexity: O(log 3 n)

Base conversion is usually by repeated division. Hence it's time complexity is O(log 3 N)

Space complexity: O(log 3 N)

Store it a sa string of log 3 N size.




3. Max numer[Best]

Approach 4: Integer Limitations
An important piece of information can be deduced from the function signature


In particular, n is of type int. In Java, this means it is a 4 byte, signed integer [ref]. 
The maximum value of this data type is 2147483647. 
 
​
Since we know the max value of this data type, we can also deduce the max value that is a power
of 3.

3 ^⌊log 3 MaxInt⌋ = 3 ^⌊19.56⌋= 3 ^ 19 =1162261467

Therefore, the possible values that are a factor of 3 are going to be of the form 3^[0,1,2,3,4...19].
When 1162261467 is divided by any of this numbers, we will always get an integer with a remainder
of 0. As a result, that's the check we are going for.


Time complexity: O(1)
Space complexity: O(1)
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


// Other Approaches(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n <= 0)
            return false;
        
        while( n % 3 == 0){
            n /= 3;
        }
        
        return n == 1;
    }
};



// Other Approaches(3)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        else
            return (1162261467 % n == 0);   
    }
};