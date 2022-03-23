"""
Problem statement:

Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.

Example 1:

Intervals: [[1,4], [2,5], [7,9]]
Output: [[1,5], [7,9]]
Explanation: Since the first two intervals [1,4] and [2,5] overlap, we merged them into 
one [1,5].
svg viewer
Example 2:

Intervals: [[6,7], [2,4], [5,9]]
Output: [[2,4], [5,9]]
Explanation: Since the intervals [6,7] and [5,9] overlap, we merged them into one [5,9].

Example 3:

Intervals: [[1,4], [2,6], [3,5]]
Output: [[1,6]]
Explanation: Since all the given intervals overlap, we merged them into one.

"""

"""
-------------------------    My Approaches:
1. using the merge interval technique

    we can use the merge interval technique to solve this problem. if we are to sort the intervals
    based on their start time, it becomees easier to comapre if two intervals are merged
    worthy. if they are, then we combine them else if one interval is withing the other 
    interval, the larger interval remains. when we come across an interval with which
    we dont merge, we push the interval we are hoilding into the new list and continue the 
    same process till the end of the list

    Time complexity: O(n log n) wjere n is the number of intervals
    Space complexity: O(n)
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
from __future__ import print_function


class Interval:
  def __init__(self, start, end):
    self.start = start
    self.end = end

  def print_interval(self):
    print("[" + str(self.start) + ", " + str(self.end) + "]", end='')


def merge_intervals(intervals, merged):
  new_interval = intervals[0]
  for i in range(1, len(intervals)):
    curr_interval = intervals[i]
    if curr_interval.start <= new_interval.end:
      if curr_interval.end > new_interval.end:
        new_interval = Interval(new_interval.start, curr_interval.end)
    else:
      merged.append(new_interval)
      new_interval = intervals[i]
  merged.append(new_interval)

def merge(intervals):
  merged = []
  # TODO: Write your code here
  intervals.sort(key=lambda x: x.start)
  merge_intervals(intervals, merged)
  return merged


def main():
  print("Merged intervals: ", end='')
  for i in merge([Interval(1, 4), Interval(2, 5), Interval(7, 9)]):
    i.print_interval()
  print()

  print("Merged intervals: ", end='')
  for i in merge([Interval(6, 7), Interval(2, 4), Interval(5, 9)]):
    i.print_interval()
  print()

  print("Merged intervals: ", end='')
  for i in merge([Interval(1, 4), Interval(2, 6), Interval(3, 5)]):
    i.print_interval()
  print()

main()


# Other Approaches(1)
