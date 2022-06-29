/*
Problem statement:

Given a string, find all of its permutations preserving the character sequence but changing case.

Example 1:

Input: "ad52"
Output: "ad52", "Ad52", "aD52", "AD52" 
Example 2:

Input: "ab7c"
Output: "ab7c", "Ab7c", "aB7c", "AB7c", "ab7C", "Ab7C", "aB7C", "AB7C"
*/

/*
-------------------------    My Approaches:
1. DFS + backtracking

    we can use dfs + backtracking approach in order to solve this problem. if we see a characer that is an alphabet, ther are one of two routes
    that the problem can take. we either use the lowercase or uppercase. if ithe character is a number, there is only one route and that is to add the number to the string.

    Time complexity: O(k!) where k is the number of alphabets in the string
    Space complexity: O(k!)


2. BFS + queue

    we can also use a bfs approach witha  queue to solve this problem. in that case, this approach is very similar to problem 100 where they used the bfs approach with queuue.

    Time complexity: O(k!) where k is the number of alphabets in the string
    Space complexity: O(k!)

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
#include <string>
#include <vector>
#include <cctype>

class LetterCaseStringPermutation {
 public:
  static void generatePermutationRecursive(const string& str, int index, string currentString, vector<string> & permutations){
    if(index == str.size())
      permutations.push_back(currentString);
    else{
      if(!isalpha(str[index]))
        generatePermutationRecursive(str, index+1, currentString + string(1,str[index]), permutations);
      else{
        generatePermutationRecursive(str, index+1, currentString + string(1,tolower(str[index])), permutations);
        generatePermutationRecursive(str, index+1, currentString + string(1,toupper(str[index])), permutations);
      }
    }
  }

  static vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    string currentString;
    if(str.size())
      generatePermutationRecursive(str, 0, currentString, permutations);
    // TODO: Write your code here
    return permutations;
  }
};

int main(int argc, char* argv[]) {
  vector<string> result = LetterCaseStringPermutation::findLetterCaseStringPermutations("aB");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = LetterCaseStringPermutation::findLetterCaseStringPermutations("765");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}


// My Approaches(2)
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cctype>

class LetterCaseStringPermutation {
 public:
  static void generatePermutations(const string& str, vector<string> & permutations){
    queue<string> layers;
    layers.push("");

    for(auto ch: str){
      int n = layers.size();
      for(int i=0; i< n; i++){
        string oldLayer = layers.front();
        layers.pop();

        if(!isalpha(ch))
          layers.push(oldLayer + string(1,ch));
        else{
          layers.push(oldLayer + string(1,tolower(ch)));
          layers.push(oldLayer + string(1,toupper(ch)));
        }
      }
    }

    // whatever remains in the queu is the answer
    while(!layers.empty()){
      permutations.push_back(layers.front());
      layers.pop();
    }
  }

  static vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    // TODO: Write your code here
    if(str.size())
      generatePermutations(str, permutations);
    return permutations;
  }
};

int main(int argc, char* argv[]) {
  vector<string> result = LetterCaseStringPermutation::findLetterCaseStringPermutations("aB");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = LetterCaseStringPermutation::findLetterCaseStringPermutations("");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}




//  Other Approaches(1)
