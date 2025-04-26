/*
Problem statement:

Given two arrays representing the preorder and inorder traversals of the same binary tree consisting of unique values, construct the original tree.

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7].

Output: The binary tree structure:

    3
   / \
  9   20
     /  \
    15   7
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
    Intuition

    lets review how preorder and inorder traversals work

    preorder traversal: visit the current node first, then the ;left subtree, and finally the right subtree. to solve this
    problem, we need to use the unique properties oif preorder and inorder traversals:
        1. in a preorder traversal, th first element is always the root of the tree
        2. in an inorder traversal, the elements to the left of the root are in the left subtree, and the elements to the right of the root are in the right subtree.

    using these properties, we can:
        1. identify the root of the tree from the preorder traversal
        2. find the index of the root in the inorder traversal to determine the left and right subtrees
        3. recursively build the left and right subtrees using thhe corresponding portions of both arrays

    this approach allows us to reconstruct the entire tree by diving it into smaller subproblems.


    Explanation:

    the key approach is to use the proder array to identiyf the root and the inorder array to indentify the left and right subtrees.

    the elements in the tree are unique, so we can construct a mapping from the value to the index in the inorder array.

    in the given preorder array, the first element represents the root of the binary tree. using its value, its index can be located in the 
    inorder array. the elments to the left of this iondex in the inorer array represent the elft subtree and the elements to the right represnet the right subtree. the same steps
    are then repeated for the left and right subtrees repsectively (recursievely).

    Lets break down the steps:
    1. create a value to index map for inorder traversal: we create a dictionary to store the index of each value in the
    inorder traversal. this allows us to quickly find the position of the rott in the inorder array, which iscrucial for determining the sizes of left and right subtrees.
    2. define a recursive helper function: we create a helper function that takes the following parameters:
        - preorder_start and preorder_end: the range of indices in the preorder array were currently considering
        - inorder_start and inorder_end: the range of indices in the inorder array were currently considering
    3. base case: if the start index is greater than the end index for either array, we return None, as this represents and empty subtree.
    4. Identify the root: the first element in the current preorder range is always the root of the current subtree
    5. find the root in inorder traversal: use the value-to-index map to quickly locate the toor's position in the inorder array.
    6. cal;culate sizes of left and right subtrees: the number of elements to the left of the root in the inorder array is the size of the elft
    subtree. the remaining element sform the right subtree. 

    recursively construct left and right subtrees: 
        1. for the left subtree, use ehte left portion of both preorder and inorder arrays. 
        2. for the right subtree, use the right eportion of both preorder and inorder arrays. 

    return the constructed node: create a new TreeNode with the root value and attach the left and right subtrees. 

    This recurisve appraioch efficiently treconstructs the binary tree by diviing the problem inot smaller subproblems for each subtree. the use 
    of the value-to-index map allows for O(1) lookiup of root poisitions in the inorder array, resulting in an overall time complexity of O(n).where n
    is the no of nodes in the tree. 



    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_map>
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

Node<int>* build_tree_recursive(std::vector<int>& preorder, std::unordered_map<int, int>& valueToIndex, int preStart, int inStart, int size) {
    if (size <= 0) return nullptr;

    int rootValue = preorder[preStart];
    int inorderIndex = valueToIndex[rootValue];
    int leftSize = inorderIndex - inStart;

    Node<int>* left = build_tree_recursive(preorder, valueToIndex, preStart + 1, inStart, leftSize);
    Node<int>* right = build_tree_recursive(preorder, valueToIndex, preStart + 1 + leftSize, inorderIndex + 1, size - 1 - leftSize);

    return new Node<int>(rootValue, left, right);
}

Node<int>* construct_binary_tree(std::vector<int>& preorder, std::vector<int>& inorder) {
    std::unordered_map<int, int> valueToIndex;
    for (int i = 0; i < inorder.size(); ++i) {
        valueToIndex[inorder[i]] = i;
    }

    return build_tree_recursive(preorder, valueToIndex, 0, 0, preorder.size());
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
    std::vector<int> preorder = get_words<int>();
    std::vector<int> inorder = get_words<int>();
    Node<int>* res = construct_binary_tree(preorder, inorder);
    std::vector<std::string> res_vec;
    format_tree(res, [](auto v) { return std::to_string(v); }, res_vec);
    put_words(res_vec);
}