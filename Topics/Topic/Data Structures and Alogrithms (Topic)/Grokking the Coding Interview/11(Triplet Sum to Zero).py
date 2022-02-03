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


    Time complexity: O(n^2)
    Space complexity: O()
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
> two otherh approaches can be applied here
> the first is uign three efor loops to iteratre through the unsorted lsit. 
time compledity: O(n^3)
space complexity: O(1)

> the second is usiing a map instead on the unsorted list. we are looking for two eleenmtn that give
us target - arr[num] and we can use the map to keep trakc of the elements we have seen till then.
Time complexity: O(n^2)
Spoace complexity: O(n)
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
