/*
Problem statement:

iven an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7

Output: [[2,2,3],[7]]

Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.

7 is a candidate, and 7 = 7.

These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8

Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1

Output: []

Example 4:
Input: candidates = [1], target = 1

Output: [[1]]

Example 5:
Input: candidates = [1], target = 2

Output: [[1, 1]]

Constrains:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
All elements of candidates are distinct.
1 <= target <= 500
*/

/*
-------------------------    My Approaches:
1. combinatorial approach

    we can apply the combinatorial approach in order to solve this problem. since it is askign us for all combinations 
    that lead us to the su,m, we just keepp adding neighbors and go into the dfs recursive call structure. if your sum is equal to the target , then we have found a solution.
    if the sum exceeds the target, then we are not going to get a solution from that point.

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
we can try subtracting eahc candidate number until the remaining number is either less or equal to 0

te only problem is that we have duplicatre combinations in our results

dedup

in this example, we get to the teal node from the root by subtracting 3. for the next step, we would subtract 2 but that would give us [3,2]
which is a duplicate of [2,3] that we already have. the reason for duplication is we have already considered all options incluiding subtracting 3
when we subtraced 2 in the previous branch. therefore, we dont want to look back and use any precedent candidatate such as 2. we dedup in the for loop
by only using candiadate numbers whose index in the array is >= last used number's index


to do that, we just need to add an extra condition to prine the duplicate branches
    if remaining - num < 0:
        break

the idea of establishing order and pruning backward branches a is very useful de-deuplication technique. you can also use it in tow pointer provlems that has
duplicate candiudates


the way we deup us ti ibky use cindidate numbers whose index in the array is >= last used number's index. in this example,
when we are at the teal node, we dont want to look back and use any precedent candidate such as 2. this is because by DFS order, we arlready exp;lored subtracting 2 and during that traversal we have considered using 3 (blue nodes)

we use an additional state start_index to kkeep track of the position of the last used number ("start" index becauyse it is the index you want to start building new branches from). final tree with duplicate branch pruned





    Time complexity: O(n^target/min(candidates))
        in the worst case, the state-sapce tree has n branches and the depth of the tree is at most target divided by the smallest number in candidates
        every number can be used or not used therefore leading to exponential time complexity

    Space complexity: O(target/min(candidates))
        as each candidate combination is at most length target/min(candidates) corresponding to the maximum height of the state-space tree.


*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void dfs(std::vector<int> & candidates, int target, std::vector<int> & path,std::vector<std::vector<int>> & result, int currSum, int startIndex){
    // if found target sum
    if(currSum == target){
        result.push_back(path);
    }
    // if no possible solution
    else if(currSum > target)
        return;
    else{
        for(int i=startIndex; i< candidates.size(); i++){
            currSum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates, target, path, result, currSum, i);
            currSum -= candidates[i];
            path.pop_back();
        }
    }
}


std::vector<std::vector<int>> combination_sum(std::vector<int> candidates, int target) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    
    dfs(candidates, target, path, result, 0, 0);
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

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::vector<int> candidates = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    std::vector<std::vector<int>> res = combination_sum(candidates, target);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void dfs(std::vector<int> candidates, int target, std::vector<std::vector<int>>& res, std::vector<int> seq, int sum, int start) {
    if (sum == target) {
        std::vector<int> list(seq);
        res.emplace_back(list);
    }
    if (sum < target) {
        for (int i = start; i < candidates.size(); i++) {
            sum += candidates[i];
            if (sum > target) break;
            seq.emplace_back(candidates[i]);
            dfs(candidates, target, res, seq, sum, i);
            seq.pop_back();
            sum -= candidates[i];
        }
    }
}

std::vector<std::vector<int>> combination_sum(std::vector<int> candidates, int target) {
    std::vector<std::vector<int>> res;
    dfs(candidates, target, res, {}, 0, 0);
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

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    std::vector<int> candidates = get_words<int>();
    int target;
    std::cin >> target;
    ignore_line();
    std::vector<std::vector<int>> res = combination_sum(candidates, target);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}