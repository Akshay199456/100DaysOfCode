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

2. Same as Other Approaches(1)
    we just wanted to make sure we understood the approach that was provided in Other Approaches(1). as a result, worte down the code
    to comfinrm we understood the logic
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
the idea behind this problem is to use the property of binary search trees

as a quick recap, a BST is a type of binary tree where for any given node with value a, the values in its left subtree
are all less than a and the values in its right subtree are all greater than a.

the tree on the left is a VST because every node holds this property whereas the right tree is not a BST because there is a 2 on the right subtree of the node
with value 3. since 2 < 3, the property that the values on the rightide is greater than the current node does not hold


original problerm

Trees are naturally recurisve data structures and as such we will use recursion to find our answer. for binary search trees, specifically, we often break down each recursive call into
cases. the reason we do this is because for every node we can decide whether to traverse down the left subtree or right substree based on the value of the
current node.

to find the lowest common ancestor of two nodes in a BST, we break our search into 3 common cases:
1. if nodes p and q are on the left of the current node, the continue search the left side
2. if nodes p and q are the right of the current node, then continue search the right side
3. f nodes p and q are split (one is on the left, the other is on the right), then we can return the current node
as the LCA.

Note that there is a special case when either p == cur.val or q == curr.val, since we have definted that a node can be its
own descendatnt, this falls in case 3.



    Time complexity: O(h)
        since we dont need to traverse the entire tree for our search and on each level, we only visit a single node, the final time
        complexity is O(h) wwhere h is the height of the tree. in the worst case, the tree is not balanced and h is n.
    Space complexity: O()
        if we count stack memory as space usage, then our space complexity is O(h) where h is the height of the tree because in the worst case
        we have a line graph where nodes p and q are at thje end, which leads to O(n) stack memory
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



// My Approaches(2)
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

int lca_on_bst(Node<int>* bst, int p, int q) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(p<bst->val && q<bst->val)
        return lca_on_bst(bst->left,p,q);
    else if(p>bst->val && q>bst->val)
        return lca_on_bst(bst->right,p,q);
    else
        return bst->val;
    
    return 0;
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

int lca_on_bst(Node<int>* bst, int p, int q) {
    if (p < bst->val &&  q < bst->val) {
        return lca_on_bst(bst->left, p, q);
    } else if (p > bst->val && q > bst->val) {
        return lca_on_bst(bst->right, p, q);
    } else {
        return bst->val;
    }
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