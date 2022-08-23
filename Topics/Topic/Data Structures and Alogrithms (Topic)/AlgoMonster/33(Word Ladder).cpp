/*
Problem statement:

Word Ladder is "a puzzle begins with two words, and to solve the puzzle one must find a chain of other words to link the two, in which two adjacent words (that is, words in successive steps) differ by one letter."

For example: COLD → CORD → CARD → WARD → WARM



Given a start word, an end word, and a list of dictionary words, determine the minimum number of steps to go from the start word to the end word using only words from the dictionary.

Input:

start = "COLD"
end = "WARM"
word_list = ["COLD", "GOLD", "CORD", "SOLD", "CARD", "WARD", "WARM", "TARD"]
Output:

4
Explanation: We can go from COLD to WARM by going through COLD → CORD → CARD → WARD → WARM
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
we start from a word. in each step we can only go from one word in the list to another and we want to end up on some word. this siggests that we can represent each word with a node
in a graph. in order to do this simply replace every character in the string with a new charavter and see if we have generated this ord before. we can use a set to keep track of which
words we have already made as nodes. each step that transforms a word to another then becomes an edges between the corresponding nodes

now problem becomes 'find the minimum distance from one node in a graph to the other' which is a problem that bfs handles very easily.

conceptially we now have an algorithm that is a 2-step process:
    1. build a grpah that re[presents the words and transformations
    2. use BFS on the graph to find th eminimum distance

in actual algorithm,, however, we don't need to build up the graph before using BFS; we cann build the graph as we go instead of storing the edges, we cancaluate the set of neighbors
for the current node only wehen need to visit them.


nodes int he graph are determined by the no of edges in the dictionary. edges are determined by words that are 1 letter aprart,. annother node is that aftere deges are computerd
some performance increases might by possible by hashing the string ato a numerical value.

    Time complexity: O(n+m)
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <queue> // queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_set> // unordered_set
#include <vector> // vector

std::string alphabets = "abcdefghijklmnopqrstuvwxyz";

int word_ladder(std::string begin, std::string end, std::vector<std::string> word_list) {
    // make a set because existence query is O(1) vs O(N) for list
    std::unordered_set<std::string> words(word_list.begin(), word_list.end());
    std::queue<std::string> q;
    q.push(begin);
    int distance = 0;
    while (q.size() > 0) {
        int n = q.size();
        distance++;
        for (int i = 0; i < n; i++) {
            std::string word = q.front();
            for (int j = 0; j < word.size(); j++) {
                for (char c : alphabets) {
                    std::string next_word = word.substr(0, j) + c + word.substr(j + 1);
                    if (!words.count(next_word)) continue;
                    if (next_word == end) return distance;
                    q.push(next_word);
                    // removing from the set is equivalent to marking the word visited
                    words.erase(next_word);
                }
            }
            q.pop();
        }
    }
    return 0;
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
    std::string begin;
    std::getline(std::cin, begin);
    std::string end;
    std::getline(std::cin, end);
    std::vector<std::string> word_list = get_words<std::string>();
    int res = word_ladder(begin, end, word_list);
    std::cout << res << '\n';
}
