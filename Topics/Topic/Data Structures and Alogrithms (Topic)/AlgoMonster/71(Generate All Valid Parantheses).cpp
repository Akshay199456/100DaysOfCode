/*
Problem statement:

Given an integer n, generate all strings with n matching parentheses. "matching" parentheses mean

there is equal number of opening and closing parentheses.
each opening parenthesis has matching closing parentheses.
For example, () is a valid string but )( is not a valid string because ) has no matching parenthesis before it and ( has no matching parenthesis after it.

Input
n: number of matching parentheses
Output
all valid strings with n matching parentheses

Examples
Example 1:
Input:

n = 2
Output: (()) ()()

Explanation:

There are two ways to create a string with 2 matching parentheses.

Example 2:
Input:

n = 3
Output: ((())) (()()) (())() ()(()) ()()()

Explanation:

There are 5 ways to create a string with 3 matching parentheses.
*/

/*
-------------------------    My Approaches:
1. Backtracking

    we can use backtracking in order to solve this problem. if we observe each example, we can notice that the 
    closed bracket cant exceed the open bracket at anyu time. as a result, when selecting a close bracket we make that check in addition
    to making the same check that we make on the open bracket which is if it is less than n.

    the stop condition is when we have all the open and close brackets filled out which is 2*n.

    Time complexity: O(2^n)
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
generate all valid paranthese is a strong indication this is a combinatorial problem and should be solved using backtracking.

starting with an empy string, we can add ( or ) and continue to do that until the length reaches 2*n. the tricky things is not all the pairs 
generated in this way are valid. specifically, the string is invalid hwen:
    1. there are more than n occurrences of (
    2. we want to add an ) but there is no matching (.

lets draw the tree for n=2 and see what it looks like:

we prune the bracnhes that will not lead to a valid leaf node.


Additional states:
    in the previous problem, we were able to prune the tree by checking if the string is a palindrome. the validity check is a simple check on the string
    itself and did not require additional states.

    for the current problem thpugh, we have to keep track of how many ( and ) we have seen so far to determine whether a bracnh is valid

    Applying our template:

    we add additional states openCount and closeCount to represent the number of opening and closing parantheses respectively. when we branch out
    and generate the edges, we can either add ( and increment openCount or add ) and increment closeCount.

    Time complexity: O(4^n)
        there are 2^(2^n) = 4^n combinations of possible parantheses. however, since we prune the invalid branches earli on, this a very genrous bound
    Space complexity: O(n)
        stack memory of is bounded by height of the state-space tree which is O(n) in the worse case

    Footnote:
        note that we used tow ifs instead of a for loop in the implementation because there are only two cases and the additional states are updated differently.
        could have followed the template exactly and wrote as hown in Other Approiaches(2)

        but this less clean because of all ifs and is harder to follow and reason. the fist of the story is the template is meant to provide an 
        overall coede structure. adapt the code as you see fit

        also note that in the template we revert(...additional states) but we didnt do that here because openCount and closeCount are proimitive
        types and we updated them inline dfs(startIndex + 1, path, openCount + 1, closeCount, res, n) dfs(startIndex + 1, append(path, ')'), openCount, closeCount + 1, res, n).
        
*/



//  My approaches(1)
#include <algorithm> // sort
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits
#include <string> // string
#include <vector> // vector

void dfs(int openIndex, int closeIndex, int n, std::string & path, std::vector<std::string> & result){
    if(path.size() == 2*n){
        result.push_back(path);
        return;
    }
    
    if(openIndex < n){
        path.push_back('(');
        dfs(openIndex+1,closeIndex,n,path,result);
        path.pop_back();
    }
    
    if(closeIndex < n && closeIndex < openIndex){
        path.push_back(')');
        dfs(openIndex,closeIndex+1,n,path,result);
        path.pop_back();
    }
        
}

std::vector<std::string> generate_parentheses(int n) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::string> result;
    std::string path = "";
    dfs(0,0,n,path,result);
    return result;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    std::vector<std::string> res = generate_parentheses(n);
    std::sort(res.begin(), res.end());
    for (const std::string& line : res) {
        std::cout << line << '\n';
    }
}



//  Other Approaches(1)
#include <algorithm> // sort
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits
#include <string> // string
#include <vector> // vector

void dfs(int startIndex, std::vector<char>& path, int openCount, int closeCount,
         std::vector<std::string>& res, int n) {
    if (path.size() == 2 * n) {
        res.emplace_back(path.begin(), path.end());
        return;
    }
    if (openCount < n) {
        path.emplace_back('(');
        dfs(startIndex + 1, path, openCount + 1, closeCount, res, n);
        path.pop_back();
    }
    if (closeCount < openCount) {
        path.emplace_back(')');
        dfs(startIndex + 1, path, openCount, closeCount + 1, res, n);
        path.pop_back();
    }
}

std::vector<std::string> generate_parentheses(int n) {
    std::vector<char> path;
    std::vector<std::string> res;
    dfs(0, path, 0, 0, res, n);
    return res;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    std::vector<std::string> res = generate_parentheses(n);
    std::sort(res.begin(), res.end());
    for (const std::string& line : res) {
        std::cout << line << '\n';
    }
}


//Other Approaches(2)
def generate_parentheses(n):
    def dfs(path, open_count, close_count, res):
        if len(path) == 2 * n:
            res.append(''.join(path))
            return
        for parenthesis in ['(', ')']:
          if parenthesis == '(' and open_count >= n:
              continue
          if parenthesis == ')' and close_count >= open_count:
              continue
          path.append(parenthesis)
          if parenthesis == '(':
              open_count += 1
          else:
              close_count += 1
          dfs(path, open_count, close_count, res)
          # reverting the state
          if parenthesis == '(':
              open_count -= 1
          else:
              close_count -= 1
          path.pop()
    ans = []
    dfs([], 0, 0, ans)
    return ans     