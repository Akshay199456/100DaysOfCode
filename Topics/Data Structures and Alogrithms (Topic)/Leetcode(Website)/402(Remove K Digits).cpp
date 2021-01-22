/*
-------------------------Question:

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/*
-------------------------    My Approaches:
1. Greedy Approach

This problem can be solved with a greedy approach. If we think about the problem and want to remove the digits such that the whole number is minizmed, well we then need to remove the digits such that it happens. Our first though might
be to remoe the digits that are hold the highest value in the string. Howevr, if we follow that,we will soon recognize a quick understanding. The position where the digit lies is way more important than what is the digit. As a result,
we need to remove the digits at positions where they exert the main influence.This happens at digits where is a drop from a higher value. For example, in 1432, there is a drop going from 4->3. As a result, since this digit holds a strong
value within its vicinity, removing it would minimze theat value within that vicinity. As a result, we need to continue doing this pattern for all the ks possiblem in order to minimze the toal value associated with the number.

Time complexity: O(kn)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

/*
Maybe use two pointer to optimize it

int slowPtr = 0, fastPtr = 1;
        while(fastPtr < num.size() && k > 0){
            while(num[slowPtr] == '#')
                slowPtr--;
            
            if(num[fastPtr] < num[slowPtr]){
                num[slowPtr] = '#'
            }
        }
*/

// My Approaches(1)
class Solution {
public:
    string removeLeadingZeroes(string num){
        int firstNonZeroIndex = -1;
        bool isEnd = false;
        for(int i=0; i<num.size() && !isEnd; i++){
            if(num[i] != '0'){
                isEnd = true;
                firstNonZeroIndex = i;
            }
        }
        
        if(!isEnd)
            return "0";
        return num.substr(firstNonZeroIndex, num.size() - firstNonZeroIndex);
    }
    
    string getMinValue(string num, int k){
        int startIndex = 0;
        while(startIndex < num.size() && k > 0){
            // cout<<"StartIndex: "<<startIndex<<" Num size: "<<num.size()<<" k: "<<k<<endl;
            if(startIndex == 0 || num[startIndex] >= num[startIndex-1])
                ++startIndex;
            else{
                num = num.substr(0, startIndex-1) + num.substr(startIndex, num.size() - startIndex);
                // cout<<"New number: "<<num<<endl;
                startIndex--;
                k--;
            }
        }
        
        if( k > 0){
            num = num.substr(0, num.size() - k);
            // cout<<"Final num: "<<num<<endl;
        }
        
        // cout<<"Num before filter: "<<num<<endl;
        num = removeLeadingZeroes(num);
        // cout<<"Num after filter: "<<num<<endl;
        return num;
    }
    
    string removeKdigits(string num, int k) {
        if(k <= 0)
            return num;
        else if(num.size() == k)
            return "0";
        return getMinValue(num, k);
    }
};