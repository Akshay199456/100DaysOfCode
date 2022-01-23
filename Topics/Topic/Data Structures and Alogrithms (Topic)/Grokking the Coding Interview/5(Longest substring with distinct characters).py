"""
Given a string, find the length of the longest substring, which has all distinct characters.
"""

"""
-------------------------    My Approaches:
1. Sliding wndow approach
    Start: 8:35 pm
    End: 9:05 pm

    we can sue the sliding window approach here to solve this problem.
    as long as the elements in the dictionary are unique, we dont have to 
    worry and keep adding new unique elements into it and extendt end. However,
    if we run into an elemnt that already exists in the doctionairy, we will have to 
    remove elements from the beg\inning of the array, till s[end] is no
    longer in the doctionary and for eahc removal, advance beg by 1. 

    Time complexity: O(n)
    Space complexity: O(n)
*/
"""

"""
/*
-------------------------    Other Approaches 
1.
    Start: 
    End: 

    Time complexity: O()
    Space complexity: O()

ollows the liding window pattern. 

Can use a dynamic sliding window approach 

Can use a hashmap to remember the last index of each character we have processes. Whenever we get a duplicate character, we will shrink our sliding window to ensure we always have dstinct character in the sliding window. 

Time complexity 

O(n) 

Space complexity: O(k) where k is the nu,ber of distinct characters in the input string.this also means that k <= n , because in the worst case, the whole string might not have any duplicate character so the entire string will bne added to the hashmpa. Having said that, since we can expect a fixed set of characters in the input string, we can say the algorithm runs in fixed space O(1).. In this case, we can use a fixed size array instead of the hashmap. 

"""



#  My approaches(1)
def get_max_length(s):
  beg, end, max_length = 0,0,0
  frequency_dict = {}
  while end < len(s):
    if s[end] in frequency_dict:
      condn = True
      while (beg < end and condn):
        frequency_dict[s[beg]] -= 1
        if not frequency_dict[s[beg]]:
          del frequency_dict[s[beg]]
        beg += 1

        if s[end] not in frequency_dict:
          condn = False     
    else:
      frequency_dict[s[end]] = 1
      max_length = max(max_length, end - beg + 1)
      end += 1
  return max_length

def non_repeat_substring(s):
  # TODO: Write your code here
  return get_max_length(s)


# Other Approaches(1)
def non_repeat_substring(str1):
  window_start = 0
  max_length = 0
  char_index_map = {}

  # try to extend the range [windowStart, windowEnd]
  for window_end in range(len(str1)):
    right_char = str1[window_end]
    # if the map already contains the 'right_char', shrink the window from the beginning so that
    # we have only one occurrence of 'right_char'
    if right_char in char_index_map:
      # this is tricky; in the current window, we will not have any 'right_char' after its previous index
      # and if 'window_start' is already ahead of the last index of 'right_char', we'll keep 'window_start'
      window_start = max(window_start, char_index_map[right_char] + 1)
    # insert the 'right_char' into the map
    char_index_map[right_char] = window_end
    # remember the maximum length so far
    max_length = max(max_length, window_end - window_start + 1)
  return max_length


def main():
  print("Length of the longest substring: " + str(non_repeat_substring("aabccbb")))
  print("Length of the longest substring: " + str(non_repeat_substring("abbbb")))
  print("Length of the longest substring: " + str(non_repeat_substring("abccde")))