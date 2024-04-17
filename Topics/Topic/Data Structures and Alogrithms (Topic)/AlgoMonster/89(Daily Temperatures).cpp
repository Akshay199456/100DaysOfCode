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
1. Solution

    consider the brute force solution that searches through the entire array to find the next warmer day for each day, the runtime is O(n^2). we want to avoid traversing through the entire array
    during every day, and we can achieve this by optimiing using a monotonic stack

    we ill traverse through the enture array only once and use the stack to store past information. since we want to traverse through the array only once, at index i, we wouldnt know the next warmer
    day until we visit it, so we store i in the stack. the stack sotres all the days without a solution, in increasing index vlaue. once we encounter a warmer day, we keep popping the indices with lower termpertatures
    and add the corresponding solution (th enumber of days passed) for each popped day. the logic is as follows: on a new day i, we want to check wehther  the temperature t[i] is warmer than the term,perature on the top of the stack
    (stack[-1]); we have two outcomes:
        1. t[1] > t[stack[-1]], then we have found a solution for day prev_day_index = stack[-1], we pop the stack and store res[prev_day_index] = i-prev_day_index.
        2. t[i] <= t[stack[-1]] and we put day i onto the stack

    note that we continue checking condition 1 with the new top of the stack until we reach condition 2 or there is nothing in the stack. alsom obersve that we always pop the 
    stacj until t[1] <= t[stack[-1]], so that each time we push an index i onto the stack, we know that the previous index has a warmer temperature. since each day is coller than the previous
    day on the stack, we deduce that the termperatures associated with these idneices are monotonically decreasing in the stack (from bottom to top of the stack). with the stack property that associated temperatures are
    monotonically decreasing, we can guarnatee each day will get popped when we find its solution.

    Time complexity: O(n)
        we lopp throug the array once, and the stack is an O(1) data structure for insertion and popping.
    Space complexity: O(n)
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
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <stack> // stack
#include <string> // getline, string
#include <vector> // vector

std::vector<int> daily_temperatures(std::vector<int> t) {
    std::vector<int> res(t.size(), 0);
    // stores indices of previous colder days
    std::stack<int> stack;
    for (int i = 0; i < t.size(); i++) {
        // while the stack is not empty and current day is warmer than the day referred by the top of the stack
        while (!stack.empty() && t[stack.top()] < t[i]) {
            // get the index of the colder previous day and pop it from stack
            int prev_day_index = stack.top();
            stack.pop();
            // set the popped index in the res array to (current index - the popped index)
            res[prev_day_index] = i - prev_day_index;
        }
        // push the current index to stack
        stack.push(i);
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