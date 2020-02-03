/*

**Question:**

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/


/*

**My Brute Force Approach:**

Time Complexity: O(s+j)
Space Complexity: O(s+j)



Runtime: 4 ms, faster than 65.10% of C++ online submissions for Jewels and Stones.
Memory Usage: 9.2 MB, less than 5.00% of C++ online submissions for Jewels and Stones.
*/

// This solution can be made better by just using one map instead of the two by excluding the map 
//  for string J


class Solution {
public:
    void createMap(unordered_map<char,int> & mapTemplate, string element){
       for(int i=0; i<element.length(); i++){
            if(mapTemplate[element[i]])
                mapTemplate[element[i]]++;
            else
                mapTemplate[element[i]] = 1;
        } 
    }
    
    void displayMaps(unordered_map<char, int> map){
        for(auto it: map){
            cout<<"Element: "<<it.first<<" Count: "<<it.second<<"\n";
        }
    }
    
    int getCount(unordered_map<char, int> mapJ, unordered_map<char, int> mapS){
        int sum = 0;
        for(auto it:mapJ){
            cout<<"Map J element: "<<it.first<<"\n";
            auto iterator = mapS.find(it.first);
            if(iterator!=mapS.end())
                sum+=iterator->second;
        }
        
        return sum;
    }
    
    
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> mapJ, mapS;
        createMap(mapJ, J);
        createMap(mapS, S);
        // cout<<"\n\nDisplaying map J\n";
        // displayMaps(mapJ);
        // cout<<"\n\nDisplaying map S\n";
        // displayMaps(mapS);
        return getCount(mapJ, mapS);
    }
};


/*
Improved Algorithm:
Time Complexity: O(s+j)
Space Complexity: O(s)
*/