/*
Problem statement:

Find the length of the longest substring of a given string without repeating characters.

Input: abccabcabcc

Output: 3

Explanation: longest substrings are abc, cab, both of length 3

Input: aaaabaaa

Output: 2

Explanation: ab is the longest substring, length 2
*/

/*
-------------------------    My Approaches:
1. Sliding Window

    we can apply the sliding window approach to this problem since it invovlves workign with substrings.
    we also make use of a mapp to record if the character has beene cnpiuntered or not. if it has,. then we need to skip characters form the beginning
    till the character at right is removed. after that we can start expanding right as long as we dnt come across a character we came across before.

    Time complexity: O(n)
    Space complexity: O(1)
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
#include <iostream> // cin, cout
#include <string> // getline, string
#include <unordered_map>

int longest_substring_without_repeating_characters(std::string s) {
    // WRITE YOUR BRILLIANT CODE HERE
    int left{0}, right{0}, maxLength = 0;
    std::unordered_map<char,int> elementCount; 
    while(right < s.size()){
        if(elementCount.find(s[right]) == elementCount.end()){
            elementCount[s[right]] += 1;
            maxLength = std::max(maxLength, right-left+1);
            ++right;
        }
        else{
            elementCount[s[left]] -= 1;
            if(!elementCount[s[left]]) 
                elementCount.erase(s[left]);
            ++left;
        }
    }
    return maxLength;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    int res = longest_substring_without_repeating_characters(s);
    std::cout << res << '\n';
}



//  Other Approaches(1)
