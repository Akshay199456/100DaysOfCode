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
Intuituion

if we could work from target nodes and push some information upwards that lets us find the LCA

sadly this is impossible as we would need to know exactly where node1 and node2 are. additionally, each node in the binary
tree would need a reference to their parent node in order to find the common ancestors of both nodes


solution

we can however, mimich this idea usinng DFS. Specifically, we will use a postorder traversal method because it will go all the way down from the root to the leaf
nodes and work its way back back up root again.

how can we use postorder DFS traversal to help us? once we finish prcoessing a node x and return to its parent node, we will consider a few cases:

1. thhe node-x is null
2. the node-x is either node1 or node2
3. the node-x is neither node1 nore node2.

the first two cases (1) and (2) are simple and we can ismply return themselves immediately. that is, if the current node is null, return null; and if the current node is either
node1 or node2, immediately return node1 or node2 (whichever it is). we will see later why we can do this.

case (3) is trickier in that it also involves some case work due to it getting returned values from both its subtrees.these are the cases and their respective beahviors:"
1. if both subtrees return non-null nodes: return the current node itself
2. if both subtrees return null nodes, retun null
3. if exactly one of the subtrees returns a non-null node and the other returns a null node: return the non-null node


Here;s another example of why we would/could reutn immediately even if one of the target nodes exists in the sibtree of the other


finally here are 5 examples of his LCA algorihtm on a binary tree and the respective return values of each node


    Time complexity: O(n)
        where n is the no of nodes in the tree because in the worst case we need to traverse through each and every node
    Space complexity: O()
        the space complexity is O(h) because the stack memory depends on the height of the tree. but, in the worst case, this is O(n).
        a skewed tree such that all ndoes ahve zero or one child has the height O(n)
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

Node<int>* lca(Node<int>* root, Node<int>* node1, Node<int>* node2) {
    if (!root) return nullptr;
    // case 2 in above figure
    if (root == node1 || root == node2) return root;
    Node<int>* left = lca(root->left, node1, node2);
    Node<int>* right = lca(root->right, node1, node2);
    // case 1
    if (left && right) return root;
    // at this point, left and right can't be both non-null since we checked above
    // case 4 and 5, report target node or LCA back to parent
    if (left) return left;
    if (right) return right;

    // case 4, not found return null
    return nullptr;
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