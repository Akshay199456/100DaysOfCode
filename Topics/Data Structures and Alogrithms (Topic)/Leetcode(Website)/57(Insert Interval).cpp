/*
-------------------------Question:

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

/*
-------------------------My Approaches:

1. Using the sorted intervals to insert the new interval in multiple runs

Since we know that the intervals are already sorted, we can use that information to insert our interval into the sorted
list. We first find the index where out new interval will be going into the newArray by finding its positions from the 
oldArray. We then use that information to scan with a two pointer approach the extent to which our merge will take place
for intervals on the left and the right of the newInterval from the orgiinal array. Once we have this information, we can
transfer our intervals into the new array as we have covered all the intervals, those that will be merged as well as those
that arent't merged.

Time complexity: O(n)
Space complexity; O(n)
*/

/*
-------------------------Other approaches
1. sing single run to insert the new interval

If we studied our last approach, you would notice thatwe are actually making 3 runs through the array. The first to help
us get the index where this newInterval would be inserted into the new array. The second helps us figure out which intervals
overlap with this new interval given that we have found the index where this new element would be inserted. The third adds
the elements into the new array including the new interval. Since we are running through the array multiple times, this
is a bottleneck that we can improve upon. 

As a result, what we can do is copy all the intervals to the new array that are kess than the new interval and don't 
intersect with it. Since they don't intersect, we know that ehese elements will be in the same position in the new array.
We then merge intervals that intersect and add them to the new array. Finally, we add those elements on the right of the
current interval that don't intersect with the new interval. As a result, we are running through the original array only
once.

Time complexity: O(n)
Space complexity: O(n)
*/

// My Approaches(1)
class Solution {
public:
    int findInsertionIndex(vector<vector<int>> intervals, vector<int> newInterval){
        int insertionIndex = 0;
        bool positionFound = false;
        for(int i = 0 ; i < intervals.size() && !positionFound; i++){
            if(intervals[i][0] <= newInterval[0])
                ++insertionIndex;
            else
                positionFound = true;
        }
        return insertionIndex;
    }
    
    bool isIntervalOverlapping(vector<int> interval1, vector<int> interval2){
        cout<<"Interval 1: "<<interval1[0]<<" "<<interval1[1]<<endl;
        cout<<"Interval 2: "<<interval2[0]<<" "<<interval2[1]<<endl;
        if(interval2[0] >= interval1[0] && interval2[0] <= interval1[1])
            return true;
        return false;
    }
    
    void insertElements(vector<vector<int>> & result, vector<vector<int>> intervals, int beg, int end){
        for(int i = beg; i <= end; i++)
            result.push_back(intervals[i]);
    }
    
    void transferNewArray(vector<vector<int>> intervals, vector<vector<int>> & result, int begIndex, int endIndex, vector<int> newInterval){
        cout<<"New interval: "<<newInterval[0]<<" "<<newInterval[1]<<endl;
        cout<<"Beg index: "<<begIndex<<" End index: "<<endIndex<<endl;
        insertElements(result, intervals, 0,begIndex-1);
        result.push_back(newInterval);
        insertElements(result, intervals, endIndex+1, intervals.size()-1);
    }
    
    void mergeIntervals(vector<vector<int>> intervals, vector<int> newInterval, vector<vector<int>> & result, int insertionIndex){
        bool begFound = false, endFound = false;
        int begIndex = insertionIndex, endIndex = insertionIndex;
        
        // finding the left index till where we extend
        for(int i = insertionIndex-1; i>=0 && !begFound; i--){
            if(isIntervalOverlapping(intervals[i], newInterval)){
                cout<<i<<" Overlaps"<<endl;
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                begIndex--;
            }
            else{
                cout<<i<<" Doesn't"<<endl;
                begFound = true;
            }
        }
        
        // finding the right index till where we extend
        for(int i = insertionIndex; i < intervals.size() && !endFound; i++){
            if(isIntervalOverlapping(newInterval, intervals[i])){
                cout<<i<<" Overlaps"<<endl;
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                endIndex++;
            }
            else{
                cout<<i<<" Doesn't"<<endl;
                endFound = true;
                endIndex--;
            }
        }
        
        transferNewArray(intervals, result, begIndex, endIndex, newInterval);
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int insertionIndex = findInsertionIndex(intervals, newInterval);
        cout<<"Insertion index: "<<insertionIndex<<endl;
        mergeIntervals(intervals, newInterval, result, insertionIndex);
        return result;
    }
};


// Other Approaches(1)
class Solution {
public:
    bool isIntervalOverlapping(vector<int> interval1, vector<int> interval2){
        if((interval2[0] >= interval1[0] && interval2[0] <= interval1[1]) || (interval1[0] >= interval2[0] && interval1[0] <= interval2[1])) 
            return true;
        return false;
    }
    
    
    void mergeIntervals(vector<vector<int>> intervals, vector<int> newInterval, vector<vector<int>> & result){
        int index = 0;
        // copying elements on left of current interval that don't itersect
        while(index < intervals.size() && intervals[index][1] < newInterval[0] && !isIntervalOverlapping(intervals[index], newInterval))
            result.push_back(intervals[index++]);
        
        // merging elements that intersect
        while(index < intervals.size() && isIntervalOverlapping(newInterval, intervals[index])){
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            index++;
        }
        result.push_back(newInterval);
        
        // copying elements on right of current interval that don't intersect
        while(index < intervals.size() && !isIntervalOverlapping(intervals[index], newInterval))
            result.push_back(intervals[index++]);
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        mergeIntervals(intervals, newInterval, result);
        return result;
    }
};