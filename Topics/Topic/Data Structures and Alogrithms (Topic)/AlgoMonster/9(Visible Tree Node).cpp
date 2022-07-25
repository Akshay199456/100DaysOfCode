/*
Problem statement:

n a binary tree, we define a node "visible" when no node on the root-to-itself path (inclusive) has a greater value. The root is always "visible" since there are no other nodes between the root and itself. Given a binary tree, count the number of "visible" nodes.

Input:


*/

/*
-------------------------    My Approaches:
1. dfs approach

    we can use the dfs approach in order to solve this problem. we know that if we run into a null node, then we should return 0 as a null node cant be a visible node.
    the other thing we want to check is if the current node is the nax value that we have seen in this path till now.
    if it is, then it is a visible node and so we increment that count. we can then go to the left and right nodes and make the same decision by passing in the max value that we ahve seen till now

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
we can dfs on the tree and keep track of the max value we have seen as we go.

1. decide on the return value
    the problem asks for the total no of visible nodes so we return the total no of visisible nodes for the current subtree after we visit a node

2. identify states
    the definition for a 'visible' node is its value is greater than any other node's value on the root-to-itself path. to determine whether the current node is visilbe or not, we need to lknow
    the max value from the root to it. we can carry this as a state as we traverse down the tree.

having decided on the state and return value, we can now write the dfs

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

int getCount(Node<int> * root, int maxValue){
    if(!root)
        return 0;
    
    maxValue = std::max(maxValue, root->val);
    int totalCount = getCount(root->left, maxValue) + getCount(root->right, maxValue);
    
    if(root->val >= maxValue)
        totalCount +=1;
    return totalCount;
}

int visible_tree_node(Node<int>* root) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(!root)
        return 0;
    return getCount(root, root->val);
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
    int res = visible_tree_node(root);
    std::cout << res << '\n';
}



//  Other Approaches(1)
include <algorithm> // copy
#include <iostream> // cin, cout
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

int dfs(Node<int>* root, int max_sofar) {
    if (!root) return 0;
    int total = 0;
    if (root->val >= max_sofar) total++;
    total += dfs(root->left, std::max(max_sofar, root->val));
    total += dfs(root->right, std::max(max_sofar, root->val));
    return total;
}

int visible_tree_node(Node<int>* root) {
    // start max_sofar with smallest number possible so any value root has is greater than it
    return dfs(root, std::numeric_limits<int>::min());
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
    int res = visible_tree_node(root);
    std::cout << res << '\n';
}