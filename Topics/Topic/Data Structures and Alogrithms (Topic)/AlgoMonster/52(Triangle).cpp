/*
Problem statement:

The problem is to find the minimum path sum from top to bottom if given a triangle. Each step you may move to adjacent numbers on the row below.

Input
triangle: see example
Output
the minimum path sum

Examples
Example 1:
Input:

triangle = [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
Output: 11

Explanation:

The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.
*/

/*
-------------------------    My Approaches:
1. combinatorics

    in this approach we use the cmbinatorics approach to generate the state-space tree.
    once we start from the root, we have one of two chocies: either move to the index at the next level or move to the index+1 
    at the next level. this way we cover all possible permutations of the problem and we have a minvalue that evalauts the minimum value
    at the last level of the tree

    Time complexity: O(2^n)
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
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void getMin(std::vector<std::vector<int>> & triangle, int & minValue, int sum, int index, int level){
    // if we have reached the leaf
    if(level == triangle.size()){
        if(sum < minValue)
            minValue = sum;
        return;
    }
    
    sum  += triangle[level][index];
    getMin(triangle, minValue, sum, index, level+1);
    getMin(triangle, minValue, sum, index+1, level+1);
}

int minimum_total(std::vector<std::vector<int>> triangle) {
    // WRITE YOUR BRILLIANT CODE HERE
    int minValue = std::numeric_limits<int>::max();
    if(!triangle.size())
        return 0;
    
    getMin(triangle,minValue, 0, 0, 0);
    return minValue;
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

int main() {
    int triangle_length;
    std::cin >> triangle_length;
    ignore_line();
    std::vector<std::vector<int>> triangle;
    for (int i = 0; i < triangle_length; i++) {
        triangle.emplace_back(get_words<int>());
    }
    int res = minimum_total(triangle);
    std::cout << res << '\n';
}



//  Other Approaches(1)
