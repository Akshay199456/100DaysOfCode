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


    Time complexity: O()
    Space complexity: O()
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
