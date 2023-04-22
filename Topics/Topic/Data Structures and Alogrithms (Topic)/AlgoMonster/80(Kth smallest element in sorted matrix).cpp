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
Brute force

    A brute force solution would traverse the matrix entirely and insert each elemnt into some type of container (array, vector, etc).
    we then sort the container and index kth element.

    the time complexity for this solution would be O(n^2 log n^2) because there are a total of n*n = n^2
    elements and sorting takes O(nlogn) in general.

Min Heap

    the brute force solution above is sufficient for th ebounds of this problem where n <= 1000. however, we can do better by 
    making use of the fact that each row is sorted. the idea is to use a keep a pointer on each row. we will move a pointer when
    said pointer is pointing to the smallestelement out of every pointer.

    the idea is simple, but how do we efficiently check which pointer is pointing at the smallest element? we can use a min heap! however, we cant
    just store the values themsevles, because otehrwise we would lose which row the values correspond too. we also cant store a value
    and row pair because then we would lose which column each pointer corresponds to per row. so we will store a value, row and 
    column tuple

    noote that we onl update k once we have popped the top element of the min heap. this helps simplify implementation
    details. furthermore, once a pointer cannot move anymore i.e it has reached the n-1th column, we remove it completely.

    for this specific impleemntation below, the tmime complexity is O(n+klogn) since it takes O(n) to process the first row
    and each of the k iterations take O(logn) to process due tot he use of the min heap.

    the space complexity is O(n) as the heap slways stores one element for each row (until its empty).


Additional notes:
    their approach 2 was the same as my approach 2 which id idnt code since we had used that technique before.


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
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <queue> // priority_queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int kth_smallest(std::vector<std::vector<int>> matrix, int k) {
    int n = matrix.size();
    auto compare_pos = [&matrix](std::vector<int> pos1, std::vector<int> pos2) {
        return matrix[pos1[0]][pos1[1]] > matrix[pos2[0]][pos2[1]];
    };
    // Keeps track of row and column numbers of items in the heap
    // The smallest item represented by the row and column number is added to the top
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare_pos)> heap(compare_pos);
    heap.push({0, 0});
    // Keeps track of the top of each row that is not processed
    int column_top[n] = { 0 };
    // Keeps track of the first number of each row that is not processed
    int row_first[n] = { 0 };
    // Repeat the process k - 1 times
    while (k > 1) {
        k--;
        std::vector<int> coords = heap.top();
        heap.pop();
        int row = coords[0], col = coords[1];
        row_first[row] = col + 1;
        // Add the item on the right to the heap if everything above it is processed
        if (col + 1 < n && column_top[col + 1] == row) {
            heap.push({row, col + 1});
        }
        column_top[col] = row + 1;
        // Add the item below it to the heap if everything before it is processed
        if (row + 1 < n && row_first[row + 1] == col) {
            heap.push({row + 1, col});
        }
    }
    std::vector<int> res = heap.top();
    return matrix[res[0]][res[1]];
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