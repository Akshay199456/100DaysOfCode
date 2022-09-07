/*
Problem statement:

There is a dictionary containing words from an alien language for which we don’t know the ordering of the letters. Write a method to find the correct order of the letters in the alien language. It is given that the input is a valid dictionary and there exists an ordering among its letters.

Example 1:

Input: Words: ["ba", "bc", "ac", "cab"]
Output: bac
Explanation: Given that the words are sorted lexicographically by the rules of the alien language, so
from the given words we can conclude the following ordering among its characters:

1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
2. From "bc" and "ac", we can conclude that 'b' comes before 'a'

From the above two points, we can conclude that the correct character order is: "bac"
Example 2:

Input: Words: ["cab", "aaa", "aab"]
Output: cab
Explanation: From the given words we can conclude the following ordering among its characters:

1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'

From the above two points, we can conclude that the correct character order is: "cab"
Example 3:

Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
Output: ywxz
Explanation: From the given words we can conclude the following ordering among its characters:

1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'

From the above five points, we can conclude that the correct character order is: "ywxz"
*/

/*
-------------------------    My Approaches:
1. Topological Sort

    we can solve this problem using the topological sort algorithm.
    to create the graph, the first things we want to do is compare the each word against the next word
    and get the ordering of the characters. we cna then fill that into the graph./ once we have that, the rest is the basic topolgical sort. we crate a map to store th eparent count
    and insert the parents with count =0 and keep moving till all parents are covered.

    Time complexity: O(v+e)
    Space complexity: O(v+e)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
since the given words are sorted lexicographically by the rules of the alien language, we ccan alwasys compare two adjacent words to determine the ordering of the acharacters.
take example-1 above: [ba,bc,ac,cab]

    1. tkae th first two words ba and bc. starting from the begnniong of the words, find the first character that is
    different in bopth words: it would be 'a' from 'ba' and 'c' from 'bc'. because of the sorted order of words i.e dictioanry),
    we can conclude that 'a' comes before 'c' in the alien language.
    2. similarly, from 'bc' and 'ac', we can conclude that 'b' comes before 'a'

these two points tell us that we are actually asked to find the topoliogical ordering of the characters and that the ordering 
rules should be inferred from adjacent words from the alien dictionary

this makes the current problem similar to tasks scheduling order, the only difference being that we need to build th egraph
of the characters by comparing adjacent words first and then perform the topological sort for the graph to determine the order fo the 
characters

in step 'd', each task can becpme a source onyl once and each edge (a rule) will be accessed and removed ocne.
therefore, the time complexity of the above algorithm will be O(v+e_ whwere 'v' is the total number of different
charactrers and 'e' is the total number of rules in the alien languuage. since at most, eacg pair of words can give us one rule,
therefore, we cna conlclude that the upper bound fot he riules is O(n) where n is the number of words in the input. so we can say the time
complexity of our aglorithm is O(v+n)

    Time complexity: O(v+n)
    Space complexity: O(v+n)
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class AlienDictionary {
 public:
  static void createGraph(const vector<string> &words, unordered_map<char, vector<char>> & graph){
    // initialize chars to empty list
    for(int i=0; i < words.size(); i++){
      string currWord = words[i];
      for(int j=0; j< currWord.size(); j++){
        if(graph.find(currWord[j]) == graph.end()){
          vector<char> list;
          graph[currWord[j]] = list;
        }
      }
    }


    // initialize chars based on words
    string prevWord = words[0];
    for(int i=1; i < words.size(); i++){
      string currWord = words[i];
      bool isEnd = false;
      for(int j=0; j < currWord.size() && j < prevWord.size() && !isEnd; j++){
        if((currWord[j] != prevWord[j])){
          vector<char> list = graph[prevWord[j]];
          if(find(list.begin(), list.end(), currWord[j]) == list.end()){
            graph[prevWord[j]].push_back(currWord[j]) ;
          }
          isEnd = true;
        }
      }

      prevWord = currWord;
    }
  }


  static void getParentCount(unordered_map<char, vector<char>> & graph , unordered_map<char, int> & parentCount){
    // initialize each char to 0
    for(auto it = graph.begin(); it!= graph.end(); it++){
      parentCount[it->first] = 0;
    }

    // initialize each char to count
    for(auto it = graph.begin(); it!= graph.end(); it++){
      vector<char> list = it->second;
      for(int i=0; i < list.size(); i++){
        parentCount[list[i]] += 1;
      }
    }
  }


  static vector<char> getTopSort(unordered_map<char, vector<char>> & graph , unordered_map<char, int> & parentCount){
    queue<char> elementQueue;
    vector<char> result;
    
    // get all paretns with count = 0
    for(auto it = parentCount.begin(); it!= parentCount.end(); it++){
      if(!it->second)
        elementQueue.push(it->first);
    }

    // get rest of the parents
    while(!elementQueue.empty()){
      char frontElement = elementQueue.front();
      // cout<<"front element: "<<frontElement<<endl;
      elementQueue.pop();
      result.push_back(frontElement);

      vector<char> list = graph[frontElement];
      for(int i=0; i<list.size(); i++){
        // cout<<"char: "<<list[i]<<endl;
        parentCount[list[i]] -= 1;
        if(!parentCount[list[i]])
          elementQueue.push(list[i]);
      }
    }

    // cout<<"result size: "<<result.size()<<endl;
    // cout<<"graph size: "<<graph.size()<<endl;
    // cout<<"rsult: "<<result[0]<<endl;

    if(result.size() == graph.size())
      return result;
    return vector<char>();
  }


  static string findOrder(const vector<string> &words) {
    string sortedOrder;
    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> parentCount;

    // TODO: Write your code here
    if(words.size()){
      createGraph(words, graph);
      getParentCount(graph, parentCount);
      vector<char> list = getTopSort(graph, parentCount);
      if(list.size()){
        string result(list.begin(), list.end());
        sortedOrder = result;
      }
    }
    return sortedOrder;
  }
};

int main(int argc, char *argv[]) {
  string result = AlienDictionary::findOrder(vector<string>{});
  cout << "Character order: " << result << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AlienDictionary {
 public:
  static string findOrder(const vector<string> &words) {
    if (words.empty() || words.empty()) {
      return "";
    }

    // a. Initialize the graph
    unordered_map<char, int> inDegree;        // count of incoming edges for every vertex
    unordered_map<char, vector<char>> graph;  // adjacency list graph
    for (auto word : words) {
      for (char character : word) {
        inDegree[character] = 0;
        graph[character] = vector<char>();
      }
    }

    // b. Build the graph
    for (int i = 0; i < words.size() - 1; i++) {
      string w1 = words[i], w2 = words[i + 1];  // find ordering of characters from adjacent words
      for (int j = 0; j < min(w1.length(), w2.length()); j++) {
        char parent = w1[j], child = w2[j];
        if (parent != child) {             // if the two characters are different
          graph[parent].push_back(child);  // put the child into it's parent's list
          inDegree[child]++;               // increment child's inDegree
          break;  // only the first different character between the two words will help us find the
                  // order
        }
      }
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    queue<char> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
    string sortedOrder;
    while (!sources.empty()) {
      char vertex = sources.front();
      sources.pop();
      sortedOrder += vertex;
      vector<char> children =
          graph[vertex];  // get the node's children to decrement their in-degrees
      for (char child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    // if sortedOrder doesn't contain all characters, there is a cyclic dependency between
    // characters, therefore, we will not be able to find the correct ordering of the characters
    if (sortedOrder.length() != inDegree.size()) {
      return "";
    }

    return sortedOrder;
  }
};

int main(int argc, char *argv[]) {
  string result = AlienDictionary::findOrder(vector<string>{"ba", "bc", "ac", "cab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"cab", "aaa", "aab"});
  cout << "Character order: " << result << endl;

  result = AlienDictionary::findOrder(vector<string>{"ywx", "wz", "xww", "xz", "zyy", "zwz"});
  cout << "Character order: " << result << endl;
}
