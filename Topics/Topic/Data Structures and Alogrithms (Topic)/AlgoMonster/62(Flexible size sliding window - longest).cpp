/*
Problem statement:

Recall finding the largest size k subarray sum of an integer array in Largest Subarray Sum. What if we dont need the largest sum among all subarrays of fixed size k, but instead, we want to find the length of the longest subarray with sum smaller than or equal to a target?

Given input nums = [1, 6, 3, 1, 2, 4, 5] and target = 10, then the longest subarray that does not exceed 10 is [3, 1, 2, 4], so the output is 4 (length of [3, 1, 2, 4]).
*/

/*
-------------------------    My Approaches:
1. Sliding window - varying size

    For this problem, we need to use the sliding window approach. as long as the sum is smaller than target, we can keep expanding 
    the window by moving the end pointer tot he right. once the condition is not satisfied, we move the beg
    pointer to th eleft till the condition is not satisifed. we continue this till we reach the end of hte
    array.

    Time complexity: O(n)
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
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int subarray_sum_longest(std::vector<int> nums, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    int beg = 0, end = 0, currSum = 0, maxLength = 0;
    
    while(end < nums.size()){
        if(currSum + nums[end] <= target)
            currSum += nums[end++];    
        else{
            maxLength = std::max(maxLength, end-beg);
            currSum -= nums[beg++];
        }   
    }
    return std::max(maxLength, end-beg);
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> nums = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = subarray_sum_longest(nums, target);
    std::cout << res << '\n';
}



//  Other Approaches(1)
