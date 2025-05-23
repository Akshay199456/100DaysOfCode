/*
Problem statement:

You are given a set of numbers nums consisting of distinct numbers. Find the size of the largest subset that satisfies the following condition: for each two number pairings in the set, one number is divisible by the other.

Input
nums: a list integers representing the set.
Output
An integer representing the size of the largest subset that satisfy the condition.

Examples
Example 1:
Input:

nums = [1, 2, 3]
Output: 2

Explanation:

Either [1, 2] or [1, 3] satisfy the condition, because both 2 and 3 are both divisible by 1. Either way, the largest set has a size of 2.

Example 2:
Input:

nums = [1, 2, 4, 8]
Output: 4

Explanation:

In this set, for each pair of numbers, at least one is divisible by the other because they are all powers of 2. As such, the max subset has a size of 4, the size of the original set.

Constraints
1 <= len(nums) <= 1000
1 <= nums[i] <= 10^9
Each number in nums is unique
*/

/*
-------------------------    My Approaches:
1. combinatorics + dfs

    we can use basic brute force approach which includes combinatorics + dfs to solve this problem.
    we sort the numbers at the very beginning as it makes it easy to compare the numbers later on as we just need to compare each number with the previous
    number since they are in sorted order. in addition, at each step , we have one of two chocie we can make:
    1) either add this element to the lsit 2) or not add this element. when the index reaches the lisze size, we lknow we ahve
    covered all elements and as a result, we make the check if the numbers are in sorted roder. 

    we can actually improve upon the approach by only storing the last number we have encountered since the array is sorted similar to what we had in the
    previous problem pb 57. that way we can save on the O(n) time complexity that it takes once we reach the 
    index end.

    Time complexity: O(nlogn + n*2^n)
    Space complexity: O(n)


2. Top-down approach

    we can also solve this problem wih the top-down approach just like we did with pb 57. since we are interested in finding the largest divisble subset,
    we can make this taks easier by sorting the numbers in proper order. once they are sorted, the states we are interested in
    finding the LS(largest subset) at i inclduing the element nums[i]. the transition then, would be how do we get
    from LS(i-1) to LS(i). well, if e have the array sorted, then we just need to check with the 
    previous subsets and see if the current element nums[i] is divisble by nums[j]. if it is and by transitive proerpty, we can
    then extend that subset with this new element and thus icnrease the length by 1. if its not, then we cant continue with the subset.

    Time complexity: O(nlogn + n^2) = O(n^2)
    Space complexity: O(n)


3. Bottom-up approach

    We can improve upon the top-down approach using the bottom-up approach in almost hte exact same way that we did in pb 57.
    the only difference is that for the check we check if currNum % prevNum == 0. if it is, then we can extend that subset with this element.
    else we cant

    Time complexity: O(nlogn + n^2) = O(n^2)
    Space complexity: O(n)

*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
1. Solution

    divisibility is transitive. that is, if a is divisble by b and b is divisible by c, then a is divisbile by c. furthermore, if a is divisible by b,
    then a must be larger than it (or equal, bit that is not relevant in this queston as the numbers are unique)

    therefore, if a set satisfies the condition, starting from the lowest number, the next smallest number must be divisible by the 
    current nunmber. this means that we can expand on the set by finding a number that is divisble by the largest element in the exisitng set

    in that case, for each number in nums, consider the size of the largest set that satisfies the condition and whose largest element is equal to that number.
    it is equal to the size of th ;argest subset whose largest number can divide the current number (not including the currednt number)
    plus 1. if no such set exists, then the largest size is 1 becase the set simplt consists of the number itself (and the condition always
    holds true for sets with one element)
    
    knowing this, we have built up a logic for  a bottom-up DP: starting fromt he smallest number, we calcualte the size of the largest set that satisifies the condtioon 
    and whose largest number is that number using the mthods above. then the size of the largest size
    that satisifeis the condition is the max size from the numbers calculated above.

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

/*
void printList(std::vector<int> & list){
    for(int i=0; i< list.size(); i++){
        std::cout<<list[i]<<" ";
    }
    std::cout<<std::endl;
}
*/

bool isConditionSatisfied(std::vector<int> & list){
//     printList(list);
    for(int i=1; i<list.size(); i++){
        if(list[i] % list[i-1] != 0)
            return false;
    }
    return true;
}


void generateSubsets(std::vector<int> & nums, int index, std::vector<int> list, int & maxLength){
    if(index == nums.size()){
        bool isValid = isConditionSatisfied(list);
        if(isValid)
            maxLength = std::max(maxLength, (int)list.size());
    }
    else{
        // we can add this number to the set
        list.push_back(nums[index]);
        generateSubsets(nums, index+1, list, maxLength);
        
        // or not add it to the list
        list.pop_back();
        generateSubsets(nums, index+1, list, maxLength);
    }
}

int find_largest_subset(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<int> list;
    int maxLength = 1;
    std::sort(nums.begin(), nums.end());
    generateSubsets(nums, 0, list, maxLength);
    return maxLength;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> nums = get_words<int>();
    int res = find_largest_subset(nums);
    std::cout << res << '\n';
}



// My Approaches(2)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int getLargestSubset(int i, std::vector<int> & nums, std::vector<int> & memo, int & maxLength){
    if(!i)
        return 0;
    else if(memo[i])
        return memo[i];
    
    int len = getLargestSubset(0, nums, memo, maxLength) + 1;
    int currNum = nums[i-1];
    
    for(int j=1; j < i; j++){
        int prevNum = nums[j-1];
        int value = getLargestSubset(j, nums, memo, maxLength);
        if(currNum % prevNum == 0)
            len = std::max(len, value+1);
    }
    
    maxLength = std::max(maxLength,len);
    return memo[i] = len;
}


int find_largest_subset(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    int n = (int) nums.size();
    std::vector<int> memo(n+1,0);
    int maxLength = 0;
    std::sort(nums.begin(), nums.end());
    getLargestSubset(n,nums, memo, maxLength);
    return maxLength;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> nums = get_words<int>();
    int res = find_largest_subset(nums);
    std::cout << res << '\n';
}


// My Approaches(3)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_largest_subset(std::vector<int> nums) {
    // WRITE YOUR BRILLIANT CODE HERE
    int n = (int) nums.size();
    std::vector<int> dp(n+1,0);
    int maxLength = 0;
    std::sort(nums.begin(), nums.end());
    
    for(int i=1; i<=n; i++){
        int currNum = nums[i-1];
        dp[i] = dp[0]+1;
        
        for(int j=1; j<i; j++){
            int prevNum = nums[j-1];
            if(currNum % prevNum == 0)
                dp[i] = std::max(dp[i], dp[j]+1);
        }
        maxLength = std::max(maxLength, dp[i]);
    }
    
//     getLargestSubset(n,nums, memo, maxLength);
    return maxLength;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> nums = get_words<int>();
    int res = find_largest_subset(nums);
    std::cout << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy, max, max_element
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_largest_subset(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> max_subsets;
    for (int i = 0; i < nums.size(); i++) {
        int max_subset = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0) {
                max_subset = std::max(max_subset, max_subsets[j]);
            }
        }
        max_subsets.emplace_back(max_subset + 1);
    }
    return *std::max_element(max_subsets.begin(), max_subsets.end());
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> nums = get_words<int>();
    int res = find_largest_subset(nums);
    std::cout << res << '\n';
}
