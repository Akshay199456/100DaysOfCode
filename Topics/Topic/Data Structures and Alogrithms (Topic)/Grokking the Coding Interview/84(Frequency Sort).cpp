/*
Problem statement:

Given a string, sort it based on the decreasing frequency of its characters.

Example 1:

Input: "Programming"
Output: "rrggmmPiano"
Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before any other character.
Example 2:

Input: "abcbab"
Output: "bbbaac"
Explanation: 'b' appeared three times, 'a' appeared twice, and 'c' appeared only once.
*/

/*
-------------------------    My Approaches:
1. Top K elements pattern

    we can use the top k elements pattern in this prolem. first we need to get the frequency of each characcter and store it inot a map.
    pmce we have that, we cna then push the counts of the characters with the characters intoa  max heap and then use that to fill the string

    Time complexity: O(nlogn)
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
follows top k elements pattern and shares similarities with top k frequent numbers.

can follow the same approach as dicussed in top k frequent numbers. first will need the frequencies of all characters
then use a max heap to find the most occuring characters

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
 public:
  static void fillMap(unordered_map<char, int> & elementCount, const string &str){
    for(int i=0; i< str.size(); i++){
      if(elementCount.find(str[i]) == elementCount.end())
        elementCount[str[i]] = 1;
      else
        elementCount[str[i]]+=1;
    }
  }

  static void fillHeap(unordered_map<char, int> & elementCount, priority_queue<pair<int, char>>& pq){
    for(auto it = elementCount.begin(); it!=elementCount.end(); it++){
      pq.push(make_pair(it->second, it->first));
    }
  }

  static void fillString(priority_queue<pair<int, char>>& pq, string & sortedString){
    while(!pq.empty()){
      int count = pq.top().first;
      char ch = pq.top().second;
      while(count--){
        sortedString += ch;
      }
      pq.pop();
    }
  }

  static string sortCharacterByFrequency(const string &str) {
    string sortedString = "";
    // TODO: Write your code here
    if(str.size()){
      unordered_map<char, int> elementCount;
      priority_queue<pair<int, char>> pq;
      fillMap(elementCount, str);
      fillHeap(elementCount, pq);
      fillString(pq, sortedString);
    }
    return sortedString;
  }
};

int main(int argc, char *argv[]) {
  string result = FrequencySort::sortCharacterByFrequency("a");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;

  result = FrequencySort::sortCharacterByFrequency("aaaaaa");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
 public:
  struct valueCompare {
    bool operator()(const pair<char, int> &x, const pair<char, int> &y) {
      return y.second > x.second;
    }
  };

  static string sortCharacterByFrequency(const string &str) {
    // find the frequency of each character
    unordered_map<char, int> characterFrequencyMap;
    for (char chr : str) {
      characterFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all characters to the max heap
    for (auto entry : characterFrequencyMap) {
      maxHeap.push(entry);
    }

    // build a string, appending the most occurring characters first
    string sortedString = "";
    while (!maxHeap.empty()) {
      auto entry = maxHeap.top();
      maxHeap.pop();
      for (int i = 0; i < entry.second; i++) {
        sortedString += entry.first;
      }
    }

    return sortedString;
  }
};

int main(int argc, char *argv[]) {
  string result = FrequencySort::sortCharacterByFrequency("Programming");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;

  result = FrequencySort::sortCharacterByFrequency("abcbab");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}
