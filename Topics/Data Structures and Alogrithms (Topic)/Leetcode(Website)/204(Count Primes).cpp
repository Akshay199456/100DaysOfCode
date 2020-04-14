/*
-------------------------Question:

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

/*
-------------------------My Approaches:
1. Finding if number is prime and counting number of primes [Worst]

To check if a number is prime, we check if we have more than 2 factors from 1 till the number.
If it does, it's not a prime. Else it is.

Since we do this for all numbers from 2 till the number given to us, this becomes an O(n^2)
algorithm.

Time complexity: O(n^2)
Space complexity: O(1)



2. Optimizing procedure for finding if number of prime [Better]

We can optimize the checking if a number is prime procedure by only checking till sqrt(n). If we
find some other factor as we go from 2 to sqrt(n), then we know it can't be prime since it has
an additional factor other from 1 and the number itself.


Time complexity: O(nlogn)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    bool checkPrime(int number){
        int nFactors = 0;
        for(int i = 1; i<= number; i++){
            if(number % i == 0)
                nFactors++;
            if(nFactors > 2)
        		return false;
        }
        return true;
    }
    
    int countPrimeNumbers(int n){
        int nPrimes = 0;
        for(int i = 2; i < n; i++){
            if(checkPrime(i))
                nPrimes++;
        }
        return nPrimes;
    }
    
    int countPrimes(int n) {
        if(n <= 1)
            return 0;
        else{
            return countPrimeNumbers(n);
        }
    }
};


// My Approaches(2)
class Solution {
public:
    bool checkPrime(int number){
        int nFactors = 0;
        for(int i = 2; i<= sqrt(number); i++){
            if(number % i == 0)
                return false;
        }
        return true;
    }
    
    int countPrimeNumbers(int n){
        int nPrimes = 0;
        for(int i = 2; i < n; i++){
            if(checkPrime(i))
                nPrimes++;
        }
        return nPrimes;
    }
    
    int countPrimes(int n) {
        if(n <= 1)
            return 0;
        else{
            return countPrimeNumbers(n);
        }
    }
};