/*
Problem statement:

Given two strings, original and check, return the minimum substring of original such that each character in check, including duplicates, are included in this substring. By "minimum", I mean the shortest substring. If two substrings that satisfy the condition has the same length, the one that comes lexicographically first are smaller.

Parameters
original: The original string.
check: The string to check if a window contains it.
Result
The smallest substring of original that satisfy the condition.
Examples
Example 1
Input: original = "cdbaebaecd", check = "abc"

Output: baec

Explanation: baec is the shortest substring of original that contains all of a, b, and c.

Constraints
1 <= len(check), len(original) <= 10^5
original and check both contains only upper case and lower case characters in English. The characters are case sensitive.
*/

/*
-------------------------    My Approaches:
1. two pointer: sliding window of varying size aproach

    this problem is very simila rto pb 20 excpt here that the window can vary in order to accomondate the minimum substring.
    if it si a vlaid substring, we  check if it sis a ebtter solution and if so, record it. if not a better solution we cna just move left forard and see if we can get nything better.
    otherwise, we re cord the valur at right and move right forward

    it is constant time to compare the substing since there is at most 52 characers so it is fixed in comparison.    

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
solution similar to find all anagrams in a string except instead of amtching exactly, we are to find a window that contains all characters
in check. in this case, the comparison for checking valdid woindow is changed to compare that for every character in check, see if the window contains more of that charcter

in addition, the movingin conditions of the window changes as well. instead of two pointers moving at once, maintinaing of he size of the window, each pointer moves independently.
wehnt he windows does not contain check, we move the end pointer until t does (or it reaches the end), then we mvo teh start poonter until the window is no longer contains checkk. in this case, just
before moving the winwo was the local minimial substring. then, its a simple matter of comparing local minimal substring and find the minimum one.

    Time complexity: O(n)
    Space complexity: O()


Additional Notes:
    the solution is similar to find longest subarray with sum smaller than target, its a find longest sliding window problem.
    
    in this case, the compairson for checking valid window is changed to compare that for every character in check, see if the window contains enough of that character.

    we could apply the find longest sliding window template to this question. to check the validity of a window, we introduce two variables (counters): required and satisfied.
        1. required: the number of distinct characters we are required to have. counter for distinct characters that appeared in check.
        2. satisfied: the no of distinct characters that are satisified within the cirrent window. now, we can check whether required == satisfied to confirm if the windo is valid.
    
    since we only care about those characters that appears in check, so we wukk only make changes to satisfied when the 
    added/removed character appears in check. if the current window contains exactly the same amoiunt of one
    specific character as in check after adding the counter, then we increase satisified by 1 (we will not update satisfied on all other additions).
    if we remmoved a character from the window and that character is part of check, we check whetehr the amount has dropped below check's amoiunt.

    Time complexity: O(n)
    Space complexity: O(n)
*/



//  My approaches(1)
#include <iostream> // cin, cout
#include <string> // getline, string
#include <vector>
#include <limits>

int getIndex(char letter){
    int index = tolower(letter) - 'a';
    std::string s(1,letter);
    if(isupper(letter))
        index += 26;
//     std::cout<<"character: "<<s<<" Index: "<<index<<std::endl;
    return index;   
}


bool isSubstring(std::vector<int> & checkMap, std::vector<int> & origMap, int maxSize){
    for(int i=0; i < maxSize; i++){
//         std::cout<<"i: "<<i<<" checkmap: "<<checkMap[i]<<" origMap: "<<origMap[i]<<std::endl;
        if(checkMap[i] != 0 && checkMap[i] > origMap[i])
            return false;
    }
    return true;
}

std::string get_minimum_window(std::string original, std::string check) {
    // WRITE YOUR BRILLIANT CODE HERE
    int maxSize{52}, left{0}, right{0}, windowSize{std::numeric_limits<int>::max()};
    std::vector<int> checkMap(maxSize, 0), origMap(maxSize, 0);
    std::string result = "";
    
    // create map for check
    for(int i=0; i < check.size(); i++){
        int index = getIndex(check[i]);
        checkMap[index]+=1;
    }
    
    while(right < original.size()){
        if(isSubstring(checkMap, origMap, maxSize)){
            // if it's a better solution
            int index = getIndex(original[left]);
            if(result == "" || (right-left < windowSize) || ((right-left == windowSize) && (original.substr(left, right-left)).compare(result) < 0)){
                windowSize = right-left;
                result = original.substr(left, right-left);
//                 std::cout<<"Result: "<<result<<std::endl;
            }
            origMap[index] -= 1;
            left++;
        }
        else{
            int index = getIndex(original[right]);
            origMap[index] +=1;
            right++;
        }
    }
    
    // check the last susbtring after the end of the loop since that has not been consdiered
    while(right == original.size()){
        if(isSubstring(checkMap, origMap, maxSize)){
            // if it's a better solution
            int index = getIndex(original[left]);
            if(result == "" || (right-left < windowSize) || ((right-left == windowSize) && (original.substr(left, right-left)).compare(result) < 0)){
                windowSize = right-left;
                result = original.substr(left, right-left);
            }
            origMap[index] -= 1;
            left++;
        }
        else
            ++right;
    }
    
    return result;
}

int main() {
    std::string original;
    std::getline(std::cin, original);
    std::string check;
    std::getline(std::cin, check);
    std::string res = get_minimum_window(original, check);
    std::cout << res << '\n';
}



//  Other Approaches(1)
#include <iostream> // cin, cout
#include <string> // getline, string
#include <unordered_map> // unordered_map

// Change the number of char c inside the window by "delta"
// Automatically increase or decrease "satisfy_count" to reflect the current value.
// Returns the new "satisfy_count"
int delta_char(char c, int delta, int satisfy_count, std::unordered_map<char, int>& check_count, std::unordered_map<char, int>& window_count) {
    if (!window_count.count(c)) {
        window_count[c] = 0;
    }
    if (window_count[c] >= (check_count.count(c) ? check_count[c] : 0)) {
        satisfy_count -= 1;
    }
    window_count[c] += delta;
    if (window_count[c] >= (check_count.count(c) ? check_count[c] : 0)) {
        satisfy_count += 1;
    }
    return satisfy_count;
}

std::string get_minimum_window(std::string original, std::string check) {
    // Counts the number of each character of "check"
    std::unordered_map<char, int> check_count;
    for (char c: check) {
        if (check_count.count(c)) {
            check_count[c] += 1;
        } else {
            check_count[c] = 1;
        }
    }
    // Counts the number of each character in the sliding window
    std::unordered_map<char, int> window_count;
    // Count the number of entries in "check_count" that is smaller than or equal to that in "window_count"
    // If "satisfy_count" is equal to the number of entries in "check_count", that window contains "check".
    // We then just need to check if its the minimum.
    int satisfy_count = 0;
    int original_len = original.size();
    // Two pointers pointing to the window (inclusive start, exclusive end)
    int start_ptr = 0, end_ptr = 0;
    // The number of entries in "check_count". Used to check if "window_count" contains "check_count"
    int match_req = check_count.size();
    // The smallest recorded string that satisfies the conditions
    std::string smallest_str;
    while (end_ptr < original_len) {
        // Moves the end pointer until it contains "check" or it reaches the end
        while (end_ptr < original_len && satisfy_count < match_req) {
            satisfy_count = delta_char(original[end_ptr], 1, satisfy_count, check_count, window_count);
            end_ptr++;
        }
        // If the window reaches the end and does not contain "check", break loop
        if (end_ptr == original_len && satisfy_count < match_req) break;
        // Otherwise, the window contains "check", so we move the start pointer
        // until it no longer does. Then, the one before failing the check is the local
        // minimal substring.
        while (satisfy_count >= match_req) {
            satisfy_count = delta_char(original[start_ptr], -1, satisfy_count, check_count, window_count);
            start_ptr++;
        }
        std::string valid_window = original.substr(start_ptr - 1, end_ptr - start_ptr + 1);
        // Compare the local minimum to the stored smallest string
        // If there is nothing stored, or the condition outlined is true, we store the string
        if (smallest_str == "" || smallest_str.size() > valid_window.size()) {
            smallest_str = valid_window;
        } else if (smallest_str.size() == valid_window.size() && valid_window < smallest_str) {
            smallest_str = valid_window;
        }
    }
    return smallest_str;
}

int main() {
    std::string original;
    std::getline(std::cin, original);
    std::string check;
    std::getline(std::cin, check);
    std::string res = get_minimum_window(original, check);
    std::cout << res << '\n';
}


// Other Approaches(2)
#include <iostream> // cin, cout
#include <string> // getline, string
#include <unordered_map> // unordered_map

std::string get_minimum_window(std::string original, std::string check) {
    std::unordered_map<char, int> check_count;
    for (char c: check) { ++check_count[c]; }
    
    std::unordered_map<char, int> window_count;
    int m = original.size();
    int window = -1, length = m+1;
    int satisfied = 0, required = check_count.size();
    int l = 0;    
    
    for (int r = 0; r < m; ++r) {
        if (check_count.count(original[r])) {
            window_count[original[r]]++;
            if (window_count[original[r]] == check_count[original[r]]) {
                satisfied++;
            }
        }
        while (satisfied == required) {    
            if (r-l+1 < length ||
              (r-l+1 == length && original.compare(l, length, original, window, length) < 0)) { 
                window = l;
                length = r-l+1;
            }
            if (check_count.count(original[l])) {     // delete only characters from check
                window_count[original[l]]--;
                if (window_count[original[l]] < check_count[original[l]]) { // removing original[l] makes window dissatisfied
                    satisfied--;
                }
            }
            l++;
        }
    }
    return (window >= 0)? original.substr(window, length) : "";
}

int main() {
    std::string original;
    std::getline(std::cin, original);
    std::string check;
    std::getline(std::cin, check);
    std::string res = get_minimum_window(original, check);
    std::cout << res << '\n';
}
