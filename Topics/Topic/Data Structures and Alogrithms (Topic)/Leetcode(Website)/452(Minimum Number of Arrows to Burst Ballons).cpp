/*
-------------------------Question:

There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.

 

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Example 4:

Input: points = [[1,2]]
Output: 1
Example 5:

Input: points = [[2,3],[2,3]]
Output: 1
 

Constraints:

0 <= points.length <= 104
points[i].length == 2
-231 <= xstart < xend <= 231 - 1
*/

/*
-------------------------    My Approaches:
1. Greedy approach

We can apply the greedy approach to solve this problem. If we want to minimize the no of arrows, we should collectively group the ballons such that we minimize the number of arrows shot at the ballons. As a result, we do this by sorting
the ballons so that they are arranged in the order of ballons that end first. Once we have this, we can find which ballons collectively grouped woith each other by finding the merge intervals from each ballon interacting with the 
next ballon. As long as the ballons merge, we just need to spend 1 arrow to shoot throw the multiple ballons. If the intervals don't merge, then we need to use an additional arrow instead to burst through the remaining collection of 
ballons and keep repeating this same procedure.

Time complexity: O(nlogn)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    int getMinArrows(vector<vector<int>> points){
        int mergeStart, mergeEnd;
        int minArrows = 1;
        
        sort(points.begin(), points.end(), [](const auto &p1, const auto &p2){return p1[1] < p2[1];});
        mergeStart = points[0][0], mergeEnd = points[0][1];
        // cout<<"Mergestart: "<<mergeStart<<" mergeEnd: "<<mergeEnd<<endl;
        
        for(int i=1; i<points.size(); i++){
            if(points[i][0] <= mergeEnd){
                mergeStart = max(points[i][0], mergeStart);
                mergeEnd = min(points[i][1], mergeEnd);
                // cout<<"After intersection, Mergestart: "<<mergeStart<<" MergeEnd: "<<mergeEnd<<endl;
            }
            else{
                minArrows++;
                mergeStart = points[i][0];
                mergeEnd = points[i][1];
                // cout<<"New Mergestart: "<<mergeStart<<" Mergeend: "<<mergeEnd<<endl;
            }
        }
        return minArrows;
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() <= 1)
            return points.size();
        return getMinArrows(points);
    }
};