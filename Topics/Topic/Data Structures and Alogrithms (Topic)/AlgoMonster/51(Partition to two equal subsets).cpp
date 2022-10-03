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

2. DP - top-down approach

    we can improve upon the previous approach by pruing off branches that are repeated as well as those that have repeated
    branches. we use a set to store the state of th esums that we enter. if we come across it, then we know that we dont have a valid solution so we return false.
    else we move down to the next branch after making modifications to the current sum branches.
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



//  My approaches(2)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_set>
#include <utility>

// Hash function 
struct hashFunction
{
  size_t operator()(const std::pair<int,int> &x) const
  {
    return x.first ^ x.second;
  }
};

bool dfs(std::vector<int> & nums, int sumA, int sumB, int index, std::unordered_set<std::pair<int,int>, hashFunction> & visited){
    if(index == nums.size()){
        if(sumA == sumB)
            return true;
        return false;
    }
    else if(!nums[index])
        return dfs(nums, sumA + nums[index], sumB, index+1, visited) || dfs(nums, sumA, sumB + nums[index], index+1, visited);
    
    std::pair<int,int> firstPair = std::make_pair(sumA, sumB);
    std::pair<int,int> secondPair = std::make_pair(sumB, sumA);
    if(((visited.find(firstPair) != visited.end()) || (visited.find(secondPair) != visited.end())))
        return false;
    else{
        visited.emplace(firstPair);
        visited.emplace(secondPair);
        return dfs(nums, sumA + nums[index], sumB, index+1, visited) || dfs(nums, sumA, sumB + nums[index], index+1, visited);
    }
    
}

bool can_partition(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_set<std::pair<int,int>, hashFunction> visited;
    if(!nums.size())
        return true;
    else
        return dfs(nums, nums[0], 0, 1, visited) || dfs(nums,0, nums[0], 1, visited);
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

