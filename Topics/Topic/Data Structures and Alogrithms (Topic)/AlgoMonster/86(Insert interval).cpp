/*
Problem statement:

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example: 1
Input:
intervals = [[1,3],[6,9]]
newInterval = [2,5]
Output:
[[1,5],[6,9]]
Example: 2
Input:
intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]
Output:
[[1, 2], [3, 10], [12, 16]]
Example: 3
Input:
intervals = []
newInterval = [5,7]
Output:
[[5,7]]
Example: 4
Input:
intervals = [[1,5]]
newInterval = [2,3]
Output:
[[1,5]]
Example: 5
Input:
intervals = [[1,5]]
newInterval = [2,7]
Output:
[[1,7]]
*/

/*
-------------------------    My Approaches:
1. merge interval

    we just push the new interval into the array, run sorting algorithm and then we can merge the new interval. there is nothing unique in that so i havent coded it

    Time complexity: O(nlogn)
    Space complexity: O(1)
*/


/*
-------------------------    Other Approaches 
1.
    easiest way to solve this problem is to insert the interval to be inserted at the end, and now the problem has become a merge intervals problem.
    literally, the only thing we need to do is to add the new interval to the end and copy and paste the code we had in the merge interval problem.


    Time complexity: O(nlogn)
    Space complexity: O(1)
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy, max, sort
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

bool overlap(std::vector<int> a, std::vector<int> b) {
    return !(a[1] < b[0] || a[0] > b[1]);
}

std::vector<std::vector<int>> insert_interval(std::vector<std::vector<int>> intervals, std::vector<int> new_interval) {
    intervals.emplace_back(new_interval);

    // the rest is the same as merge intervals
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> res;
    for (std::vector<int> interval : intervals) {
        if (res.empty() || !overlap(res.back(), interval)) {
            res.emplace_back(interval);
        } else {
            std::vector<int>& last_interval = res.back();
            last_interval[1] = std::max(last_interval[1], interval[1]);
        }
    }
    return res;
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    int intervals_length;
    std::cin >> intervals_length;
    ignore_line();
    std::vector<std::vector<int>> intervals;
    for (int i = 0; i < intervals_length; i++) {
        intervals.emplace_back(get_words<int>());
    }
    std::vector<int> new_interval = get_words<int>();
    std::vector<std::vector<int>> res = insert_interval(intervals, new_interval);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}


//  Other Approaches(2)
