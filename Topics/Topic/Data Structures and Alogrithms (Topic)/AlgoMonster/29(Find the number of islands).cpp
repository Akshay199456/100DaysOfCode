/*
Problem statement:

iven a 2-dimensional matrix of values with 0 and 1, count the number of islands of 1. An island consists of all value 1 cells and is surrounded by either an edge or all 0 cells. A cell can only be adjacent to each other horizontally or vertically, not diagonally.


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
intuition

    2d matrix is a graph as dicssed in the matrix as graph module. to find  an island, we can do bfs/dfs on a node and 
    expand our serach if the neighboring cell is also 1, like how we fnd cells wth the same colr in flood fill.

    however, since there can be multiple islands we have to do flood fill on every cell. wouldnt that blow up the time ompleixty though? remember that we store the visited cells, and we can skilp cells
    that have already been visisted. so overall, each cell is visited only once

    similar to before, the time complexity is equal to the size of the matrix itself in the worst case. the size of the matrix is denotted by the number of rows times the 
    number of columsn so therefore we have r*c nodes in our graph. the number of edges for a given cell is 4 (ecept boundary cells whole edges are < 4). ad constants are dro[pped in the time
    complexity notiation.


    Time complexity: O(r*c)
    Space complexity: O()


    the matrix istels if a good place to store the information of whetrter a cellk has been visited. we can update the cell that has alreadyy been visited to 
    another number like 2 to denote its been visited. we can even simply update it to 0 sinc eht eisalnd has been recorded and we can consider
    the visited scells simply as wwater.

    while this is acommon solution in coding problems, in the real world you most likely dont want to mutate the function arguments
)*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
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

std::vector<Coordinate> get_neighbors(Coordinate cell, int num_rows, int num_cols) {
    std::vector<Coordinate> neighbors;
    int delta_row[4] = {-1, 0, 1, 0};
    int delta_col[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int neighbor_row = cell.r + delta_row[i];
        int neighbor_col = cell.c + delta_col[i];
        if (0 <= neighbor_row && neighbor_row < num_rows && 0 <= neighbor_col && neighbor_col < num_cols) {
            neighbors.emplace_back(Coordinate(neighbor_row, neighbor_col));
        }
    }
    return neighbors;
}

void bfs(std::vector<std::vector<int>>& grid, Coordinate root, int num_rows, int num_cols) {
    std::queue<Coordinate> q;
    q.push(root);
    grid[root.r][root.c] = 0;
    while (q.size() > 0) {
        Coordinate node = q.front();
        std::vector<Coordinate> neighbors = get_neighbors(node, num_rows, num_cols);
        for (Coordinate neighbor : neighbors) {
            if (grid[neighbor.r][neighbor.c] == 0) continue;
            q.push(neighbor);
            grid[neighbor.r][neighbor.c] = 0;
        }
        q.pop();
    }
}

int count_number_of_islands(std::vector<std::vector<int>> grid) {
    int num_rows = grid.size();
    int num_cols = grid[0].size();
    int count = 0;
    // bfs starting from each unvisited land cell
    for (int r = 0; r < num_rows; r++) {
        for (int c = 0; c < num_cols; c++) {
            if (grid[r][c] == 0) continue;
            bfs(grid, Coordinate(r, c), num_rows, num_cols);
            // bfs would find 1 connected island, increment count
            count++;
        }
    }
    return count;
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

int main() {
    int grid_length;
    std::cin >> grid_length;
    ignore_line();
    std::vector<std::vector<int>> grid;
    for (int i = 0; i < grid_length; i++) {
        grid.emplace_back(get_words<int>());
    }
    int res = count_number_of_islands(grid);
    std::cout << res << '\n';
}