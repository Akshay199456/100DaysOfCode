/*
-------------------------Question:

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/

/*
-------------------------    My Approaches:
1. One pass approach with two pointer

We can use a single pass to go through the array using the two pointer approach. Since we want the even elements first
followed by odd elements, whenever we see and off element, we push it to the end and bring back end by 1 position. If
we see an even element, we make the beg pointer move forward by 1.

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void sortArray(vector<int> & array){
        int beg = 0, end = array.size()-1;
        while(beg<end){
            if(array[beg] %2 == 0)
                beg++;
            else{
                swap(array[beg], array[end]);
                end--;
            }
        }
    }
    
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() >1)
            sortArray(A);
        return A;
        
    }
};