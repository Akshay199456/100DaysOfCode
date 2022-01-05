/*
-------------------------Question:

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
typedef pair<int, vector<int>> customTemplate;

class Solution {
public:
    int getSquaredDistance(vector<int> points){
        return points[0] * points[0] + points[1] * points[1];
    }
    
    vector<vector<int>> getKClosest(vector<vector<int>> points, int K){
        vector<vector<int>> result;
        priority_queue<customTemplate, vector<customTemplate>, greater<customTemplate>> elements;
        /*
        1. for each of the points calculate the distance
            2. store the poionts into a heap
        3. After the loop, retrieve top K from heap
        */
        for(int i=0; i<points.size(); i++){
            int pointDistance = getSquaredDistance(points[i]);
            elements.push(make_pair(pointDistance, points[i]));
        }
        
        for(int i = K; i>0; i--){
            customTemplate currentPair = elements.top();
            result.push_back(currentPair.second);
            elements.pop();
        }
        return result;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        return getKClosest(points, K);
    }
};