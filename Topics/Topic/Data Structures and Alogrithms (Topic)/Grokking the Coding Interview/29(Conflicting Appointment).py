"""
Problem statement:

Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.

Example 1:

Appointments: [[1,4], [2,5], [7,9]]
Output: false
Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.
Example 2:

Appointments: [[6,7], [2,4], [8,12]]
Output: true
Explanation: None of the appointments overlap, therefore a person can attend all of them.
Example 3:

Appointments: [[4,5], [2,3], [3,6]]
Output: false
Explanation: Since [4,5] and [3,6] overlap, a person cannot attend both of these appointments.


"""

"""
-------------------------    My Approaches:
1. Merge intervals pattern

    we cna apply the merge intervals pattern to solve this problem. a person can attend all appointments
    if none of the intervals intersect with each other. so we just need to sort the itnervals
    based on start time and then check if any 2 intervals intersect

    Time complexity: O(nlogn)
    Space complexity: O(n) -> reqired for sorting array
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
problem follows merge intervals pattern. can sort all the intervals by start time and then check if any 2 
intervals overlap. a person will not be able to attend all appointments if any 2 appointments
overlap
"""



#  My approaches(1)
def check_intervals_merge(early_list, late_list):
  start, end = 0,1 
  if(early_list[end] <= late_list[start]):
    return False
  return True


def can_attend(intervals):
  intervals.sort(key=lambda x:x[0])
  for i in range(1, len(intervals)):
    if check_intervals_merge(intervals[i-1], intervals[i]):
      return False
  return True


def can_attend_all_appointments(intervals):
  # TODO: Write your code here
  if len(intervals) < 2:
    return True
  return can_attend(intervals)


def main():
  print("Can attend all appointments: " + str(can_attend_all_appointments([[1, 4], [2, 5], [7, 9]])))
  print("Can attend all appointments: " + str(can_attend_all_appointments([[6, 7], [2, 4], [8, 12]])))
  print("Can attend all appointments: " + str(can_attend_all_appointments([[4, 5], [2, 3], [3, 6]])))


main()



# Other Approaches(1)
def can_attend_all_appointments(intervals):
  intervals.sort(key=lambda x: x[0])
  start, end = 0, 1
  for i in range(1, len(intervals)):
    if intervals[i][start] < intervals[i-1][end]:
      # please note the comparison above, it is "<" and not "<="
      # while merging we needed "<=" comparison, as we will be merging the two
      # intervals having condition "intervals[i][start] == intervals[i - 1][end]" but
      # such intervals don't represent conflicting appointments as one starts right
      # after the other
      return False
  return True


def main():
  print("Can attend all appointments: " + str(can_attend_all_appointments([[1, 4], [2, 5], [7, 9]])))
  print("Can attend all appointments: " + str(can_attend_all_appointments([[6, 7], [2, 4], [8, 12]])))
  print("Can attend all appointments: " + str(can_attend_all_appointments([[4, 5], [2, 3], [3, 6]])))


main()
