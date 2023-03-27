/*
Problem statement:

Find the middle node of a linked list.

Input: 0 1 2 3 4

Output: 2

If the number of nodes is even, then return the second middle node.

Input: 0 1 2 3 4 5

Output: 3


*/

/*
-------------------------    My Approaches:
1. 

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
Intuition
    if it was an array, then we can get its length and middle element trivially. for a linked list, we have to traverse it to find its length l.
    we can find l by traversing the list once and then fnd the middle element by traversing it again and stop by on 
    the l/2th element.

    is there any way to traverse only once? we can use two pointers
        1. a fast pointer that moves 2 nodes at a time and
        2. a slow popinter that moves 1 node at a time.

    since the speed of the fast pointer is 2x of the slow pointer, by the time the fast pointer reaches the end the slow pointer should be at the 
    exact middle of the list

    Time complexity: O(n)
        technically O(n/2) but again constants are cut out from the time compolexity and so we are left with just O(n)
    Space complexity: O(1)


Review:
    notice that:
        1. we have to check the existence of fast and fast.next in the while loop condition. we have to check fast because if list length is odd,
        the fast pointer would reach the last node. and if list length is even, the fast poionter would land on null.
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <vector> // vector

template <typename T>
struct Node {
    T val;
    Node<T>* next;

    explicit Node(T val, Node<T>* next = nullptr)
        : val{val}, next{next} {}

    ~Node() {
        delete next;
    }
};

int middle_of_linked_list(Node<int>* head) {
    Node<int>* slow = head;
    Node<int>* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->val;
}

template<typename T, typename Iter, typename F>
Node<T>* build_list(Iter& it, Iter& end, F f) {
    if (it == end) return nullptr;
    std::string val = *it;
    ++it;
    Node<T>* next = build_list<T>(it, end, f);
    return new Node<T>{f(val), next};
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

int main() {
    std::vector<std::string> head_vec = get_words<std::string>();
    auto head_it = head_vec.begin();
    auto head_end = head_vec.end();
    Node<int>* head = build_list<int>(head_it, head_end, [](auto s) { return std::stoi(s); });
    int res = middle_of_linked_list(head);
    std::cout << res << '\n';
}