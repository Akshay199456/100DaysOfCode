"""
Problem statement:

Given an array arr of unsorted numbers and a target sum, count all triplets in it such that arr[i] + arr[j] + arr[k] < target where i, j, and k are three different indices. Write a function to return the count of such triplets.

Example 1:

Input: [-1, 0, 2, 3], target=3 
Output: 2
Explanation: There are two triplets whose sum is less than the target: [-1, 0, 3], [-1, 0, 2]
Example 2:

Input: [-1, 4, 2, 1, 3], target=5 
Output: 4
Explanation: There are four triplets whose sum is less than the target: 
   [-1, 1, 4], [-1, 1, 3], [-1, 1, 2], [-1, 2, 3]
"""

"""
-------------------------    My Approaches:
1. two pointer approach
    Start: 8:30 pm
    End: 8:57 pm

    we can use the two pointer approach here to solve the problem. we sort the array first.
    we then use the two pointer approach fiing the position of beg and end. if the sum of the 
    3 indices is less than the target, then we know all the number in between beg and end will
    also contribute to the result so w add them up, we then have to move beg forward as there
    culd still be elements from the side of beg that contribute to the result. if at any time
    the sum is greater than the target, we then push end backward as we want to get a smaller
    element which can only be obtained by moving backwards


    Time complexity: O(n^2)
    Space complexity: O(n) fir sorting array
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
follows the two pointer pattern and shares similarities with triplet sum to zero.
only differnece is we need to find triplets that satisfy condition
"""



#  My approaches(1)
def get_count(arr, target):
  arr.sort()
  count = 0
  for index in range(len(arr)):
    beg, end = index+1, len(arr)-1
    while beg < end:
      if arr[index] + arr[beg] + arr[end] < target:
        count += end - beg
        beg += 1
      else:
        end -= 1
  return count

def triplet_with_smaller_sum(arr, target):
  # TODO: Write your code here
  if len(arr) < 3:
    return 0
  return get_count(arr, target)


# Other Approaches(1)
def triplet_with_smaller_sum(arr, target):
  arr.sort()
  count = 0
  for i in range(len(arr)-2):
    count += search_pair(arr, target - arr[i], i)
  return count


def search_pair(arr, target_sum, first):
  count = 0
  left, right = first + 1, len(arr) - 1
  while (left < right):
    if arr[left] + arr[right] < target_sum:  # found the triplet
      # since arr[right] >= arr[left], therefore, we can replace arr[right] by any number between
      # left and right to get a sum less than the target sum
      count += right - left
      left += 1
    else:
      right -= 1  # we need a pair with a smaller sum
  return count


def main():
  print(triplet_with_smaller_sum([-1, 0, 2, 3], 3))
  print(triplet_with_smaller_sum([-1, 4, 2, 1, 3], 5))


main()

