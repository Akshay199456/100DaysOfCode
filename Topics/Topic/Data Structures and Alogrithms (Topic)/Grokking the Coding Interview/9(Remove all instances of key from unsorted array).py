"""
Problem statement:

Problem 1: Given an unsorted array of numbers and a target ‘key’, remove all instances of ‘key’ in-place and return the new length of the array.

Example 1:

Input: [3, 2, 3, 6, 3, 10, 9, 3], Key=3
Output: 4
Explanation: The first four elements after removing every 'Key' will be [2, 6, 10, 9].
Example 2:

Input: [2, 11, 2, 2, 1], Key=2
Output: 2
Explanation: The first two elements after removing every 'Key' will be [11, 1].
Solution: This problem is quite similar to our parent problem. We can follow a two-pointer approach and shift numbers left upon encountering the ‘key’. Here is what the code will look like:

"""

"""
-------------------------    My Approaches:
1. 
    Start: 7:57 pm
    End: 8:07 pm

    two pointer approach similar to pb 8.

    Time complexity: O(n)
    Space complexity: O(1)
*/
"""

"""
-------------------------    Other Approaches 
1.
    Start: 
    End: 

    

    Time complexity: O(n)
    Space complexity: O(1)
"""


"""
-------------------------    Notes

"""



#  My approaches(1)
def remove_element(arr,key):
  length, beg, end = 0,0,0
  while end < len(arr):
    if arr[end] != key:
      arr[beg] = arr[end]
      length += 1
      beg += 1
    end += 1

  return length

def main():
  print("Array new length: " +
        str(remove_element([3, 2, 3, 6, 3, 10, 9, 3], 3)))
  print("Array new length: " +
        str(remove_element([2, 11, 2, 2, 1], 2)))


main()



# Other Approaches(1)
"""
def remove_element(arr, key):
  nextElement = 0  # index of the next element which is not 'key'
  for i in range(len(arr)):
    if arr[i] != key:
      arr[nextElement] = arr[i]
      nextElement += 1

  return nextElement
"""