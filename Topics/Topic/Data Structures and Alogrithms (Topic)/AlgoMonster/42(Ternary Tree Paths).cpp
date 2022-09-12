/*
Problem statement:

Given a ternary tree (each node of the tree has at most three children), find all root-to-leaf paths.


*/

/*
-------------------------    My Approaches:
1. Combinatorial search - backtracking

    we can use the backtracking technique to solve this problem. since the problem is asking us for all posssible paths,
    the way wer can do that is by using recursion and backtracking to add each inidividual path into the part of the solution.
    when it is a leaf node we add it inot the result else we continue to add th eelement from each path.

    Time complexity: O(n) where n is the no of nodes in the tree
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
we use path to keep track of the nodes we have visited to reach the current node and use it to construct our solution when we reach leaf noddes.

Additional approach:

in the recursive call in the Other Approaches(1)-1, we create a new list each time we recurse with
path + [root.val]. this is not space efficient because creating a new list requires allocating new spapce in memory and copying over each element. a more efficient 
way is to use a single list path and push and pop fillowign the call stack.

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, stoi, string
#include <utility> // move
#include <vector> // vector

template <typename T>
struct Node {
    T val;
    std::vector<Node<T>*> children;

    explicit Node(T val, std::vector<Node<T>*> children = {})
        : val{val}, children{children} {}
};

void getPaths(Node<int>* root, std::vector<std::string> & result, std::string path){
    if(root){
        bool isLeaf = true;
        std::string stringValue = std::to_string(root->val);
        path += stringValue;
        
        // check if leaf node
        std::vector<Node<int>*> childrenNode = root->children;
        for(int i=0; i < childrenNode.size() && isLeaf; i++){
            if(childrenNode[i])
                isLeaf = false;
        }
        
        if(isLeaf)
            result.push_back(path);
        else{
            for(int i=0; i < childrenNode.size(); i++){
                getPaths(childrenNode[i], result, path + "->");
            }
        }
    }
}


std::vector<std::string> ternary_tree_paths(Node<int>* root) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::string> result;
    std::string path;
    getPaths(root, result, path); 
    return result;
}

// this function build a tree from input
// learn more about how trees are encoded in https://algo.monster/problems/serializing_tree
template<typename T, typename Iter, typename F>
Node<T>* build_tree(Iter& it, F f) {
    std::string val = *it;
    ++it;
    int num = std::stoi(*it);
    ++it;
    std::vector<Node<T>*> children;
    for (int i = 0; i < num; i++)
        children.emplace_back(build_tree<T>(it, f));
    return new Node<T>{f(val), std::move(children)};
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
    std::vector<std::string> res = ternary_tree_paths(root);
    for (const std::string& line : res) {
        std::cout << line << '\n';
    }
}



//  Other Approaches(1)
void dfs(Node<int>* root, std::vector<std::string> path, std::vector<std::string>& res) {
    if (root->children.size() == 0) {
        path.emplace_back(std::to_string(root->val));
        std::string s = "";
        for (int i = 0; i < path.size(); i++) {
            if (i == path.size() - 1) {
                s += path[i];
            } else {
                s += path[i] + "->";
            }
        }
        res.emplace_back(s);
        return;
    }
    for (auto& child: root->children) {
        if (child) {
            std::vector<std::string> path_copy(path);
            path_copy.emplace_back(std::to_string(root->val));
            dfs(child, path_copy, res);
        }
    }
}

std::vector<std::string> ternary_tree_paths(Node<int>* root) {
    std::vector<std::string> res;
    if (root) dfs(root, {}, res);
    return res;
}

// Other Approaches(2)
void dfs(Node<int>* root, std::vector<std::string> path, std::vector<std::string>& res) {
    if (root->children.size() == 0) {
        path.emplace_back(std::to_string(root->val));
        std::string s = "";
        for (int i = 0; i < path.size(); i++) {
            if (i == path.size() - 1) {
                s += path[i];
            } else {
                s += path[i] + "->";
            }
        }
        res.emplace_back(s);
        path.pop_back();
        return;
    }
    for (auto& child: root->children) {
        if (child) {
            std::vector<std::string> path_copy(path);
            path.emplace_back(std::to_string(root->val));
            path_copy.emplace_back(std::to_string(root->val));
            dfs(child, path, res);
            dfs(child, path_copy, res);
            path.pop_back();
        }
    }
}
std::vector<std::string> ternary_tree_paths(Node<int>* root) {
    std::vector<std::string> res;
    if (root) dfs(root, {}, res);
    if (root)  dfs(root, {}, res);
    return res;
}