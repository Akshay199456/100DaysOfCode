"""

"""

"""
-------------------------    My Approaches:
1. Sliding window approach
    Start: 7:42 pm
    End: 8:07 pm

    we can use the sliding wndow approach simiar to what was in pb 3.
*/
"""

"""
/*
-------------------------    Other Approaches 
1.
    Start: 
    End: 
"""



#  My approaches(1)
def get_max_length(fruits):
  beg, end, max_length = 0,0,0
  frequency_map = {}
  while end < len(fruits):
    if fruits[end] in frequency_map:
      frequency_map[fruits[end]] += 1
    else:
      if len(frequency_map) >= 2:
        while len(frequency_map) >= 2:
          frequency_map[fruits[beg]] -= 1
          if not frequency_map[fruits[beg]]:
            del frequency_map[fruits[beg]]
          beg += 1
      
      frequency_map[fruits[end]] = 1
    
    max_length = max(max_length, end-beg+1)
    end += 1
  return max_length

def fruits_into_baskets(fruits):
  # TODO: Write your code here
  return get_max_length(fruits)


# Other Approaches(1)