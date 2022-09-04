/*
Problem statement:

ou happen upon a puzzle box that unlocks... Something. You aren't quite sure what just yet. The puzzle is a 2 x 3 box, and there are 5 square sliding bricks labelled conveniently with 1 to 5. It looks something like this:



It can be represented as a 2 x 3 matrix containing numbers from 0 to 5, where 0 represents an empty space. For example, the pattern above can be represented by [[4, 1, 3], [2, 0, 5]].

The tiles are interlocked with each other, so you cannot take the tiles out. However, the tiles can move freely horizontally and vertically, so each turn, you can move a tile to an adjacent empty space. You have a feeling that when you move the tiles to the position [[1, 2, 3], [4, 5, 0]], the puzzle will be solved and unlock the "something". Like this:



You need to be quick about solving this puzzle, though, as you might attract the attention of someone who doesn't like you poking around in their dungeon. You wonder whether it is possible to solve this puzzle, and if so, how many steps you need to move in order to do so.

Input
init_pos: an integer matrix representing the initial position of the puzzle.
Output
The number of steps required to solve this puzzle, or -1 if the puzzle is impossible to solve.

Examples
Example 1:
Input:

init_pos = [[4, 1, 3], [2, 0, 5]]
Output: 5

Explanation:

First slide
*/

/*
-------------------------    My Approaches:
1. Graph - DFS

We can solve this problem using BFS approach. The matrix pon its own can be used to represent an implcit graph. the key to this problem is to keep swapping the numbers into the place of 0.
as a result, its neighbors would inclucde its 4 neighbors to its side, horizontally and vertically..since at each step, we are pushing each of ht ecombinations form its possible neighbors,
and we are pushing this in in the form of BFS, we will always arrive at ht esolution on hte shortest number of steps which will give us the answer to our problem.

we make use of converting a matrix to stirng and string to matrix to make it easier to keep track of wht elements have been cvered.

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
this is a straightforward BFS problem. however, the biggest diffculty in implementing a solution is findint hte state adjacent to the curent state and being able to store the different states in a hash table
for lookup of items. the core idea is another state is adjacent tot he current state when the entry with the 0 is swapped with one of the entries adjacent to it, which is
very helpful if we use a mutable structure (like lists). on th eotehr hand, we need to store the swapped value in a hash table and in a quuee, which is veru helpful if we use  ahashable
structure (like tuples) which are usually immutable. other than that, its just a standard BFS solution.

a node transition graph might look like this

which side a line comes out of represents whuch way the puzzle can move and what happens when you move the puzzle that way. note this graph is two directions as you can always move back to return to the riginal poisiton.

thje time complexitu is O(n!) where n is the size of the matrix in question. we usually would never reach the worst case scnario though.

    Time complexity: O(n!)
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <queue>
#include <unordered_map>

std::string getValue(std::vector<std::vector<int>> & initPos){
    std::string strValue = "";
    for(int i=0; i< initPos.size(); i++){
        for(int j=0; j< initPos[0].size(); j++){
            strValue += std::to_string(initPos[i][j]);
        }
    }
    return strValue;
}

std::vector<int> getMatrix(std::vector<std::vector<int>> & initPos, std::string & topElement){
    int nRows = initPos.size();
    int nCols = initPos[0].size();
    std::vector<int> result;
    
    for(int i=0; i < topElement.size(); i++){
        initPos[i/nCols][i%nCols] = topElement[i] - '0';
        if(topElement[i] == '0'){
            result.push_back(i/nCols);
            result.push_back(i%nCols);
        }
    }
    return result;
}

void getDuplicate(std::vector<std::vector<int>> & duplicate, std::vector<std::vector<int>> & initPos){
    for(int i=0; i <initPos.size(); i++){
        std::vector<int> list;
        for(int j=0; j < initPos[0].size(); j++){
            list.push_back(initPos[i][j]);
        }
        duplicate.push_back(list);
    }
}

void printMatrix(std::vector<std::vector<int>> & matrix){
    for(int i=0; i < matrix.size(); i++){
        for(int j=0; j < matrix[0].size(); j++)
            std::cout<<matrix[i][j]<<" ";
        std::cout<<"\n";
    }
}


int minSteps(std::vector<std::vector<int>> & initPos){
    std::queue<std::string> elementQueue;
    std::unordered_map<std::string, int> visited;
    std::vector<int> xPos = {-1,0,1,0};
    std::vector<int> yPos = {0,1,0,-1};
    
    // insert base condition into queue
    std::string value = getValue(initPos);
    elementQueue.push(value);
    visited[value] = 0;
    
    while(!elementQueue.empty()){
        std::string topElement = elementQueue.front();
        int step = visited[topElement];
//         std::cout<<topElement<<std::endl;
        
        if(topElement == "123450")
            return step;
        else{
            std::vector<int> zeroPos = getMatrix(initPos, topElement); 
//             std::cout<<"Printing initPos: "<<std::endl;
//             printMatrix(initPos);
            int x = zeroPos[0], y = zeroPos[1];
            
            for(int i=0; i < xPos.size(); i++){
                if(x+xPos[i] >= 0 && x+xPos[i] < initPos.size() && y+yPos[i] >=0 && y+yPos[i] < initPos[0].size()){
                    std::vector<std::vector<int>> duplicate;
                    getDuplicate(duplicate, initPos);
                    
                    std::swap(duplicate[x][y], duplicate[x+xPos[i]][y+yPos[i]]);
                    std::string value = getValue(duplicate);
                    if(visited.find(value) == visited.end()){
                        visited[value] = step+1;
                        elementQueue.push(value);
                    }
                }
            }
        }
        
        elementQueue.pop();
    }
    
    return -1;
}

int num_steps(std::vector<std::vector<int>> init_pos) {
    // WRITE YOUR BRILLIANT CODE HERE
    return minSteps(init_pos);
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
    int init_pos_length;
    std::cin >> init_pos_length;
    ignore_line();
    std::vector<std::vector<int>> init_pos;
    for (int i = 0; i < init_pos_length; i++) {
        init_pos.emplace_back(get_words<int>());
    }
    int res = num_steps(init_pos);
    std::cout << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <cmath> // pow, round
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <queue> // queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <vector> // vector

int serialize(std::vector<std::vector<int>> position) {
    int total = 0;
    for (std::vector<int> line : position) {
        for (int entry : line) {
            total *= 10;
            total += entry;
        }
    }
    return total;
}

std::vector<std::vector<int>> deserialize(int state) {
    std::vector<std::vector<int>> result{{}, {}};
    for (int i = 1; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            int exponent = i * 3 + j;
            int digit = state / (int) (std::round(std::pow(10, exponent))) % 10;
            result[1 - i].emplace_back(digit);
        }
    }
    return result;
}

int num_steps(std::vector<std::vector<int>> init_pos) {
    int target_state = 123450;
    int row_directions[4] = {1, 0, -1, 0};
    int col_directions[4] = {0, 1, 0, -1};

    int init_state = serialize(init_pos);
    if (init_state == target_state) return 0;
    std::unordered_map<int, int> moves_map({{init_state, 0}});
    std::queue<int> moves_queue;
    moves_queue.push(init_state);
    while (moves_queue.size() > 0) {
        int top_state = moves_queue.front();
        int row = 0, col = 0;
        std::vector<std::vector<int>> top_position = deserialize(top_state);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (top_position[i][j] == 0) {
                    row = i;
                    col = j;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int new_row = row + row_directions[i], new_col = col + col_directions[i];
            if (0 <= new_row && new_row < 2 && 0 <= new_col && new_col < 3) {
                std::vector<std::vector<int>> new_position = deserialize(top_state);
                new_position[row][col] = top_position[new_row][new_col];
                new_position[new_row][new_col] = top_position[row][col];
                int new_state = serialize(new_position);
                if (!moves_map.count(new_state)) {
                    moves_map[new_state] = moves_map[top_state] + 1;
                    moves_queue.push(new_state);
                    if (new_state == target_state) return moves_map[new_state];
                }
            }
        }
        moves_queue.pop();
    }
    return -1;
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
    int init_pos_length;
    std::cin >> init_pos_length;
    ignore_line();
    std::vector<std::vector<int>> init_pos;
    for (int i = 0; i < init_pos_length; i++) {
        init_pos.emplace_back(get_words<int>());
    }
    int res = num_steps(init_pos);
    std::cout << res << '\n';
}