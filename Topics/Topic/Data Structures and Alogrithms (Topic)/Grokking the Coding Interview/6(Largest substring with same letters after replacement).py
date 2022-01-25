"""
Problem statement:


"""

"""
-------------------------    My Approaches:
1. 
    Start: 
    End: 



    Time complexity: O()
    Space complexity: O()
*/
"""

"""
-------------------------    Other Approaches 
1.
    Start: 
    End: 

    

    Time complexity: O(n)
    Space complexity: O(1)

    This problem uses the sliding window approach. the key to understand this problem is that
    we can only replace k letters in our string. since that is the case, we must keep track of the 
    most frequenct character in the string that we have encountered. as long as the length of the string
    and the max frequenct character is less than or equal to k, then we can make the necessary
    minimum replacements and the max length increases. we want to keep track of the count of the 
    most frequenct chacaracter becasue having knowledge of that allows us to maximize tha bility to replace as few
    characters as possible by replacing hte remaining character and aslso sicne we are trying to find
    the largest ubstring which will invovle repklacing the least number in order to maximize the
    length. 
    
    when this difference exceeds k, we know that that substring will no longer be a good solution
    and we will not be able to only spend k characters to get the max substring length since
    the number of ahcraters to replace s greater than k. as a result, the best solution for us in this case will
    be to instead reduce the string as if we were to continnue with that string, wwe would only be 
    in a worse off position as the number of characters would only increase. by reducing the window
    and thebery moving left forward, we give us the ability to find another solution that might
    be a bette solution to the one we have.

"""


"""
-------------------------    Notes

"""



#  My approaches(1)



# Other Approaches(1)
def get_index(letter):
  return ord(letter) - ord('a')

def get_max_length(string, k):
  left, right, max_length, max_freq_letter = 0, 0, 0, 0
  freq_count = [0] * 26
  for right in range(len(string)):
    freq_count[get_index(string[right])] += 1
    max_freq_letter = max(max_freq_letter, freq_count[get_index(string[right])])

    if right - left + 1 - max_freq_letter > k:
      freq_count[get_index(string[left])] -= 1
      left += 1
    
    max_length = max(max_length, right - left + 1)

  return max_length


def length_of_longest_substring(string, k):
  # TODO: Write your code here
  return get_max_length(string, k)



# Other Approaches(2)
def length_of_longest_substring(str1, k):
  window_start, max_length, max_repeat_letter_count = 0, 0, 0
  frequency_map = {}

  # Try to extend the range [window_start, window_end]
  for window_end in range(len(str1)):
    right_char = str1[window_end]
    if right_char not in frequency_map:
      frequency_map[right_char] = 0
    frequency_map[right_char] += 1
    max_repeat_letter_count = max(
      max_repeat_letter_count, frequency_map[right_char])

    # Current window size is from window_start to window_end, overall we have a letter which is
    # repeating 'max_repeat_letter_count' times, this means we can have a window which has one letter
    # repeating 'max_repeat_letter_count' times and the remaining letters we should replace.
    # if the remaining letters are more than 'k', it is the time to shrink the window as we
    # are not allowed to replace more than 'k' letters
    if (window_end - window_start + 1 - max_repeat_letter_count) > k:
      left_char = str1[window_start]
      frequency_map[left_char] -= 1
      window_start += 1

    max_length = max(max_length, window_end - window_start + 1)
  return max_length


def main():
  print(length_of_longest_substring("aabccbb", 2))
  print(length_of_longest_substring("abbcb", 1))
  print(length_of_longest_substring("abccde", 1))


main()

