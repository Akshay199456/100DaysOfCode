/*
Problem statement:

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example 1:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
-------------------------    My Approaches:
1. combinatorics

we can solve this problem using combinatorics. since we are given to find all the subsets, as we are going along and adding element,
we are forming a subset, so we should be adding it to the result. we should stop a recursive call when the start idnex is eqal to the length of the vector as then all the elemnts have been considered.

    Time complexity: O(2^n)
    Space complexity: O(2^n)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
similar to permutations, we make a binary choice of whether to include the number in the subset at each level

we cab yse a state u ti keeo tracj if tge ubdex if tge cyrrebt cgar we are at

    Time complexity: O()
    Space complexity: O()

alternative solution

    this problem is very special because every time we make a choce already have a subset so some of the leaf node values are in interna nodes as well. therefore, we can potentially terminate the search earlier

    an alternative and faster soultuion is to tajke advantage of the fact that internal nodes are also final states and draw the tree differently.

similar to combinatioon sum, we dedup by only pruinign backward branches

the main difference betweent eh alternate solution and the original is the poisition of the res.append(cur). we dont wait inmtil
we get to a leaf node to add to the result list. we isntead add to the result list at each step

time complexity: O(2^n)

we have to permute through the possibilities

*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void dfs(std::vector<int> & nums, std::vector<std::vector<int>> & result, std::vector<int> & path, int startIndex){
    if(startIndex == nums.size()){
        return;
    }
    else{
        for(int i= startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            result.push_back(path);
            dfs(nums, result, path, i+1);
            path.pop_back();
        }
    }
}

std::vector<std::vector<int>> subsets(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    result.push_back(path);
    dfs(nums, result, path, 0);
    return result;
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> nums = get_words<int>();
    std::vector<std::vector<int>> res = subsets(nums);
    for (std::vector<int> row : res) {
        std::sort(row.begin(), row.end());
    }
    std::sort(res.begin(), res.end());
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void dfs(int i, std::vector<int> cur, std::vector<int> nums, std::vector<std::vector<int>>& res) {
    if (i == nums.size()) {
        std::vector<int> list(cur);
        res.emplace_back(list);
        return;
    }
    cur.emplace_back(nums[i]);
    dfs(i + 1, cur, nums, res);
    cur.pop_back();
    dfs(i + 1, cur, nums, res);
}

std::vector<std::vector<int>> subsets(std::vector<int> nums) {
    std::vector<std::vector<int>> res;
    dfs(0, {}, nums, res);
    return res;
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> nums = get_words<int>();
    std::vector<std::vector<int>> res = subsets(nums);
    for (std::vector<int> row : res) {
        std::sort(row.begin(), row.end());
    }
    std::sort(res.begin(), res.end());
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}


// Other appraoches(2)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void dfs(int i, std::vector<int> cur, std::vector<int> nums, std::vector<std::vector<int>>& res) {
    if (i == nums.size()) return;
    cur.emplace_back(nums[i]);
    std::vector<int> list(cur);
    res.emplace_back(list);
    dfs(i + 1, cur, nums, res);
    cur.pop_back();
    dfs(i + 1, cur, nums, res);
}

std::vector<std::vector<int>> subsets(std::vector<int> nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> empty;
    res.emplace_back(empty);
    dfs(0, {}, nums, res);
    return res;
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> nums = get_words<int>();
    std::vector<std::vector<int>> res = subsets(nums);
    for (std::vector<int> row : res) {
        std::sort(row.begin(), row.end());
    }
    std::sort(res.begin(), res.end());
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}
