"""
Problem statement:

Given two lists of intervals, find the intersection of these two lists. Each list consists of disjoint intervals sorted on their start time.

Example 1:

Input: arr1=[[1, 3], [5, 6], [7, 9]], arr2=[[2, 3], [5, 7]]
Output: [2, 3], [5, 6], [7, 7]
Explanation: The output list contains the common intervals between the two lists.
Example 2:

Input: arr1=[[1, 3], [5, 7], [9, 12]], arr2=[[5, 10]]
Output: [5, 7], [9, 10]
Explanation: The output list contains the common intervals between the two lists.


"""

"""
-------------------------    My Approaches:
1. Merge intervals technique followed by two pointers

    We can apply the merge interval technique here. as shown in the apttern, when two intervals 
    are involved, there are 1 of 6 possibilites for those intervals. As a result, if a ends before
    b , we know they wont intersect and the next best choiuce can be obtained by omoinvg a
    forward as moving b forward will no ways provide oyu with an intersecting point by moving
    a fotrrward might. 
    we do this for when b ends before a as well with only the conditions reversed,
    otherwise the two intervals intersect. and if they intersect, which pointer gets moved
    forward after finding the point of itnersection depends on which interval ends first.
    if both end at the same time, then there is no possoibility for either to isntersect with
    any other next interval from the two lists so we move both the pointers forward for each
    of them.

    Time complexity: O(a+b)
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

"""



#  My approaches(1)
def get_intersection(list_a, list_b, start, end):
  new_list = [list_a, list_b]
  new_list.sort(key=lambda x: x[start])
  return [min(new_list[0][end], new_list[1][start]), min(new_list[0][end], new_list[1][end])]


def merge_intervals(intervals_a, intervals_b, result):
  start, end, ptr_a, ptr_b = 0, 1, 0, 0
  while ptr_a < len(intervals_a) and ptr_b < len(intervals_b):
    if(intervals_a[ptr_a][end] < intervals_b[ptr_b][start]):
      ptr_a += 1
    elif(intervals_b[ptr_b][end] < intervals_a[ptr_a][start]):
      ptr_b += 1
    else:
      intersect_list = get_intersection(intervals_a[ptr_a], intervals_b[ptr_b], start, end)
      result.append(intersect_list)
      if(intervals_a[ptr_a][end] < intervals_b[ptr_b][end]):
        ptr_a += 1
      elif(intervals_b[ptr_b][end] < intervals_a[ptr_a][end]):
        ptr_b += 1
      else:
        ptr_a += 1
        ptr_b += 1

def merge(intervals_a, intervals_b):
  result = []
  # TODO: Write your code here
  if intervals_a and intervals_b:
    merge_intervals(intervals_a, intervals_b, result)
  return result


def main():
  print("Intervals Intersection: " + str(merge([[1, 3], [5, 6], [7, 9]], [[2, 3], [5, 7]])))
  print("Intervals Intersection: " + str(merge([[1, 3], [5, 7], [9, 12]], [[5, 10]])))
  print("Intervals Intersection: " + str(merge([[1, 3], [5, 7], [9, 12]], [[13, 14]])))
  print("Intervals Intersection: " + str(merge([[1, 3], [5, 7], [9, 12]], [[5, 7]])))


main()




# Other Approaches(1)
