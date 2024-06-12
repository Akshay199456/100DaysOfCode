/*
Problem statement:

Given a BST, output the k closest values in this BST to x. Sort the output by value.

The output set is guaranteed to be unique.

Do not convert the BST to a list.

Input
bst: a valid BST of size n.
x: an integer representing the number to find the k closest numbers to.
k: an integer.
Output
A list of integers containing the k closest numbers to x.

Examples
Example 1:
Input:

bst = <See explanation>
x = 7
k = 4
Output: [5, 6, 8, 10]

Explanation:



All four numbers in the output are within 3 away from 7.

Constraints
1 <= k <= n <= 10^5
*/

/*
-------------------------    My Approaches:
1. my approach [doesnt follow all conditions][not coded]

    well this approach will break one fo the ocnditions that has been setup by the program which is to not convert bst into list. 

    the way i would oslve it is to basically get the bst into a list. we can then use binary search to find where exactly the element would be situated if it were part of the bst.
    once we have the index, then we start taking one index from the left and right. we compare and see which is the smallest and add that to the result and push the index further back for whichever
    was the smallest. we continue to do this till we get all k closest values and contiunue to amekt he comparisona nd push the indexes. if we reach the end of the indexes on either end, we just take the rest of the values
    from the other side of the list. 

    with the operation for moving to the next node, the algorithm becomes simple. it is presented in other appraoches 1- (3) onwars

    Time complexity: O(n)
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1.  suggested solution

    this questiuon can be solved as follows, if it was a simple array: we can slide a window of size k, starting from the front. we move this window o the right, and the max distance from the target will decrease unitil it starts to increase again.
    in that case, the moment before the max distance inscrease is the closest k value.

    how do we implement this ina  bst, though? the key here is being able to find he next node given the current node. to do that, if we know the current node, if there exists a right subtree,
    then the next node must be the leftmost node of that subtree. otherwsie the next node is the least ancestor whose right tree has not been traversed.

    with the operation for moving to the next node, the algorithm becomes simple

    Time complexity: O(n) where n is the size of the tree
    Space complexity: O(n)
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <cmath> // abs
#include <deque> // deque
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <vector> // vector

template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;

    explicit Node(T val, Node<T>* left = nullptr, Node<T>* right = nullptr)
        : val{val}, left{left}, right{right} {}

    ~Node() {
        delete left;
        delete right;
    }
};

std::vector<int> closest_values(Node<int>* bst, int x, int k) {
    std::deque<int> res_deque;
    std::vector<Node<int>*> stack;
    Node<int>* node = bst;
    while (!stack.empty() || node) {
        while (node) {
            stack.push_back(node);
            node = node->left;
        }
        node = stack.back();
        stack.pop_back();
        if (res_deque.size() < k) {
            res_deque.push_back(node->val);
        } else {
            if (std::abs(res_deque.front() - x) > std::abs(node->val - x)) {
                res_deque.pop_front();
                res_deque.push_back(node->val);
            } else {
                break;
            }
        }
        node = node->right;
    }
    std::vector<int> res(res_deque.begin(), res_deque.end());
    return res;
}

// this function builds a tree from input
// learn more about how trees are encoded in https://algo.monster/problems/serializing_tree
template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;
    ++it;
    if (val == "x") return nullptr;
    Node<T>* left = build_tree<T>(it, f);
    Node<T>* right = build_tree<T>(it, f);
    return new Node<T>{f(val), left, right};
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
    std::vector<std::string> bst_vec = get_words<std::string>();
    auto bst_it = bst_vec.begin();
    Node<int>* bst = build_tree<int>(bst_it, [](auto s) { return std::stoi(s); });
    int x;
    std::cin >> x;
    ignore_line();
    int k;
    std::cin >> k;
    ignore_line();
    std::vector<int> res = closest_values(bst, x, k);
    put_words(res);
}