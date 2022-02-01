"""
Problem statement:

Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space; after removing the duplicates in-place return the length of the subarray that has no duplicate in it.

Example 1:

Input: [2, 3, 3, 3, 6, 9, 9]
Output: 4
Explanation: The first four elements after removing the duplicates will be [2, 3, 6, 9].
Example 2:

Input: [2, 2, 2, 11]
Output: 2
Explanation: The first two elements after removing the duplicates will be [2, 11].
"""

"""
-------------------------    My Approaches:
1. two pointer apprach
    Start: 8:46 pm
    End: 9:04 pm

    We cans olve this problem usigg the two pointer approach. since our array is sorted and we are looking
    for elements that satisy a condition (duplicate elements), we can apply the two pointer approach rhere.
    as long as the length of the array is more than or equal to 2,we can apply the technique
    by using two poitners. when we see a duplicate, we just push end forwarrds. else if dont
    see a duplicate, we need to increase the length, move beg forward , get a copy of the new element 
    in the new beg place and then push end forward.


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
need to remove duolicates in place
"""



#  My approaches(1)
def get_length(arr):
  beg, end, length = 0, 1, 1
  while end < len(arr):
    if arr[end] != arr[beg]:
      length += 1
      beg += 1
      arr[beg] = arr[end]
    
    end += 1
  return length

def remove_duplicates(arr):
  # TODO: Write your code here
  if len(arr) < 2:
    return len(arr)
  return get_length(arr)



# Other Approaches(1)
def remove_duplicates(arr):
  # index of the next non-duplicate element
  next_non_duplicate = 1

  i = 1
  while(i < len(arr)):
    if arr[next_non_duplicate - 1] != arr[i]:
      arr[next_non_duplicate] = arr[i]
      next_non_duplicate += 1
    i += 1

  return next_non_duplicate


def main():
  print(remove_duplicates([2, 3, 3, 3, 6, 9, 9]))
  print(remove_duplicates([2, 2, 2, 11]))


main()

