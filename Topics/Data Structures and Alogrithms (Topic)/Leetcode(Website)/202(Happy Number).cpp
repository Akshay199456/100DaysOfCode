/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

/*
-------------------------My Approaches:

1. Brute-Force solution[Worst]

This approach uses a brute force solution to solve the problem where we check the sum of squares
for each of the intermediate numbers and whenever it hits 1 we return true. Else if we git a
duplicate that's stored in the map, we return false.

Time complexity: O(n) where n is the total number of elements that are not in the loop and those
that are in the loop
Space complexity: O(n) where n is the total number of elements that are not in the loop and those
that are in the loop
*/

/*
-------------------------Other approaches

1. Using floyd's cycle detection algorithm[Best]

This approach uses Floyd's cycle detection algorithm beautifully to detect the cycle in the problem.
While this is not a linked list problem, we can use that approach here to make this algorithm run
faster. 

We have 2 variables, slow and fast, as in Floyd's detection algorithm. The fast moves at a rate
2* faster than slow. The exit condition is when 'fast' hits 1. When it does, we know that we have
encountered 1 which means slow will encounter it as well later on even though fast and slow are on
different elements. This means that fast will keep having the value 1 till slow reaches that point
since 1^2 = 1. That's why, when we encounter 1 with 'fast', we know that it's a happy number and
return true.

If there is a cyle, slow and fast will meet in value at one point or another since fast moves at 
a faster rate than slow and both fast and slow are in the cycle. Thus, when they meet, we know that 
a cycle exists and therefore, we return fast

Time complexity: O(n) where n is the total number of elements that are not in the loop and those
that are in the loop

Space complexity: O(1) 
*/


// My Solution(1)
class Solution {
public:
    int sumOfSquares(int n){
        int total = 0;
        while(n > 0){
            total+= pow(n % 10,2);
            n = n/10;        
        }
        return total;
    }
    
    bool isHappy(int n) {
        unordered_set<int> encountered;
        bool end = false;
        while(!end){
            int squareSum = sumOfSquares(n);
            if(!encountered.empty()){
                if(squareSum == 1)
                    return true;
                else if(encountered.find(squareSum) != encountered.end())
                    return false;
            }      
            encountered.emplace(squareSum);
            n = squareSum;
        }
        return end;
    }
};


// Other Approaches(1)
class Solution {
public:
    int sumOfSquares(int n){
        int total = 0;
        while(n){
            total += pow(n%10,2) ;
            n = n / 10;
        }
        return total;
    }
    
    
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do{
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
            if(fast == 1)
                return true;
        }while(slow!=fast); 
        
        return false;
    }
};