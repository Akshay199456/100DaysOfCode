/*
Problem statement:

Input
nums: the integer sequence
Output
the length of longest subsequence

Examples
Example 1:
Input:

nums = [50, 3, 10, 7, 40, 80]
Output: 4

Explanation:

The longest subsequence is [3, 7, 40, 80] which has length 4.

Example 2:
Input:

nums = [1, 2, 4, 3]
Output: 3

Explanation:

Both [1, 2, 4] and [1, 2, 3] are longest subsequences which have length 3.
*/

/*
-------------------------    My Approaches:
1. combinatorics + dfs

    we generate the state-space tree using combinatorics. at each stage, we have 1 of 2 possible steps we can do.
    1) we can either not add the element at the current index and move the index forward
    2) we can add the element at the current index
        - the ability to add the element at the current index will depend if the element at the current idnex exceeds the last element that we had added.
        if it does not exceeed, then it doesnt contrinbute to an increasing subsequence and as a result, there is no point adding that element. if it does exceed,
        then we can add that element, increase the index by 1 and currLength by 1 and move forward with the recursive call structure

    Time complexity: O(2^n) where n is the size of the array
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


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <limits>

void getLongestLength(std::vector<int> & nums, int lastElement, int currLength, int & maxLength, int index){
    if(index == nums.size()){
        maxLength = std::max(currLength, maxLength);
        return;
    }
    
    // choose to not add element
    getLongestLength(nums, lastElement, currLength, maxLength, index+1);
    // choose to add element
    if(nums[index] > lastElement)
        getLongestLength(nums, nums[index], currLength+1, maxLength, index+1);
}


int longest_sub_len(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    int maxLength = 0;
    if(!nums.size())
        return 0;
    getLongestLength(nums, std::numeric_limits<int>::min(), 0, maxLength,0);
    return maxLength;
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

int main() {
    std::vector<int> nums = get_words<int>();
    int res = longest_sub_len(nums);
    std::cout << res << '\n';
}



//  Other Approaches(1)
