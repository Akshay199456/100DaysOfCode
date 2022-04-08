"""
Problem statement:

Given a list of intervals representing the start and end time of ‘N’ meetings, find the minimum number of rooms required to hold all the meetings.

Example 1:

Meetings: [[1,4], [2,5], [7,9]]
Output: 2
Explanation: Since [1,4] and [2,5] overlap, we need two rooms to hold these two meetings. [7,9] can 
occur in any of the two rooms later.
Example 2:

Meetings: [[6,7], [2,4], [8,12]]
Output: 1
Explanation: None of the meetings overlap, therefore we only need one room to hold all meetings.
Example 3:

Meetings: [[1,4], [2,3], [3,6]]
Output:2
Explanation: Since [1,4] overlaps with the other two meetings [2,3] and [3,6], we need two rooms to 
hold all the meetings.

Example 4:

Meetings: [[4,5], [2,3], [2,4], [3,5]]
Output: 2
Explanation: We will need one room for [2,3] and [3,5], and another room for [2,4] and [4,5].

Here is a visual representation of Example 4:
"""

"""
-------------------------    My Approaches:
1. Meeting intervals pattern along with using heap

    we can use the meeting intervals pattern here to solve the problem. sort the intervals based 
    on start time. in oredr to track the number of items, we basically need to track which rooms
    are aravaialble and which are not and that is why we sort the intervals. once sorted, we 
    add the intervals one by one into a heap.when adding, if the interval at the top of heap intersects
    witht eh current interval, then we need to take another room since two intervals are colliding. similarly when  we are
    adding a new interval and it does not collide with the top of the heap,, that means we no
    longer need that room that is being used so we continue to pop from the heap until we find an interval that collides or the heap is empty. 
    we then add the current interval

    Time complexity: O(nlogn)
    Space complexity: O(n) for sorting the array
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
from heapq import *


class Meeting:
  def __init__(self, start, end):
    self.start = start
    self.end = end


def check_intersection(meeting_early, meeting_late):
  if meeting_early[0] <= meeting_late[1]:
    return False
  return True


def get_min_rooms(meetings):
  meetings.sort(key=lambda x:x.start)
  count, max_count, pq = 1, 1, [(meetings[0].end, meetings[0].start)]
  # print('pq is: ')
  # print_meeting(pq)

  for i in range(1, len(meetings)):
    if check_intersection(pq[0], (meetings[i].end, meetings[i].start)):
      heappush(pq, (meetings[i].end, meetings[i].start))
      count += 1
      max_count = max(count, max_count)
    else:
      while pq and not check_intersection(pq[0], (meetings[i].end, meetings[i].start)):
        heappop(pq)
        count -= 1
      heappush(pq, (meetings[i].end, meetings[i].start))
  return max_count


def min_meeting_rooms(meetings):
  # TODO: Write your code here
  if len(meetings) < 2:
    return len(meetings)
  return get_min_rooms(meetings)


def main():
  print("Minimum meeting rooms required: " + str(min_meeting_rooms(
    [Meeting(4, 5), Meeting(2, 3), Meeting(2, 4), Meeting(3, 5)])))
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(1, 4), Meeting(2, 5), Meeting(7, 9)])))
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(6, 7), Meeting(2, 4), Meeting(8, 12)])))
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(1, 4), Meeting(2, 3), Meeting(3, 6)])))
  print("Minimum meeting rooms required: " + str(min_meeting_rooms(
    [])))
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(1, 4)])))
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(1, 4), Meeting(2, 3)])))
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(1, 4), Meeting(4, 8)])))
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(1, 4), Meeting(5,6)])))

main()




# Other Approaches(1)
