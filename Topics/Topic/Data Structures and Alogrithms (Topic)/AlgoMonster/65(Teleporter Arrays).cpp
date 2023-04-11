/*
Problem statement:

You are given two sorted arrays of distinct integers, arr1, and arr2. Your goal is to start from the beginning of one array, and arrive to the end of one array (it could be the same array or not).

For each step, you can either move forward a step on an array, or move to a square in the other array where the number is the same as the number in your current square ("teleport"). Your total score is defined as the sum of all unique numbers that you have been on.

Find the maximum score that you can get given the above rules. Since the result might be very large and cause overflow, return the maximum score modded by 10^9 + 7.

Parameters
arr1: A list of ordered, distinct integers.
arr2: Another list of ordered, distinct integers.
Result
The maximum score possible, modded by 10^9 + 7.
Examples
Example 1
Input: arr1 = [2, 4, 5, 8, 10], arr2 = [4, 6, 8, 9]

Output: 30

Explanation:


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
for simplicity, we call numbers that appears multiple times "teleporters". because both arrays are ordered and distinct, teleporter
number must appear in both array exactly once, and each teleporter in both arrays must be ordered in the same way.

consider the interval between two teleporters. if there are no number between hese two numbers that appear in both array, then in those steps you can only go forward.
therefore, the score in that section would be the sum of the subarray in that section.

furthermroe, regardless where yo start, it does not affect the choce whether to go top or bottom in that section. if you start fromt he top array,
you can go left to continue the top array and teleport to the bottom array. the same foes for if you start start from the bttom array.
in that case, to maximize the score, we only need to maximize the score of each interval between two teleporters.

note that the same holds true for numbers before the first teleporter and after the final teleporter so we can apply the same logic.

for the same implementation, we use two poonters, one for each array. we always move the smaller pointer forward and keep track of the sum of the subsection until both pointers are the same. then we find
the maximim sum between twhese two subsections and add them to the result. repeat this until we finish iterating through both
arrays.

You can also look at it as a graph problem and imagine there is a bidirectional edge between two identical numbers between
the arrays. either way, you shouild end up with something similar tot he solution above.


    Time complexity: O(n+m) where n and m are the size of the arrays, respectively.
    Space complexity: O(1)



Additional notes:

    now, the logic for the program makes sense. as per the problem, we call the numbers that appear in both the 
    arrays as teleporters as using these pointes, we can telemport form one array to another. 
    as a result, the problem then boils down to getting the max subarray sum from each of the two arrays between two teleporters.
    this is because we nkow that the value of the telporter is the same and since the problem is asking us for the maximum score that we can 
    obtain using the rules, we want to get the max subarray sum between any two telporters.

    once we are at the telporter, then is quite easy. we just need to get the max subarray sum.
    As a rsult, we movethee pointers forward on the arrays depending on whichever pointer is on the smaller value since we know both arrrays are sorted.
    this way when the array 1 has the smaller vealue compared to array 2, we move its pointer forward. similarly, awhen array2 has the smaller value, we move
    its pointer forward. this way we go through the values of each of the arrays till wwee ecnounter array2[ptr1] = array2[ptr2]. when this copndition
    becomes valid, we then choose the max subarray sum from the two, mvoe the poitners forward and reset the sujms to 0 for the next
    section. 
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy, max
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int MODULO_AMT = 1000000007;

int maximum_score(std::vector<int> arr1, std::vector<int> arr2) {
    int ptr1 = 0, ptr2 = 0;
    int n1 = arr1.size(), n2 = arr2.size();
    // We use long for these attributes because they can exceed integer limit.
    // The max score, summed up and modded
    long long result = 0;
    // The sum of the subarray between the previous teleporter and the pointer for each array
    long long section_sum1 = 0, section_sum2 = 0;
    // As long as the two arrays are not both at the end, we increment the pointers
    while (ptr1 < n1 || ptr2 < n2) {
        // If they match, we sum up the max score of that section and the score of
        // the current position, then shrink result by using modulo
        // Reset the sums and move the pointers afterwards
        if (ptr1 < n1 && ptr2 < n2 && arr1[ptr1] == arr2[ptr2]) {
            result += std::max(section_sum1, section_sum2) + arr1[ptr1];
            result % MODULO_AMT;
            section_sum1 = 0;
            section_sum2 = 0;
            ptr1++;
            ptr2++;
            continue;
        }
        // If either "ptr1" reaches the end, or "ptr2" is smaller than "ptr1"
        // we move "ptr2" and keep track of the sum.
        if (ptr1 == n1 || (ptr2 != n2 && arr1[ptr1] > arr2[ptr2])) {
            section_sum2 += arr2[ptr2];
            ptr2++;
        } else {
            // Otherwise, we move "ptr1" and keep track of that sum
            section_sum1 += arr1[ptr1];
            ptr1++;
        }
    }
    // Add the remaining max section sum to the result, then return the result modulo
    result += std::max(section_sum1, section_sum2);
    return result % MODULO_AMT;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> arr1 = get_words<int>();
    std::vector<int> arr2 = get_words<int>();
    int res = maximum_score(arr1, arr2);
    std::cout << res << '\n';
}