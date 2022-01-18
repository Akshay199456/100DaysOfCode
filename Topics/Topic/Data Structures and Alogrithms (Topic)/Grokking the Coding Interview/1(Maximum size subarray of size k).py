"""

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