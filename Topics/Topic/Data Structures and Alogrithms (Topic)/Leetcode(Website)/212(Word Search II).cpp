/*
-------------------------Question:

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.

*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Using trie to store words and then following alon gthe trie as we go through cell[Time Limit Exceeded]

We can create a trie of the words since we will be using prefixes here. Once we creat ehte trie from the list of words. we can then easily search for whether any of the cells neighboring to the current cell is a potential candidate
to continue to the end of the word.

Note: This is a vvalid solution. While this deons't clear the debugger due to time constrainsts, we could make few adoptions as highlighted in Additional Notes(1) to make it agree with the debugger. One of these includes using a 
hashmap instead for the trie instead of the vector of childrens. This is for another day.


Time complexity: O(mn * 4 * 3^(l-1))
Space complexity: O(kg) where k is no of words in words and g is the max length of word
*/

// Other Approaches(1)
struct TrieNode{
    vector<TrieNode *> children;
    string endWord;
};


class Solution {
public:
    TrieNode * createNode(){
        TrieNode * temp = new TrieNode;
        for(int i=0; i< 26; i++)
            temp->children.push_back(NULL);
        temp->endWord = "#";
        
        return temp;
    } 
             
    void insertWord(TrieNode * & root, string word){
        TrieNode * temp = root;
        for(int i=0; i< word.size(); i++){
            int index = word[i] - 'a';
            if(!(temp->children[index]))
                temp->children[index] = createNode();
            temp = temp->children[index];
        }
        temp->endWord = word;
    }
    
    void checkChildren(TrieNode * root, int i, int j, vector<vector<char>> & board, vector<string> & result){
        char currentChar = board[i][j];
        TrieNode * currentNode = root->children[currentChar - 'a'];
        
        if(currentNode->endWord.compare("#") != 0){
            result.push_back(currentNode->endWord);
            currentNode->endWord = "#";
        }
        
        board[i][j] = '#';
        vector<vector<int>> directions {{0,-1}, {0,1}, {1,0}, {-1,0}};
        
        for(int index=0; index < directions.size(); index++){
            int potI = i + directions[index][0], potJ = j + directions[index][1];
            if(potI >=0 && potI < board.size() && potJ >= 0 && potJ < board[0].size() && board[potI][potJ] != '#' && currentNode->children[board[potI][potJ] - 'a'] != NULL)
                checkChildren(currentNode, potI, potJ, board, result);
        }
        
        board[i][j] = currentChar;
    }
    
    vector<string> getWords(vector<vector<char>>& board, vector<string>& words){
        vector<string> result;
        TrieNode * root = createNode();
        TrieNode * temp = root;
        
        // insert all the words into the trie
        for(int i=0; i< words.size(); i++)
            insertWord(root, words[i]);
         
        // check if any word begins as we go through baord
        for(int i=0; i< board.size(); i++){
            for(int j=0; j< board[0].size(); j++){
                int index = board[i][j] - 'a';
                if(root->children[index] != NULL)
                    checkChildren(temp, i, j, board, result);    
            }
        }
        
        return result;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        return getWords(board, words);
    }
};