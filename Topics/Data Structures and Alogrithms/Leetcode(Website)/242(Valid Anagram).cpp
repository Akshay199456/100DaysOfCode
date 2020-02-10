/*
-------------------------Question:

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

/*
-------------------------    My Approaches:

1.

My approach was to use a single hashmap to store the number of occurrences of each character in string
s. We then go through the string t and check for the occurrence of the characters. If there's only
instance of the character in the hashmap, we delete it whenever we encounter it in the string t.
At the end, if we notice any character in string t that's not in the hashmap or if the hashmap is 
empty, we return false since they are not anagrams. If at the end, the hashmap is empty, we return
true since they are anagrams else return false. Also, if two strings are not of the same length,
they can't be anagrams as well.

Time complexity: O(s) + O(s) = O(s) [both are of the same length]
Space complexity: O(s)

2. (Worst)

Sort the two strings and then compare character by character. If the two sorted strings differ in 
characters or of different lengths, we return false since they aren't anagrams else we return true

Time complexity: O(slogs)[both are of the same length]
Space complexity: O(1)

3. (Worse)

Basically My approaches(1), but uses two hashmaps instead of one for each of the strings.

Time complexity: O(s) + O(s) = O(s)[both are of the same length]
Space complexity: O(s) + O(s) = O(s)
*/

/*
-------------------------    Other approaches:

1. (Same)

Another approach to My approach(1) is to use an array to store the number of occurrences using an
array instead of a hash table. Since hash table requires some time to calculate hash values in order
to minimize collisions, this could be costing us a little time. By using arrays, we can minimize 
this time.

We do this by incrementing the counter for each character encountered in string s and decrementing
counter for each character encountered in string t. This takes O(n) single time. We then have to
iterate through the 26 character array to check if there is any character that occurs more than
once. If so, we return false as they can't be anagrams else return true as they are anagrams.

Space Complexity: O(1)[ Array of size 26] -> O(n) depending on language
Time complexity: O(n)

*/

// My approach(1)
class Solution {
public:
    void createMap(unordered_map<char, int> & map, string s){
        for(int i = 0; i < s.size(); i++){
            auto it = map.find(s[i]);
            if(it == map.end())
                map[s[i]] = 1;
            else
                map[s[i]] += 1;
        }
    }
    
    bool checkAnagram(unordered_map<char, int> map, string t){
        for(int i = 0; i < t.size(); i++){
            auto it = map.find(t[i]);
            if(it == map.end())
                return false;
            else{
                if(map[t[i]] == 1)
                    map.erase(t[i]);
                else
                    map[t[i]] -= 1;
            }
        }
        
        if(map.empty())
            return true;
        else
            return false;
        
    }
    
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        if(s.size() != t.size())
            return false;
        else{
            createMap(map, s);
            return checkAnagram(map, t);
        }
    }
};


// Other approaches(1)
class Solution {
public:
    static int const LETTER_SIZE = 26;
    
    void createOccurrenceMap(string s, string t, int * pointer){
        for(int i = 0 ; i < s.size(); i++){
            pointer[s[i] - 'a']++;
            pointer[t[i] - 'a']--;
        }
    }
    
    bool checkOccurrence(int * pointer){
        for(int i = 0 ; i < LETTER_SIZE; i++)
            if(pointer[i])
                return false;
        return true;
    }
    
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        else{
            int letterOccurrence[LETTER_SIZE] = {0};
            createOccurrenceMap(s,t, letterOccurrence);
            return checkOccurrence(letterOccurrence);
        }
    }
};