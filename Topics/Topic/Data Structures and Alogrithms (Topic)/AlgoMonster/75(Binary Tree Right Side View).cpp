/*
Problem statement:

Given a binary tree, return the rightmost node of each level.


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
We can do a level order travesal and add the lsat node to return the result.

    Time complexity: O(n)
        we traverse every edge and node once but since the no of edges is n-1, then this simply becomes O(n)
    Space complexity: O()

Comparing this with the level order traversal problem, we can make the small modification that we append the right child of the tree to the queue first and only one element to 
result for each level.
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
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

std::vector<int> binary_tree_right_side_view(Node<int>* root) {
    std::vector<int> res;
    if (root == nullptr) return res;
    std::queue<Node<int>*> level;
    level.push(root);
    while (level.size() > 0) {
        int n = level.size();
        // only append the first node we encounter since it's the rightmost
        res.emplace_back(level.front()->val);
        for (int i = 0; i < n; i++) {
            Node<int>* node = level.front();
            if (node->right) level.push(node->right);
            if (node->left) level.push(node->left);
            level.pop();
        }
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
    std::vector<int> res = binary_tree_right_side_view(root);
    put_words(res);
}