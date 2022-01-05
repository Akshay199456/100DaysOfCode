/*
-------------------------Question:

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

 
Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
 

Example 2:

Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
 

Example 3:

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
 

Note:

All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*/

/*
-------------------------My Approaches:

1. Using a two pointer approach with an additional pointer to insert back the characters and count

We can use the two pointer approach here with both the pointers starting at the beginning of the array. We use beg and end
to progress forwards. Any time we encounter the same character wee push end forward by 1. Else, as long as count is not
1, we decompress and insert it back into the array witht eh additional pointer that we have.

Time complexity: O(n)
Space complexity: O(1)

*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    void insertIntoArray(vector<char> & chars, int & newBeg, string value){
        for(int i = 0; i < value.size(); i++)
            chars[newBeg++] = value[i];
    }
    
    int compressArray(vector<char> & chars){
        int beg = 0, end =1, count = 1, newBeg = 0;
        char currentChar = chars[beg];
        while(end < chars.size()){
            if(chars[end] == chars[beg]){
                ++count;
                end++;
            }
            else{
                chars[newBeg++] = currentChar;
                if(count != 1)
                    insertIntoArray(chars, newBeg, to_string(count));
                
                beg = end;
                currentChar = chars[beg];
                count = 1;
                end++;
            }
        }
        
        chars[newBeg++] = currentChar;
        if(count != 1)
            insertIntoArray(chars, newBeg, to_string(count));
        
        return newBeg;
    }
    
    int compress(vector<char>& chars) {
        if(chars.size() == 0 || chars.size() == 1)
            return chars.size();
        return compressArray(chars);
    }
};