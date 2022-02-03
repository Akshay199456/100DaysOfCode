"""
Problem statement:


"""

"""
-------------------------    My Approaches:
1. 
    Start: 8:39 pm
    End: 9:11 pm

    we can apply the two pointer approiach here similar to the past couple of problems. the difference
    here though is that you want o keep trak of the difference as you are going alon and use that information
    to find the triplet with the least sum after you have established that its diffrence from the 
    trarget is the least. if it is equal, then the condtion for checking the least sum comes into
    play else we only use the difference from the ttarget sum to make that decision


    Time complexity: O(n^2)
    Space complexity: O(n)
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
def get_triplet_sum(arr, target_sum):
  arr.sort()
  best_sum, min_diff = None,  None
  for index in range(len(arr)):
    beg, end = index + 1, len(arr) - 1
    while beg < end:
      curr_sum = arr[index] + arr[beg] + arr[end]
      if (best_sum is None) or (abs(curr_sum-target_sum) < min_diff) or (abs(curr_sum-target_sum) == min_diff and curr_sum < best_sum):
        best_sum = curr_sum
        min_diff = abs(curr_sum - target_sum)
      
      if curr_sum < target_sum:
        beg += 1
      else:
        end -= 1
  return best_sum


def triplet_sum_close_to_target(arr, target_sum):
  # TODO: Write your code here
  if len(arr) < 3:
    return 0
  return get_triplet_sum(arr, target_sum)




# Other Approaches(1)
