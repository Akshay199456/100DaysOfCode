/*
-------------------------Question:

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/

/*
-------------------------My Approaches:

1. Backtracking

We can use backtracking here to solve this problem. If you observe the problem closely, there
are a couple of important pointers that are associated. First, every valid solution begins
with a '(' and ends with a ')'. Second, the number of ( has to be more than or equal to the 
number of ) at all times since the ( associated with a pair always comes before the ) of that 
pair. Using those two conditions, we can use the backtracking technique to solve the problem.

Time complexity: 
Space complexity:

*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    void getSolution(string element, int open, int close, int n, vector<string> & result){
        if(element.size() < 2*n){
            if(open < n && open + 1 >= close)
                getSolution(element + "(", open + 1, close, n, result);
            if(close < n && open >= close + 1)
                getSolution(element + ")", open, close + 1, n, result);
        }
        
        else if(element.size() == 2 * n)
            result.push_back(element);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n > 0)
            getSolution("(", 1 , 0, n, result);
        else if(!n)
            result.push_back("");
        return result;
    }
};