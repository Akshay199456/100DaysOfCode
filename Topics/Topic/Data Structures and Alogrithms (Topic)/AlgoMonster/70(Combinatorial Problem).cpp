/*
Problem statement:

Find all n-letter words composed by 'a' and 'b', return them in a list of strings in lexicographical order.

Input: 2
Output: ["aa", "ab", "ba", "bb"]

Input: 4
Output: ["aaaa", "aaab", "aaba", "aabb", "abaa", "abab", "abba", "abbb", "baaa", "baab", "baba", "babb", "bbaa", "bbab", "bbba", "bbbb"]
*/

/*
-------------------------    My Approaches:
1. Backtracking approach

    We can apply the backtracking approachj in order to solve this problem. As we have read from the strategy, backtracking problems can be
    solved using a 3 step process which is:
        1/ identify the state
        2. draw the state-space tree
        3. dfs/backtrack on the state-space tree
    
    using this tempalte for any backtracking problem should help sui ins olving the problem


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
#include <algorithm> // sort
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits
#include <string> // string
#include <vector> // vector

void dfs(std::string & letters, std::vector<std::string> & result, int n, std::string & candidate){
    if(candidate.size() == n){
        result.push_back(candidate);
        return;
    }
    
    for(int i=0; i<letters.size(); i++){
        candidate.push_back(letters[i]);
        dfs(letters, result, n, candidate);
        candidate.pop_back();
    }
}

std::vector<std::string> letter_combination(int n) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::string letters= "ab";
    std::string candidate = "";
    std::vector<std::string> result;
    dfs(letters, result, n, candidate);
    return result;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    std::vector<std::string> res = letter_combination(n);
    std::sort(res.begin(), res.end());
    for (const std::string& line : res) {
        std::cout << line << '\n';
    }
}



//  Other Approaches(1)
