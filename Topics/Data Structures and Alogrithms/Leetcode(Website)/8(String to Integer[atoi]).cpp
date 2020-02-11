/*
-------------------------Question:

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/

/*
-------------------------    My Approaches:

This approach uses modularity to assign different responsibilities to each function. While not
complicated, it does involve using checks at certain intervals to make sure that the approach works.
For this problem, I will comment the code and explain it there instead of explaining the solution
in this section.

Time complexity: O(n)
Space complexity: O(1)

*/

/*
-------------------------    Other approaches:

1. (Same)

This approach uses the same logic as in **My approaches(1)** but does it more concisely in its
code. As a result, it's way more beautiful code written by someone else. Will comment the code
to explain the logic utilized to make it more concise.

Time complexity: O(n)
Space complexity: O(n)
*/


// My approaches(1)
class Solution {
public:
    int checkFirstCharacterValid(string element){
    	/*
		
		This function is part of the core functionality of the algorithm.

    	Purpose of this function is to check if the first character that's encountered in the string
    	that's not a space character(' ') is a valid character in the form of '+', '-' or a digit.
    	If so, we return the index of the character so the other functions can continue the rest
    	of the operation to determine the value from that index.

    	If it's not a valid character, we return -1.
    	*/
        int index = 0;
        while(index < element.size()){
            if(element[index] == ' ')
                index++;
            else if(element[index] == '+' || element[index] == '-' || isdigit(element[index]))
                return index;
            else
                return -1;
        }
        return -1;
    }
    
    int checkSignValue(int sign){
    	/*
    	This function is only called if the value embedded in the int variable exceeds the 
    	MAX_INT or MIN_INT value.

    	If the value of the sign is 1, we return the INT_MAX else we return INT_MIN.
    	*/
         if(sign == 1)
             return INT_MAX;
        else
            return INT_MIN;
    }
    
    int checkRemainingDigits(string element, int index){
    	/*
    	This function is  called to check the remaining valid digits in an element if we are about
    	to hit the overflow condition of INT_MAX/10.

    	If no valid digits exist, we return 0; if one exists, return 1; for more than one valid
    	digit, we return 2.
    	*/
        if(index+1 < element.size() && isdigit(element[index+1])){
            if(index + 2 < element.size() && isdigit(element[index+2]))
                return 2;
            else
                return 1;
        }  
        else
            return 0;
    }
    
    int calculateIntValue(string element, int index){
    	/*
    	Core function to calculate the int value embedded in the string.
    	*/
        int sign = 1, total = 0;
        // If the current index is a '+' or '-', we adjust the sign bit accordingly and continue
        // the rest of the string.
        if(element[index] == '+')
            index++;
        else if(element[index] == '-'){
            sign = -1;
            index++;
        }
        
        while(isdigit(element[index]) && index < element.size()){
            int value = element[index] - '0';
            total = total * 10 + value;
            int nDigits = checkRemainingDigits(element, index); 
            if(total > INT_MAX / 10){
            	/* 
            	If the overflow condition is met but we don't have any additional digits, we know
            	that it doesn't exceed the INT_MAX and so return the value multiplied by the 
            	respective sign. Else we return INT_MAX or INT_MIN depending on the sign bit. 
            	*/
                if(!nDigits)
                    return total * sign;
                else
                    return checkSignValue(sign);
            }
                
            else if(total == INT_MAX / 10){
            	/* 
            	If the overflow condition is met but we don't have any additional digits, we know
            	that it doesn't exceed the INT_MAX and so return the value multiplied by the 
            	respective sign. If we have one digit remaining, we need to check if that digit
            	exceeds the overflow or not. If it does, we return INT_MAX or INT_MIN. If it doesn;t
            	we return the embedded value. 
            	If more than one digit, we return INT_MAX or INT_MIN depending on the sign bit. 
            	*/
                if(!nDigits)
                    return total * sign;
                else{
                    if(nDigits == 1){
                        int nextValue = element[index+1] - '0';
                        if( nextValue > 7)
                            return checkSignValue(sign);
                        else{
                            total = total * 10 + nextValue;
                            return total * sign;
                        }
                    }      
                    else
                        return checkSignValue(sign);
                }
            }
            // Increment the current index to the next value
            index++;
        }   
        return total * sign;
    }
    
    int myAtoi(string str) {
        int isValidIndex = checkFirstCharacterValid(str);
        if(isValidIndex == -1)
            return 0;
        else
            return calculateIntValue(str, isValidIndex);
    }
};


// Other approaches(1)
class Solution {
public:
    int skipSpaces(string str){
    	/*
    	Skips through spaces so that either '+', '-' or a digit is the first occurrence.
    	*/
        int index = 0;
        while(str[index] == ' ' && index < str.size())
            index++;
        return index;
    }
    
    int myAtoi(string str) {
        int index  = skipSpaces(str), sign = 1, total = 0;

        /*
        If the current character is '+', the expression returns false and sign gets value 1.
        Instead, the current character is '-', the expression returns true and sign gets value -1.
        */
        if(str[index] == '+' || str[index] == '-')
            sign = 1 - 2 * (str[index++] == '-');
        
        // As long as character is a digit
        while(str[index] >= '0' && str[index] <= '9'){
        	/*
        	Makes the check in beginning itself to verify if overflow has occurred
        	*/
            if(total > INT_MAX/10 || (total == INT_MAX/10 && str[index] > '7')){
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            
            // Updates total with the representation of the current character and increments index
            // At any point, if we hit an invalid character, we come outside of the while loop
            // and return the total * sign. If it hits overflow, we return INT_MAX or INT_MIN
            // depending on sign.
            total = 10 * total + (str[index++] - '0'); 
        }
        return total * sign;
    }
};
