/*
Problem statement:

etermine whether a string is a palindrome, ignoring non-alphanumeric characters and case. Examples:

Input: Do geese see God? Output: True

Input: Was it a car or a cat I saw? Output: True

Input: A brown fox jumping over Output: False


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
intuition

this is a straightforward two-poointer problem. we have two pointers l and r, starting from the leftmost and rightmost positions and moving towards each other.
at each step,
    1. if the elements they point to are the same, then we move each pointer one position towards each other;
    otherwise, the string is not a palindrome.

note that the problem asks us to ignor all non-alphanumeric characters. so any time we see one we have to skip it by incrementing one position
only for the correspondong pointer.

the implementation is relatively strightforward.

note that:
    1. we need a while loop here because there could be multiple non-alphanummeric characters in a row and we want to skip all of them
    2. we need to do bound checking in the inner while loop too since while oincrementing l/decremening r, th eouter loop condition
    l < r could be broken and the enxt line if s[l].lower() != s[r].lower() would be invalid when l<r does not hold.

    Time complexity: O(n)
        since we nl look at each character at mos once and space complexity is O(1) since we didnt allocate a dynamic amount of memory
    Space complexity: O(1)




Alternative solution

an easier and less error-prone way is to filter the non-alphanumeric characters first and then valudate palindromeness.
the time comlexity is still O(n). although, since strings are immutable is most mainstream languages, fiulktering requires allocating a new string so space
complexity would be O(n) where n is the length of the string. the sapce complexity is O(n) as we are creating a new list of at most size N.
*/



//  My approaches(1)



//  Other Approaches(1)
#include <cctype> // isalnum, tolower
#include <iostream> // boolalpha, cin, cout
#include <string> // getline

bool is_palindrome(std::string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        // Note 1, 2
        while (l < r && !std::isalnum(s[l])) {
            l++;
        }
        while (l < r && !std::isalnum(s[r])) {
            r--;
        }
        // compare characters ignoring case
        if (std::tolower(s[l]) != std::tolower(s[r])) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    bool res = is_palindrome(s);
    std::cout << std::boolalpha << res << '\n';
}



// Other Approaches(2)
include <cctype> // isalnum, tolower
#include <iostream> // boolalpha, cin, cout
#include <string> // getline
#include <vector> // vector

bool is_palindrome(std::string s) {
    std::vector<char> arr;
    for (char c : s) {
        if (std::isalnum(c)) arr.emplace_back(std::tolower(c));
    }

    int l = 0, r = arr.size() - 1;
    while (l < r) {
        if (std::tolower(arr[l]) != std::tolower(arr[r])) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    bool res = is_palindrome(s);
    std::cout << std::boolalpha << res << '\n';
}

