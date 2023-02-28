/*
Problem statement:

We have a message to decode. Letters are encoded to digits by their positions in the alphabet

A -> 1
B -> 2
C -> 3
...
Y -> 25
Z -> 26
Given a non-empty string of digits, how many ways are there to decode it?

Input: "18"

Output: 2

Explanation: "18" can be decoded as "AH" or "R"

Input: "123"

Output: 3

Explanation: "123" can be decoded as "ABC", "LC", "AW"
*/

/*
-------------------------    My Approaches:
1. combinatorics

    we can use the pattern of comb inatorics to solve thos problem. the problem asks us to figure out the toal no of ways
    we can decode the string. since we are asked to find the toal number of ways, this is a combinaorics problem.
    at every step, we can choose either 1 or 2 characters as the letters allows us that range. now, if the string that is represented by the no
    of characters is valid, then we can continue with finding its next layer whuich will agin contina 1 or 2 characters. however, if the string represented by the character is not valid, then 
    we reutrn 0 as no combination is possible. 

    Time complexity: O(2^n)
    Space complexity: O(n)


2. memoization

    we can improve upon our original approach by using memoization instead. whenever we come across a statee that we have already evalaueted before, we return the value.
    that way, we dont repeat calculations that have beend one before.

    Time complexity: O(n)
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
combinatoral search problem, apply the three-step system:

1. identify states
    what state do we need to know wheteher we have decoded a string?
        we can keep track of the number of digits we have already matched in index i. when i == length of digits, we have finished.

    what state do we need to decide which child nodes of the state-space tree should be visited next?
    since there's no constrint on which letters can be used for decoding, we dont need any state here

2. draw the sapce-state tree

3. DFS
    using the backtracking template as a basis, we add the state we identified in step 1:
        1. i for the number of digites we have already matched
    dfs returns the number of ways we can decode digits[i:]



    Time complexity: O(2^n)
    Space complexity: O()

    n is the length of the string. essentially at every digit, we either make a new number or add it to the old one. we can make this into linerar time through dp but currently we have a exponential time solutionm



Additional Notes 1:
    can start from the beginning of the string and try to decode eahc digit in the string until we get to the end of the string.

    each digit 1-9 maps to an alphabet. for digits 1 and 2, there is a possibility to decide two consecutive digits together.

    for example, there are 2 ways to decode 12:
        1. 1->a and 2->B
        2. 12 -> L
    
    there aare two ways to decide 23:
        1. 2->B, 6->F
        2. 26->Z
    
    there is only one way to decode 27
        2->B and 7->9 because there is no 27th alphabet
    
    its impossible to decode a strng with a leading 0 such as 02 because 0 does not map to any alphabet. the only wau to decode a strng with 0 is to have a preceeding 1 or 2 and decode as 10 and 20
    respectively.

    so depending on the current and folloing digit, there could be 0 to 2 ways to branch out.


Time complexity:
    in the worst case, every digit can decoded in 2 ways. with n digits, there are O(2^n) nodes in the state-space tree.
    We do O(1) operation for each node so the overall time compleixty is O(2^n)


Additional Notes(2)

    Similar to the previous problem, we see threre are duplicated subtrees.

    the green and red subtree contains the exact same content 3 and had the same prefix. the green subtree is visited before the red subtree and we can
    memoize the results from green subtree by keeping a memo array that records the start_index of the remaining strings to be decoded.

    Time complexity
        the time complexity of the memoization is the size of the memo array O(n) multiplied by the no of operations per state which is O(1). so the overall time complexity is O(n).
    
    Space complexity
        the height of the state-space tree is at most O(n). the size of the memo array is O(n). therefore the space complexdity is O(n).


*/



//  My approaches(1)
#include <iostream> // cin, cout
#include <string> // getline, string

int dfs(std::string & digits, int start, int step){
    if(start + step > digits.size())
        return 0;
    else{
        std::string sub = digits.substr(start, step);
        int intValue = std::stoi(sub);
        
        if(intValue < 0 || intValue > 26)
            return 0;
        else if(start + step == digits.size())
            return 1;
        return dfs(digits, start+step, 1) + dfs(digits, start+step, 2);
    }
}

int decode_ways(std::string digits) {
    // WRITE YOUR BRILLIANT CODE HERE
    return dfs(digits, 0, 1) + dfs(digits, 0, 2);
}

int main() {
    std::string digits;
    std::getline(std::cin, digits);
    int res = decode_ways(digits);
    std::cout << res << '\n';
}


// My Approaches(2)
#include <iostream> // cin, cout
#include <string> // getline, string
#include <unordered_map>
#include <utility>

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};


int dfs(std::string & digits, int start, int step, std::unordered_map<std::pair<int,int>, int, hash_pair> & memo){
    if(start + step > digits.size())
        return 0;
    else if(memo.find(std::make_pair(start, step)) != memo.end())
        return memo[std::make_pair(start, step)];
    else{
        std::string sub = digits.substr(start, step);
        int intValue = std::stoi(sub);        
        if(intValue < 0 || intValue > 26)
            return 0;
        else if(start + step == digits.size())
            return 1;
            
        int returnValue = dfs(digits, start+step, 1, memo) + dfs(digits, start+step, 2, memo);
        memo[std::make_pair(start, step)] = returnValue;
        return returnValue;
    }
}

int decode_ways(std::string digits) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_map<std::pair<int,int>, int, hash_pair> memo;
    return dfs(digits, 0, 1, memo) + dfs(digits, 0, 2, memo);
}

int main() {
    std::string digits;
    std::getline(std::cin, digits);
    int res = decode_ways(digits);
    std::cout << res << '\n';
}




//  Other Approaches(1)
int dfs(int start_index, std::string digits, std::string letters[26]) {
    if (start_index == digits.length()) return 1;
    
    int ways = 0;
    std::string remaining = digits.substr(start_index);
    for (int i = 0; i < 26; i++) {
        std::string prefix = letters[i];
        if (remaining.find(prefix) == 0) {
            ways += dfs(start_index + prefix.length(), digits, letters);
        }
    }
    return ways;
}

int decode_ways(std::string digits) {
    std::string letters[26];
    // use numbers 1 to 26 to represent all alphabet letters
    for (int i = 0; i < 26; i++) {
        letters[i] = std::to_string(i + 1);
    }
    
    return dfs(0, digits, letters);
}


// Other Approaches(2)
nt dfs(int start_index, std::string digits, std::string letters[26]) {
int dfs(int start_index, int memo[], std::string digits, std::string letters[26]) {
    if (start_index == digits.length()) return 1;
    
    if (memo[start_index] == -1) {
    int ways = 0;
        int ways = 0;
    std::string remaining = digits.substr(start_index);
        std::string remaining = digits.substr(start_index);
    for (int i = 0; i < 26; i++) {
        for (int i = 0; i < 26; i++) {
        std::string prefix = letters[i];
            std::string prefix = letters[i];
        if (remaining.find(prefix) == 0) {
            if (remaining.find(prefix) == 0) {
            ways += dfs(start_index + prefix.length(), digits, letters);
                ways += dfs(start_index + prefix.length(), memo, digits, letters);
            }
        }
        memo[start_index] = ways;
    }
    return ways;
    return memo[start_index];
}
int decode_ways(std::string digits) {
    std::string letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i] = std::to_string(i + 1);
    }
    
    return dfs(0, digits, letters);
    int memo[digits.length()];
    std::fill_n(memo, digits.length(), -1);
    return dfs(0, memo, digits, letters);


// Other Approaches(3)
int dfs(int startIndex, std::string digits) {
    if (startIndex == digits.length()) return 1;
    
    int ways = 0;
    // can't decode string with leading 0
    if (digits[startIndex] == '0') {
      return ways;
    }
    // decode one digit
    ways += dfs(startIndex + 1, digits);
    // decode two digits
    if (startIndex + 2 <= digits.length() && stoi(digits.substr(startIndex, 2)) <= 26) {
        ways += dfs(startIndex + 2, digits);
    }
    return ways;
}

int decode_ways(std::string digits) {
    return dfs(0, digits);
}


// Other Approaches(3)
#include <iostream> // cin, cout
#include <string> // getline

int dfs(int startIndex, std::string digits, int memo[]) {
    if (startIndex == digits.length()) return 1;
    if (memo[startIndex] != -1) return memo[startIndex];
    
    int ways = 0;
    // can't decode string with leading 0
    if (digits[startIndex] == '0') {
      return ways;
    }
    // decode one digit
    ways += dfs(startIndex + 1, digits, memo);
    // decode two digits
    if (startIndex + 2 <= digits.length() && stoi(digits.substr(startIndex, 2)) <= 26) {
        ways += dfs(startIndex + 2, digits, memo);
    }
    memo[startIndex] = ways;
    return ways;
}

int decode_ways(std::string digits) {
    int memo[digits.length()];
    std::fill_n(memo, digits.length(), -1);
    return dfs(0, digits, memo);
}

int main() {
    std::string digits;
    std::getline(std::cin, digits);
    int res = decode_ways(digits);
    std::cout << res << '\n';
}