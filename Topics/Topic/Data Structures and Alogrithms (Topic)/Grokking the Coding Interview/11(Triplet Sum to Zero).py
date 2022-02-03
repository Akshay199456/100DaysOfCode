"""
Problem statement:


"""

"""
-------------------------    My Approaches:
1. 
    Start: 7:37 pm
    End: 8:10 pm

    we can use the two poiner approach here. at first, we need to sort the array so the elements are in
    sorted order. we can then take each element and from the rest of the lsit basically apply the two
    pointer technique we applied in pb 7 tog ind the pair whose sum is qual to target - arr[num].

    we will need o(n) space to sort the array.

    Time complexity: O(n^2)
    Space complexity: O(n)
*/
"""

"""
-------------------------    Other Approaches 
1.
    > two otherh approaches can be applied here
> the first is uign three efor loops to iteratre through the unsorted lsit. 
time compledity: O(n^3)
space complexity: O(1)

> the second is usiing a map instead on the unsorted list. we are looking for two eleenmtn that give
us target - arr[num] and we can use the map to keep trakc of the elements we have seen till then.
Time complexity: O(n^2)
Spoace complexity: O(n)
"""


"""
-------------------------    Notes
> follows two pointers pattern and shares similarieties with pair with target sum
> to follow similar approach, we sorty the arrya tnd then inteate through it taking one number
at a time.
> let's say during iteration we are at number 'x', so we need to find 'y' and 'z' such that
x+y+z = 0. at this stage, our pbleme translates into finding a pair whose sum is equal to -x
> to handle unique condition, we have to skip any duplicate number. since we will be sorting the array,
the duplicate numbers will be next to each other and are easier to skip.
"""



#  My approaches(1)
def find_triplets(arr, triplets):
  arr.sort()
  for index in range(len(arr)):
    beg, end, sum_to_find = index+1, len(arr)-1,0 - arr[index]
    while beg < end:
      items = [arr[index], arr[beg], arr[end]]
      if arr[beg] + arr[end] == sum_to_find:
        if not triplets or triplets[-1] != items:
          triplets.append(items)
        end -=1
      elif arr[beg] + arr[end] < sum_to_find:
        beg += 1
      else:
        end -= 1



def search_triplets(arr):
  triplets = []
  # TODO: Write your code here
  find_triplets(arr, triplets)
  return triplets





# Other Approaches(1)
def search_triplets(arr):
  arr.sort()
  triplets = []
  for i in range(len(arr)):
    if i > 0 and arr[i] == arr[i-1]:  # skip same element to avoid duplicate triplets
      continue
    search_pair(arr, -arr[i], i+1, triplets)

  return triplets


def search_pair(arr, target_sum, left, triplets):
  right = len(arr) - 1
  while(left < right):
    current_sum = arr[left] + arr[right]
    if current_sum == target_sum:  # found the triplet
      triplets.append([-target_sum, arr[left], arr[right]])
      left += 1
      right -= 1
      while left < right and arr[left] == arr[left - 1]:
        left += 1  # skip same element to avoid duplicate triplets
      while left < right and arr[right] == arr[right + 1]:
        right -= 1  # skip same element to avoid duplicate triplets
    elif target_sum > current_sum:
      left += 1  # we need a pair with a bigger sum
    else:
      right -= 1  # we need a pair with a smaller sum


def main():
  print(search_triplets([-3, 0, 1, 2, -1, 1, -2]))
  print(search_triplets([-5, 2, -1, -2, 3]))


main()
