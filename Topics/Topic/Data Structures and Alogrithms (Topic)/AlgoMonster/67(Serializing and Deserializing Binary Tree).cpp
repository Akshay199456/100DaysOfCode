/*
Problem statement:

Given a binary tree, write a serialize function that converts the tree into a string and a deserialize function that converts a string to a binary tree. You may serialize the tree into any string representation you want as long as it can be deseralized.
*/

/*
-------------------------    My Approaches:
1. Using stack

    we can use stack  in oder to solv thtis problem. we use the pre-order tehcnique in order to serialize the tree and for every
    null node we encounter, we replace it with 'x' while serializing.

    while deserializing, whenever we encounter an x, we know it is a null node. so if the node before it was on
    the left path, we switch it to the right oath. if it was on the right path, then we conintue to remove nodes till all the 
    right path nodes re removed.

    Time complexity: O(n) 
    Space complexity: O(n)

    for both serializing and deserrilaizing

*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
To serialize, we can simply do a DFS and append the node value to the string. we need to encode null nodes too since otherwise,
we wouldt be able to tell if we have reached leaf nodes when we deserlaize. we use 'x' here as placeholder for the null node.

to deserialize, we split the string into tokens and consume them. for each tpklen,w e create a new node using the token valu.
when we see an x, we know we reached the leaf and return.

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, stoi, string, to_string
#include <vector> // vector
#include <stack>
#include <tuple>

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

void serialize_helper(Node<int>* root, std::string & output){
    if(!root){
        output += "x";
    }
    else{
        output += std::to_string(root->val);
        output += "@";        
        serialize_helper(root->left, output);
        serialize_helper(root->right, output);
    }
}

std::string serialize(Node<int>* root) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::string output;
    serialize_helper(root, output);
    return output;
}


Node<int>* deserialize_helper(std::string & root, int index){
    // doing preorder
    std::stack<std::tuple<Node<int>*, char>> elementStack;
    Node<int>* treeRoot = nullptr;
    
    while(index < root.size()){
        if (root[index] == 'x'){
            // get top of stack
            std::tuple<Node<int>*, char> topPair = elementStack.top();
            
            // if L, 
            if(std::get<1>(topPair) == 'L'){
                // change it to R
                elementStack.pop();
                std::tuple tuplePair = std::make_tuple(std::get<0>(topPair), 'R');
                elementStack.push(tuplePair);
            }
            //if R, 
            else{
                while(elementStack.size()>1 && (std::get<1>(topPair) == 'R')){
                    // pop all Rs
                    elementStack.pop();
                    std::tuple<Node<int>*, char> newTop = elementStack.top();
                    if(std::get<1>(newTop) == 'L')
                        std::get<0>(newTop)->left = std::get<0>(topPair);
                    else
                        std::get<0>(newTop)->right = std::get<0>(topPair);
                    
                    // change topPair
                    topPair = newTop;
                }
                
                // change L to R
                std::tuple<Node<int>*, char> latestTop = elementStack.top();
                elementStack.pop();
                std::tuple tuplePair = std::make_tuple(std::get<0>(latestTop), 'R');
                elementStack.push(tuplePair);   
            }
            
            // push index forward
            index++;
            
            
        }
        else{
            // get the value in string format
            std::string stringValue;
            while(root[index] != '@'){
                stringValue += root[index++];
            }
            
            //std::cout<<"String value: "<<stringValue<<std::endl;
            
            // get the integer value
            int value = std::stoi(stringValue);
            //push index forward to skip '@'
            index++;
            
            // create node for value
            Node<int>* tempRoot = new Node<int>(value);
            if(!treeRoot){
                //std::cout<<"Tree root value: "<<tempRoot->val<<std::endl;
                treeRoot = tempRoot;
            }
    
            // add value to stack
            std::tuple tuplePair = std::make_tuple(tempRoot, 'L');
            elementStack.push(tuplePair);
        }
    }
    return treeRoot;
}


Node<int>* deserialize(std::string root) {
    // AND HERE
    //std::cout<<"Deserializing: "<<root<<std::endl;
    if(root == "x")
        return nullptr;
    return deserialize_helper(root, 0);
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
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
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
    std::vector<std::string> tree_vec = get_words<std::string>();
    auto tree_it = tree_vec.begin();
    Node<int>* tree = build_tree<int>(tree_it, [](auto s) { return std::stoi(s); });
    Node<int>* res = deserialize(serialize(tree));
    std::vector<std::string> res_vec;
    format_tree(res, [](auto v) { return std::to_string(v); }, res_vec);
    put_words(res_vec);
}





//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
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

void serialize_dfs(Node<int>* root, std::vector<std::string>& res) {
    if (root == nullptr) {
        res.emplace_back("x");
        return;
    }
    res.emplace_back(std::to_string(root->val));
    serialize_dfs(root->left, res);
    serialize_dfs(root->right, res);
}

std::string serialize(Node<int>* root) {
    std::vector<std::string> res;
    serialize_dfs(root, res);
    std::stringstream ss;
    std::copy(res.begin(), res.end(), std::ostream_iterator<std::string>(ss, " "));
    return ss.str();
}

Node<int>* deserialize_dfs(std::vector<std::string>::iterator& nodes) {
    std::string val = *nodes;
    ++nodes;
    if (val == "x") return nullptr;
    Node<int>* cur = new Node<int>(std::stoi(val));
    cur->left = deserialize_dfs(nodes);
    cur->right = deserialize_dfs(nodes);
    return cur;
}

Node<int>* deserialize(std::string root) {
    std::istringstream ss(root);
    std::vector<std::string> nodes;
    std::copy(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>(), std::back_inserter(nodes));
    auto nodes_iter = nodes.begin();

    return deserialize_dfs(nodes_iter);
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
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
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
    std::vector<std::string> tree_vec = get_words<std::string>();
    auto tree_it = tree_vec.begin();
    Node<int>* tree = build_tree<int>(tree_it, [](auto s) { return std::stoi(s); });
    Node<int>* res = deserialize(serialize(tree));
    std::vector<std::string> res_vec;
    format_tree(res, [](auto v) { return std::to_string(v); }, res_vec);
    put_words(res_vec);
}