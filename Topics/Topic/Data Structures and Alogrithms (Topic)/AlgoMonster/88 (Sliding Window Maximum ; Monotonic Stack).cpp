/*
Problem statement:

We have an array and a sliding window defined by a start index and an end index. The sliding window moves from left of the array to right. There are always k elements in the window. The window moves one position at a time. Find the maximum integer within the window each time it moves.

Input:

arr = [1, 3, 2, 5, 8, 7]
k = 3
Output:

[3, 5, 8, 8]
*/

/*
-------------------------    My Approaches:
1. Applying monotonic stack principles

    we can apply the principles of monotonic stack in order to solve this problem. monotonic stack does really well in problems where you need to find the maximum within a window and this problem illustrates that.
    As long as end-beg<k, we want to hold the maximum we have seen in the window at the front so we pop as needed and then insert the maximu. once we have crossed our window size, we will need to pop off from the 
    begging. before that though, we insert the element at the front since it was he maximum for our window. if the element at the front is the same as the beg index that we are at, then we pop it.
    and then increment beg.

    Time complexity: O(n)
    Space complexity: O(n)
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
#include <deque>

std::vector<int> slidingWindowMaximum(std::vector<int> & nums, int k){
    std::vector<int> result;
    std::deque<int> q;
    int beg = 0, end = 0;
    while(end < nums.size()){
        if(end - beg < k){
            while(!q.empty() && nums[q.back()] <= nums[end])
                q.pop_back();
            q.push_back(end++);
        }
        else{
            result.push_back(nums[q.front()]);
            if(beg == q.front())
                q.pop_front();
            ++beg;
        }
    }
    result.push_back(nums[q.front()]);
    return result;
}

std::vector<int> sliding_window_maximum(std::vector<int> nums, int k) {
    // WRITE YOUR BRILLIANT CODE HERE
    if (!k)
        return {};
    return slidingWindowMaximum(nums, k);
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
    std::vector<int> nums = get_words<int>();
    int k;
    std::cin >> k;
    ignore_line();
    std::vector<int> res = sliding_window_maximum(nums, k);
    put_words(res);
}



//  Other Approaches(1)
