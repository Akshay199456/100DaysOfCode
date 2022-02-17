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
