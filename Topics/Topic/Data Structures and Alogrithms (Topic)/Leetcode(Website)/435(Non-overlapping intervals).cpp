/*
-------------------------Question:

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:

Input: [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:

Input: [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Note:

You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

*/

/*
-------------------------    My Approaches:
1. An approach towards greedy approach.

We got most of this solution right, but seem to skip a few conditions mentioned in Other Approaches(1). While we decided to select the shortest interval(this helped us satisfy the (2) in Other Approaches(1) by finding the difference
of each intervals and selecting the smallest, it made us miss a few conditions.

Time complexity: O(nlogn)
Space complexity: O(1)

*/

/*
-------------------------    Other approaches:
1. Greedy Approach

We can use the greedy apporach here to solve the problem. In my approach, I chose to sort the intervals by the start time but this can also be applied to the end times. Once we have the time intervals sorted by start time. there are a 
few cases that arise. Comparing any two intervals, we have one of three choices:

1. Two intervals dont intersect with each other

If two intervals dont intersect with each other, it's easy. We just need to keep track using the last interval that we saw.

2. Two intervals intersect with each other with the second fully contained within the first

If the second interval is fully contained within the first, then we apply the greedy approach. Here, we want to select the second interval since selecting that interval allows us to slect more non-intersecting intervals int the future.
Also, having the larger first interval meanis that we would be skipping more time intervals. However, since our goal is to minimize the amount of intervals to remove, we want to remove the larger interval.

3. Two intervals intersect with each other with the second only intersecting with part of the first.

Here, we want to remove th esecond interval as that ends the last. Similar to our logic in (2), we want to minmize the number of intervals to remove and this means we get rid of the interval that ends the last as it gives us the 
opportunity to slelect the next interval and thus mroe intervals theerby removing fewer intervals.


Time complexity: O(nlogn)
Space complexity: O(1)
*/

// My Approaches(1)[Not working]
class Solution {
public:
    int minIntervals(vector<vector<int>> intervals){
        int minNumber = 0;
        sort(intervals.begin(), intervals.end());
        int lastStart = intervals[0][0], lastEnd = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < lastEnd){
                minNumber++;
                if((lastEnd - lastStart) > (intervals[i][1] - intervals[i][0])){
                    lastStart = intervals[i][0];
                    lastEnd = intervals[i][1];
                }
            }
            else{
                lastStart = intervals[i][0];
                lastEnd = intervals[i][1];
            }
        }
        
        return minNumber;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        return minIntervals(intervals);
    }
};

// Other Approaches(1)
class Solution {
public:
    int minIntervals(vector<vector<int>> intervals){
        int minNumber = 0;
        sort(intervals.begin(), intervals.end());
        int lastEnd = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < lastEnd){
                minNumber++;
                if(intervals[i][1] <= lastEnd)
                    lastEnd = intervals[i][1];
            }
            else
                lastEnd = intervals[i][1];
        }
        return minNumber;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        return minIntervals(intervals);
    }
};