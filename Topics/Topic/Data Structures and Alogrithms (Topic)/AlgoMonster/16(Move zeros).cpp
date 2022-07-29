/*
Problem statement:

Given an array of integers, move all the 0s to the back of the array while maintaining the relative order of the non-zero elements. Do this in-place using constant auxiliary space.

Input:

[1, 0, 2, 0, 0, 7]
Output:

[1, 2, 7, 0, 0, 0]
*/

/*
-------------------------    My Approaches:
1. Two pointers moving in same directions

we can use a fast and slow pointer with the primary pointer being th eslow pointer. everytime we come across a 0,
we move the fast pointer forward till we hit a non-zero element and then swap the elements at slow and fast.  we then push the fast an dslow pointer
forward which also happens in the other case. we dont need to pull back fast pointer to the location of the slow pointer since
fast pointer would be skipping zeros and is therfore  only going to be present at tnon-zero elements

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

void move_zeros(std::vector<int>& nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    int slow{0}, fast{0};
    while(slow < nums.size() && fast < nums.size()){
        if(!nums[slow]){
            // find the next non-zero element
            while(fast < nums.size() && !nums[fast])
                ++fast;
            
            if(fast < nums.size()){
                int swappedValue = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = swappedValue;
            }
        }
        
        ++slow;
        ++fast;
    }
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
    std::vector<int> nums = get_words<int>();
    move_zeros(nums);
    put_words(nums);
}



//  Other Approaches(1)
