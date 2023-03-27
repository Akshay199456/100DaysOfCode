/*
Problem statement:

Given an array of integers sorted in ascending order, find two numbers that add up to a given target. Return the indices of the two numbers in ascending order. You can assume elements in the array are unique and there is only one solution. Do this in O(n) time and with constant auxiliary space.

Input: [2 3 4 5 8 11 18], 8

Output: 1 3
*/

/*
-------------------------    My Approaches:
1. 

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
brute force

provided we understand the problem, first step is to find a solution is to solve it brute force.
since the problem asks for wo elemetns that sum to targt, we can simply try every pair of numbers and see if they sym to it. this would take O(n^2) time



using additional condition

to improve on the brute force solution, two natural questions to ask are "do we have to look ateach pair(can we skip any pairs)?" and "have we used all the conditions given by t eh 
problem statement?"
noticed that we are not using the condition that array is sosrted. this means the smallest two sum we can get is the sum of the first two numbers
2+3 and the largest two sum we ca n get is the sum of the last two numbers 11+18. if we sort all
two sum paris bby their sum value, the middle points is the smallest number + largest number 2+18. from this pointt, we can compare with our target 8.
    1. if our sum equals to targt, then we are done.
    2. if our sum is less than target, we need to exchange one of the numbers for a buigger number. since 18 is already the bigger number 
    availanb;e., we have to exachange 2 for a bigger number. we go to 3.
    if your sum if greater than the target, we need to exchange one of the numbers for a smaller number. since 2 is the 
    smallest number available, we have to exchange 18 for a smaller number, we go to 11.
    repeat the process until the sium is qual to our target



    Time complexity: O(n)
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

std::vector<int> two_sum_sorted(std::vector<int> arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int two_sum = arr[l] + arr[r];
        if (two_sum == target) {
            return {l, r};
        } else if (two_sum < target) {
            l++;
        } else {
            r--;
        }
    }
    return std::vector<int>();
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    std::vector<int> res = two_sum_sorted(arr, target);
    put_words(res);
}
