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

*/

/*
-------------------------    Other approaches:

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