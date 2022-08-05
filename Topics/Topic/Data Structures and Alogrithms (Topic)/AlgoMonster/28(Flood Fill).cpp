/*
Problem statement:

In computer graphics, an uncompressed raster image is presented as a matrix of numbers. Each entry of the matrix represents the color of a pixel. A flood fill algorithm takes a coordinate r, c and a replacement color, and replaces all pixels connected to r, c that have the same color (i.e., the pixels connected to the given coordinate with of same color and all the other pixels connected to the those pixels of the same color) with the replacement color. (e.g. MS-Paint's paint bucket tool).

Input
r: row
c: column
replacement: replacement color
image: an 2D array of integers representing the image
Output
the replaced image

Examples
Example 1:
Input:

r = 2
c = 2
replacement = 9
arr = [[0,1,3,4,1],[3,8,8,3,3],[6,7,8,8,3],[12,2,8,9,1],[12,3,1,3,2]]
Output: [[0,1,3,4,1],[3,9,9,3,3],[6,7,9,9,3],[12,2,9,9,1],[12,3,1,3,2]]
*/

/*
-------------------------    My Approaches:
1. graph - dfs

we can use a dfs technique here so tsolve this problem since we are not lookinf for the shortest path. if we know that at the index satisfies the condition, we look 
through all of its neighbors as well and fill the color as needed

    Time complexity: O(n^2)
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
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void fillMatrix(int r, int c, int identityColor, int replacement, std::vector<std::vector<int>> & image){
    if(r>=0 && r < image.size() && c>=0 && c < image[0].size()){
        if(image[r][c] == identityColor){
            image[r][c] = replacement;
            std::vector<int> rowAdd = {-1,0,1,0};
            std::vector<int> colAdd = {0,1,0,-1};
            for(int i=0; i<rowAdd.size(); i++)
                fillMatrix(r + rowAdd[i], c + colAdd[i], identityColor, replacement, image);
        }
    }
}


std::vector<std::vector<int>> flood_fill(int r, int c, int replacement, std::vector<std::vector<int>> image) {
    // WRITE YOUR BRILLIANT CODE HERE
    if(r>=0 && r < image.size() && c>=0 && c < image[0].size()){
        int identityColor = image[r][c];
        fillMatrix(r,c,identityColor, replacement, image);
    }
    return image;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    int r;
    std::cin >> r;
    ignore_line();
    int c;
    std::cin >> c;
    ignore_line();
    int replacement;
    std::cin >> replacement;
    ignore_line();
    int image_length;
    std::cin >> image_length;
    ignore_line();
    std::vector<std::vector<int>> image;
    for (int i = 0; i < image_length; i++) {
        image.emplace_back(get_words<int>());
    }
    std::vector<std::vector<int>> res = flood_fill(r, c, replacement, image);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}



//  Other Approaches(1)
#include <algorithm> // copy
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

std::vector<Coordinate> get_neighbors(std::vector<std::vector<int>>& image, Coordinate node, int root_color, int num_rows, int num_cols) {
    std::vector<Coordinate> neighbors;
    int delta_row[4] = {-1, 0, 1, 0};
    int delta_col[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int neighbor_row = node.r + delta_row[i];
        int neighbor_col = node.c + delta_col[i];
        if (0 <= neighbor_row && neighbor_row < num_rows && 0 <= neighbor_col && neighbor_col < num_cols) {
            if (image[neighbor_row][neighbor_col] == root_color) {
                neighbors.emplace_back(Coordinate(neighbor_row, neighbor_col));
            }
        }
    }
    return neighbors;
}

void bfs(std::vector<std::vector<int>>& image, Coordinate root, int replacement_color, int num_rows, int num_cols) {
    std::queue<Coordinate> q;
    q.push(root);
    bool visited[num_rows][num_cols] = {{ false }};
    int root_color = image[root.r][root.c];
    image[root.r][root.c] = replacement_color;    // replace root color
    visited[root.r][root.c] = true;
    while (q.size() > 0) {
        Coordinate node = q.front();
        std::vector<Coordinate> neighbors = get_neighbors(image, node, root_color, num_rows, num_cols);
        for (Coordinate neighbor : neighbors) {
            if (visited[neighbor.r][neighbor.c]) continue;
            image[neighbor.r][neighbor.c] = replacement_color;  // replace color
            q.push(neighbor);
            visited[neighbor.r][neighbor.c] = true;
        }
        q.pop();
    }
}

std::vector<std::vector<int>> flood_fill(int r, int c, int replacement, std::vector<std::vector<int>> image) {
    int num_rows = image.size();
    int num_cols = image[0].size();
    bfs(image, Coordinate(r, c), replacement, num_rows, num_cols);
    return image;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    int r;
    std::cin >> r;
    ignore_line();
    int c;
    std::cin >> c;
    ignore_line();
    int replacement;
    std::cin >> replacement;
    ignore_line();
    int image_length;
    std::cin >> image_length;
    ignore_line();
    std::vector<std::vector<int>> image;
    for (int i = 0; i < image_length; i++) {
        image.emplace_back(get_words<int>());
    }
    std::vector<std::vector<int>> res = flood_fill(r, c, replacement, image);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}