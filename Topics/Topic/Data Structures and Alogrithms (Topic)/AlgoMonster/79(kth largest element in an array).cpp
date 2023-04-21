/*
Problem statement:

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not necessarily the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

/*
-------------------------    My Approaches:
1. Using min heap

    we can use a min heap in order to solve this problem. as long as the heap size is less than k, we can
    keep inserting elements into the heap. Once it exceeds k, we check the elkement we are currently at against the top of the 
    heap. if it is greater than the top, we pop the top and insert thi element instead. this is because, we are using our heap
    to store the k largest elements witht he klth largest element being at the top of the min heap since its the smallest.
    once we have gone through all the elkements, we just pop th etop of the heap and hat will give us the answer.


    Time complexity: O(nlogk)
    Space complexity: O(k)
*/


/*
-------------------------    Other Approaches 
1. Solution

    orting th earray before indexing gives us a O(nlogn) solutiopn. we can do better with a max heap. heapify
    is O(n) and poppingthe first k ele,menmt is O(klogn) so combined is O(n+klogn)

    Assuming thaat we used heapigy in place, then the space complexity ios O(1). if we had allocated a new max heap, then
    the space complexity s On) 

    Time complexity: O()
    Space complexity: O()

2. Quick Select
    
    alternatively we could use quick select for this particular problem. worst case sceaniro, it runs on O(n^2), but on average, it runs on O(n).
    
    quick slkeect uses the principole of quick sort, only during each process, we only need to care about the middle point compared to k-1 (because the question uses 1 indexing) and
    depending on the result, we either stop the progrtam, recurse to the left side or recurse to the right side.

    note that it is easy to get the indices of quick select wrong, so in a real coding interview, its often better to implement
    the ehap solution and have less chance of error.

*/


/*
-------------------------    Notes
s

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

int getKLargest(std::vector<int> nums, int k){
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i=0; i<nums.size(); i++){
        if(pq.size() < k)
            pq.push(nums[i]);
        else{
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    return pq.top();
}

int find_kth_largest(std::vector<int> nums, int k) {
    // WRITE YOUR BRILLIANT CODE HERE
    return getKLargest(nums, k);    
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
    std::vector<int> nums = get_words<int>();
    int k;
    std::cin >> k;
    ignore_line();
    int res = find_kth_largest(nums, k);
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

int find_kth_largest(std::vector<int> nums, int k) {
    std::priority_queue<int> heap(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++) {
        heap.pop();
    }
    return heap.top();
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
    std::vector<int> nums = get_words<int>();
    int k;
    std::cin >> k;
    ignore_line();
    int res = find_kth_largest(nums, k);
    std::cout << res << '\n';
}

// Other Approaches(2)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_kth_largest(std::vector<int> nums, int k) {
    int min_ptr = 0, max_ptr = nums.size() - 1;
    while (min_ptr < max_ptr) {
        int pivot = nums[max_ptr];
        int swap_left = min_ptr, swap_right = max_ptr;
        while (swap_left < swap_right) {
            while (swap_left < swap_right && nums[swap_left] > pivot) {
                swap_left++;
            }
            while (swap_left < swap_right && nums[swap_right] <= pivot) {
                swap_right--;
            }
            if (swap_left < swap_right) {
                std::swap(nums[swap_left], nums[swap_right]);
            }
        }
        std::swap(nums[swap_left], nums[max_ptr]);
        if (swap_left == k - 1) {
            return nums[swap_left];
        } else if (swap_left < k - 1) {
            min_ptr = swap_left + 1;
        } else {
            max_ptr = swap_left - 1;
        }
    }
    return nums[min_ptr];
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
    std::vector<int> nums = get_words<int>();
    int k;
    std::cin >> k;
    ignore_line();
    int res = find_kth_largest(nums, k);
    std::cout << res << '\n';
}