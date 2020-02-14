/*
-------------------------Question:

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

*/

/*
-------------------------    My Approaches:

1. 

This involved using 2 pointers to keep track of the end and the start. For every swap,
the start was moved forward while the end was moved backward by 1 place. We continue this till
the middle of the array is obtained.

Time complexity: O(n/2) -> O(n)
Space complexity: O(1)

*/

// My approaches(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < end)
            swap(s[start++], s[end--]);  
    }
};