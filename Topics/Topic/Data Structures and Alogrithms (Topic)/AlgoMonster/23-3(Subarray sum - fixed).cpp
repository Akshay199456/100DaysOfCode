/*
Problem statement:

iven an array (list) nums consisted of only non-negative integers, find the largest sum among all subarrays of length k in nums.

For example, if the input is nums = [1, 2, 3, 7, 4, 1], k = 3, then the output would be 14 as the largest length 3 subarray sum is given by [3, 7, 4] which sums to 14.
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
solution
    the systematic approach is to check the sum of each subarray with size k and find hte largest one. we start from the leftmost window of size k in the arraay and we can keep track of a window_sum variable that stores the sum of the
    current window. when we shift the window to the right, we add a new element to the right of the window and remove the leftmost element from the window. to obtain the window_sum of the new window,
    we can add the value of  the new element and suubtract thelue we removed on the elft. then, for each windowm we wush to
    check whether the window_sum is at least largest where largest is the current largest sum among all processed windows.


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int subarray_sum_fixed(std::vector<int> nums, int k) {
    int window_sum = 0;
    for (int i = 0; i < k; ++i) {
      window_sum = window_sum + nums[i];
    }
    int largest = window_sum;
    for (int right = k; right < nums.size(); ++right) {
        int left = right - k;
        window_sum = window_sum - nums[left];
        window_sum = window_sum + nums[right];
        largest = std::max(largest, window_sum);
    
    }
    return largest;
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