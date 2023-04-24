/*
Problem statement:

Given a string s, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result. If not possible, return the empty string.

Example 1:
Input:s = "aab"
Output: aba
Example 2:
Input:s = "aaab"
Output: ``
Note:
s will consist of lowercase letters and have length in range [1, 500].
*/

/*
-------------------------    My Approaches:
1. 

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
solution:
    we divide the indices of the string into two: odds and evens. in that case, elements with odd indices can only be adjacent to
    element with even indices and vice-versa. note that because the index starts at zero, there will always be more or equal evens than odds. if there
    are more of one character than the number of evens, it is impossible to rearrange the string so no adjacent characters are the same. otherwise, we can start from the character that
    occurs the most and fill out spots with even indices. once we run out of spots to fill, we fill out the spots with odd indices.
    in this case, the result will guarantee to have no same adjacent characters

    for implementation, we use a heap to guarantee the character that is repeated the most is processed first, and because the character repeated the most changes as we process more characters.

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
include <iostream> // cin
#include <queue> // priority_queue
#include <string> // getline, string
#include <unordered_map> // unordered_map

std::string reorganize_string(std::string s) {
    int n = s.size();
    std::unordered_map<char, int> char_count;
    for (char c : s) {
        if (char_count.count(c)) {
            char_count[c] += 1;
        } else {
            char_count[c] = 1;
        }
    }
    // Use a max heap to compare the multiplicity of each character
    auto compare = [](std::pair<char, int>& a, std::pair<char, int>& b) {
        // use < for max heap
        return a.second < b.second; 
    };
    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(compare)> heap(char_count.begin(), char_count.end(), compare);
    // Return the empty string if there are too many of one character
    if (heap.top().second > (n + 1) / 2) return "";
    // Stores the resulting char array to be converted to string
    std::vector<char> res(n);
    // Pointer to the next item to be inserted
    // Increment by 2 until it reaches the end to fill out even positions,
    // then it is reset to 1 to fill out odd positions
    int ptr = 0;
    // Insert characters into the char array by their multiplicity
    while (heap.size() > 0) {
        std::pair<char, int> pairing = heap.top();
        heap.pop();
        for (int i = 0; i < pairing.second; i++) {
            res[ptr] = pairing.first;
            ptr += 2;
            if (ptr >= n) ptr = 1;
        }
    }
    std::string res_str(res.begin(), res.end());
    return res_str;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string res = reorganize_string(s);
    if (res.size() == 0) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }
    std::unordered_map<char, int> s_counter;
    std::unordered_map<char, int> res_counter;
    for (char c : s) {
        if (s_counter.count(c)) {
            s_counter[c] += 1;
        } else {
            s_counter[c] = 1;
        }
    }
    for (char c : res) {
        if (res_counter.count(c)) {
            res_counter[c] += 1;
        } else {
            res_counter[c] = 1;
        }
    }
    if (s_counter != res_counter) {
        std::cout << "Not rearrangement" << std::endl;
        return 0;
    }
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] == res[i + 1]) {
            std::cout << "Same character at index " << i << " and " << i + 1 << '\n';
        }
    }
    std::cout << "Valid" << std::endl;
}