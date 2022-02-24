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

    like provided in the notes, this approac h improves upon our apprach and makes it better.
    they way it does that is it finds the first elements tha violate the condition on
    either end. just because we have found these elements doesnt mean, that's the answer 
    as we could have a few elements that exceed outside these elements in terms of range
    on either side

    so once we get these inital values, we find the max and min of the range. we then 
    compare the remaingin elements on either side and makes sure they are in the range.
    if they are not, we extend.

    Time complexity: O(n)
    Space complexity: O(n)


2. 
    Time complexity: O(n)
    Sopace complexity: O(1)
"""


"""
-------------------------    Notes
once an array is sorted, the smalles tnumber is at the beginning and hte largest number is at the 
end of the array. so if we start fro te beginning of the array to find the first elemetn which 
is out of sorting order ie which is amller than its previous element and similarly
from the end of the array to find th efirst element which is bigger than its previous element
, will sorting the subrray between these two numbers result in the whole arrray being sorted?

et’s try to understand this with Example-2 mentioned above. In the following array, what are the first numbers out of sorting order from the beginning and the end of the array:

    [1, 3, 2, 0, -1, 7, 10]
Starting from the beginning of the array the first number out of the sorting order is ‘2’ as it is smaller than its previous element which is ‘3’.
Starting from the end of the array the first number out of the sorting order is ‘0’ as it is bigger than its previous element which is ‘-1’
As you can see, sorting the numbers between ‘3’ and ‘-1’ will not sort the whole array. To see this, the following will be our original array after the sorted subarray:

    [1, -1, 0, 2, 3, 7, 10]
The problem here is that the smallest number of our subarray is ‘-1’ which dictates that we need to include more numbers from the beginning of the array to make the whole array sorted. We will have a similar problem if the maximum of the subarray is bigger than some elements at the end of the array. To sort the whole array we need to include all such elements that are smaller than the biggest element of the subarray. So our final algorithm will look like:

From the beginning and end of the array, find the first elements that are out of the sorting order. The two elements will be our candidate subarray.
Find the maximum and minimum of this subarray.
Extend the subarray from beginning to include any number which is bigger than the minimum of the subarray.
Similarly, extend the subarray from the end to include any number which is smaller than the maximum of the subarray.

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
def get_element_misalligned(arr, index):
  if index:
    res, pos = None, len(arr)-2
    isEnd = False
    while pos >= 0 and not isEnd:
      if arr[pos] > arr[pos+1]:
        res = pos+1
        isEnd = True
      pos -= 1
    return res
  else:
    res, pos = None, 1
    isEnd = False
    while pos < len(arr) and not isEnd:
      if arr[pos] < arr[pos-1]:
        res = pos-1
        isEnd = True
      pos += 1
    return res


def get_shortest_length(arr):
  beg, end = get_element_misalligned(arr, 0), get_element_misalligned(arr, 1)
  if beg is None or end is None:
    return 0
  min_value, max_value = min(arr[beg:end+1]), max(arr[beg:end+1])
  start_beg, start_end = beg-1, end+1 

  while start_beg >= 0:
    if arr[start_beg] > min_value:
      beg = start_beg
    start_beg -=1

  while start_end < len(arr):
    if arr[start_end] < max_value:
      end = start_end
    start_end += 1
  
  return end - beg +1


# Other Approaches(2)
import math


def shortest_window_sort(arr):
  low, high = 0, len(arr) - 1
  # find the first number out of sorting order from the beginning
  while (low < len(arr) - 1 and arr[low] <= arr[low + 1]):
    low += 1

  if low == len(arr) - 1:  # if the array is sorted
    return 0

  # find the first number out of sorting order from the end
  while (high > 0 and arr[high] >= arr[high - 1]):
    high -= 1

  # find the maximum and minimum of the subarray
  subarray_max = -math.inf
  subarray_min = math.inf
  for k in range(low, high+1):
    subarray_max = max(subarray_max, arr[k])
    subarray_min = min(subarray_min, arr[k])

  # extend the subarray to include any number which is bigger than the minimum of the subarray
  while (low > 0 and arr[low-1] > subarray_min):
    low -= 1
  # extend the subarray to include any number which is smaller than the maximum of the subarray
  while (high < len(arr)-1 and arr[high+1] < subarray_max):
    high += 1

  return high - low + 1


def main():
  print(shortest_window_sort([1, 2, 5, 3, 7, 10, 9, 12]))
  print(shortest_window_sort([1, 3, 2, 0, -1, 7, 10]))
  print(shortest_window_sort([1, 2, 3]))
  print(shortest_window_sort([3, 2, 1]))


main()



def shortest_window_sort(arr):
  # TODO: Write your code here
  if len(arr) < 2:
    return 0
  return get_shortest_length(arr)
