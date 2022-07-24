/*
Problem statement:

An array of boolean values is divided into two sections; the left section consists of all false and the right section consists of all true. Find the boundary of the right section, i.e. the index of the first true element. If there is no true element, return -1.

Input: arr = [false, false, true, true, true]

Output: 2

Explanation: first true's index is 2.
*/

/*
-------------------------    My Approaches:
1. binary search

    this problem is a perfect candidate for binary search. since we have the true and false ordered, we can use the binary search to find hte boundary where the true an false meet easily by skipping
    through a whole set of elements. rememeber, binary search is a solid pattern to use when you ahve ordered elements of any size.

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
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_boundary(std::vector<bool> arr) {
    // WRITE YOUR BRILLIANT CODE HERE
    int beg{0}, end{arr.size()-1};
    while(beg<=end){
        int mid = beg + (end-beg)/2;
        if(!arr[mid])
            beg = mid+1;
        else{
            if(!mid)
                return 0;
            else if(!arr[mid-1])
                return mid;
            else
                end = mid-1;
        }
    }
    return -1;       
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<bool> arr;
    bool b;
    while (ss >> std::boolalpha >> b) {
        arr.push_back(b);
    }
    int res = find_boundary(arr);
    std::cout << res << '\n';
}



//  Other Approaches(1)
