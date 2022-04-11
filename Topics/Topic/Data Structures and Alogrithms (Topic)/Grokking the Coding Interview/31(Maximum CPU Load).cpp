/*
Problem statement:

We are given a list of Jobs. Each job has a Start time, an End time, and a CPU load when it is running. Our goal is to find the maximum CPU load at any time if all the jobs are running on the same machine.

Example 1:

Jobs: [[1,4,3], [2,5,4], [7,9,6]]
Output: 7
Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load (3+4=7) will be when both the 
jobs are running at the same time i.e., during the time interval (2,4).
Example 2:

Jobs: [[6,7,10], [2,4,11], [8,12,15]]
Output: 15
Explanation: None of the jobs overlap, therefore we will take the maximum load of any job which is 15.
Example 3:

Jobs: [[1,4,2], [2,4,1], [3,6,5]]
Output: 8
Explanation: Maximum CPU load will be 8 as all jobs overlap during the time interval [3,4]. 

*/

/*
-------------------------    My Approaches:
1. Merging intervals pattern

    We can apply the mergin intervals patterns to solve this problem. we sort the vector of jobs
    so that they are aligned based on the starting time. once they are sorted, we need to insert
    the time itnervals into the heap. if the current time interval being added coincides
    with the top of th heap, then we know there is an itnersection in time intervals and so
    we need to aadd the load. we update the maxload as well. If thre is no itnersection,
    then we get rid of the rpevious itnerval till the heap is empty or an itnersection is 
    occurred. after that we push the new interval in

    Time complexity: O(nlogn)
    Space complexity: O(n)
*/
/*


-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes

*/



//   My approaches(1)
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int,int,int> tup;

class Job {
 public:
  int start = 0;
  int end = 0;
  int cpuLoad = 0;

  Job(int start, int end, int cpuLoad) {
    this->start = start;
    this->end = end;
    this->cpuLoad = cpuLoad;
  }
};

bool customSort(Job & t1, Job & t2){
  if(t1.start == t2.start)
    return t1.end < t2.end;
  return t1.start < t2.start;
}


bool isIntersecting(tup & heapTop, tup & currTuple){
  if(get<0>(currTuple) >= get<1>(heapTop))
    return false;
  return true;
}


void getMaxLoad(vector<Job> & jobs, int & maxCPULoad){
  sort(jobs.begin(), jobs.end(), customSort);
  priority_queue<tup,vector<tup>,greater<tup>> pq;
  pq.push(make_tuple(jobs[0].start, jobs[0].end, jobs[0].cpuLoad));
  int currLoad = jobs[0].cpuLoad;
  maxCPULoad = currLoad;
  for(int i=1; i<jobs.size(); i++){
    tup currTuple = make_tuple(jobs[i].start, jobs[i].end, jobs[i].cpuLoad);
    tup heapTop = pq.top();
    if(isIntersecting(heapTop, currTuple)){
      pq.push(currTuple);
      currLoad += jobs[i].cpuLoad;
      maxCPULoad = max(maxCPULoad, currLoad);
    }
    else{
      while(!pq.empty() && !isIntersecting(heapTop, currTuple)){
        currLoad -= get<2>(heapTop);
        pq.pop();
      }
      pq.push(currTuple);
      currLoad += get<2>(currTuple);
      maxCPULoad = max(maxCPULoad, currLoad);
    }
  }
}

class MaximumCPULoad {
 public:
  static int findMaxCPULoad(vector<Job> &jobs) {
    int maxCPULoad = 0;
    // TODO: Write your code here
    if(jobs.size())
      getMaxLoad(jobs, maxCPULoad);
    return maxCPULoad;
  }
};

int main(int argc, char *argv[]) {
  vector<Job> input = {{1, 4, 3}, {7, 9, 6}, {2, 5, 4}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{6, 7, 10}, {8, 12, 15}, {2, 4, 11}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{1, 4, 2}, {3, 6, 5}, {2, 4, 1}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{1, 4, 2}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{1, 4, 2}, {8, 9, 1}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

  input = {{1, 4, 2}, {8, 9, 10}};
  cout << "Maximum CPU load at any time: " << MaximumCPULoad::findMaxCPULoad(input) << endl;

}




//  Other Approaches(1)
