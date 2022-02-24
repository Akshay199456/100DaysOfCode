"""
Problem statement:

iven an array, find the length of the smallest subarray in it which when sorted will sort the whole array.

Example 1:

Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted
Example 2:

Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted
Example 3:

Input: [1, 2, 3]
Output: 0
Explanation: The array is already sorted
Example 4:

Input: [3, 2, 1]
Output: 3
Explanation: The whole array needs to be sorted.
"""

"""
-------------------------    My Approaches:
1. 
    Start: 7:47 pm
    End: 8:15 pm

    the brute foce would have been to generate all the subarrays and then comparee each
    subarray against the sorted version of the array and see in how many places they are mismatched.

    the more efficient way is to just compare the array against its sorted version. we need to 
    then find the starting end ending point of the mismatch. these 2 variables will
    fictate the result.


    Time complexity: O(nlogn)
    Space complexity: O(m)
*/
"""

"""
-------------------------    Other Approaches 
1.
    Start: 
    End: 

    

    Time complexity: O()
    Space complexity: O()
"""


"""
-------------------------    Notes

"""



#  My approaches(1)
def get_shortest_length(arr):
  arr_copy = arr.copy()
  arr_copy.sort()
  beg = end = None
  index = 0
  while index < len(arr):
    if arr_copy[index] != arr[index]:
      if beg is None:
        beg = index
      end = index
    index += 1

  return end-beg+1 if end is not None else 0


def shortest_window_sort(arr):
  # TODO: Write your code here
  return get_shortest_length(arr)




# Other Approaches(1)
