/*
Problem statement:

The Umbristan Department of Forestry(UDF) is tackling a rather difficult problem and the Umbristan government has detached you one of its best workers to go resolve the issue. When you arrive you are quickly briefed on the problem at hand. Inside the Umbristan National Park there exists an area that has been closed off as fencing needs to be erected in the area. The department for whatever reason needs to set up some very expensive fencing between the trees. The department has also set up some rules for the fence

The fence needs to be set up such that every tree in the area is connected to the fence.

The department is on a very strict operating budget and so needs to minimize the metres of fencing required.

The department has counted the number of trees in the area as well as determined all possible tree pairs where a fence can be built between the pair.

4.Can you help them figure out the smallest amount of fencing required?

It is possible that not all the nodes will be connected to one another depending on the tree pairs. Input will consist of trees the number of trees in the area labelled from 1 to n as well as pairs, a list consisting of the tuple [a, b, d] which denotes that a fence can be built between the trees a and b that will be d metres in length.

Constraints
1 <= trees <= 10^5

Examples
Example 1:
Input: trees = 5, pairs = [[1, 2, 1], [2, 4, 2], [3, 5, 3], [4, 4, 4]]
Output: 6
Explanation:
We can erect fencing between trees for the following pairs, 1 and 2, 2 and 4, 3 and 5. With this every tree is connected by a fence and we have used 6 metres of fencing.
*/

/*
-------------------------    My Approaches:
1. Prim's algorithm

    i used prim's algorithm in order to solve the rpoblem.  we basically followed prim's algorithm which we had learn about. in addition, i added a couple of additional checks.
    the first while look runs till isEnd = false. isned becomes treu when we have covered all vertices/forests trees. 
    the enxt check we added was for foundNextIndex. we added that check so that we get to know if thre are any additional trees that are left to fence. if no, we have basically covered all 
    trees in the forest so we return the cost of covering the trees. the last check is for nextIteration. we use this is order to know wherether we have covered all the trees in a 
    particular group. since the problem states that there could be mutiple groups of trees with not all connected to one another, we use hteis variable to make sure, we are done with a partciular group before we
    move on to hte next roup of forest trees.

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
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void createGraph(int trees, std::vector<std::vector<int>> & pairs , std::vector<std::vector<int>> & matrix){
    for(int i=0; i< pairs.size(); i++){
        std::vector<int> list = pairs[i];
        matrix[list[0]][list[1]] = list[2];
        matrix[list[1]][list[0]] = list[2];
    }
}

int mst(int trees, std::vector<std::vector<int>> & matrix){
    int minCost = 0;
    std::vector<bool> selected(trees+1,false);
    selected[0] = true;
    bool isEnd = false;
    while(!isEnd){
        int nextIndex = std::numeric_limits<int>::min();
        bool foundNextIndex = false;
        
        //get next index for minimum spanning tree
        for(int i=1; i< selected.size() && !foundNextIndex; i++){
            if(!selected[i]){
                nextIndex = i;
                foundNextIndex = true;
            }
        }
        
        if(foundNextIndex){
            //perform minimum spanning tree from that index
            selected[nextIndex] = true;
            bool nextIteration = true;
            while(nextIteration){
                int minValue = std::numeric_limits<int>::max();
                bool swapFound = false;
                int x = 0, y = 0;
                
                //get the next minimum weight from all possible options
                for(int i=1; i<=trees; i++){
                    if(selected[i]){
                        for(int j = 1; j <= trees; j++){
                            if(!selected[j] && matrix[i][j]){
                                if(minValue > matrix[i][j]){
                                    swapFound = true;
                                    minValue = matrix[i][j];
                                    x = i;
                                    y = j;
                                }
                            }
                        }
                    }
                }
                
                // if swap found, we have a new edge added to the tree
                if(swapFound){
                    minCost += minValue;
                    selected[y] = true;
                }
                else // need to get the next vertex and get te edges it is connected to
                    nextIteration = false;
            }
        }
        else
            isEnd = true;               
    }
    return minCost;
}

int mst_forest(int trees, std::vector<std::vector<int>> pairs) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::vector<std::vector<int>> matrix(trees+1, std::vector<int>(trees+1));
    createGraph(trees, pairs, matrix);
    return mst(trees, matrix);
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

int main() {
    int trees;
    std::cin >> trees;
    ignore_line();
    int pairs_length;
    std::cin >> pairs_length;
    ignore_line();
    std::vector<std::vector<int>> pairs;
    for (int i = 0; i < pairs_length; i++) {
        pairs.emplace_back(get_words<int>());
    }
    int res = mst_forest(trees, pairs);
    std::cout << res << '\n';
}



//  Other Approaches(1)
