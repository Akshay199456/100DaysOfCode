/*
-------------------------Question:

Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.

Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
Example 4:

Input: s = "yzyzyzyzyzyzyzy", k = 2
Output: true
Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.
Example 5:

Input: s = "cr", k = 7
Output: false
Explanation: We don't have enough characters in s to construct 7 palindromes.
 

Constraints:

1 <= s.length <= 10^5
All characters in s are lower-case English letters.
1 <= k <= 10^5

*/

/*
-------------------------    My Approaches:
1. Greedy approach

In order to determine if we can divide the original string into k subnstrings, we don't need to break it into k substrings. Instead, let's try to look at it from the basic facts. We know that a palindrome can be a odd palindrome or an even
palindrome. Odd palindrome have 1 odd character while even palindrome have no odd character. As a result, a palindrome can have either 0 or 1 odd characters. Now, if we observe the test cases, we notice that if s.size() < k, we can't create
any substrings at all since we don't have enough characters. As a resul, in this case we return false. We can only create substrinmgs if s.size() >= k. 

Now, if we are to create k substrings, they can be eithe of even substring or odd substring. With even substring, we don't need to worry because, we can arange the characters of an even substring in any way as there are even no of 
characters for each character and thus they can be arranged in any way any they will still remain a palindrome. With odd substring though, we can only have at most 1 odd chacter per substring which will be at the center in order for
the substring to be a plaindromic substring. Alos, any character that is odd and is greater than 1 can be broken into a combination of even + 1 where we can invest the even into any odd or even substring leaving us with the only 1 
character.

This means that, at most, we can only have as many substrings as there are odd number of character . In other words, k is limited by the no of odd characters. Thus, if our given k is greater than the no of odd characters, we won't be
able to create any substring and must return false.

For all other cases, we can form palindromic substrings and thus must return true.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:
1. Greedy approach



Time complexity: O(n)
Space complexity: O(n)
*/

// Other Approaches(1)
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size())
            return false;
        else{
            unordered_map<char, int> countMap;
            int oddCount = 0;
            
            // build map of count of characters
            for(int i=0; i<s.size(); i++){
                if(countMap.find(s[i]) == countMap.end())
                    countMap[s[i]] = 1;
                else
                    countMap[s[i]]++;
            }
            
            // get count of odd characters
            for(auto it = countMap.begin(); it!= countMap.end(); it++){
                if(it->second % 2 == 1)
                    ++oddCount;
            }
            
            if(oddCount > k)
                return false;
            return true;
        }
    }
};