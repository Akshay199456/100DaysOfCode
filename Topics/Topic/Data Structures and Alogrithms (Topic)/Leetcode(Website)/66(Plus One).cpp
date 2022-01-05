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
Space complexity: O(n) since you are basically pushing every entry to the right to insert 1.

This seems to be the most populat appraoch to the solution


2. Using no additional space.

Using a pointer that starts at the end of the array, we can traverse through the array and keep adding. If the number
only has 9s, it will return a carry of 1 at the end, we can then append a 0 to the end followed by converting the first
digit to a 1.   

Time complexity: O(n)
Space complexity: O(1)
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

// My Approaches(2)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size() - 1, carry = 1, sum = 0;
        while(end >= 0){
            sum = digits[end] + carry;
            digits[end--] = sum % 10;
            carry = sum / 10;
        }
        
        if(carry == 1){
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};