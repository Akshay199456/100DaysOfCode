/*
Problem statement:

A sorted array of unique integers was rotated at an unknown pivot. For example, [10, 20, 30, 40, 50] becomes [30, 40, 50, 10, 20]. Find the index of the minimum element in this array. All the numbers are unique.

Input: [30, 40, 50, 10, 20]

Output: 3

Explanation: the smallest element is 10 and its index is 3.

Input: [3, 5, 7, 11, 13, 17, 19, 2]

Output: 7

Explanation: the smallest element is 2 and its index is 7.


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
at first glance, it seems that there's no way to do it in less than linear time. the array is not sorted.

but rememeber binary search can work beyond sorted arrays as long as there is a binary decision we can use to shrink the search range.

lets draw a figure and see if there's a pattern. if we plot the numbers against their index, we get:

notice, the numbers are divided into two sections: number larger than the last elemnet of the array and numbers smaller than it.
the minimum element is at the boundary between the two sections.

we can apply a filter of < the last element and get the boolean array that characterizes the two sections.

now the problem is yet again reduced the finding the first true element in a boolean array. and we already know how to do this from the 
find the boundary problem.

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_min_rotated(std::vector<int> arr) {
    int left = 0, right = arr.size() - 1, boundary_index = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // if arr[mid] <= last element, then it belongs to the lower half
        if (arr[mid] <= arr[arr.size() - 1]) {
            boundary_index = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return boundary_index;
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
    std::vector<int> arr = get_words<int>();
    int res = find_min_rotated(arr);
    std::cout << res << '\n';
}
