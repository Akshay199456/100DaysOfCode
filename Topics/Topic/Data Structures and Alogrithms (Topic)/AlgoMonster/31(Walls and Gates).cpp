/*
Problem statement:

ou are given an m by n grid of integers representing a map of a dungeon. In this map:

-1 represents a wall or an obstacle of some kind.
0 represents a gate out of the dungeon.
INF represents empty space.
For this question, let INF be 2^31 - 1 == 2147483647, which is the max value of the integer type in many programming languages.

Venturing into the dungeon is very dangerous, so you would like to know how close you are at each point in the dungeon to the exit. Given the map of the dungeon, return the same map, but for each empty space, that space is replaced by the number of steps it takes to reach any exit. If a space cannot reach the exit, that space remains INF.

Note that each step, you can move horizontally or vertically, but you cannot move pass a wall or an obstacle.

Input
dungeon_map: a matrix of integer representing the dungeon map.
Output
A matrix of integer representing the dungeon map with the addition of distance to an exit for each empty space.

Examples
Example 1:
Input:

dungeon_map = [
  [INF, -1, 0, INF],
  [INF, INF, INF, -1],
  [INF, -1, INF, -1],
  [0, -1, INF, INF],
]
Output: [ [3, -1, 0, 1], [2, 2, 1, -1], [1, -1, 2, -1], [0, -1, 3, 4], ]

Explanation:

Constraints
1 <= n, m <= 500
*/

/*
-------------------------    My Approaches:
1. 

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
Classic breadth first search problem as it asks for the sitance from each point to some location. simply initialize the queue with a list of gate locations and each cycle , when we process the location at the front of the queue,
we add all the adjacent locations into the queue if their value is INF(meanining it is empty and unprocessed) and amrk the sitances on the cells by adding the value of the current
cell by 1. this way each empty space is only the queue once.

    Time complexity: O()
    Space complexity: O()


Additional notes:

classic breadth first search problem, as it asks for the distance from the gate to some location. here, we want to introduce the concept of
multi-source BFS. we have multiple sources (gates) into the dungeon, there might be multiple ways to reach a location but we want to find the shortest path. at each gate the distance to a gate is 0, so our
level 0 queue will contain all the gates unlike what we have seen before. each step into the dungeon will add one more level to the BFS tree.
if an empty space is marked visited (i.e has non-INFF value) when we arrived there, there must have been a shorter path towards it, so that
we can prune the tree like a normal BFS.

in the implementation, we will simply initialize the queue with a list of fate locations. and during each cycle when we process the location at the front of the queueu, we add all the adjacent locations into the queue if their value
is INF (meaning it is emptu and nprocessed) and mark the distances on the cells by adding the value of the current cell by 1. this way each empty space is only in th queue once.

Time compleixty: O(m*n)
    in the worst case, there are potentially n*m empty spaces in the dungeon as there are at most 4 neighbors to each point, it is at most
    checked 4 times, so the total time complexity is bounded by O(4*(n*m)) which is in O(n*m)

Space complexity: O(n+m)
    worse case space complexity is given by the parameter of the dungeon which is 2(n+m). imagine the entire outer edges are the gates, at each level, there are at most
    2(n+m) spaces. hence we bound the sapce b y O(n+m).

*/



//  My approaches(1)



//  Other Approaches(1)
include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <queue> // queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

struct Coordinate {
    int r;
    int c; 
    Coordinate(int r, int c) : r(r), c(c) {}
};

std::vector<Coordinate> get_neighbors(Coordinate pos, int n, int m) {
    std::vector<Coordinate> neighbors;
    int delta_row[4] = {0, 1, 0, -1};
    int delta_col[4] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
        int neighbor_row = pos.r + delta_row[i];
        int neighbor_col = pos.c + delta_col[i];
        if (0 <= neighbor_row && neighbor_row < n && 0 <= neighbor_col && neighbor_col < m) {
            neighbors.emplace_back(Coordinate(neighbor_row, neighbor_col));
        }
    }
    return neighbors;
}

std::vector<std::vector<int>> map_gate_distances(std::vector<std::vector<int>> dungeon_map) {
    std::queue<Coordinate> q;
    int n = dungeon_map.size(), m = dungeon_map[0].size();
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (dungeon_map[r][c] == 0) {
                q.push(Coordinate(r, c));
            }
        }
    }
    while (q.size() > 0) {
        Coordinate pos = q.front();
        std::vector<Coordinate> neighbors = get_neighbors(pos, n, m);
        for (Coordinate neighbor : neighbors) {
            if (dungeon_map[neighbor.r][neighbor.c] == std::numeric_limits<int>::max()) {
                dungeon_map[neighbor.r][neighbor.c] = 1 + dungeon_map[pos.r][pos.c];
                q.push(neighbor);
            }
        }
        q.pop();
    }
    return dungeon_map;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    int dungeon_map_length;
    std::cin >> dungeon_map_length;
    ignore_line();
    std::vector<std::vector<int>> dungeon_map;
    for (int i = 0; i < dungeon_map_length; i++) {
        dungeon_map.emplace_back(get_words<int>());
    }
    std::vector<std::vector<int>> res = map_gate_distances(dungeon_map);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}