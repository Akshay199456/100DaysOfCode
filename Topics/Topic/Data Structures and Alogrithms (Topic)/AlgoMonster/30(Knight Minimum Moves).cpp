/*
Problem statement:

On an infinitely large chessboard, a knight is located on [0, 0].

A knight can move in eight directions.



Given a destination coordinate [x, y], determine the minimum number of moves from [0, 0] to [x, y].
*/

/*
-------------------------    My Approaches:
1. graph -bfs

since we are looking for the minimum moves, we use bfs to solve this problem

    Time complexity: O(v+e)
    Space complexity: O(v+e)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
inutition
    problm asks for minimum moves so bfs is our choice here. the chessboard being infine is totally fine with bfs since we build the graph as we go
    the get_neighbors function now returns cells in 8 directions

    and since the chessboard is infiinite, we no longer have wor worry about bound checking

    Time complexity: O(r*c)
    Space complexity: O()

    computational time is equakl to the size of the gid which is r*c in the worst case. edges in the graph are constant at 8 sinc ht knight can move at most to 8 squares from a given
    cell.
*/



//  My approaches(1)
#include <iostream> // cin, cout, streamsize
#include <limits> // numeric_limits
#include <queue>
#include <utility>
#include <unordered_set>
#include <vector>

struct hashFunction
{
  size_t operator()(const std::pair<int,int> &x) const
  {
    return x.first ^ x.second;
  }
};


std::vector<std::pair<int,int>> getNeighbors(int x, int y){
    std::vector<int> xMove = {-2,-1,1,2,2,1,-1,-2};
    std::vector<int> yMove = {1,2,2,1,-1,-2,-2,-1};
    std::vector<std::pair<int,int>> result;
    
    for(int i=0; i< xMove.size(); i++){
        result.push_back(std::make_pair(x+xMove[i], y+yMove[i]));
    }
    return result;
}

int get_knight_shortest_path(int x, int y) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::queue<std::pair<int,int>> elements;
    std::unordered_set<std::pair<int,int>, hashFunction> visited;
    int nMoves = 0;
    
    elements.push(std::make_pair(0,0));
    visited.emplace(std::make_pair(0,0));
    while(!elements.empty()){
        int nElements = elements.size();
        for(int i=0; i< nElements; i++){
            std::pair<int,int> topElement = elements.front();
            if(topElement.first == x && topElement.second == y)
                return nMoves;
            
            for(std::pair<int,int> neighbor : getNeighbors(topElement.first,topElement.second)){
                if(visited.find(neighbor) == visited.end()){
                    elements.push(neighbor);
                    visited.emplace(neighbor);
                }
            }
            elements.pop();
        }
        ++nMoves;
    }
    
    return nMoves;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int x;
    std::cin >> x;
    ignore_line();
    int y;
    std::cin >> y;
    ignore_line();
    int res = get_knight_shortest_path(x, y);
    std::cout << res << '\n';
}



//  Other Approaches(1)
std::vector<Coordinate> get_neighbors(Coordinate coord) {
    std::vector<Coordinate> neighbors;
    int delta_row[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int delta_col[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    for (int i = 0; i < 8; i++) {
        int neighbor_row = coord.r + delta_row[i];
        int neighbor_col = coord.c + delta_col[i];
        neighbors.emplace_back(Coordinate(neighbor_row, neighbor_col));
    }
    return neighbors;
}

#include <limits> // numeric_limits
#include <queue> // queue
#include <unordered_set> // unordered_set
#include <vector> // vector

struct Coordinate {
    int r;
    int c; 
    Coordinate(int r, int c) : r(r), c(c) {}

    bool operator==(const Coordinate& coord) const {
        return (this->r == coord.r && this->c == coord.c);
    }

    struct HashFunction {
        size_t operator()(const Coordinate& coord) const {
            size_t r_hash = std::hash<int>()(coord.r);
            size_t c_hash = std::hash<int>()(coord.c);
            return r_hash ^ c_hash;
        }
    };
};

std::vector<Coordinate> get_neighbors(Coordinate coord) {
    std::vector<Coordinate> neighbors;
    int delta_row[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int delta_col[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    for (int i = 0; i < 8; i++) {
        int neighbor_row = coord.r + delta_row[i];
        int neighbor_col = coord.c + delta_col[i];
        neighbors.emplace_back(Coordinate(neighbor_row, neighbor_col));
    }
    return neighbors;
}

int bfs(Coordinate start, int x, int y) {
    std::unordered_set<Coordinate, Coordinate::HashFunction> visited;
    visited.emplace(start);
    int steps = 0;
    std::queue<Coordinate> q;
    q.push(start);
    while (q.size() > 0) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Coordinate node = q.front();
            if (node.c == x && node.r == y) return steps;
            std::vector<Coordinate> neighbors = get_neighbors(node);
            for (Coordinate neighbor : neighbors) {
                if (visited.count(neighbor)) continue;
                q.push(neighbor);
                visited.emplace(neighbor);
            }
            q.pop();
        }
        steps++;
    }
    return steps;
}

int get_knight_shortest_path(int x, int y) {
    return bfs(Coordinate(0, 0), x, y);
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int x;
    std::cin >> x;
    ignore_line();
    int y;
    std::cin >> y;
    ignore_line();
    int res = get_knight_shortest_path(x, y);
    std::cout << res << '\n';
}