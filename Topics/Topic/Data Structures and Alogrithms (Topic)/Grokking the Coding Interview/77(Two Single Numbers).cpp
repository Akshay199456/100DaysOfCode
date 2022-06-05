/*
Problem statement:

n a non-empty array of numbers, every number appears exactly twice except two numbers that appear only once. Find the two numbers that appear only once.

Example 1:

Input: [1, 4, 2, 1, 3, 5, 6, 2, 3, 5]
Output: [4, 6]
Example 2:

Input: [2, 1, 3, 2]
Output: [1, 3]
*/

/*
-------------------------    My Approaches:
1. [not coded]

    tbf, we cam yup with two approaches but none of those approaches are the exor approach.

    approach 1

    thee first apporach was using hashmap or hashset to store orccurences. when it is not present, we insert it. when it is
    present, we remove it. at the end, the ones that remain are the ones that have count 1.

    time complexity: O(n)
    Space complexity: O(n)


    approach 2

    we can sort the arry and then use two poitners to find the one which dont hae a duplicate occurrence

    Time complexity: O(nlogn)
    Space complexity: O(1)
*/


/*
-------------------------    Other Approaches 
1. exor approach

    so the first part of this solution where we did the exor of the nmbers is what we had through of as well.

    this problem quite similar to single numer, the only difference is that, we have two single numbers isntead of one in this problem.

    lets assume num1 and num2 are the two single numbers. if we do exor of all elmeents of the given array, we wll be left with xor of num1 and num2 as
    all other numbers will cancel each other because all of them appeared twice. lets call it n1xn2. 

    since we know that num1 and num2 are two difference numbers, therefore, they should have at least one bit different between them. if a bit in n1xn2 is '1', this means that num1 and
    num2 have different bits in that place, as we know that we can get '1' only when we do exor of two
    different bits i.e

    1 xor 0 = 0
    0 exor 1 = 1

    can tqake any bit which is '1' in n1xn2 and partition all numbers in the given array into 2 groups based on that bit. one group will have all thse numbers with that bit set to '0' while the other
    with the bit set to '1'. this will ensure that num1 will be in one group and num2 will be in the other. we can take exor of all numbers in each
    groups separtly to get num1 and num2 as all other numbers in each group will cancel each other. here are the steps:

    1. taking xor of all numbers in the given array give us xor of num1 and num2 , calling this xor n1xn2
    2. find any bit which is set in n1xn2. we can take the rightmost bit which is 1. lets call this rightmostbit.
    3. iteratre through all numbers of the input array to a[rtition them into two groups based on rightmostbit. take xor of all numbers in both the groups separartly. both these exor are the reqired numbers.

    Time complexity: O(n)
    Space complexity: O(1)
*/


/*
-------------------------    Notes

*/



//  My approaches(1)



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <vector>

class TwoSingleNumbers {
public:
  static vector<int> findSingleNumbers(vector<int> &nums) {
    // get the XOR of the all the numbers
    int n1xn2 = 0;
    for (int num : nums) {
      n1xn2 ^= num;
    }

    // get the rightmost bit that is '1'
    int rightmostSetBit = 1;
    while ((rightmostSetBit & n1xn2) == 0) {
      rightmostSetBit = rightmostSetBit << 1;
    }
    int num1 = 0, num2 = 0;
    for (int num : nums) {
      if ((num & rightmostSetBit) != 0) // the bit is set
        num1 ^= num;
      else // the bit is not set
        num2 ^= num;
    }
    return vector<int>{num1, num2};
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 2, 1, 3, 5, 6, 2, 3, 5};
  vector<int> result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;

  v1 = {2, 1, 3, 2};
  result = TwoSingleNumbers::findSingleNumbers(v1);
  cout << "Single numbers are: " << result[0] << ", " << result[1] << endl;
}
