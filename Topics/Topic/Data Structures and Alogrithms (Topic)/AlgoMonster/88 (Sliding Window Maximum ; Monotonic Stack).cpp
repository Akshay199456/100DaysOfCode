/*
Problem statement:

We have an array and a sliding window defined by a start index and an end index. The sliding window moves from left of the array to right. There are always k elements in the window. The window moves one position at a time. Find the maximum integer within the window each time it moves.

Input:

arr = [1, 3, 2, 5, 8, 7]
k = 3
Output:

[3, 5, 8, 8]
*/

/*
-------------------------    My Approaches:
1. Applying monotonic stack principles

    we can apply the principles of monotonic stack in order to solve this problem. monotonic stack does really well in problems where you need to find the maximum within a window and this problem illustrates that.
    As long as end-beg<k, we want to hold the maximum we have seen in the window at the front so we pop as needed and then insert the maximu. once we have crossed our window size, we will need to pop off from the 
    begging. before that though, we insert the element at the front since it was he maximum for our window. if the element at the front is the same as the beg index that we are at, then we pop it.
    and then increment beg.

    Time complexity: O(n)
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1. Explanation

    brute force

    we can write a nested loop, the outer loop going through each window and the inner loop finding the max within the window. this is O(n^2) time complexity.
    to optimize beyond brute force, we can eitther reduce the complexity of the outer loop or inner loop. since we must examine each element at least once (there's no way to find the maximum
    if we dont know what the values are), there is not much we can do for the outer loop. so we haveto work on the inner loop

    Time complexity: O()
    Space complexity: O()


    Preserving the maximum of elements in the window

    Currently, to get the max of the sliding window, we look at each elmeent in the window and compare them. analogous to sliding window sum problem (given an arrray and a window isize, reuttnr the sum
    of each window) when a window slides, only two elements change - the leftmost gets removed and a new elements gets added to the right. everything in the middle (let's call them
    "window elements") is unchanged , and the maximum element among these window elements is unchanged as well. the kley to reduce inner loop complexity is to persist the maximum fo the window elements
    as we slide the window. idelaly, we want to be able to access the maximum element in less than O(N) time and updating it in less than O(n) time.


    Max Heap

    One way to achieve this goal is to push the window elements in a max heap and pop the elftmost element out of the heap when the window slides. the time compleity of this approach is Onlogk) sinmce
    we have to push k elements into the heap and pop k elkements out of the heap for each window. the space comeplxity is O(k) sinc ethe heap can only hold k elements at a time.

    this is pretty good already but can wwe do better?


    Larger elements entering the window invalidates smaller elemnts

    a question we can ask ourselves is "do we need to keep all the window elements in our state?". an important iobservation is for two elemnets arr[left] and arr[right][, whjere left<right,
    arr[left] leaves the window earler as we slide. if arr[rigth] is larger than arr[left], then there s no point keeping arr[left] in our state since arr[right] is alwayus gonna be larger during the time arr[left] is 
    in the window. therefore, arr[left] can never be the maximum



2. Monotonuic deque

    here we introduce an interesting data structure. it's a deque with an interesting property - the elem,ents in the deque from head to tail are in decreasing order (hence the name monotonic).

    to achieve this property, we modify the push operation so that
        when we push an element into the deque, we first pop everything smaller than  it our of the deque.
    
    this enforces the deceasing order. lets see it in action. 
    the time complexity is O(n). this is because each element in the original array can only be pushed into and poppped out of the deque once.
    the space complexit is O(n) as there may be at most n elements in the deque.

    the main reason the monotonic deque achieves this is that it stores both magnitude and position information. from head to tail, the leemnts get smaller and are further to the right of the array

    in the actual implementation, we store indies inestead of the actual eelments in the deque. this is because we need the index to know if an element is out of the window or not and we can always get the value suing the index from the arrray.


    Time complexity: O(n)
    Space complexity: O(n)


*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <deque>

std::vector<int> slidingWindowMaximum(std::vector<int> & nums, int k){
    std::vector<int> result;
    std::deque<int> q;
    int beg = 0, end = 0;
    while(end < nums.size()){
        if(end - beg < k){
            while(!q.empty() && nums[q.back()] <= nums[end])
                q.pop_back();
            q.push_back(end++);
        }
        else{
            result.push_back(nums[q.front()]);
            if(beg == q.front())
                q.pop_front();
            ++beg;
        }
    }
    result.push_back(nums[q.front()]);
    return result;
}

std::vector<int> sliding_window_maximum(std::vector<int> nums, int k) {
    // WRITE YOUR BRILLIANT CODE HERE
    if (!k)
        return {};
    return slidingWindowMaximum(nums, k);
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
    std::vector<int> nums = get_words<int>();
    int k;
    std::cin >> k;
    ignore_line();
    std::vector<int> res = sliding_window_maximum(nums, k);
    put_words(res);
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <deque> // deque
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

std::vector<int> sliding_window_maximum(std::vector<int> nums, int k) {
    std::deque<int> max_indices;
    std::vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        while (!max_indices.empty() && nums[max_indices.back()] <= nums[i]) {
            max_indices.pop_back();
        }
        max_indices.push_back(i);
        // remove first element if it's outside the window
        if (max_indices.front() == i - k) {
            max_indices.pop_front();
        }
        // if window has k elements add to results (first k-1 windows have < k elements because we start from empty window and add 1 element each iteration)
        if (i >= k - 1) {
            res.emplace_back(nums[max_indices.front()]);
        }
    }
    return res;
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
    std::vector<int> nums = get_words<int>();
    int k;
    std::cin >> k;
    ignore_line();
    std::vector<int> res = sliding_window_maximum(nums, k);
    put_words(res);
}
