/*
Problem statement:

Given an array of integers and an integer target, find a subarray that sums to target and return the start and end indices of the subarray.

Input: arr: 1 -20 -3 30 5 4 target: 7

Output: 1 4

Explanation: -20 - 3 + 30 = 7. The indices for subarray [-20,-3,30] is 1 and 4 (right exclusive).
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
brute force is to find the sum of each subarray and compare it with the target. let n be the number of eleements in the array. there are n subarrays with size 1, n-1
subarrays with size 2 and 1 subarray with size n. time complexity is O(n^2)

key observation is that the sum of subarray[i,j] is equal to the sum of [0,j] minus the sum of [0,i-1].

the sum of elmeents from indexi 0 to i is called the prefix sum. if we have the subarray sum fir each index, we can find the 
sym of any subarray in constant time.

with knowledge of prefix sum under our belt, the problem boils down to two sum. we keep a dictionary of prefix_sum:index while going through the 
array calculating prefix_sum. if at any point, prefix_sum-target is in the dictionary, we have found our subarray.

in the implementation, typically we use prefix_sum[i] to denote the sum of elements in 0...i-1 (rightmost element i is not included in the sm). one good things about this is
prefix_sum[0] then means sum of array up to bit not including the first element i.e empty array. the definition of empty array sum is useful when there exists a subarray starting from 0 that sums up to the target.
without the defintion of empty array sum, we would miss it because its compleemnet 0 does not exist in the dictionary.
git    Time complexity: O(n)
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
#include <unordered_map> // unordered_map
#include <vector> // vector

std::vector<int> subarray_sum(std::vector<int> arr, int target) {
    std::unordered_map<int, int> prefix_sums;
    // an empty subarray has a sum of 0
    prefix_sums[0] = 0;
    int cur_sum = 0;
    for (int i = 0 ; i < arr.size(); i++) {
        cur_sum += arr[i];
        int complement = cur_sum - target;
        if (prefix_sums.count(complement)) {
            return {prefix_sums[complement], i + 1};
        }
        prefix_sums[cur_sum] = i + 1;
    }
    // return no indices if arr is empty
    return {};
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
    std::vector<int> res = subarray_sum(arr, target);
    put_words(res);
}