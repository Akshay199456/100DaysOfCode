/*
Problem statement:

Given a sorted array of integers and a target integer, find the first occurrence of the target and return its index. Return -1 if the target is not in the array.

Input:

arr = [1, 3, 3, 3, 3, 6, 10, 10, 10, 100]
target = 3
Output: 1

Explanation: First occurrence of 3 is at index 1.

Input:

arr = [2, 3, 5, 7, 11, 13, 17, 19]
target = 6
Output: -1

Explanation: 6 does not exists in the array.
*/

/*
-------------------------    My Approaches:
1. binary search

We can use the binary search technique similar to pb 1 and 2 before.

    Time complexity: O(logn)
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
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_first_occurrence(std::vector<int> arr, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    int beg{0}, end{arr.size()-1};
    int index = -1;
    while(beg <= end){
        int mid = beg + (end-beg)/2;
        if(arr[mid] >= target){
            if(arr[mid] == target)
                index = mid;
            end = mid-1;
        }
        else
            beg = mid+1;
    }
    return index;
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

int main() {
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = find_first_occurrence(arr, target);
    std::cout << res << '\n';
}



//  Other Approaches(1)
