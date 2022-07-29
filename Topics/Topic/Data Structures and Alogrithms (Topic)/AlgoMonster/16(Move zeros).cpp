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
problem description asks us to do it in-place withotue extra data structure. there are only a couple of things
we can do under these constrints - linear traversal or binary search

we use slow and fast pointer.. the fast one moves one element at a time and
    1. if the current elment is 0, do nothing
    if the current element is non-zeroo, swap its elm,ent with the slow-pointers's element and moiv the slwo pointer

    the slow pointer sloways points to the next 0 if there is one.

the order of non-0 elements is preserved because theearly one always gets swapped to the early 0s.

    Time complexity: O()
    Space complexity: O()


Alternative approach

sometimes it helps to come up with an inefficient solutoon first and them inprove ip n it.

one such solution is to copy the non-zero elements to a new array, then copy the elements back to the original array and fill the rest with zeros


now if we take a look at bbith arrayss, we may notice that our position in the iriginal array  is never hehind the new
array (after all, if we only scanned k elements, we can never get more than k non-zero elements)

additionaly, note that before copying the non-zero elements back, modifying the elements before the eelments before hte current
position in the oroiginal array will not affect the algoruthm as we only scan forward in the array

therefore, we can 'put' the new array entriely in the beginning portion of the original array that we have already scanned - as in, store the elmeentns there and avodi nusing a new
array (a common technique for a lot of in-place algorithms). bettter yet, this is exactly where the non-zero eleemts need to be, so it also saves us from enededing
to copu the elements back.

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
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void move_zeros(std::vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            int slow_num = nums[slow];
            nums[slow] = nums[fast];
            nums[fast] = slow_num;
            slow++;
        }
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



// Other Approaches(2)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void move_zeros(std::vector<int>& nums) {
    // copy to new array
    std::vector<int> non_zeros;
    for (int n : nums) {
        if (n != 0) non_zeros.emplace_back(n);
    }
    // copy back
    int i = 0;
    for (; i < non_zeros.size(); i++) {
        nums[i] = non_zeros[i];
    }
    // fill rest with zeros
    for (; i < nums.size(); i++) {
        nums[i] = 0;
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


// Other Approaches(3)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void move_zeros(std::vector<int>& nums) {
    // copy in-place
    int i = 0;
    for (int n : nums) {
        if (n != 0) {
            nums[i] = n;
            i++;
        }
    }
    // fill rest with zeros
    for (; i < nums.size(); i++) {
        nums[i] = 0;
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
