/*
-------------------------Question:

https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
*/

/*
-------------------------    My Approaches:
1. Using a stack

We can use a stack to perform the calculation. Our first gooal is to convert from infix to postfix followed by finding the value .

For converting to postfix, based on what we encounter, there are a few possibilities:
    1. '(' : append it to the operator stack
    2. ')' : remove all the operators in the stack till we encounter a '(' or the stack is empty. This way we complete the calcualtions within the brackets as they are of higher precedence.
    3. operand: If operand, simply append it to the string as order remains the same.
    4. operator: If operator, then we must keep removing operators from the stack as long as the current operator has a precedence less than that at the top of the stack. This is because, since the operaot rat the top of the stack has a
    higher precedence, it must be given importance first which means thatit must popped from the stack first. After this, we can push the current operator into the stack.

Time eomplexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    int getOperatorPrecedence(char op){
        if(op == '/' || op == '*')
            return 3;
        else if(op == '+' || op == '-')
            return 2;
        else
            return -1;
    }
    
    string convertToPostfix(string s){
        string resultString = "";
        stack<char> operatorStack;
        
        // fill postfix String using rules
        for(int i=0; i<s.size(); i++){
            /*
            if space, ignore
            if ( push it into operator stack
            if ) remove all operators till ( encouuntered, and then pop (
            if operand, push it into string
            get precedence value of operator,
            */
            // cout<<"Position: "<<i<<" Current char: "<<s[i]<<endl;
            
            if(isdigit(s[i])){
                while( i < s.size() && isdigit(s[i])){
                    resultString += s[i++];
                }
                resultString += "#";
                --i;
            }
            else if(s[i] == '('){
                // cout<<"Pushing ("<<endl;
                operatorStack.push(s[i]);
            }
            else if(s[i] == ')'){
                // cout<<"Enountered )"<<endl;
                while(!operatorStack.empty() && operatorStack.top() != '('){
                    resultString += operatorStack.top();
                    operatorStack.pop();
                }   
                operatorStack.pop();
            }
            else{
                if(operatorStack.empty() || getOperatorPrecedence(s[i]) > getOperatorPrecedence(operatorStack.top()))
                    operatorStack.push(s[i]);
                else{
                    while(!operatorStack.empty() && getOperatorPrecedence(s[i]) <= getOperatorPrecedence(operatorStack.top())){
                        resultString += operatorStack.top();
                        operatorStack.pop();
                    }
                    operatorStack.push(s[i]);
                }
            }
            // cout<<"Result stirng: "<<resultString<<endl;
        }
        
        
        // if any operaotrs left at end of string, pop them out
        while(!operatorStack.empty()){
            resultString += operatorStack.top();
            operatorStack.pop();
        }
        return resultString;
    }
    
    int getValue(int firstValue, int secondValue, char op){
        if(op == '+')
            return firstValue + secondValue;
        else if(op == '-')
            return firstValue - secondValue;
        else if(op == '*')
            return firstValue * secondValue;
        else
            return firstValue / secondValue;
    }
    
    int calculateValue(string postfixString){
        stack<int> valueStack;
        int total = 0;
        string tempString  = "";
        
        for(int i=0; i<postfixString.size(); i++){
            if(isdigit(postfixString[i]))
                tempString += postfixString[i];
            else if(postfixString[i] == '#'){
                valueStack.push(stoi(tempString));
                tempString = "";
            }
            else{
                int secondValue = valueStack.top();
                valueStack.pop();
                int firstValue = valueStack.top();
                valueStack.pop();
                int value = getValue(firstValue, secondValue, postfixString[i]);
                valueStack.push(value);
            }
        }
        
        return valueStack.top();
    }
    
    string removeSpace(string s){
        string resultString = "";
        // get rid of sapce
        for(int i=0; i<s.size(); i++){
            if(s[i]!= ' ')
                resultString += s[i];
        }
        
        return resultString;
    }
    
    int calculate(string s) {
        // covert infix to postfix
        string removedSpaceString = removeSpace(s);
        string postfixString = convertToPostfix(removedSpaceString);
        // cout<<"Postfix string: "<< postfixString<<endl;
        // calcualte value of postfix
        if(!postfixString.size())
            return 0;
        return calculateValue(postfixString);
    }
};