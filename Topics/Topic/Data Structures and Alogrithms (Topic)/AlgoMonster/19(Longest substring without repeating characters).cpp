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
intuituon

the brute force approach is to check every single substring and count he oines with non-repeating characters. a substring is defined by a start index and end index

to improve on brute force, we have to skip unnecessary operations. for a substring start with start that already contains one 
duplicate chaacter, we want to stop checking  more substring with the start index. when this happens we want to increment start and look at the next set of substirngs.

this makes it a classic sliding window problem. a sliding winodw is defined by two pointers mmoving in the same direction. we move the window
(incrementing pointers) whoile maintaining a certain invariant. for this particular problem, the invariant  is the characters inside the window being unique.
we use a set to record what's in the winodw. and when we encounter a character that's already in the window, we want to move the left pointer until it goes past the last occurentce of that 
character

    Time complexity: O(n)
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
#include <algorithm> // max
#include <iostream> // cin, cout
#include <string> // getline
#include <unordered_set> // unordered_set

int longest_substring_without_repeating_characters(std::string s) {
    int n = s.size();
    int longest = 0;
    int l = 0, r = 0;
    std::unordered_set<char> window;
    while (r < n) {
        if (!window.count(s[r])) {
            window.emplace(s[r]);
            r++;
        } else {
            window.erase(s[l]);
            l++;
        }
        longest = std::max(longest, r - l);
    }
    return longest;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    int res = longest_substring_without_repeating_characters(s);
    std::cout << res << '\n';
}
