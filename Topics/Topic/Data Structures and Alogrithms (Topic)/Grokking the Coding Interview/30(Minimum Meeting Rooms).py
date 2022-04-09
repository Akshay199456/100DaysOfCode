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
Meetings: [[4,5], [2,3], [2,4], [3,5]]

Step 1: sorting the meetings on start time will give: [[2,3], [2,4], [3,5], [4,5]]

Step 2: merging overlapping meetings:
    2,3] overlaps with [2,4], so after merging we’ll have => [[2,4], [3,5], [4,5]]
[2,4] overlaps with [3,5], so after merging we’ll have => [[2,5], [4,5]]
[2,5] overlaps [4,5], so after merging we’ll have => [2,5]

since all the meetings have emrged into one big emeting ([2,5]) does this mean that they all are overlapping
and we need a minimum of 4 rooms to hold these meetings. the answer is no.

Some emeetings are muttually exclusisve. for example [2,3] and [3,5] don't overlap and can happen
in one room. as a result, we need to keep trackl of the mutual exclusiveness of the overalpping meetings.


Our strategy will look like this:
1. sort the meeting sbased on start time
2. scheudle the frist meeting (lets call it m1) in one room (lets call it r1)
3. if the next meeting m2 is not overlapping with m1, we can safely schedule t int eh same room r1.
4. if the next meeting me is overlapping with m2, we cant use r1, so we will scheudle it in 
another room (lets calll it r2)
5. now if next meeting m4 is overla[[ing with m3, we need to see if the room r1 has become free.
for this,, we need to keep track of the end time of the meeting happening in it. if the end time 
of m2 is before the start time of m4m we can use that room r1, oteherwisem we ned to reschedule 
m4 in another room r3.

as a result, we need to keep track of the ending time of all the meetinfs currently happening
so that when we try to schedule a new meeting, we can see what meetings have already ended. we need
to put this information in a data strcuture that can easily give us the smallest ending time.
a min heap would fit our requirements best

so the algorithm would look like:
1. sort all meetings on start time
2. create a min heap to store all active meetings. this min heap will also be sued to find the 
active emeting with the smallest end time
3. iteratre through all th eemetings one by one to add them in the min heap. lets say we are truong
to schedule the emeeting m1
4. since the min heap contains all the active meetings, so before scheduling m1, we can remove 
all meetings from the heap that have ended before m1 i.e remove all meetings fromt he heap
that have an edn time smaller than or requal to the start time of m1
4. no add m1 to the heap
6. the hea[ will always have all the overlapping meetings so we will need rooms for all of them.
keep a counter to remember the maximum size of th eheap at any time which will be the 
minimum number of rooms needed.
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
from heapq import *


class Meeting:
  def __init__(self, start, end):
    self.start = start
    self.end = end

  def __lt__(self, other):
    # min heap based on meeting.end
    return self.end < other.end


def min_meeting_rooms(meetings):
  # sort the meetings by start time
  meetings.sort(key=lambda x: x.start)

  minRooms = 0
  minHeap = []
  for meeting in meetings:
    # remove all the meetings that have ended
    while(len(minHeap) > 0 and meeting.start >= minHeap[0].end):
      heappop(minHeap)
    # add the current meeting into min_heap
    heappush(minHeap, meeting)
    # all active meetings are in the min_heap, so we need rooms for all of them.
    minRooms = max(minRooms, len(minHeap))
  return minRooms


def main():
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(1, 4), Meeting(2, 5), Meeting(7, 9)])))
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(6, 7), Meeting(2, 4), Meeting(8, 12)])))
  print("Minimum meeting rooms required: " +
        str(min_meeting_rooms([Meeting(1, 4), Meeting(2, 3), Meeting(3, 6)])))
  print("Minimum meeting rooms required: " + str(min_meeting_rooms(
    [Meeting(4, 5), Meeting(2, 3), Meeting(2, 4), Meeting(3, 5)])))


main()
