/*
Problem statement:

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not necessarily the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
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
sorting the array before indexing works find bit this solution uises a max heap. heapify  is O(n) and popping the first k element is O(klogn)) so combined is 
O(n + klogn))

alternatively, we could use quick select for this particular problem. worst case scenaior, it runs on O(n^2), but on average, it runs
on O(n).

quick select uses the principle of quick sort, only during each process, we onky need to care about the middle point, compared
to k-1(because the questions uses 1 indexng) and dependng the result, we either stop the progtam, recurse to the left side
or recurse to the right side.

note that it is easyu to get the indices of quick select wrong so in a real coding interview, its often better to impleent the heap solution and have
less chance of error

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
