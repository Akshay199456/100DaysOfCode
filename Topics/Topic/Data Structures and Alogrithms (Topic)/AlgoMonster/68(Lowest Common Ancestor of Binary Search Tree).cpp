/*
Problem statement:

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Input
bst: a binary tree representing the existing BST.
p: the value of node p as described in the question
q: the value of node q as described in the question
Output
The value of the LCA between nodes p and q

Examples
Example 1:
Input:

bst = [6,2,8,0,4,7,9,x,x,3,5]
p = 2
q = 8
Output: 6

Explanation:


The ancestors of node p with value 2 are node 2 and node 6. The ancestors of node q with value 8 are node 8 and node 6.

The lowest common ancestors between these two nodes is 6.
*/

/*
-------------------------    My Approaches:
1. DFS + BST

    We can use the DFS approach in order to solve this problem. since he poblem is a bst, we can divide this approach into two steps.
    first step is to get the path for each value. since it is a bst, we can accomplish this in O(h) time which in the worst case would be O(n) time.
    Once wwe get hte path for each node, the second path si to compare the two paths from the eginning.
    the point at which the two lists deviate from each other is the lowest common ancestor. this is because, since it is a bst, we can easily get the path through making comparision with the root value.
    this path will be unique for that node.. so when we get the interesection of the tw nodes, the point at which they deviate will be the answer.    


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
#include <iostream> // boolalpha, cin, cout, streamsize
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


bool getPath(Node<int>* bst, int val, std::vector<int> & list){
    if(!bst)
        return false;
    else{
        list.push_back(bst->val);
        if(bst->val == val)
            return true;
        else if(val < bst->val)
            return getPath(bst->left, val, list);
        else
            return getPath(bst->right, val, list);
    } 
}


void printPath(std::vector<int> & list){
    std::cout<<"printing list: "<<std::endl;
    for(int i=0; i<list.size(); i++){
        std::cout<<list[i]<<" ";
    }
    std::cout<<std::endl;
}


int findLowestAncestor(std::vector<int> & pList, std::vector<int> & qList){
    int index = 0, lowestAncestor = 0;
    while(index < pList.size() && index < qList.size()){
        if(pList[index] == qList[index]){
            lowestAncestor = pList[index];
            index++;
        }
        else
            return lowestAncestor;
    }
    return lowestAncestor;
}

int lca_on_bst(Node<int>* bst, int p, int q) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(!bst)
        return 0;
    std::vector<int> pList;
    std::vector<int> qList;
    
    bool pFound = getPath(bst, p, pList);
    bool qFound = getPath(bst, q, qList);
    
//     printPath(pList);
//     printPath(qList);
    
    if(!pFound || !qFound)
        return 0;
    return findLowestAncestor(pList, qList);
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

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<std::string> bst_vec = get_words<std::string>();
    auto bst_it = bst_vec.begin();
    Node<int>* bst = build_tree<int>(bst_it, [](auto s) { return std::stoi(s); });
    int p;
    std::cin >> p;
    ignore_line();
    int q;
    std::cin >> q;
    ignore_line();
    int res = lca_on_bst(bst, p, q);
    std::cout << res << '\n';
}




//  Other Approaches(1)
