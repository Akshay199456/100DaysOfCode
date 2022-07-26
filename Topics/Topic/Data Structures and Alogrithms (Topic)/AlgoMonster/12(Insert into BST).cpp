/*
Problem statement:

iven the root node of a valid BST and a value to insert into the tree, return a new root node representing the valid BST with the addition of the new item. If the new item already exists in the binary search tree, do not insert anything.

You must expand on the original BST by adding a leaf node. Do not change the structure of the original BST.

Input
bst: a binary tree representing the existing BST.
val: an integer representing the value to be inserted.
Output
A valid BST with the inserted number, or the same BST if the number already exists.

Examples
Example 1:
Input:

tree = <See explanation>
val = 7
Output: <See explanation>

Explanation:

Before insertion:



After insertion:


*/

/*
-------------------------    My Approaches:
1. DFS

    we can plly the DFS approach to solve this problem. the base conditon is when we hit an
    empty node. when we do, that means we should be inserting the new node at that point. otherwise, depening on the direction and the val,
    we mvoe that paritcualr directions

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
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, stoi, string, to_string
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

void insertValue(Node<int>* bst, int val, Node<int>* parent){
    if(bst && bst->val != val){
        if(val < bst->val)
            insertValue(bst->left, val, bst);
        else 
            insertValue(bst->right, val, bst);
    }
    else if(!bst){
        Node<int> * newNode = new Node(val);
        if(val > parent->val)
            parent->right = newNode;
        else
            parent->left = newNode;
    }
}


Node<int>* insert_bst(Node<int>* bst, int val) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(!bst){
        Node<int> * newNode = new Node(val);
        return newNode;
    }
    
    insertValue(bst, val, bst);
    return bst;
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

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T, typename F>
void format_tree(Node<T>* node, F f, std::vector<std::string>& out) {
    if (node == nullptr) {
        out.emplace_back("x");
        return;
    }
    out.emplace_back(f(node->val));
    format_tree(node->left, f, out);
    format_tree(node->right, f, out);
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
    int val;
    std::cin >> val;
    ignore_line();
    Node<int>* res = insert_bst(bst, val);
    std::vector<std::string> res_vec;
    format_tree(res, [](auto v) { return std::to_string(v); }, res_vec);
    put_words(res_vec);
}



//  Other Approaches(1)
