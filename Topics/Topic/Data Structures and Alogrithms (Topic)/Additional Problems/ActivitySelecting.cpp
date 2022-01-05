/*
-------------------------Question:
1. 

You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time.

Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The 
maximum set of activities that can be executed 
is {0, 2} [ These are indexes in start[] and 
finish[] ]

Example 2 : Consider the following 6 activities 
sorted by by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and 
finish[] ]
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Greedy algorithm approach

We can apply the concept of greedy algorithms here in order to solve this problem. To maximize the number of activiites to be performed by the person, we want to make sure to select activiites that finish the quickest in terms of end time.
This allows us to select more activiites which maxoimizes the number of activies. As a result, we sort the activities by the end time so that we can select the activities that end first.

We always select the first activity. This is because by selecting the first activity, we always have a solution that is better than or equal to any other solutioin that might be available since the first activity ends first and hence we 
will have the maximum nubmber of intervals by selecting this activity. If there were any other solution with a interval k that wiould be better, there would be one of two options.

1. there is another interval 1 that intersects with the interval k.
2. there is another interval 1 that doesn't intersect with the interval k.

If there is another interval that intersects, then removing k and adding 1 would maintain the same max number. If there is another interval that doesn't intersect, then including it would give you a higher maxNumber. As a result, choosing
the first interval will always give you an optimal soluition as compared to other intervals.
*/


// Other Approaches(1)
#include <iostream>
#include <vector>

using namespace std;

int getMaxActivities(vector<int> startTimes, vector<int> endTimes){
  int maxNumber = 1, currStart = startTimes[0], currEnd = endTimes[0];
  for(int i=1; i <startTimes.size(); i++){
    if(startTimes[i] >= currEnd)
      currStart = startTimes[i], currEnd = endTimes[i], maxNumber++;
  }
  return maxNumber;
}

int main()
{
  vector<int> startTimes = {10,12,20};
  vector<int> endTimes = {20,25,30};
  int maxNumber = 0;
  if(startTimes.size() != 0)
    maxNumber = getMaxActivities(startTimes, endTimes);
  
  cout<<"Max number: "<<maxNumber<<endl;
  return 0;
}

