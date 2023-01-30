/*
Problem statement:

Let's continue on finding the sum of subarrays. This time given a positive integer array nums, we want to find the length of the shortest subarray such that the subarray sum is at least target. Recall the same example with input nums = [1, 4, 1, 7, 3, 0, 2, 5] and target = 10, then the smallest window with the sum >= 10 is [7, 3] with length 2. So the output is 2.
*/

/*
-------------------------    My Approaches:
1. Sliding window - varying size


    we can solve this problem with slidign window of verying size just like pb 62. the only idfference here is that we want t
    'gind a window that is o he samllest size that satisfies the condition. as a result, as long as currSum + nums[end] satieisfies the condition, 
    we keep eanding the window. when it satisfies the conditoion, there is no point expanding it after since any other window after that will only be larger.
    so, we push beg forward and get the minlength set.

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
a brute force is to use largest_sum_subarray_k as a subroutine to check whether there exists a subarray of each possiblle length k with sum larger
than target adnd find the smallest k. but that woul be too slow. so we will alter the longest sliding window approach
to now search for the shortest subarray. only this time, our goal is to shrink the window, we we will check whether a window is valid
anmds shrink the valid iwndows to find th smalelst one.

we want to find the shortest subarray that sumps up to at least target. if the sum of the current window is less than target, we must extend the window so that 
we can increase the window_sum. if window_sum >= target, we want to shrink the window from the left side so that we could explore a smaller window that potentially
adds up to target.

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

int subarray_sum_shortest(std::vector<int> nums, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    int beg = 0, end = 0, currSum = 0, minLength = std::numeric_limits<int>::max();
    if(!nums.size())
        return 0;
    
    while(end < nums.size()){
        if(currSum + nums[end] < target)
            currSum += nums[end++];
        else{
            minLength = std::min(minLength, end-beg+1);
            currSum -= nums[beg++];
        }
    }
    
    if(!beg && end == nums.size())
        return nums.size();
    else if(currSum >= target)
        minLength = std::min(minLength, end-beg+1);
    
    return minLength;
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
    int res = subarray_sum_shortest(nums, target);
    std::cout << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int subarray_sum_shortest(std::vector<int> nums, int target) {
    int windowSum = 0, length = nums.size();
    int left = 0;
    for (int right = 0; right < nums.size(); ++right) {
        windowSum = windowSum + nums[right];
        while (windowSum >= target) {
            length = std::min(length, right-left+1);
            windowSum = windowSum - nums[left];
            ++left;
        }
    }
    return length;
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
    int res = subarray_sum_shortest(nums, target);
    std::cout << res << '\n';
}
