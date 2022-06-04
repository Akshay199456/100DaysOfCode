/*
Problem statement:

In a non-empty array of integers, every number appears twice except for one, find that single number.

Example 1:

Input: 1, 4, 2, 1, 3, 2, 3
Output: 4
Example 2:

Input: 7, 9, 7
Output: 9
*/

/*
-------------------------    My Approaches:
1. Bitwise exor

    We can use hte bitwise exor patern here in order to solve the problem. since we know
    tht each element occurs twice except the one element, if we were to exor all the elements
    , all the elements that have count 2 would cancel each other out leaving the number
    that has count 1

    Time complexity: O(n)
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
one straight forward solution can be to use hashmap and iterate through input:
  1. if a number s already present in hashmap, remove it
  2. if number is not presetn in hashmpa, add t.
  3., in the end, only number left in hte hashmap is our requireed single number

  time complexity: On

Space complexity: O(n)


Can do better with Exor appraoch.
the following two properties of xor are:
  1. it retjurns zero if we take xor of two same numbers
  it returns the same number if we xor with zero

so we can exor all the numbers in t einput; duplicate numbers will zero our
each other and we will eb left with the single number

time complexity: O(n)
Space complexity: O(1)
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int getNumber(const vector<int>& arr){
      int number = 0;
      for(int ele: arr){
        number ^= ele;
      }
      return number;
    }

    static int findSingleNumber(const vector<int>& arr) {
      // TODO: Write your code here
      return getNumber(arr);
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
  cout << SingleNumber::findSingleNumber(vector<int>{7,9,7}) << endl;
  cout << SingleNumber::findSingleNumber(vector<int>{0,1,1,2,2}) << endl;
  cout << SingleNumber::findSingleNumber(vector<int>{0,0,1,2,2}) << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
  public:
    static int findSingleNumber(const vector<int>& arr) {
      int num = 0;
      for (int i=0; i < arr.size(); i++) {
        num = num ^ arr[i];
      }
      return num;
    }
};

int main(int argc, char* argv[]) {
  cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}