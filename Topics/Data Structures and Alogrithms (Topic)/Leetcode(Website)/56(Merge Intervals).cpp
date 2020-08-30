/*
-------------------------Question:
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]
*/

/*
-------------------------My Approaches:
1. Sortign intervals and two pointer approach

If we sketch the problem and try to understand the brute force approach, this is basically a scheduling problem at the end
of the day.Right. Think about it. If you had a bunch of classes, how would you organize your scehdule. You would list
the classes in the order of their start time and fuse them together if they extend each other else skip it if one
is composed within the other. we apply the same strategy here. As a result, it's important to sort the array to have
that ability to fuse intervals together.

We pass in our own comparator to just sort the arrays based on the begin index.

Time complexity: O(nlogn)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {

public:
    static bool comparator(vector<int> interval1, vector<int> interval2){
       return interval1[0] < interval2[0];
    }
    
    void mergeIntervals(vector<vector<int>> intervals, vector<vector<int>> & result){
        int beg = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i< intervals.size(); i++){
            if(intervals[i][0] <= end){
                if(intervals[i][1] > end)
                    end = intervals[i][1];
            }
            else{
                vector<int> list{beg, end};
                result.push_back(list);
                beg = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        vector<int> list{beg, end};
        result.push_back(list);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), comparator);
        mergeIntervals(intervals, result);
        return result;
    }
};