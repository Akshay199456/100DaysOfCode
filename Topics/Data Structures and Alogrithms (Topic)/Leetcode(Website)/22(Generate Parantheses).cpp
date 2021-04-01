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

Time complexity: O(4^n/sqrt(n))
Space complexity: O(4^n/sqrt(n))


2. Brute force approach[coded]

The brute force approach is pretty simple. We generate all the 2^n combinations that can
possibly exist. Once we have that we have to make sure to go through each combination to keep
check that they are valid by making sure the close is alwyas less than or equal to the number of
open brackets

Time complexity: O(n*2^n)
Space complexity: O(n*2^n)
*/

/*
-------------------------Other approaches

1. Brute force approach[Not coded]

The brute force approach is pretty simple. We generate all the 2^n combinations that can
possibly exist. Once we have that we have to make sure to go through each combination to keep
check that they are valid by making sure the close is alwyas less than or equal to the number of
open brackets

Time complexity: O(n*2^n)
Space complexity: O(n*2^n)


2. Dynamic programming with backtracking

If we analyze the problem, we can understand that this problem is an instance of the dynamic
programming concept and hence you can build the solution for the curent situation based on the
previous situations. 

There are 2 basic conditions which dictate all the other situations that depend on it:

f(0) = ""
f(1) = "()"

Using these 2 conditions, can deduce what f(2) is:

f(2) = ["()()", "(())"]

If we analyze f(2) carefully, the solutions for it can be represented as:
f(2) = [{f(0)}f(1), {f(1)}f(0)]
where the {} represents the "(" and ")" respectively

Using this, we can extend it to any other layer as 
f(n) = {f(0)}f(n-1) + {f(1)}f(n-2) + {f(2)}f(n-3) + ........ + {f(n-1)}f(0)
     = Sigma ( {f(i)}f(n-i-1))

We can therefore use this information to come up with an algorithmic solution

Time complexity: O(4^n/sqrt(n))
Space complexity: O(4^n/sqrt(n))
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


// My Approaches(2)
class Solution {
public:
    bool isValidSolution(string currentString){
        stack<char> parStack;
        for(int i=0; i<currentString.size(); i++){
            if(currentString[i] == '(')
                parStack.push('(');
            else{
                if(parStack.empty() || parStack.top() != '(')
                    return false;
                else
                    parStack.pop();
            }
        }
        return parStack.empty();
    }
    
    void generateAllParenthesis(vector<string> & result, string currentString, int n, vector<string> tokens){
        if(currentString.size() == 2*n && isValidSolution(currentString))
            result.push_back(currentString);
        else if(currentString.size() < 2*n){
            for(int i=0; i<tokens.size(); i++){
                currentString.append(tokens[i]);
                generateAllParenthesis(result, currentString, n, tokens);
                currentString.pop_back();
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<string> tokens{"(", ")"};
        string currentString = "";
        generateAllParenthesis(result, currentString, n, tokens);
        return result;
    }
};



// Other Approaches(2)
class Solution {
public:
    vector<vector<string>> result;
    
    void generateSolution(int n){
        for(int i = 1; i <= n; i++){
            vector<string> list;
            for(int j = 0; j < i; j++){
                for(string firstElement: result[j])
                    for(string secondElement: result[i - j - 1])
                        list.push_back("(" + firstElement + ")" + secondElement);
            }
            result.push_back(list);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        if( n < 0)
            return list;
        
        list.push_back("");
        result.push_back(list);
        generateSolution(n);
        return result[n];
    }
};