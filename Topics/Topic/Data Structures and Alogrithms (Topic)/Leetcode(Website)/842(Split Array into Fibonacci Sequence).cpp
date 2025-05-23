/*
-------------------------Question:

Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
F.length >= 3;
and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]
Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]
Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.
Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.
Note:

1 <= S.length <= 200
S contains only digits.
*/

/*
-------------------------    My Approaches:
1. Recursive, backtracking approach

We can apply the recursive approach in order to solve this problem. If we notice the patterns in the problem, we see that at each step, there are one of 2 steps we can do: either start a new number from this index or extend the number we
had for the previous number. This allows us to build the numbers as we are going along. It is one of these 2 steps that will gie a solution. 

Time complexdity: O(n* 2^n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:
1. Improved version of recursive approach

If we observed My Approaches(1), there were two specific bottlenecks. 
    (1) We were checking for the property of Fibonacci satisfaction at the end F(n-2) + F(n-1) == F(n) at the very end. This would build up solutions for which the condition was not all satisifed and only check it at the end.
    (2) We were adding numbers greater than the max length of 10 digits that set up an int number. This would build really long numbers as a result even though they weren't valid.

These two improvmeents were made in this approach. As a result, our solution here improved.

Time complexity: O(n^2)
Space complexity: O(n)
*/

// My Approaches(1)
class Solution {
public:
    bool isLeadingZero(vector<string> & list){
        for(int i=0; i<list.size(); i++){
            if(list[i].size() > 1 && list[i][0] == '0')
                return true;
        }
        return false;
    }
    
    bool isValidSolution(vector<string> & list){
        bool isValid = true;
        if(isLeadingZero(list))
            isValid = false;
        else{
            for(int i=2; i< list.size() && isValid; i++){
                if(stoi(list[i-2]) + stoi(list[i-1]) != stoi(list[i]))
                    isValid = false;
            }   
        }
        return isValid;
    }
    
    void addToResult(vector<string> & list, vector<int> & result){
        for(int i=0; i<list.size(); i++)
            result.push_back(stoi(list[i]));
    }
    
    void findFibonacci(string s, vector<int> & result, int index, vector<string> list, bool & isSolutionFound){
        if(index == s.size()){
            if(list.size() >= 3 && isValidSolution(list)){
                isSolutionFound = true;
                addToResult(list, result);
            }
        } 
        else{
            // start number fromn this digit
            string tempString(1,s[index]);
            list.push_back(tempString);
            findFibonacci(s, result, index+1, list, isSolutionFound);
            list.pop_back();
            
            // add this digit to previous number
            list[list.size()-1] += s[index];class Solution {
public:
    bool backtrack(string & s, vector<int> & result, int index){
        if(index >= s.size()){
            if(result.size() >= 3)
                return true;
        }
        
        int maxSize = (s[index] == '0') ? 1 : 10;
        
        for(int i=1; i<=maxSize && index+i <= s.size(); i++){
            long long value = stoll(s.substr(index, i));
            if(value > INT_MAX)
                return false;
            
            int resultSize = result.size();
            
            if(result.size() >= 2){
                long long sum = (long long)result[resultSize-2] + (long long) result[resultSize-1];
                if(sum < value)
                    return false;
            }
            
            if(result.size() <= 1 || (((long long) result[resultSize-2] + (long long) result[resultSize-1]) == value)){
                result.push_back(value);
                if(backtrack(s, result, index+i))
                    return true;
                result.pop_back();
            }
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        backtrack(S, result, 0);
        return result;
    }
};
                
            }
            list[list.size()-1].pop_back(); 
        }
    }
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        vector<string> list;
        string tempString(1,S[0]);
        bool isSolutionFound = false;
        
        list.push_back(tempString);
        findFibonacci(S, result, 1, list, isSolutionFound);
        return result;
    }
};


// Other Approaches(1)
class Solution {
public:
    bool backtrack(string & s, vector<int> & result, int index){
        if(index >= s.size()){
            if(result.size() >= 3)
                return true;
        }
        
        int maxSize = (s[index] == '0') ? 1 : 10;
        
        for(int i=1; i<=maxSize && index+i <= s.size(); i++){
            long long value = stoll(s.substr(index, i));
            if(value > INT_MAX)
                return false;
            
            int resultSize = result.size();
            
            if(result.size() >= 2){
                long long sum = (long long)result[resultSize-2] + (long long) result[resultSize-1];
                if(sum < value)
                    return false;
            }
            
            if(result.size() <= 1 || (((long long) result[resultSize-2] + (long long) result[resultSize-1]) == value)){
                result.push_back(value);
                if(backtrack(s, result, index+i))
                    return true;
                result.pop_back();
            }
        }
        return false;
    }
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        backtrack(S, result, 0);
        return result;
    }
};