/*
Problem statement:

Given an integer, find its square root without using the built-in square root function. Only return the integer part (truncate the decimals).

Input: 16

Output: 4

Input: 8

Output: 2

Explanation: square root of 8 is 2.83..., return integer part 2
*/

/*
-------------------------    My Approaches:
1. Binary Search

    we can apply  the binary search technique ehre as well. at each step we check if mid*mid is less than or equal to the target.
    if it is , then we record it and move beg = mid+1;

    Time complexity: O(logn)
    Space complexity: O(1)
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

int square_root(int n) {
    // WRITE YOUR BRILLIANT CODE HERE
    int beg{0}, end{n}, index{0};
    while(beg <= end){
        int mid = beg + (end-beg)/2;
        int squaredValue{mid*mid}; 
        if(squaredValue <= n){
            index = mid;
            beg = mid+1;
        }
        else
            end = mid-1;
    }
    return index;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int res = square_root(n);
    std::cout << res << '\n';
}



//  Other Approaches(1)
include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits

int square_root(int n) {
    int left = 0, right = n, res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid <= n / mid) {
            left = mid + 1;
            res = mid;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int res = square_root(n);
    std::cout << res << '\n';
}
