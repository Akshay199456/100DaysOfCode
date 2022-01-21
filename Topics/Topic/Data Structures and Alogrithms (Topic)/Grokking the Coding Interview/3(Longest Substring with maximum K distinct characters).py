"""

"""

"""
-------------------------    My Approaches:
1. Sliding window problem
    Start: 7:35 p.m
    End: 8:16 pm

we can use the sliding windows approach here to solve this problem. as long as the element does exist in the dicotinary, we can keep adding it. when it doesnt exist in the doctionary
and the length of the ditionary is greater than or equal to k, that measn we need to pop off elements at ht beginnign from the dictionary and move beg forward. otherwise
we move end forward by adding the e,ement as e are going along
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
def get_max_length(str1, k):
  beg, end, max_length = 0, 0, 0
  element_dict = {}

  while end < len(str1):
    if str1[end] in element_dict:
      element_dict[str1[end]] += 1
    else:
      if len(element_dict) >= k:
        while(len(element_dict) >= k):
          element_dict[str1[beg]] -= 1
          if element_dict[str1[beg]] == 0:
            del element_dict[str1[beg]]
          beg += 1
        
      element_dict[str1[end]] = 1

    max_length = max(max_length, end-beg+1)
    end += 1
  return max_length



def longest_substring_with_k_distinct(str1, k):
  # TODO: Write your code here
  return 0 if not (k and len(str1)) else get_max_length(str1,k)


# Other Approaches(1)