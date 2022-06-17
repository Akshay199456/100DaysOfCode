/*
Problem statement:

Given an array of points in a 2D
2D
 plane, find ‘K’ closest points to the origin.

Example 1:

Input: points = [[1,2],[1,3]], K = 1
Output: [[1,2]]
Explanation: The Euclidean distance between (1, 2) and the origin is sqrt(5).
The Euclidean distance between (1, 3) and the origin is sqrt(10).
Since sqrt(5) < sqrt(10), therefore (1, 2) is closer to the origin.
Example 2:

Input: point = [[1, 3], [3, 4], [2, -1]], K = 2
Output: [[1, 3], [2, -1]]

*/

/*
-------------------------    My Approaches:
1. Top k elements

    we can apply the top k elements pattern as it is looking for best k points to origin.
    we make use of max heap and follow the approahc similiar to previous problems.

    Time complexity: O(nlogk)
    Space complexity: O(1)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Point {
 public:
  int x = 0;
  int y = 0;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  int distFromOrigin() const {
    // ignoring sqrt
    return (x * x) + (y * y);
  }

  const bool operator<(const Point& p) { return p.distFromOrigin() > this->distFromOrigin(); }
};

class KClosestPointsToOrigin {
 public:
  static vector<Point> findClosestPoints(const vector<Point>& points, int k) {
    // put first 'k' points in the vector
    vector<Point> maxHeap(points.begin(), points.begin() + k);
    make_heap(maxHeap.begin(), maxHeap.end());

    // go through the remaining points of the input array, if a point is closer to the origin than
    // the top point of the max-heap, remove the top point from heap and add the point from the
    // input array
    for (int i = k; i < points.size(); i++) {
      if (points[i].distFromOrigin() < maxHeap.front().distFromOrigin()) {
        pop_heap(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();
        maxHeap.push_back(points[i]);
        push_heap(maxHeap.begin(), maxHeap.end());
      }
    }

    // the heap has 'k' points closest to the origin
    return maxHeap;
  }
};

int main(int argc, char* argv[]) {
  vector<Point> maxHeap = KClosestPointsToOrigin::findClosestPoints({{1, 3}, {3, 4}, {2, -1}}, 2);
  cout << "Here are the k points closest the origin: ";
  for (auto p : maxHeap) {
    cout << "[" << p.x << " , " << p.y << "] ";
  }
}



//  Other Approaches(1)
