"""
Problem statement:

iven an array with positive numbers and a positive target number, find all of its contiguous subarrays whose product is less than the target number.

Example 1:

Input: [2, 5, 3, 10], target=30 
Output: [2], [5], [2, 5], [3], [5, 3], [10]
Explanation: There are six contiguous subarrays whose product is less than the target.
Example 2:

Input: [8, 2, 6, 5], target=50 
Output: [8], [2], [8, 2], [6], [2, 6], [5], [6, 5] 
Explanation: There are seven contiguous subarrays whose product is less than the target.

"""

"""
-------------------------    My Approaches:
1. 
    Start: 8:43 pm
    End: 

    we can use the two pointer approach here inspite of the list not being sorted. at tach iteration,
    we check iof the prodcut times arr[end] is greater than the traget. if it si not, then
    we can extend the end pointer as we can still expand. we add this to our prod and then 
    extend end. if it is greater than the target, we must then greentate all sublists of the list
, get rid of the arr[beg] from the prod and push beg forward.

    at th very end, we want to get the remaining elements that might have eben missted as a result
    of end hitting the max value while beg still exsitign.

    to be noted here is that lists are mutable, so when you add to a list, it modifeis the list.
    even if you have assigned once to a list after each iteration of the loop,. it seems to get called only 
    once for the whole program.

    Time complexity: O(n^3)
    Space complexity: O(n^2)
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
problem follows sliding window and the two pointes pattern and shares similariteis with triplets
with samller small with two differences:
        input array is not sorted
        instead of dinding triplets with sum less than a target, we need to find all subarrays having
        a product less than the target
"""



#  My approaches(1)
def generate_subarrays(start, end, result, arr, all_tuples_set):
    for i in range(start, end+1):
        for j in range(i+1, end+1):
            temp_list = arr[i:j]
            if tuple(temp_list) not in all_tuples_set:
                result.append(temp_list)
                all_tuples_set.add(tuple(temp_list))


def get_all_subarrays(arr, target, result):
    beg, end, prod = 0, 0, 1
    all_tuples_set = set()
    while end < len(arr):
        if prod * arr[end] < target:
            prod *= arr[end]
            end += 1
        else:
            generate_subarrays(beg, end, result, arr, all_tuples_set)
            prod /= arr[beg]
            beg += 1
    generate_subarrays(beg,end, result, arr, all_tuples_set)

def find_subarrays(arr, target):
    result = []
    if len(arr) > 0:
        get_all_subarrays(arr, target, result)
    return result




# Other Approaches(1)
from collections import deque


def find_subarrays(arr, target):
  result = []
  product = 1
  left = 0
  for right in range(len(arr)):
    product *= arr[right]
    while (product >= target and left < len(arr)):
      product /= arr[left]
      left += 1
    # since the product of all numbers from left to right is less than the target therefore,
    # all subarrays from left to right will have a product less than the target too; to avoid
    # duplicates, we will start with a subarray containing only arr[right] and then extend it
    temp_list = deque()
    for i in range(right, left-1, -1):
      temp_list.appendleft(arr[i])
      result.append(list(temp_list))
  return result


def main():
  print(find_subarrays([2, 5, 3, 10], 30))
  print(find_subarrays([8, 2, 6, 5], 50))


main()
