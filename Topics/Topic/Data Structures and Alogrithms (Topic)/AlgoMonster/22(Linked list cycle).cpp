/*
Problem statement:

Given a linked list with potentially a loop, determine whether the linked list from the first node contains a cycle in it. For bonus points, do this with constant space.

Parameters
nodes: The first node of a linked list with potentially a loop.
Result
Whether there is a loop contained in the linked list.
Examples
Example 1
Input:



Output:

true

Example 2
Input:



Output:

false

Constraints
1 <= len(nodes) <= 10^5
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
if linked list has no loop, then we we iteratie through the list, we will eventually reach the end of the list, at which point, we can
simply reurn. however, the hcallenge is figurng out how to terminate the program if it finds a loop.
otherwise the program would go on forever.

a simple sooltion would be to use a set to store the information. we store all the nodes we have been through and check if we have been threere each time
we move. however, a set is not constant memeoru and there might be issues with hashing and whatnot. clearly, ther 's a ebtter way

introducing floy's cycle finding algorith, also known as the tortiose and hare algorith,. the idesa is to have tow pointer,
the fast pointer(or 'hare') move at double sleed of the slow pointer(or tortise). each ccycle, the tortoise moves once and the hare moves twice. the idea is that since that the cycle
must have interger size, when the tortise and the hare are both int he cucle, their distance difference must also be an integer.
then, each cycle, because of their speed difference, the distance between them constantly reduces untul they meet, in which case we know there is a ccle.
however, if there is no cycle, they will never meet because the speed of the hare is always fsater



    Time complexity: O(n)
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
template <typename T>
struct Node {
    T val;
    Node<T>* next;

    explicit Node(T val, Node<T>* next = nullptr)
        : val{val}, next{next} {}

    ~Node() {
        delete next;
    }
};

Node<int>* next_node(Node<int>* node) {
    if (node->next == NULL) {
        return node;
    }
    return node->next;
}

bool has_cycle(Node<int>* nodes) {
    Node<int>* tortoise = next_node(nodes);
    Node<int>* hare = next_node(next_node(nodes));
    while (tortoise != hare && hare->next != NULL) {
        tortoise = next_node(tortoise);
        hare = next_node(next_node(hare));
    }
    return hare->next != NULL;
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
    std::vector<int> rawInput = get_words<int>();
    std::vector<Node<int>*> nodeList;
    for (int i = 0; i < rawInput.size(); i++) {
        nodeList.push_back(new Node<int>(i));
    }
    for (int i = 0; i < rawInput.size(); i++) {
        if (rawInput[i] != -1) {
            nodeList[i]->next = nodeList[rawInput[i]];
        }
    }
    Node<int>* nodes = nodeList[0];
    bool res = has_cycle(nodes);
    std::cout << std::boolalpha << res << '\n';
}
