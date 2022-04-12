/*
Problem statement:

For ‘K’ employees, we are given a list of intervals representing the working hours of each employee. Our goal is to find out if there is a free interval that is common to all employees. You can assume that each list of employee working hours is sorted on the start time.

Example 1:

Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
Output: [3,5]
Explanation: Both the employees are free between [3,5].
Example 2:

Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
Output: [4,6], [8,9]
Explanation: All employees are free between [4,6] and [8,9].
Example 3:

Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
Output: [5,7]
Explanation: All employees are free between [5,7].
*/

/*
-------------------------    My Approaches:
1. Merging intervals patterns

    to solve this problem, we need to break down the problem into componenets.
    Compoenents:
        1. Merge all components together into proper order
            1. Merge all the intervals together
            2. Sorting the intervals
        2. Merge all intervals that intersect with each other
        3. obtain missing intervals fromt he intervals that merge.
    
    We solve each of these compoenents properly and we solve the problem.

    The way we merged all the intervals together was putting them intoa  enw list and then 
    sorting it. i am sure there is a more effiencet solution than that to do it.
    once the intervals were merged ans sorted, we then merged all the intervals such that
    the intervals that intersected with each other were fused together. as a result, these
    are the collection of all intervals where the employees are busy. in order to find the 
    intervals where they are not busy, we just find the space betweent eh tintervals

    Time complexity: O(kn log kn) if k is the no of employees and n is the no of intervals for each employee
    Space complexity: O(kn)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O(n log k ) where n is the toal no of itnervals and k is the toal no of employees.
    this is becasue we are iterating through the intervals only once (taking O(n) time) and every time we
    process an interval, we remove and can isnert one interval in the min heap (which will take
    O(log K) time. at any time, heap will not have more than k elements
 
    Space complexity: O(k) since heap will not have more than k elemets at a time.
*/


/*
-------------------------    Notes
Follows the merge interval pattern

one simple solutuion would be to put all employees working hours in list and sort them on the start
time. then we can iteratre through the list to find the gaps. sorting th eintervals on the example
gives us:
[1,3], [2,4], [6,8], [9,12]

we can now iterate through these intervals and whenever we find non-overlapping intervals,
eg [2,4] and [6,8], we can calucalte a free interval (eg: [4,6]) this algorithm will
take O(n log n) time where n is the toal nttal no of intervals. this time is needed becasue 
we need to sort alll the iintervals. the speace complexity will be O(n) which ius needded for sorting.
can we find a better solution?

using a heap to sort the intervals

one of the facts we are not utilizing is theat each employee list is indivudally sorted

we can take the first interval of each employee and isnert it into a min heap. this min heap
can always gives us the interval with the smallest start time. once we have the smallest start-time
interval, we can compare it with the next smalelst start-time interval (again from heap) to find
the gap.

whenever we take an interval out of the min heap, we can isnert the same employee's next 
interval. this also means that we need to know which interval belongs to which employee.

*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class EmployeeFreeTime {
 public:
  static void mergeAllIntervals(const vector<vector<Interval>> &schedule, vector<Interval> & allIntervals){
    for(int i=0; i< schedule.size(); i++){
      for(int j=0; j<schedule[i].size(); j++)
        allIntervals.push_back(schedule[i][j]);
    }
  }

  static bool customSort(Interval & i1, Interval & i2){
    if(i1.start == i2.start)
      return i1.end < i2.end;
    return i1.start < i2.start;
  }

  static void sortIntervals(vector<Interval> & allIntervals){
    sort(allIntervals.begin(), allIntervals.end(), customSort);
  }

  static void printIntervals(vector<Interval> & allIntervals){
    for(int i=0; i<allIntervals.size(); i++)
      cout<<"("<<allIntervals[i].start<<","<<allIntervals[i].end<<")";
    cout<<endl;
  }


  static bool isIntersect(Interval & i1, Interval & i2){
    if(i2.start > i1.end)
      return false;
    return true;
  }

  static vector<Interval> intervalsMerge(vector<Interval> & allIntervals){
    Interval mergeInterval = allIntervals[0];
    vector<Interval> result;
    for(int i=1; i< allIntervals.size(); i++){
      Interval currInterval = allIntervals[i];
      if(isIntersect(mergeInterval, currInterval))
        mergeInterval = Interval(mergeInterval.start, currInterval.end);
      else{
        result.push_back(mergeInterval);
        mergeInterval = currInterval;
      }
    }
    result.push_back(mergeInterval);
    return result;
  }

  static vector<Interval> missingIntervals(vector<Interval> & mergedIntervals){
    vector<Interval> result;
    for(int i=1; i< mergedIntervals.size(); i++){
      result.push_back(Interval(mergedIntervals[i-1].end, mergedIntervals[i].start));
    }
    return result;
  }

  static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule) {
    vector<Interval> result;
    vector<Interval> allIntervals;
    // TODO: Write your code here
    mergeAllIntervals(schedule, allIntervals);
    sortIntervals(allIntervals);
    vector<Interval> mergedIntervals = intervalsMerge(allIntervals);
    return missingIntervals(mergedIntervals);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<Interval>> input = {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}};
  vector<Interval> result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
}




//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class EmployeeFreeTime {
 public:
  struct startCompare {
    bool operator()(const pair<Interval, pair<int, int>> &x,
                    const pair<Interval, pair<int, int>> &y) {
      return x.first.start > y.first.start;
    }
  };

  static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule) {
    vector<Interval> result;
    if (schedule.empty()) {
      return result;
    }

    // PriorityQueue to store one interval from each employee
    priority_queue<pair<Interval, pair<int, int>>, vector<pair<Interval, pair<int, int>>>,
                   startCompare>
        minHeap;

    // insert the first interval of each employee to the queue
    for (int i = 0; i < schedule.size(); i++) {
      minHeap.push(make_pair(schedule[i][0], make_pair(i, 0)));
    }

    Interval previousInterval = minHeap.top().first;
    while (!minHeap.empty()) {
      auto queueTop = minHeap.top();
      minHeap.pop();
      // if previousInterval is not overlapping with the next interval, insert a free interval
      if (previousInterval.end < queueTop.first.start) {
        result.push_back({previousInterval.end, queueTop.first.start});
        previousInterval = queueTop.first;
      } else {  // overlapping intervals, update the previousInterval if needed
        if (previousInterval.end < queueTop.first.end) {
          previousInterval = queueTop.first;
        }
      }

      // if there are more intervals available for the same employee, add their next interval
      vector<Interval> employeeSchedule = schedule[queueTop.second.first];
      if (employeeSchedule.size() > queueTop.second.second + 1) {
        minHeap.push(make_pair(employeeSchedule[queueTop.second.second + 1],
                               make_pair(queueTop.second.first, queueTop.second.second + 1)));
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<Interval>> input = {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}};
  vector<Interval> result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
}
