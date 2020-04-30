/*
*/

/*
*/

/*
*/

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
            //printMap(charMap);
        }
        return maxLevel;
    }
    
    void printMap(unordered_map<char,int> map){
        for(auto it = map.begin(); it!=map.end(); it++){
            cout<<"Element: "<<it->first<<" Index: "<<it->second<<endl;
        }
    }
    
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        return getLongestSubstring(s);
    }
};