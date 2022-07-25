/*
Problem statement:

A balanced binary tree is defined as a tree such that either it is an empty tree, or both its subtree are balanced and has a height difference of at most 1.

In that case, given a binary tree, determine if it's balanced.

Parameter
tree: A binary tree.
Result
A boolean representing whether the tree given is balanced.
Examples
Example 1
Input:



Output: true

Explanation: By definition, this is a balanced binary tree.

Example 2
Input:



Output: false

Explanation: The subtrees of the node labelled 3 has a height difference of 2, so it is not balanced.
*/

/*
-------------------------    My Approaches:
1. DFS

    we can use the dfs approach in order to solve this problem. the base condition here will be an a null node. we return 0 for the depth if we are at the nullnode.
    then at each subtree node, we check if the tree is balanced. if it sis, we return the height for that subtree. else we return -1 upwards.

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


int checkBalanced(Node<int>* tree){
    if(!tree)
        return 0;
    
    int leftBalanced = checkBalanced(tree->left);
    int rightBalanced = checkBalanced(tree->right);
    
    if(leftBalanced < 0 || rightBalanced < 0 || std::abs(leftBalanced-rightBalanced) > 1)
        return -1;
    return std::max(leftBalanced, rightBalanced)+1;
}


bool is_balanced(Node<int>* tree) {
    // WRITE YOUR BRILLIANT CODE HERE
    int value = checkBalanced(tree);
    if(value == -1)
        return false;
    return true;
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
    std::vector<std::string> tree_vec = get_words<std::string>();
    auto tree_it = tree_vec.begin();
    Node<int>* tree = build_tree<int>(tree_it, [](auto s) { return std::stoi(s); });
    bool res = is_balanced(tree);
    std::cout << std::boolalpha << res << '\n';
}



//  Other Approaches(1)
