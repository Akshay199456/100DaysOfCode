/*
Problem statement:

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:
Input:n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:
1 is typically treated as an ugly number.
n does not exceed 1690.
*/

/*
-------------------------    My Approaches:
1. Brute force (not coded)

    we could go through each number starting from 1 and see if it its prime factors only includes 2,3,5. if it does, we then increment count
    till count = n. once count = n, we have our result and return it.

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
Brute force

    a brute force method would generate ugly numbers and store all possibities for look up. we can generate them out of order and then sort them later.

    in theory this is impossible, but since there ae limits on te size of datatypes, we only need to loop up to those limits.

    Time complexity: O()
    Space complexity: O()


Min Heap

    instead of generating all the ugly numbers, sorting them, and getting the nth, we can instead generate them in order and stop when we get to
    the nth.

    in order to generate them in order, lets consider starting wit th just the number 1. to generat eht e next few ugly numbers,
    we can take 1 and multiple it by 2,3 and 5. we add the newly generated numbers to the list if they dont already exist. the new list is
    now [1,2,3,5].

    next, we will take the next smallest element which is 2. once again, we take 2 and multiply it by 2,3, and 5 and we get 4,6 and 10.
    we add the newly generated nmbers to the list if they dont already exist. the new list in sorted order is now [1,2,3,4,5,6,10].

    the next smallest element is 3. taking 3 and multiplying it by 2,3 and 5, we get 6,9, and 15. we add the newly generated numbers tot he list if 
    they dont already exist.  6 already exists in the list so we skip it and insert 9 and 15 into our list. the list is now
    [1,2,3,4,5,6,9,10,15]

    then we deal with 4, then 5, then 6, then 8 (which will be generated from 4), etc...

    continuing this pattern, we see that in th e n-1th iteration, the next smallest element that we deal with will be our
    nth ugly number as long as we keep the list in a sorted order. to do so, we can use a min heap which keeps the elmeents in asnceding order and will maintain the top most
    element as the smallest number. once we fininsh multiplyingthe samllest number (i.e the top element in th eheap) by 2,3,5, we can pop it from our heap
    and now the next smallest number will be at the tio of the heap. lastly, to check if a number has been generated, we can use a smiple hash set.

    space complexity: O(n) as there are at most 3n elements in heap
    time complexity: O(nlogn)
        we build up the ugly numbers by popping ht esmallerst and insert its multiples. sonmce the inserted values are most lilkely
        larger than the existing ugl numbers, the amortized insertion time is O(1). each deletion time is O(logn) so the total deletion time
        is O(nlogn). overall, the amortized time complexity is O(nlogn)
*/



//  My approaches(1)
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits
#include <unordered_set>
#include <queue>
#include <vector>

int getNumber(int n){
    std::unordered_set<int> elementSet;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    pq.push(1);
    elementSet.emplace(1);
    int count = 0;
    std::vector<int> primeList{2,3,5};
    
    while(!pq.empty()){
        int currTop = pq.top();
        pq.pop();
        ++count;
        if (count == n)
            return currTop;
        
        for(int i=0; i<primeList.size(); i++){
            int nextNumber = primeList[i] * currTop;
            if(elementSet.find(nextNumber) == elementSet.end()){
                elementSet.emplace(nextNumber);
                pq.push(nextNumber);
            }
        }
    }
    return -1;
}

int nth_ugly_number(int n) {
    // WRITE YOUR BRILLIANT CODE HERE
    return getNumber(n);
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int res = nth_ugly_number(n);
    std::cout << res << '\n';
}



//  Other Approaches(1)
int nth_ugly_number(int n) {
  std::vector<int> ugly_numbers;
  long long i, j, k, max_int = INT_MAX;
  for (i = 1; i <= max_int; i *= 2) {
    for (j = i; j <= max_int; j *= 3) {
      for (k = j; k <= max_int; k *= 5) {
        ugly_numbers.emplace_back((int)k); // since we guarantee that k <= int limit
      }
    }
  }
  sort(ugly_numbers.begin(), ugly_numbers.end());
  return ugly_numbers[n - 1];
}


// Other Approaches(2)
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits
#include <queue> // priority_queue
#include <unordered_set> // unordered_set

const int allowed_prime[3] = {2, 3, 5};

int nth_ugly_number(int n) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> ans_heap;
    std::unordered_set<int> used_nums;
    ans_heap.push(1);
    used_nums.emplace(1);
    for (int i = 0 ; i < n - 1; i++) {
        int res = ans_heap.top();
        ans_heap.pop();
        for (int multiplier : allowed_prime) {
            int num = res * multiplier;
            if (!used_nums.count(num)) {
                ans_heap.push(num);
                used_nums.emplace(num);
            }
        }
    }
    return ans_heap.top();
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n;
    std::cin >> n;
    ignore_line();
    int res = nth_ugly_number(n);
    std::cout << res << '\n';
}