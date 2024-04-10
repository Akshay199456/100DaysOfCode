/*
Problem statement:

Given a collection of intervals, merge all overlapping intervals.

Example: 1
Input:
intervals = [[1,3],[2,6],[8,10],[15,18]]
Output:
[[1,6],[8,10],[15,18]]
Explanation:
Since intervals [1,3] and [2,6] overlap, they are merged into [1,6].

Example: 2
Input:
intervals = [[1,4],[4,5]]
Output:
[[1,5]]
Explanation:
Intervals [1,4] and [4,5] are considered to be overlapping.

Constraints:
intervals[i][0] <= intervals[i][1]
*/

/*
-------------------------    My Approaches:
1. Merge intervals pattern

    we can solve this problem using the merge intervals pattern. if two intervals overlap, we make i1 as the merged interval and i2 move to the next interval/
    if not, we push i1 into the result, and make i1 hold what i2 was and move i2 to the next interval

    Time complexity: O(n)
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
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
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

void printIntervals(std::vector<std::vector<int>> & intervals){
    for(int i=0; i< intervals.size(); i++){
        std::cout<<"Interval: ( "<< intervals[i][0]<<" "<< intervals[i][1]<<std::endl;
    }
}

bool isIntervalIntersecting(std::vector<int> & i1, std::vector<int> & i2){
    return i1[1] >= i2[0] && i2[1] >= i1[0];
}

void getResult(std::vector<std::vector<int>> & intervals, std::vector<std::vector<int>> & result){
    int i=1;
    std::vector<int> i1 = intervals[0];
    std::vector<int> i2 = intervals[1];
    while(i<intervals.size()){
        if(isIntervalIntersecting(i1, i2)){
            std::vector<int> mergedInterval{std::min(i1[0],i2[0]), std::max(i1[1], i2[1])};
            i1 = mergedInterval;
        }
        else{
            result.push_back(i1);
            i1 = i2;
        }
        
        ++i;
        if(i < intervals.size())
            i2 = intervals[i];
    }
    result.push_back(i1);
}

std::vector<std::vector<int>> merge_intervals(std::vector<std::vector<int>> intervals) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::vector<int>> result;
    if(intervals.size() <= 1)
        return intervals;
    
    sortIntervals(intervals);
    // printIntervals(intervals);
    getResult(intervals, result);
    return result;
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
    std::vector<std::vector<int>> res = merge_intervals(intervals);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}



//  Other Approaches(1)
