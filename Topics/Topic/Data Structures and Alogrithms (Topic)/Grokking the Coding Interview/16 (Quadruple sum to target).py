"""
Problem statement:

Given an array of unsorted numbers and a target number, find all unique quadruplets in it, whose sum is equal to the target number.

Example 1:

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.
Example 2:

Input: [2, 0, -1, 1, -2, 2], target=2
Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
Explanation: Both the quadruplets add up to the target.
"""

"""
-------------------------    My Approaches:
1. Two pointer approach aftre sortiing th earray
    Start: 8:08
    End: 8:37 pm

    you basically sort the array. once you sort the array, you can use the two pointer approach.
    if we get a result, we push both the pointers else if the sum is less than the target, we 
    push beg forward else we push end backward

    Time complexity: O(n^3)
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
follows the two pointer pattern and shares similarities with triplet sum to zero
can iteratre through the tarrya, taking one number at a time. at every step during the iteratoron,
we will search for the quadruplets similar to truiple summ to zero whose sum is equal to the given target
"""



#  My approaches(1)
def get_result(arr, target):
  quadruplets = []
  arr.sort()
  for i in range(0, len(arr)):
    for j in range(i+1,len(arr)):
      beg, end = j+1, len(arr)-1
      while(end > beg):
        current_sum = arr[i] + arr[j] + arr[beg] + arr[end]
        if current_sum == target:
          quadruplets.append([arr[i],arr[j],arr[beg],arr[end]])
          beg += 1
          end -= 1
        elif current_sum < target:
          beg += 1
        else:
          end -=1
  
  return quadruplets

def search_quadruplets(arr, target):
  # TODO: Write your code here
  return get_result(arr, target)
  



# Other Approaches(1)
def search_quadruplets(arr, target):
  arr.sort()
  quadruplets = []
  for i in range(0, len(arr)-3):
    # skip same element to avoid duplicate quadruplets
    if i > 0 and arr[i] == arr[i - 1]:
      continue
    for j in range(i + 1, len(arr)-2):
      # skip same element to avoid duplicate quadruplets
      if j > i + 1 and arr[j] == arr[j - 1]:
        continue
      search_pairs(arr, target, i, j, quadruplets)
  return quadruplets


def search_pairs(arr, target_sum, first, second, quadruplets):
  left = second + 1
  right = len(arr) - 1
  while (left < right):
    quad_sum = arr[first] + arr[second] + arr[left] + arr[right]
    if quad_sum == target_sum:  # found the quadruplet
      quadruplets.append(
        [arr[first], arr[second], arr[left], arr[right]])
      left += 1
      right -= 1
      while (left < right and arr[left] == arr[left - 1]):
        left += 1  # skip same element to avoid duplicate quadruplets
      while (left < right and arr[right] == arr[right + 1]):
        right -= 1  # skip same element to avoid duplicate quadruplets
    elif quad_sum < target_sum:
      left += 1  # we need a pair with a bigger sum
    else:
      right -= 1  # we need a pair with a smaller sum


def main():
  print(search_quadruplets([4, 1, 2, -1, 1, -3], 1))
  print(search_quadruplets([2, 0, -1, 1, -2, 2], 2))


main()
