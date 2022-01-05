/*
-------------------------Question:

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
 

Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

/*
-------------------------My Approaches:
1. Recursive Approach

For palindrome based questions, the best way to find if a word is a palindrome or not is by using the two pointer approach.
Since we are looking for subsequences here, one approach you can think of is list all set of subsequences of all possible
lengths and then determine which one of them are palindromes. We can do this recursively which generates a tree based 
structure. If the start and end character are the same, then we know that the length of the subsequence that will result
from this will be atleast 2 and then we recursively check for the subsequence that results from the substring enclosed withion
those indexes.
If the start and end index characters don't match, then we know that we won't have any subsequences of that length. So, we
need to check of subsequences of length-1. The way we can do that is by choosing one of two paths: either pushing beg index
by 1 forward or by pushing the end indedx by 1 backwards. This results in a tree based structure.

Time complexity: O(2^n)
Space complexity: O(n)


2. Bottom-up DP

If we observe the above approach, we can notice that there are several calculations that are being repeated again and again.
As a result, once we have the max subsequence that is possible for a state, we store it so that it can be used once it is
encoutnered in other states.

We use a dpTable to store the states. If the characters at start index and end index don't match, we find the max of the
the value at dpTable[i+1][j] and dpTable[i][j-1] as those are the two paths which will lead to the current node. If the 
characters match, then our result will only depend on dpTable[i+1][j-1] as that is the only path posssible if two characters
match so we check for start+1, end-1.

Time complexity: O(n^2)
Space complexity: O(n^2)

*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    int getRecursive(string s, int beg, int end){
        if(beg > end)
            return 0;
        else if(beg == end)
            return 1;
        else{
            if(s[beg] == s[end])
                return 2 + getRecursive(s, beg+1, end-1);
            else{
                int left = getRecursive(s, beg, end-1);
                int right = getRecursive(s, beg+1, end);
                return max(left, right);
            }
        }
    }
    
    int longestPalindromeSubseq(string s) {
        return getRecursive(s, 0, s.size()-1);
    }
};


// My Approaches(2)
class Solution {
public:
    vector<vector<int>> dpTable;
    
    void initializeDpTable(int size){
        for(int i = 0; i < size; i++){
            vector<int> list;
            for(int j = 0; j < size; j++){
                if(i == j)
                    list.push_back(1);
                else
                    list.push_back(0);
            }
            dpTable.push_back(list);
        }
    }
    
    
    void getRecursive(string s){
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = i + 1; j < s.size(); j++){
                // cout<<"i: "<<i<<" j: "<<j<<endl;
                if(s[i] == s[j]){
                    // cout<<"\ti+1: "<<i+1<<" j-1: "<<j-1<<endl;
                    dpTable[i][j] = 2 + dpTable[i+1][j-1];
                }
                else{
                    // cout<<"\ti: "<<i<<" j-1: "<<j-1<<endl;
                    // cout<<"\ti+1: "<<i+1<<" j: "<<j<<endl;
                    dpTable[i][j] = max(dpTable[i][j-1], dpTable[i+1][j]);
                }
            }
        }
    }
    
    int longestPalindromeSubseq(string s) {
        initializeDpTable(s.size());
        getRecursive(s);
        return dpTable[0][s.size()-1];
    }
};