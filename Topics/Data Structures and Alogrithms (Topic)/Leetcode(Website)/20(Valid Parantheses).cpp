/*
-------------------------Question:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/


/*
-------------------------My Approaches:

1. Using a stack to store the operations

We can use a stack to store the order in which the brackets occur and check if the order is maintained
as we progress through the string. If not, we return false. If it is, we can pop the stack and
continue to do so till the end of the string. At the end, if the string is empty, we can confirm
it's a valid string else it's not.


Time complexity: O(n)
Space complexity: O(n)


2. Using a modular approach to My Approaches(1)

The second approach is a more modular approach to My Approaches(1) which helps to automate the
check procedure as much as possible instead of hard-coding it.

Time complexity: O(n)
Space complexity: O(n)



*/

/*
-------------------------Other approaches


*/



// My Approach(1)
class Solution {
public:
    bool checkValidString(string element){
        stack<char> bracketStack;
        for(int i = 0; i < element.size(); i++){
            if(element[i] == '(' || element[i] == '{' || element[i] == '[')
                bracketStack.push(element[i]);
            else{
                if(!bracketStack.empty() && ((element[i] == ')' && bracketStack.top() =='(') || (element[i] == ']' && bracketStack.top() =='[') || (element[i] == '}' && bracketStack.top() =='{')))
                    bracketStack.pop();
                else
                    return false;
            }
        }
        return bracketStack.empty(); 
    }
    
    bool isValid(string s) {
        if(s == "")
            return true;
        else{
            return checkValidString(s);
        }
    }
};



// My Approach(2)
class Solution {
public:
    void createMapOperations(unordered_map<char,char> & operations){
        operations[')'] = '(';
        operations['}'] = '{';
        operations[']'] = '[';
    }
    
    bool checkOpenOperation(char operand){
        if(operand == '(' || operand == '{' || operand == '[')
            return true;
        return false;
    }
    
    bool checkValidString(string element, unordered_map<char,char> operations){
        stack<char> bracketStack;
        for(int i = 0; i < element.size(); i++){
            if(checkOpenOperation(element[i]))
                bracketStack.push(element[i]);
            else if(!bracketStack.empty() && operations[element[i]] == bracketStack.top())
                bracketStack.pop();
            else
                return false;
        }
        return bracketStack.empty(); 
    }
    
    bool isValid(string s) {
        if(s == "")
            return true;
        else{
            unordered_map<char,char> operations;
            createMapOperations(operations);
            return checkValidString(s, operations);
        }
    }
};