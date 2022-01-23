"""
Given an array of positive numbers and a positive number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.


"""

"""
-------------------------    My Approaches:
1. sliding window approach
    Start: 8:37 pm
    Pause: 9:27 pm

    Resume: 7:56 pm
    Pause: 7:59 pm

    Resume: 8:06 pm
    End: 8:32 pm 

we can use the sliding wnow appraoch to solve this problem. as long as the sum is less than s, we add it and extend end. when the sum crosses s, we then take the minlength into consideration,
subtract the beginning eleemnt from the total and move the begining forward. we continue this tillt eh first loop condition is met. after that, we might still have an answer
reamining , so we run another loop until the total is greater than s which would give you an answer if an answer exissted there

Time complexity: O(n)
Space complexity: O(1)
*/
"""

"""
/*
-------------------------    Other Approaches 
1.
    Start: 
    End: 
"""



#  My approaches(1)
def get_minimum(min_length, beg, end, total, arr):
  min_length = min(min_length, end - beg)
  total -= arr[beg]
  beg = beg + 1
  return min_length, total, beg


def get_min_length(arr, s):
  beg, end, total, min_length = 0,0,0, len(arr) +1
  while(beg <= end and end < len(arr)):
    if total < s:
      total += arr[end]
      end = end + 1
    else:
      min_length, total, beg = get_minimum(min_length, beg, end, total, arr)
  
  while total >= s:
    min_length, total, beg = get_minimum(min_length, beg, end, total, arr)

  return 0 if min_length == len(arr)+1 else min_length



def smallest_subarray_sum(s, arr):
  # TODO: Write your code here
  return get_min_length(arr, s)


# Other Approaches(1)
import math


def smallest_subarray_sum(s, arr):
  window_sum = 0
  min_length = math.inf
  window_start = 0

  for window_end in range(0, len(arr)):
    window_sum += arr[window_end]  # add the next element
    # shrink the window as small as possible until the 'window_sum' is smaller than 's'
    while window_sum >= s:
      min_length = min(min_length, window_end - window_start + 1)
      window_sum -= arr[window_start]
      window_start += 1
  if min_length == math.inf:
    return 0
  return min_length


def main():
  print("Smallest subarray length: " + str(smallest_subarray_sum(7, [2, 1, 5, 2, 3, 2])))
  print("Smallest subarray length: " + str(smallest_subarray_sum(7, [2, 1, 5, 2, 8])))
  print("Smallest subarray length: " + str(smallest_subarray_sum(8, [3, 4, 1, 1, 6])))


main()
