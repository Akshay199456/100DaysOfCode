/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
*/

/*
-------------------------My Approaches:

1. Binary Search

This approach uses binary search to find the first bad version. If we encounter a bad version,
we check the element behind if it's a bad version as well. If it is not, then we know the element
we are at is the start of the bad versions, else we check the list of elements behind it to find
start of the bad versions. However, if it's good, we check ahead of the element for any bad elements.

Time complexity: O(log N)
Space complexity: O(1)
*/

// My Approaches(1)
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBad(int beg, int end){
    	// int mid = beg + (end-beg)/2; //Both work here; this takes care of overflow
        int mid = (beg)/2 + (end)/ 2;
        
        if(beg == end)
            return beg;
        else if (isBadVersion(mid)){
            if(!isBadVersion(mid-1))
                return mid;
            else
                return firstBad(beg, mid - 1);
        }
        else
            return firstBad(mid+1, end);
    }
    
    int firstBadVersion(int n) {
      return firstBad(1, n); 
    }
};