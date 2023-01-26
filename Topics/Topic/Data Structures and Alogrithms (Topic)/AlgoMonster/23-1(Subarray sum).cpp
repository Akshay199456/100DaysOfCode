/*
Problem statement:

Given an array of integers and an integer target, find a subarray that sums to target and return the start and end indices of the subarray.

Input: arr: 1 -20 -3 30 5 4 target: 7

Output: 1 4

Explanation: -20 - 3 + 30 = 7. The indices for subarray [-20,-3,30] is 1 and 4 (right exclusive).


*/

/*
-------------------------    My Approaches:
1. two pointer approach

    we basiclaly used the two pointer approach in order to solve this problem. we use two for loops to go through
    each subarray and calculate its sum and check if its value is equal to the target. if it is equal, we return it else
    we contineu with the next subarray.

    Time complexity: O(n^2)
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
1. Intuition

    the brute force way is to find the sum of each subarray and compare iot with the target. Let N be the 
    number of elements in the array. there are n subarrays with size 1, n-1 subarrays with size 2 and 1 subarray with size n.
    time complexity is O(n^2)

    key observation is that the sum of a subarray [i,j] is equal to the sum of [0,j] minus the sum of [0,i-1]
    The sum of elements from index 0 to i is called thre prefix sum. if we have the subarray sum for each index, we can find the 
    sum of any subarray in constant time.

    with the knowledge of the prefix sum under our belt, the problem boils down to two sum. we keep a dictionary of prefix_sum: index while
    going through the array calculating prefix_sum. if at any point, prefix_sum - target is in the dictionary, we have
    found our subarray.


    Time complexity: O(n)
    Space complexity: O()


2. Prefix sum

    So, it took me a while to understnd this approach. if you look at the image Additional Notes(1)-7, what the problem asks us is to finmd
    a subarray with sum k. now, we can keep a cumulative sum from the beginning of the array and lets name that sum. in that case, if we want to find whether
    k exists for the sum of the subarray, what we just need to check is if sum-k exists in the map wheree sum-k is the sum from the beginning 
    og the array to point where the subarray with sum k exists. this is because if k exists and we know sum exists, then if we are able to find sum-k, we can infer k exists. and that
    means a subarray with sum k exists.

    that's how the technique gets applied here for prefix_sum.
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

std::vector<int> getRange(std::vector<int> arr, int target){
    int start = -1, end = -1;
    int sum = 0;
    for(int i=0; i < arr.size(); i++){
        start = i, end = i;
        sum = arr[i];
        if(sum == target)
            return {start, end+1};
        
        for(int j=i+1; j< arr.size(); j++){
            end = j;
            sum += arr[j];
            if(sum == target)
                return {start, end+1};
        }        
    }
    return {-1,-1};
}

std::vector<int> subarray_sum(std::vector<int> arr, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    return getRange(arr, target);
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
    int target;
    std::cin >> target;
    ignore_line();
    std::vector<int> res = subarray_sum(arr, target);
    put_words(res);
}


// My Approaches(2)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_map>

std::vector<int> subarray_sum(std::vector<int> arr, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_map<int,int> elementMap;
    int cumSum = 0;
    elementMap[0] = 0;
    
    for(int i=0; i< arr.size(); i++){
        cumSum += arr[i];
        int complement =  cumSum - target;
        if(elementMap.find(complement) != elementMap.end())
            return {elementMap[complement], i+1};        
        elementMap[cumSum] = i+1;
    }
    
    return {};
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
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    std::vector<int> res = subarray_sum(arr, target);
    put_words(res);
}




//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <vector> // vector

std::vector<int> subarray_sum(std::vector<int> arr, int target) {
    std::unordered_map<int, int> prefix_sums;
    // an empty subarray has a sum of 0
    prefix_sums[0] = 0;
    int cur_sum = 0;
    for (int i = 0 ; i < arr.size(); i++) {
        cur_sum += arr[i];
        int complement = cur_sum - target;
        if (prefix_sums.count(complement)) {
            return {prefix_sums[complement], i + 1};
        }
        prefix_sums[cur_sum] = i + 1;
    }
    // return no indices if arr is empty
    return {};
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
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    std::vector<int> res = subarray_sum(arr, target);
    put_words(res);
}
