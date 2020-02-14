/*
-------------------------Question:

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

/*
-------------------------My Approaches:

1.

My approach to this problem was to try to minimize the time take by the algorithm in the general case
while taking up O(n) time in the worst case scenario. As a result, I kept a count of the number of nine
encountered. Only if the number of nine encountered were equal to size of the array should we append a 1
to the beginning of the array. Else, we keep calculating the sum till the extent to which the carry is 0
as we are modifying the original vector.

Time complexity: O(n) only in the worst case (999, 9999)
Space complexity: O(1)

This seems to be the most populat appraoch to the solution
*/

// My approach(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        int countNine = 0;
        int carry = 1;
        while((index >= 0) && ( carry == 1 )){
            digits[index] += carry;
            if(digits[index] == 10){
                countNine += 1;
                digits[index] = 0;
            }
            else
                carry = 0;
            --index;
        }
       
        if(countNine == digits.size())            
            digits.insert(digits.begin(), 1);
        
        return digits;      
    }
};