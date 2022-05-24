/*
Problem statement:

Given an array of lowercase letters sorted in ascending order, find the smallest letter in the given array greater than a given ‘key’.

Assume the given array is a circular list, which means that the last letter is assumed to be connected with the first letter. This also means that the smallest letter in the given array is greater than the last letter of the array and is also the first letter of the array.

Write a function to return the next letter of the given ‘key’.

Example 1:

Input: ['a', 'c', 'f', 'h'], key = 'f'
Output: 'h'
Explanation: The smallest letter greater than 'f' is 'h' in the given array.
Example 2:

Input: ['a', 'c', 'f', 'h'], key = 'b'
Output: 'c'
Explanation: The smallest letter greater than 'b' is 'c'.
Example 3:

Input: ['a', 'c', 'f', 'h'], key = 'm'
Output: 'a'
Explanation: As the array is assumed to be circular, the smallest letter greater than 'm' is 'a'.
Example 4:

Input: ['a', 'c', 'f', 'h'], key = 'h'
Output: 'a'
Explanation: As the array is assumed to be circular, the smallest letter greater than 'h' is 'a'.

*/

/*
-------------------------    My Approaches:
1. Modified binary search

    very much similar to pb 687 grok with the only idfference is that it is a ciruclar array.

    Time complexity: O(logn)
    Space complexity: O(1)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes

*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class NextLetter {
 public:
  static char getNextLetter(const vector<char>& letters, char key){
    if(key >= letters[letters.size()-1])
      return letters[0];

    int beg = 0, end = letters.size()-1, index = 0;
    while(beg <= end){
      int mid = beg + (end-beg)/2;
      if(letters[mid] <= key)
        beg = mid+1;
      else{
        index = mid;
        end = mid-1;
      }
    }
    return letters[index];
  }

  static char searchNextLetter(const vector<char>& letters, char key) {
    // TODO: Write your code here
    if(!letters.size() || ((letters.size() < 2) && key == letters[0]))
      return (char)0;
    return getNextLetter(letters, key);
  }
};

int main(int argc, char* argv[]) {
  cout << NextLetter::searchNextLetter(vector<char>{'b', 'd'}, 'd') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;
}



//  Other Approaches(1)
