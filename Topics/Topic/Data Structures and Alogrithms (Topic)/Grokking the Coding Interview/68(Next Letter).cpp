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
problem follows the binary search pattern. since bonary search helps us find an element in
a sorted array efficiently, we can use a modfiied version of it to find next letter

can use a similar approach to ceiling of a number. there are a couple of differences through:

1. the arrya is considered circular which means if the key is bigger than the last letter of the
arayy or if it is smalletr than the first letter of the array, the key's next letter will
be the first letter of the array

2. the other difference is that we have to find the next biggest letter which cant be eqaul to the
'key'. this means that we will ignore the case where key == arr[middle]. to handle this case,
we can update our start range to start = middle + 1;

in the end, instead of returning the eklement pointed out by start, we have to
return the letter pointed out by start % array_length. this is needed becasue of point 2
dicussed above. imagine that th elast ltter of the array is equal to the 'key'. in that case, we 
have to return the first letter of the input array.
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
using namespace std;

#include <iostream>
#include <vector>

class NextLetter {
 public:
  static char searchNextLetter(const vector<char>& letters, char key) {
    int n = letters.size();

    int start = 0, end = n - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < letters[mid]) {
        end = mid - 1;
      } else {  // if (key >= letters[mid]) {
        start = mid + 1;
      }
    }
    // since the loop is running until 'start <= end', so at the end of the
    // while loop, 'start == end+1'
    return letters[start % n];
  }
};

int main(int argc, char* argv[]) {
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;
}
