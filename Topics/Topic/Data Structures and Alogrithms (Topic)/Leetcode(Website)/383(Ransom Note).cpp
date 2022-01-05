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

This also has a time complexity advantage as compared to map. With a map, we have to hash the entity and
then check if the entity exists and then return the value if it exists. This takes quite a bit of time.
However, if you use a character vector, we can easily find the value we are looking for using the index.
While in theory both have the same runtime, in practice the character array is better

Time complexity: O(m+n)
Space complexity: O(n)
*/

/*

1. Using character array instead of map

When we have an idea of the entities that are being stored in the map eg: only uppercase letters or only
lowercase letters, letters of a certian language, we can use a character vector instead of a map. This makes
sure that our space complexity is constant instead of changing with the input.

Time complexity: O(m+n)
Space complexity: O(1)
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


// Other Approaches(1)
class Solution {
public:
    void generateCharacterMap(vector<int> & charMap, string magazine){
        for(int i = 0; i < magazine.size(); i++)
            ++charMap[magazine[i] - 'a'];
    }
    
    bool checkRansom(vector<int> & charMap, string ransomNote){
        for(int i = 0; i < ransomNote.size(); i++){
            if(--charMap[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
    
    bool checkValidRansom(string ransomNote, string magazine){
        vector<int> charMap(26, 0);
        generateCharacterMap(charMap, magazine);
        return checkRansom(charMap, ransomNote);
    }
    
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.empty() && ransomNote.empty())
            return true;
        else
            return checkValidRansom(ransomNote, magazine);
    }
};