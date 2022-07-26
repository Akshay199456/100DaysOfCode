/*
Problem statement:

A binary search tree is a binary tree with the property that any of its node's value is greater than or equal to any node in its left subtree and less than or equal to any node's value in its right subtree.

Given a binary tree, determine whether it is a binary search tree.


*/

/*
-------------------------    My Approaches:
1. DFS

we apply the DFS pattern here. for the base condition we check if the tree is empty and if its , then we return true. we also need to check if the root->val exceeds the range it is permitted
to and if does, we return false. otherwise, we allow recursion to play its role on both the left and right subtree

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
1. decide on the return value
    we have to know wherether the left and right subtrees are valid BSTs. we get this from subtree return values

2. identify states
    to determine whether the subtree rooted at the current node is a BST or not, we need to know the range (min, max) the current node values is allwoed to be in.

having decided on the state and return value, we can now write the DFS

there are n nodes and n-1 edges in a tree so if we traverse each one, then the totla traveal is O(2n-1) which is O(n)

note on the logic in the last line of the DFS; when we recursively call DFS on the left node, since the left child's value should be less than or equal to current nodes' value we should opass current node's values as max value.
vice versa for right recrusive call/


    Time complexity: O(n)
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <vector> // vector
#include <limits>

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


bool checkValidBST(Node<int>* root, int minValue, int maxValue){
    if(!root)
        return true;
    else if (root->val < minValue || root->val > maxValue)
        return false;
    
    return checkValidBST(root->left, minValue, root->val) && checkValidBST(root->right, root->val, maxValue);    
}


bool valid_bst(Node<int>* root) {
    // WRITE YOUR BRILLIANT CODE HERE
    return checkValidBST(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
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
    bool res = valid_bst(root);
    std::cout << std::boolalpha << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
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

bool dfs(Node<int>* root, int min_val, int max_val) {
    if (!root) return true;
    if (!(min_val <= root->val && root->val <= max_val)) return false;
    return dfs(root->left, min_val, root->val) && dfs(root->right, root->val, max_val);
}

bool valid_bst(Node<int>* root) {
    return dfs(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
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
    bool res = valid_bst(root);
    std::cout << std::boolalpha << res << '\n';
}