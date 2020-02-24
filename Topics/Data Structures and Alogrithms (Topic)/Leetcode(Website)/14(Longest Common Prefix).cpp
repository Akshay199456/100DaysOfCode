/*
-------------------------Question:
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

/*
-------------------------My Approaches:
1.

This approach goes step by step through each string to find if the current character that's being
evaluated to check if it exists in the next string. It keeps continuing this till a mismatch occurs
or the end of the string occurs and then returns the result.

Time complexity: O(nk)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

1. Horizontal scanning (Same)

Finds the longest prefix with pair of strings and continues that till all the strings are 
analyzed.

[Check images in image folder to get a better idea of this approach]

Time complexity : O(S) , where S is the sum of all characters in all strings.

In the worst case all n strings are the same. The algorithm compares the string S1S1 with the other
strings [S_2 \ldots S_n][S 2…S n]
 There are SS character comparisons, where SS is the sum of all characters in the input array.

Space complexity : O(1). We only used constant extra space.



2. Vertical Scanning (Same)

Basically the approach I did.

Time complexity : O(S) , where S is the sum of all characters in all strings. 
In the worst case there will be nn equal strings with length mm and the algorithm performs 
S = m \cdot nS=m⋅n character comparisons. Even though the worst case is still the same as 
Approach 1, in the best case there are at most n \cdot minLenn⋅minLen comparisons where 
minLenminLen is the length of the shortest string in the array.

Space complexity : O(1). We only used constant extra space.


3. Divide and Conquer (Worse)

We can also use the divide and conquer approach to solve this problem. The exit condition is when
we hot only a single string. At the end of the divide method, we are left with 2 single string
elements which we then combine to find the longest prefix and return that.

Time complexity: O(S)
Space complexity: O(m * log N)
	- log N since we have n recursive calls and at each of the calls we use up O(m) memory
	to store the result


4. Using trie ()

Tries can be used effectively to obtain the longest prefix of the word. We know that the longest
prefix will be of the same length of the first word or less than it and can use that to construct
the trie for the first word of the vector of strings. Once we have that, we can keep checking every
other string with the trie we have constructed. If it's of a length greater than the string in the
trie, we don't have to worry about inserting it into the trie since we have already found a prefix
that's common and irrespective of inserting it or not, we have found a common prefix. If it's of
a length less than that the string in the trie, we indicate the endOfWord since that's the common
prefix.

This way when we go through the trie, whenever we hit an endOfWord, we know that's the common
prefix with respective to all the strings and return that as the result. Obviously if the first
trie node has an end of word, we know that there's no common prefix and return that instead as the 
result.

Time complexity: O(S) where S= m*n in the worst case; m-> no of letters in string, n-> no of strings.
Space complexity: O(m) m->length of first string in array of strings



5. Using binary search

This approach uses binary search to deliver the result. 

Once we have the minimum length of all strings in the array, we use that to decide the beg and 
end to be used for the binary search algorithm. Using this as the mid, we search wther or not 
that prefix exists in the rest of the vector strings. If it does, we push beg to mid+1, else
we push end to mid - 1 and keep continuing till beg <= end. Beg > end at the point when the 
longest prefix exists. Hence, we use that mid to return the result

Time complexity: O(S*log N) where S is the sum of all characters in all strings.

The algorithm makes log n iterations, for each of them there are S = m*n comparisons, which gives 
total O(S log n) 

Space complexity: O(1)

*/

// My Approaches(1)
class Solution {
public:
    string longestPrefix(vector<string> strs){
        string result = "";
        string begElement = strs[0];
//         i -> character; j -> string element
        for( int i = 0; i < begElement.size(); i++){
            for( int j = 1; j < strs.size(); j++){
                string currElement = strs[j];
                if( (i == currElement.size()) || (begElement[i] != currElement[i]))
                    return result;
            }
            result.push_back(begElement[i]);
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        else if(strs.size() == 1)
            return strs[0];
        else
            return longestPrefix(strs);
    }
};



// Other approaches(3)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        else if(strs.size() == 1)
            return strs[0];
        else 
            return longestPrefix(strs, 0, strs.size() - 1);
    }
    
    string longestPrefix(vector<string> strs, int beg, int end){
        if(beg == end)
            return strs[beg];
        else{
            int mid = (beg + end) / 2;
            // cout<<"Beg: "<<beg<<" Mid: "<<mid<<" End: "<<end<<"\n";
            string prefixLeft = longestPrefix(strs, beg, mid);
            string prefixRight = longestPrefix(strs, mid + 1, end);
            return findCommon(prefixLeft, prefixRight);
        }
    }
    
    string findCommon(string prefixLeft, string prefixRight){
        string result = "";
        int minIndex = min(prefixLeft.size(), prefixRight.size());
        for(int index = 0; index < minIndex; index++){
            if(prefixLeft[index] != prefixRight[index])
                return result;
            result += prefixLeft[index];
        }
        
        return result;
    }
};




// Other approaches(4)
const int SIZE = 26;
struct TrieNode{
    TrieNode* children[SIZE];
    bool endOfWord;
};

class Solution {
public:
    TrieNode* getNode(){
        TrieNode * pointer = new TrieNode();
        for(int i = 0; i < SIZE; i++)
            pointer->children[i] = NULL;
        pointer->endOfWord = false;
        return pointer;
    }
    
    void createTrie(string element, TrieNode * root){
        TrieNode * curr = root;
        for(int i = 0; i < element.size(); i++){
            int index = element[i] - 'a';
            if(!curr->children[index])
                curr->children[index] = getNode();
            curr = curr->children[index];
        }    
    }
    
    string getString(TrieNode * root, string element){
        string result = "";
        TrieNode * temp = root;
        for(int i = 0; i < element.size(); i++){
            if(temp->endOfWord)
                return result;
            else{
                int index = element[i] - 'a';
                result.push_back(element[i]);
                temp = temp->children[index];
            }
        }
        return result;
    }
    
    string findLongestPrefix(TrieNode * root, vector<string> strs){
        for(int i = 1; i < strs.size(); i++){
            TrieNode * curr = root;
            string element = strs[i];
            bool end = false;
            for(int j = 0; j < min(element.size(), strs[0].size()) && !end; j++){
                int index = element[j] - 'a';
                if(!curr->children[index]){
                    curr->endOfWord = true;
                    end = true;
                }
                else if(curr->endOfWord)
                    end = true;
                else
                    curr = curr->children[index];
            }
            curr->endOfWord = true;
        }
        return getString(root, strs[0]);
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        else if(strs.size() == 1)
            return strs[0];
        else{
            TrieNode * root = getNode();
            createTrie(strs[0], root);
            return findLongestPrefix(root,strs);
        }
    }
};



// Other approaches(5)
class Solution {
public:
    int getMinLength(vector<string> strs){
        int min = INT_MAX;
        for(int i = 0; i < strs.size(); i++)
            if(min > strs[i].size())
                min = strs[i].size();
        return min;
    }
    
    bool checkExists(vector<string> strs, int len){
        string element = strs[0].substr(0, len);
        for(int i = 1; i < strs.size(); i++)
            if(element.compare(strs[i].substr(0, len)) != 0)
                return false;

        return true;      
    }
    
    string findLongestPrefix(vector<string> strs){
        int min = getMinLength(strs);
        int beg = 1, end = min;
        while(beg <= end){
            int mid = (beg + end) / 2;
            if(checkExists(strs, mid))
                beg = mid + 1;
            else
                end = mid - 1;
        }
        return strs[0].substr(0, (beg+end) / 2);
    }
    
    string longestCommonPrefix(vector<string>& strs){
        if(strs.size() == 0)
            return "";
        else if (strs.size() == 1)
            return strs[0];
        else
            return findLongestPrefix(strs);
    }
};