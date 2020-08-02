/*
-------------------------Question:

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
-------------------------My Approaches:

1. Using a hashmap to store the occurrences

We can keep track of the largest substring using a hashmap. At any instance, the current character can
either exist or not in the hashmap. If it doesn't exist, we add it to the hashmap and increment the level.
We also need to check if this level is the max level that we have encountered and if so, store it.

If we have encountered the character before, continuing from a state where the character didn't exist would
provoide the best solution. As a result, to keep the condition of substring going, we need to delete every
character that occurred on or before the first encounter from the hashmap. This way the hashmap only stores
the occurrences of the ucontinuing substring going at all times. We then insert the current character into
the hashmap.

A quick note here:

If you are searchign for a character in a hashmap using charMap[s[j]] and the character doesn't exist,
the [] operator automatically creates an entry into the hashmap with s[j] as the key and the default value
for the type of the value as the value, in this case, 0. As a result, it would always show that the elemntn
existed since if the element didn't exist, it would create it and if it did exist, it would repkace it.

Time complexity: O(n^2)
Space compelxity: O(n)
*/

/*
-------------------------Other approaches

1. Generate all substrings and test whether each substring is unique in its characters[Worst]

The brute force approach to this problem is to generate all possible substrings and test for character
uniqueness in each of the substrings. Generating substrings is an O(n^2) operation[As illustrated in the
allSubstrings.cpp file in ProgrammingLanguages/C++/vimSetup]. Testing for uniqueness of each of the
substirngs is anohter O(n) operation. Thus, the total time complexity for this solution is O(n^3).

We can test for uniqueness of a substring using a hashset. The hashset space is determined by the min
of the length of the substring and the total number of characters in the langauge.

Time complexity:O(n^3)
Space complexity:O(min(n,m))


2. Using a window slider/two pointer

A sliding window is an abstract concept commonly used in array/string problems. A window is a range of 
elements in the array/string which usually defined by the start and end indices, i.e. [i, j)[i,j) 
(left-closed, right-open). A sliding window is a window "slides" its two boundaries to the certain 
direction. For example, if we slide [i, j)[i,j) to the right by 11 element, then it becomes 
[i+1, j+1)[i+1,j+1) (left-closed, right-open).

In this approach, we use the window slider to basically decide if a character has been seen before. As long
as we have not seen the character, we keep moving the right end of the slider and add the character to the
set since we will be using the set to keep track of all of the characters that we have encountered. By 
moving the right end of the slider, we are able to get the new set of elements that we can test for since
we know that as there was no duplciate from 0 - j, we can add and test of character at j+1. Anytime we 
encounter a duplicate, the key is to move the left window. This is because, since we have encountered a 
duplicate, we want to make sure to get rid of any characters that existed at or before the character we
encoutnered since adding the new character in that case would break the substring condition. This is why
we keep removing the characters from the left window one at a time till the duplicate value has been removed 
from the set. Once the duplicate value has been removed, we know that adding the current character which 
triggered the duplicate condition will be safe since it will be unique in the set and will start counting 
as the next substring.

Another point to note here is that if we have part of a substring that's a duplicate, any substring
that's derived from that part will also contain a duplicate. As a result, the window slider helps effciciently
deal with those scenarios by making sure that the characters in the set will always be unique and be part
of the substring.

Note here: the window slider approach is very useful in substrings generating problems here like this problem since it
only takes into consideration the substrings that are valid and are potential solutions rather than building upon
substrings that don't fit the condition.

Time compleity: O(2*n)=> O(n)
Space complexity: O(min(n,m))


3. Efficient window slider

The bottleneck ni My Approaches(1) and Other Approaches(2) was always deleting elements from the set/map
when the duplicate occurred. As a result, in the first case we had a runtime if O(n^2) while in the second,
we had a run time of O(n). This approach aims to improve upon that.

We don't have to delete the elements that have been encountered and all the elements before it. We could
rather set a new beginning indicator which we can use to skip through those characters. Yes, the characters
which were duplicate encounters will still continue to be in the map. However, by using the new beginning,
we can start with the new beginning level and make our calculations of the length of the max substring
from it.

In the map, we are storing the index of the next character from which to begin with if we encounter a 
duplicate. IF we ecnouner a duplicate, we make sure to adjsut the new beginning 'currStart' accordingly
so that we are considerign the length that has been attributed from the duplicate values and values
before it. This way, we are able to reduce the bottleneck of deleting entries from the map and as a result,
are restricted to O(n) runtime since we onlly pass through each element once and make the decision during
the pass.

Time complexity: O(n)
Space comeplxity: O(min(m,n))

If we have prior idea of the kind of characters we are dealing with, instead of using a hashmap, we can
use an array of constant size. That way our space complexity becomes O(1).

The previous implements all have no assumption on the charset of the string s.

If we know that the charset is rather small, we can replace the Map with an integer array as direct 
access table.

Commonly used tables are:

int[26] for Letters 'a' - 'z' or 'A' - 'Z'
int[128] for ASCII
int[256] for Extended ASCII

*/

// My Approaches(1)
class Solution {
public:
    int getLongestSubstring(string s){
        int maxLevel = 1, currentLevel = 1;
        unordered_map<char, int> charMap;
        charMap[s[0]] = 0;
        for(int i= 1; i <  s.size(); i++){
            if(charMap.find(s[i]) == charMap.end()){
                currentLevel++;
                charMap[s[i]] = i;
                if(currentLevel > maxLevel)
                    maxLevel = currentLevel;
            }
            else{
                int diff = i - charMap[s[i]];
                currentLevel = diff;
                for(int j = 0; j <= charMap[s[i]]; j++){
                    if(charMap.find(s[j])!= charMap.end() && charMap[s[j]] == j)
                      charMap.erase(charMap.find(s[j]));
                }
                charMap[s[i]] = i;
            }      
        }
        return maxLevel;
    }
    
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        return getLongestSubstring(s);
    }
};



// Other Approaches(2)
class Solution {
public:
    int getLengthSubstring(string s){
        int left = 0, right = 0, maxLength = 0;
        unordered_set<char> charSet;
        while(left < s.size() && right < s.size()){
            if(charSet.find(s[right]) == charSet.end()){
                charSet.emplace(s[right++]);
                maxLength = max(maxLength, right - left);
            }
            else
                charSet.erase(s[left++]);
        }
        return maxLength;
    }
    
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        else
            return getLengthSubstring(s);
    }
};


// Other Approaches(3)
class Solution {
public:
    int getLongestLength(string s){
        int currStart = 0, maxLevel = 0;
        unordered_map<char, int> charMap;
        for(int currIndex = 0; currIndex < s.size(); currIndex++){
            if(charMap.find(s[currIndex]) != charMap.end()){
                currStart = max(currStart, charMap[s[currIndex]]);
            }
            maxLevel = max(maxLevel, currIndex - currStart + 1);
            charMap[s[currIndex]] = currIndex + 1;
        }
        return maxLevel;
    }
    
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        else
            return getLongestLength(s);
    }
};