/*
Problem statement:

Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
Input:
matrix = [
  [ 1,  5,  9],
  [10, 11, 13],
  [12, 13, 15]
],
k = 8,
Output: 13
Note:
You may assume k is always valid, 1 ≤ k ≤ n^2. You may also assume that 1 <= n <= 1000.
*/

/*
-------------------------    My Approaches:
1. using property of heap

    we can solve this problem using a simple heap. we can go through each element and insert it into the heap keeping he size of the ehap
    fixed at k. we are using a max heap btw. this way whenever an element greater than the top of the heap and the size of the heap is greater than or equal to k,
    we pop the top of the heap and instead push this new elmeent in as we are looking for the kth smallest elmenet.
    this element will be at the top of th e heap at the end.

    Time complexity: O(n^2logk)
    Space complexity: O(k)

2. merge k sorted lists technique [not coded] {pb 78 algo}

    we can technically use the same technique that we learnt for merge k sorted lists to solve this problem as well.
    since in merge k sorted lists, we can have a pointer at teach of the lists. since we know each list is sorted, 
    we can push the leemnts one by one into the heap. since we are looking for the kth smallest element and we are beinnging at the front of each of the lists,
    after k insertion, we have found the answer and so we can return the top of the heap.

    time complexity: O(nlogk)
    space complexity: O(k)

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
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <queue>

int getKSmallest(std::vector<std::vector<int>> matrix, int k){
    std::priority_queue<int> pq;
    
    // insert elements into heap
    for(int i=0; i< matrix.size(); i++){
        for(int j=0; j < matrix[i].size(); j++){
            if(pq.size() < k)
                pq.push(matrix[i][j]);
            else{
                if(pq.top() > matrix[i][j]){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
    }
    
    // get top of heap and return it 
    return pq.top();
}


int kth_smallest(std::vector<std::vector<int>> matrix, int k) {
    // WRITE YOUR BRILLIANT CODE HERE
    return getKSmallest(matrix, k);
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
    int matrix_length;
    std::cin >> matrix_length;
    ignore_line();
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < matrix_length; i++) {
        matrix.emplace_back(get_words<int>());
    }
    int k;
    std::cin >> k;
    ignore_line();
    int res = kth_smallest(matrix, k);
    std::cout << res << '\n';
}



//  Other Approaches(1)
