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


    Time complexity: O()
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
