/*
Problem statement:


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
topological ordering is an ordering of nodes such that every node appears in the ordering before all the nodes it points to. in this problem,
we are given the nodes and their relative ordering from the seqs. we can try to construct a topolgical ordering and see if its the same as original.

building the graph

we are not given a graph but we can build a graph from the given sequences by using paris in the sequence as edges.
for example, [1,2,3] means we have edges 1->2 and 2->3. we can use set in the graph represnetation here to store neighbors
because there might be repeated eges fromt he sequences.

uniqueness

we can use kahn's algorithm to reconstruct toplogical ordering. kahn's algorithm is analgous BFS; we keep the nodes with no 
parents in a queue, pop top of the queue, subtract 1 from parent count for all nodes it points to and then push
any new nodes that have 0 parent count into the queue. the key to determine uiniqieuness is checking the number of nodes
in the quueu at each step. if there is more than one node in the queue, we can pop any of them and still obtain a valid
ordering and that means tere will be more than one way to reconstruct he oroiginal sequence and therefore not queie.

    Time complexity: O(n+m)
    Space complexity: O()

Additional notes:

comparing my approach to the actual solution, as always, we were on the right path to the solution.
while it definitely took us a lot more time to figure out the problem, we were on the right path to figurign otu the solution.
while the actual solution used a set as part of the graph, we used a set instad which was ok in order to constrct the graph.
as a resu,lt, we had constructed the graph in the right manner which allowed us to understand
that if we have mroe than 2 nodes in the solution, then it would not be a unique solution and 
hence it would be false. however, we didnt fully have confidence in ourself to go down the apth

every time i think i dont have an idea to solve the rpoblem, i have always been on thr right path to fiuring out the solution. we just need to trust in our ability and have confidence in our skills 
which we have worked on in order to get us there.
*/



//  My approaches(1) [not fully implemented]
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_map>

typedef std::unordered_map<int, std::vector<int>> map1;


void createGraph(std::vector<std::vector<int>> & seqs, map1 & elementMap){
    for(int i=0; i< seqs.size(); i++){
        std::vector<int> currSequence = seqs[i];
        if(currSequence.size() > 1){
            for(int j=0; j < currSequence.size()-1; j++){
                if(elementMap.find(currSequence[j]) == elementMap.end()){
                    std::vector<int> list;
                    elementMap[currSequence[j]] = list;
                }
                elementMap[currSequence[j]].push_back(currSequence[j+1]);
            }
        }
    }
}

/*
void printGraph(map1 & elementMap){
    for(auto it = elementMap.begin(); it!= elementMap.end(); it++){
        std::cout<<"Element "<< it->first<<" :";
        std::vector<int> list = it->second;
        for(int i=0; i< list.size(); i++){
            std::cout<<list[i]<<" ";
        }
        std::cout<<std::endl;
    }
}
*/


bool sequence_reconstruction(std::vector<int> original, std::vector<std::vector<int>> seqs) {
    // WRITE YOUR BRILLIANT CODE HERE
    map1 elementMap;
    createGraph(seqs, elementMap);
    return false;
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
    std::vector<int> original = get_words<int>();
    int seqs_length;
    std::cin >> seqs_length;
    ignore_line();
    std::vector<std::vector<int>> seqs;
    for (int i = 0; i < seqs_length; i++) {
        seqs.emplace_back(get_words<int>());
    }
    bool res = sequence_reconstruction(original, seqs);
    std::cout << std::boolalpha << res << '\n';
}




//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <queue> // queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <vector> // vector

std::unordered_map<int, int> count_parents(std::unordered_map<int, std::unordered_set<int>> graph) {
    std::unordered_map<int, int> counts;
    for (auto entry : graph) {
        counts[entry.first] = 0;
    }
    for (auto entry : graph) {
        for (auto node : entry.second) {
            counts[node] += 1;
        }
    }
    return counts;
}

bool topo_sort(std::unordered_map<int, std::unordered_set<int>> graph, std::vector<int> original) {
    std::vector<int> reconstructed;
    std::queue<int> q;
    std::unordered_map<int, int> counts = count_parents(graph);
    for (auto entry : counts) {
        if (entry.second == 0) q.push(entry.first);
    }
    while (q.size() > 0) {
        // if there's > 1 node in the queue, the reconstruction is not unique
        if (q.size() > 1) return false;
        int node = q.front();
        reconstructed.emplace_back(node);
        for (int child : graph[node]) {
            counts[child] -= 1;
            if (counts[child] == 0) q.push(child);
        }
        q.pop();
    }
    // check if sequence is the same as original sequence
    return original == reconstructed;
}

bool sequence_reconstruction(std::vector<int> original, std::vector<std::vector<int>> seqs) {
    int n = original.size();
    // using set here due to possibility of repeated sequences
    std::unordered_map<int, std::unordered_set<int>> graph;
    for (int i = 1; i <= n; i++) {
        graph[i] = std::unordered_set<int>();
    }
    for (std::vector<int> seq : seqs) {
        for (int i = 0; i < seq.size() - 1; i++) {
            int early_num = seq[i], late_num = seq[i + 1];
            if (!graph[early_num].count(late_num)) {
                graph[early_num].emplace(late_num);
            }
        }
    }
    return topo_sort(graph, original);
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
    std::vector<int> original = get_words<int>();
    int seqs_length;
    std::cin >> seqs_length;
    ignore_line();
    std::vector<std::vector<int>> seqs;
    for (int i = 0; i < seqs_length; i++) {
        seqs.emplace_back(get_words<int>());
    }
    bool res = sequence_reconstruction(original, seqs);
    std::cout << std::boolalpha << res << '\n';