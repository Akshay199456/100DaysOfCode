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
