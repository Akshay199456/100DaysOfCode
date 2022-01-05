/*

-------------------------Question:

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letter

*/

/*
-------------------------    My Approaches:

1.

The key to solving this problem is to know the order as well as the no of occurrences of the element.
Using a hashmap to store the no of occurrences of each character of the string on the first run
and then going through the string to check the first occurrence of the character that occurs once
helps achieve the solution.

Time complexity: O(n) + O(n) = O(n)
Space complexity: O(n)

To note, this solution takes O(n) to create the hashmap and another O(n) to go through the string.
As a result, if we are dealing with a very long string, this solution would cost a lot of memory.
In that case, having a sorted hashmap that maintains the order of the elements that have been 
inserted/ or using two hashmaps(one to store those that occur once - a sorted hashmap while the 
other to store more than once - a normal hashmap) can be more helpful as you wouldn't have to 
iterate through the string twice could be a more helpful solution.

*/

/*
-------------------------Other approaches
1. Using two pointer approach

We can use the two pointer appraoch here to solve this problem effectively. In addition to the poitners, we make use of
an array of constant size equal to the length of the no of characters possible. We will us ehte fast pointer to traverse
the string while the slow pointer will point to the current character which has not been repreated. We first increment 
count associated with the characters at both th efast and slow position. AS long as fast is less than the size of the
string, we get the count of the fast character and store it in the array. Then, as long as the character in the slow
position is ==1, we are good. Else we move slow till we find the next character which has only occurred once. At this
point, is slow exceeds the size of the string, we return -1. At the end, we return slow since that will point to the
character which had the first occurrence of the non repeatign character.

Time complexity: O(n)
Space complexity: O(c) -> O(1)
*/



// My approaches(1)
class Solution {
public:
    void createMap(unordered_map<char, int> & map, string element){
        for(int i= 0 ; i < element.size() ; i++){
            auto it = map.find(element[i]);
            if(it == map.end())
                map[element[i]] = 1;
            else
                map[element[i]] += 1;
        }
    }
    
    int getFirstUnique(unordered_map<char, int> map, string element){
        for(int i = 0; i< element.size(); i++){
            if(map[element[i]] == 1)
                return i;
        }
        return -1;
    }
    
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        createMap(map, s);
        return getFirstUnique(map, s);
    }
};


// Other Approaches(1)
class Solution {
public:
    int getUniqIndex(string s){
        int slow = 0, fast = 1;
        vector<int> arrayCount(26,0);
        arrayCount[s[slow] - 'a']++;
        while(fast < s.size()){
            arrayCount[s[fast] - 'a']++;
            while(slow < s.size() && arrayCount[s[slow] - 'a'] > 1)
                slow++;
            
            if(slow == s.size())
                return -1;
            fast++;
        }
        return slow;
    }
    
    int firstUniqChar(string s) {
        if(s.size() == 0)
            return -1;
        else
            return getUniqIndex(s);
    }
};