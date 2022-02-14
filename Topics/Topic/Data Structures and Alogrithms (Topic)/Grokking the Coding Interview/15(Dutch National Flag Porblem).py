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
