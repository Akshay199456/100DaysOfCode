/*
Problem statement:

Note that this problem requires knowing heap, which is covered in the Priority Queue/Heap section. If you are working through the content in order, feel free to skip this problem and come back after you have completed the heap section.

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you.

You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language.

Derive the order of letters in this language.

Note:

You may assume all letters are in lowercase.
Every letter that appears in the input must also appear in the output, and your output cannot have characters not in the input.
If no ordering of letters makes the dictionary sorted lexicographically, return an empty string.
There may be multiple valid orders. If that's the case, return the smallest in normal lexicographical order.
Input
words: A list of strings of size n, representing the dictionary words sorted lexicographically in the alien language.
Output
A string representing the smallest possible lexicographical order, or an empty string if no valid order exists.

Examples
Example 1:
Input:

words = ["wrt","wrf","er","ett","rftt"]
Output: wertf

Explanation:



Example 2:
Input:

words = ["z","x"]
Output: zx

Explanation:

From z and x，we can get z < x. So return zx.

Constraints
2 <= n <= 10000
1 <= words[i] <= 30
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
since words are given in lexicographical order in the alien language, you can use it t deduce the ordering of letters in that language.
because a lexicogrpahical order is a total ordering, regardlesss of the ordering of the letters, we only need to consider words adjacent to each other.

for each adjacent words, we compare each character of the string until we find a different character. then, we can decude that the character fromt he first
string is lexicographciallyt smaller than the character from the second string. after parsing throug all the strings, we get a directed graph that we can perform a standard topological sort
on using our kahn's algorithm template. keep in mind instead of using a regfular queue, we need to use a heap to guarantee the smallest ordering to satisfy requireemnt 4 in the problem statement.

    Time complexity: O(w*n)
        assume that the strings are at most sie w, each string comparison is bounded by O(w). Let L represent the letters that
        appeared in the input, we can extract |L| nodes and at most n edges from words in O(w*n) time. To obtain the 
        topological sort of the graph, it takes O(|L|+n) time. in total, the time complexity is O(w*n) as we know that |L|
        us actually bounded by the constant 26.
    Space complexity: O(n)
        since we know that the graph has |L| nodes and at most n edges, the size of the graph is bounded by O(n). the heap (output)
        will contain |L| elements. therefore, the overall space complexity is O(n)


Additional notes:

we had deduced the ordering. i knew we had to cpompare the adjacent strings for this problem in order to determine the logival ordering of the characters.
however, the part i didn't know was how to use the heap in this problem.

also, tbf this was a easy problem which i should have been able to solve it easily. for these kind of rpoblems, the bggest trouble i seem to have is in actual construction of the graph
itself or hot of abide by the additional conditions specificed. once you know how to construct the graph, the topological osrt algoirthm is pretty standard to gethte right ordering necessary.
in this problem coindition 4 mentioned to return the smalles t in normal lexicographical order. that was something i didn not read correctly. that is why thye use a min heap to get the smaller character of there are multiple solutions which makes
sense. for this problems, i just need to get better at learnign to create grpah that abides by the conditions. the rest of the stuff is pretty simple and is something i know.
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <queue> // priority_queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <vector> // vector

template <typename T> std::unordered_map<T, int> count_parents(std::unordered_map<T, std::vector<T>> graph) {
    std::unordered_map<T, int> counts;
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

std::vector<char> topo_sort(std::unordered_map<char, std::vector<char>> graph) {
    std::vector<char> res;
    std::priority_queue<char, std::vector<char>, std::greater<char>> q;
    std::unordered_map<char, int> counts = count_parents(graph);
    for (auto entry : counts) {
        if (entry.second == 0) q.push(entry.first);
    }
    while (q.size() > 0) {
        char node = q.top();
        q.pop();
        res.emplace_back(node);
        for (char child : graph[node]) {
            counts[child] -= 1;
            if (counts[child] == 0) q.push(child);
        }
    }
    
    for (auto entry : counts) {
        if (entry.second != 0) return std::vector<char>();
    }
    return res;
}

std::string alien_order(std::vector<std::string> words) {
    std::unordered_map<char, std::vector<char>> graph;
    for (std::string word : words) {
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!graph.count(c)) {
                graph[c] = std::vector<char>();
            }
        }
    }
    std::string prev = words[0];
    // derive order from adjacent words
    for (int i = 1; i < words.size(); i++) {
        std::string cur = words[i];
        for (int j = 0; j < prev.size() && j < cur.size(); j++) {
            //ignore duplicates
            if (prev[j] != cur[j]) {
                std::vector<char> list = graph[prev[j]];
                if (std::find(list.begin(), list.end(), cur[j]) == list.end()) {
                    graph[prev[j]].emplace_back(cur[j]);
                }
                break;
            }
        }
        prev = cur;
    }

    std::vector<char> sorted = topo_sort(graph);
    if (sorted.size() > 0) {
        std::string s(sorted.begin(), sorted.end());
        return s;
    }
    return "";
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
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
    std::vector<std::string> words = get_words<std::string>();
    std::string res = alien_order(words);
    std::cout << res << '\n';
}