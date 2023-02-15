/*
Problem statement:

Lowest common ancestor (LCA) of two nodes v and w in a tree is the lowest (i.e. deepest) node that has both v and w as descendants. We also define each node to be a descendant of itself (so if v has a direct connection from w, w is the lowest common ancestor).

Given two nodes of a binary tree, find their lowest common ancestor.
*/

/*
-------------------------    My Approaches:
1. DFS + chocies

    We can use DFS in order to solve the propblem. we use the decision making process as shown in the figure.
    at any node, we want o make a few checks. we want to check the left if we have seen one of the nodes.
    we also want to check on the right if we have seen one of the nodes. finally, we want to check if the current node is itself the nodes we are looking for.
    [there is a speical case when node1==node2 and the node we are looking for is the current node we ware at, thus we increment by 1].
    As long as any two of these conditions are satisfied, we have found the solution we are looking for.
    this is because, only for the LCA node will we have a count of 2, since either we found on the left or the right or it is itslef ht enode.
    every other node after and before it will have atmost count 1.

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

bool getLca(Node<int>* root, Node<int>* & node1, Node<int>* & node2, Node<int>* & result){
    if(!root)
        return false;
    else{
        int count = 0;
        bool left = getLca(root->left, node1, node2, result);
        bool right = getLca(root->right, node1, node2, result);
        bool curr = (root==node1 || root==node2);
        
        if(left)
            ++count;
        if(right)
            ++count;
        if(curr){
            ++count;
            if(node1 == node2)
                ++count;
        }
            
        
        if(count == 2)
            result = root;
        return left || right || curr;
    }
}

Node<int>* lca(Node<int>* root, Node<int>* node1, Node<int>* node2) {
    // WRITE YOUR BRILLIANT CODE HERE
    Node<int> * result = nullptr;
    getLca(root, node1, node2, result);
    return result;
}

template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;
    ++it;
    if (val == "x") return nullptr;
    Node<T>* left = build_tree<T>(it, f);
    Node<T>* right = build_tree<T>(it, f);
    return new Node<T>{f(val), left, right};
}

Node<int>* find_node(Node<int>* root, int target) {
    if (root == nullptr || root->val == target) return root;
    Node<int>* left_search = find_node(root->left, target);
    if (left_search != nullptr) {
        return left_search;
    }
    return find_node(root->right, target);
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

int main() {
    std::vector<std::string> tree_vec = get_words<std::string>();
    auto tree_it = tree_vec.begin();
    Node<int>* root = build_tree<int>(tree_it, [](auto s) { return std::stoi(s); });
    int target;
    std::cin >> target;
    ignore_line();
    Node<int>* node1 = find_node(root, target);
    std::cin >> target;
    ignore_line();
    Node<int>* node2 = find_node(root, target);
    Node<int>* res = lca(root, node1, node2);
    if (res == nullptr) {
        std::cout << "null" << '\n';
    } else {
        std::cout << res->val << '\n';
    }
}



//  Other Approaches(1)
