/*
Problem statement:

Given a string original and a string check, find the starting index of all substrings of original that is an anagram of check. The output must be sorted in ascending order.

Parameters
original: A string
check: A string
Result
A list of integers representing the starting indices of all anagrams of check.
Examples
Example 1
Input: original = "cbaebabacd", check = "abc"

Output: [0, 6]

Explanation: The substring from 0 to 2, "cba", is an anagram of "abc", and so is the substring from 6 to 8, "bac".

Example 2
Input: original = "abab", check = "ab"

Output: [0, 1, 2]

Explanation: All substrings with length 2 from "abab" is an anagram of "ab".

Constraints
1 <= len(original), len(check) <= 10^5
Each string consists of only lowercase characters in standard English alphabet.
*/

/*
-------------------------    My Approaches:
1. sliding window of fixed size

    this sis  asldiding window problem of fixed size. till we hit the length of check, we cna keep adding characters to the map
    . however, once we hit the length we make the check for whether the vectors(which are the maps for us) are equal and if so,
    we push in the index where left is currently. in all cases in this scenario, we push the left poitner formward.
    we can ssume the check for equality of the map of check and original to be constant since we aknow we are dealing with
    only lowercase characters in the englsih alphabet and there are 26 at most so the size is a constant when we make a comparative check.

    also, when right pointer arrives at the end of the loop, there is always one condition that is still elft to check i.e wen
    right-1 value has been isnerted and has mvoed forward and left at its position. that is why, we make a check for this at the end of the loop. 

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
classical sliding window problem. sliding window is maintained at the size of check, and we keep track if the number of each type of characters
inside the wndow in a hashmap. everyc cycle, we move the window to the right, pushing the rightost character while pooing the leftmost
character. we check that at any given time, if the content of the set matches the character count of check, by definition, that substring is an anagram and we can isner the index into the resulting list

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)

#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // ostream_iterator, prev
#include <string> // getline, string
#include <vector> // vector

std::vector<int> find_all_anagrams(std::string original, std::string check) {
    // WRITE YOUR BRILLIANT CODE HERE
    int charSize{26}, left{0}, right{0};
    std::vector<int> checkMap(charSize,0), origMap(charSize, 0);
    std::vector<int> result;
    
    // get map for check
    for(int i=0; i<check.size(); i++){
        int index = check[i] - 'a';
        checkMap[index] += 1;
    }
    
    // generate map for original as we go
    while(right < original.size()){
        if(right-left+1 <= check.size()){
            int index = original[right] - 'a';
            origMap[index] += 1;
            ++right;
        }
        else{
            if(checkMap == origMap)
                result.push_back(left);
            int index = original[left] - 'a';
            origMap[index] -= 1;
            ++left;
        }
    }
    
    if(checkMap == origMap)
        result.push_back(left);
    
    
    return result;
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::string original;
    std::getline(std::cin, original);
    std::string check;
    std::getline(std::cin, check);
    std::vector<int> res = find_all_anagrams(original, check);
    put_words(res);
}


//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // ostream_iterator, prev
#include <string> // getline
#include <vector> // vector

std::vector<int> find_all_anagrams(std::string original, std::string check) {
    // check_length is the window size
    int original_length = original.length(), check_length = check.length();
    if (original_length < check_length) return {};
    
    std::vector<int> res;
    // stores the frequency of each character in the check string
    std::vector<int> check_counter(26, 0);
    // stores the frequency of each character in the current window
    std::vector<int> window(26, 0);
    // first window
    for (int i = 0; i < check_length; i++) {
        check_counter[check[i] - 'a']++;
        window[original[i] - 'a']++;
    }
    if (window == check_counter) res.emplace_back(0);

    for (int i = check_length; i < original_length; i++) {
        window[original[i - check_length] - 'a']--;
        window[original[i] - 'a']++;
        if (window == check_counter) {
            res.emplace_back(i - check_length + 1);
        }
    }
    return res;
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::string original;
    std::getline(std::cin, original);
    std::string check;
    std::getline(std::cin, check);
    std::vector<int> res = find_all_anagrams(original, check);
    put_words(res);
}
