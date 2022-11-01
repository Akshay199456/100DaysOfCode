/*
Problem statement:

iven a number that is less than 10^5 determine the smallest amount of perfect squares needed to sum to a particular number? The same number can be used multiple times.

Examples
Example 1:
Input: 12
Output: 3
Explanation:
12 = 4 + 4 + 4

Example 2:
Input: 13
Output: 2
Explanation:
13 = 4 + 9
*/

/*
-------------------------    My Approaches:
1. brue force -> combinatorics approach

    we can use the brute force approach of generating all combinations in order to solve the probkem.
    the way we would do that is generating squares of each number and then checking if it crosses the sum or hits the sum.
    if it hits the sum, we record for mincount else if if it crosses the sum, we stop the recursion there. else we continue recursion

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits

void getMinCount(int n, int sum, int & minCount, int currCount, int minIndex){
    if(sum >= n){
        if(sum == n)
            minCount = std::min(minCount, currCount);
    }
    else{
        for(int i=minIndex; i <= n; i++){
            int squaredValue = i*i;
            getMinCount(n, sum + squaredValue, minCount, currCount+1, minIndex);
        }
    }
}

int perfect_squares(int n) {
    // WRITE YOUR BRILLIANT CODE HERE
    int minCount = std::numeric_limits<int>::max();
    if(!n)
        return 0;
    getMinCount(n, 0, minCount, 0, 1);
    return minCount;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int res = perfect_squares(n);
    std::cout << res << '\n';
}



//  Other Approaches(1)
