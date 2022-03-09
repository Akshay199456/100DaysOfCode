"""
Problem statement:


"""

"""
-------------------------    My Approaches:
1. fast and slow pointer to detect fccycle

    this problem is composed of multiple smalelr parts. 
    we still use the fast and slow pointer where fast is going through twice the rate of
    slow but we move both as an amount of slow so if slow ever meets with fast, we know
    we are in a cycle as long as the length is greater than 1 and it only moves in one
    direction.
    we come up with an algorithm to detect the next position based on the current position
    and make the necessary checks as needed

    Time complexity: O(n^2)
    Space complexity: O(n)
*/
"""

"""
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
"""


"""
-------------------------    Notes

"""



#  My approaches(1)
def get_next_step(index, no_of_steps, arr_length):
  next_index = index + no_of_steps
  if next_index >= arr_length:
    return (next_index) % arr_length
  elif next_index < 0:
    return arr_length + (next_index % (-1*arr_length))
  else:
    return next_index


def check_cycle(arr, index):
  slow = fast = index
  is_forward = is_backward = False
  elements_visited = set()
  print('Checking cycle')
  while True:
    elements_visited.add(slow)
    if arr[slow] > 0:
      is_forward = True
    if arr[slow] < 0:
      is_backward = True

    fast = get_next_step(fast, 2*arr[slow], len(arr))
    slow = get_next_step(slow, arr[slow], len(arr))
    print('slow: ', slow, ' fast: ', fast)
    
    if (slow == fast and len(elements_visited) > 1) and not (is_forward and is_backward):
      return True
    elif slow in elements_visited:
      return False



def circular_array_loop_exists(arr):
  # TODO: Write your code here
  for index,element in enumerate(arr):
    is_cycle = check_cycle(arr, index)
    if is_cycle:
      return True
  return False

def main():
  print(circular_array_loop_exists([1, 2, -1, 2, 2]))
  print(circular_array_loop_exists([2, 2, -1, 2]))
  print(circular_array_loop_exists([2, 1, -1, -2]))


main()




# Other Approaches(1)
