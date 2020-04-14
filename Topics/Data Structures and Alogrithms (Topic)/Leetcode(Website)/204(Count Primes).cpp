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
1. Using an array to store occurences of primes and non-primes

We can use an array to store the occurrences of both primes and non-primes. While we initialize
all values from 2 to the number itself to be true. For every true value, we record it as a 
prime and knock off every value that's based on that value till the number itslelf. This way
at the end when we reach the number, all the values that are primes will be left behind while every
other number will be eliminated

Time complexity: O(n log(log n))
Space complexity: O(n)


2. Checking till sqrt(n)[Slightly better in theory since we skip across more results. On paper 
both are equivalent.]


We can build upon the previous apporoach by only evaluating the numbers till their sqrt root since
every composite number has a proper factor less than or equal to its square root and we can use
that to eliminate the rest of the factors of the composite number.


The reason we make the check with the square root of the number is as follows:

For a given number n, if it's divisible by p, then n = p * q where p <=q. This means that we can
also derive p < sqrt(n) since sqrt(n) * sqrt(n) = n = p * q. Since we know that p<=q, this means
that for sqrt(n) * sqrt(n) = p * q to be valid, p must be <=sqrt(n) since q is greater than p.
As a result, we only need to check the results till sqrt(n) and check if there is any additional
factor and if so, that number can't be a prime since it has a factor other than 1 and the number
itself. 


In addition, in the inner loop, we don't have to start from the value of i. Instead, we can start
from i*i since every value below i*i would have already been covered by the other prime factors and
increment it by i till we reach n.

Time complexity: O(n log(log n))
Space complexity: O(n)
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


// Other approaches(1)
class Solution {
public:
    int getCountPrimes(int number){
        vector<bool> primeList(number, true);
        primeList[0] = primeList[1] = false;
        int nPrimes = 0;
        for(int i = 2; i < number; i++){
            if(primeList[i]){
                nPrimes++;
                for(int j = 2; i*j < number; j++)
                    primeList[i*j] = false;
            }
        }
        return nPrimes;
    }
    
    
    int countPrimes(int n) {
        if(n < 2)
            return 0;
        else{
            return getCountPrimes(n);
        }
    }
};


// Other Approaches(2)
class Solution {
public:
    int getCountPrimes(int number){
        vector<bool> primeList(number, true);
        primeList[0] = primeList[1] = false;
        int nPrimes = 0;
        for(int i = 2; i*i <= number; i++){
            if(primeList[i]){
                for(int j = i*i; j < number; j+=i)
                    primeList[j] = false;
            }
        }
        
        for(int j = 2; j < primeList.size(); j++){
            if(primeList[j])
                nPrimes++;
        }      
        return nPrimes;
    }
    
    
    int countPrimes(int n) {
        if(n < 2)
            return 0;
        else{
            return getCountPrimes(n);
        }
    }
};