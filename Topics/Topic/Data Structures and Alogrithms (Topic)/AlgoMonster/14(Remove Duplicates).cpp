/*
Problem statement:

Given a sorted list of numbers, remove duplicates and return the new length. You must do this in-place and without using extra memory.

Input: [0, 0, 1, 1, 1, 2, 2].

Output: 3.

Your function should modify the list in place so the first 3 elements becomes 0, 1, 2. Return 3 because the new length is 3.
*/

/*
-------------------------    My Approaches:
1. Two pointer approach in same direction

    we can use the two pointe approach to solve this problem. we have a fast and slow pointer to start with.
    whenever arr[fas] = arr[slow], we move fast pointer forward. else we get the value of fast and subsitute it in arr[slow] and then move fast forward

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
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int remove_duplicates(std::vector<int>& arr) {
    // WRITE YOUR BRILLIANT CODE HERE
    int slow{0}, fast{0};
    while(fast < arr.size()){
        if(arr[fast] != arr[slow]){
            ++slow;
            arr[slow] = arr[fast];
        }
        ++fast;
    }
    return arr.size() ? ++slow : 0;
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
    int res = remove_duplicates(arr);
    arr.resize(res);
    put_words(arr);
}



//  Other Approaches(1)
