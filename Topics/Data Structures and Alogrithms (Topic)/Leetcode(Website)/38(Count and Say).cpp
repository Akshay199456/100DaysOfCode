/*
-------------------------Question:

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".
*/

/*
-------------------------My Approaches:
1.

I used recursion in order to solve this problem. It builds each instance from the previous instance
until it reaches the base case of 1-5. It then uses that result to generate the pattern from the 
previous instance.

Time complexity: O(n)
Spac complexity: O(n)
*/


/*
-------------------------Other approaches
1. Iterative approach

This solution is just an iterative approach to My approaches(1). As a result, it takes less space
since it doesn't use the stack like the recursive method does.

Time complexity: O(n)
Space complexity: O(1)
*/

// My approaches(1)
class Solution {
    string pattern[5] = {"1", "11", "21", "1211", "111221"};
public:
    string appendResults(int count, char element){
        string pair = to_string(count);
        string s(1,element);
        pair.append(s);
        return pair;
    }
    
    string countAndSay(int n) {
        if(n < 1 || n >30)
            return "";
        else if(n >=1 && n<=5)
            return pattern[n-1];
        else{
            int  i = 1, count = 1;
            string prevPattern = countAndSay(n-1), result = "";
            char element = prevPattern[0];
            while(i < prevPattern.size()){
                if(prevPattern[i] == element)
                    ++count;
                else{
                    result.append(appendResults(count, element));
                    element = prevPattern[i];
                    count = 1;
                }
                ++i;
            }
            result.append(appendResults(count, element));
            return result;
        }
    }
};

// Other approaches(1)
class Solution {
public:
    string appendString(int count, char element){
        string s(1, element);
        return to_string(count) + s;
    }
    
    string countAndSay(int n) {
        if(n < 1 || n > 30)
            return "";
        else{
            string result = "1";
            while( --n ){
                int count = 1;
                char element = result[0];
                string curr = "";
                for(int i = 1; i <result.size(); i++){
                    if(element == result[i])
                        ++count;
                    else{
                        curr += appendString(count, element);
                        count = 1;
                        element = result[i];
                    }
                }
                curr += appendString(count, element);
                result = curr;
            }
            return result;
        }
    }
};