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


    Time complexity: O()
    Space complexity: O()
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
