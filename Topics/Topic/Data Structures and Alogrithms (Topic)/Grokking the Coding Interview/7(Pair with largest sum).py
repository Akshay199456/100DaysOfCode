"""
Problem statement:

Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.

Example 1:

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6
Example 2:

Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11

"""

"""
-------------------------    My Approaches:
1. two popinter approach
    Start: 8:06 pm
    End: 8:21 pm

    we can use the two pointer qpproach here as it applies to this problem. we are givena  sorted array
    and we are trying to look for elements that statisfy some contraint.
    keping thw two pinter,s one at the beginning and the other at the end, we checl if our sum
    meets the target_sum/ if so, we returnt he indexes as the result. else if our sum is less than target sum
    then we need to move the beg pointer forward as that gives us the ability to increase the sum.
    else vice versa and we nmove he end pointer backward.


    Time complexity: O(n)
    Space complexity: O(1)
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
> since array is sorted, a brute force approach could be to iteratre through array, taking one number
at a time and searching for the second number through binary search. time complexity will be
O(nlogn.)
> to do better, we can follow the two poointer appraoch



> An alternate approach

instead of using a two pinter ir a binary search approach,. cna utilize a hastable to search for rquired
pair. cann interatre through the array one number at t a time.. let's say during our iteration
we are at number 'x', so we need to find y such that x+y == target. we will do things here:
    1. search for y (which is equivalent to target - x) in hashtable. if it is there, we have found the required pari
    2. otherwise, insert x in the hashtable so that we cans each it for the alter nbumbers

Time complexity: O(n)
Space complexity: O(n)
"""



#  My approaches(1)
def get_pair_index(arr, target_sum):
  beg, end = 0, len(arr) - 1
  
  while (beg <= end):
    total_sum = arr[beg] + arr[end]
    if total_sum == target_sum:
      return [beg,end]
    elif total_sum > target_sum:
      end -= 1
    else:
      beg += 1

  return [-1,-1]

def pair_with_targetsum(arr, target_sum):
  # TODO: Write your code here
  return get_pair_index(arr, target_sum)




# Other Approaches(1)
def pair_with_targetsum(arr, target_sum):
  left, right = 0, len(arr) - 1
  while(left < right):
    current_sum = arr[left] + arr[right]
    if current_sum == target_sum:
      return [left, right]

    if target_sum > current_sum:
      left += 1  # we need a pair with a bigger sum
    else:
      right -= 1  # we need a pair with a smaller sum
  return [-1, -1]


def main():
  print(pair_with_targetsum([1, 2, 3, 4, 6], 6))
  print(pair_with_targetsum([2, 5, 9, 11], 11))


main()


# Other Appraoches(2)
def pair_with_targetsum(arr, target_sum):
  nums = {}  # to store numbers and their indices
  for i, num in enumerate(arr):
    if target_sum - num in nums:
      return [nums[target_sum - num], i]
    else:
      nums[arr[i]] = i
  return [-1, -1]


def main():
  print(pair_with_targetsum([1, 2, 3, 4, 6], 6))
  print(pair_with_targetsum([2, 5, 9, 11], 11))


main()
