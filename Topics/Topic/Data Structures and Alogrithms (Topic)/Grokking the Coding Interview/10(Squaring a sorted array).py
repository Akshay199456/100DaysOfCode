"""
Problem statement:


"""

"""
-------------------------    My Approaches:
1. 
    Start: 
    End: 



    Time complexity: O()
    Space complexity: O()
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
def get_square(index,arr):
  return arr[index] * arr[index]

def fill_squares(arr, squares):
  beg, end = 0, len(arr)-1
  while beg <= end:
    beg_squared, end_squared = get_square(beg,arr), get_square(end, arr)
    if beg_squared > end_squared:
      squares.append(beg_squared)
      beg += 1
    else:
      squares.append(end_squared)
      end -= 1
  squares.reverse()

def make_squares(arr):
  squares = []
  # TODO: Write your code here
  fill_squares(arr, squares)
  return squares



# Other Approaches(1)
