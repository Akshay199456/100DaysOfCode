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


2. Dp with two pointer solution - bottom up

    I think this solution works because for every position in the table, we are calculating the minimum no of perfect sequares required to reach
    a number. so if we are to build upon that step by step, we will get the smallest no of perfect sequares required to reach the solution itself.
    also, when we do for example: MC where Mc is for minimum count for a number
        so , when we do for 5, it can be generated in a few ways
            MC(5)   = MC(1) + MC(4)
                    = MC(2) + MC(3)
    rememeber, each MC of existing numbers already has the minimum nno of steps required to reach that number.
    so if we are to break down the sum into smaller components, those smaller componeents will have the minimum steps itself to reach that number.
    as a result, the solution you are building it on will also have the smallest set of numbers since any other combination will be covered by it if it is the
    solution with minimum count

    we do need to check if a number ios a perfect square cause if it is, its MC count gets set to 1.

    for our approach, we went directly to bottom-up approach. but, instead of the direct additions, we could also make use of recursion to fill the two 
    pointer approach and that would give us top-down.

    Again, the reason this approach works is because each number can be based on previous numbers
    that come before it, whether they are perfect sequares or not. if they are perfect sequares, then the no of steps is 1.
    else if the number is not a perfect sequare, it is going to be based on another pperfect sequare and as a result, the result for it would be greater than 1.
    we use the two pointer approahc to go through all possible combinaions that can arise for everynumber

    Time complexity:: O(n^2)
    Space complexity: O(n)

*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
1. Approache 1 - DP

    Answer is to use dynamic programming either bottom-up or top-down and to maintain the least number of numbers to 
    get a certain sum. alternatively, you can use a graphy theory algorithm such as bfs to solve this question as well as a queue.
    the solution displayed uses a bottom-up DP approach, the other solutions may serve as good practice for practicing other 
    algorithms.

    Time complexity: O(n*sqrt(n))
    Space complexity: O()

Additional notes:

    comparing my dp approach against the approach used by them acheives the same results just in slightly different ways.
    what i do for each index is check with all other subsequecens when we make a decision for a particular index.
    what they do is start from a perfect number and check how many steps it would take from that perfect number
    to the number n. they then move on tot he next perfect number and continue the same from there. at the end both of these acheive the same results.
    look at the images for this approach to understand how they do.


Additional notes(1):
    Link to video to get a better understanding of the technqiue: https://www.youtube.com/watch?v=HLZLwjzIVGo&ab_channel=NeetCode
    Helps you understand the technique behind the dp approach. highly recommended to watch the video to understand
    the brute force approach and how you would approach this problem in a brute force approach therby leading you
    to view the problem from top-down or bottom-up approach.

    as you can see in the other approaches(2)-2, the first for loop only goes until i*i <=n. this is because when 
    i*i > n, we cant use any numbers in order to get the sum sicne it crosses the number we are trying to hit.
    as a result, that bounds the outer for loop to sqrt(n). 
    in the inner section of that loop, we assign cur to i*i. i will go over why we do thi soon.
    the inner for loop goes from the j = cur till j <= n. the inner for loop is basically usuing the squares 
    starting from 1^2. so te first time we run th einner for loop, it is basically saying, how many 1^2 will
    allow us to hit the answer we are looking for. when the inner loop runs again, it then asks the question,
    how many 2^2 allows us to hit the answer we are looking for.
    the cindition dp[j] = std::min(dp[j], dp[j-cur] +1) is sued to get e least no of squares possible.
    we do j-cur so that we are building on the answer at dp[j-cur] byu adding one additional square to it
    (which is for our current cur). that's why we increment y 1 that value.


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


// My Approaches(2)
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits
#include <vector>
#include <math.h>

bool isPerfectSquare(int n){
    if(ceil((double)std::sqrt(n)) == floor((double)std::sqrt(n)))
        return true;
    return false;
}

int perfect_squares(int n) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<int> dp(n+1,0);
    int minCount = std::numeric_limits<int>::max();
    
    for(int i=1; i<=n; i++){
        if(isPerfectSquare(i))
            dp[i] = 1;
        else{
            int beg = 1, end = i-1;
            int minValue = std::numeric_limits<int>::max();
            while(beg <= end)
                minValue = std::min(minValue, dp[beg++] + dp[end--]);
            dp[i] = minValue;
        }
    }
    
    return dp[n];
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
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits

int perfect_squares(int n) {
    int dp[n + 1];
    std::fill(dp, dp + n + 1, std::numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 1; i * i <= n; i++) {
        int cur = i * i;
        for (int j = cur; j <= n; j++) {
            dp[j] = std::min(dp[j], dp[j - cur] + 1);
        }
    }
    return dp[n];
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


