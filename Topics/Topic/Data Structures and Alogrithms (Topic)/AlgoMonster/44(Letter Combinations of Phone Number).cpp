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
this is essentially asking for all permutations with the constraint of a  number to letter mapping.

1. identify state(s)

    to construct a letter combination we need

    1. the letter we have selected so far

    to make a choice when we viist the current node's children, we dont need to maintain any additional state since the next possible letters
    are defined by the number to letter mapping

2. Draw the tree

3. DFS on the tree

    since state makes at most 4 recursive calls, we have O(4^n) states. in our base case, we retuire O(n) o build string. so, final runtime is 
    O(4^n * n)

    n is the length of the input string. worse case we have 4 choices for every numbner, average case we have 3 choices so it should be closer to O(3^n *n)

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
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // ostream_iterator, prev
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <vector> // vector

std::unordered_map<char, std::string> keyboard = {{'2',"abc"}, {'3',"def"}, {'4',"ghi"},
    {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};

void dfs(std::vector<char> path, std::vector<std::string>& res, std::string digits, int i) {
    if (path.size() == digits.size()) {
        std::string s(path.begin(), path.end());
        res.emplace_back(s);
        return;
    }
    for (char& c: keyboard[digits[i]]) {
        path.emplace_back(c);
        dfs(path, res, digits, i + 1);
        path.pop_back();
    }
}

std::vector<std::string> letter_combinations_of_phone_number(std::string digits) {
    std::vector<std::string> res;
    dfs({}, res, digits, 0);
    return res;
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
