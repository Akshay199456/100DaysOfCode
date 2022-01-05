/*
-------------------------Question:

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: S = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: S = "12345"
Output: ["12345"]
Example 4:

Input: S = "0"
Output: ["0"]
 

Constraints:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/

/*
-------------------------    My Approaches:
1. Generating all permutations

We can generate all permutations using the backtracking approach. For each character, we can either convert it into a lowercase or uppercase and then move into the next set of character indexes. We do this till we reach the end of the string.

Time complexity: O( N * (2^N))
Space complexity: O(2^N)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    string convertString(string S, int index, int convertIndex){
        string result = "";
        // append prefix
        for(int i=0; i<index; i++)
            result += S[i];
        
        // add character by converting it
        if(convertIndex)
            result += toupper(S[index]);
        else
            result += tolower(S[index]);
        
        // append suffix
        for(int i = index+1; i<S.size(); i++)
            result+= S[i];
        
        return result;
    }
    
    void generatePermutations(unordered_set<string> & permutationSet, string intermediateString, int index){
        if(index < intermediateString.size()){
            if(isalpha(intermediateString[index])){     
                // convert lowercase - 0 and uppercase - 1
                for(int i=0; i<=1; i++){
                    intermediateString = convertString(intermediateString, index, i);
                    if(permutationSet.find(intermediateString) == permutationSet.end())
                        permutationSet.emplace(intermediateString);
                    generatePermutations(permutationSet, intermediateString, index+1);
                }
            }
            else
                generatePermutations(permutationSet, intermediateString, index+1);
        }
    }
    
    vector<string> getResult(unordered_set<string> permutationSet){
        vector<string> result;
        for(auto it= permutationSet.begin(); it!= permutationSet.end(); it++)
            result.push_back(*it);
        return result;
    }
    
    vector<string> letterCasePermutation(string S) {
        unordered_set<string> permutationSet;
        permutationSet.emplace(S);
        generatePermutations(permutationSet, S, 0);
        return getResult(permutationSet);
    }
};