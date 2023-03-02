/*
Problem statement:

Given a binary tree, return its level order traversal. The input is the root node of the tree. The output should be a list of lists of integers, with the ith list containing the values of nodes on level i, from left to right.

For example:


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
Explanation:
    we can use DFS for this problem by keeping tack of the depth for each node. a better way though is to use VFS since it traverses the tree
    by level by default.

    Applying the template, we use a queue to keep track of nodes to visit next.

    how to get a node's level
        when we dequeue a node from the queue, we need to know the level it sits in the tree to add it to the corresponding level in the result. but nodes in the queue
        do not have any information about level. how do we get a node's level?

        one observation is that queue contains at most two levels of nodes. to see wjhy, lets assume our tree is three-level deep.
        Lets call the nodes of the shallowest level "level 0" nodes and their children "level 1" nodes, whose children are "level 2" nodes. when we do a BFS,
        we first push "level 0" nodes into the queue, and as we process them, we push their children "level 1" nodes into the queue. to get
        :level 2" nodes on the queueue, we have to start dequeuing and processing "level 1" nodes but we can't dequeue any "level 1" nodes until we have finsished dequeueing the processing "level 0" nodes
        since a queueu is a FIFO structure. therefore its imporssible to have 3 levels in the queue at the same time, and we can have at most two levels in the queue

        also observe that we always push the leftmost node of a level intot he queueu first. when we dequeueu the leftmost node (and before we add its children), the queueu contiains only one level of nodes. we can save the no of nodes in the queue ina  variable n,
        and dequeue  the next n nodes


    Time complexity: O(n)
        we traverse every edge and node once but since the no of edges is n-1, this simply becomes O(n)
    Space complexity: O(n)
        there are at most O(n) nodes in the queue
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

std::vector<std::vector<int>> level_order_traversal(Node<int>* root) {
    std::vector<std::vector<int>> res;
    if (root == nullptr) return res;
    std::queue<Node<int>*> level;
    level.push(root);
    while (level.size() > 0) {
        int n = level.size();
        std::vector<int> new_level;
        for (int i = 0; i < n; i++) {
            Node<int>* node = level.front();
            new_level.emplace_back(node->val);
            if (node->left) level.push(node->left);
            if (node->right) level.push(node->right);
            level.pop();
        }
        res.emplace_back(new_level);
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
    std::vector<std::vector<int>> res = level_order_traversal(root);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}
