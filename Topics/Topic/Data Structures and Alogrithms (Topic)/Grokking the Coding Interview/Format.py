"""
Problem statement:


"""

"""
-------------------------    My Approaches:
1. Fast and slow pointer approach

    We can use the fast and slow pointer approach to solve this problem. we can use that 
    technique to get the middle node. once we have the middle node, we then reverse the list
    . once reversed, we then compare nodes from the ends of the linked list. before we eoither return
    true or false, we reverse the list again so that it is in the original order


    Time complexity: O(n)
    Space complexity: O(1)
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
if we didivde linked list inot two halves, the node values of the first half in the forward direction
should be similar to the node values of the second half in the backward direction. as we
are given a singly linked list, can't move in backward direction. to handle this:
    1. we can use fast and slow pointers method to find the middle node of the linked l;ist
    once we have middle of linked lis,t we will reverse second half
    then, compare first half with reversed second half to see if the linked list represents
    paldinrome
    finally, we will reverse the second half of the linked lsit again to revert and brin the lnked
    list back to its original form.
"""



#  My approaches(1)
class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next

def get_middle(head):
  slow = fast = head
  while (fast is not None and fast.next is not None):
    slow = slow.next
    fast = fast.next.next
  return slow

def reverse_list(middle_node):
  beg, end = middle_node, middle_node.next
  beg.next = None
  while end is not None:
    next_node = end.next
    end.next = beg
    beg = end
    end = next_node
  return beg


def compare_lists(head, middle_node, last_node):
  beg, end = head, last_node
  while end is not None:
    if beg.value != end.value:
      reverse_list(last_node)
      return False
    
    beg = beg.next
    end = end.next

  reverse_list(last_node)
  return True

def check_palindrome(head):
  middle_node = get_middle(head)
  last_node = reverse_list(middle_node)
  return compare_lists(head, middle_node, last_node)


def is_palindromic_linked_list(head):
  # TODO: Write your code here
  return check_palindrome(head)



def main():
  head = Node(2)
  head.next = Node(4)
  head.next.next = Node(6)
  head.next.next.next = Node(4)
  head.next.next.next.next = Node(2)

  print("Is palindrome: " + str(is_palindromic_linked_list(head)))

  head.next.next.next.next.next = Node(2)
  print("Is palindrome: " + str(is_palindromic_linked_list(head)))


main()










# Other Approaches(1)
class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next


def is_palindromic_linked_list(head):
  if head is None or head.next is None:
    return True

  # find middle of the LinkedList
  slow, fast = head, head
  while (fast is not None and fast.next is not None):
    slow = slow.next
    fast = fast.next.next

  head_second_half = reverse(slow)  # reverse the second half
  # store the head of reversed part to revert back later
  copy_head_second_half = head_second_half

  # compare the first and the second half
  while (head is not None and head_second_half is not None):
    if head.value != head_second_half.value:
      break  # not a palindrome

    head = head.next
    head_second_half = head_second_half.next

  reverse(copy_head_second_half)  # revert the reverse of the second half

  if head is None or head_second_half is None:  # if both halves match
    return True

  return False


def reverse(head):
  prev = None
  while (head is not None):
    next = head.next
    head.next = prev
    prev = head
    head = next
  return prev


def main():
  head = Node(2)
  head.next = Node(4)
  head.next.next = Node(6)
  head.next.next.next = Node(4)
  head.next.next.next.next = Node(2)

  print("Is palindrome: " + str(is_palindromic_linked_list(head)))

  head.next.next.next.next.next = Node(2)
  print("Is palindrome: " + str(is_palindromic_linked_list(head)))


main()
