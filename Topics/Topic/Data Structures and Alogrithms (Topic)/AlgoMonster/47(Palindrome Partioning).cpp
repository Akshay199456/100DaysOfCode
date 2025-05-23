/*
Problem statement:

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Examples
Example 1:
Input: aab
Output:
  [
  ["aa","b"],
  ["a","a","b"]
  ]
*/

/*
-------------------------    My Approaches:
1.  [Coded in second round after understanding main code]

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
we try to remove prefix at each possible position and only continue if the prefix is a palindrome (since every substring has
to be a palindrome)

we prune the tree by not branching out when the prefix is not a palindrome

    Time complexity: O(2^n *n)
        estimating ity of backtrackong on a pruned tree is tricky because pruned branches should be excluded from the overall time
        complexity. one way to estimate is to look at the operation we have done on the input. for each letter in the input string,
        we can either include it as a previous string or start a new string with it. with these two choices, the toal number of operations
        is 2^n. we also need O(n) to check oif the string is a palindrome. in total, the complexity is O(2^n * n)
    Space complexity: O(n)
        space complexity depends on the eight of the tree a dn the height of the state-sapce tree is worst case O(n)

this is because once we determine a paldinrome we work backwards to consider the other palindromes and enumerate them accordingly.

Additionala notes:

this is not a difficult problem. with our approach, we are very close to what was the actual approach to solve this problem.Actually, now that i think about it,
my approach was bascially th approach used in this problem. in this problem, they began from the start and then based on whether the prefix was
a palindrome decided to continue with the rest of the path or not.

if i look at my apporach, it is definitely slightly different in that i came up with the tree struycture that we can
choose to either add one more character tot he previous string or create a new string with one character. then dependong on if they are palindrome or not,
we can decide to cut off a path. 

therefore, i think these approaches are pretty similar.
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // ostream_iterator, prev
#include <string> // getline, string
#include <vector> // vector

bool isPalindrome(std::string element){
    int startIndex = 0, endIndex = element.size()-1;
    while(startIndex < endIndex){
        if(element[startIndex] != element[endIndex])
            return false;
        startIndex++;
        endIndex--;
    }
    retuurn true;
}


void dfs(std::vector<std::vector<std::string>> & result, std::vector<std::string> & currPath, int startIndex, std::string s){
    if(startIndex == s.size()){
        result.push_back(currPath);
        return;
    }
    
    for(int endIndex=startIndex; endIndex < s.size(); endIndex++){
        std::string currSubstring = s.substr(startIndex, endIndex-startIndex+1);
        if(isPalindrome(currSubstring)){
            currPath.push_back(currSubstring);
            dfs(result, currPath, endIndex+1, s);
            currPath.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> partition(std::string s) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> currPath;
    dfs(result, currPath, 0, s);
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
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::vector<std::string>> res = partition(s);
    for (const std::vector<std::string>& row : res) {
        put_words(row);
    }
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // ostream_iterator, prev
#include <string> // getline, string
#include <vector> // vector

bool is_palindrome(std::string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void dfs(std::vector<std::vector<std::string>>& res, std::vector<std::string> part, std::string s, int start) {
    if (start == s.size()) {
        std::vector<std::string> li(part);
        res.emplace_back(li);
    }
    for (int i = start; i < s.size(); i++) {
        if (is_palindrome(s.substr(start, i + 1 - start))) {
            part.emplace_back(s.substr(start, i + 1 - start));
            dfs(res, part, s, i + 1);
            part.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> res;
    dfs(res, {}, s, 0);
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
    std::string s;
    std::getline(std::cin, s);
    std::vector<std::vector<std::string>> res = partition(s);
    for (const std::vector<std::string>& row : res) {
        put_words(row);
    }
}