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



Additional Notes

we can try every word in the dictionary and see if the dictionary word is a prefix of the target word.
for example, assuming the dictionary contains ['a','b','algo'], 'a' and 'algo' are both prefixes of 'algomonster', but 'b' is not. if the dictionary word is a prefix,
then we can consider the prefix matched and continue to try to match the remaining part of the target word. we can draw the state-space tree by using every dictionary word
as an edge at every level.

using the backtracking 2 template as shown in Addotional Notes(1)-4:

and fill out the missing logic:
    1. is_leaf: if start_index reaches the target.length, then we have matchedd every letter and word break is a success.
    2. get_edges: we use startIndex to record the next letter in the target we have matched so far. target[:startIndex] is matched
    and target[startIndex:] is to be matched. we try this for each word in the dictionary.
    3. initial_value: we start with False because we haven't broken thr target word yet.
    4. aggregate: we use logical OR to update ans to True if return value from the child recursive call is True.
    5. additional states: there is no additional states; we have all the information to determine how to branch out

This is shown in Other Approaches(3)

    Time complexity:
        since there are m words in the words array, we know that each node has a branching factor of m. the depth of the tree depends on the size
        of the shortest word in the array, in the worst case, the state-space tree will have a depth of n/(shortest word size). the no of nodes in the tree is
        bounded by O(m^(n/(shortest word size))). we also know that each string comparison takes at most O(n), we can multiply it to get the toal complexity of 
        O(m^(n/(shortest word size))) * n.


Memoization

    everything looks great. when we finish typing that last bracket/semicolon, we can almost hear angels singing and all tests passing.
    except there is one pesky test case:

    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
    ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

    why does this one time out? we have 10 branches to check each level of the tree and there are 140 'a's in the target, in the worst case,
    we would be looking at 10^140 branches which is too big for our algorithm. the way to solve this is to use memoization to cache the branches we have already seen. we can even see duplicates in the above example.

    what to meoize

        the green and red subtree have the same content and the same prefix "aa". the difference is threa are two edges
        'a' and 'a' from root to the green 'b' and thre is only one edge 'aa' from root to red 'b'. by order of DFS pre-order traversal, we visit the green subtree
        before we visit the red subtree. ionce we have gone through the green subtree, we have already seen all the possibiilities to calculate whether it's ossible to make up the remaining 'b'
        and thre is no point to visit the red subtree any more since it contains the exact same content. we can memoize this
        by stroioing the result for each start_index rempresneting the wehther it's possible to break target.substring(startIndex, target.length) using words in the dictionary.

    This is shown in Other Approaches(2)

    Time complexity:

        the size of the memo array is O(n) where n is the length of the target word. For each state in the memo array, we have to try every dictionary word to 
        see if it';s a prefix of the target word at the current location. assuming the size of the dictionary is m, string matchging takes O(n), so the overall
        time complexit is O(n^2 *m)

    Space complexity:
        the height of the state space tree is O(n). the size of the memo array is O(n). therefore, the overall space compleixty is O(n).

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
    return ok == 1;
}
bool word_break(std::string s, std::vector<std::string> words) {
    int memo[s.size()];
    std::fill_n(memo, s.size(), -1);
    return dfs(0, memo, s, words);
}


// Other Approaches(3)
bool dfs(int start_index, std::string target, std::vector<std::string> words) {
    if (start_index == target.size()) return true;

    bool ans = false;
    for (std::string word: words) {
        if (target.substr(start_index).find(word) == 0) {
          ans = ans || dfs(start_index + word.size(), target, words));
        }
    }

    return ans;
}

bool word_break(std::string target, std::vector<std::string> words) {
    return dfs(0, target, words);
}
