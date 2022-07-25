/*
Problem statement:

Max depth of a binary tree is the longest root-to-leaf path. Given a binary tree, find its max depth.

Input:


*/

/*
-------------------------    My Approaches:
1. DFS

    wee can use the dfs appraoch in order to solve this problem. we have our base when we hit an empty node and pass the state ack up the tree.

    Time complexity: O(n)
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
Explantation:

1. decide on the return value
    the problem asks the total max depth, so we return the depth for the current subtree after we visit a node
2. idenitfy states
    to devide the depth of current node, we only need depth from its children and dont neeed any additional state

having decided on the state and reutnr value, we can now write the DFS.

there are n nodes and n-1 edges in a tree so if we traverse each one then the total traversal is O(2n-1) which is O(n)

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
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

int tree_max_depth(Node<int>* root) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(!root)
        return 0;
    
    int leftDepth = tree_max_depth(root->left);
    int rightDepth = tree_max_depth(root->right);
    return std::max(leftDepth, rightDepth)+1;
}

// this function build a tree from input
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
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<std::string> root_vec = get_words<std::string>();
    auto root_it = root_vec.begin();
    Node<int>* root = build_tree<int>(root_it, [](auto s) { return std::stoi(s); });
    int res = tree_max_depth(root);
    std::cout << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy, max
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
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

int tree_max_depth(Node<int>* root) {
    // Null node adds no depth
    if (root == nullptr) return 0;
    // Depth of current node's subtree = max depth of the two subtrees + 1 provided by current node
    return std::max(tree_max_depth(root->left), tree_max_depth(root->right)) + 1;
}

// this function build a tree from input
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
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<std::string> root_vec = get_words<std::string>();
    auto root_it = root_vec.begin();
    Node<int>* root = build_tree<int>(root_it, [](auto s) { return std::stoi(s); });
    int res = tree_max_depth(root);
    std::cout << res << '\n';
}
