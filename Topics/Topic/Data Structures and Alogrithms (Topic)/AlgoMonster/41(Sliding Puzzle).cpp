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


    Time complexity: O()
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
