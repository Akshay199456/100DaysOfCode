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
intuition
    classic combinatorial search problem. let's apply the 3-step system from backtracking template

    1. identiy states
        1. what states doe we need to know whether we have reahced a solution (and suing it to construct a solution if the problem asks for it)?
            - we need a state to keep track of the list of letters we have chosen for the current permuitation
        2. what state do we need to decide which child nodes should be visited next and which ones should be pruned?
            - we have to know what are the letters left that we can still use (since each letter can only be used once)?
    
    2. draw the state-space tree
    
    3. DFS on the state-space tree
        using the backtracking template as basis, we add the two states we identitifed in step 1:
            1. a path list to represent permuitation constructed so far
            2. a used list to record which letters are already used. used[i] == true means ith letter in oringial list has been ised

    Time complexity: O(n!)
    Space complexity: O()

    this is because we have n letters to choose from then n-1 and so on therefore n* (n-1) * (n-2) * .... * 1

    notice how similar the solution is to ternary tree paths. the difference is that we have a new constraint "number of letters left" while deciding which subtree to go down to

    note on deep copy

    in exit logic of above solution, we appen a deep copy of the path res.append(path[:]). this createsa  new list with elements being hte same as current elements of path.
    consider what happens if we dont make the deep copy:

    we get eh same copy 3 times. because append(path) actually appends a referecne (memory address), we actually appended the same list 3 times.
    path.append(i) mutates the list and affects all references to that list. to fix this, we create a new list before we append./
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
include <iostream> // cin, cout
#include <string> // getline, string
#include <vector> // vector

void dfs(std::vector<char> path, bool used[], std::vector<std::string> &res, std::string letters) {
    if (path.size() == letters.size()) {
        // make a deep copy, otherwise we'd be appending the same list over and over
        std::string s(path.begin(), path.end());
        res.emplace_back(s);
        return;
    }
    for (int i = 0; i < letters.size(); i++) {
        // skip used letters
        if (used[i]) continue;
        // add letter to permutation, mark letter as used
        path.emplace_back(letters[i]);
        used[i] = true;
        dfs(path, used, res, letters);
        // remove letter from permutation, mark letter as unused
        path.pop_back();
        used[i] = false;
    }
}

std::vector<std::string> permutations(std::string letters) {
    std::vector<std::string> res;
    bool used[letters.size()] = { false };
    dfs({}, used, res, letters);
    return res;
}

int main() {
    std::string letters;
    std::getline(std::cin, letters);
    std::vector<std::string> res = permutations(letters);
    for (const std::string& line : res) {
        std::cout << line << '\n';
    }
}