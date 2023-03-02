/*
Problem statement:

iven a binary tree, find the depth of the shallowest leaf node.


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
Explanation
    Can solve this problem with either DFS or BFS. With DFS, we traverse the whole tree looking for leaf nodes and recod and update the minimum
    depth as we go. With BFS though, since we search level by level we are guaranteed to find shallowest
    leaf node earlier than other leaf nodes. this is the biggest advantage of BFS over DFS.

    Time complexity: O(n)
        we traverse every edge and node once but since the no of edges is n-1, then simply becomes O(n)
    Space complexity: O(n)
        At most O(n) nodes in the queue.
    
    Added a variable depth to keep tracking current level/depth and an early return when we found a leaf node.
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
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

int binary_tree_min_depth(Node<int>* root) {
    std::queue<Node<int>*> level;
    int depth = -1; // start from -1 because popping root will add 1 depth
    level.push(root);
    while (level.size() > 0) {
        depth++;
        int n = level.size();
        for (int i = 0; i < n; i++) {
            Node<int>* node = level.front();
            if (node->left == nullptr && node->right == nullptr) {
                return depth;  // found leaf node, early return
            }
            if (node->left) level.push(node->left);
            if (node->right) level.push(node->right);
            level.pop();
        }
    }
    return depth;
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

int main() {
    std::vector<std::string> root_vec = get_words<std::string>();
    auto root_it = root_vec.begin();
    Node<int>* root = build_tree<int>(root_it, [](auto s) { return std::stoi(s); });
    int res = binary_tree_min_depth(root);
    std::cout << res << '\n';
}