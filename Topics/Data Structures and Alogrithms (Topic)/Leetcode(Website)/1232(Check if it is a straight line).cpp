/*
-------------------------Question:

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

 

Example 1:



Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:



Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

/*
-------------------------My Approaches:
1. Calculating slope

If points are in a straight line, the slope between any two points must be the same since they are in a
straight line. We use this principle to understand if the points make a straight line

A couple of things to note here though. If you are dividing an int by an int, you wil always get an int.
So if you want to get a double value, you have to typecast either the numerator or the denominator.
Second, the double and float class have access to Inf, -Inf and Nan which are used to determine valid
divisions. We use this to obtain our answer. inf == inf

Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

*/


// My approaches(1)
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double initialSlope = (double)(coordinates[1][1] - coordinates[0][1])/(coordinates[1][0] - coordinates[0][0]);
        cout<<"Initial slope: "<<initialSlope<<endl;
        for(int i = 2; i < coordinates.size(); i++){
            double slope = (double)(coordinates[i][1] - coordinates[0][1])/(coordinates[i][0] - coordinates[0][0]);
            cout<<"Slope: "<<slope<<endl;
            if(slope != initialSlope)
                return false;
        }
        return true;
    }
};