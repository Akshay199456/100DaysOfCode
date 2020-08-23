/*
-------------------------Question:

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches
1. Brute force approach

The first approach that we can use to solve this problem is the brute force approach. As the question suggests, we can
generate all permutations of s1 and then check if it is contianed withing s2. If it is, then return true; else return
false;

To generate permutations, check out the 'Helping Images' folder for more steps. The crux of the approach is that we swap
the current index with the left index till we reach the end where we insert it into the result.

Time complexity: O(s2* s1!)
Space complexity: O(s1!)
*/

// Other Approaches(1)
class Solution {
public:
    void generatePermutations(vector<string> & allPermutations, string s1, int left, int right){
        if(left == right)
            allPermutations.push_back(s1);
        else{
            for(int i = left; i <= right; i++){
                swap(s1[left], s1[i]);
                generatePermutations(allPermutations, s1, left+1, right);
                swap(s1[left], s1[i]);
            }
        }
    }
    
    bool checkPermutationExists(vector<string> allPermutations, string s2){
        for(int i = 0; i < allPermutations.size(); i++){
            if(s2.find(allPermutations[i]) != string::npos)
                return true;
        }
        return false;
    }
    
    bool findInclusion(string s1, string s2){
        vector<string> allPermutations;
        generatePermutations(allPermutations, s1, 0, s1.size() - 1);
        return checkPermutationExists(allPermutations, s2);
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        return findInclusion(s1, s2);
    }
};