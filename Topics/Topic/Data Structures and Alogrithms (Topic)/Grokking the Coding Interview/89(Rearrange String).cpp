/*
Problem statement:

Given a string, find if its letters can be rearranged in such a way that no two same characters come next to each other.

Example 1:

Input: "aappp"
Output: "papap"
Explanation: In "papap", none of the repeating characters come next to each other.
Example 2:

Input: "Programming"
Output: "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
Explanation: None of the repeating characters come next to each other.
Example 3:

Input: "aapa"
Output: ""
Explanation: In all arrangements of "aapa", atleast two 'a' will come together e.g., "apaa", "paaa".
*/

/*
-------------------------    My Approaches:
1. 

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
problem follows top k numbers pattern. Can follow a greedy approach to find an arrangement of the given string where no two same characters come next to each other

can work in a stepwise fashion to create a string with all characters from the input string. following a greedy approach, we should first append the most frequent characters to the output strings for which 
we can use a max heap. by appending the most frequent character first, we have the best chance to find a string where no two same characters come next to each other.

so in each step, we should append one occurrence of the highest frequency chracter to the output string. we will not put this character back on the heap to ensure that no two same characters are adjacent to each other. in
the next step, we should process the next most frequent character from the heap in the same way and then, at the end of this
step, insert hte character fromt he previous step back to th eheap after decrementing its frequency.

followinbg this algorithm, if we can append all the chracters from the input string to the output string, we would have successfully found an arrangement of the given string where no two same characters appeared adjacent to each other.

    Time complexity: O(nlogn)
    Space complexity: O(n)


Additional Notes

In each of the hard problems where i have not fully solved the problem, i have always been on the right track to solve the problem. right before i give up or stop solving the problem, I have always
been on the right track to figuring out how the problem works. so, i should have confidence on my abilities whenever i am solving these kind of problems, bnecause i will figure out a way to solve the problem if i just give myself some more time in order
to solve it.

Even on this problem, my first strategy was to figure out the count fo the charactes. my next strategy was to put the count of character sinto a max heap based on the frequency. my strategy was to take it out, decrement its count, use it and put it back inside. 
where my approach differeed from the solution was that they kept hold of it and only inserted it back after the nextstep. this would make sense as we would not want to have the same character appear at the top of the heap simulataneosuyl.
*/



//  My approaches(1)



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeString {
 public:
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return y.second > x.second;
    }
  };

  static string rearrangeString(const string &str) {
    unordered_map<char, int> charFrequencyMap;
    for (char chr : str) {
      charFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all characters to the max heap
    for (auto entry : charFrequencyMap) {
      maxHeap.push(entry);
    }

    pair<char, int> previousEntry(-1, -1);
    string resultString = "";
    while (!maxHeap.empty()) {
      pair<char, int> currentEntry = maxHeap.top();
      maxHeap.pop();
      // add the previous entry back in the heap if its frequency is greater than zero
      if (previousEntry.second > 0) {
        maxHeap.push(previousEntry);
      }
      // append the current character to the result string and decrement its count
      resultString += currentEntry.first;
      currentEntry.second--;
      previousEntry = currentEntry;
    }

    // if we were successful in appending all the characters to the result string, return it
    return resultString.length() == str.length() ? resultString : "";
  }
};

int main(int argc, char *argv[]) {
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aappp") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("Programming") << endl;
  cout << "Rearranged string: " << RearrangeString::rearrangeString("aapa") << endl;
}
