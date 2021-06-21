/*
-------------------------Question:

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 1000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Using BFS and modeling problem as a graph

We can model the problem as a graph problem. As a result, nodes here are the words and the edge relationships are between words that are one letter away. So, we build the graph as we are going along. We create a graph as a DAG as
we don't want to go back to the upper layer as it would cause a cycle. In addition, nodes at each layer are not connected to each other as that would also lead to cycles. By constructing the graph in this manner, we are able create a 
relationship between the different nodes and as we follow the edges, we can get to the destination. We use BFS as a result to find the shortest path to the destination. In addition, we use bfs while constructing the graph since we wnat to 
connect nodes that are a word away.

Time complexity: O(nk^2 + nlogn + alpha)
Space complexity: O(nk)
*/

// Other Approaches(1)
class Solution {
public:
    unordered_map<string, vector<string>> graph;
    vector<vector<string>> result;
    
    vector<string> getNeighbors(string currWord, unordered_set<string> & wordListSet){
        vector<string> list;
        for(int i=0; i< currWord.size(); i++){
            
            char oldChar = currWord[i];
            for(int j=0; j< 26; j++){
                
                currWord[i] = 'a' + j;
                if(currWord[i] != oldChar && wordListSet.find(currWord) != wordListSet.end())
                    list.push_back(currWord);
            }
            currWord[i] = oldChar;
        }
        return list;
    }
    
    void bfs(string & beginWord, string & endWord, unordered_set<string> & wordListSet){
        queue<string> q;
        unordered_set<string> isEnqueuedSet;
        
        // add begin word to queue
        q.push(beginWord);
        // remove beginWord from set of wordlist if it exists
        if(wordListSet.find(beginWord) != wordListSet.end())
            wordListSet.erase(beginWord);
        
        
        isEnqueuedSet.emplace(beginWord);
        
        while(!q.empty()){
            vector<string> visited;
            
            for(int i=q.size(); i > 0; i--){
                string currWord = q.front();
                q.pop();
                
                
                vector<string> neighbors = getNeighbors(currWord, wordListSet);
                for(int i=0; i < neighbors.size(); i++){
                    visited.push_back(neighbors[i]);
                    if(graph.find(currWord) == graph.end()){
                        vector<string> list;
                        graph[currWord] = list;
                    }
                    // creating the graph relationship
                    graph[currWord].push_back(neighbors[i]);
                    
                    // keep track of the nodes we are going to visit or have visited
                    if(isEnqueuedSet.find(neighbors[i]) == isEnqueuedSet.end()){
                        q.push(neighbors[i]);
                        isEnqueuedSet.emplace(neighbors[i]);
                    }
                }
            }
            
            // remove all the visited nodes from the wordList set
            for(int i=0; i< visited.size(); i++){
                if(wordListSet.find(visited[i]) != wordListSet.end())
                    wordListSet.erase(visited[i]);
            }
        }
    }
    
    void backtrack(vector<string> & list, string & currWord, string & endWord){
        if(currWord.compare(endWord) == 0)
            result.push_back(list);
        else{
            for(int i=0; i< graph[currWord].size(); i++){
               list.push_back(graph[currWord][i]);
               backtrack(list, graph[currWord][i], endWord);
               list.pop_back();
           } 
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListSet;
        vector<string> list;
        
        // create a set from the list of words
        for(int i=0; i< wordList.size(); i++)
            wordListSet.emplace(wordList[i]);
        
        bfs(beginWord, endWord, wordListSet);
        list.push_back(beginWord);
        backtrack(list, beginWord, endWord);
        return result;
    }
};