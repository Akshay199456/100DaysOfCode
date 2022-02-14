"""
Problem statement:


"""

"""
-------------------------    My Approaches:
1. 
    Start: 5:4- pm
    End: 6:14 pm

    we can use the two pointer approach to solve this problem. the wya i have done it is split into 
    2 phaases where you first put the 2 in place and then put the 0 in place. however, these can
    be combined into one step itself as there is nothing stopping it.

    either way the time and speace complexity is the same. you write fewer liones of code with the
    second appraoch

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
brute force solutiion would take O(nlogn)
we can use a two pointer approach while iterating throuh array. the pointers low and high which are pointing
to first and last element of array. while iterating, we will move all 0s before low and all 2s
after high so that in the end, all 1s will be between low and high.
"""



#  My approaches(1)
def sort_array(arr):
  beg, end = 0, len(arr)-1
  # sort out 2s
  while(beg < end):
    if arr[beg] == 2:
      arr[beg], arr[end] = arr[end], arr[beg]
      end -= 1
    else:
      beg += 1
  
  print(arr)

  # sort out 0s
  beg, end = 0, 0
  while end < len(arr):
    if arr[end] == 0:
      arr[beg], arr[end] = arr[end], arr[beg]
      beg += 1
    end += 1
    

def dutch_flag_sort(arr):
  # TODO: Write your code here
  sort_array(arr)
  return arr




# Other Approaches(1)
def dutch_flag_sort(arr):
  # all elements < low are 0, and all elements > high are 2
  # all elements from >= low < i are 1
  low, high = 0, len(arr) - 1
  i = 0
  while(i <= high):
    if arr[i] == 0:
      arr[i], arr[low] = arr[low], arr[i]
      # increment 'i' and 'low'
      i += 1
      low += 1
    elif arr[i] == 1:
      i += 1
    else:  # the case for arr[i] == 2
      arr[i], arr[high] = arr[high], arr[i]
      # decrement 'high' only, after the swap the number at index 'i' could be 0, 1 or 2
      high -= 1


def main():
  arr = [1, 0, 2, 1, 0]
  dutch_flag_sort(arr)
  print(arr)

  arr = [2, 2, 0, 1, 2, 0]
  dutch_flag_sort(arr)
  print(arr)


main()

