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
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
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



//  Other Approaches(1)
