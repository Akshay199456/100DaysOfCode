/*
Problem statement:

Given an array of intervals, find the next interval of each interval. In a list of intervals, for an interval i its next interval j will have the smallest ‘start’ greater than or equal to the ‘end’ of i.

Write a function to return an array containing indices of the next interval of each input interval. If there is no next interval of a given interval, return -1. It is given that none of the intervals have the same start point.
*/

/*
-------------------------    My Approaches:
1. 
    tbf, for this problem i did come up with the brute force appraoch, which was to 
    to go through all the intervals for each interval and get ht enext internval. as 
    thought that would a solution that is O(n^2) in terms of complexity and was  a good
    brute force asolution we came up with. i didnt code it but knew that was an approach.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1. 2heaps pattern



    Time complexity: O(nlogn)
    Space complexity: O(n)
*/


/*
-------------------------    Notes
brute foce approach would be to take one interval at a time and go thorugh all the other intervaks
to find the nex interval. algorithm would take O(n^2) where n is the total no
of intervals.

can utilizie the two heaps appraoch. can push all intervals into 2 heaps: one heap to sort 
intervals on max start time(lets call it maxStartHeap) and other max end time (lets call it 
maxEndHeap). can iterate through all intervals of maxEndHeap to find their next interval.
Algoirhtm will ake following steps:)
1. take out the top (having highest end) interval from amxEndHeap to find its nexdt interval.
lets call this interval topEnd
2. find an interval in the maxStartHeap with the closest start greater than or equal to the start
of topEnd. since maxStartHeap is sorted by start of intervals, it is easy to find the 
ionterval with the highest start. lets call this interval topStart.
3. Add the index of topStart in the result array as the next interval of topEnd. if we cant
find the next interval, add -1 to the result array
4. put the topStart back in the maxStartHeap, as it could be the next interval of other
intervals.
5. repeat steps 1-4 until no intervals left in amxEndHeap.
*/



//  My approaches(1)



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

class NextInterval {
 public:
  struct startCompare {
    bool operator()(const pair<Interval, int> &x, const pair<Interval, int> &y) {
      return y.first.start > x.first.start;
    }
  };

  struct endCompare {
    bool operator()(const pair<Interval, int> &x, const pair<Interval, int> &y) {
      return y.first.end > x.first.end;
    }
  };

  static vector<int> findNextInterval(const vector<Interval> &intervals) {
    int n = intervals.size();
    // heap for finding the maximum start
    priority_queue<pair<Interval, int>, vector<pair<Interval, int>>, startCompare> maxStartHeap;
    // heap for finding the minimum end
    priority_queue<pair<Interval, int>, vector<pair<Interval, int>>, endCompare> maxEndHeap;

    vector<int> result(n);
    for (int i = 0; i < intervals.size(); i++) {
      maxStartHeap.push(make_pair(intervals[i], i));
      maxEndHeap.push(make_pair(intervals[i], i));
    }

    // go through all the intervals to find each interval's next interval
    for (int i = 0; i < n; i++) {
      // let's find the next interval of the interval which has the highest 'end'
      auto topEnd = maxEndHeap.top();
      maxEndHeap.pop();

      result[topEnd.second] = -1;  // defaults to -1
      if (maxStartHeap.top().first.start >= topEnd.first.end) {
        auto topStart = maxStartHeap.top();
        maxStartHeap.pop();
        // find the the interval that has the closest 'start'
        while (!maxStartHeap.empty() && maxStartHeap.top().first.start >= topEnd.first.end) {
          topStart = maxStartHeap.top();
          maxStartHeap.pop();
        }
        result[topEnd.second] = topStart.second;
        // put the interval back as it could be the next interval of other intervals
        maxStartHeap.push(topStart);
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> intervals = {{2, 3}, {3, 4}, {5, 6}};
  vector<int> result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
  cout << endl;

  intervals = {{3, 4}, {1, 5}, {4, 6}};
  result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
}
