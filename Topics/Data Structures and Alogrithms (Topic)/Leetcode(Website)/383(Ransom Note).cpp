/*
-------------------------Question:

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

/*
-------------------------My Approaches:

1. Using map to store occurrences

We can use a map to store the occurrences of all the characters in the magazine. Once we have the map, we
can check for the number of occurrences of the ransom note in the map. If at any time the no of occurrences
drops to 0, we delete it from the map. This way we know if the character in the ransom Note no longer exists,
we return false. At the end, we return true if it doesn;t throw any error for each of the characters.

Time complexity: O(m+n)
Space complexity: O(n)
*/

/*
*/

// My Approaches(1)
class Solution {
public:
    void constructMap(string magazine, unordered_map<char,int> & map){
        for(int i = 0; i < magazine.size(); i++){
            if(map.find(magazine[i]) == map.end())
                map[magazine[i]] = 1;
            else
                map[magazine[i]]++;
        }
    }
    
    bool checkRansomFromMap(string ransomNote, unordered_map<char,int> & map){
        for(int i = 0; i < ransomNote.size(); i++){
            if(map.find(ransomNote[i]) == map.end())
                return false;
            else{
                map[ransomNote[i]]--;
                if(map[ransomNote[i]] == 0)
                    map.erase(ransomNote[i]);
            }
        }
        return true;
    }
    
    bool checkValidRansom(string ransomNote, string magazine){
        unordered_map<char, int> map;
        constructMap(magazine, map);
        return checkRansomFromMap(ransomNote, map);
    }
    
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.empty() && ransomNote.empty())
            return true;
        else
            return checkValidRansom(ransomNote, magazine);
    }
};