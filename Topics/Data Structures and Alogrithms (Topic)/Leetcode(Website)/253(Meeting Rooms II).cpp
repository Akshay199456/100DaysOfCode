/*
-------------------------Question:

*/

/*
-------------------------    My Approaches:
1. Using prioirty queue and storing real time state of the rooms

We can use this appraoch to hold the real time state of the rooms that are being occupied. In the min heap, we store info on the end times of the different rooms. If for our next interval, we have the beginning time greater than the end
time at the top of the min heap, we keep popping till either the heap is empty orwe have found an end time that we collide with. We then add the end time for the current interval into the min heap.

Time complexity: O(n^2 logn)
Space complexity: O(n)

*/

/*
-------------------------    Other approaches:
1. Using priority queue to store max rooms that have been occupied. Doesn't store real time state of rooms

Same as My Approaches(1) but here we don't store real time state of the intervals. If at any time, we have an interval that starts after the end time of the interval at the top, we pop the top off and insert the end time for the 
current interval. This way, we are only popping when we need to and the size of the heap stores info on the max number of roooms reuired.

Time complexity: O(nlogn)
Space complexity: O(n)
*/


// My Approaches(1)
class Solution {
public:
    int findMinimumRooms(vector<vector<int>> & intervals){
        int minRooms = 1;
        priority_queue<int, vector<int>, greater<int>> heap;
        heap.push(intervals[0][1]);
        
        for(int i=1; i< intervals.size(); i++){
            while(!heap.empty() && intervals[i][0] >= heap.top())
                heap.pop();
            
            heap.push(intervals[i][1]);
            minRooms = max(minRooms, (int) heap.size());
        }
        return minRooms;
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), ([](const auto &a, const auto &b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        }));
        
        return findMinimumRooms(intervals);
    }
};

// Other approaches(1)
class Solution {
public:
    int findMinimumRooms(vector<vector<int>> & intervals){
        priority_queue<int, vector<int>, greater<int>> heap;
        
        heap.push(intervals[0][1]);
        for(int i=1; i< intervals.size(); i++){
            if(intervals[i][0] >= heap.top())
                heap.pop();
            
            heap.push(intervals[i][1]);
        }
        return heap.size();
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), ([](const auto &a, const auto &b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        }));
        
        return findMinimumRooms(intervals);
    }
};