/*
-------------------------Question:
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

/*
-------------------------My Approaches:
1.

This approach goes step by step through each string to find if the current character that's being
evaluated to check if it exists in the next string. It keeps continuing this till a mismatch occurs
or the end of the string occurs and then returns the result.

Time complexity: O(nk)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

1. Horizontal scanning (Same)

Finds the longest prefix with pair of strings and continues that till all the strings are 
analyzed.

[Check images in image folder to get a better idea of this approach]

Time complexity : O(S) , where S is the sum of all characters in all strings.

In the worst case all n strings are the same. The algorithm compares the string S1S1 with the other
strings [S_2 \ldots S_n][S 2…S n]
 There are SS character comparisons, where SS is the sum of all characters in the input array.

Space complexity : O(1). We only used constant extra space.



2. Vertical Scanning (Same)

Basically the approach I did.

Time complexity : O(S) , where S is the sum of all characters in all strings. 
In the worst case there will be nn equal strings with length mm and the algorithm performs 
S = m \cdot nS=m⋅n character comparisons. Even though the worst case is still the same as 
Approach 1, in the best case there are at most n \cdot minLenn⋅minLen comparisons where 
minLenminLen is the length of the shortest string in the array.

Space complexity : O(1). We only used constant extra space.


3. Divide and Conquer (Worse)

We can also use the divide and conquer approach to solve this problem. The exit condition is when
we hot only a single string. At the end of the divide method, we are left with 2 single string
elements which we then combine to find the longest prefix and return that.

Time complexity: O(S)
Space complexity: O(m * log N)
	- log N since we have n recursive calls and at each of the calls we use up O(m) memory
	to store the result


*/

// My Approaches(1)
class Solution {
public:
    string longestPrefix(vector<string> strs){
        string result = "";
        string begElement = strs[0];
//         i -> character; j -> string element
        for( int i = 0; i < begElement.size(); i++){
            for( int j = 1; j < strs.size(); j++){
                string currElement = strs[j];
                if( (i == currElement.size()) || (begElement[i] != currElement[i]))
                    return result;
            }
            result.push_back(begElement[i]);
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        else if(strs.size() == 1)
            return strs[0];
        else
            return longestPrefix(strs);
    }
};

// Other approaches(3)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        else if(strs.size() == 1)
            return strs[0];
        else 
            return longestPrefix(strs, 0, strs.size() - 1);
    }
    
    string longestPrefix(vector<string> strs, int beg, int end){
        if(beg == end)
            return strs[beg];
        else{
            int mid = (beg + end) / 2;
            // cout<<"Beg: "<<beg<<" Mid: "<<mid<<" End: "<<end<<"\n";
            string prefixLeft = longestPrefix(strs, beg, mid);
            string prefixRight = longestPrefix(strs, mid + 1, end);
            return findCommon(prefixLeft, prefixRight);
        }
    }
    
    string findCommon(string prefixLeft, string prefixRight){
        string result = "";
        int minIndex = min(prefixLeft.size(), prefixRight.size());
        for(int index = 0; index < minIndex; index++){
            if(prefixLeft[index] != prefixRight[index])
                return result;
            result += prefixLeft[index];
        }
        
        return result;
    }
};