/*
Problem statement:

An array of boolean values is divided into two sections; the left section consists of all false and the right section consists of all true. Find the boundary of the right section, i.e. the index of the first true element. If there is no true element, return -1.

Input: arr = [false, false, true, true, true]

Output: 2

Explanation: first true's index is 2.
*/

/*
-------------------------    My Approaches:
1. binary search

    this problem is a perfect candidate for binary search. since we have the true and false ordered, we can use the binary search to find hte boundary where the true an false meet easily by skipping
    through a whole set of elements. rememeber, binary search is a solid pattern to use when you ahve ordered elements of any size.

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
binary decision we have to make when we look at an element is:
    1. if the element is false, we discard everything to the lft and the current element itself.
    2. if the element is true, the current element could be the first true although there may be other true to the left. we discard everything to the right but what about the current element?

    we can either keep the current element in the range or record it somewhere and then discard it. here we choose the latter.

    we keep a variable boundary_undex that represents the elftmost true's index currently recorded. if the current element is true, then we update boundar_index
    with its index and discard everything to the right inclduing the current element itself since its index has been recorded by the variable

    good thing with this approach is that we dont have to moduft the while loop logic in the vanilla binary search from the last module besides introducing a variable



Alternative approach

another approach to handle case 2 above is to keep the current element in the search range instead of sicarding it i.e if arr[mid]: right = mid instead
of right = mid-1. however, doing this without modifying the while condition will result in an infinte loop. this is because
when left == right, right = mid will not modify right and this, not shrink search range and we will bne stuck in the while loop forever. to makee this worl
we have to remove teh euality in the while condition.

in addition, a while loop without eaulity will miss the single-element edge case so we have to add an additional hcck after the loop to handle this case.
overall, we have to make three modifications to the vanilla binary search to make it work



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

int find_boundary(std::vector<bool> arr) {
    // WRITE YOUR BRILLIANT CODE HERE
    int beg{0}, end{arr.size()-1};
    while(beg<=end){
        int mid = beg + (end-beg)/2;
        if(!arr[mid])
            beg = mid+1;
        else{
            if(!mid)
                return 0;
            else if(!arr[mid-1])
                return mid;
            else
                end = mid-1;
        }
    }
    return -1;       
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<bool> arr;
    bool b;
    while (ss >> std::boolalpha >> b) {
        arr.push_back(b);
    }
    int res = find_boundary(arr);
    std::cout << res << '\n';
}



//  Other Approaches(1)
include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_boundary(std::vector<bool> arr) {
    int left = 0;
    int right = arr.size() - 1;
    int boundaryIndex = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid]) {
            boundaryIndex = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return boundaryIndex;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<bool> arr;
    bool b;
    while (ss >> std::boolalpha >> b) {
        arr.push_back(b);
    }
    int res = find_boundary(arr);
    std::cout << res << '\n';
}