/*
Problem statement:

You are given a set of numbers nums consisting of distinct numbers. Find the size of the largest subset that satisfies the following condition: for each two number pairings in the set, one number is divisible by the other.

Input
nums: a list integers representing the set.
Output
An integer representing the size of the largest subset that satisfy the condition.

Examples
Example 1:
Input:

nums = [1, 2, 3]
Output: 2

Explanation:

Either [1, 2] or [1, 3] satisfy the condition, because both 2 and 3 are both divisible by 1. Either way, the largest set has a size of 2.

Example 2:
Input:

nums = [1, 2, 4, 8]
Output: 4

Explanation:

In this set, for each pair of numbers, at least one is divisible by the other because they are all powers of 2. As such, the max subset has a size of 4, the size of the original set.

Constraints
1 <= len(nums) <= 1000
1 <= nums[i] <= 10^9
Each number in nums is unique
*/

/*
-------------------------    My Approaches:
1. combinatorics + dfs

    we can use basic brute force approach which includes combinatorics + dfs to solve this problem.
    we sort the numbers at the very beginning as it makes it easy to compare the numbers later on as we just need to compare each number with the previous
    number since they are in sorted order. in addition, at each step , we have one of two chocie we can make:
    1) either add this element to the lsit 2) or not add this element. when the index reaches the lisze size, we lknow we ahve
    covered all elements and as a result, we make the check if the numbers are in sorted roder. 

    we can actually improve upon the approach by only storing the last number we have encountered since the array is sorted similar to what we had in the
    previous problem pb 57. that way we can save on the O(n) time complexity that it takes once we reach the 
    index end.

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
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/*
void printList(std::vector<int> & list){
    for(int i=0; i< list.size(); i++){
        std::cout<<list[i]<<" ";
    }
    std::cout<<std::endl;
}
*/

bool isConditionSatisfied(std::vector<int> & list){
//     printList(list);
    for(int i=1; i<list.size(); i++){
        if(list[i] % list[i-1] != 0)
            return false;
    }
    return true;
}


void generateSubsets(std::vector<int> & nums, int index, std::vector<int> list, int & maxLength){
    if(index == nums.size()){
        bool isValid = isConditionSatisfied(list);
        if(isValid)
            maxLength = std::max(maxLength, (int)list.size());
    }
    else{
        // we can add this number to the set
        list.push_back(nums[index]);
        generateSubsets(nums, index+1, list, maxLength);
        
        // or not add it to the list
        list.pop_back();
        generateSubsets(nums, index+1, list, maxLength);
    }
}

int find_largest_subset(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<int> list;
    int maxLength = 1;
    std::sort(nums.begin(), nums.end());
    generateSubsets(nums, 0, list, maxLength);
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
    int res = find_largest_subset(nums);
    std::cout << res << '\n';
}



//  Other Approaches(1)
