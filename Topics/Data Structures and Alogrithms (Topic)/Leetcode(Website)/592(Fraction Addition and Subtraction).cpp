/*
-------------------------Question:

Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

 

Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"
Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"
Example 4:

Input: expression = "5/3+1/3"
Output: "2/1"
 

Constraints:

The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1, 10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/

/*
-------------------------    My Approaches:
1. Evaluating tokens 

We can break down the expression into numerators and denominators and then perform the calculations once we have the tokens.

Note: We can also improve upon this solution by instead calculating the value as we are going along instead of splitting into tokens. The time complexity would remain the same [O(nlog x)] but the space complexity would be O(1) in that case.

Time complexity: O(n log x) where x is the max possible value for the denominator
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void getTokens(string & expression, vector<int> & numeratorTokens, vector<int> & denominatorTokens){
        string temp = "";
        
        int index = 0;
        while(index < expression.size()){
            if(expression[index] != '/'){
                temp += expression[index];
                index++;
            }
            else{
                int numerator = stoi(temp);
                temp = "";
                index++;
                while(index<expression.size()  && isdigit(expression[index])){
                    temp += expression[index];
                    index++;
                }
                
                int denominator = stoi(temp);
                temp = "";
                numeratorTokens.push_back(numerator);
                denominatorTokens.push_back(denominator);
            }
        }
    }
    
    
    int getGcd(int a, int b){
        if(!b)
            return a;
        return getGcd(b, a % b);
    }
    
    int getLcm(int a,int b){
        return (a/ getGcd(a,b)) * b;
    }
    
    
    void appendIrreducible(int numerator, int denominator, string & result){
        int cd = gcd(numerator,denominator);
        
        numerator /= cd;
        denominator /= cd;
        result += to_string(numerator) + "/" + to_string(denominator);
    }
    
    string getResult(vector<int> & numeratorTokens, vector<int> & denominatorTokens){
        string result = "";
        while(numeratorTokens.size() > 1){
            vector<vector<int>> tokens;
            for(int i=0; i<2; i++){
                vector<int> temp{numeratorTokens[numeratorTokens.size()-1], denominatorTokens[denominatorTokens.size()-1]};
                tokens.push_back(temp);
                numeratorTokens.pop_back();
                denominatorTokens.pop_back();
            }
            
            int lcm = getLcm(tokens[0][1], tokens[1][1]);
            tokens[0][0] *= lcm / tokens[0][1];
            tokens[1][0] *= lcm / tokens[1][1];
            int cumNum = tokens[0][0] + tokens[1][0];
            numeratorTokens.push_back(cumNum);
            denominatorTokens.push_back(lcm);
        }
        appendIrreducible(numeratorTokens[0], denominatorTokens[0], result);
        return result;
    }
    
    
    string fractionAddition(string expression) {
        vector<int> numeratorTokens, denominatorTokens;
        getTokens(expression, numeratorTokens, denominatorTokens);
        return getResult(numeratorTokens, denominatorTokens);
    }
};