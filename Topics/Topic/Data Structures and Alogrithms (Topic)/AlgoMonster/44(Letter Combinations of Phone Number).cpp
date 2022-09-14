/*
Problem statement:

Given a phone number that contains digits 2-9, find all possible letter combinations the phone number could translate to.



Input:

"56"
Output:

["jm","jn","jo","km","kn","ko","lm","ln","lo"]
*/

/*
-------------------------    My Approaches:
1. backtracking + combinatorics approachss

    we can sue the backtracking + combinatorics template to solve this problem.

    to know the state of our solution, we keep a combination string which adds string as we are going along. when its size is equal to the size of hte digits, we have our answer
    to know the state of whioch character should be next, we just need to use an index to keep moving the index forward as oon as we add a character. since we are looking for all combinations, order does matter here
    and hence using an index suffices as opposed to using a map

    Time complexity: O(n!)
    Space complexity: O(n!)
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
#include <iostream> // cin, cout
#include <iterator> // ostream_iterator, prev
#include <string> // getline, string
#include <vector> // vector
#include <unordered_map>

void fillMap(std::unordered_map<char, std::string> & phoneMap){
    phoneMap['2'] = "abc";
    phoneMap['3'] = "def";
    phoneMap['4'] = "ghi";
    phoneMap['5'] = "jkl";
    phoneMap['6'] = "mno";
    phoneMap['7'] = "pqrs";
    phoneMap['8'] = "tuv";
    phoneMap['9'] = "wxyz";
}

void dfs(std::unordered_map<char, std::string> & phoneMap, std::vector<std::string> & result, std::string & combination, std::string digits, int pos){
    if(combination.size() == digits.size())
        result.push_back(combination);
    else{
        std::string possibleLetters = phoneMap[digits[pos]];
        for(int i=0; i < possibleLetters.size(); i++){
            combination.push_back(possibleLetters[i]);
            dfs(phoneMap, result, combination, digits, pos+1);
            combination.pop_back();
        }
    }
}

std::vector<std::string> letter_combinations_of_phone_number(std::string digits) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_map<char, std::string> phoneMap;
    std::vector<std::string> result;
    std::string combination;
    int pos = 0;
    
    fillMap(phoneMap);
    dfs(phoneMap, result, combination, digits, pos);
    
    return result;
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
    std::string digits;
    std::getline(std::cin, digits);
    std::vector<std::string> res = letter_combinations_of_phone_number(digits);
    put_words(res);
}



//  Other Approaches(1)
