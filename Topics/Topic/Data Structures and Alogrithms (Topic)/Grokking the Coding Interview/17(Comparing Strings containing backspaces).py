"""
Problem statement:

Comparing Strings containing Backspaces (medium)#
Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.

Example 1:

Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
Example 2:

Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
Example 3:

Input: str1="xp#", str2="xyz##"
Output: true
Explanation: After applying backspaces the strings become "x" and "x" respectively.
In "xyz##", the first '#' removes the character 'z' and the second '#' removes the character 'y'.
Example 4:

Input: str1="xywrrmp", str2="xywrrmu#p"
Output: true
Explanation: After applying backspaces the strings become "xywrrmp" and "xywrrmp" respectively.

"""

"""
-------------------------    My Approaches:
1. 
    Start: 7:36 pm 
    End: 8:07 pm

    you can use the two poitner technique here to solv this problem. they key is to start the pointers
    fromt he end of the strings. we want to skip characters that are backspaces and those that 
    are omitted becasue fo the backspaces. at this point, we cna then compare the chaccaracters
    and check if they are qequal. if they are, we continue. else we return false

    Time complexity: O(a+b)
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
to compare strings, we need to apply backspaces. an efficient way to do this would be from the end 
of the both of strings. we can have separate pointers, pointing to the last element of the
given strngs. we can then start comparing the characters pointed out by both the pointers
to see if the strings are equal. if, at any stage, the character pointed out by any of the pointers
is a backspace, we will skip and apply the backspace until we have a valid character avaialable for 
comparispon.
"""



#  My approaches(1)
def advance_pointer(string, ptr):
  backspaces, isEnd = 0, False
  while ptr>=0 and not isEnd:
    if(string[ptr] == '#'):
      backspaces += 1
      ptr -= 1
    else:
      if(not backspaces):
        isEnd = True
      else:
        backspaces -= 1
        ptr -= 1
  return ptr

def check_strings_equal(str1, str2):
  ptr1, ptr2 = len(str1)-1, len(str2)-1
  while(ptr1 >=0 and ptr2 >=0):
    ptr1, ptr2 = advance_pointer(str1, ptr1), advance_pointer(str2, ptr2)
    if ptr1 < 0 or ptr2 < 0:
      if ptr1 == ptr2:
        return True
      else:
        return False
    elif str1[ptr1] != str2[ptr2]:
      return False
    else:
      ptr1 -= 1
      ptr2 -= 1

  return ptr1 == ptr2 

def backspace_compare(str1, str2):
  # TODO: Write your code here
  return check_strings_equal(str1, str2)




# Other Approaches(1)
def backspace_compare(str1, str2):
  # use two pointer approach to compare the strings
  index1 = len(str1) - 1
  index2 = len(str2) - 1
  while (index1 >= 0 or index2 >= 0):
    i1 = get_next_valid_char_index(str1, index1)
    i2 = get_next_valid_char_index(str2, index2)
    if i1 < 0 and i2 < 0:  # reached the end of both the strings
      return True
    if i1 < 0 or i2 < 0:  # reached the end of one of the strings
      return False
    if str1[i1] != str2[i2]:  # check if the characters are equal
      return False

    index1 = i1 - 1
    index2 = i2 - 1

  return True


def get_next_valid_char_index(str, index):
  backspace_count = 0
  while (index >= 0):
    if str[index] == '#':  # found a backspace character
      backspace_count += 1
    elif backspace_count > 0:  # a non-backspace character
      backspace_count -= 1
    else:
      break

    index -= 1  # skip a backspace or a valid character

  return index


def main():
  print(backspace_compare("xy#z", "xzz#"))
  print(backspace_compare("xy#z", "xyz#"))
  print(backspace_compare("xp#", "xyz##"))
  print(backspace_compare("xywrrmp", "xywrrmu#p"))


main()
