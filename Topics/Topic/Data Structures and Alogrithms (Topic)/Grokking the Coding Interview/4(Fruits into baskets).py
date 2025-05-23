"""
Given an array of characters where each character represents a fruit tree, you are given two baskets, and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.

You can start with any tree, but you can’t skip a tree once you have started. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.

Write a function to return the maximum number of fruits in both baskets.
"""

"""
-------------------------    My Approaches:
1. Sliding window approach
    Start: 7:42 pm
    End: 8:07 pm

    we can use the sliding wndow approach simiar to what was in pb 3.

    Time complexity: O(n)
    Space complexity: O(1)
*/
"""

"""
/*
-------------------------    Other Approaches 
1.
    Start: 
    End: 

    ollwos the sliding window pattern 

Quite similar to longest substring with k distinct character  

Need to find theh length of the longest subarray with no more than 2 distinct character. This transfdorms the current problem into longest substring with k distinct characters where k=2. 
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
def fruits_into_baskets(fruits):
  window_start = 0
  max_length = 0
  fruit_frequency = {}

  # try to extend the range [window_start, window_end]
  for window_end in range(len(fruits)):
    right_fruit = fruits[window_end]
    if right_fruit not in fruit_frequency:
      fruit_frequency[right_fruit] = 0
    fruit_frequency[right_fruit] += 1

    # shrink the sliding window, until we are left with '2' fruits in the fruit frequency dictionary
    while len(fruit_frequency) > 2:
      left_fruit = fruits[window_start]
      fruit_frequency[left_fruit] -= 1
      if fruit_frequency[left_fruit] == 0:
        del fruit_frequency[left_fruit]
      window_start += 1  # shrink the window
    max_length = max(max_length, window_end-window_start + 1)
  return max_length


def main():
  print("Maximum number of fruits: " + str(fruits_into_baskets(['A', 'B', 'C', 'A', 'C'])))
  print("Maximum number of fruits: " + str(fruits_into_baskets(['A', 'B', 'C', 'B', 'B', 'C'])))