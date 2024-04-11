/*
Problem statement:

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...](si < ei), determine if a person could attend all meetings.

Example: 1
Input:
intervals = [[0,30],[5,10],[15,20]]
Output:
false
Example: 2
Input:
intervals = [[7,10],[2,4]]
Output:
true
*/

/*
-------------------------    My Approaches:
1. interval pattern

    we can apply the interval pattern here to solve the problem. the only caveat is theat if thre are two meetings like [6,8], [8,10], we can still make it for this example 
    since you can go to the next itnerval but for the merge intervals, those intervals would get merged.

    Time complexity: O(nlogn)
    Space complexity: O(1)
*/


/*
-------------------------    Other Approaches 
1.

this problem vasically asks if there's any overla[p between adjacent intervals. we sort the intervals bu start time and use the ttechnique from the intro section to check for overlap

let n denote the size of the intervals array

    Time complexity: O(nlogn)
    Space complexity: O(1)
*/


/*
-------------------------    Notes


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

void sortIntervals(std::vector<std::vector<int>> & intervals){
    auto compareElement = [](std::vector<int> &a, std::vector<int> &b){
        return a[0] < b[0];
    };
    std::sort(intervals.begin(), intervals.end(), compareElement);
}

bool isIntervalIntersecting(std::vector<int> & i1, std::vector<int> & i2){
    return i1[1] > i2[0] && i2[1] > i1[0];
}

bool isAllMeetingsPossible(std::vector<std::vector<int>> & intervals){
    int i=1;
    while(i < intervals.size()){
        if(isIntervalIntersecting(intervals[i-1], intervals[i]))
            return false;
        ++i;
    }
    return true;
}

bool meeting_rooms(std::vector<std::vector<int>> intervals) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(intervals.size() <=1)
        return true;
    
    sortIntervals(intervals);
    return isAllMeetingsPossible(intervals);
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
    int intervals_length;
    std::cin >> intervals_length;
    ignore_line();
    std::vector<std::vector<int>> intervals;
    for (int i = 0; i < intervals_length; i++) {
        intervals.emplace_back(get_words<int>());
    }
    bool res = meeting_rooms(intervals);
    std::cout << std::boolalpha << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy, sort
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

bool meeting_rooms(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end());
    
    for (int i = 0; i < intervals.size() - 1; i++) {
        if (intervals[i][1] > intervals[i + 1][0]) return false;
    }
    return true;
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
    int intervals_length;
    std::cin >> intervals_length;
    ignore_line();
    std::vector<std::vector<int>> intervals;
    for (int i = 0; i < intervals_length; i++) {
        intervals.emplace_back(get_words<int>());
    }
    bool res = meeting_rooms(intervals);
    std::cout << std::boolalpha << res << '\n';
}