/*
Problem statement:

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Examples
Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation:
The first 1's next greater number is 2;

The number 2 can't find a next greater number;

The second 1's next greater number needs to search circularly, which is also 2.

Note:
The length of the given array won't exceed 10000.
*/

/*
-------------------------    My Approaches:
1. monotonic stack pattern
        (Not the most absract of code. that can be improved upon later)
    we can apply the monotonic stack pattern here as well as we are looking to find the next greatest element. ther's only one caveat thouugh, its a circular array whic means
    the elements end up continuing once you arrive at the end of the array.
    the process will remain the same till we reach the end of the array as with previous problems. however, once we arrive at the end, we will have to continue with the beginning of the 
    array till we come across the biggest element in the array, which will be at the front of the deque. why will it be at the front of the deque? this is because the largest element
    in te arrary arrives normlaly at the front of the deque since no other element is higher than it. as a result, every other element in the deque will be lower than the front of the 
    deque (since it is the highest element). 
    why do we need to go only until the index of the alrgest element in the second run? this is because we know that once we arrive at the index of the largest element in the second run, every other elment we would have 
    encountered will be smaller than the largest element (whjich is in the front of th edeque). the largest element will be the largest elemnt and no elemnt can be higher than that. as a result, the second
    run gives us the ability to find the next larger elemnt for every other element. ni addition, lets say that the larer element for an elemnt after the largest elemtn is just before the largest elemtn. when we go for our second run
    before the limit, we will ccome across this element. since it is higher than our eleemnt (which is afte the limit), we now have found the larger element in order for it (before the limit).
    in addition, once we cross over the the point of the largest elemtn, its basically the same loop repeating again which we can avoid as we have already got the rest of the e,emntns sorted.


    Time complexity: O(2n)= O(n)
    Space complexity: O(n)

2. Monotonic stack pattern (not implemented)

    the other approach which is almost ht esame as (1) is instead of going through the limit, we just repeat a second run. by going through the second run, we are assured we have covered every element in the cycle.
    lets say that the list if divided into two section l = x + y where the partition is the point of largest element. when we repeat a second time the iteration, this beasically becomes
    x + y + x + y. as a result we are assured we have covered every elemnt from the beginning to the start of the partition and from the start of the partition till the beginning of the array again.

    we just have to make sure to not replace elements which have already found their next larger elemnt. to do this we can initially fill the array with -1. when we go through the first
    run some of them will get filled with an element other than -1. if that is the case, we just skip those elmeents in the next tun  when we come across them since they have already been fileld 

    Time complexity: O(2n)= O(n)
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
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <deque>

void nextGreatestElement(std::vector<int> & nums, std::vector<int> & result){
    int end = 0, nextLimit = -1;
    std::deque<int> q;
    // get next greatest element in proper order
    while(end < nums.size()){
        while(!q.empty() && nums[q.back()] < nums[end]){
            result[q.back()] = nums[end];
            q.pop_back();
        }
        q.push_back(end++);
    }
    
    if(!q.empty()){
        // continue searching for next greater element in circular order till the max of the current q
        end = 0, nextLimit = q.front();
        //std::cout<<"q front: "<<nextLimit<<" Size: "<<q.size()<<std::endl;
        while(end < nextLimit){
            while(!q.empty() && nums[q.back()] < nums[end]){
                result[q.back()] = nums[end];
                q.pop_back();
            }
            q.push_back(end++);
        }
    }
    
    // fill remaining elements with largest element
    int largestElement = nums[q.front()];
    q.pop_front();
    
    while(!q.empty()){
        if(nums[q.front()] != largestElement)
            result[q.front()] = largestElement;
        q.pop_front();
    }
}

std::vector<int> next_greater_elements(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<int> result(nums.size(), -1);
    if(nums.size() > 1)
        nextGreatestElement(nums, result);
    return result;
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
    std::vector<int> res = next_greater_elements(nums);
    put_words(res);
}



//  Other Approaches(1)
