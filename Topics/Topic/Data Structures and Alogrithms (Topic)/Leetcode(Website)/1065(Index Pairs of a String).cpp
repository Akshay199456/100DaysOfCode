/*
-------------------------Question:

Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] is in the list of words.

 

Example 1:

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]
Example 2:

Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: 
Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].
 

Note:

All strings contains only lowercase English letters.
It's guaranteed that all strings in words are different.
1 <= text.length <= 100
1 <= words.length <= 20
1 <= words[i].length <= 50
Return the pairs [i,j] in sorted order (i.e. sort them by their first coordinate in case of ties sort them by their second coordinate).
*/

/*
-------------------------    My Approaches:
1. Using a trie

We can use a trie to solve this problem. Since we have a bunch of words, ppushing them into a
dictionary would help us in the long run as we can check for the existence of a word in
O(k) time which is pretty efficient. Once we have inserted the word into the trie, we 
just need to generate the substrings as we are going along and check inside the trie
if they exist

Time complexity: O(ks + n^3) where n is the length of the text string
Space complexity: O(ks) where k is the length of each word and s is the total no of words
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
const int alphabetSize = 26;

struct TrieNode{
    TrieNode * children[alphabetSize];
    bool isEndOfWord;
};

TrieNode * getNewNode(){
    TrieNode * currentNode = new TrieNode;
    for(int i=0; i< alphabetSize; i++)
        currentNode->children[i] = NULL;
        
    currentNode->isEndOfWord = false;
    return currentNode;
}

void insertWord(string element, TrieNode * root){
    TrieNode * currentNode = root;
    for(int i=0; i<element.size(); i++){
        int index = element[i] - 'a';
        if(currentNode->children[index] == NULL)
            currentNode->children[index] = getNewNode();   
                
        currentNode = currentNode->children[index];
    }  
    currentNode->isEndOfWord = true;
}


vector<vector<int>> findPairs(string text, TrieNode * root){
        vector<vector<int>> result;
        
        for(int i=0; i<text.size(); i++){
            int j = i;
            bool isEndOfLoop = false;
            TrieNode * currentNode = root;
            
            while(j < text.size() && !isEndOfLoop){
                int index = text[j] - 'a';
                
                // if there is a prefix from [i...j]
                if(currentNode->children[index]){
                    j++;
                    currentNode = currentNode->children[index];
                    
                    if(currentNode->isEndOfWord){
                        vector<int> list{i,j-1};
                        result.push_back(list);
                    }
                }
                // else, stop checking for further prefixes, as we have met a condition where a prefix doesn't exist and any prefix based ona  aprefix that doesn't eixst doesn't exist as well.
                else
                    isEndOfLoop = true;
            }
        }
        
        return result;
    }


void printTrie(string word, TrieNode * parent){
        TrieNode * currentNode = parent;
    
        // if end of word, print it
        if(currentNode->isEndOfWord)
            cout<<"Word: "<<word<<endl;
    
        for(int i=0; i<alphabetSize; i++){
            // if there exists a valid owrd, go down that rabbit hole
            if(currentNode->children[i] != NULL){
                char currentChar = i + 'a';
                printTrie(word + currentChar, currentNode->children[i]);   
            }
        }
    }


class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        TrieNode * root = getNewNode();
        
        // insert words into a trie structure
        for(int i=0; i<words.size(); i++)
            insertWord(words[i], root);
        
        // print Trie for debugging
        // printTrie("", root);
        
        // find pairs in the trie
        return findPairs(text, root);
    }
};