/*
Problem statement:

Given k sorted lists of numbers, merge them into one sorted list.

Input: [[1, 3, 5], [2, 4, 6], [7, 10]]

Output: [1, 2, 3, 4, 5, 6, 7, 10]
*/

/*
-------------------------    My Approaches:
1. using min heap

    we can use a min heap in order to solve this problem. 

    ath eht ebeginning we just push the first elemnt from each of the lists into the heap. since its a min heap, the value that is the least
    will be at the top of the heap. in addition, since we are storing the list no and index of the elemtn in the list, once we take out the min element
    we can push its next elemnt instead as that will be one of the candidates for the next smallest element.

    we continue this till all the lists have been covered.

    Time complexity: O(nlogk) whjere n is the no of lists, k is the length of each list
    Space complexity: O(n) where n is the no of lists
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
Intuition

    the first thing that comes to mind is we can concatenate all lists into one list and sort the list. This is O(NlogN) because sorting is O(NlogN) where N
    is the total length of all lists

    next, we ask the question "are there any conditions that we havent used?". we know that all the lists are sorted and we havent used that condition.
    for each list, the smallest number is the first number. we can take the first number of each list and put them into a "pool of top k
    smallest numbers" where k is the number of lists. the samllest number in the pool is the smallest number of all the lists and should be added to the final merged list.
    we then take the next smallest number from the list and add it to the pool. repeat until we have exhausted all the lists.

    now the question becomes "how do we compare a stream of k numbers?" and thats a perfect use case for a min heap".

    note that:
        1. we push a tuple (val, current_list, head_index) into the heap. val is used to compare in the heap. we ened
        current_list and head_index because we want to know the next number to push
    
    Time complexity: O(nlogk)
        there are always k elements in the min-heap. for n elements where each insertion/deletion takes O(logk) time, the toal time complexity is 
        bounded by O(nlogk)
    
    Space complexity: O(k)
        aside fromt he outputs, we use a min-heap of size k, so the space complexity is O(k)
    
    note that we could also push all the elements into one min heap and pop them one by one. the heaps ize would be O(n)
    which means heap pop would be O(logn). this approach is slower than the O(logk) solution above, especially
    when n>>k.
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <queue>

struct Pair{
    int key;
    int posInList;
    int listNo;
    
    Pair(int k, int pos, int n): key(k), posInList(pos), listNo(n){
    }
    
    bool operator < (const struct Pair& other) const{
        return key > other.key;
    }
};

void getSorted(std::vector<std::vector<int>> & lists, std::vector<int> & result){
    // add first element from every list
    std::priority_queue<Pair> pq;
    
    for(int i=0; i<lists.size(); i++){
        std::vector<int> currList = lists[i];
        if(!currList.empty()){
            Pair currPair = Pair(currList[0],0, i);
            pq.push(currPair);
        }
    }
    
    //add remainign elements
    while(!pq.empty()){
        Pair topPair = pq.top();
        pq.pop();
        result.push_back(topPair.key);
        if(topPair.posInList + 1 < lists[topPair.listNo].size())
            pq.push(Pair(lists[topPair.listNo][topPair.posInList + 1], topPair.posInList + 1, topPair.listNo));
    }
}


std::vector<int> merge_k_sorted_lists(std::vector<std::vector<int>> lists) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<int> result;
    if(lists.empty())
        return result;
    
    getSorted(lists, result);
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
    int lists_length;
    std::cin >> lists_length;
    ignore_line();
    std::vector<std::vector<int>> lists;
    for (int i = 0; i < lists_length; i++) {
        lists.emplace_back(get_words<int>());
    }
    std::vector<int> res = merge_k_sorted_lists(lists);
    put_words(res);
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <queue> // priority_queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

struct Element {
    int val;
    std::vector<int> current_list;
    int head_index;

    Element(int val, std::vector<int> current_list, int head_index)
        : val{val}, current_list{current_list}, head_index{head_index} {}
};

std::vector<int> merge_k_sorted_lists(std::vector<std::vector<int>> lists) {
    std::vector<int> res;
    auto compare_element = [](Element& a, Element& b) { return a.val > b.val; };
    std::priority_queue<Element, std::vector<Element>, decltype(compare_element)> heap(compare_element);
    // push first number of each list into the heap
    for (auto list : lists) {
        Element e(list[0], list, 0);
        heap.push(e);
    }
    while (heap.size() > 0) {
        Element e = heap.top();
        heap.pop();
        res.emplace_back(e.val);
        int head_index = e.head_index + 1;
        // if there are more numbers in the list, push into the heap
        if (head_index < e.current_list.size()) {
            Element new_e(e.current_list[head_index], e.current_list, head_index);
            heap.push(new_e);
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
    int lists_length;
    std::cin >> lists_length;
    ignore_line();
    std::vector<std::vector<int>> lists;
    for (int i = 0; i < lists_length; i++) {
        lists.emplace_back(get_words<int>());
    }
    std::vector<int> res = merge_k_sorted_lists(lists);
    put_words(res);
}