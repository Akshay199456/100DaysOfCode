/*
Problem statement:


*/

/*
-------------------------    My Approaches:
1. Combinatorics

    this problem can be solved using combinatorics. since we are asked to find if we can make s from
    the words vector, we will need to break down the word s into its different compoenents and check for two parts.
    we want to check if the first word either exists in the dictionary of words we have. but that's not it. we also need to find whether
    we can build the second word either directly from the word in the dictionary or from each of the compoenents of the vector of strings.

    Time complexity: O()
    Space complexity: O()

2. Memoization

    we make use of a map to store the results of previous recurisve calls. this way we dont repeat the same call over and over again.
    the only changes e make to the code is that if we have the reuslt fo a previous call, we return it immeidaely onstead of doing it again.
    in addition, we store thee result of each call after each for loop to track the state as we are going along.
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
this is yet another combinatorial search problem. let's apply the three-step backtracking system:

1. identify the states

    to determine whether we have completely constructed target s, we have to find
        what are the characters left to be matched using words in the list
    to make a choce when we visit the current node's children, we dont need any additional states since we can use any word in the list unlimited number of time

2. draw the space-state tree

    in the diagram , there are two parts that lead to an empty string i.e completely matching thhe tartget. when we DFS, we would reach te left one first without visiting the other one since we just need one successful to return treu

3. DFS on the space-state tree

    using the backtracking template as a basis, we add the state we idenitified in step 1:
        1. we use index startIndex to record the current position in the target we have matched so far. s[:startIndex] is matched and s[startIndex:] is to be matched


    
Memoization

    everything looks great. when we finish typing that last bracket/semicolon, there is one pesky test acxase:

    why does this one time out? we have 10 banches to check each level of the tree and there are 140as in the target, in the worst case, we would be looking at 10^140 branches.
    this is 'combinatorial explosion' in the backtracking module. we have been struck by it. the way to solve this is to use memoization to ccache the branches we have already seen. we have seen duplicates in the above example

    Time complexity: O(s*w * max(w[i]))
    Space complexity: O()

    s us tghe length of the string, w is the length of the words array and max(w[i]) is the maximal possible word length. here our time completyity is polynomial since we memoize and we iteratre through the 
    possibilities. at every position s we try every word in w which takes time proportionate to the word length

*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_set>

void fillSet(std::unordered_set<std::string> & elementSet, std::vector<std::string> & words){
    for(int i=0; i< words.size(); i++)
        elementSet.emplace(words[i]);
}

bool dfs(std::unordered_set<std::string> & elementSet, std::string & wordBreak){
    if(!wordBreak.size())
        return true;
    else{
        for(int i=1; i<= wordBreak.size(); i++){
            std::string firstWord = wordBreak.substr(0, i);
            std::string secondWord = wordBreak.substr(i);
            
//             std::cout<<"first word: "<<firstWord<<std::endl;
//             std::cout<<"second word: "<<secondWord<<std::endl;
            
            bool result = (elementSet.find(firstWord) != elementSet.end()) && dfs(elementSet,secondWord);
            if(result)
                return result;
        }
        return false;
    }
}

bool word_break(std::string s, std::vector<std::string> words) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_set<std::string> elementSet;
    fillSet(elementSet, words);
    return dfs(elementSet,s);
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
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::string> words = get_words<std::string>();
    bool res = word_break(s, words);
    std::cout << std::boolalpha << res << '\n';
}


// My Approaches(2)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_set>

void fillSet(std::unordered_set<std::string> & elementSet, std::vector<std::string> & words){
    for(int i=0; i< words.size(); i++)
        elementSet.emplace(words[i]);
}

bool dfs(std::unordered_set<std::string> & elementSet, std::string & wordBreak, std::unordered_map<std::string, bool> & memo){
    if(!wordBreak.size())
        return true;
    else if(memo.find(wordBreak) != memo.end())
        return memo[wordBreak];
    else{
        bool result = false;
        for(int i=1; i<= wordBreak.size() && !result; i++){
            std::string firstWord = wordBreak.substr(0, i);
            std::string secondWord = wordBreak.substr(i);
            
//             std::cout<<"first word: "<<firstWord<<std::endl;
//             std::cout<<"second word: "<<secondWord<<std::endl;
            
            result = result || ((elementSet.find(firstWord) != elementSet.end()) && dfs(elementSet,secondWord, memo));            
        }
        memo[wordBreak] = result;
        return memo[wordBreak];
    }
}

bool word_break(std::string s, std::vector<std::string> words) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_set<std::string> elementSet;
    std::unordered_map<std::string, bool> memo;
    fillSet(elementSet, words);
    return dfs(elementSet,s,memo);
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
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::string> words = get_words<std::string>();
    bool res = word_break(s, words);
    std::cout << std::boolalpha << res << '\n';
}





//  Other Approaches(1)
bool dfs(int start_index, std::string s, std::vector<std::string> words) {
    if (start_index == s.size()) return true;

    for (std::string word: words) {
        if (s.substr(start_index).find(word) == 0) {
            if (dfs(start_index + word.size(), s, words)) return true;
        }
    }

    return false;
}

bool word_break(std::string s, std::vector<std::string> words) {
    return dfs(0, s, words);
}


// Other Approaches(2)
bool dfs(int start_index, std::string s, std::vector<std::string> words) {
bool dfs(int start_index, int memo[], std::string s, std::vector<std::string> words) {
    if (start_index == s.size()) return true;
    if (memo[start_index] != -1) return memo[start_index] == 1;
    int ok = 0;
    for (std::string word: words) {
        if (s.substr(start_index).find(word) == 0) {
            if (dfs(start_index + word.size(), s, words)) return true;
            if (dfs(start_index + word.size(), memo, s, words)) {
                ok = 1;
                break;
            }
        }
    }
    memo[start_index] = ok;
    return false;
    return ok == 1;
}
bool word_break(std::string s, std::vector<std::string> words) {
    return dfs(0, s, words);
    int memo[s.size()];
    std::fill_n(memo, s.size(), -1);
    return dfs(0, memo, s, words);
}