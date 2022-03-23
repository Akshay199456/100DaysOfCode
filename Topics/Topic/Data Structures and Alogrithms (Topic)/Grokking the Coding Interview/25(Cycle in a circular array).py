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

    Time complexity: O(n^2)
    Space complexity: O(1)
"""


"""
-------------------------    Notes
the fast and slow pointer method is an efficient way to finding a cycle in the array. we can start
from each index of the array to find the cycle. if a number does not have a cycle we will
move forward to the next element. couple of additola things we need to take care of:
  1. cycle should have more than one element. this means that whwen we move a pointer forward
    if the pointer points to the same element after the move, we have a one-element cyucle. therefore, we
    can finish our cycle search for the current element
  2. other requirement is that cycle should not contain both forward and backward movements. 
    will handle this by remembering the direction of each element while searching for the cycle.
    if the number is positive, the direction will be fortward and if the number is negative, the 
    direction will be backward. so whenever we move a pointer forward if thre is a change in 
    the direction, we will finish our cycle search right thre for the current element

Another approach
  in algorithm, we dont keep a record of all the numbers that have been evaludated for ccles.
  we know that all such numbers willnot produce a cycle for any other instace as well.
  if we can remeber all the numbers that have been visited, our algorithm will improve
  to O(n) as then each number will be avaluated for cycles only once. we can keep track of this
  by creating a separate array, however, in this case, the space complexity of our algorithm
  will increase to O(n).

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
def circular_array_loop_exists(arr):
  for i in range(len(arr)):
    is_forward = arr[i] >= 0  # if we are moving forward or not
    slow, fast = i, i

    # if slow or fast becomes '-1' this means we can't find cycle for this number
    while True:
      # move one step for slow pointer
      slow = find_next_index(arr, is_forward, slow)
      # move one step for fast pointer
      fast = find_next_index(arr, is_forward, fast)
      if (fast != -1):
        # move another step for fast pointer
        fast = find_next_index(arr, is_forward, fast)
      if slow == -1 or fast == -1 or slow == fast:
        break

    if slow != -1 and slow == fast:
      return True

  return False


def find_next_index(arr, is_forward, current_index):
  direction = arr[current_index] >= 0

  if is_forward != direction:
    return -1  # change in direction, return -1

  next_index = (current_index + arr[current_index]) % len(arr)

  # one element cycle, return -1
  if next_index == current_index:
    next_index = -1

  return next_index


def main():
  print(circular_array_loop_exists([1, 2, -1, 2, 2]))
  print(circular_array_loop_exists([2, 2, -1, 2]))
  print(circular_array_loop_exists([2, 1, -1, -2]))


main()
