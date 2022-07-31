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


    Time complexity: O()
    Space complexity: O()
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
