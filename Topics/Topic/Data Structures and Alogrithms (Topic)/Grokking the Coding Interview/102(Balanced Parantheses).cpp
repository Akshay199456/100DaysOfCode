/*
Problem statement:

For a given number ‘N’, write a function to generate all combination of ‘N’ pairs of balanced parentheses.

Example 1:

Input: N=2
Output: (()), ()()
Example 2:

Input: N=3
Output: ((())), (()()), (())(), ()(()), ()()()
*/

/*
-------------------------    My Approaches:
1. BFS based subset pattern

    we can use the bfs based subset pattern in order to solve this problem. as always, the key in a bfs appraoch is to understand how we can get from the current lebvel
    to the next level and we do it again and again.

    in this problem, to get from n=2 to n=3, we would basically have to add a balanced pair between every position of the string from the previous level.
    we know that the previous level is blanacned. so as long as we keep things balanced in this level, the solution for this level is also balanced. and the way we keep it balanced in this level is by by adding a balanced pair at each position
    of the string fromt he previous level. we do this repatefdly till we arrive at the soplution we are interested in. we also keep check if a string has been repeated befre
    using a set which tracks if a string has occurred before.

    Time complexity: O(n*(2^n))
    Space complexity: O(n*(2^n))
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
#include <unordered_set>
#include <vector>

class GenerateParentheses {
 public:
  static void generateParentheses(int num, vector<string> & result){
    queue<string> layers;
    layers.push("");
    for(int i=1; i<= num; i++){
      int n = layers.size();
      unordered_set<string> stringSeen;
      for(int j=0; j<n; j++){
        string oldLayer = layers.front();
        layers.pop();

        for(int k=0; k<=oldLayer.size(); k++){
          string copyString = oldLayer;
          copyString.insert(k, "()");
          if(stringSeen.find(copyString) == stringSeen.end()){
            stringSeen.emplace(copyString);
            layers.push(copyString);
          }
        }
      }
    }

    while(!layers.empty()){
      result.push_back(layers.front());
      layers.pop();
    }
  }

  static vector<string> generateValidParentheses(int num) {
    vector<string> result;
    // TODO: Write your code here
    generateParentheses(num, result);
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GenerateParentheses::generateValidParentheses(4);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GenerateParentheses::generateValidParentheses(5);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}



//  Other Approaches(1)
