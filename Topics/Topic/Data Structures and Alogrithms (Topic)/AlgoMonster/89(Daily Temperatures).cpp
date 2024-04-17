/*
Problem statement:

Given a list of daily temperatures T, return a list such that for each day in the input, tells you how many days you would have to wait for a warmer temperature. If there is no future day for which this is possible, put 0 instead.

Examples
Example 1:
Input: [73, 74, 75, 71, 69, 72, 76, 73]
Output: [1, 1, 4, 2, 1, 1, 0, 0]
Note:
The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

/*
-------------------------    My Approaches:
1. Using monotonic stack pattern
2.

    Both Approaches(1) and (2) are practically the same. the only difference is (2) is way more verboseto make it more understandable.
    both approaches uses the monotonic stack pattern. Since the problem asks for the next warmer temperature, what we are looking for is basically the next higher element. and
    what data structure does that well. the monotonic stack allows us to identify the next lareger elemnt for an index when we pop it off. since we are storing the indexes, it beccomes
    easy to identify the difference in space which is what we store in the result. by default, the result is initialized to 0 so we dont have to worry about inititlizing the rest of the 
    elements who dont have a higher elemnt.

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
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <deque>

std::vector<int> daily_temperatures(std::vector<int> t) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<int> result(t.size(), 0);
    std::deque<int> q;
    int end = 0;
    while(end < t.size()){
        while(!q.empty() && t[q.back()] < t[end]){
            result[q.back()] = end - q.back();
            q.pop_back();
        }
        q.push_back(end++);
    }
    
    // whatever is still left in deque, keep it as 0
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> t = get_words<int>();
    std::vector<int> res = daily_temperatures(t);
    put_words(res);
}


// My Approaches(2)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <deque>

std::vector<int> daily_temperatures(std::vector<int> t) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<int> result(t.size(), 0);
    std::deque<int> q;
    int end = 0;
    while(end < t.size()){
        while(!q.empty() && t[q.back()] < t[end]){
            int poppingIndex = q.back();
            int diff = end - poppingIndex;
            result[poppingIndex] = diff;
            q.pop_back();
        }
        q.push_back(end++);
    }
    
    // whatever is still left in deque, keep it as 0
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> t = get_words<int>();
    std::vector<int> res = daily_temperatures(t);
    put_words(res);
}



//  Other Approaches(1)
