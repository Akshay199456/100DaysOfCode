/*
Problem statement:

iven a string of unique letters, find all of its distinct permutations.

Input
letters: a string of unique letters
Output
all of its distinct permutations

Examples
Example 1:
Input:

letters = `abc`
Output: ```` abc acb bac bca cab cba

`

**Explanation**:
All permutations.
*/

/*
-------------------------    My Approaches:
1. backtracking template

    we applied the backtracking template that was provided in algo monster. the usmmary is that it is composed of 3 parts:
    1. identify state
    2. draw the state-space tree
    3. dfs/backtrack on state-space tree

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
#include <iostream> // cin, cout
#include <string> // getline, string
#include <vector> // vector
#include <unordered_set>

void dfs(std::string & letters, std::vector<std::string> & result, std::string & permutation, std::unordered_set<char> & visited){
    if(permutation.size() == letters.size())
       result.push_back(permutation);
      else{
          for(int i=0; i < letters.size(); i++){
              if(visited.find(letters[i]) == visited.end()){
                  permutation.push_back(letters[i]);
                  visited.emplace(letters[i]);
                  dfs(letters, result, permutation, visited);
                  permutation.pop_back();
                  visited.erase(letters[i]);
              }
          }
      }
}

std::vector<std::string> permutations(std::string letters) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::string> result;
    std::string permutation;
    std::unordered_set<char> visited;
    dfs(letters, result, permutation, visited);
    return result;
}

int main() {
    std::string letters;
    std::getline(std::cin, letters);
    std::vector<std::string> res = permutations(letters);
    for (const std::string& line : res) {
        std::cout << line << '\n';
    }
}



//  Other Approaches(1)
