/*
Problem statement:

Given two binary trees root and subRoot, determine if subRoot is a subtree of root. A subtree of a binary tree is a tree that consists of a node in the tree and all of its descendants.
*/

/*
-------------------------    My Approaches:
1. DFS

    We can use a depth-first search (DFS) approach to traverse the root tree and check if the subtree matches at each node. We can define a helper function that checks if two trees are identical.
    The main function will traverse the root tree and call the helper function whenever it finds a node that matches the root of the subtree.

    Time complexity: O(m*n)
    Space complexity: O(m+n)
    where m is the number of nodes in the root tree and n is the number of nodes in the subRoot tree.
    The time complexity is O(m*n) because we need to traverse the entire root tree (m) and for each node, we need to check if the subtree matches (n). the space complexity is O(m+n) because we need to store the nodes in the stack during the traversal.
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
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template<typename T>
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


bool dfs(Node<int>* root, Node<int>* sub_root){
    if(!root && !sub_root)
        return true;
    else if(!root || !sub_root)
        return false;
    return (root->val == sub_root->val) && dfs(root->left, sub_root->left) && dfs(root->right, sub_root->right); 
}


bool subtree_of_another_tree(Node<int>* root, Node<int>* sub_root) {
    // WRITE YOUR BRILLIANT CODE HERE
    bool result = false;
    if(!root || !sub_root)
        return false;
    if(root->val == sub_root->val)
        result = result || dfs(root, sub_root);
    else
        result = subtree_of_another_tree(root->left, sub_root)|| subtree_of_another_tree(root->right, sub_root);
    
    return result;
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
    std::vector<std::string> sub_root_vec = get_words<std::string>();
    auto sub_root_it = sub_root_vec.begin();
    Node<int>* sub_root = build_tree<int>(sub_root_it, [](auto s) { return std::stoi(s); });
    bool res = subtree_of_another_tree(root, sub_root);
    std::cout << std::boolalpha << res << '\n';
}



//  Other Approaches(1)
