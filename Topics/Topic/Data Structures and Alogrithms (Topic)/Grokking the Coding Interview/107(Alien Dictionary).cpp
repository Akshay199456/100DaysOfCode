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


    Time complexity: O()
    Space complexity: O()
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
