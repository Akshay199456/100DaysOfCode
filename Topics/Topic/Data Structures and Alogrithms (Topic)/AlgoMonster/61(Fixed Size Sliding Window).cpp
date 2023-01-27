/*
Problem statement:

Given an array (list) nums consisted of only non-negative integers, find the largest sum among all subarrays of length k in nums.

For example, if the input is nums = [1, 2, 3, 7, 4, 1], k = 3, then the output would be 14 as the largest length 3 subarray sum is given by [3, 7, 4] which sums to 14.
*/

/*
-------------------------    My Approaches:
1. Sliding window - fixed size

    We can use a sliding window of fixed size to solve this problem. since we are trying to find the largest sum
    aomonn g all subarrays of length k, we can have a sliding window of size k and calcualte the suma s we are going along and update
    the maxSum as we ar emoving along

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

int getLargestSum(std::vector<int> & nums, int k){
    int beg = 0, end = 0, currSum = 0, maxSum = 0;
    while(end < nums.size()){
        if(end - beg == k-1){
            currSum += nums[end];
            maxSum = std::max(maxSum, currSum);
            currSum -= nums[beg];
            beg++;
        }
        else
            currSum += nums[end];
        ++end;
    }
    return maxSum;
}

int subarray_sum_fixed(std::vector<int> nums, int k) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(!k || k>nums.size())
        return 0;
    return getLargestSum(nums, k);
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
    int k;
    std::cin >> k;
    ignore_line();
    int res = subarray_sum_fixed(nums, k);
    std::cout << res << '\n';
}



//  Other Approaches(1)
