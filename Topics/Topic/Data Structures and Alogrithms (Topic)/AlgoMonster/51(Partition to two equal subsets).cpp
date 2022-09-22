/*
Problem statement:

Input
nums: the array
Output
if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal

Examples
Example 1:
Input:

nums = [3, 4, 7]
Output: true

Explanation:

The array can be partitioned as [3,4] and [7].

Example 2:
Input:

nums = [1, 5, 11, 5]
Output: true

Explanation:

The array can be partitioned as [1, 5, 5] and [11].


*/

/*
-------------------------    My Approaches:
1. brute force - combinatorics

    since this problem asks if we can soplit the elements into two subsets, well then that's what we have got to do. in order to do that, this problem then becomes part of the 
    combinatorics problem where we have to generate all possible combinations. and that is exactly what we do.
    at every new element, you have one of two chocies, either add it to set a or add it to set b. When we have finally
    added the last element, we can then comapre the sums to make srue they are equal and if they are return true. else return false.

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
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

bool dfs(std::vector<int> & nums, int sumA, int sumB, int index){
    if(index == nums.size()){
        if(sumA == sumB)
            return true;
        return false;
    }
    return dfs(nums, sumA + nums[index], sumB, index+1) || dfs(nums, sumA, sumB + nums[index], index+1);
}

bool can_partition(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    return dfs(nums, 0, 0, 0);
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
    bool res = can_partition(nums);
    std::cout << std::boolalpha << res << '\n';
}



//  Other Approaches(1)
