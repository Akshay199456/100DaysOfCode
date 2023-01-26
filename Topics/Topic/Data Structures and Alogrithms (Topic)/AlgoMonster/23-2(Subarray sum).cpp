/*
Problem statement:

Find the total number of subarrays that sums up to target.


*/

/*
-------------------------    My Approaches:
1. using prefix sum

    we can use prefiix sum in order to solve the problem similar to what we had in pb 23-1. 
    the only difference in this problem is that we have to find the total number of subarrays that sum up to a target.
    we use the technique veyr similar to 23-1 in that we still want to find the complement and try to find the complement
    in the hashmap that we have seen till now. the reason we want to find the complement is because, if we find the complement which is curSum - target, we already know tht we have the curSum so by finding the complement., we are technically
    finding the target as well. so when we find the complement, we are basically finding the subarray sthat starts from the beignning and with sum equal to the compleemnt.
    if we do find that compleemnt, then we know that a certain number of subarrays has the sum = compleemnt, which also means that
    a certain number of subarrays have sum = target. as a result we increment count by the num of subarrays we found.
    we then store the curSum with count =1 if it didnt exist in map or increment its count if it already existed.
    

    Time complexity: O()
    Space complexity: O()
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
#include <unordered_map>

int subarray_sum_total(std::vector<int> arr, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    int count = 0, curSum = 0;
    std::unordered_map<int,int> elementCount;
    elementCount[0] = 1;
    
    for(int i=0; i<arr.size(); i++){
        curSum += arr[i];
        int complement = curSum - target;
        
        if(elementCount.find(complement) != elementCount.end())
            count += elementCount[complement];
        
        if(elementCount.find(curSum) != elementCount.end())
            elementCount[curSum] += 1;
        else
            elementCount[curSum] = 1;
    } 
    return count;
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
    std::vector<int> arr = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    int res = subarray_sum_total(arr, target);
    std::cout << res << '\n';
}



//  Other Approaches(1)
