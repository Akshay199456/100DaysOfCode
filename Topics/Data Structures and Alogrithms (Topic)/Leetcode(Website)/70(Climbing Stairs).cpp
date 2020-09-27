/*
-------------------------Question:

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

/*
-------------------------My Approaches:
1. Same as Other Approaches(2)

We used the top-down dynamic programming approach for this problem with memoization to store the results.

Time complexity: O(n)
Space complexity: O(n)


2. Bottom-up dynamic programming

Since we know that the base conditions for this problem in n[0] = n[1] = 1{There is only one way to get to 0 and that is to
start from 0 itself, there is only one way to get to 1 and that is to go from 0 to 1 in +1 step}, we can base the rest of
the result based on this base cases.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------Other approaches

1. Recursive Brute Force approach

The key to this approach is to understand how to get to a higher level given the level you start at.
For example, if you are trying to find the number of steps it takes to get to 5 starting from 4,
you have 1 of 2 choices that you can choose to get there. You can either move from 4 to 5 by climbing
1 step or move from 4 to 6 by climbing 2 steps. Thus, at every level, you have one of 2 choices to
move from the current level to the next level. This aproach starts from the level 0 to the level we
want to get to. Since the upper level is formed by the levels before it, the total number of the 
steps to get to the current level is the total number of steps to get to the current level from 
level-1 and the toal number of steps to get to the current level from level-2 as those are the only
2 options available to the user.

A representation of the tree is given in the 'Helping Images' folder.


Time complexity: O(2^n) since we have 2^n nodes in the tree.
Space complexity: O(n) [depth of the tree]




2. Recursive approach with memoization[Better]

We can improve upon the previous approach since it contains many repetitions. Once we calcualte the 
For example, once we calcuate the total number of steps it takes to go from 3 to 5, we don't need to
repeat it for the other levels whenever we come across the same instance. As a result, we can use
an array to store the number of steps. This way if we come across a value in the array that has 
already occurred, we return that number itself instead of performing the calculation for that
value. This is called memoization and helps us in this case to prune the tree.


Time complexity: O(n)
Space complexity: O(n)



3. Dynamic Programming[Better]

This problem matches the definition of dynamic programming

1. It can be broken into sub-problems.
2. It contains the optimal substructure property i.e. optimal solution to the problem can be
constructed efficiently from the optimal solutions to the sub-problems.

One can reach ith step in one of the two ways:

1. Taking a single step from (i-1)th step.
2. Taking a step of 2 from (i-2)th step.

So, the total number of ways to reach ith step is equal to sum of ways of reaching (i-1)th
step and ways of reaching (i-2)th step.

Let dp[i] denotes the number of ways to reach on ith step:

dp[i]=dp[i-1]+dp[i-2]

Time complexity: O(n)
Space complexity: O(n)



4. Fibonacci series

We can improve the Other Approaches(3) by understanding that this problem is basically a form
of fibonacci series and hence its solution can be represented by the solution of a fibonacci
problem. As a result, we can minimize on the space utilized this way

Time complexity: O(n)
Space complexity: O(1) 


5,6. Binets method, Fibonacci formula

These remaining 2 approaches only apply to the fibonacci series in particular. In case the 
finbonacci series ever becomes a bottle neck and you want to reduce it's runtime, you can
use any one of these 2 approaches to improve the efficiency and continue with the rest of the
problem.

[Check 'Helping Images' for more info on the 2 approaches]

Time complexity: O(log n) pow takes log n time
Space complexity: O(1)
*/


// My approaches(1)
class Solution {
public:
    vector<int> dpList;
    
    void initializeDp(int n){
        for(int i = 0; i <=n; i++)
            dpList.push_back(-1);
    }
    
    int getResult(int n){
        if(n <= 1)
            return 1;
        else if(dpList[n] != -1)
            return dpList[n];
        else{
            dpList[n] = getResult(n-1) + getResult(n-2);
            return dpList[n];
        }
    }
    
    int climbStairs(int n) {
        initializeDp(n);
        return getResult(n);
    }
};


// My Approaches(2)
class Solution {
public:
    vector<int> dpList;
    
    void initializeDp(int n){
        for(int i = 0; i <=n; i++)
            dpList.push_back(-1);
        dpList[0] = dpList[1] = 1;
    }
    
    int getResult(int n){
        if(n <= 1)
            return dpList[1];
        for(int i = 2; i <= n; i++)
            dpList[i] = dpList[i-1] + dpList[i-2];
        return dpList[n];
    }
    
    int climbStairs(int n) {
        initializeDp(n);
        return getResult(n);
    }
};


// Other Approaches(1)
class Solution {
public:
    int climbStairsSteps(int beg, int end){
        if(beg > end)
            return 0;
        else if(beg == end)
            return 1;
        else
            return climbStairsSteps(beg+1, end) + climbStairsSteps(beg+2, end);
    }
    
    int climbStairs(int n) {
        return climbStairsSteps(0, n);
    }
};


// Other Approaches(2)
class Solution {
public:
    int climbStairsSteps(int beg, int end, vector<int> & memo){
        if(beg > end)
            return 0;
        else if(beg == end)
            return 1;
        else if(memo[beg] != -1)
            return memo[beg];
        else{
            memo[beg] = climbStairsSteps(beg+1, end, memo) + climbStairsSteps(beg+2, end, memo);
            return memo[beg];
        }
    }
    
    int climbStairs(int n) {
        vector<int> memo(n, -1);
        return climbStairsSteps(0, n, memo);
    }
};



// Other Approaches(3)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1);
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2; i <= n; i++){
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
};



// Other Approaches(4)
class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 1;
        if(n == 0)
            return 0;
        else if(n==1)
            return first;
        else{
            int result;
            for(int i = 2; i <= n; i++){
                result = first  + second;
                first = second;
                second = result;
            }
            return result;
        }
    }
};



// Other Approaches(5)
class Solution {
public:
    int climbStairs(int n) {
        if( n == 0)
            return 0;
        else{
            int total = (1/sqrt(5)) * (pow((1+ sqrt(5))/2, n+1) - pow((1 - sqrt(5))/2, n+1));
            return total;
        }   
    }
};