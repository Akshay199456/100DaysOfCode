/*
-------------------------Question:

Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

/*
-------------------------My Approaches:

1. Sorting the vector and using a hashmap

In this approach, we sort each string in the vector. This allows us to identify the anagrams
easily as each anagram would have the same sorted order. Once we sort the strings, we enter
them into a hashmap along with the location they were first noticed and will be stored in the 
result. Whenever we encounter a new sorted string, we allocate it into a new vector else we 
obtain the position where the anagram is stored in the result and push the new sorted entry
into that location.

Time complexity: O(knlogn)
Space complexity: O(n)
*/

/*
-------------------------Other approaches

*/



// My Approaches(1)
class Solution {
public:
    void displayResult(vector<string> strs){
        for(int i = 0; i < strs.size(); i++){
            for(int j = 0; j < strs[i].size(); j++)
                cout<<strs[i][j];
            cout<<" , ";
        }
    }
    
    void sortVector(vector<string> & strs){
        for(int i = 0; i <strs.size(); i++)
            sort(strs[i].begin(), strs[i].end());
    }
    
    void copyVector(vector<string> original, vector<string> & copy){
        for(int i = 0; i < original.size(); i++)
            copy.push_back(original[i]);
    }
    
    void generateResult(vector<string> strs, vector<vector<string>> & result, vector<string> copy){
        unordered_map<string, int> map;
        int count = 0;
        for(int i = 0; i < copy.size(); i++){
            auto it = map.find(copy[i]);
            if(it == map.end()){
                vector<string> newList;
                map[copy[i]] = count++;
                newList.push_back(strs[i]);
                result.push_back(newList);
            }
            else{
                result[it->second].push_back(strs[i]);
            }
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> copy;
        copyVector(strs, copy);
        sortVector(copy);
        generateResult(strs, result, copy);
        return result;
    }
};
