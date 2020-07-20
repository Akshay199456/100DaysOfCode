// This problem was also solved through codepath.

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

/*
-------------------------    Codepath My Approaches:

1. 

Same as My Approches(1) but in python

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


// Codepath my approaches(1)
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        """
        1. Understand:
        
            write function that reverses string
            input is array of characters
            must do it in place without extra allocation for another array - O(1) space
            contains printable ascii characters

            Can it contain symbols - yes

        2. Match:
            
            two pointer approach where pointer at beginning and end
            
        3. Plan:
        
            Going to use two pointer approach to reverse string. swap characters at the pointers and then push
            pointers forward and backward.
            
        4. Implement
        
        5. Review
        
        6. Evaluate
            Time complexity: O(n)
            Space complexity: O(1)
        
        """
        length = len(s)
        for index in range(length // 2):
            temp = s[index];
            s[index] = s[length - index - 1]
            s[length - index - 1] = temp