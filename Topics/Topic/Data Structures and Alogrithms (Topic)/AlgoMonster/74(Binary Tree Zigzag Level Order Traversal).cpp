/*
Problem statement:

Given a binary tree, return its level order traversal but in alternate left to right order.


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
Explnation:
    this problem is almost the same as level order traversal. we just have to keep a flag to track if we are currently traversing left-to-right or riight-to-left.

    Time complexity: O(n)
        we traverse every edge and nodde once but since the nummmber of edges is n-1, then this simply becomes O(n)
    Space complexity: O(n)
        there ar at most O(n) nodes in the queue.
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <list> // list
#include <queue> // queue
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

std::vector<std::vector<int>> zig_zag_traversal(Node<int>* root) {
    std::vector<std::vector<int>> res;
    if (root == nullptr) return res;
    std::queue<Node<int>*> level;
    level.push(root);
    bool left_to_right = true;
    while (level.size() > 0) {
        int n = level.size();
        std::list<int> new_level;
        for (int i = 0; i < n ; i++) {
            Node<int>* node = level.front();
            if (left_to_right) {
                new_level.emplace_back(node->val);
            } else {
                new_level.emplace_front(node->val);
            }
            if (node->left) level.push(node->left);
            if (node->right) level.push(node->right);
            level.pop();
        }
        res.emplace_back(std::vector(new_level.begin(), new_level.end()));
        left_to_right = !left_to_right;    // flip flag
    }
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::string> root_vec = get_words<std::string>();
    auto root_it = root_vec.begin();
    Node<int>* root = build_tree<int>(root_it, [](auto s) { return std::stoi(s); });
    std::vector<std::vector<int>> res = zig_zag_traversal(root);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}