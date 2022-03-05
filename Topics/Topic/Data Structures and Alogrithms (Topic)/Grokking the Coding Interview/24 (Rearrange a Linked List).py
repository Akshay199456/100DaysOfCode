"""
Problem statement:

Given the head of a Singly LinkedList, write a method to modify the LinkedList such that the nodes from the second half of the LinkedList are inserted alternately to the nodes from the first half in reverse order. So if the LinkedList has nodes 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, your method should return 1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.

Your algorithm should not use any extra space and the input LinkedList should be modified in-place.

Example 1:

Input: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> null
Output: 2 -> 12 -> 4 -> 10 -> 6 -> 8 -> null 
Example 2:

Input: 2 -> 4 -> 6 -> 8 -> 10 -> null
Output: 2 -> 10 -> 4 -> 8 -> 6 -> null

"""

"""
-------------------------    My Approaches:
1. Fast ald slow pointer

    We use the fast and slow pointer approach to find the middle of the linked list.
    once we find the middle of the linked list, we then reverse the second half of the linked
    list. at this point, the second half of the linked list either ahs the same number
    of elements as the first half or one more. we make slight modifications if it is one more.
    otherwise, we just move the pointers around.

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
Shaes simikaraties with palindrome linked list
follow the the following steps:
    1. can use the fast and slow poitners method similar to middle of linked list to find middle node
    of linked list
    2. once we have middle of linked list, reverse the second half of the linked list
    3, finally, iteratre through first half and reversed second halg to produce a linked
    list in requreied order

"""



#  My approaches(1)
from __future__ import print_function


class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next

  def print_list(self):
    temp = self
    while temp is not None:
      print(str(temp.value) + " ", end='')
      temp = temp.next
    print()


def get_middle_node(head):
  slow = fast = head
  prev_node = slow
  while (fast is not None and fast.next is not None):
    prev_node = slow
    slow = slow.next
    fast = fast.next.next
  
  prev_node.next = None
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


def rearrange_list(head, last_node):
  beg_node = head
  prev_node = last_node
  while beg_node is not None and last_node is not None:
    next_beg = beg_node.next
    next_last = last_node.next
    beg_node.next = last_node
    beg_node = next_beg
    last_node.next = beg_node
    prev_node = last_node
    last_node = next_last

  if last_node is not None:
    prev_node.next = last_node


def reorder(head):
  # TODO: Write your code here
  middle_node = get_middle_node(head)
  last_node = reverse_list(middle_node)
  rearrange_list(head, last_node)
  return head


def main():
  head = Node(1)
  head.next = Node(2)
  head.next.next = Node(3)
  head.next.next.next = Node(4)
  head.next.next.next.next = Node(5)
  head.next.next.next.next.next = Node(6)
  reorder(head)
  head.print_list()


main()




# Other Approaches(1)
from __future__ import print_function


class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next

  def print_list(self):
    temp = self
    while temp is not None:
      print(str(temp.value) + " ", end='')
      temp = temp.next
    print()


def reorder(head):
  if head is None or head.next is None:
    return

  # find middle of the LinkedList
  slow, fast = head, head
  while fast is not None and fast.next is not None:
    slow = slow.next
    fast = fast.next.next

  # slow is now pointing to the middle node
  head_second_half = reverse(slow)  # reverse the second half
  head_first_half = head

  # rearrange to produce the LinkedList in the required order
  while head_first_half is not None and head_second_half is not None:
    temp = head_first_half.next
    head_first_half.next = head_second_half
    head_first_half = temp

    temp = head_second_half.next
    head_second_half.next = head_first_half
    head_second_half = temp

  # set the next of the last node to 'None'
  if head_first_half is not None:
    head_first_half.next = None


def reverse(head):
  prev = None
  while head is not None:
    next = head.next
    head.next = prev
    prev = head
    head = next
  return prev


def main():
  head = Node(2)
  head.next = Node(4)
  head.next.next = Node(6)
  head.next.next.next = Node(8)
  head.next.next.next.next = Node(10)
  head.next.next.next.next.next = Node(12)
  reorder(head)
  head.print_list()


main()

