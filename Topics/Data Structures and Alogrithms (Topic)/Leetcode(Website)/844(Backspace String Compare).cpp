/*
-------------------------Question:

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

/*
-------------------------My Approaches:

1. Using maps

We can use maps to store the occurrences of the characters. For every # we encounter, we delete the 
preceding character as long as there exceeded a character in the map.

Time compelexity: O(m+n)
Space complexity: O(m+n)


2. Using stack(Not coded)

We can do the same as My approaches(1) but instead of using maps, we can use stacks. The same idea applies
as in My approaches(1)

Time complexity: O(m+n)
Space complexity: O(m+n)
*/

/*
-------------------------Other approaches

*/


// My Approaches(1)
class Solution {
public:
    void constructMap(string element, unordered_map<int, char> & map){
        int index = -1;
        for(int i = 0; i < element.size(); i++){
            if(element[i] == '#'){
                if(!map.empty())
                    map.erase(index--);
            } 
            else
                map[++index] = element[i];
        }
    }
    
    void printMap(unordered_map<int, char> map){
        for(auto it = map.begin(); it != map.end(); it++)
            cout<<"Index: "<<it->first<<" Character: "<<it->second<<endl;
    }
    
    bool backspaceCompare(string S, string T) {
        unordered_map<int,char> sMap, tMap;
        constructMap(S, sMap);
        constructMap(T, tMap);
        return sMap == tMap;
    }
};