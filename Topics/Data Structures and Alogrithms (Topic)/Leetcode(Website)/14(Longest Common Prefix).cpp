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