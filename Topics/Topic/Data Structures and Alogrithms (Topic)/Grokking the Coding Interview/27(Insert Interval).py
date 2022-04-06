"""
Problem statement:


"""

"""
-------------------------    My Approaches:
1. 

    Time complexity: O()
    Space complexity: O()
*/
"""

"""
-------------------------    Other Approaches 
1.

    Time complexity: O(n)
    Space complexity: O(1)
"""


"""
-------------------------    Notes
if list was not sorted, could have simply appended the new interval to it and used the merge() 
function from Merge Intervals problem.
However, since list is sorted, should try to come uup with solution better than O(nlogn)
when inserting new interval in sorted list, need to first find the correct index where the 
new interval can be placed. in other words, need to skip all the intervals whicj end before 
the start of the new interval. so can iteratre through the given sorted listed of intervals 
and skip all the intervals with followign condition
    intervals[i].end < newinterval.start

once found the correct place, can follow approach similar to merge intervals problem to inser 
and/or merge new interval.
lets call new interval 'a' and the first interval with the above condition 'b'. there are 
5 possibilities.

to handle all merging scenarios,, can do something like
c.start = min(a.start, b.start)
c.end = max(a.end, b.end)

Overall algorithm would look like:
1. skip all intervals which end before the start of the new interval i.e skip all intervals
with following condition:
    intervals[i].end < newInterval.start

2. lets call the last interval 'b' that does not satisfy above condition. if 'b' overlaps
with new interval (a) (i.e. b.start <= a.end), need to merge them into a new interval 'c':

    c.start = min(a.start, b.start)
    c.end = max(a.end, b.end)

3. repeat above two steps to emrge 'c' with new overlapping itnerval

"""



#  My approaches(1)



# Other Approaches(1)
def insert(intervals, new_interval):
  merged = []
  i, start, end = 0, 0, 1

  # skip (and add to output) all intervals that come before the 'new_interval'
  while i < len(intervals) and intervals[i][end] < new_interval[start]:
    merged.append(intervals[i])
    i += 1

  # merge all intervals that overlap with 'new_interval'
  while i < len(intervals) and intervals[i][start] <= new_interval[end]:
    new_interval[start] = min(intervals[i][start], new_interval[start])
    new_interval[end] = max(intervals[i][end], new_interval[end])
    i += 1

  # insert the new_interval
  merged.append(new_interval)

  # add all the remaining intervals to the output
  while i < len(intervals):
    merged.append(intervals[i])
    i += 1
  return merged


def main():
  print("Intervals after inserting the new interval: " + str(insert([[1, 3], [5, 7], [8, 12]], [4, 6])))
  print("Intervals after inserting the new interval: " + str(insert([[1, 3], [5, 7], [8, 12]], [4, 10])))
  print("Intervals after inserting the new interval: " + str(insert([[2, 3], [5, 7]], [1, 4])))


main()
