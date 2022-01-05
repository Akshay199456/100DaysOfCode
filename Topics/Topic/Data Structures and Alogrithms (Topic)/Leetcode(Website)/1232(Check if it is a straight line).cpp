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
divisions. We use this to obtain our answer. 

inf == inf

However, a note to take here though. The interpretation of Inf,-Inf and Nan might differe from one compiler
to another so this might not always give you the right answer.


Time complexity: O(n)
Space complexity: O(1)
*/

/*
-------------------------Other approaches
1. Using slope in a different way

This approach is very similar to the My approaches(1) as well in that we use the slope to make the decision
of whether two points have the same slope. However, the difference is that, when 3 points are in a stright
line, the slope from them is the same so we can say that:

    (y2 - y1)/(x2-x1) = (y1-y0)/(x1-x0)

            OR

    (y2 - y1) * (x1 - x0) = (x2 - x1) * (y1 - y0)

We use this bottom condition to check if the addition of the new point satisifies the condition. If it does,
we know that they have the same slopes which means they can make a striaght line comprising all those points.


Time complexity: O(n)
Space complexity: O(1)
*/


// My approaches(1)
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double initialSlope = (double)(coordinates[1][1] - coordinates[0][1])/(coordinates[1][0] - coordinates[0][0]);
        // cout<<"Initial slope: "<<initialSlope<<endl;
        for(int i = 2; i < coordinates.size(); i++){
            double slope = (double)(coordinates[i][1] - coordinates[0][1])/(coordinates[i][0] - coordinates[0][0]);
            // cout<<"Slope: "<<slope<<endl;
            if(slope != initialSlope)
                return false;
        }
        return true;
    }
};



// Other Approaches(1)
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2)
            return true;
        else{
            int delY = coordinates[1][1] - coordinates[0][1];
            int delX = coordinates[1][0] - coordinates[0][0];
            for(int i = 2; i < coordinates.size(); i++){
                int diffY = coordinates[i][1] - coordinates[0][1];
                int diffX = coordinates[i][0] - coordinates[0][0];
                
                if(diffY * delX != diffX * delY)
                    return false;
            }
            return true;
        }
        
    }
};