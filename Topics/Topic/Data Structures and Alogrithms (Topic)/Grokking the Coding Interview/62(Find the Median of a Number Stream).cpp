/*
Problem statement:

Design a class to calculate the median of a number stream. The class should have the following two methods:

insertNum(int num): stores the number in the class
findMedian(): returns the median of all numbers inserted in the class
If the count of numbers inserted in the class is even, the median will be the average of the middle two numbers.
*/

/*
-------------------------    My Approaches:
1. 

    Came up with two approaches but neither approach the pattern we are trying to implement.

    Approach 1:
        store numbers in vector: time compleixty of insertnum = O(1)
        whenever, we are asked to find median, we sort the vector, and get the median.
        time complexity for findMedian: O(nlogn)
    
    Approach 2:
        store numbers in a heap: time complexity for insertNum = O(log n)
        when asked to find median, we pop elements from heap into a stack till we hit
        the elements we are looking for . we can then get the avg.
        Time comepxlty for findmoedian: O(nlogn)

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

*/



//  My approaches(1)



//  Other Approaches(1)
