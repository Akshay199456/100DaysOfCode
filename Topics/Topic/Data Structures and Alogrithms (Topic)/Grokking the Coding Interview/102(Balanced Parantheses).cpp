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
solution follows subsets pattern and can be mapped to permutations. can follow a similar BFS approach.

taking example-2 mentiioned above to generate all the combinations of balanced parentheses. following a bfs approach,
will leep adding open parentheses '(' or close parentheses ')'. at each step, we need to keep two things in mind:
    1. cant add more than 'n' open parenthesis
    2. to keep parentheses balanced, we can add a close parenthesis ')' only when we have already added enough open parenthesis '('. for thism we can keep a count of opena nd close parenthsis
    with every combination

following this guideline, let's generate parenthese for N=3:
1. start with an empty combination: ""
2. at every step, let's take all combinations of the previous step and add ( or ) keeping the above two mentuoned rules in moind.
3. for the empty combination, we can add ( since the ciunt of open parentheiss will be less than 'N'. we cant add ) as we dont have an equivalent open parenthesis, so our
list of combinations will now be "(".
4. for the next iteration, let's take all combinations of the previous set. For (, we can add another ( to it since the count of open parentheis will be less than 'N'. We can aslo add ')' as we do have an equivalent
open parenthesiss, so our list of combinations will be '(('' '()'.
5. in the next iteration, for the first comnnatiopn "((", we can add another ( to it as the count of open parenthesis will be less than 'N'. We can aslo add ')' as we do have an equivalent open parenthesis. this gives us two neew combinations
: "(((" and "(()". for the second combination, "()", we can add another "(" to it since teh count open parenthesis will be less than 'N'. we can't add ")" as we dont have an equivalent open parentehsis, so 
our list of combinations will be "(((", "(()", "()(".
and we can continue 

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
using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class ParenthesesString {
 public:
  string str;
  int openCount = 0;   // open parentheses count
  int closeCount = 0;  // close parentheses count

  ParenthesesString(const string &s, int openCount, int closeCount) {
    this->str = s;
    this->openCount = openCount;
    this->closeCount = closeCount;
  }
};

class GenerateParentheses {
 public:
  static vector<string> generateValidParentheses(int num) {
    vector<string> result;
    queue<ParenthesesString> queue;
    queue.push({"", 0, 0});
    while (!queue.empty()) {
      ParenthesesString ps = queue.front();
      queue.pop();
      // if we've reached the maximum number of open and close parentheses, add to the result
      if (ps.openCount == num && ps.closeCount == num) {
        result.push_back(ps.str);
      } else {
        if (ps.openCount < num) {  // if we can add an open parentheses, add it
          queue.push({ps.str + "(", ps.openCount + 1, ps.closeCount});
        }

        if (ps.openCount > ps.closeCount) {  // if we can add a close parentheses, add it
          queue.push({ps.str + ")", ps.openCount, ps.closeCount + 1});
        }
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GenerateParentheses::generateValidParentheses(2);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GenerateParentheses::generateValidParentheses(3);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}


// Other Approaches(2)
using namespace std;

#include <iostream>
#include <string>
#include <vector>

class GenerateParenthesesRecursive {
 public:
  static vector<string> generateValidParentheses(int num) {
    vector<string> result;
    vector<char> parenthesesString(2 * num);
    generateValidParenthesesRecursive(num, 0, 0, parenthesesString, 0, result);
    return result;
  }

 private:
  static void generateValidParenthesesRecursive(int num, int openCount, int closeCount,
                                                vector<char> &parenthesesString, int index,
                                                vector<string> &result) {
    // if we've reached the maximum number of open and close parentheses, add to the result
    if (openCount == num && closeCount == num) {
      result.push_back(string(parenthesesString.begin(), parenthesesString.end()));
    } else {
      if (openCount < num) {  // if we can add an open parentheses, add it
        parenthesesString[index] = '(';
        generateValidParenthesesRecursive(num, openCount + 1, closeCount, parenthesesString,
                                          index + 1, result);
      }

      if (openCount > closeCount) {  // if we can add a close parentheses, add it
        parenthesesString[index] = ')';
        generateValidParenthesesRecursive(num, openCount, closeCount + 1, parenthesesString,
                                          index + 1, result);
      }
    }
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GenerateParenthesesRecursive::generateValidParentheses(2);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GenerateParenthesesRecursive::generateValidParentheses(3);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
