/*
-------------------------Question:

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

/*
-------------------------    My Approaches:
1. Using a stack

We can use a stack to store the operands as we are going along. Whenever we encounter an operator, we pop the two operands at the top of the stack , perform the operation depending on the operator and insert it back into the stack. We
continue this till we reach the end of the string and then return the value at the top of the stack.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My approaches(1)
class Solution {
public:
    int getNumber(int firstNumber, int secondNumber, char token){
        if(token == '-')
            return firstNumber - secondNumber;
        else if(token == '*')
            return firstNumber * secondNumber;
        else if(token == '+')
            return firstNumber + secondNumber;
        else
            return firstNumber / secondNumber;
    }
    
    int getValue(stack<int> operand, vector<string> tokens){
        for(int i=0; i<tokens.size(); i++){
            int firstNumber = -1, secondNumber = -1;
            if(tokens[i].compare("-") == 0 || tokens[i].compare("*") == 0 || tokens[i].compare("+") == 0 || tokens[i].compare("/") == 0){
                secondNumber = operand.top();
                operand.pop();
                firstNumber = operand.top();
                operand.pop();
                
                int value = getNumber(firstNumber, secondNumber, tokens[i][0]);
                // cout<<"First number: "<<firstNumber<<" Second number: "<<secondNumber<<" operand: "<<tokens[i]<<" value: "<<value<<endl;
                operand.push(value);
            }
            else
                operand.push(stoi(tokens[i]));
        }
        return operand.top();
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> operand;
        return getValue(operand, tokens);
    }
};