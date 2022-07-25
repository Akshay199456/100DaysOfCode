/*
Problem statement:

A mountain array is defined as an array that

has at least 3 elements
has an element with the largest value called "peak", with index k. The array elements monotonically increase from the first element to A[k], and then monotonically decreases from A[k + 1] to the last element of the array. Thus creating a "mountain" of numbers.
That is, given A[0]<...<A[k-1]<A[k]>A[k+1]>...>A[n-1], we need to find the index k. Note that the peak element is neither the first nor the last element of the array.

Find the index of the peak element. Assume there is only one peak element.

Input: 0 1 2 3 2 1 0

Output: 3

Explanation: the largest element is 3 and its index is 3.
*/

/*
-------------------------    My Approaches:
1.  binary search

    we can use the binary search technique to solve this problem. we know that at the peak, it is greater than the elment at its immediate predecssor
    as well as the elemnt at its immediate successor and this is only position where this occurs. we also know that it can't be  at the ends of the araay. as a result, we test for that condition.
    if it is only greater than its predecssor, then we know that the peak is going to be on the right side as the value is still to increase.
    if it is only greater than its scucessor, then we know that the peak has occurred before or at this idnex, so swe set it.
    if both are set, then we know we have found our answer.

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

int peak_of_mountain_array(std::vector<int> arr) {
    // WRITE YOUR BRILLIANT CODE HERE
    int beg{0}, end{arr.size()-1}, minIndex{-1};
    while(beg <= end){
        int mid = beg + (end-beg)/2;
        bool leftValid = false, rightValid = false;
        if(!mid || arr[mid] > arr[mid-1])
            leftValid = true;
        if(mid==arr.size()-1 || arr[mid]>arr[mid+1])
            rightValid = true;
        
        if(leftValid && rightValid)
            return mid;
        else if(leftValid)
            beg = mid+1;
        else
            end=mid-1;
    }
    return -1;
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

int main() {
    std::vector<int> arr = get_words<int>();
    int res = peak_of_mountain_array(arr);
    std::cout << res << '\n';
}



//  Other Approaches(1)
