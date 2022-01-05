/*
-------------------------Question:

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
You may assume all letters are in lowercase.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/

/*
-------------------------    My Approaches:

1. Topological Sort with cycle detection

We can use the cycle detection to make sure no cycle exists as topological sort only works on DAG, directed acyclic graphs.
Once we have determined that there's no cycle, we can then use the topological sort on the graph. We know from the problem
that the list of words are sorted. To be noted here is that, it doesn't necessarily mean that the characters in each word
are sorted as well. It only means the words when compared to each other are sorted. Using that knowledge, we can use the
comparison between any two words to determine the order in which the characters occur and inserted those nodes into the 
graph as a direfcted edge. For each group of words, we skip the letters if they are equal and add the first non same 
character to the graph. We continue to do this foll all the adjancet words to build the graph. Once we have the graph,
the next part is the topological sort. However, the node that finishes first is inserted into the bottom of the stack so
that when the nodes are removed fgrom the stack, the nodes that have finsihed first are at the last while the nodes that have
been at the last come out first. This allows our nodes to be explored in the order in which they are arranged in the alien's
dictionary in the proper sorting as the characters which finish first are lexicographically greater and should appear last 
in the ordering.

Time complexity: O(V+E)
Space complexity: O(V+E)

*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
#include <iostream>
#include <vector>
#include <string>
#include <ostream>
#include <unordered_map>
#include <stack>

using namespace std;

unordered_map<char, vector<char>> graph;

void createGraph(vector<string> words){
  // initialize graph with empty list
  for(int i=0; i<26; i++){
    vector<char> list;
    graph[i + 'a'] = list;
  }

  // create connections of the graph
  for(int i=0 ; i<words.size()-1; i++){
    string currentWord = words[i], nextWord = words[i+1];
    int j=0;
    bool isEnd = false;
    while(j < min(currentWord.size(), nextWord.size()) && !isEnd){
      if(currentWord[j] == nextWord[j])
        j++;
      else{
        isEnd = true;
        graph[currentWord[j]].push_back(nextWord[j]);
      }
    }
  }
}

void printGraph(){
  for(auto it=graph.begin(); it!=graph.end(); it++){
    cout<<"Character: "<<it->first<<endl;
    for(int i=0; i<it->second.size(); i++)
      cout<<"\tNeighbor: "<<it->second[i]<<endl;
  }
}

bool isCycleUtil(char currentVertex, unordered_map<char,int> & vertexStates){
  // 0-> visiting; 1->visited
  if(vertexStates.find(currentVertex) != vertexStates.end() && vertexStates[currentVertex] == 1)
    return false;

  vertexStates[currentVertex] = 0;
  for(int i=0; i<graph[currentVertex].size(); i++){
    if(vertexStates.find(graph[currentVertex][i]) != vertexStates.end() && vertexStates[graph[currentVertex][i]] == 0)
      return true;
    else if(isCycleUtil(graph[currentVertex][i], vertexStates))
      return true;
  }
  vertexStates[currentVertex] = 1;
  return false;
}

bool isCycle(){
  unordered_map<char, int> vertexStates;
  for(auto it = graph.begin(); it!= graph.end(); it++){
    if(isCycleUtil(it->first, vertexStates))
      return true;
  }
  return false;
}

void topologicalSortUtil(char currentVertex, stack<char> & currentStack, vector<bool> & visited){
  visited[currentVertex] = true;
  for(int i=0; i<graph[currentVertex].size(); i++){
    if(!visited[graph[currentVertex][i]])
      topologicalSortUtil(graph[currentVertex][i], currentStack, visited);
  }
  currentStack.push(currentVertex);
}

void topologicalSort(string & result){
  stack<char> currentStack;
  vector<bool> visited(26,false);

  for(auto it=graph.begin(); it!=graph.end(); it++){
    if(!visited[it->first])
      topologicalSortUtil(it->first,currentStack, visited);
  }

  while(!currentStack.empty()){
    result.push_back(currentStack.top());
    currentStack.pop();
  }
}


int main() {
  string result = "";
  vector<string> words{"world", "word", "rod", "row"};
  if(words.size() != 0){
    if(words.size() == 1)
      result.push_back(words[0][0]);
    else{
      createGraph(words);
      //printGraph();
      if(isCycle())
        result = "Invalid; graph contains cycle";
      else
        topologicalSort(result);
    }
  }

  cout<<"Result: "<<result<<endl;
  return 0;
}