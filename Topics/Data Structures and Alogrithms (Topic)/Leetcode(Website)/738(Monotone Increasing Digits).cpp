/*
-------------------------Question:

Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9
Example 2:
Input: N = 1234
Output: 1234
Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].
*/

/*
-------------------------    My Approaches:
1. Greedy approach

This problem can be solved using a greedy approach heuristic. The goal given to us is to produce a monotone increasing sequence where x<=y in digits. As a result, when we are going through the number as a string, we need to find the first
point from the left where the monotoonic sequence is broken. From a greedy approach, all the digits from this digit should be set to 9. For example, if we were given 200, the answer would be 199. Thus, any digit after 2 would be set to 9 in order to maximize
the result. We then fixe the monotonic sequence before the fault and keep fixing it till the sequnce before the fualt is also monotonically increasing. In the example, 200, to obtain the max monotonic number less than or equal to 200, 
the best possible way to maiximze the sequence would be to change the 0 in 20 to a 9 and decrease the 2 by 1 to a 1 to give us the number 190. We would then have to fix the last 0 and the only way to make it monotocially
increasing is by changing that 0 to a 9 to be in accorance with the previous digit

Time complexity: O(n)
Space complexity: O(n)

*/

/*
-------------------------    Other approaches:

*/

// My Approaaches(1)
class Solution {
public:
    bool checkMonotone(string stringValue){
        for(int i=1; i<stringValue.size(); i++){
            if(stringValue[i-1] > stringValue[i])
                return false;
        }
        return true;
    }
    
    int maxMonotone(string stringValue){
        int faultIndex = 0;
        bool isEnd = false;
        for(int i=1; i<stringValue.size() && !isEnd; i++){
            if(stringValue[i] < stringValue[i-1]){
                faultIndex = i;
                isEnd = true;
                stringValue[i-1] = ((stringValue[i-1] - '0')-1) + '0'; 
            }
        }
        
        isEnd = false;
        
        // change to all 9s starting from faultIndex to allow monotone sequence after faultIndex
        for(int i=faultIndex; i < stringValue.size(); i++)
            stringValue[i] = '9';
        
        // fix the monotone sequence before faultIndex
        for(int i=faultIndex-1; i>0 && !isEnd; i--){
            if(stringValue[i] <  stringValue[i-1]){
                stringValue[i] = '9';
                stringValue[i-1] = ((stringValue[i-1] - '0')-1) + '0'; 
            }
            else
                isEnd = true;
        }
        
        return stoi(stringValue);
    }
    
    int monotoneIncreasingDigits(int N) {
        string stringValue = to_string(N);
        if(stringValue.size() == 1 || checkMonotone(stringValue))
            return N;
        return maxMonotone(stringValue);
    }
};