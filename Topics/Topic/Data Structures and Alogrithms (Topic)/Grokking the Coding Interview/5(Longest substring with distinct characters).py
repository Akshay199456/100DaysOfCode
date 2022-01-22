"""

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