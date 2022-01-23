"""
Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’.


"""

"""
-------------------------    My Approaches:
1. using sldiing window technique
    Start: 8:27 pm
    End: 8:59 pm


we can use the sliding window technique as we go through the array to solve theis problem. this way we keep track of the max as we are going along
and increase end end pointer till we hit the end of the array

*/
"""

"""
/*
-------------------------    Other Approaches 
1.

Time complexity: O(n*k) 

A better appraoch 

If you observe closely, you will realize that to calculate the sum of a contiguous subarray, we can utilize the sum of the previous subarray. For this, consider each subarray as a sliding window of size 'k'. To calculate the sum of the next subarray, we need to solde the inwdow ahead by one element. So to slide the window forward and caluclate the sum of the new position of the sliding window, we need to do 2 things: 

Subtract the element going out of the sliding window i.e subtract the first element of the window 

Add the new element getting included in the sliding window i.e the elemnt coming right after the end of the window. 

This apporach will save us from re-calculating the sum of the overlapping part fo the sliding window 


Complexity: 

Time: O(n) 

Space: O(1) 
"""



#  My approaches(1)
def get_max_sum(k, arr):
  total_sum, start, end, max_sum = 0, 0, 0, -1
  while end < len(arr):
    total_sum += arr[end]

    if (end - start == k):
      total_sum -= arr[start]
      start+=1

    if max_sum < total_sum:
        max_sum = total_sum
    end += 1

  return max_sum


def max_sub_array_of_size_k(k, arr):
  # TODO: Write your code here
  if len(arr) < k:
    return -1
  return get_max_sum(k, arr)


# Other Approaches(1)
def max_sub_array_of_size_k(k, arr):
  max_sum = 0
  window_sum = 0

  for i in range(len(arr) - k + 1):
    window_sum = 0
    for j in range(i, i+k):
      window_sum += arr[j]
    max_sum = max(max_sum, window_sum)
  return max_sum


def main():
  print("Maximum sum of a subarray of size K: " + str(max_sub_array_of_size_k(3, [2, 1, 5, 1, 3, 2])))
  print("Maximum sum of a subarray of size K: " + str(max_sub_array_of_size_k(2, [2, 3, 4, 1, 5])))


main()
