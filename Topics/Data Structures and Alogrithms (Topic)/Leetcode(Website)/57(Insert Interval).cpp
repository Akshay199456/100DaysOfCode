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

*/

/*
-------------------------Other approaches

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