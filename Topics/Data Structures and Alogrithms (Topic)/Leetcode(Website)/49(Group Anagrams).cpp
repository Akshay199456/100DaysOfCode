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

This approach is based on the idea that anagrams have the same sorted strings.

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

1. Using an integer array to store the occurrences of the letters in the string.[Best]

This approach is based on the idea that anagrams have the same count and occurences of letters.

In My Apporaches(1), we sorted the strings so that it would be easy to identify if the strings
were anagrams. This was the bottleneck of the approach as the sorting would take O(knlogn) time.
The way we can reduce this bottleneck is by instead using the count of the occurences of the 
letters of the strings. Since anagrams will have the same occurences of characters, we can use 
that information to generate a string representation of their occurenences and instead store that
inside the map. This takes a constant time in the large spectrum as it doesn;t depend on the input.

Once we have generated the string reprensentation of the count representation, we can store the 
string asspciated with that string pattern into a vector. Whenever we encounter a string pattern
that exists in the map, we add the string associated with the string patterns to the string vector
associated with the string pattern. Else we create a new string pattern in the map and store the
new vector with it.

Time complexity: O(nk)
Space complexity: O(n)

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





// Other Approaches(1)
class Solution {
public:
    string getStringRepresentation(vector<int> characterArray){
        string pattern = "";
        for(int i = 0; i < characterArray.size(); i++)
            pattern += to_string(characterArray[i]) + "#";
        return pattern;
    }
    
    void appendToMap(string pattern, string element, unordered_map<string, vector<string>> & map){
        auto it = map.find(pattern);
        if(it == map.end()){
            vector<string> newElement;
            newElement.push_back(element);
            map[pattern] = newElement;
        }
        else
            it->second.push_back(element);
    }
    
    
    void buildMap(vector<string> strs, unordered_map<string, vector<string>> & map){
        for(int i = 0; i < strs.size(); i++){
            vector<int> characterArray(26, 0);
            for(int j = 0; j < strs[i].size(); j++)
                characterArray[strs[i][j] - 'a']++;
            string pattern = getStringRepresentation(characterArray);
            appendToMap(pattern, strs[i], map);
        }
    }
    
    void getResult(unordered_map<string, vector<string>> map, vector<vector<string>> & results){
        for(auto it = map.begin(); it != map.end(); it++){
            results.push_back(it->second);
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string, vector<string>> map;
        buildMap(strs, map);
        getResult(map, results);
        return results;
    }
};
