/*
Problem statement:

Given an array of integers and an integer target, find a subarray that sums to target and return the start and end indices of the subarray.

Input: arr: 1 -20 -3 30 5 4 target: 7

Output: 1 4

Explanation: -20 - 3 + 30 = 7. The indices for subarray [-20,-3,30] is 1 and 4 (right exclusive).


*/

/*
-------------------------    My Approaches:
1. two pointer approach

    we basiclaly used the two pointer approach in order to solve this problem. we use two for loops to go through
    each subarray and calculate its sum and check if its value is equal to the target. if it is equal, we return it else
    we contineu with the next subarray.

    Time complexity: O(n^2)
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
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

std::vector<int> getRange(std::vector<int> arr, int target){
    int start = -1, end = -1;
    int sum = 0;
    for(int i=0; i < arr.size(); i++){
        start = i, end = i;
        sum = arr[i];
        if(sum == target)
            return {start, end+1};
        
        for(int j=i+1; j< arr.size(); j++){
            end = j;
            sum += arr[j];
            if(sum == target)
                return {start, end+1};
        }        
    }
    return {-1,-1};
}

std::vector<int> subarray_sum(std::vector<int> arr, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    return getRange(arr, target);
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




//  Other Approaches(1)
