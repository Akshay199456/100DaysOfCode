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


3. Two pointer approach

We can also solve this problem using the two pointer approach. This way we don't have to use extra space.
With the two pointer appraoch, we start the pointers from the end of the strings. This gives us a good 
idea to compare the characters. That way we can skip the characters easily by adjusting the pointer when
we encounter '#'. Also, since the strings may not be of the sme length, we need to adjust the pointers
so that we are comparing the characters. In addition, if we encounter a situation where we have encoutnered
the beginning of one string but are still progressing through the other, we have to ensure that the other
string is equivalent to the first string by making sure it evalautes to null for the two stirngs to be 
equal. Check 'Helpong Images' for more info on this approach. 


Time complexity: O(m+n)
Space complexity: O(1)
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


// My Approaches(3)
class Solution {
public:
    void skipPtr(string element, int & ptr){
        int skipNumber = 0;
        bool end = false;
        while(ptr >= 0 && !end){
            if(element[ptr] == '#'){
                skipNumber++;
                ptr--;
            }
            else{
                if(!skipNumber)
                    end = true;
                else{
                    ptr--;
                    skipNumber--;
                }
            }
        }
    }
    
    bool traverseString(string element, int & ptr){
        int nCharacters = 0;
        for(int i = 0; i <= ptr; i++){
            if(element[ptr] != '#')
                nCharacters++;
            else{
                if(nCharacters > 0)
                    nCharacters--;
            }
        }
        
        ptr = -1;
        if(!nCharacters)
            return true;
        return false;
    }
    
    bool backspaceCompare(string S, string T) {
        int sptr = S.size() - 1, tptr = T.size() - 1;
        while(sptr >= 0 || tptr >= 0){
            if(sptr >= 0 && tptr >= 0){
                if(S[sptr] != '#' && T[tptr] != '#'){
                    if(S[sptr] == T[tptr]){
                        sptr--;
                        tptr--;
                    }
                    else
                        return false;
                }
                
                else{
                    skipPtr(S, sptr);
                    skipPtr(T, tptr);
                }
            }
            
            else{
                if(sptr < 0)
                    return traverseString(T, tptr);
                return traverseString(S, sptr);
            }
        }
        return true;
    }
};