"""
Problem statement:

Given an array of unsorted numbers and a target number, find a triplet in the array whose sum is as close to the target number as possible, return the sum of the triplet. If there are more than one such triplet, return the sum of the triplet with the smallest sum.

Example 1:

Input: [-2, 0, 1, 2], target=2
Output: 1
Explanation: The triplet [-2, 1, 2] has the closest sum to the target.
Example 2:

Input: [-3, -1, 1, 2], target=1
Output: 0
Explanation: The triplet [-3, 1, 2] has the closest sum to the target.
Example 3:

Input: [1, 0, 1, 1], target=100
Output: 3
Explanation: The triplet [1, 1, 1] has the closest sum to the target.

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
> solution follows the two pointers pattern aand is quite similar to triplet sum to zero problem.
> similar approach to iterte through the array, taking one number at a time. at every step, we 
will save the difference between the triplet and thr target number so in end, we cna return the triplet
with closest sum.
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
import math


def triplet_sum_close_to_target(arr, target_sum):
  arr.sort()
  smallest_difference = math.inf
  for i in range(len(arr)-2):
    left = i + 1
    right = len(arr) - 1
    while (left < right):
      target_diff = target_sum - arr[i] - arr[left] - arr[right]
      if target_diff == 0:  # we've found a triplet with an exact sum
        return target_sum  # return sum of all the numbers

      # the second part of the following 'if' is to handle the smallest sum when we have more than one solution
      if abs(target_diff) < abs(smallest_difference) or (abs(target_diff) == abs(smallest_difference) and target_diff > smallest_difference):
        smallest_difference = target_diff  # save the closest and the biggest difference

      if target_diff > 0:
        left += 1  # we need a triplet with a bigger sum
      else:
        right -= 1  # we need a triplet with a smaller sum

  return target_sum - smallest_difference


def main():
  print(triplet_sum_close_to_target([-2, 0, 1, 2], 2))
  print(triplet_sum_close_to_target([-3, -1, 1, 2], 1))
  print(triplet_sum_close_to_target([1, 0, 1, 1], 100))


main()
